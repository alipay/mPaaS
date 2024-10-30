package com.mpaas.upgrade;

import android.app.Activity;
import android.content.Context;
import android.content.SharedPreferences;
import android.graphics.drawable.Drawable;
import android.os.Handler;
import android.os.Looper;
import android.widget.Toast;

import com.alibaba.fastjson.JSON;
import com.alipay.mobile.android.security.upgrade.log.LoggerUtils;
import com.alipay.mobile.android.security.upgrade.util.ResourcesUtil;
import com.alipay.mobile.android.security.upgrade.util.SharePreferenceUtil;
import com.alipay.mobile.android.security.upgrade.util.UpdateUtils;
import com.alipay.mobile.android.security.upgrade.util.UpgradeConstants;
import com.alipay.mobile.common.logging.api.LoggerFactory;
import com.alipay.mobile.framework.LauncherApplicationAgent;
import com.alipay.mobileappcommon.biz.rpc.client.upgrade.model.ClientUpgradeRes;


/*参考源码版本升级工具类*/
public class CheckVersionServiceImplCustom {
    protected static final String TAG = "CheckVersionServiceImpl";
    /**
     * 服务端返回的是否有新版本
     *
     * @param result
     * @return
     */
    public static boolean hasNewVersion(ClientUpgradeRes result) {
        boolean hasNewVersion =  result != null && (result.resultStatus == 202 || result.resultStatus == 203 || result.resultStatus == 204
                || result.resultStatus == 206);
        return hasNewVersion;
    }


    /**
     * 服务端返回关键参数为空，直接提示
     */
    public static void dealDataInValid(Context context){
        LoggerUtils.writeUpdateMonitorLog("RPC-UPGRADE-DATA", "ABOUT-RPC-RES-KEY-DATA-NULL", "160526-04", "", "");
        LoggerFactory.getTraceLogger().debug(TAG, "关于页面task升级关键数据不合法，不弹框");
        String dataErrorTip = ResourcesUtil.getString(com.alipay.mobile.android.security.upgrade.R.string.about_serve_system_business);
        Toast.makeText(context, dataErrorTip,Toast.LENGTH_LONG).show();
    }

    /**
     * 没有新版本
     */
    public static void dealHasNoNewVersion(Context context,ClientUpgradeRes mClientUpgradeRes){
        if (null != mClientUpgradeRes && mClientUpgradeRes.resultStatus == 201) {
            String isNewCilent = ResourcesUtil.getString(com.alipay.mobile.android.security.upgrade.R.string.about_is_new_client);
           Toast.makeText(context ,isNewCilent,Toast.LENGTH_LONG).show();
        }else{
            //走到这个地方，说明服务端返回有问题了
            dealDataInValid(context);
            LoggerFactory.getTraceLogger().debug(TAG, "dealHasNoNewVersion(),response is null or resultstatus less than 0");
            return;
        }
        LauncherApplicationAgent.getInstance().getMicroApplicationContext().dismissProgressDialog();
    }


}
