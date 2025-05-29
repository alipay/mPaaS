package com.example.h5;

import android.os.Bundle;
import android.webkit.WebView;
import android.webkit.WebViewClient;

import com.alipay.mobile.framework.app.ui.BaseActivity;
import com.mpaas.H5.R;

public class WebViewActivity1 extends BaseActivity {
    WebView webView;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_webview1111);

        webView = (WebView) findViewById(R.id.webview);

        webView.setWebViewClient(new WebViewClient()); // 确保点击链接时不会离开应用
        webView.getSettings().setJavaScriptEnabled(true); // 启用JavaScript
        webView.loadUrl("https://cy.cloud.ccb.com/united-ecology/#/zgsy/index?channelCode=HB_ZSY_ZSY&svcCtlgNm=hb_index_zsy&gsmsToken=eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJjbGllbnRDb2RlIjoiQzEwIiwiaXNzIjoiZ3Ntc3NpdCIsInRpbWUiOjE3MjU1MzE1ODE2MTgsInVzZXJJZCI6IjEzNTIwMjcwNDcifQ.xkVk39_UHCVuhCAR6exl4Dab0GGVsg6NufTMdmOMt10&gsmsFlag=true&clientCode=C10"); // 加
//        webView.loadUrl("http://192.168.162.161:5500/web/viewer.html?file=http://192.168.162.161:5500//web/2.pdf#"); // 加
    }
}
