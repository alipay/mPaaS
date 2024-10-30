package com.mpaas.antui.viewdemo.view;

import android.content.Context;
import android.util.AttributeSet;
import android.view.LayoutInflater;

import com.mpaas.antui.R;
import com.alipay.mobile.antui.basic.AURelativeLayout;

/**
 * Created by xuanmu on 17/8/18.
 */

public class BaseFootView extends AURelativeLayout {
    public BaseFootView(Context context) {
        super(context);
        init(context);
    }

    public BaseFootView(Context context, AttributeSet attrs) {
        super(context, attrs);
        init(context);
    }

    public BaseFootView(Context context, AttributeSet attrs, int defStyle) {
        super(context, attrs, defStyle);
        init(context);
    }

    private void init(Context context){
        LayoutInflater.from(context).inflate(R.layout.view_base_foot, this, true);
    }
}
