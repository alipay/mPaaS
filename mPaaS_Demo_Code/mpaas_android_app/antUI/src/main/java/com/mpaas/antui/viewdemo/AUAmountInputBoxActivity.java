package com.mpaas.antui.viewdemo;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.widget.ScrollView;

import com.alipay.mobile.antui.amount.AUAmountInputBox;
import com.alipay.mobile.antui.keyboard.AUNumberKeyboardView;
import com.mpaas.antui.R;


/**
 * Created by xuanmu on 16/11/28.
 */
public class AUAmountInputBoxActivity extends Activity {
    private AUAmountInputBox inputBox1;
    private AUNumberKeyboardView keyboardView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        View view = View.inflate(this, R.layout.view_amountinputbox, null);
        setContentView(view);

        keyboardView = (AUNumberKeyboardView) findViewById(R.id.keyboard);
        keyboardView.setNumKeyRandom(true);
        inputBox1 = (AUAmountInputBox) findViewById(R.id.amount_input_1);
        ScrollView scrollView = (ScrollView) findViewById(R.id.scroll);

        inputBox1.setFootHint("添加转账说明（20字以内)");
        inputBox1.getEditLayout().setKeyBoardView(keyboardView, scrollView);

//        AUAmountInputBox inputBox2 = (AUAmountInputBox)findViewById(R.id.amount_input_2);
//        inputBox2.setFootText("不可输入");
//
//        AUAmountEditText editText = (AUAmountEditText)findViewById(R.id.edit_text);
//        final AUAmountLabelText labelText = (AUAmountLabelText)findViewById(R.id.label_text);
//        labelText.setText("1,234,56,3.1");
//
//        editText.getEditText().addTextChangedListener(new TextWatcher() {
//            @Override
//            public void beforeTextChanged(CharSequence s, int start, int count, int after) {
//
//            }
//
//            @Override
//            public void onTextChanged(CharSequence s, int start, int before, int count) {
//
//            }
//
//            @Override
//            public void afterTextChanged(Editable s) {
//                labelText.setText(s);
//            }
//        });
    }

    @Override
    public void onWindowFocusChanged(boolean hasFocus) {
        super.onWindowFocusChanged(hasFocus);
        if (hasFocus) {
            inputBox1.requestFocus();
        }
    }
}
