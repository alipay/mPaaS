package com.mpaas.antui.viewdemo;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.widget.LinearLayout;

import com.alipay.mobile.antui.bar.AUTabBarItem;
import com.alipay.mobile.antui.utils.PublicResources;
import com.mpaas.antui.R;


/**
 * Created by xuanmu on 16/10/8.
 */
public class AUTabBarActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        View v = View.inflate(this, R.layout.view_tabbar, null);
        setContentView(v);

        LinearLayout container = (LinearLayout) findViewById(R.id.container);
        /** AUTabBarItem start **/

        final AUTabBarItem tab_3 = new AUTabBarItem(this);
        container.addView(tab_3);
        tab_3.setText("标签5");
        tab_3.setIconUnicode(PublicResources.String_iconfont_alipaylogo_h);
        tab_3.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                tab_3.setSelected(true);
            }
        });

        /** AUTabBarItem end **/

    }
}
