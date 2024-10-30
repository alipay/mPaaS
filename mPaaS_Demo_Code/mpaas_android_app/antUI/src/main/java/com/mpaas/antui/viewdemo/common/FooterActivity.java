package com.mpaas.antui.viewdemo.common;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.widget.Toast;

import com.mpaas.antui.R;
import com.alipay.mobile.antui.common.AUPageFooterView;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by minghui on 2017/8/22.
 */

public class FooterActivity extends Activity{

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        View v = View.inflate(this, R.layout.footer_activity, null);
        setContentView(v);

        AUPageFooterView footerView1 = (AUPageFooterView) findViewById(R.id.footer1);
        AUPageFooterView footerView2 = (AUPageFooterView) findViewById(R.id.footer2);
        AUPageFooterView footerView3 = (AUPageFooterView) findViewById(R.id.footer3);
        AUPageFooterView footerView4 = (AUPageFooterView) findViewById(R.id.footer4);

        footerView1.setCopyRightText("© 2004-2017 Alipay.com. All rights reserved.");

        List<String> linklist2 = new ArrayList<String>();
        linklist2.add("底部链接");
        footerView2.setCopyRightText("© 2004-2017 Alipay.com. All rights reserved.");
        footerView2.addFooterLinker(linklist2);

        footerView2.setOnLinkClickListener(new AUPageFooterView.OnLinkClickListener() {
            @Override
            public void OnLinkClick(int index) {
                Toast.makeText(FooterActivity.this, "click index"+index, Toast.LENGTH_SHORT).show();
            }
        });


        List<String> linklist3 = new ArrayList<String>();
        linklist3.add("底部链接");
        linklist3.add("底部链接");
        linklist3.add("底部链接goduwqioougfor");
        footerView3.setCopyRightText("© 2004-2017 Alipay.com. All rights reserved.");
        footerView3.addFooterLinker(linklist3);

        footerView3.setOnLinkClickListener(new AUPageFooterView.OnLinkClickListener() {
            @Override
            public void OnLinkClick(int index) {

                Toast.makeText(FooterActivity.this, "click index"+index, Toast.LENGTH_SHORT).show();
            }
        });

        List<String> linklist4 = new ArrayList<String>();
        linklist4.add("底部链接");
        linklist4.add("底部链接");
        footerView4.addFooterLinker(linklist4);
        footerView4.setCopyRightTextViewVisible(View.GONE);

        footerView4.setOnLinkClickListener(new AUPageFooterView.OnLinkClickListener() {
            @Override
            public void OnLinkClick(int index) {

                Toast.makeText(FooterActivity.this, "click index"+index, Toast.LENGTH_SHORT).show();
            }
        });


    }
}
