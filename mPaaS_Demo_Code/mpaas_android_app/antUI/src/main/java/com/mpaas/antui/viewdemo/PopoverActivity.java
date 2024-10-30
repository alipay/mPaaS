package com.mpaas.antui.viewdemo;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.Toast;

import com.alipay.mobile.antui.utils.PublicResources;
import com.mpaas.antui.R;
import com.alipay.mobile.antui.basic.AUTitleBar;
import com.alipay.mobile.antui.dialog.AUFloatMenu;
import com.alipay.mobile.antui.iconfont.model.IconInfo;
import com.alipay.mobile.antui.iconfont.model.MessagePopItem;

import java.util.ArrayList;
import java.util.HashMap;

/**
 * Created by xuanmu on 17/8/22.
 */

public class PopoverActivity extends Activity {
    private AUTitleBar popTitle;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_pop_over);
        popTitle = (AUTitleBar) findViewById(R.id.pop_title_bar);

    }

    public void withIconBadge(View view){
        ArrayList<MessagePopItem> menuList = new ArrayList<MessagePopItem>();

        MessagePopItem item1 = new MessagePopItem();
        IconInfo info = new IconInfo();
        info.icon = getResources().getString(PublicResources.String_iconfont_group_chat);
        item1.icon = info;
        item1.title = "分享";
        HashMap<String, Object> externParam = new HashMap<String, Object>();
        externParam.put("badgeType", "msg_redpoint");
        item1.externParam = externParam;
        menuList.add(item1);


        MessagePopItem item2 = new MessagePopItem();
        IconInfo info2 = new IconInfo();
        info2.icon = getResources().getString(PublicResources.String_iconfont_delete);
        item2.icon = info2;
        item2.title = "转发";
        externParam = new HashMap<String, Object>();
        externParam.put("badgeType", "msg_text");
        externParam.put("badgeText", "25");
        item2.externParam = externParam;
        menuList.add(item2);

        MessagePopItem item3 = new MessagePopItem();
        IconInfo info3 = new IconInfo();
        info3.icon = getResources().getString(PublicResources.String_iconfont_add_user);
        item3.icon = info3;
        item3.title = "添加朋友";
        HashMap<String, Object> externParam3 = new HashMap<String, Object>();
        item3.externParam = externParam3;
        item3.externParam.put("badgeType","text");
        item3.externParam.put("badgeText","新功能");
        menuList.add(item3);

        MessagePopItem item4 = new MessagePopItem();
        IconInfo info4 = new IconInfo();
        info4.icon = getResources().getString(PublicResources.String_iconfont_collect_money);
        item4.icon = info4;
        item4.title = "收付款";
        menuList.add(item4);

        MessagePopItem item5 = new MessagePopItem();
        IconInfo info5 = new IconInfo();
        info5.icon = getResources().getString(PublicResources.String_iconfont_help);
        item5.icon = info5;
        item5.title = "使用帮助";
        menuList.add(item5);

        final AUFloatMenu floatMenu = new AUFloatMenu(PopoverActivity.this);
        floatMenu.showDrop(popTitle.getRightButtonIconView(), menuList);
        floatMenu.setOnClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                Toast.makeText(PopoverActivity.this, String.valueOf(position), Toast.LENGTH_SHORT).show();
                floatMenu.hideDrop();
            }
        });
    }


    public void withIcon(View view){
        ArrayList<MessagePopItem> menuList = new ArrayList<MessagePopItem>();

        MessagePopItem item1 = new MessagePopItem();
        IconInfo info = new IconInfo();
        info.icon = getResources().getString(PublicResources.String_iconfont_group_chat);
        item1.icon = info;
        item1.title = "分享";
        menuList.add(item1);


        MessagePopItem item2 = new MessagePopItem();
        IconInfo info2 = new IconInfo();
        info2.icon = getResources().getString(PublicResources.String_iconfont_delete);
        item2.icon = info2;
        item2.title = "转发";
        menuList.add(item2);

        MessagePopItem item3 = new MessagePopItem();
        IconInfo info3 = new IconInfo();
        info3.icon = getResources().getString(PublicResources.String_iconfont_add_user);
        item3.icon = info3;
        item3.title = "添加朋友";
        menuList.add(item3);

        MessagePopItem item4 = new MessagePopItem();
        IconInfo info4 = new IconInfo();
        info4.icon = getResources().getString(PublicResources.String_iconfont_collect_money);
        item4.icon = info4;
        item4.title = "收付款";
        menuList.add(item4);

        MessagePopItem item5 = new MessagePopItem();
        IconInfo info5 = new IconInfo();
        info5.icon = getResources().getString(PublicResources.String_iconfont_help);
        item5.icon = info5;
        item5.title = "使用帮助";
        menuList.add(item5);

        final AUFloatMenu floatMenu = new AUFloatMenu(PopoverActivity.this);
        floatMenu.showDrop(popTitle.getRightButtonIconView(), menuList);
        floatMenu.setOnClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                Toast.makeText(PopoverActivity.this, String.valueOf(position), Toast.LENGTH_SHORT).show();
                floatMenu.hideDrop();
            }
        });
    }


    public void withText(View view){
        ArrayList<MessagePopItem> menuList = new ArrayList<MessagePopItem>();

        MessagePopItem item1 = new MessagePopItem();
        item1.title = "分享";
        menuList.add(item1);


        MessagePopItem item2 = new MessagePopItem();
        item2.title = "转发";
        menuList.add(item2);

        MessagePopItem item3 = new MessagePopItem();
        item3.title = "添加朋友";
        menuList.add(item3);

        MessagePopItem item4 = new MessagePopItem();
        item4.title = "收付款";
        menuList.add(item4);

        MessagePopItem item5 = new MessagePopItem();
        item5.title = "使用帮助";
        menuList.add(item5);

        final AUFloatMenu floatMenu = new AUFloatMenu(PopoverActivity.this);
        floatMenu.showDrop(popTitle.getRightButtonIconView(), menuList);
        floatMenu.setOnClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                Toast.makeText(PopoverActivity.this, String.valueOf(position), Toast.LENGTH_SHORT).show();
                floatMenu.hideDrop();
            }
        });
    }

    public void bottomPop(View view){
        Intent intent = new Intent();
        intent.setClassName(this, CardMenuActivity.class.getName());
        startActivity(intent);
    }
}
