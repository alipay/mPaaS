package com.mpaas.cdpdemo;

import android.os.Bundle;
import android.view.View;
import android.widget.TextView;


/**
 * cdp.SinglelineFullLocationActivity
 * Created by gezihua on 2019/12/18.
 */

public class SinglelineFullLocationActivity extends FulllocationBaseActivity {
    private TextView title_text;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.mcdp_demo_actiivty_annoucement_fulllocation);
        title_text = (TextView) findViewById(R.id.title_text);
        title_text.setText(getString(R.string.single_advertising_practice));
        findViewById(R.id.dynamic_content_lv).setVisibility(View.VISIBLE);
        enableListModel();
    }
}
