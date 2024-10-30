package com.mpaas.antui.viewdemo.view;

import android.content.Context;
import android.util.AttributeSet;
import android.view.LayoutInflater;

import com.mpaas.antui.R;
import com.alipay.mobile.antui.basic.AUImageView;
import com.alipay.mobile.antui.basic.AURelativeLayout;
import com.alipay.mobile.antui.basic.AUTextView;
import com.alipay.mobile.antui.iconfont.AUIconView;

/**
 * Created by xuanmu on 17/7/18.
 */

public class ExpaGroupItem extends AURelativeLayout {

    private AUTextView groupTitle;
    private AUImageView groupIcon;
    private AUIconView groupArrow;

    public ExpaGroupItem(Context context) {
        super(context);
        init(context);
    }

    public ExpaGroupItem(Context context, AttributeSet attrs) {
        super(context, attrs);
        init(context);
    }

    public ExpaGroupItem(Context context, AttributeSet attrs, int defStyleAttr) {
        super(context, attrs, defStyleAttr);
        init(context);
    }

    private void init(Context context) {
        LayoutInflater.from(context).inflate(R.layout.expa_group_item, this, true);
        groupTitle = (AUTextView) findViewById(R.id.group_title);
        groupIcon = (AUImageView) findViewById(R.id.group_icon);
        groupArrow = (AUIconView) findViewById(R.id.group_arrow);
    }

    public void setInfo(ComponentModel model) {
        groupTitle.setText(model.title);
        groupIcon.setImageResource(model.iconResId);
    }

    public void setArrowVisible(boolean isVisible) {
        groupArrow.setVisibility(isVisible ? VISIBLE : GONE);
    }
}
