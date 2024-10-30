package com.mpaas.cdpdemo;

import android.graphics.Color;
import android.os.Bundle;
import android.text.TextUtils;
import android.util.Log;
import android.view.View;
import android.widget.Toast;

import com.alipay.mobile.antui.basic.AUTextView;
import com.alipay.mobile.antui.basic.AUTitleBar;
import com.alipay.mobile.framework.LauncherApplicationAgent;
import com.alipay.mobile.framework.app.ui.BaseActivity;
import com.mpaas.cdp.CdpAdvertisementService;
import com.mpaas.cdp.CdpAdvertisementService.IAdGetSingleSpaceInfoCallBack;
import com.mpaas.cdp.CdpAdvertisementView;
import com.mpaas.cdp.structure.SpaceInfo;
import com.mpaas.cdp.structure.SpaceObjectInfo;

/**
 * 研究一下动态广告如何接入，读一下原来的代码就成了
 */
public class CustomActivity extends BaseActivity {
    protected CdpAdvertisementView mCdpView;
    protected String mSpaceCode = "custom_custom";
    private AUTextView pitContentTv;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_custom);
        ((AUTitleBar) findViewById(R.id.title_atb)).setTitleText("自渲染");
        mCdpView = (CdpAdvertisementView) findViewById(R.id.pit_cdp_cav);
        pitContentTv = (AUTextView) findViewById(R.id.pit_content_tv);
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
        serviceByInterface.getSpaceInfoByCode(mSpaceCode, new IAdGetSingleSpaceInfoCallBack() {

            @Override
            public void onSuccess(SpaceInfo spaceInfo) {
                Log.e("aaaaaaaaaa", spaceInfo.toString());
                if (spaceInfo == null ||
                        spaceInfo.spaceObjectList == null ||
                        spaceInfo.spaceObjectList.size() == 0) {
                    return;
                }
                SpaceObjectInfo spaceObjectInfo = spaceInfo.spaceObjectList.get(0);
                pitContentTv.setText(spaceObjectInfo.content);
                pitContentTv.setTextColor(Color.parseColor(spaceObjectInfo.textColor));
                pitContentTv.setBackgroundColor(Color.parseColor(spaceObjectInfo.bgColor));
            }

            @Override
            public void onFail() {

            }
        });

    }
}
