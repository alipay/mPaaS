package com.mpaas.cdpdemo;

import android.os.Bundle;

import com.alipay.mobile.antui.basic.AUTitleBar;

public class DynamicContent1Activity extends DynamicActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        ((AUTitleBar) findViewById(R.id.title_atb)).setTitleText(getString(R.string.dynamic_view_content_1));
    }
}
