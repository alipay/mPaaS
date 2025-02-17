package com.example.h5;

import android.webkit.ValueCallback;

import com.alipay.mobile.nebulauc.provider.H5PermissionRequestProvider;
import com.mpaas.mas.adapter.api.MPLogger;

import java.util.Map;

public class H5PermissionRequestProviderImp implements H5PermissionRequestProvider {
    @Override
    public boolean generalPermissions(Map<String, String> map, ValueCallback<Map<String, String>> valueCallback) {
        MPLogger.info("权限拦截", map.toString() + "\n" + valueCallback.toString());
        return false;
    }
}
