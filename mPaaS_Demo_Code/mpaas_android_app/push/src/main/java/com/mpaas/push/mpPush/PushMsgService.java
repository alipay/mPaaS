package com.mpaas.push.mpPush;

import android.content.Intent;
import android.net.Uri;
import android.text.TextUtils;
import android.util.Log;

import androidx.localbroadcastmanager.content.LocalBroadcastManager;

import com.alipay.mobile.common.logging.api.LoggerFactory;
import com.alipay.pushsdk.content.AliPushRcvService;
import com.alipay.pushsdk.data.BDataBean;
import com.alipay.pushsdk.push.PushAppInfo;
import com.mpaas.push.R;

/**
 * Created by larry.cl.
 * push的接收服务
 */

public class PushMsgService extends AliPushRcvService {

    private static final String TAG = "pushTag";
    public static final String PUSH_SERVICE_ACTION = "tt-action";
    //推送消息的类型，用户自定义即可
    public static final int TYPE_MSG = -1;
    public static final int TYPE_INNER_PUSH_INIT = -2;
    public static final int TYPE_THIRD_PUSH_INIT = -3;
    //自建渠道推送标识
    public static String mAdToken = "";
    //第三方渠道推送标识
    public static String mThirdToken = "";

    public static String mUserId = "mpaas_push_demo";

    public static int platformType = 0;

    public static boolean useDefault = false;

    public PushMsgService() {
        super();
    }

    /**
     * If you use built-in notification from SDK, please return true.
     */
    @Override
    protected boolean useDefaultNotification(String msgKey, String msgValue) {
        Intent intent = new Intent(PUSH_SERVICE_ACTION);
        intent.putExtra("push_type", TYPE_MSG);
        intent.putExtra("push_key", msgKey);
        intent.putExtra("push_value", msgValue);
        LocalBroadcastManager.getInstance(this).sendBroadcast(intent);
        LoggerFactory.getTraceLogger().debug(TAG, "onHandleIntent sendLocalBroadcast: " + intent.toString());
        Log.d("handleActionReceived","useDefaultNotification" );
        return useDefault;
    }

    /**
     * This is only called when useDefaultNotification returns false.
     * @param msgKey   消息推送的key
     * @param msgValue 消息推送的value
     * @param clicked  是否已经点击了
     *                 对于三方渠道来说clicked = true ,展示通知栏
     *                 对于自建渠道来说clicked = false，没有展示通知栏
     */
    @Override
    protected void handleActionReceived(String msgKey, String msgValue, boolean clicked) {
        Log.d("handleActionReceived","handleActionReceived" );
        if (TextUtils.isEmpty(msgValue)) {
            return;
        }
        BDataBean data = BDataBean.create(msgValue);
        if (clicked) {
            try {
                Uri uri = Uri.parse(data.getUrl());
                Intent actionIntent = new Intent(Intent.ACTION_VIEW);
                actionIntent.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
                actionIntent.setData(uri);
                actionIntent.putExtra("data", data.getParams());
                startActivity(actionIntent);
            } catch (Exception e) {
                Log.e(TAG, "Unable start activity due to wrong format uri", e);
            }
            Log.d("handleActionReceived","handleActionReceived" +clicked);
        } else {
            // show your notification and handle action
            NotificationHelper helper = new NotificationHelper(getApplicationContext());
            helper.notify(getString(R.string.zhuyifeineijinxiaoxi) + data.getTitle(), data.getContent());
            Log.d("handleActionReceived","handleActionReceived" +clicked);
        }

    }

    /**
     * @param adToken 自建渠道的推送标识
     */

    @Override
    protected void handleActionId(String adToken) {
        Log.d("handleActionReceived","handleActionId" );
        PushAppInfo pushAppInfo = new PushAppInfo(getApplicationContext());
        pushAppInfo.setAppToken(adToken);
        LoggerFactory.getTraceLogger().debug(TAG, getString(R.string.self_built_channel_adToken) + adToken);
        Intent intent = new Intent(PUSH_SERVICE_ACTION);
        intent.putExtra("push_type", TYPE_INNER_PUSH_INIT);
        intent.putExtra("push_token", adToken);
        LocalBroadcastManager.getInstance(this).sendBroadcast(intent);
        mAdToken = adToken;
    }

    /**
     * @param thirdToken   三方渠道的推送标识
     * @param platformType 三方渠道的类型 华为=5 小米=4
     */
    @Override
    protected void handleActionThirdId(String thirdToken, int platformType) {
        LoggerFactory.getTraceLogger().debug(TAG, getString(R.string.third_channel_adToken) + thirdToken + "platformType: " + platformType);
        Intent intent = new Intent(PUSH_SERVICE_ACTION);
        intent.putExtra("push_type", TYPE_THIRD_PUSH_INIT);
        intent.putExtra("push_thirdToken", thirdToken);
        intent.putExtra("push_channel", platformType);
        LocalBroadcastManager.getInstance(this).sendBroadcast(intent);
        mThirdToken = thirdToken;
        PushMsgService.platformType = platformType;
    }
}
