package com.mpaas.antui.viewdemo;

import android.app.Activity;
import android.graphics.drawable.ColorDrawable;
import android.graphics.drawable.StateListDrawable;
import android.os.Bundle;

import com.alipay.mobile.antui.utils.PublicResources;
import com.mpaas.antui.R;
import com.alipay.mobile.antui.basic.AUImageView;
import com.alipay.mobile.antui.basic.AURoundImageView;
import com.alipay.mobile.antui.iconfont.util.IconUtils;

/**
 * Created by xuanmu on 16/12/30.
 */
public class ImageActivity extends Activity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.view_image);

        AURoundImageView round = (AURoundImageView)findViewById(R.id.round);
        round.setImageDrawable(new ColorDrawable(getResources().getColor(PublicResources.Color_AU_COLOR_APP_GREEN)));

        AUImageView imageView = (AUImageView)findViewById(R.id.icon_drawable);
        imageView.setClickable(true);
        StateListDrawable iconDrawable = IconUtils.getTitleIcon_Blue(this, PublicResources.String_iconfont_more);
        imageView.setImageDrawable(iconDrawable);
    }
}
