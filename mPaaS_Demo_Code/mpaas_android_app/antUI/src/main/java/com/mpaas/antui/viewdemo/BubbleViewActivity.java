package com.mpaas.antui.viewdemo;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.RelativeLayout;
import android.widget.SeekBar;

import com.alipay.mobile.antui.badge.bubble.AUBubbleView;
import com.mpaas.antui.R;

/**
 * Created by yves on 2018/5/16.
 */

public class BubbleViewActivity extends Activity {
    private static final String TAG = "BubbleViewActivity";

    SeekBar sb;
    AUBubbleView bv;

    Button bt0;
    Button bt1;
    Button bt2;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_bubble);


        sb = (SeekBar) findViewById(R.id.sb);
        bv = (AUBubbleView) findViewById(R.id.bv5);
        bt0 = (Button) findViewById(R.id.bt_top_right);
        bt1 = (Button) findViewById(R.id.bt_top_mid);
        bt2 = (Button) findViewById(R.id.bt_top_left);

        sb.setProgress(100);

        bv.setText("会变的气泡");
        bv.setTextSize(55 * sb.getProgress() / sb.getMax());

        sb.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
            @Override
            public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
                bv.setTextSize(55 * progress / 100);
                Log.d(TAG, "onProgressChanged: " + 55 * progress / 100);
            }

            @Override
            public void onStartTrackingTouch(SeekBar seekBar) {

            }

            @Override
            public void onStopTrackingTouch(SeekBar seekBar) {

            }
        });

        bt0.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                bv.setBubblePosition(AUBubbleView.POSITION_TOP_RIGHT);
                RelativeLayout.LayoutParams lp = (RelativeLayout.LayoutParams) bv.getLayoutParams();
                lp.removeRule(RelativeLayout.ALIGN_PARENT_RIGHT);
                lp.removeRule(RelativeLayout.CENTER_HORIZONTAL);
                lp.addRule(RelativeLayout.ALIGN_PARENT_LEFT);
                bv.setLayoutParams(lp);
            }
        });

        bt1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                bv.setBubblePosition(AUBubbleView.POSITION_TOP_MID);
                RelativeLayout.LayoutParams lp = (RelativeLayout.LayoutParams) bv.getLayoutParams();
                lp.removeRule(RelativeLayout.ALIGN_PARENT_LEFT);
                lp.removeRule(RelativeLayout.ALIGN_PARENT_RIGHT);
                lp.addRule(RelativeLayout.CENTER_HORIZONTAL);
                bv.setLayoutParams(lp);
            }
        });

        bt2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                bv.setBubblePosition(AUBubbleView.POSITION_TOP_LEFT);
                RelativeLayout.LayoutParams lp = (RelativeLayout.LayoutParams) bv.getLayoutParams();
                lp.removeRule(RelativeLayout.ALIGN_PARENT_LEFT);
                lp.removeRule(RelativeLayout.CENTER_HORIZONTAL);
                lp.addRule(RelativeLayout.ALIGN_PARENT_RIGHT);
                bv.setLayoutParams(lp);
            }
        });
    }
}
