package com.mpaas.cdpdemo;

import android.os.Bundle;
import android.util.TypedValue;
import android.view.Gravity;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.ListView;
import android.widget.Toast;

import com.alipay.mobile.antui.basic.AUTextView;
import com.alipay.mobile.framework.app.ui.BaseActivity;

public class DynamicActivity extends BaseActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_dynamic);
        Toast.makeText(this, getClass().getName(), Toast.LENGTH_LONG).show();
    }

    protected void enableListModel() {
        findViewById(R.id.dynamic_content_rl).setVisibility(View.GONE);
        ListView listView = (ListView) findViewById(R.id.dynamic_content_lv);
        listView.setVisibility(View.VISIBLE);
        listView.setAdapter(new ListAdapter());
    }

    private class ListAdapter extends BaseAdapter {
        @Override
        public int getCount() {
            return 30;
        }

        @Override
        public Object getItem(int i) {
            return null;
        }

        @Override
        public long getItemId(int i) {
            return i;
        }

        @Override
        public View getView(int i, View view, ViewGroup viewGroup) {
            if (view == null) {
                view = new AUTextView(DynamicActivity.this);
            }
            AUTextView tv = (AUTextView) view;
            tv.setText(getString(R.string.content_text) + " " + i);
            tv.setGravity(Gravity.CENTER);
            tv.setTextColor(0xff000000);
            tv.setTextSize(TypedValue.COMPLEX_UNIT_SP, 20);
            return view;
        }
    }
}
