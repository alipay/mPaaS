package com.mpaas.mindemo;

import android.annotation.SuppressLint;
import android.content.Context;
import android.os.Bundle;
import android.view.View;

import com.alibaba.ariver.app.api.App;
import com.alibaba.ariver.resource.api.appinfo.UpdateAppCallback;
import com.alibaba.ariver.resource.api.appinfo.UpdateAppException;
import com.alibaba.ariver.resource.api.models.AppModel;
import com.alipay.mobile.framework.app.ui.BaseActivity;
import com.mpaas.mas.adapter.api.MPLogger;
import com.mpaas.mriver.api.debug.MriverDebug;
import com.mpaas.mriver.api.integration.Mriver;
import com.mpaas.mriver.api.resource.MriverResource;
import com.mpaas.mriver.base.view.title.ITitleView;
import com.mpaas.mriver.base.view.title.TitleViewFactoryProxy;

import java.util.List;

public class MriverActivity extends BaseActivity {

    @SuppressLint("MissingInflatedId")
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_mriver);


        findViewById(R.id.btnNew).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                //无胶囊
                Mriver.setProxy(TitleViewFactoryProxy.class, new TitleViewFactoryProxy() {
                    @Override
                    public ITitleView createTitle(Context context, App app) {
                        return new CustomTitleView(context);
                    }
                });
                Bundle bundle = new Bundle();
                bundle.putString("query", "name=123&pwd=456");//设置参数
                Mriver.startApp(MriverActivity.this, "8899889988998899", bundle);
            }
        });
        findViewById(R.id.btnNewaa).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                //有胶囊
                Mriver.setProxy(TitleViewFactoryProxy.class, new TitleViewFactoryProxy() {
                    @Override
                    public ITitleView createTitle(Context context, App app) {
                        return null;
                    }
                });
                Bundle bundle = new Bundle();
                bundle.putString("page", "pages/index/index");//设置路径
                bundle.putString("query", "name=2222&pwd=0000");//设置参数
                Mriver.startApp(MriverActivity.this, "2022061311260001", bundle);
            }
        });

        findViewById(R.id.btnScan).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                MriverDebug.debugAppByScan(MriverActivity.this);
            }
        });
        MriverResource.updateApp("8899889988998899", new UpdateAppCallback() {
            @Override
            public void onSuccess(List<AppModel> list) {
                if (list != null && list.size() > 0) {
                    MPLogger.error("更新小程序", "onSuccess:" + list.get(0).getAppId() + "     " + list.get(0).getAppVersion());
                } else {
                    MPLogger.error("更新小程序", "onSuccess null");
                }
            }

            @Override
            public void onError(UpdateAppException e) {
                MPLogger.error("更新小程序", "onError:" + e.getMessage());
            }
        });
    }
}