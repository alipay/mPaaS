package com.mpaas.demo;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.support.annotation.Nullable;
import android.view.View;

import com.alipay.mobile.antui.basic.AUToast;
import com.mpaas.demo.nebula.CustomizeActivity;
import com.mpaas.demo.nebula.MyJSApiPlugin;
import com.mpaas.demo.nebula.NebulaAppActivity;
import com.mpaas.demo.nebula.OnlineActivity;
import com.mpaas.demo.nebula.R;
import com.mpaas.nebula.adapter.api.MPNebula;

public class HomeActivity extends Activity {

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_home);

        findViewById(R.id.btn_online).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startActivity(new Intent(HomeActivity.this, OnlineActivity.class));
            }
        });

        findViewById(R.id.btn_offline).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startActivity(new Intent(HomeActivity.this, NebulaAppActivity.class));
            }
        });
        findViewById(R.id.btn_plugin_register).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                registerJSAPI();
                AUToast.makeToast(HomeActivity.this, R.string.custom_jsapi_setting_tips, 4000).show();
            }
        });
        findViewById(R.id.btn_customized_config).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startActivity(new Intent(HomeActivity.this, CustomizeActivity.class));
            }
        });

    }


    private void registerJSAPI() {
        MPNebula.registerH5Plugin(
                MyJSApiPlugin.class.getName(),
                null,
                "page",
                new String[]{"myapi1", "myapi2"}
        );
    }
}
