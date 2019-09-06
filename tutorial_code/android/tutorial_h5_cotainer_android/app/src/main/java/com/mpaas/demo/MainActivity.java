package com.mpaas.demo;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;

import com.mpaas.nebula.adapter.api.MPNebula;


public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        findViewById(R.id.start_url_btn).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                MPNebula.startUrl("https://tech.antfin.com/");
            }
        });

        findViewById(R.id.h5_to_native_btn).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                MPNebula.startUrl("https://mcube-prod.oss-cn-hangzhou.aliyuncs.com/570DA89281533-default/80000000/1.0.0.1_all/nebula/fallback/h5_to_native.html");
            }
        });

        findViewById(R.id.custom_jsapi_btn).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                // 需要注册自定义插件，推荐在启动的时候注册一次即可（参见 MyApplication 的 registerCustomJsapi）
                MPNebula.startUrl("https://mcube-prod.oss-cn-hangzhou.aliyuncs.com/570DA89281533-default/80000001/1.0.0.1_all/nebula/fallback/custom_jsapi.html");
            }
        });

        findViewById(R.id.custom_title_btn).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                // 设置自定义 title（设置一次即可）
                MPNebula.setCustomViewProvider(new H5ViewProviderImpl());
                // 随意启动一个地址，title 已经改变
                MPNebula.startUrl("https://tech.antfin.com/");
            }
        });
    }
}
