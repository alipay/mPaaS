package com.mpaas.demo.hotpatch;

import android.content.pm.PackageManager;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

import androidx.core.app.ActivityCompat;

import com.mpaas.demo.MainActivity;
import com.mpaas.demo.R;
import com.mpaas.demo.base.BaseActivity;
import com.mpaas.hotpatch.adapter.api.MPHotpatch;
import com.mpaas.mas.adapter.api.MPLogger;
import com.mpaas.mas.adapter.api.MPTracker;

import java.util.HashMap;
import java.util.Map;

public class HotpatchActivityPoc extends BaseActivity {
    private Button mHotpatchNeedHotpatchBtn;
    private Button mHotpatchTriggerHotpatchBtn;
    private static final int REQUEST_EXTERNAL_STORAGE = 1;
    private static String[] PERMISSIONS_STORAGE = {
            "android.permission.READ_PHONE_STATE"};
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_hotpatch_poc);
        int permission = ActivityCompat.checkSelfPermission(HotpatchActivityPoc.this,
                "android.permission.READ_PHONE_STATE");
        if (permission != PackageManager.PERMISSION_GRANTED) {
            // 没有写的权限，去申请写的权限，会弹出对话框
            ActivityCompat.requestPermissions(HotpatchActivityPoc.this, PERMISSIONS_STORAGE, REQUEST_EXTERNAL_STORAGE);
        }
        findView();
        initView();
    }

    private void findView() {
        mHotpatchNeedHotpatchBtn = (Button) findViewById(R.id.hotpatch_need_hotpatch_btn);
        mHotpatchTriggerHotpatchBtn = (Button) findViewById(R.id.hotpatch_trigger_hotpatch_btn);
    }

    private void initView() {
        mHotpatchNeedHotpatchBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                hotpatch();
            }
        });
        mHotpatchTriggerHotpatchBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                initHotPatch();
                Map<String, String> params = new HashMap<>();
                params.put("size", "2");//key--属性id ；value --属性值
                MPLogger.event("hotpatch_init", "hotpatch", params);
            }
        });


    }


    private void hotpatch(){
        // 以下代码为需要被热修复的部分
        String content = getString(R.string.hot_fix_abnormal);
//        String content =  getString(R.string.hot_fix_abnormal_success);
        Toast.makeText(HotpatchActivityPoc.this, content, Toast.LENGTH_SHORT).show();
    }

    private void initHotPatch(){
        MPHotpatch.init();
    }

    @Override
    protected void onResume() {
        super.onResume();
        MPTracker.onActivityResume(this);
    }
}
