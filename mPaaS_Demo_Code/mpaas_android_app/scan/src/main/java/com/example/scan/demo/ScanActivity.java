package com.example.scan.demo;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;

import androidx.annotation.Nullable;

import com.alipay.android.phone.scancode.export.adapter.MPScan;
import com.example.scan.demo.R;
import com.example.scan.demo.custom.MyScanActivity;

/**
 * Created by xingcheng on 2018/8/8.
 */

public class ScanActivity extends Activity {
    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_scan);

        findViewById(R.id.standard_ui_btn).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startActivity(new Intent(ScanActivity.this, ScanRequestActivity.class));
            }
        });

        findViewById(R.id.standard_ui_fullscreen_btn).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startActivity(new Intent(ScanActivity.this, ScanFullScreenActivity.class));
            }
        });

        findViewById(R.id.custom_ui_btn).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                scanWithCustomUI();
            }
        });
    }

    private void scanWithCustomUI() {
        MPScan.init(this);

        Intent intent = new Intent(ScanActivity.this, MyScanActivity.class);
        startActivity(intent);

    }
}
