package com.mpaas.antui.viewdemo.view;

import android.content.Context;
import android.content.res.TypedArray;
import android.util.AttributeSet;
import android.view.Gravity;
import android.view.LayoutInflater;

import com.alipay.mobile.antui.utils.PublicResources;
import com.mpaas.antui.R;
import com.alipay.mobile.antui.basic.AULinearLayout;
import com.alipay.mobile.antui.basic.AUTextView;
import com.alipay.mobile.antui.utils.DensityUtil;

/**
 * Created by xuanmu on 17/8/17.
 */

public class BaseHeadView extends AULinearLayout {

    public BaseHeadView(Context context) {
        super(context);
        init(context, null);
    }

    public BaseHeadView(Context context, AttributeSet attrs) {
        super(context, attrs);
        init(context, attrs);
    }

    public BaseHeadView(Context context, AttributeSet attrs, int defStyleAttr) {
        super(context, attrs, defStyleAttr);
        init(context, attrs);
    }

    private void init(Context context, AttributeSet attrs){
        LayoutInflater.from(context).inflate(R.layout.view_base_head, this, true);
        this.setOrientation(VERTICAL);
        this.setGravity(Gravity.CENTER);
        this.setPadding(0, 0, 0, DensityUtil.dip2px(context, 30));

        AUTextView titleContent = (AUTextView)findViewById(R.id.title_content);

        if (attrs != null) {
            TypedArray array = context.obtainStyledAttributes(attrs, PublicResources.Attr_Title_Bar);
            if (array.hasValue(PublicResources.Attr_Title_Bar_titleText)) {
                String titleText = array.getString(PublicResources.Attr_Title_Bar_titleText);
                titleContent.setText(titleText);
            }
            array.recycle();
        }
    }

}
