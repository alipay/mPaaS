package com.mpaas.antui.viewdemo.common;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;

import com.mpaas.antui.R;

/**
 * Created by minghui on 2017/8/29.
 */

public class ScreenActivity extends Activity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        View v = View.inflate(this, R.layout.filter_menu, null);
        setContentView(v);

        findViewById(R.id.single_filter).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startActivity(new Intent(ScreenActivity.this, SingleFilterActivity.class));
            }
        });

        findViewById(R.id.multi_filter).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startActivity(new Intent(ScreenActivity.this, MultipleFilterActivity.class));
            }
        });

    }

}

