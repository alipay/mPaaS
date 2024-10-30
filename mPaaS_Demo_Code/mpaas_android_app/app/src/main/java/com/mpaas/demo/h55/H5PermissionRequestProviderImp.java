package com.mpaas.demo.h55;

import static com.mpaas.demo.sync.BaseSyncActivity.TAG;

import android.Manifest;
import android.webkit.ValueCallback;

import com.alipay.mobile.antui.dialog.AUNoticeDialog;
import com.alipay.mobile.framework.LauncherApplicationAgent;
import com.alipay.mobile.framework.permission.RequestPermissionsResultCallback;
import com.alipay.mobile.h5container.api.H5Page;
import com.alipay.mobile.h5container.service.H5Service;
import com.alipay.mobile.nebula.permission.H5PermissionCallback;
import com.alipay.mobile.nebula.util.H5Log;
import com.alipay.mobile.nebula.util.H5ServiceUtils;
import com.alipay.mobile.nebulacore.util.PermissionUtils;
import com.alipay.mobile.nebulauc.provider.H5PermissionRequestProvider;

import java.util.HashMap;
import java.util.Map;

public class H5PermissionRequestProviderImp implements H5PermissionRequestProvider {
    @Override
    public boolean generalPermissions(Map<String, String> params, final ValueCallback<Map<String, String>> valueCallback) {
        String type = (String) params.get("type");
        String url = params.get("origin");
        String[] permissionsTemp = null;
        String desc = "";
        if ("microphone".equalsIgnoreCase(type)) {
            permissionsTemp = new String[]{Manifest.permission.RECORD_AUDIO};
            desc = "录音";
        } else if ("camera".equalsIgnoreCase(type)) {
            permissionsTemp = new String[]{Manifest.permission.CAMERA};
            desc = "相机";
        }

        if (permissionsTemp == null) {
            return false;
        }

        final String[] permissions = permissionsTemp;
        H5Service h5Service = H5ServiceUtils.getH5Service();
        H5Page h5Page = null;
        if (h5Service != null) {
            h5Page = h5Service.getTopH5Page();
        }
        if (h5Page == null) {
            Map<String, String> results = new HashMap();
            results.put("allow", "no");
            valueCallback.onReceiveValue(results);
            return true;
        }
        AUNoticeDialog dialog;

        (dialog = new AUNoticeDialog(h5Page.getContext().getContext(), (CharSequence) null, "是否允许" + url + "获取" + desc + "权限", "允许", "不允许")).setPositiveListener(new AUNoticeDialog.OnClickPositiveListener() {
            public void onClick() {
                LauncherApplicationAgent.getInstance().getMicroApplicationContext()
                        .requestPermissions(permissions,
                                H5PermissionCallback.H5_PERMISSIONS_REQUEST_CODE,
                                new RequestPermissionsResultCallback() {
                                    @Override
                                    public void onRequestPermissionsResult(int i, String[] strings, int[] ints) {
                                        boolean success = PermissionUtils.verifyPermissions(ints);
                                        H5Log.d(TAG, "onCheckSelfPermission permission: " + success);
                                        Map<String, String> results = new HashMap();
                                        results.put("allow", success ? "yes" : "no");
                                        valueCallback.onReceiveValue(results);
                                    }
                                });

                H5Log.d("H5ApiBizPermissionManager", "checkWebARCameraPermission...allow");
            }
        });
        dialog.setNegativeListener(new AUNoticeDialog.OnClickNegativeListener() {
            public void onClick() {
                Map<String, String> results = new HashMap();
                results.put("allow", "no");
                valueCallback.onReceiveValue(results);
                H5Log.d("H5ApiBizPermissionManager", "checkWebARCameraPermission...cancel");
            }
        });
        dialog.setCanceledOnTouchOutside(false);
        dialog.setCancelable(false);
        dialog.show();
        return true;
    }
}
