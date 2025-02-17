package com.mpaas.antui.viewdemo.common;

import android.app.Activity;
import android.os.Bundle;
import android.os.Handler;
import android.util.Log;
import android.view.View;

import com.alipay.mobile.antui.badge.AUBadgeView;
import com.alipay.mobile.antui.tablelist.AUDoubleTitleListItem;
import com.alipay.mobile.antui.tablelist.AUSingleTitleListItem;
import com.alipay.mobile.antui.tablelist.AUSwitchListItem;
import com.mpaas.antui.R;

/**
 * Created by minghui on 2017/8/22.
 */

public class BadgeActivity extends Activity {

    private AUSingleTitleListItem titleListItem;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        View v = View.inflate(this, R.layout.badge_activity, null);
        setContentView(v);

        AUBadgeView b = (AUBadgeView) findViewById(R.id.badge_view);
        b.setMsgText("ne");
        ((AUBadgeView) findViewById(R.id.badge_view1)).setMsgText("new");

        ((AUBadgeView) findViewById(R.id.badge_view2)).setMsgText("三个字");
        ((AUBadgeView) findViewById(R.id.badge_view3)).setMsgText("四个文字");

        /** AUBadgeView start **/

        titleListItem = (AUSingleTitleListItem) findViewById(R.id.single_item);
        AUBadgeView badgeView1 = new AUBadgeView(this);
        badgeView1.setMsgCount(10);
        titleListItem.attachFlagToArrow(badgeView1);

        AUSwitchListItem switchListItem = (AUSwitchListItem) findViewById(R.id.switch_item);
        final AUBadgeView badgeView = new AUBadgeView(this);
        badgeView.setRedPoint(true);
        switchListItem.attachFlagToArrow(badgeView);


        AUDoubleTitleListItem titleListItem2 = (AUDoubleTitleListItem) findViewById(R.id.single_item2);
        AUBadgeView badgeView2 = new AUBadgeView(this);
        badgeView2.setMsgText("new");
        titleListItem2.attachFlagToArrow(badgeView2);

        AUSingleTitleListItem titleListItem3 = (AUSingleTitleListItem) findViewById(R.id.single_item3);
        final AUBadgeView badgeView3 = new AUBadgeView(this);
        badgeView3.setSmallTextSize(true);
        badgeView3.setOnContentChangedListener(new AUBadgeView.OnContentChangedListener() {
            @Override
            public void onChange(AUBadgeView.Style newStyle, String newContent) {
                Log.d("TAG", "onChange: " + newStyle + " / " + newContent);
            }
        });
        badgeView3.setStyleAndContent(AUBadgeView.Style.TEXT, null);
        badgeView3.setStyleAndContent(AUBadgeView.Style.TEXT, "adhfh");
//        badgeView3.setRedPoint(true);
        titleListItem3.attachFlagToArrow(badgeView3);

        new Handler().postDelayed(new Runnable() {
            @Override
            public void run() {
                badgeView3.setStyleAndContent(AUBadgeView.Style.NUM, "20");
            }
        }, 2000);


        AUSingleTitleListItem titleListItem4 = (AUSingleTitleListItem) findViewById(R.id.single_item4);
        AUBadgeView badgeView4 = new AUBadgeView(this);
        badgeView4.setStyleAndMsgText(AUBadgeView.Style.TEXT, "很多很多很多");
        titleListItem4.attachFlagToArrow(badgeView4);

        /** AUBadgeView end **/


        //        titleListItem2 = (AUDoubleTitleListItem) findViewById(R.id.single_item2);
//        titleListItem3 = (AUSingleTitleListItem) findViewById(R.id.single_item3);
//        titleListItem4 = (AUSingleTitleListItem) findViewById(R.id.single_item4);
//        titleListItem5 = (AUSingleTitleListItem) findViewById(R.id.single_item5);

    }
}
