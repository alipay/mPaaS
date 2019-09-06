package com.mpaas.demo;



import android.app.Application;
import android.content.Context;

import com.alipay.mobile.framework.quinoxless.IInitCallback;
import com.alipay.mobile.framework.quinoxless.QuinoxlessFramework;
import com.mpaas.nebula.adapter.api.MPNebula;
import com.mpaas.nebula.adapter.api.MPNebulaOfflineInfo;

public class MyApplication extends Application {
    @Override
    protected void attachBaseContext(Context base) {
        super.attachBaseContext(base);
        // 建议判断下是否主进程，只在主进程初始化
        QuinoxlessFramework.setup(this, new IInitCallback() {
            @Override
            public void onPostInit() {
                // 在这里开始使用mPaaS功能
                loadOfflineNebula();
            }
        });
    }

    @Override
    public void onCreate() {
        super.onCreate();
        QuinoxlessFramework.init();
    }


    private void loadOfflineNebula() {
        new Thread(new Runnable() {
            @Override
            public void run() {
                // 此方法为阻塞调用，请不要在主线程上调用内置离线包方法。如果内置多个amr包，要确保文件已存在，如不存在，会造成其他内置离线包失败。
                // 此方法仅能调用一次，多次调用仅第一次调用有效。
                MPNebula.loadOfflineNebula("h5_json.json", new MPNebulaOfflineInfo("80000000_1.0.0.0.amr", "80000000", "1.0.0.0"));
            }
        }).start();
    }
}
