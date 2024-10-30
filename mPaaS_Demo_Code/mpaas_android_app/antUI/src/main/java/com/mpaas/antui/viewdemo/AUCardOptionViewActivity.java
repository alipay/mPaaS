package com.mpaas.antui.viewdemo;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;

import com.alipay.mobile.antui.basic.AUCardOptionView;
import com.mpaas.antui.R;

import java.util.ArrayList;

/**
 * Created by gaopan.gp on 2016/10/3.
 */
public class AUCardOptionViewActivity extends Activity {
    AUCardOptionView mAUCardOptionView;
    AUCardOptionView mAUCardOptionView2;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.view_card_option);
        mAUCardOptionView = (AUCardOptionView) findViewById(R.id.card_option_view);
        mAUCardOptionView2 = (AUCardOptionView) findViewById(R.id.card_option_view2);

        AUCardOptionView.CardOptionItem optionItem1 = new AUCardOptionView.CardOptionItem();
        optionItem1.type = AUCardOptionView.TYPE_PRAISE;
        optionItem1.hasClicked = false;


        AUCardOptionView.CardOptionItem optionItem2 = new AUCardOptionView.CardOptionItem();
        optionItem2.type = AUCardOptionView.TYPE_REWARD;
        optionItem2.hasClicked = false;


        AUCardOptionView.CardOptionItem optionItem3 = new AUCardOptionView.CardOptionItem();
        optionItem3.type = AUCardOptionView.TYPE_COMMENT;
        optionItem3.hasClicked = false;


        ArrayList<AUCardOptionView.CardOptionItem> optionItems = new ArrayList<AUCardOptionView.CardOptionItem>();
        optionItems.add(optionItem1);
        optionItems.add(optionItem2);
        optionItems.add(optionItem3);
        mAUCardOptionView.setViewInfo(optionItems,AUCardOptionView.TEXT_NOT_CHANGE);
        mAUCardOptionView.setCardOptionListner(new AUCardOptionView.CardOptionClickListner() {
            @Override
            public void onCardOptionClick(View v, AUCardOptionView.CardOptionItem optionItem, int position) {
                mAUCardOptionView.unitIncrease(v);
            }
        });

        ArrayList<AUCardOptionView.CardOptionItem> optionItems2 = new ArrayList<AUCardOptionView.CardOptionItem>();
        optionItems2.add(optionItem1);
        optionItems2.add(optionItem3);
        mAUCardOptionView2.setViewInfo(optionItems2,AUCardOptionView.TEXT_NOT_CHANGE);
        mAUCardOptionView2.setCardOptionListner(new AUCardOptionView.CardOptionClickListner() {
            @Override
            public void onCardOptionClick(View v, AUCardOptionView.CardOptionItem optionItem, int position) {
                mAUCardOptionView2.unitIncrease(v);
            }
        });

    }
}
