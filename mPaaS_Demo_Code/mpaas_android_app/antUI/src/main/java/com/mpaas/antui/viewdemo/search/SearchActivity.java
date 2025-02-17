package com.mpaas.antui.viewdemo.search;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;

import com.mpaas.antui.R;
import com.alipay.mobile.antui.basic.AUButton;

/**
 * Created by minghui on 2017/8/22.
 */

public class SearchActivity extends Activity{

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        View v = View.inflate(this, R.layout.search_activity, null);
        setContentView(v);

        AUButton searchBtn = (AUButton) findViewById(R.id.search_btn);
        searchBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startActivity(new Intent(SearchActivity.this, TopSearchActivity.class));
            }
        });
    }
}
