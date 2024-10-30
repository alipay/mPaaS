package com.mpaas.push.mpPush;


import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.view.View;

import androidx.annotation.Nullable;
import androidx.fragment.app.FragmentActivity;

import com.mpaas.mas.adapter.api.MPLogger;
import com.mpaas.push.R;

import java.util.HashMap;
import java.util.Map;

public class PushLauncherActivity extends FragmentActivity {

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_launcher);
        setAnalyticsSetting();
        findViewById(R.id.demo).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(PushLauncherActivity.this, MainActivity.class);
                startActivity(intent);
            }
        });
        handleIntent(getIntent());
        setIntent(null);
    }

    @Override
    protected void onNewIntent(Intent intent) {
        super.onNewIntent(intent);
        handleIntent(intent);
        setIntent(null);
    }

    private void handleIntent(Intent intent) {
        if (intent == null) {
            return ;
        }
        Uri uri = intent.getData();
        if (uri == null) {
            return ;
        }
        String params = intent.getStringExtra("data");
        Intent targetIntent = new Intent(PushLauncherActivity.this, LandingTargetActivity.class);
        targetIntent.putExtra("uri", uri.toString());
        targetIntent.putExtra("data", params);
        startActivity(targetIntent);
    }

//    //设置移动分析：启动事件统计/
    private void setAnalyticsSetting() {
        homePage();
    }

    private void homePage(){
        String logId = "openPush";
        // bizType 标识业务类型，相同 bizType 的自定义日志将遵循同样的上报策略，存储在同一个文件中，文件名为进程名_bizType
        // bizType 可以为空，默认为 userbehavor
        String bizType = "openPush";
        // params 为自定义参数，控制台自定义分析中事件的自定义属性对应这些键值对
        Map<String, String> params = new HashMap<>();
        params.put("time", "2021-07-15");
        MPLogger.event(logId, bizType, params);
    }
}
