package com.mpaas.cdpdemo;

import android.os.Bundle;

import com.alipay.mobile.antui.basic.AUTitleBar;

/**
 *
 * dynamic_bottom
 */
public class LocationBottomActivity extends DynamicActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        ((AUTitleBar) findViewById(R.id.title_atb)).setTitleText(getString(R.string.bottom));
    }
}
