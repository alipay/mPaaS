package com.example.scan.demo;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Toast;

import com.alipay.android.phone.scancode.export.ScanCallback;
import com.alipay.android.phone.scancode.export.ScanRequest;
import com.alipay.android.phone.scancode.export.adapter.MPScan;
import com.example.scan.demo.R;
import com.example.scan.demo.util.DialogUtil;
import com.example.scan.demo.util.ThreadUtil;

import java.util.ArrayList;
import java.util.List;

public class ScanRequestActivity extends Activity {

    private ScanRequest scanRequest;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_scan_request);

        findViewById(R.id.btn_start_scan).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                scanWithStandardUI();
            }
        });
        findViewById(R.id.btn_ui_type).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                setUIType();
            }
        });
        findViewById(R.id.btn_translucent_status_bar).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                setTranslucentStatusBar();
            }
        });
        findViewById(R.id.btn_recognize_type).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                setRecognizeType();
            }
        });
        findViewById(R.id.btn_title).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                setTitle();
            }
        });
        findViewById(R.id.btn_hint).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                setHint();
            }
        });
        findViewById(R.id.btn_open_torch_text).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                setOpenTorchText();
            }
        });
        findViewById(R.id.btn_close_torch_text).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                setCloseTorchText();
            }
        });
        findViewById(R.id.btn_hide_album).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                setHideAlbum();
            }
        });

        scanRequest = new ScanRequest();
    }

    private void scanWithStandardUI() {
        MPScan.startMPaasScanActivity(this, scanRequest, new ScanCallback() {
            @Override
            public void onScanResult(final boolean isProcessed, final Intent result) {
                if (!isProcessed) {
                    // 扫码界面点击物理返回键或左上角返回键
                    return;
                }

                // 注意：本回调是在子线程中执行
                ThreadUtil.runOnMainThread(new Runnable() {
                    @Override
                    public void run() {
                        if (result == null || result.getData() == null) {
                            Toast.makeText(ScanRequestActivity.this, R.string.scan_failure, Toast.LENGTH_SHORT).show();
                            return;
                        }
                        String msg = result.getData().toString();
                        DialogUtil.alert(ScanRequestActivity.this, msg);
                        Log.d("ScanTest", msg);
                    }
                }, 500);
            }
        });
    }

    private void setUIType() {
        String[] types = {
                "二维码",
                "条形码"
        };
        DialogUtil.radio(this, "选择UI风格", types, new DialogUtil.RadioCallback() {
            @Override
            public void onConfirm(int which) {
                switch (which) {
                    case 0:
                        scanRequest.setScanType(ScanRequest.ScanType.QRCODE);
                        break;
                    case 1:
                        scanRequest.setScanType(ScanRequest.ScanType.BARCODE);
                        break;
                }
            }
        });
    }

    private void setTranslucentStatusBar() {
        String[] types = {
                "是",
                "否"
        };
        DialogUtil.radio(this, "设置透明状态栏", types, new DialogUtil.RadioCallback() {
            @Override
            public void onConfirm(int which) {
                switch (which) {
                    case 0:
                        scanRequest.setTranslucentStatusBar(true);
                        break;
                    case 1:
                        scanRequest.setTranslucentStatusBar(false);
                        break;
                }
            }
        });
    }

    private void setRecognizeType() {
        String[] types = {
                "二维码",
                "条形码",
                "DM码",
                "PDF417码"
        };
        DialogUtil.multiply(this, "选择识别类型", types, new DialogUtil.MultiplyCallback() {
            @Override
            public void onConfirm(boolean[] isChecked) {
                List<ScanRequest.RecognizeType> recognizeTypes = new ArrayList<>();
                for (int i = 0; i < isChecked.length; i++) {
                    if (isChecked[i]) {
                        switch (i) {
                            case 0:
                                recognizeTypes.add(ScanRequest.RecognizeType.QR_CODE);
                                break;
                            case 1:
                                recognizeTypes.add(ScanRequest.RecognizeType.BAR_CODE);
                                break;
                            case 2:
                                recognizeTypes.add(ScanRequest.RecognizeType.DM_CODE);
                                break;
                            case 3:
                                recognizeTypes.add(ScanRequest.RecognizeType.PDF417_Code);
                                break;
                        }
                    }
                }
                scanRequest.setRecognizeType(recognizeTypes.toArray(new ScanRequest.RecognizeType[0]));
            }
        });
    }

    private void setTitle() {
        DialogUtil.prompt(this, new DialogUtil.PromptCallback() {
            @Override
            public void onConfirm(String msg) {
                scanRequest.setTitleText(msg);
            }
        });
    }

    private void setHint() {
        DialogUtil.prompt(this, new DialogUtil.PromptCallback() {
            @Override
            public void onConfirm(String msg) {
                scanRequest.setViewText(msg);
            }
        });
    }

    private void setOpenTorchText() {
        DialogUtil.prompt(this, new DialogUtil.PromptCallback() {
            @Override
            public void onConfirm(String msg) {
                scanRequest.setOpenTorchText(msg);
            }
        });
    }

    private void setCloseTorchText() {
        DialogUtil.prompt(this, new DialogUtil.PromptCallback() {
            @Override
            public void onConfirm(String msg) {
                scanRequest.setCloseTorchText(msg);
            }
        });
    }

    private void setHideAlbum() {
        String[] types = {
                "是",
                "否"
        };
        DialogUtil.radio(this, "设置不显示相册", types, new DialogUtil.RadioCallback() {
            @Override
            public void onConfirm(int which) {
                switch (which) {
                    case 0:
                        scanRequest.setNotSupportAlbum(true);
                        break;
                    case 1:
                        scanRequest.setNotSupportAlbum(false);
                        break;
                }
            }
        });
    }
}
