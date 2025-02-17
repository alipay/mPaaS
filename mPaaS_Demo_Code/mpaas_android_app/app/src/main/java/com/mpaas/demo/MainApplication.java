package com.mpaas.demo;

import android.app.Application;
import android.content.Context;
import android.net.http.SslError;
import android.util.Log;

import androidx.multidex.MultiDex;

import com.alipay.mobile.framework.quinoxless.QuinoxlessApplicationLike;
import com.alipay.mobile.nebula.provider.H5AppCenterPresetProvider;
import com.alipay.mobile.nebula.provider.H5ReceivedSslErrorHandler;
import com.alipay.mobile.nebula.provider.H5TransStatusBarColorProvider;
import com.alipay.mobile.nebula.provider.MPH5ContentProviderPreWebProvider;
import com.alipay.mobile.nebula.util.H5Utils;
import com.alipay.mobile.nebula.webview.APSslErrorHandler;
import com.alipay.mobile.nebula.webview.APWebView;
import com.alipay.mobile.nebulauc.provider.H5PermissionRequestProvider;
import com.example.h5.NativeMPH5ContentProviderPreWebProvider;
import com.mpaas.apm.api.MPMonitor;
import com.mpaas.cdp.api.IMCdpExportApi;
import com.mpaas.cdp.api.MCdpApi;
import com.mpaas.demo.h55.H5PermissionRequestProviderImp;
import com.mpaas.demo.h55.H5TransStatusBarColorProviderImpl;
import com.mpaas.demo.h55.H5ViewProviderImpl;
import com.mpaas.mas.adapter.api.MPLogger;
import com.mpaas.mps.adapter.api.MPPush;
import com.mpaas.mss.adapter.api.MPSync;
import com.mpaas.nebula.adapter.api.MPNebula;
import com.mpaas.nebula.adapter.api.MPNebulaOfflineInfo;

import java.util.HashMap;
import java.util.Map;

/**
 * Create by ciwei
 * On 2020/12/24
 */
public class MainApplication extends QuinoxlessApplicationLike {

    public static MainApplication application;

    public static MainApplication getContext() {
        return application;
    }

    @Override
    protected void attachBaseContext(Context base) {
        super.attachBaseContext(base);
        //分包
        MultiDex.install(this);
    }

    @Override
    public void onCreate() {
        super.onCreate();
        application = this;
        MPSync.setup(getApplication());
        MCdpApi.API.api().setExportApi(new IMCdpExportApi() {
            public Map<String, String> getExtras() {
                HashMap<String, String> extras = new HashMap<>();
                extras.put("cdp_extend_params_xxxx", String.valueOf(1));
                return extras;
            }
        });

    }


    @Override
    public void onMPaaSFrameworkInitFinished() {
        // 可以在用户登录成功后设置
        MPLogger.setUserId("MpaasPoc");
        H5Utils.setProvider(H5ReceivedSslErrorHandler.class.getName(), new H5ReceivedSslErrorHandler() {
            @Override
            public void onReceivedSslError(APWebView apWebView, APSslErrorHandler apSslErrorHandler, SslError sslError) {
                apSslErrorHandler.proceed();
            }
        });
        //麦克风权限问题
        H5Utils.setProvider(H5PermissionRequestProvider.class.getName(), new H5PermissionRequestProviderImp());
        //设置H5容器资源拦截
        H5Utils.setProvider(MPH5ContentProviderPreWebProvider.class.getName(), new NativeMPH5ContentProviderPreWebProvider());
        //自定义导航 0
//        MPNebula.setCustomViewProvider(new H5ViewProviderImpl());
        //H5沉浸式
        H5Utils.setProvider(H5TransStatusBarColorProvider.class.getName(),new H5TransStatusBarColorProviderImpl());
        loadOfflineNebula();
        //如已在 Application 中调用 mPaaS 初始化方法，则在 QuinoxlessFramework.init() 方法之后调用
        MPPush.init(this);
        //自动化日志用于记录页面切换事件。您可以借此分析应用各功能或运营页面的 PV 和 UV 等数据。
        MPLogger.enableAutoLog();

        MPMonitor.enableRpcMonitor();
    }

    private void loadOfflineNebula() {
        new Thread(new Runnable() {
            @Override
            public void run() {
                Log.e("aaaaaa", "预置离线包");
                // 此方法为阻塞调用，请不要在主线程上调用内置离线包方法。如果内置多个amr包，要确保文件已存在，如不存在，会造成其他内置离线包失败。
                // 此方法仅能调用一次，多次调用仅第一次调用有效。
                MPNebula.loadOfflineNebula("h5_json.json",
                        new MPNebulaOfflineInfo("70000000_0.0.0.2.amr", "70000000", "0.0.0.2"),
                        new MPNebulaOfflineInfo("80808080_0.0.0.9.amr", "80808080", "0.0.0.9"),
                        new MPNebulaOfflineInfo("66668888_1.0.0.0.amr", "66668888", "1.0.0.0"),
                        new MPNebulaOfflineInfo("99100000_0.0.0.20.amr", "99100000", "0.0.0.20"));

            }
        }).start();
    }
}
