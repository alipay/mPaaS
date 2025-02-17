package com.example.h5;

import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.widget.ImageView;

import com.alipay.mobile.framework.app.ui.BaseActivity;
import com.bumptech.glide.Glide;
import com.mpaas.H5.R;


public class H5LoadPublicResActivity extends BaseActivity {

    private static final String TAG = "PublicResActivity";
    private ImageView iv_public_res;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_public_res);
        iv_public_res = (ImageView) findViewById(R.id.iv_public_res);
        Glide.with(this)
                .load("https://mcube-prod.cn-hangzhou.oss.aliyuncs.com/ONEXDF259A2051016_shaojian/1.0.0/test.png")
                .into(iv_public_res);
    }

    public static void startSelf(Context context){
        if (context == null){
            return;
        }
        context.startActivity(new Intent(context, H5LoadPublicResActivity.class));
    }
}
