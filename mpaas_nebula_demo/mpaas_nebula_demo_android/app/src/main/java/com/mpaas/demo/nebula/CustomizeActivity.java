package com.mpaas.demo.nebula;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;

import com.alipay.mobile.antui.basic.AUTitleBar;
import com.alipay.mobile.antui.basic.AUToast;
import com.alipay.mobile.framework.app.ui.BaseActivity;
import com.alipay.mobile.h5container.api.H5Plugin;
import com.mpaas.nebula.adapter.api.MPNebula;

/**
 * Created by omg on 2018/7/23.
 * 此页面所有涉及到的设置通常应在应用启动后执行，且只需执行一次。
 * 此处仅为演示。
 */

public class CustomizeActivity extends BaseActivity {

    private AUTitleBar mTitle;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_customize);
        mTitle = (AUTitleBar) findViewById(R.id.titlebar);

        findViewById(R.id.btn_ua_setting).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                enableUa();
                AUToast.makeToast(CustomizeActivity.this, R.string.setting_success, 2000).show();
            }
        });
        findViewById(R.id.btn_title_setting).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                enableCustomizedTitle();
                AUToast.makeToast(CustomizeActivity.this, R.string.setting_success, 2000).show();
            }
        });
        findViewById(R.id.btn_menu_setting).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                enableCustomizedMenu();
                AUToast.makeToast(CustomizeActivity.this, R.string.setting_success, 2000).show();
            }
        });
        findViewById(R.id.btn_progress_setting).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                enableCustomizedProgress();
                AUToast.makeToast(CustomizeActivity.this, R.string.setting_success, 2000).show();
            }
        });
        findViewById(R.id.btn_pullrefresh_setting).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                enableCustomizedPullRefresh();
                AUToast.makeToast(CustomizeActivity.this, R.string.setting_success, 2000).show();
            }
        });
        findViewById(R.id.btn_bg_setting).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                enableCustomizedBackground();
                AUToast.makeToast(CustomizeActivity.this, R.string.setting_success, 2000).show();
            }
        });
        findViewById(R.id.btn_plugin_url_intercept).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                registerUrlInterceptPlugin();
                AUToast.makeToast(CustomizeActivity.this, R.string.setting_success, 2000).show();
            }
        });
        findViewById(R.id.btn_embed_webview).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                startActivity(new Intent(CustomizeActivity.this, EmbedActivity.class));
            }
        });
        mTitle.setTitleText(getString(R.string.customize));
    }

    private void enableUa() {
        MPNebula.setUa(new H5UaProviderImpl());
    }

    private void enableCustomizedTitle() {
        MPNebula.setCustomViewProvider(new CustomTitleH5ViewProvider());
    }

    private void enableCustomizedMenu() {
        MPNebula.setCustomViewProvider(new CustomNaviMenuH5ViewProvider());
    }

    private void enableCustomizedProgress() {
        MPNebula.setCustomViewProvider(new CustomProgressH5ViewProvider());
    }

    private void enableCustomizedPullRefresh() {
        MPNebula.setCustomViewProvider(new CustomPullHeaderH5ViewProvider());
    }

    /**
     * 完全自定义背景
     * <p>
     * 若仅需修改背景颜色，无需调用此方法
     * 只需在打开 H5 时传递参数：
     * Bundle bundle = new Bundle();
     * bundle.putInt(H5Param.LONG_BOUNCE_TOP_COLOR, getResources().getColor(R.color.xxxx));
     */
    private void enableCustomizedBackground() {
        MPNebula.setCustomViewProvider(new CustomBackgroudH5ViewProvider());
    }

    private void registerUrlInterceptPlugin() {
        MPNebula.registerH5Plugin(
                MyUrlInterceptPlugin.class.getName(),
                null,
                "page",
                new String[]{H5Plugin.CommonEvents.H5_PAGE_SHOULD_LOAD_URL}
        );
    }
}
