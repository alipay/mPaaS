package com.mpaas.antui.viewdemo;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.view.ViewGroup;
import android.widget.LinearLayout;

import com.mpaas.antui.R;
import com.alipay.mobile.antui.basic.AULinearLayout;
import com.alipay.mobile.antui.profession.AUQRCodeView;
import com.mpaas.antui.viewdemo.view.DemoTitleBar;

/**
 * Created by xuanmu on 17/5/19.
 */

public class QRCodeActivity extends Activity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        AULinearLayout linearLayout = new AULinearLayout(this);
        linearLayout.setOrientation(LinearLayout.VERTICAL);
        DemoTitleBar titleBar = new DemoTitleBar(this);
        final AUQRCodeView codeView = new AUQRCodeView(this);
        titleBar.setTitleText("二维码名片和吱口令");
        linearLayout.addView(titleBar, new ViewGroup.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.WRAP_CONTENT));
        linearLayout.addView(codeView, new ViewGroup.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.MATCH_PARENT));
        setContentView(linearLayout);

        codeView.setAvatarName("生活号名称");
        codeView.setAvatarDescription("城市 区域");
        codeView.setCodeInfo("用支付宝扫二维码，加入该生活圈", "该二维码将在2017年11月05日失效");
        codeView.setButtonInfo("保存到本地", "", false);
        codeView.getCodeImage().setImageResource(R.drawable.qr_default);

        titleBar.getTitleContainer().setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                codeView.setAvatarName("生活号名称生活号名称生活号名称生活号名称生活号名称生活号名称生活号名称");
                codeView.setAvatarDescription("");
                codeView.setCodeInfo("用支付宝扫二维码，关注生活号", "");
                codeView.setButtonInfo("点击生成吱口令", "推荐生活号給微信、QQ好友");
            }
        });

        codeView.getButton().setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                codeView.setButtonVisibility(false);
            }
        });
    }
}
