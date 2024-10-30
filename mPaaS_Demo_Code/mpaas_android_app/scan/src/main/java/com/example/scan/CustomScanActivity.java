
package com.example.scan;

import android.Manifest;
import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.graphics.Bitmap;
import android.graphics.Matrix;
import android.graphics.Rect;
import android.net.Uri;
import android.os.Build;
import android.os.Bundle;
import android.text.TextUtils;
import android.view.View;
import android.view.WindowManager;
import android.widget.ImageView;

import androidx.annotation.NonNull;
import androidx.core.app.ActivityCompat;
import androidx.core.content.PermissionChecker;

import com.alipay.android.phone.scancode.export.adapter.MPRecognizeType;
import com.alipay.android.phone.scancode.export.adapter.MPScanError;
import com.alipay.android.phone.scancode.export.adapter.MPScanResult;
import com.alipay.android.phone.scancode.export.adapter.MPScanner;
import com.alipay.android.phone.scancode.export.listener.MPImageGrayListener;
import com.alipay.android.phone.scancode.export.listener.MPScanListener;
import com.alipay.mobile.common.logging.api.LoggerFactory;
import com.example.scan.scan.ScanActivity;
import com.example.scan.widget.APTextureView;
import com.example.scan.widget.ScanView;

import java.util.List;

public class CustomScanActivity extends Activity {

    private final String TAG = CustomScanActivity.class.getSimpleName();
    private static final int REQUEST_CODE_PERMISSION = 1;
    private static final int REQUEST_CODE_PHOTO = 2;

    private ImageView mTorchBtn;
    private APTextureView mTextureView;
    private ScanView mScanView;

    private boolean isFirstStart = true;
    private boolean isPermissionGranted;
    private boolean isScanning;
    private boolean isPaused;

    private Rect scanRect;
    private MPScanner mpScanner;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_custom_scan);

        // 设置沉浸模式
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.KITKAT) {
            getWindow().setFlags(
                    WindowManager.LayoutParams.FLAG_TRANSLUCENT_STATUS,
                    WindowManager.LayoutParams.FLAG_TRANSLUCENT_STATUS);
        }

        mTextureView = findViewById(R.id.surface_view);
        mScanView = findViewById(R.id.scan_view);
        findViewById(R.id.gallery).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                pickImageFromGallery();
            }
        });
        mTorchBtn = findViewById(R.id.torch);
        mTorchBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                switchTorch();
            }
        });
        findViewById(R.id.back).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                onBackPressed();
            }
        });
        initMPScanner();
        checkCameraPermission();
    }

    private void initMPScanner() {
        mpScanner = new MPScanner(this);
        mpScanner.setRecognizeType(
                MPRecognizeType.QR_CODE,
                MPRecognizeType.BAR_CODE,
                MPRecognizeType.DM_CODE,
                MPRecognizeType.PDF417_CODE
        );
        mpScanner.setMPScanListener(new MPScanListener() {
            @Override
            public void onConfiguration() {
                mpScanner.setDisplayView(mTextureView);
            }

            @Override
            public void onStart() {
                if (!isPaused) {
                    runOnUiThread(new Runnable() {
                        @Override
                        public void run() {
                            if (!isFinishing()) {
                                initScanRect();
                                mScanView.onStartScan();
                            }
                        }
                    });
                }
            }

            @Override
            public void onSuccess(List<MPScanResult> list) {
                mpScanner.beep();
                if (list!=null){
                    onScanSuccess(list.get(0));
                }
            }


            @Override
            public void onError(MPScanError mpScanError) {
                if (!isPaused) {
                    runOnUiThread(new Runnable() {
                        @Override
                        public void run() {
                            Utils.toast(CustomScanActivity.this, getString(R.string.camera_open_error));
                        }
                    });
                }
            }
        });
        mpScanner.setMPImageGrayListener(new MPImageGrayListener() {
            @Override
            public void onGetImageGray(int gray) {
                // 注意：该回调在昏暗环境下可能会连续多次执行
                if (gray < MPImageGrayListener.LOW_IMAGE_GRAY) {
                    runOnUiThread(new Runnable() {
                        @Override
                        public void run() {
                            if (ScanActivity.isOpen) {
                                mpScanner.openTorch();
                            } else {
                                Utils.toast(CustomScanActivity.this, getString(R.string.flashlight_light_Tips));
                            }
                        }
                    });
                }
            }
        });
    }

    private void pickImageFromGallery() {
        Intent intent = new Intent(Intent.ACTION_GET_CONTENT);
        intent.setType("image/*");
        startActivityForResult(intent, REQUEST_CODE_PHOTO);
    }

    private void switchTorch() {
        boolean torchOn = mpScanner.switchTorch();
        mTorchBtn.setSelected(torchOn);
    }

    @Override
    public void onPause() {
        super.onPause();
        isPaused = true;
        if (isScanning) {
            stopScan();
        }
    }

    @Override
    public void onResume() {
        super.onResume();
        isPaused = false;
        if (!isFirstStart && isPermissionGranted) {
            startScan();
        }
    }

    @Override
    public void onDestroy() {
        super.onDestroy();
        mpScanner.release();
    }

    private void checkCameraPermission() {
        if (PermissionChecker.checkSelfPermission(
                this, Manifest.permission.CAMERA) != PermissionChecker.PERMISSION_GRANTED) {
            ActivityCompat.requestPermissions(this, new String[]{Manifest.permission.CAMERA}, REQUEST_CODE_PERMISSION);
        } else {
            onPermissionGranted();
        }
    }

    @Override
    public void onRequestPermissionsResult(int requestCode, @NonNull String[] permissions, @NonNull int[] grantResults) {
        super.onRequestPermissionsResult(requestCode, permissions, grantResults);
        if (requestCode == REQUEST_CODE_PERMISSION) {
            int length = Math.min(permissions.length, grantResults.length);
            for (int i = 0; i < length; i++) {
                if (TextUtils.equals(permissions[i], Manifest.permission.CAMERA)) {
                    if (grantResults[i] != PackageManager.PERMISSION_GRANTED) {
                        Utils.toast(this, getString(R.string.camera_no_permission));
                    } else {
                        onPermissionGranted();
                    }
                    break;
                }
            }
        }
    }

    private void onPermissionGranted() {
        isPermissionGranted = true;
        startScan();
    }

    private void scanFromUri(Uri uri) {
        final Bitmap bitmap = Utils.uri2Bitmap(this, uri);
        if (bitmap == null) {
            notifyScanResult(true, null);
            finish();
        } else {
            new Thread(new Runnable() {
                @Override
                public void run() {
                    MPScanResult mpScanResult = mpScanner.scanFromBitmap(bitmap);
                    mpScanner.beep();
                    onScanSuccess(mpScanResult);
                }
            }, "scanFromUri").start();
        }
    }

    private void onScanSuccess(final MPScanResult result) {
        runOnUiThread(new Runnable() {
            @Override
            public void run() {
                if (result == null) {
                    notifyScanResult(true, null);
                } else {
                    Intent intent = new Intent();
                    intent.setData(Uri.parse(result.getText()));
                    notifyScanResult(true, intent);
                }
                CustomScanActivity.this.finish();
            }
        });
    }

    private void startScan() {
        try {
            mpScanner.openCameraAndStartScan();
            isScanning = true;
        } catch (Exception e) {
            isScanning = false;
            LoggerFactory.getTraceLogger().error(TAG, "startScan: Exception " + e.getMessage());
        }
    }

    private void stopScan() {
        mpScanner.closeCameraAndStopScan();
        mScanView.onStopScan();
        isScanning = false;
        if (isFirstStart) {
            isFirstStart = false;
        }
    }

    private void initScanRect() {
        if (scanRect == null) {
            scanRect = mScanView.getScanRect(mpScanner.getCamera(), mTextureView.getWidth(), mTextureView.getHeight());

            float cropWidth = mScanView.getCropWidth();
            LoggerFactory.getTraceLogger().debug(TAG, "cropWidth: " + cropWidth);
            if (cropWidth > 0) {
                // 预览放大 ＝ 屏幕宽 ／ 裁剪框宽
                WindowManager wm = (WindowManager) getSystemService(Context.WINDOW_SERVICE);
                float screenWith = wm.getDefaultDisplay().getWidth();
                float screenHeight = wm.getDefaultDisplay().getHeight();
                float previewScale = screenWith / cropWidth;
                if (previewScale < 1.0f) {
                    previewScale = 1.0f;
                }
                if (previewScale > 1.5f) {
                    previewScale = 1.5f;
                }
                LoggerFactory.getTraceLogger().debug(TAG, "previewScale: " + previewScale);
                Matrix transform = new Matrix();
                transform.setScale(previewScale, previewScale, screenWith / 2, screenHeight / 2);
                mTextureView.setTransform(transform);
            }
        }
        mpScanner.setScanRegion(scanRect);
    }

    private void notifyScanResult(boolean isProcessed, Intent resultData) {
        ScanHelper.getInstance().notifyScanResult(isProcessed, resultData);
    }

    @Override
    public void onBackPressed() {
        super.onBackPressed();
        notifyScanResult(false, null);
    }

    @Override
    public void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        if (data == null) {
            return;
        }
        if (requestCode == REQUEST_CODE_PHOTO) {
            scanFromUri(data.getData());
        }
    }
}
