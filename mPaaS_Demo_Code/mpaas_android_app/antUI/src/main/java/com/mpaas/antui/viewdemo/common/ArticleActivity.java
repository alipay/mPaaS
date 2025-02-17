package com.mpaas.antui.viewdemo.common;

import android.app.Activity;
import android.os.Bundle;
import android.widget.Toast;

/**
 * Created by minghui on 2017/8/29.
 */

public class ArticleActivity extends Activity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);


        Toast.makeText(ArticleActivity.this, "暂未开放",Toast.LENGTH_SHORT).show();
        finish();

    }

}
