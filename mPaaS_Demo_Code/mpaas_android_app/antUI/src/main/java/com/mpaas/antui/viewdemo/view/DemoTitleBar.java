package com.mpaas.antui.viewdemo.view;

import android.content.Context;
import android.util.AttributeSet;

import com.alipay.mobile.antui.utils.PublicResources;
import com.mpaas.antui.R;
import com.alipay.mobile.antui.basic.AUTitleBar;

/**
 * Created by xuanmu on 17/8/18.
 */

public class DemoTitleBar extends AUTitleBar {
    public DemoTitleBar(Context context) {
        super(context);
        init();
    }

    public DemoTitleBar(Context context, AttributeSet attrs) {
        super(context, attrs);
        init();
    }

    public DemoTitleBar(Context context, AttributeSet attrs, int defStyle) {
        super(context, attrs, defStyle);
        init();
    }

    private void init(){
        setRightButtonIcon(getResources().getString(PublicResources.String_iconfont_search));
        setColorWhiteStyle();
        setBackground(getResources().getDrawable(R.drawable.drawable_gradient_bg));
    }
}
