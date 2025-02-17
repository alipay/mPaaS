package com.mpaas.cdpdemo;

import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.text.TextUtils;
import android.view.View;
import android.widget.Toast;

import com.alipay.mobile.antui.basic.AUTitleBar;
import com.alipay.mobile.framework.app.ui.BaseActivity;
import com.mpaas.cdp.CdpAdvertisementView;

public class FeatureNewActivityActivity extends BaseActivity {
    protected CdpAdvertisementView mCdpView;
    protected String mSpaceCode;

    public static void startActivity(Context applicationContext) {
        Intent intent = new Intent();
        intent.setClass(applicationContext, FeatureNewActivityActivity.class);
        intent.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
        applicationContext.startActivity(intent);
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_feature_new);
        mCdpView = (CdpAdvertisementView) findViewById(R.id.pit_cdp_cav);
        mCdpView.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                mCdpView.getChildAt(0);
            }
        });
        ((AUTitleBar) findViewById(R.id.title_atb)).setTitleText((String) getText(R.string.cdp_feature_new_title));
        mSpaceCode = "feature_space_new_adcode";

    }

    @Override
    protected void onResume() {
        super.onResume();
        if (!TextUtils.isEmpty(mSpaceCode) && mCdpView != null) {
            mCdpView.updateSpaceCode(mSpaceCode);
            Toast.makeText(this, "Space Code: " + mSpaceCode, Toast.LENGTH_LONG).show();
        }
    }
}
