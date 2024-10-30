package com.mpaas.antui.viewdemo;

import android.app.Activity;
import android.os.Bundle;
import android.os.Handler;
import android.util.Log;
import android.view.View;

import com.alipay.mobile.antui.common.AUWidgetMsgFlag;
import com.alipay.mobile.antui.model.ItemCategory;
import com.alipay.mobile.antui.segement.AUSegment;
import com.mpaas.antui.R;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by fuquanpeng on 16/10/8.
 */
public class AUSegmentActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.view_switch_tab);

        final AUSegment segment = (AUSegment) findViewById(R.id.switchtab);
        segment.setCurrentSelTab(1);

        segment.setTabSwitchListener(new AUSegment.TabSwitchListener() {
            @Override
            public void onTabClick(int position, View view) {
            }
        });


        final AUSegment switchTab3 = (AUSegment) findViewById(R.id.switchtab_three);
        switchTab3.resetTabView(new String[]{"选项一", "选项一", "选项二", "徐昂想"});
        new Handler().postDelayed(new Runnable() {
            @Override
            public void run() {
                switchTab3.resetTabView(new String[]{"AA的", "选项一", "选项二", "选项一萨胡搞"});
            }
        }, 1000);

        new Handler().postDelayed(new Runnable() {
            @Override
            public void run() {
                switchTab3.resetTabView(new String[]{"选项没变么", "选项一", "选项二", "选项一萨胡搞"});
            }
        }, 3000);

        new Handler().postDelayed(new Runnable() {
            @Override
            public void run() {
                switchTab3.resetTabView(new String[]{"选项大胃王没变么", "选项一", "选项二", "选项一萨胡搞"});
                switchTab3.selectTabAndAdjustLine(0);
                switchTab3.setTabSwitchListener(new AUSegment.TabSwitchListener() {
                    @Override
                    public void onTabClick(int position, View view) {
                    }
                });

            }
        }, 5000);

        final AUSegment switchTab4 = (AUSegment) findViewById(R.id.switchtab_four);
        switchTab4.setTabSwitchListener(new AUSegment.TabSwitchListener() {
            @Override
            public void onTabClick(int position, View view) {
            }
        });

        final AUSegment switchTab5 = (AUSegment) findViewById(R.id.switchtab_five);
        switchTab5.setTabSwitchListener(new AUSegment.TabSwitchListener() {
            @Override
            public void onTabClick(int position, View view) {
            }
        });

        final AUSegment switchtabMore = (AUSegment) findViewById(R.id.switchtab_more);
        switchtabMore.setTabSwitchListener(new AUSegment.TabSwitchListener() {
            @Override
            public void onTabClick(int position, View view) {
            }
        });


        final AUSegment switchtabMore2 = (AUSegment) findViewById(R.id.switchtab_more2);
        switchtabMore2.setTabSwitchListener(new AUSegment.TabSwitchListener() {
            @Override
            public void onTabClick(int position, View view) {
            }
        });
        List<ItemCategory> list = new ArrayList<ItemCategory>();
        for (int i = 0; i < 10; i++) {
            ItemCategory itemCategory = new ItemCategory();
            itemCategory.categoryname = "选项" + i;
            if (i == 5) {
                itemCategory.categoryname = "选项" + i;
            }
            if (i == 2) {
                itemCategory.categoryname = "选项" + i;
            }
//            itemCategory.categoryId = "ceshiceshi"+i;
            list.add(itemCategory);
        }
//        switchtabMore2.setDivideAutoSize(false);
        switchtabMore2.init(list);
//        switchtabMore2.setCurrentSelTab(3);

        final AUSegment switchtabMore3 = (AUSegment) findViewById(R.id.switchtab_more3);

        List<ItemCategory> list1 = new ArrayList<ItemCategory>();
        for (int i = 0; i < 3; i++) {
            ItemCategory itemCategory = new ItemCategory();
            itemCategory.categoryname = "选项" + i;
//            itemCategory.categoryId = "ceshiceshi"+i;
            list1.add(itemCategory);
        }

        switchtabMore3.setDivideAutoSize(false);
        switchtabMore3.init(list1);


        final AUSegment switchtabMore4 = (AUSegment) findViewById(R.id.switchtab4);

        List<ItemCategory> list4 = new ArrayList<ItemCategory>();
        for (int i = 0; i < 3; i++) {
            ItemCategory itemCategory = new ItemCategory();
            itemCategory.categoryname = "选项" + i;
//            itemCategory.categoryId = "ceshiceshi"+i;
            list4.add(itemCategory);
        }

        AUWidgetMsgFlag j = new AUWidgetMsgFlag(this);
        j.showMsgFlag();
//        j.setPadding(DensityUtil.dip2px(this, 5), 0, 0, 0);
        switchtabMore4.addTextRightView(j, 0);

        switchtabMore4.setCurrentSelTab(1);

        switchtabMore4.setTabSwitchListener(new AUSegment.TabSwitchListener() {
            @Override
            public void onTabClick(int position, View view) {
            }
        });

        final AUSegment switchtabMore6 = (AUSegment) findViewById(R.id.switchtab_more6);

        List<ItemCategory> list6 = new ArrayList<ItemCategory>();
        for (int i = 0; i < 6; i++) {
            ItemCategory itemCategory = new ItemCategory();
            itemCategory.categoryname = "选项" + i;
            list6.add(itemCategory);
        }
        switchtabMore6.init(list6);
        switchtabMore6.getAddIcon().setImageResource(R.drawable.alipay_logo);
        switchtabMore6.getAddIcon().setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Log.d("AUSegmentActivity", "add");
            }
        });

        AUWidgetMsgFlag j6 = new AUWidgetMsgFlag(this);
        j6.showMsgFlag();
        switchtabMore6.addTextRightView(j6, 0);
        switchtabMore6.setCurrentSelTab(2);

        switchtabMore6.setTabSwitchListener(new AUSegment.TabSwitchListener() {
            @Override
            public void onTabClick(int position, View view) {
            }
        });

        final AUSegment switchtabMore5 = (AUSegment) findViewById(R.id.switchtab_more5);
        switchtabMore5.setTabSwitchListener(new AUSegment.TabSwitchListener() {
            @Override
            public void onTabClick(int position, View view) {
            }
        });
        List<ItemCategory> list5 = new ArrayList<ItemCategory>();
        for (int i = 0; i < 10; i++) {
            ItemCategory itemCategory = new ItemCategory();
            itemCategory.categoryname = "选项" + i;
            if (i == 5) {
                itemCategory.categoryname = "开始选中我，但我不要线" + i;
            }
            if (i == 2) {
                itemCategory.categoryname = "选项" + i;
            }
            list5.add(itemCategory);
        }
        switchtabMore5.init(list5);
        new Handler().postDelayed(new Runnable() {
            @Override
            public void run() {
                switchtabMore5.setAnchor(5);
            }
        }, 1000);

    }
}