package com.mpaas.antui.viewdemo;

import android.app.Activity;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.widget.ListView;
import android.widget.SimpleAdapter;

import com.alipay.mobile.antui.utils.PublicResources;
import com.mpaas.antui.R;
import com.alipay.mobile.antui.basic.AUButton;
import com.alipay.mobile.antui.basic.AUPullLoadingView;
import com.alipay.mobile.antui.basic.AUPullRefreshView;

import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * Created by gaopan.gp on 2016/10/10.
 */
public class PullRefreshActivity extends Activity {
    AUPullRefreshView pullRefreshView;
    AUPullRefreshView pullRefreshView2;
    AUButton mSwichButton;
    AUPullLoadingView mAUPullLoadingView;
    AUPullLoadingView mAUPullLoadingView2;
    private boolean showText = true;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.pullrefreshview);
        ListView listView = (ListView) findViewById(R.id.list);
        ListView listView2 = (ListView) findViewById(R.id.list2);
        mSwichButton = (AUButton) findViewById(R.id.swichButton);
        mSwichButton.setText("切换不显示文字");
        mSwichButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (showText) {
                    mSwichButton.setText("切换显示文字");
                    showText = false;
                    pullRefreshView.setVisibility(View.GONE);
                    pullRefreshView2.setVisibility(View.VISIBLE);
                } else {
                    mSwichButton.setText("切换不显示文字");
                    showText = true;
                    pullRefreshView.setVisibility(View.VISIBLE);
                    pullRefreshView2.setVisibility(View.GONE);
                }
            }
        });
        pullRefreshView = (AUPullRefreshView) findViewById(R.id.pull_refresh_view);
        pullRefreshView.setEnablePull(true);
        pullRefreshView.setRefreshListener(new AUPullRefreshView.RefreshListener() {

            @Override
            public void onRefresh() {

                pullRefreshView.autoRefresh();

                pullRefreshView.postDelayed(new Runnable() {

                    @Override
                    public void run() {
                        pullRefreshView.refreshFinished();

                    }
                }, 5000);

            }

            @Override
            public AUPullLoadingView getOverView() {

                mAUPullLoadingView = (AUPullLoadingView) LayoutInflater.from(getBaseContext())
                        .inflate(PublicResources.Layout_PullRefresh_Overview, null);
                Date date = new Date(1466577757265L);
                SimpleDateFormat formatter = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
                String dateString = formatter.format(date);
                mAUPullLoadingView.setIndicatorText(dateString);
                mAUPullLoadingView.setLoadingText(dateString);
                return mAUPullLoadingView;
            }

            @Override
            public boolean canRefresh() {
                return true;
            }
        });

        pullRefreshView.setLoadingHeightChangeListener(new AUPullRefreshView.LoadingHeightChangeListener() {
            @Override
            public void onChangeHeight(int height, boolean isRefreshing) {
                if (height <= 0 && !isRefreshing) {
                    mSwichButton.setVisibility(View.VISIBLE);
                } else if (mSwichButton.getVisibility() == View.VISIBLE) {
                    mSwichButton.setVisibility(View.GONE);
                }
            }
        });


        pullRefreshView2 = (AUPullRefreshView) findViewById(R.id.pull_refresh_view2);
        pullRefreshView2.setEnablePull(true);
        pullRefreshView2.setRefreshListener(new AUPullRefreshView.RefreshListener() {

            @Override
            public void onRefresh() {

                pullRefreshView2.autoRefresh();

                pullRefreshView2.postDelayed(new Runnable() {

                    @Override
                    public void run() {
                        pullRefreshView2.refreshFinished();

                    }
                }, 5000);

            }

            @Override
            public AUPullLoadingView getOverView() {

                mAUPullLoadingView2 = (AUPullLoadingView) LayoutInflater.from(getBaseContext())
                        .inflate(PublicResources.Layout_PullRefresh_Overview, null);
                return mAUPullLoadingView2;
            }

            @Override
            public boolean canRefresh() {
                return true;
            }
        });

        List<Map<String, Object>> contents = new ArrayList<Map<String, Object>>();

        for (int i = 0; i < 10; i++) {
            Map<String, Object> map = new HashMap<String, Object>();
            map.put("PIC", "下接刷新List");
            map.put("TITLE", "下拉开始刷新");
            contents.add(map);
        }
        SimpleAdapter adapter = new SimpleAdapter(this,
                (List<Map<String, Object>>) contents,
                android.R.layout.simple_list_item_2, new String[]{"PIC",
                "TITLE"}, new int[]{android.R.id.text1,
                android.R.id.text2});

        listView.setAdapter(adapter);
        listView2.setAdapter(adapter);
    }
}
