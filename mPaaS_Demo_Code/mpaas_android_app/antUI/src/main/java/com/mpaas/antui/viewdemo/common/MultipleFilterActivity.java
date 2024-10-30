package com.mpaas.antui.viewdemo.common;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.widget.Toast;

import com.mpaas.antui.R;
import com.alipay.mobile.antui.basic.AUFilterMenuView;
import com.alipay.mobile.antui.filter.IFilterListener;
import com.alipay.mobile.antui.model.FilterCategoryData;
import com.alipay.mobile.antui.model.FilterItemData;
import com.alipay.mobile.antui.utils.AuiLogger;
import com.mpaas.antui.viewdemo.view.DemoTitleBar;

import java.util.ArrayList;
import java.util.Map;

/**
 * Created by minghui on 2017/8/29.
 */

public class MultipleFilterActivity extends Activity{
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        View v = View.inflate(this, R.layout.filter_actiivty, null);
        setContentView(v);

        DemoTitleBar titleBar = (DemoTitleBar) findViewById(R.id.title_bar);
        titleBar.setTitleText("多项选择器");

        final FilterCategoryData data = new FilterCategoryData();

        ArrayList<FilterItemData> list = new ArrayList<FilterItemData>();
        for(int i = 0; i < 3; i++){
            FilterItemData itemData = new FilterItemData();
            itemData.name = "分组"+i;
            itemData.code = itemData.name;
            itemData.key = "ceshi"+i+i;
            itemData.allowMultipleSelect = true;
            itemData.id = "ceshi"+i+i;
            itemData.subItemData =getSubDtas();
            list.add(itemData);
        }
        try {
            data.itemDatas = list;
        }catch (Exception e){
            AuiLogger.error("MultipleFilterActivity", e+"");
        }


        final AUFilterMenuView menuView =(AUFilterMenuView) findViewById(R.id.filter_menu_view);
        menuView.setConfirmVisibe(true);
        menuView.setGroupNameVisible(true);
        DemoTitleBar bar = (DemoTitleBar) findViewById(R.id.title_bar);
        bar.setTitleText("多项选择器");

        menuView.initData(new IFilterListener(){
            @Override
            public void onFilterSelected(FilterCategoryData data, Map<String, String> map, boolean b, boolean b1) {
                Toast.makeText(MultipleFilterActivity.this, map.toString(), Toast.LENGTH_SHORT).show();
            }
        }, data, null);

        findViewById(R.id.footer).setVisibility(View.GONE);
    }

    private ArrayList<FilterItemData> getSubDtas(){
        ArrayList<FilterItemData> list = new ArrayList<FilterItemData>();
        for(int i = 0; i < 6; i++){
            FilterItemData itemData = new FilterItemData();
            itemData.name = "选项"+i;
            itemData.code = itemData.name;
            itemData.allowMultipleSelect = true;
            itemData.key = "ceshi"+i+i;
            list.add(itemData);
        }
        return list;
    }
}
