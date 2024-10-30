package com.mpaas.mindemo;


import android.content.Context;
import android.content.res.AssetManager;
import android.text.TextUtils;

import com.alibaba.ariver.app.api.point.activity.ActivityResultPoint;
import com.alibaba.ariver.app.api.point.page.PageDestroyPoint;
import com.alibaba.ariver.app.api.point.page.PageEnterPoint;
import com.alibaba.ariver.app.api.point.page.PagePausePoint;
import com.alibaba.ariver.app.api.point.page.PageResumePoint;
import com.alibaba.ariver.app.api.point.page.PageStartedPoint;
import com.alibaba.ariver.engine.api.extensions.back.BackInterceptPoint;
import com.alibaba.ariver.engine.api.resources.Resource;
import com.alibaba.ariver.resource.api.content.OfflineResource;
import com.alibaba.ariver.resource.api.content.ResourcePackage;
import com.alibaba.ariver.resource.api.content.ResourceQuery;
import com.alibaba.ariver.resource.content.GlobalPackagePool;
import com.alibaba.ariver.resource.content.GlobalResourcePackage;
import com.mpaas.MPInitParamManifest;
import com.mpaas.core.MPInitParam;
import com.mpaas.framework.adapter.api.MPFramework;
import com.mpaas.mas.adapter.api.MPLogger;
import com.mpaas.mriver.api.debug.MriverDebug;
import com.mpaas.mriver.api.init.MriverInitParam;
import com.mpaas.mriver.api.integration.Mriver;
import com.mpaas.mriver.api.resource.MriverResource;
import com.mpaas.mriver.base.view.splash.ISplashView;
import com.mpaas.mriver.base.view.splash.SplashViewFactoryProxy;
import com.mpaas.mriver.engine.extensions.page.PageFinishedPoint;
import com.mpaas.mriver.integration.proxy.TinyEmbedUrlInterceptProxy;
import com.mpaas.mriver.integration.resource.MriverResourceInterceptor;

import java.io.InputStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class MriverInitImpl implements MPInitParamManifest {
    public static final String CUSTOM_LOADING_RESOURCE = "https://img.soogif.com/uog73lWRkB8pdazOcunMdGGP99Iwqq1E.gif";
    @Override
    public MPInitParam initParam(Context context) {
        MriverInitParam mriverInitParam = MriverInitParam.getDefault();
        mriverInitParam.setMriverInitCallback(new MriverInitParam.MriverInitCallback() {
            @Override
            public void onInit() {
                if (com.alibaba.ariver.kernel.common.utils.ProcessUtils.isMainProcess()) {
                    // 小程序相关配置，比如自定义jsapi，titlebar等
                    MPLogger.setUserId("MpaasPoc");
                    Mriver.setUserId("MpaasPoc");
                    MriverDebug.setWssHost("wss://cn-hangzhou-mproxy.cloud.alipay.com/host/");
                    MriverResource.enableVerify(MriverResource.VERIFY_TYPE_YES, "");
                    MriverResource.disableVerify();
                    //分享
                    Mriver.setConfig("mr_showShareMenuItem", "YES");
                    //切换播放器
                    Mriver.setConfig("mr_tiny_video_type", "3");
                    //h5内部webview拦截
                    Mriver.setProxy(TinyEmbedUrlInterceptProxy.class,new TinyH5UrlProvider());
                    //加载内置的point、event事件
                    List<String> miniAppPoint = new ArrayList<>();
                    miniAppPoint.add(PageStartedPoint.class.getName());
                    miniAppPoint.add(PageResumePoint.class.getName());
                    miniAppPoint.add(PagePausePoint.class.getName());
                    miniAppPoint.add(PageDestroyPoint.class.getName());
                    miniAppPoint.add(PageEnterPoint.class.getName());
                    miniAppPoint.add(PageFinishedPoint.class.getName());
                    miniAppPoint.add(ActivityResultPoint.class.getName());
                    miniAppPoint.add(BackInterceptPoint.class.getName());
                    Mriver.registerPoint(PageLifeCycleExtension.class.getName(), miniAppPoint);
                    //基础配置
                    Mriver.setConfig("h5_nbmngconfig", "{\"config\":{\"al\":\"3\",\"pr\":{\"4\":\"86400\",\"common\":\"864000\"},\"ur\":\"5\",\"fpr\":{\"common\":\"3888000\"}},\"switch\":\"yes\"}");
                    //自定义loading
                    initLoading();
                }
            }

            @Override
            public void onError(Exception e) {

            }
        });


        MPInitParam initParam = MPInitParam.obtain();
        initParam.addComponentInitParam(mriverInitParam);
        return initParam;
    }

    private void initLoading(){
        //自定义splashloadingview
        Mriver.setProxy(SplashViewFactoryProxy.class, new SplashViewFactoryProxy() {
            @Override
            public ISplashView createSplashView(Context context) {
                return new CustomLoadingView(context);
            }
        });
        //自定义加载动画
        Mriver.registerPoint(MriverResourceInterceptor.class.getName(),
                Arrays.asList("com.alibaba.ariver.resource.api.extension.ResourceInterceptPoint"));
        Mriver.setConfig("mriver_custom_appxloading", CUSTOM_LOADING_RESOURCE);
        // loading的大小：占屏幕宽度的比例，20表示loading控件大小为屏幕宽度的20%
        Mriver.setConfig("mriver_custom_appxloading_size", "20");
        ResourcePackage resourcePackage = new GlobalResourcePackage("00000001") {
            @Override
            protected boolean needWaitSetupWhenGet() {
                return false;
            }

            @Override
            public boolean needWaitForSetup() {
                return false;
            }

            @Override
            protected boolean canHotUpdate(String hotVersion) {
                return false;
            }

            @Override
            public Resource get(ResourceQuery query) {
                if (TextUtils.equals(CUSTOM_LOADING_RESOURCE, query.pureUrl)) {
                    return getPresetImageResource(MPFramework.getApplicationContext(), query);
                }
                return null;
            }
        };
        GlobalPackagePool.getInstance().add(resourcePackage);
    }


    private static Resource getPresetImageResource(Context application, ResourceQuery query) {
        Resource sResource = null;
        if (sResource == null) {
            InputStream inputStream = null;
            AssetManager am = application.getAssets();
            try {
                inputStream = am.open("preset/custom_loading.gif");

                int length = inputStream.available();
                byte[] buffer = new byte[length];
                inputStream.read(buffer);
                sResource = new OfflineResource(query.pureUrl, buffer);
            } catch (Exception e) {
                e.printStackTrace();
            } finally {
                if (inputStream != null) {
                    try {
                        inputStream.close();
                    } catch (Throwable t) {
                        t.printStackTrace();
                    }
                }
            }
        }

        return sResource;
    }

}
