package com.mpaas.cdpdemo;

import android.os.Bundle;

import com.alipay.mobile.antui.basic.AUTitleBar;

public class H5PopUpActivity extends PitActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        ((AUTitleBar) findViewById(R.id.title_atb)).setTitleText(getString(R.string.h5_popup));
        mSpaceCode = "h5-popup-test";
    }
}
