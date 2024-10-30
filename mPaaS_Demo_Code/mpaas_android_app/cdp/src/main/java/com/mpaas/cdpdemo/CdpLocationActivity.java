package com.mpaas.cdpdemo;

import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;

import com.alipay.mobile.antui.basic.AUTitleBar;
import com.alipay.mobile.framework.app.ui.BaseActivity;

public class CdpLocationActivity extends BaseActivity {

    public static void startActivity(Context baseContext) {
        Intent intent = new Intent();
        intent.setClass(baseContext,CdpLocationActivity.class);
        intent.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
        baseContext.startActivity(intent);
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_location);
        ((AUTitleBar) findViewById(R.id.title_atb)).setTitleText(getString(R.string.location));
        findViewById(R.id.location_top_btn).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                startActivity(new Intent(CdpLocationActivity.this, LocationTopActivity.class));
            }
        });
        findViewById(R.id.location_float_top_btn).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                startActivity(new Intent(CdpLocationActivity.this, LocationFloatTopActivity.class));
            }
        });
        findViewById(R.id.location_bottom_btn).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                startActivity(new Intent(CdpLocationActivity.this, LocationBottomActivity.class));
            }
        });
        findViewById(R.id.location_full_btn).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                startActivity(new Intent(CdpLocationActivity.this, LocationFullScreenActivity.class));
            }
        });
        findViewById(R.id.location_header_btn).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                startActivity(new Intent(CdpLocationActivity.this, LocationListHeaderActivity.class));
            }
        });
        findViewById(R.id.location_footer_btn).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                startActivity(new Intent(CdpLocationActivity.this, LocationListFooterActivity.class));
            }
        });

        findViewById(R.id.location_full_btn).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startActivity(new Intent(CdpLocationActivity.this, LocationFullScreenActivity.class));
            }
        });

        findViewById(R.id.location_float_btn).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                startActivity(new Intent(CdpLocationActivity.this, LocationFloatActivity.class));
            }
        });
    }
}
