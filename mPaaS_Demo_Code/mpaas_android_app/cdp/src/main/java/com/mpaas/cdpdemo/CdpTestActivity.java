package com.mpaas.cdpdemo;

import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.text.TextUtils;
import android.view.View;

import com.alipay.android.phone.mobilesdk.storage.sp.APSharedPreferences;
import com.alipay.android.phone.mobilesdk.storage.sp.SharedPreferencesManager;
import com.alipay.mobile.antui.basic.AUTitleBar;
import com.alipay.mobile.antui.dialog.AUInputDialog;
import com.alipay.mobile.common.logging.api.LoggerFactory;
import com.alipay.mobile.framework.app.ui.BaseActivity;

import static com.mpaas.cdpdemo.CustomSpaceCodeActivity.CUSTOM_SPACE_CODE;

public class CdpTestActivity extends BaseActivity {
    private static final String GROUP_ID = "com_mpaas_demo_cdp";
    private APSharedPreferences mAPSharedPreferences;

    public static void startActivity(Context baseContext) {
        Intent intent = new Intent();
        intent.setClass(baseContext,CdpTestActivity.class);
        intent.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
        baseContext.startActivity(intent);
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_test);
        ((AUTitleBar) findViewById(R.id.title_atb)).setTitleText(getString(R.string.cdp_test));
        mAPSharedPreferences = SharedPreferencesManager.getInstance(this, GROUP_ID);
        findViewById(R.id.test_custom_space_code).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                AUInputDialog dialog = new AUInputDialog(CdpTestActivity.this, null, getString(R.string.input_space_code),
                        getString(R.string.ok), getString(R.string.cancel), true);
                dialog.setPositiveListener(new AUInputDialog.OnClickPositiveListener() {
                    @Override
                    public void onClick(String spaceCode) {
                        if (TextUtils.isEmpty(spaceCode)) {
                            return;
                        }
                        mAPSharedPreferences.putString(CUSTOM_SPACE_CODE, spaceCode);
                        mAPSharedPreferences.commit();
                        Intent intent = new Intent(CdpTestActivity.this, CustomSpaceCodeActivity.class);
                        intent.putExtra(CUSTOM_SPACE_CODE, spaceCode);
                        startActivity(intent);
                    }
                });
                dialog.show();
                String spaceCode = mAPSharedPreferences.getString(CUSTOM_SPACE_CODE, "");
                dialog.getInputContent().setText(spaceCode);
                dialog.getInputContent().setSelection(spaceCode.length());
            }
        });
        findViewById(R.id.test_content_1_btn).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                startActivity(new Intent(CdpTestActivity.this, DynamicContent1Activity.class));
            }
        });
        findViewById(R.id.test_content_2_btn).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                startActivity(new Intent(CdpTestActivity.this, DynamicContent2Activity.class));
            }
        });
        findViewById(R.id.test_content_3_btn).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                startActivity(new Intent(CdpTestActivity.this, DynamicContent3Activity.class));
            }
        });
        findViewById(R.id.test_list_1_btn).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                startActivity(new Intent(CdpTestActivity.this, DynamicList1Activity.class));
            }
        });
        findViewById(R.id.test_list_2_btn).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                startActivity(new Intent(CdpTestActivity.this, DynamicList2Activity.class));
            }
        });
        findViewById(R.id.test_list_3_btn).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                startActivity(new Intent(CdpTestActivity.this, DynamicList3Activity.class));
            }
        });
        findViewById(R.id.test_upload_log_btn).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                LoggerFactory.getLogContext().flush(false);
                LoggerFactory.getLogContext().uploadAfterSync(null);
            }
        });
        findViewById(R.id.cdp_test_ui_view).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                onCdpTestUiViewClick(v);
            }
        });
        findViewById(R.id.cdp_test_case_view).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                onClickCase(getApplicationContext());
            }
        });
    }
    public static void onClickCase(Context applicationContext) {
        try {
            Class healthActivity = Class.forName("com.mpaas.diagnose.ui.HealthBizSelectActivity");
            Intent intent = new Intent(applicationContext, healthActivity);
            intent.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
            applicationContext.startActivity(intent);
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }

    }

    private void onCdpTestUiViewClick(View v) {
        CdpTestUiViewActivity.startActivity(this);

    }
}
