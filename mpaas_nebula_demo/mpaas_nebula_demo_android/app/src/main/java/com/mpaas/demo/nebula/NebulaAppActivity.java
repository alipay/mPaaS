package com.mpaas.demo.nebula;

import android.os.Bundle;
import android.view.View;

import com.alipay.mobile.antui.basic.AUTitleBar;
import com.alipay.mobile.antui.basic.AUToast;
import com.alipay.mobile.framework.app.ui.BaseActivity;
import com.mpaas.nebula.adapter.api.MPNebula;
import com.mpaas.nebula.adapter.api.MpaasNebulaUpdateCallback;

import java.util.HashMap;
import java.util.Map;

/**
 * Created by omg on 2018/7/23.
 */

public class NebulaAppActivity extends BaseActivity implements View.OnClickListener {

    private static final String TAG = "NebulaAppActivity";
    private AUTitleBar mTitle;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_nebula_app);
        mTitle = (AUTitleBar) findViewById(R.id.titlebar);
        findViewById(R.id.btn_verify_setting).setOnClickListener(this);
        findViewById(R.id.btn_open_app).setOnClickListener(this);
        findViewById(R.id.btn_update_app).setOnClickListener(this);
        findViewById(R.id.btn_update_specific_app).setOnClickListener(this);
        mTitle.setTitleText(getString(R.string.nebula_app));
    }

    private void enableAppVerification() {
        // 设置provider只需一次，通常在应用启动时设置，此处仅为演示。
        // 因为rsa只会在打开H5页面时初始化一次，所以RsaProvider必须在第一次H5页面打开前设置。
        // 除此之外，您还需要在assets/config/custom_config.json里将h5_shouldverifyapp设置成YES
        AUToast.makeToast(NebulaAppActivity.this, R.string.verify_app_setting_toast, 4000).show();
    }

    @Override
    public void onClick(View v) {
        switch (v.getId()) {
            case R.id.btn_verify_setting:
                enableAppVerification();
                break;
            case R.id.btn_open_app:
                openApp("70000000");
                break;
            case R.id.btn_update_app:
                updateAllApps();
                break;
            case R.id.btn_update_specific_app:
                updateApp("70000000");
                break;
        }
    }

    private void openApp(String appId) {
        MPNebula.startApp(appId);
    }

    private void updateApp(String appid) {
        Map<String, String> appMap = new HashMap<>();
        //key为appid，value为version，version可以通过H5AppProvider获取，startUpdateApp内部会自动读取version，所以这里可以传空
        appMap.put(appid, "");
        MPNebula.updateApp(appMap, new MpaasNebulaUpdateCallback() {
            @Override
            public void onResult(final boolean success, final boolean isLimit) {
                super.onResult(success, isLimit);
                runOnUiThread(new Runnable() {
                    @Override
                    public void run() {
                        AUToast.makeToast(NebulaAppActivity.this,
                                success ? R.string.update_success : R.string.update_failure, 2000).show();
                    }
                });
            }
        }, true);
    }

    private void updateAllApps() {
        MPNebula.updateAllApp(new MpaasNebulaUpdateCallback() {
            @Override
            public void onResult(final boolean success, final boolean isLimit) {
                super.onResult(success, isLimit);
                runOnUiThread(new Runnable() {
                    @Override
                    public void run() {
                        AUToast.makeToast(NebulaAppActivity.this,
                                success ? R.string.update_success : R.string.update_failure, 2000).show();
                    }
                });
            }
        });
    }
}
