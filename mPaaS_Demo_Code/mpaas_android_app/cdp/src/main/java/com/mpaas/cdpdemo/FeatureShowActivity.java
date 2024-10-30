package com.mpaas.cdpdemo;

import android.content.Context;
import android.content.Intent;
import android.os.Bundle;

import com.alipay.mobile.antui.basic.AUTitleBar;
import com.alipay.mobile.framework.app.ui.BaseActivity;
import com.mpaas.cdp.CdpAdvertisementView;

/**
 * 这里用来展示上中下，单帧就好
 */
public class FeatureShowActivity extends BaseActivity {

    private CdpAdvertisementView pit_cdp_cav_bottom;
    private CdpAdvertisementView pit_cdp_cav_top;
    private CdpAdvertisementView pit_cdp_cav_center;

    public static void startActivity(Context applicationContext) {
        Intent intent = new Intent();
        intent.setClass(applicationContext, FeatureShowActivity.class);
        intent.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
        applicationContext.startActivity(intent);
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_feature_show);
        ((AUTitleBar) findViewById(R.id.title_atb)).setTitleText((String) getText(R.string.cdp_feature_show_title));
        pit_cdp_cav_bottom = (CdpAdvertisementView) findViewById(R.id.pit_cdp_cav_bottom);
        pit_cdp_cav_top = (CdpAdvertisementView) findViewById(R.id.pit_cdp_cav_top);
        pit_cdp_cav_center = (CdpAdvertisementView) findViewById(R.id.pit_cdp_cav_center);

    }


    @Override
    protected void onResume() {
        super.onResume();
        pit_cdp_cav_bottom.updateSpaceCode("pit_cdp_cav_bottom");
        pit_cdp_cav_top.updateSpaceCode("pit_cdp_cav_top");
        pit_cdp_cav_center.updateSpaceCode("pit_cdp_cav_center");

    }
}
