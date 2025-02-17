package com.mpaas.antui.viewdemo.common;

import android.app.Activity;
import android.graphics.Color;
import android.os.Bundle;
import android.view.View;
import android.view.ViewGroup;
import android.widget.LinearLayout;
import android.widget.TextView;

import com.alipay.mobile.antui.basic.banner.BannerView;
import com.mpaas.antui.R;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by minghui on 2017/10/12.
 */

public class CarouselActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        View v = View.inflate(this, R.layout.carousel_activity, null);
        setContentView(v);

        LinearLayout layout = (LinearLayout) findViewById(R.id.container);

        BannerView bannerView = new BannerView(this, 4000);
        layout.addView(bannerView);
        List<BannerView.BannerItem> items = new ArrayList<BannerView.BannerItem>();
        items.add(new BannerView.BannerItem());
        items.add(new BannerView.BannerItem());
        items.add(new BannerView.BannerItem());
        items.add(new BannerView.BannerItem());
//        items.add(new BannerView.BannerItem());
//        items.add(new BannerView.BannerItem());
//        items.add(new BannerView.BannerItem());
//        items.add(new BannerView.BannerItem());
//        items.add(new BannerView.BannerItem());

        final List<String> list = new ArrayList<String>();
        String color1 = "#111111";
        String color2 = "#108ee9";
        String color3 = "#FFFFFF";

        list.add(color1);
        list.add(color2);
        list.add(color3);
        list.add(color1);
//        list.add(color2);
//        list.add(color3);
//        list.add(color1);
//        list.add(color2);
//        list.add(color3);

        BannerView.BaseBannerPagerAdapter adapter = new BannerView.BaseBannerPagerAdapter(bannerView, items) {
            @Override
            public View getView(ViewGroup container, int position) {
                TextView tv = new TextView(CarouselActivity.this);
                tv.setBackgroundColor(Color.parseColor(list.get(position)));
                container.addView(tv);
                return tv;
            }
        };
//        bannerView.setIndicatorPositionFromBottom(DensityUtil.dip2px(getBaseContext(), 10));
//        bannerView.setIndicatorStyleDark(true);
        bannerView.setAdapter(adapter);
    }
}
