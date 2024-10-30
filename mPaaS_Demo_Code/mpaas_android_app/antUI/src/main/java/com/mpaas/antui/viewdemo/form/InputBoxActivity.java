package com.mpaas.antui.viewdemo.form;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;

import com.mpaas.antui.R;
import com.alipay.mobile.antui.input.AUInputBox;
import com.alipay.mobile.antui.picker.AUDatePicker;

/**
 * Created by minghui on 2017/8/22.
 */

public class InputBoxActivity extends Activity{

    private AUInputBox datePickerInputBox, timePickerInputBox;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        View v = View.inflate(this, R.layout.inputbox_activity, null);
        setContentView(v);
        datePickerInputBox = (AUInputBox) findViewById(R.id.date_picker);
        timePickerInputBox  = (AUInputBox) findViewById(R.id.time_picker);

        datePickerInputBox.getInputEdit().setFocusable(false);
        datePickerInputBox.getInputEdit().setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                AUDatePicker datePicker = new AUDatePicker(InputBoxActivity.this,AUDatePicker.YEAR_MONTH_DAY);
                datePicker.setRange(1949,2050);
                datePicker.setOnDatePickListener(new AUDatePicker.OnYearMonthDayPickListener() {
                    @Override
                    public void onDatePicked(String year, String month, String day) {
                        datePickerInputBox.getInputEdit().setText(year+"年"+month+"月"+day+"日");
                    }
                });
                datePicker.show();
            }
        });
    }

}
