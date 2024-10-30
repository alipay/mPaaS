package com.mpaas.mindemo;

import android.content.Intent;
import android.os.Build;
import android.os.Handler;
import android.os.Looper;
import android.util.Log;
import android.webkit.ValueCallback;

import androidx.core.content.ContextCompat;

import com.alibaba.ariver.app.api.Page;
import com.alibaba.ariver.app.api.point.activity.ActivityResultPoint;
import com.alibaba.ariver.app.api.point.page.PageEnterPoint;
import com.alibaba.ariver.app.api.point.page.PageResumePoint;
import com.alibaba.ariver.app.api.point.page.PageStartedPoint;
import com.alibaba.ariver.engine.api.Render;
import com.alibaba.ariver.engine.api.bridge.model.GoBackCallback;
import com.alibaba.ariver.engine.api.common.CommonBackPerform;
import com.alibaba.ariver.engine.api.extensions.back.BackInterceptPoint;
import com.alibaba.ariver.kernel.api.node.NodeAware;
import com.alibaba.ariver.kernel.common.utils.BundleUtils;
import com.mpaas.framework.adapter.api.MPFramework;
import com.mpaas.mas.adapter.api.MPLogger;
import com.mpaas.mriver.engine.MRRender;
import com.mpaas.mriver.engine.MRWebView;
import com.mpaas.mriver.engine.extensions.page.PageFinishedContext;
import com.mpaas.mriver.engine.extensions.page.PageFinishedPoint;

import java.lang.ref.WeakReference;

public class PageLifeCycleExtension implements
        PageStartedPoint,
        PageResumePoint,
        NodeAware<Page>,
        PageEnterPoint,
        PageFinishedPoint,
        ActivityResultPoint,
        BackInterceptPoint {
    private WeakReference<Page> mPage;

    Page aPage;

    @Override
    public boolean intercepted(Render render, int i, CommonBackPerform.BackHandler backHandler, GoBackCallback goBackCallback) {
        return false;
    }

    @Override
    public void onStarted(String s) {
        checkStatusBarTheme(mPage.get());
    }

    @Override
    public void onInitialized() {

    }

    @Override
    public void onFinalized() {

    }

    @Override
    public void setNode(WeakReference<Page> weakReference) {
        mPage = weakReference;
    }

    @Override
    public Class<Page> getNodeType() {
        return Page.class;
    }

    private void checkStatusBarTheme(Page page) {
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.LOLLIPOP) {
            page.getPageContext()
                   .getActivity()
                   .getWindow()
                   .setStatusBarColor(ContextCompat.getColor(MPFramework.getApplicationContext().getApplicationContext(), R.color.text_color_red));
        }
    }

    @Override
    public void onPageResume(Page page) {

    }


    @Override
    public void onPageEnter(Page page) {
        aPage = page;
    }

    @Override
    public void onPageFinish(PageFinishedContext pageFinishedContext) {
        if (aPage == null || aPage.isDestroyed()) {
            return;
        }
        boolean forbidCopy = BundleUtils.getBoolean(aPage.getStartParams(), "ForbidCopy", false);
        if (!forbidCopy) {
            return;
        }
        final String js="var funt=(e)=>{var inputs=e.getElementsByTagName(\"input\");if (inputs) {for(let i of inputs) {var f=(e)=>{return false;};i.oncontextmenu=f;i.oncopy=f;i.onpaste=f;oncut=f;}}};funt(document);new window.MutationObserver((e,m) => {if(e){e.forEach(i=>{i.addedNodes.forEach(node=>{funt(node)});})}}).observe(document.getElementsByTagName('body')[0], {childList:true, attributes:false,subtree:true})";
        new Handler(Looper.getMainLooper()).post(new Runnable() {
            @Override
            public void run() {
                if (aPage != null && !aPage.isExited()) {
                    MRWebView mrWebView = ((MRRender) aPage.getRender()).getWebView();
                    if (mrWebView != null) {
                        mrWebView.evaluateJavascript(js, new ValueCallback<String>() {
                            @Override
                            public void onReceiveValue(String value) {
                                Log.i("TTAATT", "eventREsult: " + value);
                            }
                        });
                    }
                }
            }
        });
    }

    @Override
    public void onActivityResult(int i, int i1, Intent intent) {
        MPLogger.error("权限返回值","requestCode:"+i+"     resultCode:"+i+"   data:"+intent);
    }
}





//package com.mpaas.demo.apm;
//
//        import android.app.Activity;
//        import android.content.pm.ActivityInfo;
//        import android.content.res.AssetManager;
//        import android.content.res.Configuration;
//        import android.graphics.drawable.GradientDrawable;
//        import android.os.Bundle;
//        import android.os.Handler;
//        import android.os.Looper;
//        import android.support.annotation.Nullable;
//        import android.text.TextUtils;
//        import android.util.Log;
//        import android.webkit.ValueCallback;
//
//        import com.alibaba.ariver.app.api.App;
//        import com.alibaba.ariver.app.api.Page;
//        import com.alibaba.ariver.app.api.point.app.AppExitPoint;
//        import com.alibaba.ariver.app.api.point.page.PageEnterPoint;
//        import com.alibaba.ariver.app.api.point.page.PagePausePoint;
//        import com.alibaba.ariver.app.api.point.page.PageResumePoint;
//        import com.alibaba.ariver.kernel.RVStartParams;
//        import com.alibaba.ariver.kernel.api.node.NodeAware;
//        import com.alibaba.ariver.kernel.common.utils.BundleUtils;
//        import com.alibaba.ariver.kernel.common.utils.ExecutorUtils;
//        import com.alibaba.fastjson.JSON;
//        import com.alibaba.fastjson.JSONObject;
//        import com.mpaas.demo.BaseDemoActivity;
//        import com.mpaas.mriver.api.integration.Mriver;
//        import com.mpaas.mriver.api.resource.MriverResource;
//        import com.mpaas.mriver.engine.MRRender;
//        import com.mpaas.mriver.engine.extensions.page.PageFinishedContext;
//        import com.mpaas.mriver.engine.extensions.page.PageFinishedPoint;
//        import com.mpaas.mriver.engine.extensions.url.ShouldLoadUrlPoint;
//
//        import java.io.BufferedReader;
//        import java.io.InputStream;
//        import java.io.InputStreamReader;
//        import java.lang.ref.WeakReference;
//
//public class PageLifeCycleExtension implements PageResumePoint, PageFinishedPoint, PageEnterPoint, PagePausePoint, AppExitPoint, ShouldLoadUrlPoint, NodeAware<Page> {
//
//    private static final String TAG = "PageLifeCycleExxx";
//    private static String sReplayJs = "";
//
//    private WeakReference<Page> mPage;
//
//    @Override
//    public void onPageResume(Page page) {
//        checkStatusBarTheme(page);
//    }
//
//    @Override
//    public void onInitialized() {
//
//    }
//
//    @Override
//    public void onFinalized() {
//
//    }
//
//    @Override
//    public void onPageEnter(Page page) {
//        checkStatusBarTheme(page);
//    }
//
//    private void checkStatusBarTheme(Page page) {
//        int titleBarColor = page.getStartParams().getInt("titleBarColor");
//        titleBarColor = titleBarColor & 0xffffff;
//        BaseDemoActivity.setAndroidNativeLightStatusBar(page.getRender().getActivity(), titleBarColor == 0xffffff);
//    }
//
//    @Override
//    public void onPagePause(final Page page) {
//
//    }
//
//    @Override
//    public void onAppExit(App app) {
//        // TODO @调试面板功能
//        Mriver.setConfig("mriver_show_debug_menu_all",  "NO");
//
//
//        // TODO @打开测试版本 start
//        if (app != null && !TextUtils.isEmpty(app.getAppId())) {
//            final String appId = app.getAppId();
//            Bundle startParams = app.getStartParams();
//            String type = BundleUtils.getString(startParams, "openType");
//            boolean isTestVersion = "A".equals(type)||"B".equals(type);
//            if (isTestVersion) {
//                // 仅测试版本删除
//                ExecutorUtils.runOnMain(new Runnable() {
//                    @Override
//                    public void run() {
//                        MriverResource.deleteApp(appId); // 删除本地历史测试版本，避免后续触点打开会使用缓存
//                    }
//                }, 100);
//
//            }
//        }
//        // TODO @打开测试版本 end
//    }
//
//    @Nullable
//    @Override
//    public LoadResult shouldLoad(JSONObject jsonObject, String s, LoadType loadType) {
//        if (mPage != null && mPage.get() != null) {
//            ((MRRender)mPage.get().getRender()).getWebView().addJavascriptInterface(new JavaTestInterface(), "androidJsInterface");
//        }
//        return null;
//    }
//
//    @Override
//    public void setNode(WeakReference<Page> weakReference) {
//        mPage = weakReference;
//    }
//
//    @Override
//    public Class<Page> getNodeType() {
//        return Page.class;
//    }
//
//    @Override
//    public void onPageFinish(PageFinishedContext pageFinishedContext) {
//        if (mPage == null || mPage.get() == null) {
//            return;
//        }
//
//        final Page page = mPage.get();
//
//
//        if (TextUtils.isEmpty(sReplayJs)) {
//            try {
//                AssetManager am = page.getPageContext().getActivity().getAssets();
//                InputStream inputStream = am.open("replay/aiapm.js");
//                InputStreamReader inputReader = new InputStreamReader(
//                        inputStream);
//                BufferedReader reader = new BufferedReader(inputReader);
//                String line;
//                StringBuilder content = new StringBuilder();
//                // 分行读取
//                while ((line = reader.readLine()) != null) {
//                    content.append(line).append("\n");
//                }
//                inputStream.close();
//
//
//                sReplayJs = "javascript:" + content.toString() + "\n"
//                        + "\n ";
//            }catch (Throwable t) {
//                t.printStackTrace();
//            }
//            // 给js赋值
//        }
//
//        if (!TextUtils.isEmpty(sReplayJs)) {
//            new Handler(Looper.getMainLooper()).post(new Runnable() {
//                @Override
//                public void run() {
//                    if (!(page.getRender() instanceof MRRender) || ((MRRender) page.getRender()).getWebView() == null) {
//                        return;
//                    }
//
//
//                    ((MRRender) page.getRender()).getWebView().evaluateJavascript(sReplayJs, new ValueCallback<String>() {
//                        @Override
//                        public void onReceiveValue(String value) {
//                            Log.i("TTTES", "replayJS js Result: " + value);
//                        }
//                    });
//                }
//            });
//        }
//    }
//}
