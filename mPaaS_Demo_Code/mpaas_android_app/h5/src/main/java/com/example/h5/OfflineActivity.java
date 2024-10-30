package com.example.h5;

import android.os.Bundle;
import android.view.View;
import android.widget.Toast;

import com.alipay.mobile.framework.BuildConfig;
import com.alipay.mobile.framework.app.ui.BaseActivity;
import com.alipay.mobile.h5container.api.H5Plugin;
import com.alipay.mobile.nebula.appcenter.model.AppInfo;
import com.alipay.mobile.nebula.provider.H5AppProvider;
import com.alipay.mobile.nebula.util.H5Utils;
import com.mpaas.H5.R;
import com.mpaas.nebula.adapter.api.MPNebula;
import com.mpaas.nebula.adapter.api.MpaasNebulaUpdateCallback;

import java.util.HashMap;
import java.util.Map;

public class OfflineActivity extends BaseActivity implements View.OnClickListener {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_offline);
        findViewById(R.id.btnLoad).setOnClickListener(this);
        findViewById(R.id.btnUpdate).setOnClickListener(this);
        findViewById(R.id.btnDel).setOnClickListener(this);
        findViewById(R.id.btnUpdateDiff).setOnClickListener(this);
        findViewById(R.id.btn_plugin_register).setOnClickListener(this);
        findViewById(R.id.btnGetAppInfo).setOnClickListener(this);
        findViewById(R.id.btnPlayVideo).setOnClickListener(this);
    }

    @Override
    public void onClick(View v) {
        if (v.getId() == R.id.btnLoad) {
            //测试git
            MPNebula.startApp("66668888");
        }
        if (v.getId() == R.id.btnUpdate) {
            MPNebula.updateAllApp(new MpaasNebulaUpdateCallback() {
                @Override
                public void onResult(boolean success, boolean isLimit) {
                    super.onResult(success, isLimit);
                    runOnUiThread(new Runnable() {
                        @Override
                        public void run() {
                            Toast.makeText(OfflineActivity.this, success ? R.string.update_success : R.string.update_failure, Toast.LENGTH_SHORT).show();
                        }
                    });
                }
            }, true);
        }
        if (v.getId() == R.id.btnDel) {
            MPNebula.deleteAppInfo("66668888");
        }
        if (v.getId() == R.id.btn_plugin_register) {
            registerJSAPI();
            Toast.makeText(OfflineActivity.this, "myapi1 myapi2 tinyToNative\n注册成功", Toast.LENGTH_SHORT).show();
        }
        if (v.getId() == R.id.btnGetAppInfo) {
            H5AppProvider provider = H5Utils.getProvider(H5AppProvider.class.getName());
            AppInfo appInfo = provider.getAppInfo("66668888");                 //获取应用配置
            boolean isInstalled = provider.isInstalled("66668888", "1.0.0.0"); //某版本应用是否已经安装
            boolean isAvailable = provider.isAvailable("66668888", "1.0.0.0"); //某版本应用离线包是否已经下载完成
            Toast.makeText(OfflineActivity.this, "是否安装：" + isInstalled + "       是否下载完成" + isAvailable, Toast.LENGTH_SHORT).show();
        }
        if (v.getId() == R.id.btnUpdateDiff) {
            //增量差分包
            Map<String, String> map = new HashMap<>();
            map.put("66668888", "3.0.0.0");
            MPNebula.updateApp(map, new MpaasNebulaUpdateCallback() {
                @Override
                public void onResult(boolean success, boolean isLimit) {
                    super.onResult(success, isLimit);
                    runOnUiThread(new Runnable() {
                        @Override
                        public void run() {
                            Toast.makeText(OfflineActivity.this, success ? R.string.update_success : R.string.update_failure, Toast.LENGTH_SHORT).show();
                        }
                    });
                }
            }, true);
        }
        if (v.getId() == R.id.btnPlayVideo){
            MPNebula.startUrl("https://help.aliyun.com/document_detail/94822.html");
        }
    }

    public void registerJSAPI() {
        MPNebula.registerH5Plugin(
                MyJSApiPlugin.class.getName(),
                BuildConfig.BUNDLE_NAME,
                "page",
                new String[]{"myapi1", "myapi2", "getAppVersion", "tinyToNative", H5Plugin.CommonEvents.H5_PAGE_PHYSICAL_BACK}
        );
    }
}
