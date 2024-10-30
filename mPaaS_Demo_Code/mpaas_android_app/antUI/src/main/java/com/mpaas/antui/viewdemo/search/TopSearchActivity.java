package com.mpaas.antui.viewdemo.search;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;

import com.mpaas.antui.R;
import com.alipay.mobile.antui.basic.AUSearchBar;

/**
 * Created by minghui on 2017/8/22.
 */

public class TopSearchActivity extends Activity{

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        View v = View.inflate(this, R.layout.top_search_activity, null);
        setContentView(v);

        AUSearchBar searchBar = (AUSearchBar) findViewById(R.id.search_bar);
        searchBar.getSearchButton().setEnabled(true);

    }
}
