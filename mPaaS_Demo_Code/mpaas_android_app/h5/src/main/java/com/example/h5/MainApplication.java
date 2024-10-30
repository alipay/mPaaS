package com.example.h5;
import android.app.Application;
import android.content.Context;


import com.alipay.mobile.framework.quinoxless.IInitCallback;
import com.alipay.mobile.framework.quinoxless.QuinoxlessApplicationLike;
import com.alipay.mobile.framework.quinoxless.QuinoxlessFramework;
import com.alipay.mobile.nebula.provider.H5AppCenterPresetProvider;
import com.alipay.mobile.nebula.util.H5Utils;
import com.mpaas.mas.adapter.api.MPDiagnose;
import com.mpaas.mas.adapter.api.MPLogger;
import com.mpaas.nebula.adapter.api.MPNebula;
import com.mpaas.nebula.adapter.api.MPNebulaOfflineInfo;
import com.mpaas.tinyappcommonres.TinyAppCenterPresetProvider;


/**
 * Create by ciwei
 * On 2020/12/24
 */
public class MainApplication extends Application {

    @Override
    protected void attachBaseContext(Context base) {
        super.attachBaseContext(base);
        //分包
//        MultiDex.install(this);

        QuinoxlessFramework.setup(this, new IInitCallback() {
            @Override
            public void onPostInit() {
                // 此回调表示 mPaaS 已经初始化完成，mPaaS 相关调用可在这个回调里进行。
            }
        });
    }

    @Override
    public void onCreate() {
        super.onCreate();
//        mpsnc.setup(getApplication());
        // mPaaS 初始化。
        QuinoxlessFramework.init();

    }


//    @Override
//    public void onMPaaSFrameworkInitFinished() {
//        MPLogger.setUserId("MpaasPoc");
//        // 初始化 Sync 通道，必须先设置 userId，否则会初始化失败
//        MPDiagnose.initSyncChannel(this);
//        //初始化小程序公共资源包
//        H5Utils.setProvider(H5AppCenterPresetProvider.class.getName(), new TinyAppCenterPresetProvider());
//        loadOfflineNebula();
//        MPLogger.enableAutoLog();
//    }
//
//    private void loadOfflineNebula() {
//        new Thread(new Runnable() {
//            @Override
//            public void run() {
//                // 此方法为阻塞调用，请不要在主线程上调用内置离线包方法。如果内置多个amr包，要确保文件已存在，如不存在，会造成其他内置离线包失败。
//                // 此方法仅能调用一次，多次调用仅第一次调用有效。
//                MPNebula.loadOfflineNebula("h5_json.json", new MPNebulaOfflineInfo("70000000_0.0.0.2.amr", "70000000", "0.0.0.2"));
//            }
//        }).start();
//    }
}
