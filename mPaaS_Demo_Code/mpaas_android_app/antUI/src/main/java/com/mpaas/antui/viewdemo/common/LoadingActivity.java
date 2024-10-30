package com.mpaas.antui.viewdemo.common;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;

import com.mpaas.antui.R;
import com.alipay.mobile.antui.basic.AUTextView;

import java.text.SimpleDateFormat;
import java.util.Date;

/**
 * Created by minghui on 2017/8/22.
 */

public class LoadingActivity extends Activity{

    private AUTextView loadText;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        View v = View.inflate(this, R.layout.loading_activity, null);
        setContentView(v);

        loadText = (AUTextView) findViewById(R.id.loading_text);

        Date date = new Date(1466577757265L);
        SimpleDateFormat formatter = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
        String dateString = formatter.format(date);

        loadText.setText(dateString);

    }
}
