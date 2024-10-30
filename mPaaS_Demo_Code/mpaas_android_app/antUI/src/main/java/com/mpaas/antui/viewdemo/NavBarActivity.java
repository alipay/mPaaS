package com.mpaas.antui.viewdemo;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;

import com.mpaas.antui.R;

/**
 * Created by xuanmu on 17/8/18.
 */

public class NavBarActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        View v = View.inflate(this, R.layout.activity_navbar, null);
        setContentView(v);
    }

    public void onNavButtonClick(View view){
        if (view.getTag() instanceof String){
            String type = (String)view.getTag();
            startTitleBarActivity(type);
        }
    }

    private void startTitleBarActivity(String type) {
        Intent intent = new Intent();
        intent.setClassName(this, TitleBarActivity.class.getName());
        intent.setType(type);
        startActivity(intent);
    }
}
