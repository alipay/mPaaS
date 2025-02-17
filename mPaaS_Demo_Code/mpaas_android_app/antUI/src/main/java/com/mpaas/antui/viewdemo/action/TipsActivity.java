package com.mpaas.antui.viewdemo.action;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.widget.LinearLayout;

import com.alipay.mobile.antui.basic.AUUpdateTips;
import com.mpaas.antui.R;

/**
 * Created by xuanmu on 18/3/1.
 */

public class TipsActivity extends Activity {

    private LinearLayout rootView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_tips);
        rootView = (LinearLayout) findViewById(R.id.tips_root);
    }

    public void updateTipsClick(View view) {
        AUUpdateTips tips = new AUUpdateTips(this);
        tips.setTipText("有20条更新");
        rootView.addView(tips, 0);
    }

}
