package com.mpaas.antui.viewdemo.form;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;

import com.mpaas.antui.R;


/**
 * Created by minghui on 2017/8/21.
 */

public class CheckBoxActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        View v = View.inflate(this, R.layout.checkbox_activity, null);
        setContentView(v);
    }
}
