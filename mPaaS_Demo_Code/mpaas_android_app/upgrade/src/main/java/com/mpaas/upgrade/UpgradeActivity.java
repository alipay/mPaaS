package com.mpaas.upgrade;

import androidx.appcompat.app.AppCompatActivity;

import android.app.Activity;
import android.app.AlertDialog;
import android.app.Dialog;
import android.app.ProgressDialog;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.Space;
import android.widget.TextView;
import android.widget.Toast;

import com.alipay.android.phone.mobilesdk.storage.sp.SharedPreferencesManager;
import com.alipay.mobile.android.security.upgrade.download.normal.UpgradeForceExitCallback;
import com.alipay.mobile.android.security.upgrade.service.UpdateServices;
import com.alipay.mobile.android.security.upgrade.util.UpdateUtils;
import com.alipay.mobile.android.security.upgrade.util.UpgradeConstants;
import com.alipay.mobile.framework.LauncherApplicationAgent;
import com.alipay.mobile.framework.MicroApplicationContext;
import com.alipay.mobile.framework.app.ui.BaseActivity;
import com.alipay.mobile.upgrade.service.mpaas.MPaaSCheckVersionService;
import com.alipay.mobile.upgrade.service.mpaas.impl.MPaaSCheckVersionServiceImpl;
import com.alipay.mobile.upgrade.ui.UpdateCommonDialog;
import com.alipay.mobileappcommon.biz.rpc.client.upgrade.model.ClientUpgradeRes;
import com.mpaas.mas.adapter.api.MPLogger;
import com.mpaas.mpaasadapter.api.upgrade.MPUpgrade;
import com.mpaas.upgrade.dialog.LanguageUtils;
import com.mpaas.upgrade.dialog.UpdateCustomDialog;

import org.json.JSONException;
import org.json.JSONObject;

public class UpgradeActivity extends BaseActivity {

    private TextView mCurVersionTv;
    private Button mFastCheckBtn;
    private Button mFastCheckHasBtn;
    private Button mFastCheckGetBtn;
    private Button mDefaultIntervalUpgradeBtn;
    private Button mCustomIntervalUpgradeBtn;
    private Button customUpgradeDialog;


    private ProgressDialog mCheckUpgradeProgressDialog;
    private Dialog mDownloadDialog;
    private ProgressDialog mDownloadProgressDialog;
    private Dialog mInstallDialog;

    private MPUpgrade mMPUpgrade = new MPUpgrade();

    private UpdateCustomDialog mUpdateDialog = null ;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_upgrade);
        setTitle(getString(R.string.upgrade_release ) );
        // 设置升级服务的回调函数
        mMPUpgrade.setUpgradeCallback(new UpgradeCallBack(this));
        findView();
        initView();
        fixHuawei10();

        // 内部测试使用，开发者无需关注
//        test();
    }

    private void findView() {
        mCurVersionTv = (TextView) findViewById(R.id.upgrade_cur_version_tv);
        mFastCheckBtn = (Button) findViewById(R.id.upgrade_fast_check_btn);
        mFastCheckHasBtn = (Button) findViewById(R.id.upgrade_fast_check_has_btn);
        mFastCheckGetBtn = (Button) findViewById(R.id.upgrade_fast_check_get_btn);
        mDefaultIntervalUpgradeBtn = (Button) findViewById(R.id.upgrade_default_interval_btn);
        mCustomIntervalUpgradeBtn = (Button) findViewById(R.id.upgrade_custom_interval_btn);
        customUpgradeDialog = (Button) findViewById(R.id.upgrade_custom_dialog);
    }

    private void initView() {
        mCheckUpgradeProgressDialog = new ProgressDialog(this);
        mCheckUpgradeProgressDialog.setMessage(getString(R.string.checking_upgrade));
        mCheckUpgradeProgressDialog.setCanceledOnTouchOutside(false);
        mDownloadProgressDialog = new ProgressDialog(this);
        mDownloadProgressDialog.setMessage(getString(R.string.downloading));
        mDownloadProgressDialog.setProgressStyle(ProgressDialog.STYLE_HORIZONTAL);
        mDownloadProgressDialog.setMax(100);
        mDownloadProgressDialog.setIndeterminate(false);
        mDownloadProgressDialog.setCancelable(false);

        try {
            mCurVersionTv.setText(getString(R.string.cur_ver_is) + getPackageManager().getPackageInfo(getPackageName(), 0).versionName);
        } catch (PackageManager.NameNotFoundException e) {
            e.printStackTrace();
        }
        mFastCheckBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                mMPUpgrade.fastCheckNewVersion(UpgradeActivity.this, getResources().getDrawable(R.drawable.appicon));
            }
        });
        mFastCheckHasBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                new Thread(new Runnable() {
                    @Override
                    public void run() {
                        final int result = mMPUpgrade.fastCheckHasNewVersion();
                        runOnUiThread(new Runnable() {
                            @Override
                            public void run() {
                                if (result == UpgradeConstants.HAS_NEW_VERSION) {
                                    Toast.makeText(UpgradeActivity.this, R.string.havenew_version, Toast.LENGTH_SHORT).show();
                                } else if (result == UpgradeConstants.HAS_NO_NEW_VERSION) {
                                    Toast.makeText(UpgradeActivity.this, R.string.has_no_new_version, Toast.LENGTH_SHORT).show();
                                } else if (result == UpgradeConstants.HAS_SOME_ERROR) {
                                    Toast.makeText(UpgradeActivity.this, R.string.detection_newversion_error, Toast.LENGTH_SHORT).show();
                                }
                            }
                        });
                    }
                }).start();
            }
        });
        mFastCheckGetBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                new Thread(new Runnable() {
                    @Override
                    public void run() {
                        final ClientUpgradeRes res = mMPUpgrade.fastGetClientUpgradeRes();
                        runOnUiThread(new Runnable() {
                            @Override
                            public void run() {
                                if (null == res) {
                                    Toast.makeText(UpgradeActivity.this, R.string.error_getupgradleresult_null, Toast.LENGTH_SHORT).show();
                                } else {
                                    Toast.makeText(UpgradeActivity.this, "版本信息"+res.upgradeVersion ,Toast.LENGTH_LONG).show();
                                    MPLogger.error("升级","fastGetClientUpgradeRes:"+res.upgradeVersion);
                                }
                            }
                        });
                    }
                }).start();
            }
        });
        mDefaultIntervalUpgradeBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                // 更新提示间隔时间设置成-1时，采用默认的3天作为更新提示间隔时间
                // 开发者可以再此处设置任意更新提示间隔时间，该时间只对单次升级模式生效
//                mMPUpgrade.setIntervalTime(-1);
                mMPUpgrade.checkNewVersion(UpgradeActivity.this);
                mMPUpgrade.setUpgradeCallback(new MPaaSCheckVersionService.MPaaSCheckCallBack() {
                    @Override
                    public void startCheck() {

                    }

                    @Override
                    public void isUpdating() {

                    }

                    @Override
                    public void onException(Throwable throwable) {

                    }

                    @Override
                    public void dealDataInValid(Activity activity, ClientUpgradeRes clientUpgradeRes) {
                        MPLogger.error("升级","dealDataInValid:"+clientUpgradeRes.upgradeVersion);
                    }

                    @Override
                    public void dealHasNoNewVersion(Activity activity, ClientUpgradeRes clientUpgradeRes) {
                        MPLogger.error("升级","dealHasNoNewVersion:"+clientUpgradeRes.upgradeVersion);
                    }

                    @Override
                    public void alreadyDownloaded(Activity activity, ClientUpgradeRes clientUpgradeRes, boolean b) {
                        MPLogger.error("升级","alreadyDownloaded:"+clientUpgradeRes.upgradeVersion+ "   " + b);
                    }

                    @Override
                    public void showUpgradeDialog(Activity activity, ClientUpgradeRes clientUpgradeRes, boolean b) {
                        MPLogger.error("升级","showUpgradeDialog:"+clientUpgradeRes.upgradeVersion+ "   " + b);
                    }

                    @Override
                    public void onLimit(Activity activity, ClientUpgradeRes clientUpgradeRes, String s) {

                    }
                });
            }
        });
        mCustomIntervalUpgradeBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                // 更新提示间隔时间设置成60*1000时（1分钟），表示两次升级弹框超过一分钟才会弹出
                // 开发者可以再此处设置任意更新提示间隔时间，该时间只对单次升级模式生效
              //  mMPUpgrade.setIntervalTime(60 * 1000);
               // mMPUpgrade.checkNewVersion(UpgradeActivity.this);
                mMPUpgrade.setIntervalTime(60 * 1000);
                SPUtils.putIntervalTime(UpgradeActivity.this ,60 * 1000L);
            }
        });



        /*模拟自定义版本升级弹框*/
        customUpgradeDialog.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                new Thread(new Runnable() {
                    @Override
                    public void run() {
                        final ClientUpgradeRes res = mMPUpgrade.fastGetClientUpgradeRes();
                        runOnUiThread(new Runnable() {
                            @Override
                            public void run() {
                                if (null == res) {
                                    Toast.makeText(UpgradeActivity.this, R.string.error_getupgradleresult_null, Toast.LENGTH_SHORT).show();
                                } else {
                                    //判断版本升级类型
                                    boolean hasNewVersion = CheckVersionServiceImplCustom.hasNewVersion(res);
                                    //检查网络是否满足升级弹框有效条件
                                    boolean netTypeHasShowDialog = UpdateUtils.checkNetWorkCondition(res.netType);
                                    if(hasNewVersion && netTypeHasShowDialog){
                                        boolean dataIsValid = UpdateUtils.checkRPCDataIsValid(res);
                                        if(dataIsValid){//数据有效

                                            //设置的单次升级的时间间隔259200000
                                            long intervalTime = SPUtils.getIntervalTime(UpgradeActivity.this );
                                            long lastShowTime = SPUtils.getlastShowTime(UpgradeActivity.this );
                                            long realIntervalTime = System.currentTimeMillis() - lastShowTime;//判断2次升级的间隔
                                            boolean isOK = realIntervalTime > intervalTime;//满足单次升级的条件
                                            boolean singleUpdateOK = res.resultStatus ==202 && isOK ;

                                            /*
                                            *版本升级信息支持自定义
                                            * {
                                                 "en":"New version updated, please upgrade",
                                                  "zh":"新版本更新，请升级"
                                             }
                                             */
                                            String upgradeInfo =res.guideMemo;
                                            String upgradeText ="";
                                            try {
                                                JSONObject object = new JSONObject(upgradeInfo);
                                                if(object.has("en")  && object.has("zh") ){
                                                    //中文环境
                                                    if(LanguageUtils.isZh(UpgradeActivity.this)){
                                                        upgradeText = object.getString("zh");
                                                    }else{
                                                        upgradeText = object.getString("en");
                                                    }
                                                }else{
                                                    //不做en/zh适配
                                                    upgradeText = upgradeInfo;
                                                }

                                            } catch (JSONException e) {
                                                e.printStackTrace();
                                                upgradeText = "JSONException 版本升级默认更新";
                                            }

                                            if(res.resultStatus ==203 || res.resultStatus ==206){
                                                //203/206 为强制更新
                                                UpdateCustomDialog.Builder builder = new UpdateCustomDialog.Builder(UpgradeActivity.this);
                                                builder.setIcon(getResources().getDrawable(R.drawable.appicon));
                                                builder.setCancelable(false);//点击空白是否取消
                                                //builder.setTitle("title");
                                                builder.setMessage(upgradeText);
                                                // builder.setOnKeyListener(onKeyListener);
                                                builder.setPositiveButton(R.string.about_update_now, new DialogInterface.OnClickListener() {
                                                    @Override
                                                    public void onClick(DialogInterface dialog, int which) {
                                                       /* mMPUpgrade.update(res, new DownloadCallback(UpgradeActivity.this));*/

                                                        final UpdateServices updateServices = (UpdateServices)LauncherApplicationAgent.getInstance().getMicroApplicationContext().getExtServiceByInterface(UpdateServices.class.getName());
                                                        Bundle bundle;(bundle = new Bundle()).putString("update_version", res.upgradeVersion);
                                                        /* * @param apkPath apk路径
                                                         * @param fullMd5 服务端下发的完整包的MD5
                                                         * @param forceExitApp 是否是强制升级
                                                         * @return 是否校验通过（当然，不需要校验的情况，做校验通过处理）*/
                                                        updateServices.update(res.downloadURL, res.fullMd5, true, bundle);
                                                        updateServices.updateCacheJustForRetry(res);
                                                        updateServices.reInitUpdateDialog();
                                                    }
                                                });

                                                mUpdateDialog = builder.show();
                                                //更新最后一次升级的时间
                                                SPUtils.setlastShowTime( UpgradeActivity.this,System.currentTimeMillis());

                                            }else if(   singleUpdateOK   || res.resultStatus ==204 ){
                                                // 为单次提醒  202
                                                // 多次提醒  204
                                                // 普通升级弹框
                                                UpdateCustomDialog.Builder builder = new UpdateCustomDialog.Builder(UpgradeActivity.this);
                                                builder.setIcon(getResources().getDrawable(R.drawable.appicon));
                                                builder.setCancelable(true);//是否取消

                                                // builder.setTitle("title");
                                                builder.setMessage(upgradeText);
                                                // builder.setOnKeyListener(onKeyListener);
                                                builder.setPositiveButton(R.string.about_update_now, new DialogInterface.OnClickListener() {
                                                    @Override
                                                    public void onClick(DialogInterface dialog, int which) {
                                                        final UpdateServices updateServices = (UpdateServices)LauncherApplicationAgent.getInstance().getMicroApplicationContext().getExtServiceByInterface(UpdateServices.class.getName());
                                                        Bundle bundle;(bundle = new Bundle()).putString("update_version", res.upgradeVersion);
                                                        updateServices.update(res.downloadURL, res.fullMd5, false, bundle);
                                                        updateServices.updateCacheJustForRetry(res);
                                                        updateServices.reInitUpdateDialog();
                                                        Toast.makeText(UpgradeActivity.this, getText(R.string.about_update_next_time_to_choice),Toast.LENGTH_LONG).show();
                                                    }
                                                });
                                                builder.setNegativeButton(R.string.about_update_next_time_to_choice, new DialogInterface.OnClickListener() {
                                                    @Override
                                                    public void onClick(DialogInterface dialog, int which) {
                                                        if(mUpdateDialog != null){
                                                            mUpdateDialog.dismiss();
                                                        }

                                                    }
                                                });
                                                mUpdateDialog = builder.show();

                                                //更新最后一次升级的时间
                                                SPUtils.setlastShowTime( UpgradeActivity.this,System.currentTimeMillis());

                                            }else{
                                                Toast.makeText(UpgradeActivity.this,  "升级剩余时间 ： "+(intervalTime -realIntervalTime) +" ms ",Toast.LENGTH_LONG).show();
                                            }

                                        }else{
                                            CheckVersionServiceImplCustom.dealDataInValid(UpgradeActivity.this);
                                        }
                                    }else{
                                        CheckVersionServiceImplCustom.dealHasNoNewVersion(UpgradeActivity.this,res);
                                    }
                                }
                            }
                        });
                    }
                }).start();
            }
        });
    }

    private void fixHuawei10() {
        // 在部分 rom 上，强制更新安装时，会因为进程被杀掉导致包解析失败，加入下面的回调，第一个方法返回false，则不再进行杀进程。
        mMPUpgrade.setForceExitCallback(new UpgradeForceExitCallback() {
            @Override
            public boolean needForceExit(boolean b, MicroApplicationContext microApplicationContext) {
                // 返回false不强制退出，避免包解析失败问题。返回true的话，会走到第二个方法，开发者可以在下面方法里自行杀进程。
                return false;
            }

            @Override
            public void doForceExit(boolean b, MicroApplicationContext microApplicationContext) {

            }
        });
    }

    /**
     * 显示版本检测的ProgressDialog
     */
    public void showCheckUpgradeProgressDialog() {
        mCheckUpgradeProgressDialog.show();
    }

    /**
     * 取消版本检测的ProgressDialog
     */
    public void cancelCheckUpgradeProgressDialog() {
        mCheckUpgradeProgressDialog.cancel();
    }

    /**
     * 显示下载dialog
     *
     * @param clientUpgradeRes 更新结果
     */
    public void showDownloadDialog(final ClientUpgradeRes clientUpgradeRes) {
        String title = getString(R.string.upgrade);
        // 默认不是强制升级
        boolean isForce = false;
        // 根据不同的升级策略，显示不同的dialog标题。
        // 强制升级策略下无法取消dialog。
        switch (clientUpgradeRes.resultStatus) {
            // 状态值为202，单次提醒升级
            case 202:
                title = getString(R.string.single_upgrade);
                break;
            // 状态值为204，多次提醒升级
            case 204:
                title = getString(R.string.multi_upgrade);
                break;
            // 状态值为203或206，强制升级
            case 203:
            case 206:
                title = getString(R.string.force_upgrade);
                isForce = true;
                break;
            default:
                title = getString(R.string.unknown_upgrade_state) + clientUpgradeRes.resultStatus;
                break;
        }
        AlertDialog.Builder builder = new AlertDialog.Builder(this)
                .setTitle(title)
                .setMessage(clientUpgradeRes.guideMemo)
                .setCancelable(!isForce)
                .setPositiveButton(R.string.upgrade, new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                        mMPUpgrade.update(clientUpgradeRes, new DownloadCallback(UpgradeActivity.this));
                    }
                });
        if (!isForce) {
            builder.setNegativeButton(R.string.cancel, new DialogInterface.OnClickListener() {
                @Override
                public void onClick(DialogInterface dialog, int which) {
                    dialog.cancel();
                }
            });
        }
        mDownloadDialog = builder.create();
        mDownloadDialog.show();
    }

    /**
     * 显示下载ProgressDialog
     */
    public void showDownloadProgressDialog() {
        mDownloadProgressDialog.show();
        mDownloadProgressDialog.setProgress(0);
    }

    /**
     * 更新下载ProgressDialog的百分比
     *
     * @param percent 百分比
     */
    public void updateDownloadProgressDialog(int percent) {
        mDownloadProgressDialog.setProgress(percent);
    }

    /**
     * 取消下载ProgressDialog
     */
    public void cancelDownloadProgressDialog() {
        mDownloadProgressDialog.setProgress(0);
        mDownloadProgressDialog.cancel();
    }

    /**
     * 显示安装dialog
     *
     * @param apkPath apk路径
     * @param isForce 是否强制安装
     */
    public void showInstallDialog(final String apkPath, boolean isForce) {
        AlertDialog.Builder builder = new AlertDialog.Builder(this)
                .setTitle(R.string.install_new)
                .setMessage(getString(R.string.apk_path) + apkPath)
                .setCancelable(!isForce)
                .setPositiveButton(R.string.install, new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                        UpdateUtils.installApk(apkPath);
                    }
                });
        if (!isForce) {
            builder.setNegativeButton(R.string.cancel, new DialogInterface.OnClickListener() {
                @Override
                public void onClick(DialogInterface dialog, int which) {
                    dialog.cancel();
                }
            });
        }
        mInstallDialog = builder.create();
        mInstallDialog.show();
    }

    // 内部测试使用，开发者无需关注
    private void test() {
        try {
            Class healthActivity = Class.forName("com.mpaas.diagnose.ui.HealthBizSelectActivity");
            Intent intent = new Intent(this, healthActivity);
            startActivity(intent);
        } catch (Exception e) {
        }
    }


}