package com.example.scan.demo;

import android.app.Activity;
import android.content.Context;
import android.os.Bundle;
import android.view.View;
import android.widget.Toast;

import androidx.core.app.ActivityCompat;
import androidx.fragment.app.Fragment;

import com.alipay.android.phone.scancode.export.ScanRequest;
import com.alipay.android.phone.scancode.export.adapter.MPScan;
import com.alipay.android.phone.scancode.export.adapter.MPScanCallbackAdapter;
import com.alipay.android.phone.scancode.export.adapter.MPScanResult;
import com.alipay.android.phone.scancode.export.adapter.MPScanStarter;
import com.alipay.android.phone.scancode.export.permission.PermissionDelegate;
import com.alipay.mobile.common.logging.api.LoggerFactory;
import com.example.scan.demo.R;
import com.example.scan.demo.ui.MyCeilingDialog;
import com.example.scan.demo.util.DialogUtil;
import com.example.scan.demo.util.SPUtil;

import java.util.ArrayList;
import java.util.List;

public class ScanFullScreenActivity extends Activity {

    private ScanRequest scanRequest;
    private String TAG = "ScanFullScreenActivity";
    MyCeilingDialog permissionDialog;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_scan_fullscreen);

        findViewById(R.id.btn_start_scan).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                scanFullScreen();
            }
        });
        findViewById(R.id.btn_start_scan_continuously).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                scanFullScreenContinuously();
            }
        });
        findViewById(R.id.btn_fetch_multi_ma_results).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                setFetchMultiMaResults();
            }
        });

        findViewById(R.id.btn_recognize_type).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                setRecognizeType();
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
        findViewById(R.id.btn_multi_ma_marker).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                setMultiMaMarker();
            }
        });
        findViewById(R.id.btn_multi_ma_tip).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                setMultiMaTip();
            }
        });
        findViewById(R.id.btn_target_ma_color).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                setTargetMaColor();
            }
        });
        findViewById(R.id.btn_enable_ai).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                setAI();
            }
        });
        findViewById(R.id.btn_delay_tip_text).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                setDelayTipText();
            }
        });
        findViewById(R.id.btn_delay_tip_time).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                setDelayTipTime();
            }
        });
        findViewById(R.id.btn_enable_album_multi_code).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                scanRequest.setEnableAlbumMultiCode(true);
            }
        });
        findViewById(R.id.btn_close_permission_delegate).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                scanRequest.setPermissionDelegate(null);
            }
        });

        scanRequest = new ScanRequest();
        setPermissionDelegate();
    }

    private void scanFullScreen() {
        MPScan.startMPaasScanFullScreenActivity(this, scanRequest, new MPScanCallbackAdapter() {

            @Override
            public boolean onScanFinish(final Context context, MPScanResult mpScanResult, final MPScanStarter mpScanStarter) {
                DialogUtil.alert((Activity) context,
                        mpScanResult != null ? mpScanResult.getText() : "没有识别到码", new DialogUtil.AlertCallback() {
                            @Override
                            public void onConfirm() {
                                ((Activity) context).finish();
                            }
                        });
                return true;
            }

            /* 重写该方法可获取全部码结果 */
            @Override
            public boolean onScanFinish(final Context context, List<MPScanResult> results, MPScanStarter mpScanStarter) {
                StringBuilder content = new StringBuilder();
                for (MPScanResult result : results) {
                    content.append(result.getText()).append("\n");
                }
                if (content.length() == 0) {
                    content.append("没有识别到码");
                }
                DialogUtil.alert((Activity) context, content.toString()
                        , new DialogUtil.AlertCallback() {
                            @Override
                            public void onConfirm() {
                                ((Activity) context).finish();
                            }
                        });
                return true;
            }
        });
    }

    private void scanFullScreenContinuously() {
        MPScan.startMPaasScanFullScreenActivity(this, scanRequest, new MPScanCallbackAdapter() {

            @Override
            public boolean onScanFinish(final Context context, MPScanResult mpScanResult, final MPScanStarter mpScanStarter) {
                DialogUtil.alert((Activity) context,
                        mpScanResult != null ? mpScanResult.getText() : "没有识别到码", new DialogUtil.AlertCallback() {
                            @Override
                            public void onConfirm() {
                                mpScanStarter.restart();
                            }
                        });
                return false;
            }

            /* 重写该方法可获取全部码结果 */
            @Override
            public boolean onScanFinish(final Context context, List<MPScanResult> results, final MPScanStarter mpScanStarter) {
                StringBuilder content = new StringBuilder();
                for (MPScanResult result : results) {
                    content.append(result.getText()).append("\n");
                }
                if (content.length() == 0) {
                    content.append("没有识别到码");
                }
                DialogUtil.alert((Activity) context, content.toString()
                        , new DialogUtil.AlertCallback() {
                            @Override
                            public void onConfirm() {
                                mpScanStarter.restart();
                            }
                        });
                return false;
            }
        });
    }

    private void setFetchMultiMaResults() {
        String[] types = {
                "是",
                "否"
        };
        DialogUtil.radio(this, "设置获取全部码结果", types, new DialogUtil.RadioCallback() {
            @Override
            public void onConfirm(int which) {
                switch (which) {
                    case 0:
                        scanRequest.setFetchMultiMaResults(true);
                        break;
                    case 1:
                        scanRequest.setFetchMultiMaResults(false);
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

    private void setMultiMaMarker() {
        String[] images = {
                "默认",
                "绿箭头"
        };
        DialogUtil.radio(this, "设置多码标识图片", images, new DialogUtil.RadioCallback() {
            @Override
            public void onConfirm(int which) {
                switch (which) {
                    case 0:
                        scanRequest.setMultiMaMarker(-1);
                        break;
                    case 1:
                        scanRequest.setMultiMaMarker(R.drawable.green_arrow);
                        break;
                }
            }
        });
    }

    private void setMultiMaTip() {
        DialogUtil.prompt(this, new DialogUtil.PromptCallback() {
            @Override
            public void onConfirm(String msg) {
                scanRequest.setMultiMaTipText(msg);
            }
        });
    }

    private void setTargetMaColor() {
        String[] colors = {
                "默认",
                "绿色",
        };
        DialogUtil.radio(this, "设置选中单码标识颜色", colors, new DialogUtil.RadioCallback() {
            @Override
            public void onConfirm(int which) {
                switch (which) {
                    case 0:
                        scanRequest.setMaTargetColor(null);
                        break;
                    case 1:
                        scanRequest.setMaTargetColor("#32CD32");
                        break;
                }
            }
        });
    }

    private void setAI() {
        String[] types = {
                "是",
                "否"
        };
        DialogUtil.radio(this, "设置开启AI", types, new DialogUtil.RadioCallback() {
            @Override
            public void onConfirm(int which) {
                switch (which) {
                    case 0:
                        scanRequest.setEnableAI(true);
                        break;
                    case 1:
                        scanRequest.setEnableAI(false);
                        break;
                }
            }
        });
    }

    private void setDelayTipText() {
        DialogUtil.prompt(this, new DialogUtil.PromptCallback() {
            @Override
            public void onConfirm(String msg) {
                scanRequest.setDelayTipText(msg);
            }
        });
    }

    private void setDelayTipTime() {
        DialogUtil.prompt(this, new DialogUtil.PromptCallback() {
            @Override
            public void onConfirm(String msg) {
                try {
                    long time = Long.parseLong(msg);
                    scanRequest.setDelayTipTime(time);
                } catch (NumberFormatException e) {
                    Toast.makeText(ScanFullScreenActivity.this, "时间格式错误", Toast.LENGTH_SHORT).show();
                }
            }
        });
    }

    private void setPermissionDelegate(){
        scanRequest.setPermissionDelegate(new PermissionDelegate() {


            /**
             * 开始申请权限，用户可在这里实现自己的权限申请交互或者权限说明
             * 注意：用户在做完自己的事情后需要去申请权限，否则流程会卡住
             * @param fragment 扫码页面
             * @param requestCode   1:相机权限
             * @param permissions
             *
             */
            @Override
            public void onRequestPermission(Fragment fragment, final int requestCode, final String[] permissions) {
                //处理相机权限
                if(requestCode == 1){
                    int granted = SPUtil.getInt(ScanFullScreenActivity.this, "permission", -10);

                    LoggerFactory.getTraceLogger().debug(TAG, "onRequestPermission，requestCode="+requestCode+", granted="+granted);

                    if(granted != -1) {
                        if (permissionDialog == null) {
                            permissionDialog = new MyCeilingDialog(fragment.getContext(), "相机权限申请", "在下方弹窗中选择允许后，你可以使用扫一扫、刷脸、拍摄照片及视频等服务");
                        }
                        permissionDialog.show();
                    }
                }
                //开始申请权限
                fragment.requestPermissions(permissions, requestCode);
            }

            /**
             * 权限申请成功后的回调
             */
            @Override
            public void onPermissionGranted(Fragment fragment, int requestCode, String[] permissions, int[] grantResults) {
                LoggerFactory.getTraceLogger().debug(TAG, "onPermissionGranted");

                dismissPermissionDialog();
            }

            /**
             * 权限被拒绝后的回调
             */
            @Override
            public void onPermissionDenied(Fragment fragment, int requestCode, String[] permissions, int[] grantResults) {
                LoggerFactory.getTraceLogger().debug(TAG, "onPermissionDenied");

                dismissPermissionDialog();
                //用户禁止
                if(!ActivityCompat.shouldShowRequestPermissionRationale(fragment.getActivity(), permissions[0])){
                    LoggerFactory.getTraceLogger().debug(TAG, "user reject permission");
                    SPUtil.putInt(ScanFullScreenActivity.this, "permission", -1);
                }
            }

            private void dismissPermissionDialog(){
                if(permissionDialog != null){
                    permissionDialog.dismiss();
                    permissionDialog = null;
                }
            }
        });
    }
}
