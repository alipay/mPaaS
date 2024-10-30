package com.mpaas.antui.viewdemo.list;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;

import com.mpaas.antui.R;
import com.mpaas.antui.viewdemo.RefreshActivity;

/**
 * Created by xuanmu on 17/12/7.
 */

public class ListViewActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_list_view);
    }

    public void onListButtonClick(View view){
        if (view.getTag() instanceof String){
            String type = (String)view.getTag();
            if ("1".equals(type))
                startRefreshActivity(RefreshActivity.STYLE_1);
            else if ("2".equals(type)){
                startRefreshActivity(RefreshActivity.STYLE_2);
            } else if ("3".equals(type)){
                startRefreshActivity(RefreshActivity.STYLE_3);
            }
        }
    }

    private void startRefreshActivity(String type) {
        Intent intent = new Intent();
        intent.setClassName(this, RefreshActivity.class.getName());
        intent.setType(type);
        startActivity(intent);
    }
}
