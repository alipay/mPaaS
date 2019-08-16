package com.mpaas.demo;

import android.app.Application;
import android.content.Context;
import android.support.multidex.MultiDex;

import com.alipay.mobile.framework.quinoxless.IInitCallback;
import com.alipay.mobile.framework.quinoxless.QuinoxlessFramework;
import com.alipay.mobile.nebula.provider.H5AppCenterPresetProvider;
import com.alipay.mobile.nebula.provider.H5PublicRsaProvider;
import com.alipay.mobile.nebula.util.H5Utils;
import com.mpaas.demo.nebula.H5AppCenterPresetProviderImpl;
import com.mpaas.demo.nebula.H5RsaProviderImpl;
import com.mpaas.demo.nebula.PresetAmrPipeline;


public class MyApplication extends Application {

    @Override
    protected void attachBaseContext(Context base) {
        super.attachBaseContext(base);
        QuinoxlessFramework.setup(this, new IInitCallback() {
            @Override
            public void onPostInit() {
                // 设置离线包验签公钥
                H5Utils.setProvider(H5PublicRsaProvider.class.getName(), new H5RsaProviderImpl());
                // 预置离线包，包括普通离线包和公共资源包
                new Thread(new PresetAmrPipeline()).start();
                // 公共资源包返回 appid
                H5Utils.setProvider(H5AppCenterPresetProvider.class.getName(), new H5AppCenterPresetProviderImpl());
            }
        });
    }

    @Override
    public void onCreate() {
        super.onCreate();
        MultiDex.install(this);
        QuinoxlessFramework.init();
    }
}
