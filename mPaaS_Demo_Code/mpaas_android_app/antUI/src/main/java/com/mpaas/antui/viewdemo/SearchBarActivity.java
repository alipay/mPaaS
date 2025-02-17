package com.mpaas.antui.viewdemo;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.view.ViewGroup;
import android.widget.LinearLayout;

import com.mpaas.antui.R;
import com.alipay.mobile.antui.basic.AUSearchBar;
import com.alipay.mobile.antui.basic.AUSearchInputBox;
import com.alipay.mobile.antui.common.AUWidgetMsgFlag;

import static android.view.View.IMPORTANT_FOR_ACCESSIBILITY_NO_HIDE_DESCENDANTS;

/**
 * Created by xuanmu on 16/9/29.
 */
public class SearchBarActivity extends Activity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        View v = View.inflate(this, R.layout.view_search_bar, null);
        setContentView(v);

        AUSearchInputBox inputBox = new AUSearchInputBox(this);
        ViewGroup.LayoutParams layoutParams = new ViewGroup.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT,300);
        inputBox.setLayoutParams(layoutParams);
        inputBox.getSearchEditView().setHint("暗文本提示");
        inputBox.getSearchEditView().setImportantForAccessibility(IMPORTANT_FOR_ACCESSIBILITY_NO_HIDE_DESCENDANTS);
        inputBox.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
            }
        });
        inputBox.setContentDescription(inputBox.getSearchEditView().getHint());

        LinearLayout layout = (LinearLayout)findViewById(R.id.linearLayout);
        layout.addView(inputBox);

        AUSearchBar searchBar = (AUSearchBar)findViewById(R.id.complete);
        searchBar.getSearchButton().setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

            }
        });
        AUWidgetMsgFlag j = new AUWidgetMsgFlag(this);
        j.showMsgFlag(99);
        searchBar.attachFlag2SearchBtn(j);
    }
}
