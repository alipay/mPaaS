package com.mpaas.config;

import android.content.Intent;
import android.os.Bundle;
import android.text.TextUtils;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import com.alipay.mobile.base.config.ConfigService;
import com.alipay.mobile.framework.app.ui.BaseActivity;
import com.mpaas.configservice.adapter.api.MPConfigService;
import com.mpaas.mas.adapter.api.MPTracker;

import java.util.ArrayList;
import java.util.List;

public class ConfigServiceActivity extends BaseActivity implements View.OnClickListener, ConfigService.ConfigChangeListener {
    Button mSyncBtn, mMonitorChangeBtn, mSearch, btnJumpActivity;
    EditText mSearchInput;
    TextView mResult;
    String key;
    String value;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_config_service);
        MPTracker.onActivityCreate(this);
        setTitle(getString(R.string.title));

        mSearch = (Button) findViewById(R.id.search);
        mResult = (TextView) findViewById(R.id.result);
        mSyncBtn = (Button) findViewById(R.id.sync_config);
        mSearchInput = (EditText) findViewById(R.id.search_input);
        mMonitorChangeBtn = (Button) findViewById(R.id.monitor_change);
        btnJumpActivity = (Button) findViewById(R.id.btn_jump_Activity);

        mSearch.setOnClickListener(this);
        mSyncBtn.setOnClickListener(this);
        mMonitorChangeBtn.setOnClickListener(this);
        btnJumpActivity.setOnClickListener(this);
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        // ConfigChangeListener 内部会以软引用形式保存
        // 所以如果 ConfigChangeListener 是 activity 的话，要在 destroy 的时候进行移除
        MPConfigService.removeConfigChangeListener(this);
        MPTracker.onActivityDestroy(this);
    }

    @Override
    public void onClick(View v) {
        int id = v.getId();
        if (id == R.id.search) {
            key = mSearchInput.getText().toString();
            value = MPConfigService.getConfig(key);
            mResult.setText(value);
            enableBtn();
            Toast.makeText(ConfigServiceActivity.this, getString(R.string.config_search_monitor) + value, Toast.LENGTH_SHORT).show();
        } else if (id == R.id.sync_config) {
            MPConfigService.loadConfigImmediately(0);
            Toast.makeText(ConfigServiceActivity.this, getString(R.string.config_transfer_renew), Toast.LENGTH_SHORT).show();
        } else if (id == R.id.monitor_change) {
            MPConfigService.addConfigChangeListener(this);
            Toast.makeText(ConfigServiceActivity.this, getString(R.string.config_renew) + key + getString(R.string.config_variety), Toast.LENGTH_SHORT).show();
        } else if (id == R.id.btn_jump_Activity) {
            if (TextUtils.isEmpty(value)) {
                return;
            }
            if (value.contains("a") || value.contains("A")) {
                startActivity(new Intent(ConfigServiceActivity.this, APageActivity.class));
            } else if (value.contains("b") || value.contains("B")) {
                startActivity(new Intent(ConfigServiceActivity.this, BPageActivity.class));
            }
        }
    }

    private void enableBtn() {
        if (TextUtils.isEmpty(value)) {
            return;
        }
        if (value.contains("true")) {
            btnJumpActivity.setEnabled(true);
            btnJumpActivity.setBackgroundColor(getResources().getColor(R.color.h5_default_titlebar_color));
        } else if (value.contains("false")) {
            btnJumpActivity.setEnabled(false);
            btnJumpActivity.setBackgroundColor(getResources().getColor(R.color.colorLightGray));
        }
    }

    @Override
    public List<String> getKeys() {
        List<String> keys = new ArrayList<String>();
        keys.add("test1");
        return keys;
    }

    @Override
    public void onConfigChange(String s, String s1) {
        mResult.setText(getString(R.string.monitor_result) + " key:" + s + " value:" + s1);
        Toast.makeText(ConfigServiceActivity.this,
                getString(R.string.monitor_result) + "  key : " + s + " value : " + s1, Toast.LENGTH_SHORT).show();
    }

    @Override
    public void onWindowFocusChanged(boolean hasFocus) {
        super.onWindowFocusChanged(hasFocus);
        MPTracker.onActivityWindowFocusChanged(this, hasFocus);
    }

    @Override
    protected void onResume() {
        super.onResume();
        MPTracker.onActivityResume(this);
    }

    @Override
    protected void onPause() {
        super.onPause();
        MPTracker.onActivityPause(this);
    }

}