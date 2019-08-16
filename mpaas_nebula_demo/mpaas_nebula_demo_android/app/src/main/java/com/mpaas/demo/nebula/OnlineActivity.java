package com.mpaas.demo.nebula;

import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.view.View;

import com.alipay.android.phone.scancode.export.ScanCallback;
import com.alipay.android.phone.scancode.export.ScanRequest;
import com.alipay.android.phone.scancode.export.ScanService;
import com.alipay.mobile.antui.basic.AUButton;
import com.alipay.mobile.antui.basic.AUTitleBar;
import com.alipay.mobile.antui.basic.AUToast;
import com.alipay.mobile.antui.common.AUCheckIcon;
import com.alipay.mobile.framework.app.ui.BaseActivity;
import com.alipay.mobile.h5container.api.H5Param;
import com.mpaas.framework.adapter.api.MPFramework;
import com.mpaas.nebula.adapter.api.MPNebula;


public class OnlineActivity extends BaseActivity {

    private AUCheckIcon ciCanPullDown;

    private AUCheckIcon ciShowTitle;

    private AUCheckIcon ciShowProgress;

    private AUTitleBar mTitle;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        mTitle = (AUTitleBar) findViewById(R.id.titlebar);
        ciCanPullDown = (AUCheckIcon) findViewById(R.id.cb_pull_down);
        ciCanPullDown.setIconState(AUCheckIcon.STATE_CHECKED);
        ciShowProgress = (AUCheckIcon) findViewById(R.id.cb_progress);
        ciShowProgress.setIconState(AUCheckIcon.STATE_CHECKED);
        ciShowTitle = (AUCheckIcon) findViewById(R.id.cb_title);
        ciShowTitle.setIconState(AUCheckIcon.STATE_CHECKED);

        AUButton button = (AUButton) findViewById(R.id.btn_scan_open_page);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                ScanService service = MPFramework.getMicroApplicationContext()
                        .findServiceByInterface(ScanService.class.getName());
                ScanRequest scanRequest = new ScanRequest();
                scanRequest.setScanType(ScanRequest.ScanType.QRCODE);
                service.scan(OnlineActivity.this, scanRequest, new ScanCallback() {
                    @Override
                    public void onScanResult(boolean isSuccess, Intent result) {
                        if (!isSuccess) {
                            AUToast.makeToast(OnlineActivity.this, R.string.error_scan_code, 2000).show();
                            return;
                        }
                        Uri uri = result.getData();
                        if (uri == null) {
                            AUToast.makeToast(OnlineActivity.this, R.string.error_scan_code, 2000).show();
                            return;
                        }

                        String url = uri.toString();
                        Bundle bundle = new Bundle();
                        bundle.putString(H5Param.LONG_URL, url);
                        bundle.putBoolean(H5Param.LONG_SHOW_TITLEBAR, ciShowTitle.getIconState() == AUCheckIcon.STATE_CHECKED);
                        bundle.putBoolean(H5Param.LONG_SHOW_PROGRESS, ciShowProgress.getIconState() == AUCheckIcon.STATE_CHECKED);
                        bundle.putBoolean(H5Param.LONG_CAN_PULL_DOWN, ciCanPullDown.getIconState() == AUCheckIcon.STATE_CHECKED);
                        MPNebula.startUrl(url, bundle);
                    }
                });
            }
        });
        mTitle.setTitleText(getString(R.string.title));
    }
}
