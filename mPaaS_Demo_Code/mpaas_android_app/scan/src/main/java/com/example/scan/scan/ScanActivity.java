package com.example.scan.scan;

import android.app.Activity;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Toast;

import androidx.annotation.Nullable;
import androidx.appcompat.app.ActionBar;
import androidx.appcompat.app.AppCompatActivity;

import com.alipay.android.phone.scancode.export.ScanRequest;
import com.alipay.android.phone.scancode.export.adapter.MPScan;
import com.alipay.android.phone.scancode.export.adapter.MPScanCallbackAdapter;
import com.alipay.android.phone.scancode.export.adapter.MPScanResult;
import com.alipay.android.phone.scancode.export.adapter.MPScanStarter;
import com.example.scan.CustomScanActivity;
import com.example.scan.R;
import com.example.scan.ScanHelper;
import com.example.scan.Utils;


/**
 * Created by xingcheng on 2018/8/8.
 */

public class ScanActivity extends AppCompatActivity {
    public static boolean isOpen = false;

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_scan);

        ActionBar actionBar = getSupportActionBar();
        if (actionBar != null) {
            actionBar.setTitle(R.string.scan_title);
        }

        findViewById(R.id.standard_ui_btn).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startActivity(new Intent(ScanActivity.this, ScanRequestActivity.class));
            }
        });

        findViewById(R.id.custom_ui_btn).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                scanWithCustomUI();
            }
        });
        findViewById(R.id.morecode_ui_btn).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                morecode();
            }
        });
        findViewById(R.id.btn_close_open_torch).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                isOpen = !isOpen;
                if (isOpen){
                    Utils.toast(ScanActivity.this, "光线暗，自动打开手电筒");
                }else{
                    Utils.toast(ScanActivity.this, "光线暗，提示自动打开手电筒");
                }
            }
        });
    }

    private void scanWithCustomUI() {
        ScanHelper.getInstance().scan(this, new ScanHelper.ScanCallback() {
            @Override
            public void onScanResult(boolean isProcessed, Intent result) {
                if (!isProcessed) {
                    // 扫码界面点击物理返回键或左上角返回键
                    return;
                }

                if (result == null || result.getData() == null) {
                    Toast.makeText(ScanActivity.this, R.string.scan_failure, Toast.LENGTH_SHORT).show();
                    return;
                }
                DialogUtil.alert(ScanActivity.this, result.getData().toString());
            }
        });
    }

    private void morecode() {
        ScanRequest scanRequest = new ScanRequest();
        MPScan.startMPaasScanFullScreenActivity(this, scanRequest, new MPScanCallbackAdapter() {
            @Override
            public boolean onScanFinish(final Context context, MPScanResult mpScanResult, final MPScanStarter mpScanStarter) {
                Toast.makeText(getApplicationContext(),
                        mpScanResult != null ? mpScanResult.getText() : "没有识别到码", Toast.LENGTH_SHORT).show();
                ((Activity) context).finish();
                // 返回 true 表示该回调已消费，不需要再次回调
                return true;
            }
        });
    }
}
