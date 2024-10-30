package com.mpaas.cdpdemo;

import android.os.Bundle;
import android.text.TextUtils;
import android.view.View;
import android.widget.Toast;

import com.alipay.mobile.framework.LauncherApplicationAgent;
import com.alipay.mobile.framework.app.ui.BaseActivity;
import com.mpaas.cdp.CdpAdvertisementService;
import com.mpaas.cdp.CdpAdvertisementService.IAdGetSingleSpaceInfoCallBack;
import com.mpaas.cdp.CdpAdvertisementView;
import com.mpaas.cdp.structure.SpaceInfo;

/**
 * 研究一下动态广告如何接入，读一下原来的代码就成了
 */
public class PitActivity extends BaseActivity {
    protected CdpAdvertisementView mCdpView;
    protected String mSpaceCode;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_pit);
        mCdpView = (CdpAdvertisementView) findViewById(R.id.pit_cdp_cav);
        mCdpView.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                mCdpView.getChildAt(0);
            }
        });
    }

    @Override
    protected void onResume() {
        super.onResume();
        if (!TextUtils.isEmpty(mSpaceCode) && mCdpView != null) {
            mCdpView.updateSpaceCode(mSpaceCode);
            Toast.makeText(this, "Space Code: " + mSpaceCode, Toast.LENGTH_LONG).show();
            testQuery();
        }
    }

    private void testQuery() {
        CdpAdvertisementService serviceByInterface = LauncherApplicationAgent.getInstance().getMicroApplicationContext().findServiceByInterface(CdpAdvertisementService.class.getName());
        serviceByInterface.getSpaceInfoByCode( mSpaceCode ,new IAdGetSingleSpaceInfoCallBack(){

            @Override
            public void onSuccess(SpaceInfo spaceInfo) {
                spaceInfo.extInfo.get("some_key");

            }

            @Override
            public void onFail() {

            }
        });

    }
}
