package com.mpaas.cdpdemo;

import android.os.Bundle;
import android.widget.TextView;


/**
 * Created by gezihua on 2019/12/18.
 */

/**
 * 动态公告最佳实践
 * 1. 页面顶部，页面底部
 * 2. 列表头部，列表底部
 */
public class AnnouncementFullLocationActivity extends FulllocationBaseActivity {
    private TextView title_text;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.mcdp_demo_actiivty_annoucement_fulllocation);
        title_text = (TextView) findViewById(R.id.title_text);
        title_text.setText(getString(R.string.gonggaoquanweizhishili));
        enableListModel();
    }

}
