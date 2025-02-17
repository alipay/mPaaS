package com.mpaas.antui.viewdemo.view;

import android.content.Context;
import android.util.AttributeSet;
import android.view.LayoutInflater;

import com.mpaas.antui.R;
import com.alipay.mobile.antui.basic.AULinearLayout;

/**
 * Created by kuaikuai(simonazhou.zxm@antfin.com) on 18/3/23.
 */

public class AULinearLayoutViewTest extends AULinearLayout {

    public AULinearLayoutViewTest(Context context) {
        super(context);
        init(context);
    }

    public AULinearLayoutViewTest(Context context, AttributeSet attrs) {
        super(context, attrs);
        init(context);
    }

    public AULinearLayoutViewTest(Context context, AttributeSet attrs, int defStyleAttr) {
        super(context, attrs, defStyleAttr);
        init(context);
    }

    private void init(Context context) {
        LayoutInflater.from(context).inflate(R.layout.view_aulinearlayoutitem, this);
    }
}
