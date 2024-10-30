package com.mpaas.antui.viewdemo;

import android.app.Activity;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.Toast;

import com.alipay.mobile.antui.basic.AUTitleBar;
import com.alipay.mobile.antui.dialog.AUFloatMenu;
import com.alipay.mobile.antui.iconfont.model.IconInfo;
import com.alipay.mobile.antui.iconfont.model.MessagePopItem;
import com.alipay.mobile.antui.theme.AUThemeFactory;
import com.alipay.mobile.antui.theme.AUThemeManager;
import com.alipay.mobile.antui.utils.PublicResources;
import com.mpaas.antui.R;
import com.mpaas.antui.viewdemo.theme.ChangeThemeImpl;

import java.util.ArrayList;
import java.util.HashMap;

/**
 * Created by xuanmu on 16/10/8.
 */
public class ChangeSkinActivity extends Activity {

    private AUThemeFactory factory;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        factory = new AUThemeFactory();
        getLayoutInflater().setFactory(factory);

        setContentView(R.layout.view_change_skin);
        initTitlebar((AUTitleBar) findViewById(R.id.title_bar));
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        factory.clean();
    }

    private void initTitlebar(final AUTitleBar titleBar) {

        titleBar.getRightButton().setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

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
                item3.title = "我是测试";
                externParam = new HashMap<String, Object>();
                externParam.put("badgeType", "msg_text");
                externParam.put("badgeText", "9");
                item3.externParam = externParam;
                menuList.add(item3);

                MessagePopItem item4 = new MessagePopItem();
                IconInfo info4 = new IconInfo();
                info4.icon = getResources().getString(PublicResources.String_iconfont_collect_money);
                item4.icon = info4;
                item4.title = "不要太长呀";
                menuList.add(item4);

                MessagePopItem item5 = new MessagePopItem();
                IconInfo info5 = new IconInfo();
                info5.icon = getResources().getString(PublicResources.String_iconfont_scan);
                item5.icon = info5;
                item5.title = "我的";
                menuList.add(item5);

                item5 = new MessagePopItem();
                info5 = new IconInfo();
                info5.icon = getResources().getString(PublicResources.String_iconfont_map);
                item5.icon = info5;
                item5.title = "我的";
                menuList.add(item5);

                item5 = new MessagePopItem();
                info5 = new IconInfo();
                info5.icon = getResources().getString(PublicResources.String_iconfont_qrcode);
                item5.icon = info5;
                item5.title = "我的";
                menuList.add(item5);

                item5 = new MessagePopItem();
                info5 = new IconInfo();
                info5.icon = getResources().getString(PublicResources.String_iconfont_share);
                item5.icon = info5;
                item5.title = "我的";
                menuList.add(item5);

                item5 = new MessagePopItem();
                info5 = new IconInfo();
                info5.icon = getResources().getString(PublicResources.String_iconfont_complain);
                item5.icon = info5;
                item5.title = "我的";
                menuList.add(item5);

                item5 = new MessagePopItem();
                info5 = new IconInfo();
                info5.icon = getResources().getString(PublicResources.String_iconfont_comment);
                item5.icon = info5;
                item5.title = "我的";
                menuList.add(item5);

                final AUFloatMenu floatMenu = new AUFloatMenu(ChangeSkinActivity.this);
                floatMenu.showDrop(v, menuList);
                floatMenu.setOnClickListener(new AdapterView.OnItemClickListener() {
                    @Override
                    public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                        Toast.makeText(ChangeSkinActivity.this, String.valueOf(position), Toast.LENGTH_SHORT).show();
                        floatMenu.hideDrop();
                    }
                });
            }
        });
    }

    public void onClickDefault(View view) {
        AUThemeManager.setCurrentThemeKey(AUThemeManager.THEMEKEY_DEFAULT);
        SharedPreferences sharedPreferences = getSharedPreferences("com.alipay.mobile.antui", MODE_MULTI_PROCESS);
        SharedPreferences.Editor editor = sharedPreferences.edit();
        editor.putString("CurrentThemeKey", AUThemeManager.THEMEKEY_DEFAULT);
        editor.commit();
        restartApp();
    }

    private void restartApp() {
        Intent intent = new Intent();
        intent.setFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP);
        startActivity(intent);
    }

    public void onClickSecond(View view) {
        factory.applySkin(this, ChangeThemeImpl.getInstance());
        SharedPreferences sharedPreferences = getSharedPreferences("com.alipay.mobile.antui", MODE_MULTI_PROCESS);
        SharedPreferences.Editor editor = sharedPreferences.edit();
        editor.putString("CurrentThemeKey", "changeSkin");
        editor.commit();
    }


    public void onClickAll(View view) {
        AUThemeManager.putTheme("changeSkin", ChangeThemeImpl.getInstance());
    }
}
