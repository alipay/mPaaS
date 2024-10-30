package com.mpaas.antui.viewdemo;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.view.ViewGroup;
import android.widget.LinearLayout;
import android.widget.Toast;

import com.mpaas.antui.R;
import com.alipay.mobile.antui.basic.AUButton;
import com.alipay.mobile.antui.picker.AUDatePicker;
import com.alipay.mobile.antui.picker.AUDatePickerView;


/**
 * Created by gaopan.gp on 2016/10/2.
 */
public class DatePickActivity extends Activity {

    private final String TAG = getClass().getSimpleName();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        LinearLayout linearLayout = (LinearLayout) getLayoutInflater().inflate(R.layout.datepick, null);
        setContentView(linearLayout);
        final AUButton datePickButton1 = (AUButton) findViewById(R.id.datePickButton1);
        datePickButton1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                AUDatePicker datePicker = new AUDatePicker(DatePickActivity.this,AUDatePicker.YEAR_MONTH_DAY);
                datePicker.setRange(1949,2050);
                datePicker.setOnDatePickListener(new AUDatePicker.OnYearMonthDayPickListener() {
                    @Override
                    public void onDatePicked(String year, String month, String day) {
                        Toast.makeText(DatePickActivity.this,year + "-" + month + "-" + day,Toast.LENGTH_LONG).show();
                    }
                });
                datePicker.show();
            }
        });

        AUButton datePickButton2 = (AUButton) findViewById(R.id.datePickButton2);
        datePickButton2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                AUDatePicker datePicker = new AUDatePicker(DatePickActivity.this,AUDatePicker.YEAR_MONTH);
                datePicker.setTitleText("选择有效期");
                datePicker.setRange(2016,2050);
                datePicker.show();
            }
        });

        AUButton datePickButton3 = (AUButton) findViewById(R.id.datePickButton3);
        datePickButton3.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                AUDatePicker datePicker = new AUDatePicker(DatePickActivity.this,AUDatePicker.YEAR_MONTH_DAY);
                datePicker.setRange(2016,2050);
                datePicker.setSelectedItem(2030,12,11);
                datePicker.show();
            }
        });


        AUDatePicker picker = new AUDatePicker(this);
        picker.show();
        picker.dismiss();
        View view = picker.getOutterView();
        LinearLayout layout = (LinearLayout) findViewById(R.id.layout);
        layout.removeAllViews();
        if(view != null) {
            ((ViewGroup) view.getParent()).removeAllViews();
            layout.addView(view);
        }


        AUDatePickerView auDatePickerView = new AUDatePickerView(this);
        linearLayout.addView(auDatePickerView);
    }
}
