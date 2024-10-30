package com.mpaas.antui.viewdemo;

import android.app.Activity;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.util.Log;

import com.mpaas.antui.R;
import com.alipay.mobile.antui.basic.AULoadingView;

/**
 * Created by gaopan.gp on 2016/10/9.
 */
public class EmptyPageLoadingActivity extends Activity {
    private AULoadingView mAULoadingView;
    private int mCurrentProgress;
    private Handler mHandler = new Handler() {
        @Override
        public void handleMessage(Message msg) {
            super.handleMessage(msg);
            mAULoadingView.setCurrentProgress(mCurrentProgress);
        }
    };

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.empty_loading);
        mAULoadingView = (AULoadingView) findViewById(R.id.loadingView);
    }

    @Override
    protected void onResume() {
        super.onResume();
        new Thread(new Runnable() {
            @Override
            public void run() {
                while (mCurrentProgress < 100) {
                    try {
                        Thread.currentThread().sleep(500);
                        mCurrentProgress++;
                        mHandler.sendEmptyMessage(0);
                    } catch (Exception e) {
                        Log.e("EmptyPageActivity", e.getMessage());
                    }
                }

            }
        }).start();
    }
}
