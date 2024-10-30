package com.mpaas.demo.uicontrol.storage;

import android.app.Activity;
import android.widget.BaseAdapter;
import android.widget.Button;
import android.widget.ListView;
import android.widget.TextView;

import com.mpaas.demo.R;

import java.text.SimpleDateFormat;

public class BaseStorageActivity extends Activity {
    protected static final String GROUP_ID = "com_mpaas_demo_storage";
    protected static final SimpleDateFormat SIMPLE_DATE_FORMAT = new SimpleDateFormat("yyyy-MM-dd-HH:mm:ss");
    protected TextView mMainTv;
    protected Button mMainBtn;
    protected ListView mMainLv;
    protected BaseAdapter mAdapter;

    protected void findView() {
        mMainTv = (TextView) findViewById(R.id.storage_main_tv);
        mMainBtn = (Button) findViewById(R.id.storage_main_btn);
        mMainLv = (ListView) findViewById(R.id.storage_main_lv);
    }

    protected class ViewHolder {
        public TextView firstTv;
        public TextView secondTv;
    }
}
