package com.mpaas.antui.viewdemo;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;

import com.alipay.mobile.antui.badge.AUBadgeView;
import com.alipay.mobile.antui.basic.AUToast;
import com.alipay.mobile.antui.dialog.AUActionSheet;
import com.alipay.mobile.antui.iconfont.model.IconInfo;
import com.alipay.mobile.antui.iconfont.model.MessagePopItem;
import com.alipay.mobile.antui.utils.PublicResources;
import com.mpaas.antui.R;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

/**
 * Created by xuanmu on 18/4/8.
 */

public class ActionSheetActivity extends Activity implements AdapterView.OnItemClickListener {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_action_sheet);
    }

    public void clickAUActionSheet(View view) {

        /** AUActionSheet start **/
        AUActionSheet dialog = new AUActionSheet(this, "这是标题", "这是提供一行或二行注释, 通过信息澄清的方式避免产生用户疑问。", getMessagePopList(), this, AUActionSheet.NEGATIVE_STYLE_DEFAULT);
        dialog.show();
        /** AUActionSheet end **/

    }

    /**
     * AUActionSheet start
     **/
    private List<MessagePopItem> getMessagePopList() {
        List<MessagePopItem> menuList = new ArrayList<MessagePopItem>();

        MessagePopItem item1 = new MessagePopItem();
        item1.title = "文案强调";
        item1.externParam = new HashMap<String, Object>();
        item1.externParam.put(AUActionSheet.TEXT_WARNING_TYPE, true);
        menuList.add(item1);


        MessagePopItem item2 = new MessagePopItem();
        item2.icon = new IconInfo(getResources().getString(PublicResources.String_iconfont_delete));
        item2.title = "左图iconfont+红点";
        item2.externParam = new HashMap<String, Object>();
        item2.externParam.put(AUBadgeView.KEY_BADGE_STYLE, AUBadgeView.Style.NUM);
        item2.externParam.put(AUBadgeView.KEY_BADGE_CONTENT, "25");
        menuList.add(item2);

        MessagePopItem item3 = new MessagePopItem();
        item3.icon = new IconInfo(getResources().getString(PublicResources.String_iconfont_add_user));
        item3.title = "左图iconfont+红点文案";
        item3.externParam = new HashMap<String, Object>();
        item3.externParam.put(AUBadgeView.KEY_BADGE_STYLE, AUBadgeView.Style.TEXT);
        item3.externParam.put(AUBadgeView.KEY_BADGE_CONTENT, "新功能");
        menuList.add(item3);


        MessagePopItem item5 = new MessagePopItem();
        item5.icon = new IconInfo(getResources().getDrawable(R.drawable.image));
        item5.title = "左图drawable";
        menuList.add(item5);

        return menuList;
    }

    /**
     * AUActionSheet end
     **/


    @Override
    public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
        AUToast.showSuperToast(this, 0, "onItemClick position:" + position);
    }
}
