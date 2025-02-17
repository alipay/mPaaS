package com.mpaas.cdpdemo;

import android.content.Intent;
import android.os.Bundle;

import com.alipay.mobile.framework.LauncherApplicationAgent;
import com.alipay.mobile.framework.app.ui.BaseActivity;

/**
 * Created by gezihua on 2020/1/3.
 */

public class CdpTestUiViewActivity extends BaseActivity {
    public static void startActivity(BaseActivity cdpTestActivity) {

        Intent intent = new Intent();
        intent.setClass(cdpTestActivity, CdpTestUiViewActivity.class);
        cdpTestActivity.startActivity(intent);
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.mcdp_activity_test_ui_view);
        findViewById(R.id.cdp_test_ui_view_txt).setBackgroundResource(getMcdpSplashRoundImg());
    }

    private int getMcdpSplashRoundImg() {

        return LauncherApplicationAgent.getInstance().getBundleContext()
                .getResourcesByBundle("com-mpaas-cdp-cdp")
                .getIdentifier("mcp_splash_round_img","drawable","com.mpaas.cdp");

    }
}
