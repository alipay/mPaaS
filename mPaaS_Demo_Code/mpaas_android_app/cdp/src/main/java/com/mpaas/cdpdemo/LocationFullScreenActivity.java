package com.mpaas.cdpdemo;

import android.os.Bundle;
import android.util.Log;

import com.alipay.mobile.antui.basic.AUTitleBar;
import com.alipay.mobile.common.logging.api.LoggerFactory;
import com.alipay.mobile.framework.LauncherApplicationAgent;
import com.mpaas.cdp.ActionExecutor;
import com.mpaas.cdp.CdpAdvertisementService;
import com.mpaas.cdp.structure.SpaceInfo;
import com.mpaas.cdp.structure.SpaceObjectInfo;

public class LocationFullScreenActivity extends DynamicActivity implements  ActionExecutor {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        ((AUTitleBar) findViewById(R.id.title_atb)).setTitleText(getString(R.string.full));
        interceptClick();
    }

    @Override
    public boolean interceptAction(SpaceInfo spaceInfo, SpaceObjectInfo spaceObjectInfo, String s) {
        return true;
    }

    @Override
    public int executeAction(SpaceInfo spaceInfo, SpaceObjectInfo spaceObjectInfo, String s) {
        Log.e("suj","跳转新地址："+s);
        return 0;
    }
    private void interceptClick() {
        CdpAdvertisementService serviceByInterface = LauncherApplicationAgent.getInstance().getMicroApplicationContext().findServiceByInterface(CdpAdvertisementService.class.getName());
        if (serviceByInterface == null) {
            return;
        }
        serviceByInterface.setActionExecutor(this);
    }
}