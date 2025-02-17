package com.mpaas.antui.viewdemo;

import android.app.Activity;
import android.os.Bundle;
import android.widget.ScrollView;

import com.mpaas.antui.R;
import com.alipay.mobile.antui.api.AUScrollViewListener;
import com.alipay.mobile.antui.basic.AUImageView;
import com.alipay.mobile.antui.basic.AUScrollView;
import com.alipay.mobile.antui.basic.AUTitleBar;

/**
 * Created by xuanmu on 16/10/8.
 */
public class ScrollTitleBarActivity extends Activity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.view_scroll_titlebar);
        initTitlebar((AUTitleBar) findViewById(R.id.title_bar));

    }

    private void initTitlebar(final AUTitleBar titleBar) {
        final AUImageView testImg = (AUImageView) findViewById(R.id.test_img);
        AUScrollView testScroll = (AUScrollView) findViewById(R.id.test_scroll);

        titleBar.handleScrollChange(testImg.getMeasuredHeight(), 0);
        testScroll.setScrollViewListener(new AUScrollViewListener() {
            @Override
            public void onScrollChanged(ScrollView scrollView, int x, int y, int oldx, int oldy) {
                titleBar.handleScrollChange(y);
            }
        });

    }
}