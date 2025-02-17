package com.mpaas.demo.base;


import android.app.Activity;
import android.os.Bundle;

import com.mpaas.mas.adapter.api.MPTracker;

public class BaseActivity extends Activity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        MPTracker.onActivityCreate(this);
    }
    @Override
    public void onWindowFocusChanged(boolean hasFocus) {
        super.onWindowFocusChanged(hasFocus);
        MPTracker.onActivityWindowFocusChanged(this, hasFocus);
    }
    @Override
    protected void onResume() {
        super.onResume();
        MPTracker.onActivityResume(this);
    }
    @Override
    protected void onPause() {
        super.onPause();
        MPTracker.onActivityPause(this);
    }
    @Override
    protected void onDestroy() {
        super.onDestroy();
        MPTracker.onActivityDestroy(this);
    }
}
