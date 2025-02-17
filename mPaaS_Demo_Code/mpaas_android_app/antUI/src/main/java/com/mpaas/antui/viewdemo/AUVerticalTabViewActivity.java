package com.mpaas.antui.viewdemo;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;

import com.alipay.mobile.antui.bar.AUVerticalTabView;
import com.mpaas.antui.R;

import java.util.ArrayList;
import java.util.List;


/**
 * Created by xuanmu on 16/10/8.
 */
public class AUVerticalTabViewActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        View v = View.inflate(this, R.layout.view_verticaltabbar, null);
        setContentView(v);
        AUVerticalTabView tabView = (AUVerticalTabView) findViewById(R.id.verticalTabView);
        List<String> items = new ArrayList<String>();
        items.add("推荐");
        items.add("日韩");
        items.add("东南亚");
        items.add("南美洲");
        items.add("北美洲");
        items.add("亚洲");
        items.add("欧洲");
        items.add("非洲");
        items.add("大洋洲");
        items.add("港澳台");
        tabView.setItems(items);
        tabView.setSelected(3);
    }
}
