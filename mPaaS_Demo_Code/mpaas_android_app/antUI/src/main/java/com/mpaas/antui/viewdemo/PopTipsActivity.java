package com.mpaas.antui.viewdemo;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;

import com.mpaas.antui.R;
import com.alipay.mobile.antui.basic.AUButton;
import com.alipay.mobile.antui.basic.AUTextView;
import com.alipay.mobile.antui.pop.AUPopBar;
import com.alipay.mobile.antui.pop.AUPopTipView;

/**
 * Created by kuaikuai(simonazhou.zxm@antfin.com) on 18/4/4.
 */

public class PopTipsActivity extends Activity {

    AUTextView auTextView;
    AUPopTipView auPopTipView;
    AUPopTipView auPopTipView1;
    AUPopTipView auPopTipView2;
    AUPopTipView auPopTipView3;
    AUButton auButton;
    AUButton auButton1;
    AUButton auButton2;
    AUButton auButton3;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_pop_tips);
        auTextView = (AUTextView) findViewById(R.id.tv_tips);
        auButton = (AUButton) findViewById(R.id.ab_tips);
        auButton1 = (AUButton) findViewById(R.id.ab_tips1);
        auButton2 = (AUButton) findViewById(R.id.ab_tips2);
        auButton3 = (AUButton) findViewById(R.id.ab_tips3);

//        auPopBar.setTipsText(Html.fromHtml("<font size=\"3\" color=\"red\">我是气泡我是气泡我是气泡我是气泡我是气泡我是气泡我是气泡我是气泡</font>"));
        AUPopBar auPopBar = new AUPopBar(this);
        auPopBar.setTipsText("我是气泡我是气我是气泡我是气");
        auPopBar.setRightBottonText("立即添加");
        auPopBar.getLeftImageView().setImageResource(R.drawable.image);
        auPopBar.show();
//        auPopBar.show();
//        auPopBar.hideLeftImageView(true);
//        auPopBar.hideRightButton(true);
        auPopTipView = new AUPopTipView(this);
        auPopTipView1 = new AUPopTipView(this);
        auPopTipView2 = new AUPopTipView(this);
        auPopTipView3 = new AUPopTipView(this);
        auPopTipView3.disappearByClickView();
        auPopTipView3.setTipClickedListener(new AUPopTipView.OnToolTipClickedListener() {
            @Override
            public void onToolTipClicked(View view) {
                auPopTipView3.dismiss();
            }
        });

        auButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                auPopTipView.showTipView(auButton, "我是气泡我是气泡我是气泡我是气泡", "知道了", false);
            }
        });
        auButton1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                auPopTipView1.showTipView(auButton1, "我是气泡");
            }
        });
        auButton2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                auPopTipView2.showTipView(auButton2, "我是气泡我是气泡我是气泡我是气泡", "知道了", true);
            }
        });
        auButton3.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                auPopTipView3.showTipView(auButton3, "我是气泡我是气泡我是气泡我是气泡我是气泡我是气泡我是气泡我是气泡我是气泡我是气泡我是", "知道了");

            }
        });

    }

}
