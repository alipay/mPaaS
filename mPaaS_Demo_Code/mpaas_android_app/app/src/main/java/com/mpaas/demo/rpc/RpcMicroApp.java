package com.mpaas.demo.rpc;

import android.os.Bundle;

import com.alipay.mobile.framework.BuildConfig;
import com.alipay.mobile.framework.app.ActivityApplication;
import com.mpaas.demo.RpcMainActivity;
import com.mpaas.mobile.metainfo.Application;
import com.mpaas.mobile.metainfo.MetaInfoLibrary;

/**
 * Created by xingcheng on 2018/7/27.
 */
@MetaInfoLibrary(applicationId = BuildConfig.APPLICATION_ID)
@Application(appId = "33330010")
public class RpcMicroApp extends ActivityApplication {

    private Bundle mParam;

    @Override
    public String getEntryClassName() {
        return null;
    }

    @Override
    protected void onCreate(Bundle bundle) {
        mParam = bundle;
    }

    @Override
    protected void onStart() {
        doStart(mParam);
    }

    @Override
    protected void onRestart(Bundle bundle) {
        mParam = bundle;
        doStart(mParam);
    }

    @Override
    protected void onStop() {

    }

    @Override
    protected void onDestroy(Bundle bundle) {

    }

    private void doStart(Bundle bundle) {
        String className = RpcMainActivity.class.getName();
        getMicroApplicationContext().startActivity(this, className);
    }
}
