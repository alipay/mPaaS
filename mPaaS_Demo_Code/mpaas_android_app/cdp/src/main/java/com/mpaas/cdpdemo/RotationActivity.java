package com.mpaas.cdpdemo;


import android.os.Bundle;

import com.alipay.mobile.antui.basic.AUTitleBar;

public class RotationActivity extends PitActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        ((AUTitleBar) findViewById(R.id.title_atb)).setTitleText(getString(R.string.rotation));
          mSpaceCode = "space-rotation-pic";
          //mSpaceCode = "banner_831";
          //mSpaceCode = "test_h5";
    }
}
