package com.example.share.share;

import android.os.Bundle;

import com.alipay.mobile.framework.BuildConfig;
import com.alipay.mobile.framework.app.ActivityApplication;
import com.mpaas.mobile.metainfo.Application;
import com.mpaas.mobile.metainfo.MetaInfoLibrary;


@MetaInfoLibrary(applicationId = BuildConfig.APPLICATION_ID)
@Application(appId = "33330003")
public class ShareMicroApp extends ActivityApplication {
    @Override
    public String getEntryClassName() {
        return null;
    }

    @Override
    protected void onCreate(Bundle bundle) {

    }

    @Override
    protected void onStart() {
        getMicroApplicationContext().startActivity(this, ShareActivity1.class.getName());
    }

    @Override
    protected void onRestart(Bundle bundle) {
        onStart();
    }

    @Override
    protected void onStop() {

    }

    @Override
    protected void onDestroy(Bundle bundle) {

    }


}
