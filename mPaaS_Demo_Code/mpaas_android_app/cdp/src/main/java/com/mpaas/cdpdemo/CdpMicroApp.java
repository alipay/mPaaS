package com.mpaas.cdpdemo;

import android.os.Bundle;
import android.text.TextUtils;

import com.alipay.mobile.common.logging.api.LoggerFactory;
import com.alipay.mobile.framework.LauncherApplicationAgent;
import com.alipay.mobile.framework.app.ActivityApplication;
import com.alipay.mobile.h5container.api.H5Bundle;
import com.alipay.mobile.h5container.api.H5Param;
import com.alipay.mobile.h5container.service.H5Service;
import com.mpaas.cdp.CdpAdvertisementService;

public class CdpMicroApp extends ActivityApplication {

    private Bundle mParam;

    @Override
    public String getEntryClassName() {
        return null;
    }

    @Override
    protected void onCreate(Bundle bundle) {
        mParam = bundle;
    }

    @Override
    protected void onStart() {
        doStart(mParam);
    }

    @Override
    protected void onRestart(Bundle bundle) {
        mParam = bundle;
        // 设置userId
        setCdpUserId();
        doStart(mParam);
    }

    private void setCdpUserId() {
        CdpAdvertisementService serviceByInterface = LauncherApplicationAgent.getInstance().getMicroApplicationContext().findServiceByInterface(CdpAdvertisementService.class.getName());
        if (serviceByInterface == null) {
            return;
        }
        serviceByInterface.setUserId(LoggerFactory.getLogContext().getUserId());
    }

    @Override
    protected void onStop() {

    }

    @Override
    protected void onDestroy(Bundle bundle) {

    }

    private void doStart(Bundle bundle) {
        String className = CdpMultiStyleActivity.class.getName();
        if (null != bundle) {
            String start = bundle.getString("start");
            if (!TextUtils.isEmpty(start)) {
                if ("MultiStyle".equals(start)) {
                    className = CdpMultiStyleActivity.class.getName();
                } else if ("Location".equals(start)) {
                    className = CdpLocationActivity.class.getName();
                } else if ("H5".equals(start)) {
                    startH5();
                    return;
                } else if ("Test".equals(start)) {
                    className = CdpTestActivity.class.getName();
                } else if ("feature".equalsIgnoreCase(start)) {
                    className = FeatureActivity.class.getName();

                }
            }
        }
        getMicroApplicationContext().startActivity(this, className);
    }

    public static void startH5() {
        String url = "https://mcube-prod.oss-cn-hangzhou.aliyuncs.com/A28254A291938-test/21111111/0.0.0.1_iOS/nebula/fallback/www/index.html";
        H5Service h5Service = LauncherApplicationAgent.getInstance().getMicroApplicationContext()
                .findServiceByInterface(H5Service.class.getName());
        Bundle h5Bundle = new Bundle();
        h5Bundle.putString(H5Param.LONG_URL, url);
        h5Service.startPage(LauncherApplicationAgent.getInstance().getMicroApplicationContext().getTopApplication(),
                new H5Bundle(h5Bundle));
    }

    @Override
    public String getAppId() {
        return "33340000";
    }
}

