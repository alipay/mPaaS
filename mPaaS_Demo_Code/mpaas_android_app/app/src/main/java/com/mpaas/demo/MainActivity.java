package com.mpaas.demo;

import android.content.Intent;
import android.content.pm.PackageManager;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;

import androidx.core.app.ActivityCompat;

import com.alipay.mobile.monitor.track.TrackIntegrator;
import com.example.h5.HomeActivity1;
import com.example.h5.OfflineActivity;
import com.mpaas.analytics.AnalyticsActivity;
import com.mpaas.antui.viewdemo.HomeAntUIActivity;
import com.mpaas.cdpdemo.CdpPortalActivity;
import com.mpaas.cdpdemo.SplashActivity;
import com.mpaas.config.ConfigServiceActivity;
import com.mpaas.demo.base.BaseActivity;
import com.mpaas.demo.hotpatch.HotpatchActivityPoc;
import com.mpaas.demo.sync.SyncLauncherActivity;
import com.mpaas.demo.uicontrol.UIControlActivity;
import com.mpaas.gdmap.GdMapActivity;
import com.mpaas.mas.adapter.api.MPDiagnose;
import com.mpaas.mas.adapter.api.MPLogger;
import com.mpaas.mas.adapter.api.MPTracker;
import com.mpaas.mindemo.MriverActivity;
import com.mpaas.nebula.adapter.api.MPNebula;
import com.mpaas.push.mpPush.PushLauncherActivity;
import com.mpaas.upgrade.UpgradeActivity;

import java.util.HashMap;
import java.util.Map;

public class MainActivity extends BaseActivity {

    private static final int REQUEST_EXTERNAL_STORAGE = 1;
    private static String[] PERMISSIONS_STORAGE = {
            "android.permission.READ_EXTERNAL_STORAGE",
            "android.permission.WRITE_EXTERNAL_STORAGE",
            "android.permission.READ_PHONE_STATE"};


    public static final String Tag = "MpaasPoc";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main_poc);

        /*
         * android 动态权限申请
         * */

        try {
            //检测是否有写的权限
            int permission = ActivityCompat.checkSelfPermission(MainActivity.this,
                    "android.permission.WRITE_EXTERNAL_STORAGE");
            if (permission != PackageManager.PERMISSION_GRANTED) {
                // 没有写的权限，去申请写的权限，会弹出对话框
                ActivityCompat.requestPermissions(MainActivity.this, PERMISSIONS_STORAGE, REQUEST_EXTERNAL_STORAGE);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }


        if (SplashActivity.checkIfSplashPrepared()) {
            startActivity(new Intent(this, SplashActivity.class));
            overridePendingTransition(0, 0);
        }
        setAnalyticsSetting();
        findViewById(R.id.btn_fast_start).setOnClickListener(new OnClickListener() {
            @Override
            public void onClick(View v) {
                MPLogger.info(Tag, "startTinyApp");
                MPLogger.error(Tag, "startTinyApp");
                String logId = "startTinyApp";
                // bizType 标识业务类型，相同 bizType 的自定义日志将遵循同样的上报策略，存储在同一个文件中，文件名为进程名_bizType
                // bizType 可以为空，默认为 userbehavor
                String bizType = "Pay";
                // params 为自定义参数，控制台自定义分析中事件的自定义属性对应这些键值对
                Map<String, String> params = new HashMap<>();
                params.put("time", "2021-07-15");
                MPLogger.event(logId, bizType, params);
                Intent intent = new Intent(MainActivity.this, MriverActivity.class);
                startActivity(intent);
            }
        });
        //高德地图
        findViewById(R.id.btn_gdmap).setOnClickListener(new OnClickListener() {

            @Override
            public void onClick(View v) {
                MPLogger.info(Tag, "gdmap");
                MPLogger.error(Tag, "gdmap");
                String logId = "gdmap";
                // bizType 标识业务类型，相同 bizType 的自定义日志将遵循同样的上报策略，存储在同一个文件中，文件名为进程名_bizType
                // bizType 可以为空，默认为 userbehavor
                String bizType = "Pay";
                // params 为自定义参数，控制台自定义分析中事件的自定义属性对应这些键值对
                Map<String, String> params = new HashMap<>();
                params.put("time", "2021-07-15");
                MPLogger.event(logId, bizType, params);

                Intent intent = new Intent(MainActivity.this, GdMapActivity.class);
                startActivity(intent);
            }
        });


        //移动网关服务
        findViewById(R.id.btn_rpc).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                MPLogger.info(Tag, "rpc");
                MPLogger.error(Tag, "rpc");
                String logId = "rpc";
                // bizType 标识业务类型，相同 bizType 的自定义日志将遵循同样的上报策略，存储在同一个文件中，文件名为进程名_bizType
                // bizType 可以为空，默认为 userbehavor
                String bizType = "Pay";
                // params 为自定义参数，控制台自定义分析中事件的自定义属性对应这些键值对
                Map<String, String> params = new HashMap<>();
                params.put("time", "2021-07-15");
                MPLogger.event(logId, bizType, params);
                Intent intent = new Intent(MainActivity.this, RpcMainActivity.class);
                startActivity(intent);
            }
        });

        findViewById(R.id.btn_sync).setOnClickListener(new OnClickListener() {
            @Override
            public void onClick(View v) {
                MPLogger.info(Tag, "sync");
                MPLogger.error(Tag, "sync");
                String logId = "sync";
                // bizType 标识业务类型，相同 bizType 的自定义日志将遵循同样的上报策略，存储在同一个文件中，文件名为进程名_bizType
                // bizType 可以为空，默认为 userbehavor
                String bizType = "Pay";
                // params 为自定义参数，控制台自定义分析中事件的自定义属性对应这些键值对
                Map<String, String> params = new HashMap<>();
                params.put("time", "2021-07-17");
                MPLogger.event(logId, bizType, params);
                Intent intent = new Intent(MainActivity.this, SyncLauncherActivity.class);
                startActivity(intent);
            }
        });

        //跳转UI组件
        findViewById(R.id.btn_uikongjian).setOnClickListener(new OnClickListener() {
            @Override
            public void onClick(View v) {
                MPLogger.info(Tag, "跳转UI组件");
                MPLogger.error(Tag, "跳转UI组件");
                Intent intent1 = new Intent(MainActivity.this, UIControlActivity.class);
                startActivity(intent1);
            }
        });

        //升级
        findViewById(R.id.btn_upgrade).setOnClickListener(new OnClickListener() {
            @Override
            public void onClick(View v) {
                MPLogger.info(Tag, "升级");
                MPLogger.error(Tag, "升级");
                Intent intent = new Intent(MainActivity.this, UpgradeActivity.class);
                startActivity(intent);
            }
        });

        //热修复
        findViewById(R.id.btn_hot_patch).setOnClickListener(new OnClickListener() {
            @Override
            public void onClick(View v) {
                MPLogger.info(Tag, "热修复");
                MPLogger.error(Tag, "热修复");
                Intent intent = new Intent(MainActivity.this, HotpatchActivityPoc.class);
                startActivity(intent);
            }
        });

        //移动分析
        findViewById(R.id.btn_analytics).setOnClickListener(new OnClickListener() {
            @Override
            public void onClick(View v) {
                MPLogger.info(Tag, "移动分析");
                MPLogger.error(Tag, "移动分析");
                Intent intent = new Intent(MainActivity.this, AnalyticsActivity.class);
                startActivity(intent);
            }
        });

        //H5resources
        findViewById(R.id.H5).setOnClickListener(new OnClickListener() {
            @Override
            public void onClick(View v) {
                MPLogger.info(Tag, "H5resources");
                MPLogger.error(Tag, "H5resources");
                startActivity(new Intent(MainActivity.this, HomeActivity1.class));
            }
        });

        //antui
        findViewById(R.id.btn_antUI).setOnClickListener(new OnClickListener() {
            @Override
            public void onClick(View v) {
                MPLogger.info(Tag, "antui");
                MPLogger.error(Tag, "antui");
                startActivity(new Intent(MainActivity.this, HomeAntUIActivity.class));
            }
        });

        //配置开关管理
        findViewById(R.id.btn_config_service).setOnClickListener(new OnClickListener() {
            @Override
            public void onClick(View v) {
                MPLogger.info(Tag, "配置开关管理");
                MPLogger.error(Tag, "配置开关管理");
                startActivity(new Intent(MainActivity.this, ConfigServiceActivity.class));
            }
        });

        findViewById(R.id.btn_cdp).setOnClickListener(new OnClickListener() {
            @Override
            public void onClick(View v) {
                MPLogger.info(Tag, "cdp");
                MPLogger.error(Tag, "cdp");
                startActivity(new Intent(MainActivity.this, CdpPortalActivity.class));
            }
        });

        findViewById(R.id.btn_push).setOnClickListener(new OnClickListener() {
            @Override
            public void onClick(View v) {
                startActivity(new Intent(MainActivity.this, PushLauncherActivity.class));
            }
        });
    }

    //设置移动分析：启动事件统计/
    private void setAnalyticsSetting() {
        // 开启自动化日志
        // 开发者可在 MockLauncherActivityAgent.postInit() 中调用
        MPLogger.enableAutoLog();
        TrackIntegrator.getInstance().autoTrackClick(true);

        MPTracker.onActivityCreate(this);
        MPLogger.setUserId("MpaasPoc");
        // 初始化 Sync 通道，必须先设置 userId，否则会初始化失败
        MPDiagnose.initSyncChannel(this);
        MPLogger.reportLaunchTime(this);
        // 设置 userId 并上报用户登录，白名单功能也将使用这里设置的 userId
        MPLogger.reportUserLogin(MPLogger.getUserId());
        homePage();
    }

    private void homePage() {
        String logId = "openAppNum";
        // bizType 标识业务类型，相同 bizType 的自定义日志将遵循同样的上报策略，存储在同一个文件中，文件名为进程名_bizType
        // bizType 可以为空，默认为 userbehavor
        String bizType = "Pay";
        // params 为自定义参数，控制台自定义分析中事件的自定义属性对应这些键值对
        Map<String, String> params = new HashMap<>();
        params.put("time", "2021-07-15");
        MPLogger.event(logId, bizType, params);
    }


    @Override
    public void onWindowFocusChanged(boolean hasFocus) {
        super.onWindowFocusChanged(hasFocus);
        MPTracker.onActivityWindowFocusChanged(this, hasFocus);
    }

    @Override
    protected void onResume() {
        super.onResume();
        MPTracker.onActivityResume(this);
    }
}