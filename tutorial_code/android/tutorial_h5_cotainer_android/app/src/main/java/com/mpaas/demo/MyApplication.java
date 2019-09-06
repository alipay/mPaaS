package com.mpaas.demo;


import android.app.Application;
import android.content.Context;

import com.alipay.mobile.framework.quinoxless.IInitCallback;
import com.alipay.mobile.framework.quinoxless.QuinoxlessFramework;
import com.mpaas.nebula.adapter.api.MPNebula;

public class MyApplication extends Application {
    @Override
    protected void attachBaseContext(Context base) {
        super.attachBaseContext(base);
        QuinoxlessFramework.setup(this, new IInitCallback() {
            @Override
            public void onPostInit() {
                // 在这里开始使用mPaaS功能
                registerCustomJsapi();
            }
        });
    }

    @Override
    public void onCreate() {
        super.onCreate();
        QuinoxlessFramework.init();
    }

    private void registerCustomJsapi(){
        MPNebula.registerH5Plugin(
                // 插件的 class name
                MyJSApiPlugin.class.getName(),
                // 填空即可
                "",
                // 作用范围，填"page"即可
                "page",
                // 注册的 jsapi 名称
                new String[]{"myapi"});
    }
}
