package com.mpaas.antui.viewdemo;

import android.app.Activity;
import android.content.Context;
import android.graphics.Color;
import android.os.Bundle;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.LinearLayout;

import com.mpaas.antui.R;
import com.alipay.mobile.antui.api.AULineGroupItemInterface;
import com.alipay.mobile.antui.load.AUEmptyPageLoadingView;
import com.alipay.mobile.antui.load.AURefreshListView;
import com.alipay.mobile.antui.load.AntLoadingView;
import com.alipay.mobile.antui.load.OnLoadMoreListener;
import com.alipay.mobile.antui.tablelist.AUSingleTitleListItem;

import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;


/**
 * Created by skylineTan on 17/7/10.
 */

public class RefreshActivity extends Activity {

    public static final String STYLE_1 = "STYLE_1";
    public static final String STYLE_2 = "STYLE_2";
    public static final String STYLE_3 = "STYLE_3";

    private List<String> divider_list;
    private AURefreshListView listView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        LinearLayout v = (LinearLayout) View.inflate(this, R.layout.refresh_layout, null);
        setContentView(v);


        String type = getIntent().getType();

        if (STYLE_1.equals(type)){
            listView = new AURefreshListView(this);
            v.addView(listView);
        } else if (STYLE_2.equals(type)){
            listView = new AURefreshListView(this);
            listView.setLoadingView(Color.parseColor("#1B82D2"), AntLoadingView.STYLE_WHITE);
            v.addView(listView);
        } else if (STYLE_3.equals(type)){
            /** AUEmptyPageLoadingView start **/
            AUEmptyPageLoadingView view = new AUEmptyPageLoadingView(this);
            view.getLottieLayout().loop(true);
            view.getLottieLayout().playAnimation();
            v.addView(view, new ViewGroup.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.MATCH_PARENT));
            /** AUEmptyPageLoadingView end **/
            return;
        }

        divider_list = getData();
        final DividerAdapter adapter = new DividerAdapter(this);

        listView.setAdapter(adapter);
        Date date = new Date(1466577757265L);
        SimpleDateFormat formatter = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
        String dateString = formatter.format(date);
        listView.setLoadingText(dateString);
        listView.setLoadMore(true);


        listView.setOnLoadMoreListener(new OnLoadMoreListener() {
            @Override
            public void onLoadMore() {
                listView.postDelayed(new Runnable() {
                    @Override
                    public void run() {
                        for (int i = 0; i < 3; i++) {
                            divider_list.add("下接加载更多List");
                        }
                        adapter.notifyDataSetChanged();
                        if(divider_list.size() > 30) {
                            listView.updateLoadMore(true, false);
                        } else {
                            listView.updateLoadMore(true, true);
                        }
                    }
                }, 3000);
            }

            @Override
            public void onLoadingFinished() {

            }
        });
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


        return data;
    }


    public class DividerAdapter extends BaseAdapter {

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
            convertView.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View v) {
                    listView.finishRefresh();
                }
            });
            convertView.setOnLongClickListener(new View.OnLongClickListener() {
                @Override
                public boolean onLongClick(View v) {
                    listView.startRefresh();
                    return true;
                }
            });
            return convertView;
        }
    }
}
