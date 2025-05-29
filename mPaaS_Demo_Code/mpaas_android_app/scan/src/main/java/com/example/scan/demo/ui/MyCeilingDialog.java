package com.example.scan.demo.ui;

import android.app.Dialog;
import android.content.Context;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;

import androidx.annotation.NonNull;

import com.example.scan.demo.R;


public class MyCeilingDialog extends Dialog {

    private CharSequence mTitle;
    private CharSequence mMsg;

    public MyCeilingDialog(@NonNull Context context) {
        this(context, "", "");
    }

    public MyCeilingDialog(@NonNull Context context, CharSequence title, CharSequence msg) {
        super(context, R.style.noTitleTransBgStyle);
        setTitle(title);
        setMsg(msg);
    }

    public void setTitle(CharSequence title) {
        mTitle = title;
    }

    public void setMsg(CharSequence msg) {
        mMsg = msg;
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.my_ceiling_dialog);
        View container = findViewById(R.id.container);
        ((TextView) findViewById(R.id.title)).setText(mTitle);
        ((TextView) findViewById(R.id.message)).setText(mMsg);
    }
}
