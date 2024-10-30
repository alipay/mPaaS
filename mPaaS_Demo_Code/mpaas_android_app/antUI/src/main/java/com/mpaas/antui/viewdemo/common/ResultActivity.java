package com.mpaas.antui.viewdemo.common;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;

import com.mpaas.antui.R;
import com.mpaas.antui.viewdemo.form.FailResultActivity;
import com.mpaas.antui.viewdemo.form.SuccessResultActivity;

/**
 * Created by minghui on 2017/8/22.
 */

public class ResultActivity extends Activity{
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        View v = View.inflate(this, R.layout.result_layout, null);
        setContentView(v);

        findViewById(R.id.success_action).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startActivity(new Intent(ResultActivity.this, SuccessResultActivity.class));
            }
        });

        findViewById(R.id.fail_action).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startActivity(new Intent(ResultActivity.this, FailResultActivity.class));
            }
        });
    }
}
