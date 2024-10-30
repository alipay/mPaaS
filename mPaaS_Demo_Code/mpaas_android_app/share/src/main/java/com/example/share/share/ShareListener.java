package com.example.share.share;

import android.widget.Toast;

import com.alipay.mobile.antui.basic.AUToast;
import com.alipay.mobile.antui.utils.PublicResources;
import com.alipay.mobile.common.logging.api.LoggerFactory;
import com.alipay.mobile.common.share.ShareException;
import com.alipay.mobile.framework.service.ShareService;
import com.example.share.R;

import java.lang.ref.WeakReference;

public class ShareListener implements ShareService.ShareActionListener {

    private static final String TAG = "ShareListener";

    private WeakReference<ShareActivity1> mContext;

    public ShareListener(ShareActivity1 context) {
        mContext = new WeakReference<>(context);
    }

    /**
     * 分享成功
     *
     * @param shareType 分享类型
     */
    @Override
    public void onComplete(int shareType) {
        LoggerFactory.getTraceLogger().debug(TAG, "onComplete: " + shareType);
        final ShareActivity1 activity = mContext.get();
        if (null != activity) {
            activity.runOnUiThread(new Runnable() {
                @Override
                public void run() {
                    AUToast.makeToast(activity, PublicResources.Toast_OK, activity.getString(R.string.share_success), Toast.LENGTH_SHORT).show();
                }
            });
        }
    }

    /**
     * 分享异常
     *
     * @param shareType 分享类型
     * @param e         异常信息
     */
    @Override
    public void onException(int shareType, final ShareException e) {
        LoggerFactory.getTraceLogger().debug(TAG, "onException: " + e.getStatusCode() + ", " + e.getMessage());
        final ShareActivity1 activity = mContext.get();
        if (null != activity) {
            activity.runOnUiThread(new Runnable() {
                @Override
                public void run() {
                    int errorCode = e.getStatusCode();
                    // 当code = USER_CANCEL时，表示用户主动取消分享
                    if (ShareException.USER_CANCEL == errorCode) {
                        AUToast.makeToast(activity, PublicResources.Toast_Warn, activity.getString(R.string.share_cancel), Toast.LENGTH_SHORT).show();
                    }
                    // 分享出现其他异常
                    else {
                        AUToast.makeToast(activity, PublicResources.Toast_False, activity.getString(R.string.share_error) + "\n" + errorCode + ", " + e.getMessage(), Toast.LENGTH_SHORT).show();
                    }
                }
            });
        }
    }
}
