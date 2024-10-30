package com.mpaas.antui.viewdemo;

import android.app.Activity;
import android.os.Bundle;
import android.util.TypedValue;

import com.alipay.mobile.antui.basic.AUTextView;
import com.mpaas.antui.R;

/**
 * Created by kuaikuai(simonazhou.zxm@antfin.com) on 18/3/23.
 */

public class AULinearLayoutActivity extends Activity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.view_aulinearlayout);
//        LinearLayout auLinearLayout = (LinearLayout) findViewById(R.id.ll_test);
        AUTextView textView = (AUTextView) findViewById(R.id.tv_test);
//        LinearLayout.LayoutParams params = new LinearLayout.LayoutParams(DensityUtil.dip2px(getBaseContext(), 120), DensityUtil.dip2px(getBaseContext(), 120));
//        auLinearLayout.setLayoutParams(params);
//        auLinearLayout.setPadding(1, 1, 1, 1);
        textView.setTextSize(TypedValue.COMPLEX_UNIT_DIP, 16);
    }
}
