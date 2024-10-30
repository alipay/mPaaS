package com.mpaas.antui.viewdemo;

import android.app.Activity;
import android.graphics.Color;
import android.os.Bundle;
import android.util.TypedValue;
import android.view.Gravity;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Toast;

import com.mpaas.antui.R;
import com.alipay.mobile.antui.basic.AUImageView;
import com.alipay.mobile.antui.basic.AUTextView;
import com.alipay.mobile.antui.basic.AUTitleBar;
import com.alipay.mobile.antui.common.AUWidgetMsgFlag;
import com.alipay.mobile.antui.segement.AUSegment;
import com.alipay.mobile.antui.utils.PublicResources;

/**
 * Created by xuanmu on 16/9/26.
 */
public class TitleBarActivity extends Activity {

    public static final String TITLE_STYLE_1 = "1";
    public static final String TITLE_STYLE_2 = "2";
    public static final String TITLE_STYLE_3 = "3";
    public static final String TITLE_STYLE_4 = "4";
    public static final String TITLE_STYLE_5 = "5";
    public static final String TITLE_STYLE_6 = "6";
    public static final String TITLE_STYLE_7 = "7";

    private AUTitleBar titleBar;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        View v = View.inflate(this, R.layout.view_titlebar, null);
        setContentView(v);

        /** AUTitleBar start **/

        titleBar = (AUTitleBar) findViewById(R.id.title_bar);

        String type = getIntent().getType();
        if (TITLE_STYLE_2.equals(type)){
            // 展示副标题
            titleBar.setTitleText("标题导航");
            AUTextView textView = new AUTextView(this);
            textView.setTextSize(TypedValue.COMPLEX_UNIT_DIP, 12);
            textView.setTextColor(Color.BLACK);
            textView.setText("副标题");
            titleBar.addSubTitleView(textView);
        } else if (TITLE_STYLE_3.equals(type)){
            // 展示分段标题栏
            String[] tabs = new String[]{"Tab1标题","Tab2标题"};
            titleBar.setSegment(tabs, new AUSegment.TabSwitchListener() {
                @Override
                public void onTabClick(int position, View view) {
                    Toast.makeText(TitleBarActivity.this, String.valueOf(position), Toast.LENGTH_LONG).show();
                }
            });
        } else if (TITLE_STYLE_4.equals(type)){
            // 展示进度菊花
            titleBar.startProgressBar();
        } else if (TITLE_STYLE_5.equals(type)){
            // 展示两个按钮
            titleBar.setRightButtonIcon(getResources().getString(PublicResources.String_iconfont_bill));
            titleBar.setLeftButtonIcon(getResources().getString(PublicResources.String_iconfont_add_user));
            AUWidgetMsgFlag i = new AUWidgetMsgFlag(this);
            i.showMsgFlag(99);
            titleBar.attachFlagToLeftBtn(i);
        } else if (TITLE_STYLE_6.equals(type)){
            // 展示三个按钮
            titleBar.setRightButtonIcon(getResources().getString(PublicResources.String_iconfont_bill));
            titleBar.setLeftButtonIcon(getResources().getString(PublicResources.String_iconfont_add_user));
            AUWidgetMsgFlag i = new AUWidgetMsgFlag(this);
            i.showMsgFlag(99);
            titleBar.attachFlagToLeftBtn(i);

            AUTextView textView = new AUTextView(this);
            textView.setText("第三个");
            textView.setGravity(Gravity.CENTER);

            titleBar.addButtonViewToRight(textView);
        } else if (TITLE_STYLE_7.equals(type)){
            // 修改中间扩展区域
            titleBar.setRightButtonIcon(getResources().getString(PublicResources.String_iconfont_bill));
            titleBar.setLeftButtonIcon(getResources().getString(PublicResources.String_iconfont_add_user));

            AUImageView imageView = new AUImageView(this);
            imageView.setBackgroundColor(Color.BLUE);
            ViewGroup.LayoutParams layoutParams = new ViewGroup.LayoutParams(200, getResources().getDimensionPixelOffset(PublicResources.TitleBar_Prefer_TitleView_Height));
            imageView.setLayoutParams(layoutParams);
            titleBar.setTitleView(imageView);

            titleBar.getRightButton().setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View v) {
                    titleBar.setTitleView(null);
                }
            });



            titleBar.getLeftButton().setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View v) {
                    AUImageView imageView = new AUImageView(TitleBarActivity.this);
                    imageView.setBackgroundColor(Color.BLUE);
                    ViewGroup.LayoutParams layoutParams = new ViewGroup.LayoutParams(1080, 100);
                    imageView.setLayoutParams(layoutParams);
                    titleBar.setTitleView(imageView);
                }
            });
        }

        /** AUTitleBar end **/



//        final AUWidgetMsgFlag i = new AUWidgetMsgFlag(this);
//        i.showMsgFlag(99);
//        processBar.attachFlagToRightBtn(i);
//
//        processBar.getRightButton().setOnClickListener(new View.OnClickListener() {
//            @Override
//            public void onClick(View v) {
//                processBar.getRightButton().removeView(i);
//            }
//        });
//        processBar.setRightButtonEnabled(false);
//
//        AUTitleBar titleBar = (AUTitleBar) findViewById(R.id.title_search);
//        titleBar.setTitle2Search("测试");
//
//        AUTitleBar dynamic = (AUTitleBar) findViewById(R.id.dynamic_title);
//        dynamic.toIOSStyle("标题居中");
//        dynamic.setLeftButtonText("完成");
//        dynamic.setRightButtonIcon(getString(PublicResources.String_iconfont_add_user));
//
//
//        AUTitleBar segmentTitle = (AUTitleBar) findViewById(R.id.segment_title);
    }
}
