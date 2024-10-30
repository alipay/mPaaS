package com.mpaas.antui.viewdemo.form;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;

import com.mpaas.antui.R;
import com.alipay.mobile.antui.tablelist.AUSwitchListItem;

/**
 * Created by minghui on 2017/8/22.
 */

public class SwitchActivity extends Activity{

    private AUSwitchListItem switchListItemOn;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        View v = View.inflate(this, R.layout.switch_activity, null);
        setContentView(v);

        switchListItemOn = (AUSwitchListItem) findViewById(R.id.switch_on);
        switchListItemOn.setSwitchStatus(true);
        switchListItemOn.setLeftSubText("描述文字描述文字描述文字描述文字");
        switchListItemOn.setLeftImage(R.drawable.image);

    }
}
