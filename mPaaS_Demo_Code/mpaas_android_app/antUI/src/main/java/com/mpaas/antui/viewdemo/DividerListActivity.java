package com.mpaas.antui.viewdemo;

import android.app.Activity;
import android.content.Context;
import android.os.Bundle;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;

import com.alipay.mobile.antui.api.AULineGroupItemInterface;
import com.alipay.mobile.antui.basic.AUDividerListView;
import com.alipay.mobile.antui.tablelist.AUSingleTitleListItem;
import com.mpaas.antui.R;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by xuanmu on 17/2/16.
 */
public class DividerListActivity extends Activity {

    private List<String> divider_list;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.view_divider_list);

        AUDividerListView dividerListView = (AUDividerListView)findViewById(R.id.divider_list);
        divider_list = getData();
        DividerAdapter adapter = new DividerAdapter(this);
        dividerListView.setAdapter(adapter);
        adapter.notifyDataSetChanged();
    }

    private List<String> getData(){

        List<String> data = new ArrayList<String>();
        data.add("测试数据测试数据测试数据");
        data.add("测试数据测试数据测试数据");
        data.add("测试数据测试数据测试数据");
        data.add("测试数据测试数据测试数据");
        data.add("测试数据测试数据测试数据");
        data.add("测试数据测试数据测试数据");
        data.add("测试数据测试数据测试数据");
        data.add("测试数据测试数据测试数据");
        data.add("测试数据测试数据测试数据");
        data.add("测试数据测试数据测试数据");
        data.add("测试数据");
        data.add("测试数据测试数据测试数据");
        data.add("测试数据测试数据测试数据");
        data.add("测试数据测试数据测试数据");
        data.add("测试数据测试数");
        data.add("测试数据测试数据测试数据");
        data.add("测试数据测试数据测试数据");
        data.add("测试数据测试数据测试数据");
        data.add("测试数据测试数据测试数据");
        data.add("测试数据测试数据测试数据");
        data.add("测试数据测试");
        data.add("测试数据测试数据测试数据");
        data.add("测试数据测试数据测试数据");
        data.add("测试数据测试数据测试数据");
        data.add("测试数据测试数据测试数据");
        data.add("测试数据测试");
        data.add("测试数据测试数据测试数据");
        data.add("测试数据测试数据");


        return data;
    }


    public class DividerAdapter extends BaseAdapter{

        private Context context;

        public DividerAdapter(Context context) {
            super();
            this.context = context;
        }

        @Override
        public int getCount() {
            return divider_list.size();
        }

        @Override
        public String getItem(int position) {
            return  divider_list.get(position);
        }

        @Override
        public long getItemId(int position) {
            return 0;
        }

        @Override
        public View getView(int position, View convertView, ViewGroup parent) {
            if (convertView == null){
                convertView = new AUSingleTitleListItem(context);
                ((AUSingleTitleListItem)convertView).setItemPositionStyle(AULineGroupItemInterface.NONE);
                ViewGroup.LayoutParams layoutParams = new ViewGroup.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT,144);
                convertView.setLayoutParams(layoutParams);
            }
            ((AUSingleTitleListItem)convertView).setLeftText(getItem(position));
            ((AUSingleTitleListItem)convertView).setRightButtonText("测试");
            ((AUSingleTitleListItem)convertView).getProcessButton().setEnabled(false);
            return convertView;
        }
    }
}
