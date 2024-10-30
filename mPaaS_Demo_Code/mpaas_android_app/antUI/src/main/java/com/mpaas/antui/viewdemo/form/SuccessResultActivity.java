package com.mpaas.antui.viewdemo.form;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;

import com.mpaas.antui.R;

/**
 * Created by minghui on 2017/8/31.
 */

public class SuccessResultActivity  extends Activity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        View v = View.inflate(this, R.layout.success_res, null);
        setContentView(v);

    }
}

