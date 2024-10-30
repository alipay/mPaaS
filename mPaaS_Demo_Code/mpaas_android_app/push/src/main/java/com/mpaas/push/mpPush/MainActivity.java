package com.mpaas.push.mpPush;


import android.app.Activity;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.os.Bundle;
import android.view.View;
import android.widget.CheckBox;
import android.widget.CompoundButton;
import android.widget.EditText;
import android.widget.TextView;

import androidx.localbroadcastmanager.content.LocalBroadcastManager;

import com.alipay.mobile.common.logging.api.LoggerFactory;
import com.alipay.pushsdk.data.PushOsType;
import com.mpaas.mps.adapter.api.MPPush;
import com.mpaas.push.R;

import org.json.JSONException;
import org.json.JSONObject;

import alipay.yunpushcore.rpc.ResultPbPB;

/**
 * Created by larry.cl.
 * 包含了push初始化，绑定用户id,解绑定用户id和上传第三方push token的示例。
 */

public class MainActivity extends Activity {
    //根据自己用户系统的用户Id而定，这里以pushDemoUserId为例
    private static final String TAG = "pushTag";
    private static String OPERATION_SUCCESS;
    private static String OPERATION_FAILURE;

    private TextView mResult;
    private EditText tvAdToken;
    private EditText tvChToken;

    private NotificationHelper notificationHelper;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_push_main);
        OPERATION_FAILURE = getString(R.string.failed);
        OPERATION_SUCCESS = getString(R.string.success);
        bindViews();
        setListeners();
        init();
    }

    private void init() {
        //获取移动分析demo中提供的uid用于绑定push uid，保持统一，方便捞日志（捞日志基于该id值）。
        LocalBroadcastManager.getInstance(this).registerReceiver(new BroadcastReceiver() {
            @Override
            public void onReceive(Context context, final Intent intent) {
                StringBuilder sb = new StringBuilder();
                sb.append((getString(R.string.pushmessage)));
                mResult.setText(sb.toString());
                int pushType = intent.getIntExtra("push_type", 0);
                if (pushType == PushMsgService.TYPE_INNER_PUSH_INIT) {
                    String token = intent.getStringExtra("push_token");
                    sb.append("\n").append(getString(R.string.in_rigerst_success) + token);
                    mResult.setText(sb.toString());
                    tvAdToken.setText(token);
                } else if (pushType == PushMsgService.TYPE_THIRD_PUSH_INIT) {
                    String token = intent.getStringExtra("push_thirdToken");
                    int channel = intent.getIntExtra("push_channel", 0);
                    String platformChannel = "";
                    if (channel == PushOsType.XIAOMI.value()) {
                        platformChannel = getString(R.string.xiaomi);
                    } else if (channel == PushOsType.HUAWEI.value()) {
                        platformChannel = getString(R.string.huawei);
                    }
                    tvChToken.setText(token);
                    sb.append("\n").append(getString(R.string.third_party_channel) + platformChannel + getString(R.string.register_success_adtoken) + token);
                    mResult.setText(sb.toString());
                } else if (pushType == PushMsgService.TYPE_MSG) {
                    String key = intent.getStringExtra("push_key");
                    String value = intent.getStringExtra("push_value");
                    sb.append("\n").append(getString(R.string.push_message_key) + key + "\n"
                            + getString(R.string.push_message_value) + value);
                    mResult.setText(sb.toString());
                }
            }
        }, new IntentFilter(PushMsgService.PUSH_SERVICE_ACTION));
        notificationHelper = new NotificationHelper(this);
    }

    private void setListeners() {
        findViewById(R.id.btn_init).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                initPush();
            }
        });
        findViewById(R.id.btn_uploadThirdToken).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                doUploadToken();
            }
        });
        findViewById(R.id.btn_bind).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                doBind();
            }
        });
        findViewById(R.id.btn_unbind).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                doUnBind();
            }
        });
    }

    private void bindViews() {
        mResult = findViewById(R.id.result_view);
        mResult.setText(getString(R.string.operation_result));
        setTitle(getString(R.string.push_title));
        tvAdToken = findViewById(R.id.adtoken);
        tvChToken = findViewById(R.id.rdToken);
        tvAdToken.setText(PushMsgService.mAdToken);
        tvChToken.setText(PushMsgService.mThirdToken);
        ((EditText) findViewById(R.id.userId)).setText(PushMsgService.mUserId);

        CheckBox cbUseDefaultMessage = findViewById(R.id.use_default_push);
        cbUseDefaultMessage.setChecked(PushMsgService.useDefault);
        cbUseDefaultMessage.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                PushMsgService.useDefault = isChecked;
            }
        });
    }

    //初始化push
    private void initPush() {
        try {
            MPPush.init(getApplicationContext());
        } catch (Throwable throwable) {
            LoggerFactory.getTraceLogger().error(TAG, throwable.toString());
        }
    }

    //最好在子线程中调用绑定用户的相关操作
    private void doBind() {
        new Thread("bindUserThread") {
            @Override
            public void run() {
                doSimpleBind();
            }
        }.start();

    }

    // 绑定用户id和adtoken（封装后的简易接口，基于内置渠道标识）
    private void doSimpleBind() {
        final ResultPbPB resultPbPB = MPPush.bind(getApplicationContext()
                , PushMsgService.mUserId, PushMsgService.mAdToken);
        handlePbPBResult(getString(R.string.binding_user_operation), resultPbPB);
    }

    //最好在子线程中调用解除绑定用户的相关操作
    private void doUnBind() {
        new Thread("unBindUserThread") {
            @Override
            public void run() {
                doSimpleUnBind();
            }
        }.start();
    }

    //解除用户和adtoken 的绑定关系（封装后的简易接口）
    private void doSimpleUnBind() {
        final ResultPbPB resultPbPB = MPPush.unbind(getApplicationContext()
                , PushMsgService.mUserId, PushMsgService.mAdToken);
        handlePbPBResult(getString(R.string.unbind_user), resultPbPB);
    }

    //最好在子线程中调用标识上报的相关操作
    private void doUploadToken() {
        new Thread() {
            @Override
            public void run() {
                doSimpleUploadToken();
            }
        }.start();
    }

    //第三方push标识的上报接口（封装后的简易接口）
    private void doSimpleUploadToken() {
        final ResultPbPB resultPbPB = MPPush.report(getApplicationContext(), PushMsgService.mAdToken
                /*channel可以选择XIAOMI,HUAWEI和GCM*/
                , PushMsgService.platformType, PushMsgService.mThirdToken);
        handlePbPBResult(getString(R.string.third_pushtoken_upload_operation), resultPbPB);
    }

    /**
     * @param operationType 操作类型
     * @param resultPbPB    push操作结果
     */

    private void handlePbPBResult(final String operationType, final ResultPbPB resultPbPB) {
        MainActivity.this.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                StringBuilder sb = new StringBuilder();
                if (resultPbPB.success) {
                    sb.append(operationType + " " + getString(R.string.success)).append("\n");
                } else {
                    sb.append(operationType + " " + getString(R.string.failed)).append("\n");
                }
                sb.append(resultPbPB.toString());
                mResult.setText(sb.toString());
            }
        });
    }


    private void notifyNotification(String value) {
        try {
            JSONObject valueJsonObject = new JSONObject(value);
            String title = valueJsonObject.getString("title");
            String content = valueJsonObject.getString("content");
            notificationHelper.notify(title, content);
        } catch (JSONException e) {
            e.printStackTrace();
        }
    }

}
