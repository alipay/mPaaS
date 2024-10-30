package com.mpaas.mindemo;

import android.content.Context;
import android.view.View;
import android.widget.FrameLayout;

import androidx.annotation.NonNull;

import com.alibaba.ariver.app.api.EntryInfo;
import com.mpaas.mriver.base.view.splash.ISplashView;

public class CustomLoadingView extends FrameLayout implements ISplashView {
    private Context context;
    public CustomLoadingView(@NonNull Context context) {
        super(context);
        this.context = context;
    }

    @Override
    public void onStart() {

    }

    @Override
    public void onStop() {

    }

    @Override
    public void onFail() {

    }

    @Override
    public void updateLoadingInfo(EntryInfo entryInfo) {

    }

    @Override
    public View getView() {
        View view = View.inflate(context, R.layout.laoding_my_h5,null);
        addView(view);
        return this;
    }

    @Override
    public void onExit() {

    }
}
