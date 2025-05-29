package com.example.scan.demo.custom;

import android.content.Intent;
import android.view.View;

import androidx.core.app.ActivityCompat;
import androidx.fragment.app.Fragment;

import com.alipay.android.phone.scancode.export.adapter.MPScanResult;
import com.alipay.android.phone.scancode.export.permission.PermissionDelegate;
import com.alipay.mobile.scansdk.activity.MPaasToolsCaptureActivity;
import com.alipay.mobile.scansdk.ui2.MPCustomScanView;
import com.example.scan.demo.custom.widget.MyScanView;
import com.example.scan.demo.ui.MyCeilingDialog;
import com.example.scan.demo.util.DialogUtil;
import com.example.scan.demo.util.SPUtil;
import com.example.scan.demo.util.ThreadUtil;

import java.util.List;

public class MyScanActivity extends MPaasToolsCaptureActivity implements PermissionDelegate {

    private static final int REQUEST_CODE_PERMISSION = 1;
    private static final int REQUEST_CODE_PHOTO = 2;
    private MyScanView myScanView;
    private MyCeilingDialog permissionDialog;

    @Override
    protected MPCustomScanView getCustomScanView() {
        myScanView = new MyScanView(this);
        myScanView.setCallback(new MyScanView.Callback() {
            @Override
            public void onBackClicked(View view) {
                finish();
            }

            @Override
            public void onGalleryClicked(View view) {
                Intent intent = new Intent(Intent.ACTION_GET_CONTENT);
                intent.setType("image/*");
                startActivityForResult(intent, REQUEST_CODE_PHOTO);
            }

            @Override
            public void onMaIconClicked(View view, MPScanResult mpScanResult) {
                handleMPScanResult(mpScanResult);
            }
        });
        return myScanView;
    }

    @Override
    public void onActivityResult(int requestCode, int resultCode, final Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        if (data == null) {
            return;
        }
        if (requestCode == REQUEST_CODE_PHOTO) {
            if (data == null) {
                DialogUtil.alert(this, "获取图片异常");
                return;
            }
            ThreadUtil.runOnSubThread(new Runnable() {
                @Override
                public void run() {
                    final String path = data.getDataString();
                    final List<MPScanResult> mpScanResults = myScanView.scanFromPath(path);
                    ThreadUtil.runOnMainThread(new Runnable() {
                        @Override
                        public void run() {
                            myScanView.showMaResultWithIconForImage(MyScanActivity.this, mpScanResults, path);
                        }
                    });
                }
            });
        }
    }

    private void handleMPScanResult(MPScanResult mpScanResult) {
        String msg;
        if (mpScanResult == null) {
            msg = "没有识别到码";
        } else {
            msg = mpScanResult.getText();
        }
        DialogUtil.alert(MyScanActivity.this, msg, new DialogUtil.AlertCallback() {
            @Override
            public void onConfirm() {
                myScanView.removeAllIconViews();
                finish();
//                        restart();
            }
        });
    }

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
            int granted = SPUtil.getInt(MyScanActivity.this, "permission", -10);

            if(granted != -1) {
                if (permissionDialog == null) {
                    permissionDialog = new MyCeilingDialog(fragment.getContext(), "相机权限申请", "在下方弹窗中选择允许后，你可以使用扫一扫、刷脸、拍摄照片及视频等服务");
                }
                permissionDialog.show();
            }
        }
        fragment.requestPermissions(permissions, requestCode);
    }

    /**
     * 权限申请成功后的回调
     */
    @Override
    public void onPermissionGranted(Fragment fragment, int requestCode, String[] permissions, int[] grantResults) {
        dismissPermissionDialog();
    }

    /**
     * 权限被拒绝后的回调
     */
    @Override
    public void onPermissionDenied(Fragment fragment, int requestCode, String[] permissions, int[] grantResults) {
        dismissPermissionDialog();
        //用户禁止
        if(!ActivityCompat.shouldShowRequestPermissionRationale(fragment.getActivity(), permissions[0])){
            SPUtil.putInt(MyScanActivity.this, "permission", -1);
        }
    }

    private void dismissPermissionDialog(){
        if(permissionDialog != null){
            permissionDialog.dismiss();
            permissionDialog = null;
        }
    }

}
