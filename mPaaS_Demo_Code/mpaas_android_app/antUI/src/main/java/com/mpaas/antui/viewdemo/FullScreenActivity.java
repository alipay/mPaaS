package com.mpaas.antui.viewdemo;

import android.app.Activity;
import android.os.Bundle;
import android.view.WindowManager;
import android.widget.LinearLayout;

import com.mpaas.antui.R;
import com.alipay.mobile.antui.basic.AUButton;
import com.alipay.mobile.antui.utils.AUStatusBarUtil;
import com.alipay.mobile.antui.utils.ToolUtils;

/**
 * Created by xuanmu on 18/6/11.
 *
 * @activity : Demo Activity
 * @name : Description
 * @output : true or false
 */
public class FullScreenActivity extends Activity {


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        getWindow().setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN,
                WindowManager.LayoutParams.FLAG_FULLSCREEN);
        setContentView(R.layout.activity_full_screen);

        AUButton button = (AUButton) findViewById(R.id.btn_screen);
        if (ToolUtils.isConcaveScreen(this)) {
            LinearLayout.LayoutParams layoutParams = (LinearLayout.LayoutParams) button.getLayoutParams();
            layoutParams.topMargin = AUStatusBarUtil.getStatusBarHeight(this);
            button.setLayoutParams(layoutParams);
        }

    }
}
