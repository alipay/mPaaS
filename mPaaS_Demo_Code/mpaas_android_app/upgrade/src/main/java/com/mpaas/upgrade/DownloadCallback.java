package com.mpaas.upgrade;

import android.widget.Toast;

import com.alipay.mobile.android.security.upgrade.download.normal.UpgradeDownloadCallback;
import com.alipay.mobile.android.security.upgrade.download.normal.UpgradeDownloadRequest;
import com.alipay.mobile.common.logging.api.LoggerFactory;

import java.lang.ref.WeakReference;

/**
 * 更新下载回调
 */
public class DownloadCallback implements UpgradeDownloadCallback {

    private static final String TAG = "DownloadCallback";

    private WeakReference<UpgradeActivity> mContext;

    public DownloadCallback(UpgradeActivity context) {
        mContext = new WeakReference<>(context);
    }

    @Override
    public void onLoadNotificationConfig(UpgradeDownloadRequest upgradeDownloadRequest) {

    }

    /**
     * 准备开始下载
     *
     * @param upgradeDownloadRequest 下载请求
     */
    @Override
    public void onPrepare(UpgradeDownloadRequest upgradeDownloadRequest) {
        LoggerFactory.getTraceLogger().debug(TAG, "onPrepare");
        final UpgradeActivity upgradeActivity = mContext.get();
        if (null != upgradeActivity) {
            upgradeActivity.runOnUiThread(new Runnable() {
                @Override
                public void run() {
                    upgradeActivity.showDownloadProgressDialog();
                }
            });
        }
    }

    /**
     * 下载中回调
     *
     * @param upgradeDownloadRequest 下载请求
     * @param percent                已下载百分比
     */
    @Override
    public void onProgress(UpgradeDownloadRequest upgradeDownloadRequest, final int percent) {
        LoggerFactory.getTraceLogger().debug(TAG, "onProgress: " + percent);
        final UpgradeActivity upgradeActivity = mContext.get();
        if (null != upgradeActivity) {
            upgradeActivity.runOnUiThread(new Runnable() {
                @Override
                public void run() {
                    upgradeActivity.updateDownloadProgressDialog(percent);
                }
            });
        }
    }

    /**
     * 下载取消
     *
     * @param upgradeDownloadRequest 下载请求
     */
    @Override
    public void onCancel(UpgradeDownloadRequest upgradeDownloadRequest) {
        LoggerFactory.getTraceLogger().debug(TAG, "onCancel");
        final UpgradeActivity upgradeActivity = mContext.get();
        if (null != upgradeActivity) {
            upgradeActivity.runOnUiThread(new Runnable() {
                @Override
                public void run() {
                    upgradeActivity.cancelDownloadProgressDialog();
                    Toast.makeText(upgradeActivity, upgradeActivity.getString(R.string.download_cancel), Toast.LENGTH_SHORT).show();
                }
            });
        }
    }

    /**
     * 下载成功
     *
     * @param upgradeDownloadRequest 下载请求
     * @param savePath               apk存储路径
     */
    @Override
    public void onFinish(UpgradeDownloadRequest upgradeDownloadRequest, final String savePath) {
        LoggerFactory.getTraceLogger().debug(TAG, "onFinish: " + savePath);
        final UpgradeActivity upgradeActivity = mContext.get();
        if (null != upgradeActivity) {
            upgradeActivity.runOnUiThread(new Runnable() {
                @Override
                public void run() {
                    upgradeActivity.cancelDownloadProgressDialog();
                    Toast.makeText(upgradeActivity, upgradeActivity.getString(R.string.download_finish), Toast.LENGTH_SHORT).show();
                }
            });
        }
    }

    /**
     * 下载失败
     *
     * @param upgradeDownloadRequest 下载请求
     * @param errorCode              失败code
     * @param errorMessage           失败message
     */
    @Override
    public void onFailed(UpgradeDownloadRequest upgradeDownloadRequest, int errorCode, String errorMessage) {
        LoggerFactory.getTraceLogger().error(TAG, "onFailed: " + errorCode + ", " + errorMessage);
        final UpgradeActivity upgradeActivity = mContext.get();
        if (null != upgradeActivity) {
            upgradeActivity.runOnUiThread(new Runnable() {
                @Override
                public void run() {
                    upgradeActivity.cancelDownloadProgressDialog();
                    Toast.makeText(upgradeActivity, upgradeActivity.getString(R.string.download_exception), Toast.LENGTH_SHORT).show();
                }
            });
        }
    }
}
