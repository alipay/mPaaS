package com.mpaas.antui.viewdemo;

import android.app.Activity;
import android.content.Context;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;

import com.alipay.mobile.antui.utils.PublicResources;
import com.mpaas.antui.R;
import com.alipay.mobile.antui.dialog.AUCardMenu;
import com.alipay.mobile.antui.dialog.AUPopMenu;
import com.alipay.mobile.antui.iconfont.model.IconInfo;
import com.alipay.mobile.antui.iconfont.model.MessagePopItem;

import java.util.ArrayList;

/**
 * Created by gaopan.gp on 2016/10/3.
 */
public class CardMenuActivity extends Activity {


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.cardmenu);
    }

    public void toastPopMenu(View view) {
        final AUPopMenu popMenu = new AUPopMenu(CardMenuActivity.this, getItemList());
        if ("down".equals(view.getTag())) {
            popMenu.showTipView(view);
        } else {
            popMenu.showTipView(view, false);
        }
        popMenu.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {

            }
        });
    }

    public void showCardMenu(View view){
        Context context = view.getContext();
        ArrayList<MessagePopItem> menuList = new ArrayList<MessagePopItem>();
        MessagePopItem itemComplaint = new MessagePopItem();
        IconInfo iconInfo = new IconInfo();
        iconInfo.type = IconInfo.TYPE_ICONFONT;
        iconInfo.icon = context.getString(PublicResources.String_iconfont_complain);
        itemComplaint.icon = iconInfo;
        itemComplaint.title = "投诉";
        menuList.add(itemComplaint);

        MessagePopItem itemDelete = new MessagePopItem();
        iconInfo = new IconInfo();
        iconInfo.type = IconInfo.TYPE_ICONFONT;
        iconInfo.icon = context.getString(PublicResources.String_iconfont_delete);
        itemDelete.icon = iconInfo;
        itemDelete.title = "删除";
        menuList.add(itemDelete);
        final AUCardMenu cardMenu = new AUCardMenu(context);
        cardMenu.setOnClickListener(new AUCardMenu.OnMessageItemClickListener() {
            @Override
            public void onItemClick(int i) {

            }

            @Override
            public void onItemOptionsClick(int i, int i1) {
            }
        });
        cardMenu.directionShow(view, menuList, true);
    }


    private ArrayList<MessagePopItem> getItemList() {
        ArrayList<MessagePopItem> menuList = new ArrayList<MessagePopItem>();

        MessagePopItem item1 = new MessagePopItem();
        item1.title = "分享";
        menuList.add(item1);


        MessagePopItem item2 = new MessagePopItem();
        item2.title = "转发";
        menuList.add(item2);

        MessagePopItem item3 = new MessagePopItem();
        item3.title = "我是测试";
        menuList.add(item3);

        MessagePopItem item4 = new MessagePopItem();
        item4.title = "不要太长呀不要太长呀";
        menuList.add(item4);

        MessagePopItem item5 = new MessagePopItem();
        item5.title = "我的";
        menuList.add(item5);

        return menuList;
    }

//    @Override
//    public void onClick(View v) {
//        ArrayList<MessagePopItem> menuList = new ArrayList<MessagePopItem>();
//
//        MessagePopItem item1 = new MessagePopItem();
//        IconInfo info = new IconInfo();
//        info.type = IconInfo.TYPE_DRAWABLE;
//        info.drawable = getResources().getDrawable(R.drawable.menu_del_reject);
//        item1.icon = info;
//        item1.title = "tes1的文案就是这样";
//        item1.content = "发生地方代购费水电工12";
//        menuList.add(item1);
//
//
//        MessagePopItem item2 = new MessagePopItem();
//        IconInfo info2 = new IconInfo();
//        info2.type = IconInfo.TYPE_DRAWABLE;
//        info2.drawable = getResources().getDrawable(R.drawable.menu_delete);
//        item2.icon = info2;
//        item2.title = "阿斯顿发斯蒂芬";
//        item2.content = "是电饭锅12";
//        menuList.add(item2);
//
//        MessagePopItem item3 = new MessagePopItem();
//        IconInfo info3 = new IconInfo();
//        info3.type = IconInfo.TYPE_DRAWABLE;
//        info3.drawable = getResources().getDrawable(R.drawable.menu_ignore);
//        item3.icon = info3;
//        item3.title = "高速费毒黄瓜东方红";
//        menuList.add(item3);
//
//        MessagePopItem item4 = new MessagePopItem();
//        IconInfo info4 = new IconInfo();
//        info4.type = IconInfo.TYPE_DRAWABLE;
//        info4.drawable = getResources().getDrawable(R.drawable.menu_reject);
//        item4.icon = info4;
//        item4.title = "加工费胡椒粉工行卡规范";
//        menuList.add(item4);
//
//        MessagePopItem item5 = new MessagePopItem();
//        IconInfo info5 = new IconInfo();
//        info5.type = IconInfo.TYPE_DRAWABLE;
//        info5.drawable = getResources().getDrawable(R.drawable.menu_report);
//        item5.icon = info5;
//        item5.title = "考虑过黄金矿工法国红酒发";
//        ArrayList<String> buttonTitles = new ArrayList<String>();
//        buttonTitles.add("过时");
//        buttonTitles.add("看过了");
//        buttonTitles.add("质量差");
//        item5.optionBtn = buttonTitles;
//        menuList.add(item5);
//
//        final AUCardMenu popMenu = new AUCardMenu(CardMenuActivity.this);
//        int id = v.getId();
//        if (id == R.id.showCardMenu1) {
//            popMenu.showDrop(textView1, menuList);
//        } else if (id == R.id.showCardMenu2) {
//            popMenu.showDrop(textView2, menuList);
//        }
//
//    }
}
