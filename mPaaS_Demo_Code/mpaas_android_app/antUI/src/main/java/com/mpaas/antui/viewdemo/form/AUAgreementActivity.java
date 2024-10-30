package com.mpaas.antui.viewdemo.form;

import android.app.Activity;
import android.content.Context;
import android.os.Bundle;
import android.text.SpannableStringBuilder;
import android.view.View;

import com.mpaas.antui.R;
import com.alipay.mobile.antui.basic.AUToast;
import com.alipay.mobile.antui.clickspan.UrlClickableSpanListener;
import com.alipay.mobile.antui.profession.AUAgreementView;

/**
 * Created by xuanmu on 18/1/26.
 */

public class AUAgreementActivity extends Activity implements UrlClickableSpanListener {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        View v = View.inflate(this, R.layout.agreement_activity, null);
        setContentView(v);

        AUAgreementView auAgreementView = (AUAgreementView) findViewById(R.id.agreement_view);


        CharSequence agree1 = "《用户授权协议》";
        String url_1 = "用户授权协议_url";
        CharSequence agree2 = "《芝麻服务协议及相关授权条款》";
        String url_2 = "芝麻服务协议及相关授权条款_url";
        CharSequence agree3 = "《骑行用户信息授权协议》";
        String url_3 = "骑行用户信息授权协议_url";
        CharSequence agree4 = "《单车方用户服务协议》";
        String url_4 = "单车方用户服务协议_url";



        SpannableStringBuilder spannableStringBuilder =   auAgreementView.new AgreeTextBuilder()
                .appendCommonText("同意")
                .appendClickText(agree1, url_1, this)
                .appendClickText(agree2, url_2, this)
                .appendClickText(agree3, url_3, this)
                .appendClickText(agree4, url_4, this)
                .buildText();


        auAgreementView.setAgreeText(spannableStringBuilder);
    }

    @Override
    public void onClick(Context mContext, String url) {
        AUToast.showSuperToast(AUAgreementActivity.this, 0, url);
    }
}
