package com.mpaas.antui.viewdemo.common;

import android.app.Activity;
import android.os.Bundle;
import android.widget.Toast;

/**
 * Created by minghui on 2017/8/22.
 */

public class FilterActivity extends Activity{
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);


        Toast.makeText(FilterActivity.this, "暂未开放",Toast.LENGTH_SHORT).show();
        finish();

    }

}
