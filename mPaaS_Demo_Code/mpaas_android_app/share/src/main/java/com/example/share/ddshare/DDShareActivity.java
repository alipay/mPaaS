package com.example.share.ddshare;

import android.app.Activity;
import android.os.Bundle;
import android.widget.Toast;

import com.alipay.mobile.antui.basic.AUToast;
import com.alipay.mobile.antui.utils.PublicResources;
import com.android.dingtalk.share.ddsharemodule.DDShareApiFactory;
import com.android.dingtalk.share.ddsharemodule.IDDAPIEventHandler;
import com.android.dingtalk.share.ddsharemodule.IDDShareApi;
import com.android.dingtalk.share.ddsharemodule.message.BaseReq;
import com.android.dingtalk.share.ddsharemodule.message.BaseResp;
import com.example.share.R;

public class DDShareActivity extends Activity implements IDDAPIEventHandler {

    private IDDShareApi mIDDShareApi;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        try {
            mIDDShareApi = DDShareApiFactory.createDDShareApi(this, "dingoa7rxo7sxowhwpg5ke", false);
            mIDDShareApi.handleIntent(getIntent(), this);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    @Override
    public void onReq(BaseReq baseReq) {
    }

    @Override
    public void onResp(BaseResp baseResp) {
        int errCode = baseResp.mErrCode;
        String errMsg = baseResp.mErrStr;
        switch (errCode) {
            case BaseResp.ErrCode.ERR_OK:
                AUToast.makeToast(this, PublicResources.Toast_OK, getString(R.string.share_success), Toast.LENGTH_SHORT).show();
                break;
            case BaseResp.ErrCode.ERR_USER_CANCEL:
                AUToast.makeToast(this, PublicResources.Toast_Warn, getString(R.string.share_cancel), Toast.LENGTH_SHORT).show();
                break;
            default:
                AUToast.makeToast(this, PublicResources.Toast_False, getString(R.string.share_error) + "\n" + errCode + ", " + errMsg, Toast.LENGTH_SHORT).show();
                break;
        }
        finish();
    }
}
