package com.mpaas.demo.sync;

import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Toast;

import com.alipay.mobile.common.logging.api.LoggerFactory;
import com.mpaas.demo.R;
import com.mpaas.mas.adapter.api.MPLogger;
import com.mpaas.mss.adapter.api.MPSync;

import java.util.List;

/**
 * Created by larry.cl.
 */
public class UserBasedSyncActivity extends BaseSyncActivity {
    private String resultData = "";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
    }

    @Override
    protected void fetchSyncData(final String data) {
        Log.e("aaaaaaaaaa", "data:   " + data);
        UserBasedSyncActivity.this.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                String msg = data;
                if (msg.indexOf("sync_h5") != -1) {
                    //更新H5 80808080
                    updateApp("80808080");
                }
                tvSyncMsg.setText(msg);
                resultData = msg;
//                Toast.makeText(UserBasedSyncActivity.this, UserBasedSyncActivity.this.getString(R.string.sync_uidData) + data
//                        , Toast.LENGTH_SHORT).show();
            }
        });
    }

    @Override
    public void bindViews() {
        super.bindViews();
        mInputUid.setVisibility(View.VISIBLE);
        mInputSessionId.setVisibility(View.VISIBLE);
        mBtnBind.setVisibility(View.VISIBLE);
        mBtnUnBind.setVisibility(View.VISIBLE);
        mUnBindTips.setVisibility(View.VISIBLE);
        mBindTips.setVisibility(View.VISIBLE);
    }

    @Override
    public void init() {
        super.init();
        //本处使用移动分析demo中提供的uid（非必须），统一方便。 也可以使用其他id值
        MPSync.initialize(UserBasedSyncActivity.this);
        MPSync.registerBiz("syncUid", mSyncCallback);
        MPSync.registerBiz("CutomBizTye", mSyncCallback);
        MPSync.registerBiz("Test-All", mSyncCallback);
        MPSync.registerBiz("CutomBizTye123", mSyncCallback);

        MPSync.registerBiz("uidSyncGlobal", mSyncCallback);
        MPSync.registerBiz("MpaasPoc", mSyncCallback);
        MPSync.registerBiz("poc_sx", mSyncCallback);
        MPSync.registerBiz("pox_sx_all", mSyncCallback);
        Toast.makeText(UserBasedSyncActivity.this, getString(R.string.get_analysis_uid) + ": " + getUserId()
                , Toast.LENGTH_SHORT).show();
        mInputUid.setText(getUserId());
    }

    @Override
    public void onClick(View v) {
        int id = v.getId();
        if (id == R.id.btn_bind) {
            //绑定用户
            //LongLinkSyncService.getInstance().updateUserInfo(mInputUid.getInputEdit().getText().toString(), mInputSessionId.getInputEdit().getText().toString());

            //MPSync提供的绑定方法内部使用的userId是MPLogger.getUserId()的值，调用的时候无需再提供userId。
            boolean success = MPSync.updateUserInfo(mInputSessionId.getInputEdit().getText().toString());
            Toast.makeText(UserBasedSyncActivity.this, UserBasedSyncActivity.this.getString(R.string.sync_bind_result) + " : " + success
                    , Toast.LENGTH_SHORT).show();
            if (!success) {
                LoggerFactory.getTraceLogger().error(TAG, "绑定失败，未设置userId");
            }
            return;
        }
        if (id == R.id.btn_unbind) {
            MPSync.clearUserInfo();
            return;
        }
        if (id == R.id.btn_to_activity) {
            if (resultData.indexOf("to_a") != -1) {
                //跳转AActivity
                startActivity(new Intent(UserBasedSyncActivity.this, AActivity.class));
            }
            if (resultData.indexOf("to_b") != -1) {
                //跳转BActivity
                startActivity(new Intent(UserBasedSyncActivity.this, BActivity.class));
            }
            return;
        }

    }

    //获取移动分析demo中提供的uid
    private String getUserId() {
        return MPLogger.getUserId();
    }
}
