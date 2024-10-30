package com.mpaas.upgrade;

import android.app.Activity;
import android.widget.Toast;

import com.alipay.mobile.android.security.upgrade.service.UpdatePackageManager;
import com.alipay.mobile.common.logging.api.LoggerFactory;
import com.alipay.mobile.upgrade.service.mpaas.MPaaSCheckVersionService;
import com.alipay.mobileappcommon.biz.rpc.client.upgrade.model.ClientUpgradeRes;

import java.lang.ref.WeakReference;

/**
 * 更新检测回调
 */
public class UpgradeCallBack implements MPaaSCheckVersionService.MPaaSCheckCallBack {

    private static final String TAG = "UpgradeCallBack";

    private WeakReference<UpgradeActivity> mContext;

    public UpgradeCallBack(UpgradeActivity context) {
        mContext = new WeakReference<>(context);
    }

    /**
     * 开始检查
     */
    @Override
    public void startCheck() {
        LoggerFactory.getTraceLogger().debug(TAG, "startCheck");
        final UpgradeActivity upgradeActivity = mContext.get();
        if (null != upgradeActivity) {
            upgradeActivity.runOnUiThread(new Runnable() {
                @Override
                public void run() {
                    upgradeActivity.showCheckUpgradeProgressDialog();
                }
            });
        }
    }

    /**
     * 是不是正在更新中
     */
    @Override
    public void isUpdating() {
        LoggerFactory.getTraceLogger().debug(TAG, "isUpdating");
        final UpgradeActivity upgradeActivity = mContext.get();
        if (null != upgradeActivity) {
            upgradeActivity.runOnUiThread(new Runnable() {
                @Override
                public void run() {
                    upgradeActivity.cancelCheckUpgradeProgressDialog();
                    Toast.makeText(upgradeActivity, upgradeActivity.getString(R.string.warning_updating), Toast.LENGTH_SHORT).show();
                }
            });
        }
    }

    /**
     * 检测升级异常
     *
     * @param throwable 异常信息
     */
    @Override
    public void onException(Throwable throwable) {
        LoggerFactory.getTraceLogger().error(TAG, "onException: " + throwable.getMessage());
        final UpgradeActivity upgradeActivity = mContext.get();
        if (null != upgradeActivity) {
            upgradeActivity.runOnUiThread(new Runnable() {
                @Override
                public void run() {
                    upgradeActivity.cancelCheckUpgradeProgressDialog();
                    Toast.makeText(upgradeActivity, upgradeActivity.getString(R.string.upgrade_exception), Toast.LENGTH_SHORT).show();
                }
            });
        }
    }

    /**
     * 检测升级数据异常
     *
     * @param activity         页面
     * @param clientUpgradeRes 升级结果
     */
    @Override
    public void dealDataInValid(Activity activity, ClientUpgradeRes clientUpgradeRes) {
        LoggerFactory.getTraceLogger().debug(TAG, "dealDataInValid");
        final UpgradeActivity upgradeActivity = mContext.get();
        if (null != upgradeActivity) {
            upgradeActivity.runOnUiThread(new Runnable() {
                @Override
                public void run() {
                    upgradeActivity.cancelCheckUpgradeProgressDialog();
                    Toast.makeText(upgradeActivity, upgradeActivity.getString(R.string.data_invalid), Toast.LENGTH_SHORT).show();
                }
            });
        }
    }

    /**
     * 当前已是最新版
     *
     * @param activity         页面
     * @param clientUpgradeRes 升级结果
     */
    @Override
    public void dealHasNoNewVersion(Activity activity, ClientUpgradeRes clientUpgradeRes) {
        LoggerFactory.getTraceLogger().debug(TAG, "dealHasNoNewVersion");
        final UpgradeActivity upgradeActivity = mContext.get();
        if (null != upgradeActivity) {
            upgradeActivity.runOnUiThread(new Runnable() {
                @Override
                public void run() {
                    upgradeActivity.cancelCheckUpgradeProgressDialog();
                    Toast.makeText(upgradeActivity, upgradeActivity.getString(R.string.has_no_new_version), Toast.LENGTH_SHORT).show();
                }
            });
        }
    }

    /**
     * 最新版已经下载完成
     *
     * @param activity         页面
     * @param clientUpgradeRes 升级结果
     * @param persist          是否强制升级
     */
    @Override
    public void alreadyDownloaded(Activity activity, final ClientUpgradeRes clientUpgradeRes, final boolean persist) {
        LoggerFactory.getTraceLogger().debug(TAG, "alreadyDownloaded");
        final UpgradeActivity upgradeActivity = mContext.get();
        if (null != upgradeActivity) {
            upgradeActivity.runOnUiThread(new Runnable() {
                @Override
                public void run() {
                    upgradeActivity.cancelCheckUpgradeProgressDialog();
                    // 获取已经下好的apk存储路径
                    String apkPath = UpdatePackageManager.getInstance().getUpgradeApkFilePath(clientUpgradeRes.upgradeVersion);
                    upgradeActivity.showInstallDialog(apkPath, persist);
                }
            });
        }
    }

    /**
     * 有最新版，弹出升级提示框
     *
     * @param activity         页面
     * @param clientUpgradeRes 升级结果
     * @param persist          是否强制升级
     */
    @Override
    public void showUpgradeDialog(Activity activity, final ClientUpgradeRes clientUpgradeRes, boolean persist) {
        LoggerFactory.getTraceLogger().debug(TAG, "showUpgradeDialog");
        final UpgradeActivity upgradeActivity = mContext.get();
        if (null != upgradeActivity) {
            upgradeActivity.runOnUiThread(new Runnable() {
                @Override
                public void run() {
                    upgradeActivity.cancelCheckUpgradeProgressDialog();
                    upgradeActivity.showDownloadDialog(clientUpgradeRes);
                }
            });
        }
    }

    /**
     * 单次提醒时间没有超过设置的间隔时间
     *
     * @param activity         页面
     * @param clientUpgradeRes 升级结果
     * @param reason           原因
     */
    @Override
    public void onLimit(Activity activity, ClientUpgradeRes clientUpgradeRes, final String reason) {
        LoggerFactory.getTraceLogger().debug(TAG, "onLimit: " + reason);
        final UpgradeActivity upgradeActivity = mContext.get();
        if (null != upgradeActivity) {
            upgradeActivity.runOnUiThread(new Runnable() {
                @Override
                public void run() {
                    upgradeActivity.cancelCheckUpgradeProgressDialog();
                    Toast.makeText(upgradeActivity, upgradeActivity.getString(R.string.upgrade_less_than_interval), Toast.LENGTH_SHORT).show();
                }
            });
        }
    }
}
