package com.mpaas.antui.viewdemo.form;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;

import com.mpaas.antui.R;
import com.alipay.mobile.antui.input.AUInputBox;
import com.alipay.mobile.antui.model.OptionPickerModel;
import com.alipay.mobile.antui.model.PickerDataModel;
import com.alipay.mobile.antui.picker.AUDatePicker;
import com.alipay.mobile.antui.picker.AUCascadePicker;
import com.alipay.mobile.antui.picker.AUOptionPicker;
import com.alipay.mobile.antui.utils.AuiLogger;



import java.util.ArrayList;
import java.util.Date;
import java.util.List;


/**
 * Created by minghui on 2017/8/22.
 */

public class PickerActivity extends Activity{

    private AUInputBox box1, box2, box3, box4;
//    private List<PickerDataModel> dataModels = new ArrayList<PickerDataModel>();
    private List<PickerDataModel> datas = new ArrayList<PickerDataModel>();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        View v = View.inflate(this, R.layout.picker_activity, null);
        setContentView(v);

//        for(int i   = 0; i < 24; i++){
//            PickerDataModel model = new PickerDataModel();
//            model.name = i+":00";
//            dataModels.add(model);
//        }


//        final PickerDataModel mod00 = new PickerDataModel();
//        mod00.name = "第一列3";
//        List<PickerDataModel> sub1 = new ArrayList<PickerDataModel>();
//        PickerDataModel model1 = new PickerDataModel();
//        model1.name= "第二列32";
//        sub1.add(model1);
//
//
//        PickerDataModel model2 = new PickerDataModel();
//        model2.name = "第三列21";
//        List<PickerDataModel> subs = new ArrayList<PickerDataModel>();
//        subs.add(model2);
//        model1.subList = subs;
//
//
//        mod00.subList = sub1;

        for(int i = 0; i < 10; i++){
            PickerDataModel model = new PickerDataModel();
            model.name = "第一列"+i;
            List<PickerDataModel>  tmpList = new ArrayList<PickerDataModel>();


            for(int j   = 0; j < i+3; j++){
                PickerDataModel tmp = new PickerDataModel();
                tmp.name = "第二列"+i+j;
                List<PickerDataModel> thirdList = new ArrayList<PickerDataModel>();

                for(int k = 0; k < j+5; k++){
                    PickerDataModel mod = new PickerDataModel();
                    mod.name = "第三列"+j+k;
                    thirdList.add(mod);
                }
                tmp.subList   = thirdList;
                tmpList.add(tmp);
            }

            model.subList = tmpList;
            if(i == 1){
                model.subList = null;
            }
            datas.add(model);
        }


        box1 = (AUInputBox) findViewById(R.id.date_picker);
        box2 = (AUInputBox) findViewById(R.id.time_picker);
        box3 = (AUInputBox) findViewById(R.id.data_picker);
        box4 = (AUInputBox) findViewById(R.id.option_picker);

        box1.getInputEdit().setClickable(true);
        box1.getInputEdit().setFocusable(false);

        box2.getInputEdit().setClickable(true);
        box2.getInputEdit().setFocusable(false);

        box3.getInputEdit().setClickable(true);
        box3.getInputEdit().setFocusable(false);

        box4.getInputEdit().setClickable(true);
        box4.getInputEdit().setFocusable(false);

        box1.getInputEdit().setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                AUDatePicker datePicker = new AUDatePicker(PickerActivity.this);
                datePicker.setOnDatePickListener(new AUDatePicker.OnYearMonthDayPickListener() {
                    @Override
                    public void onDatePicked(String year, String month, String day) {
                        box1.getInputEdit().setText(year+"年"+month+"月"+day+"日");

                    }
                });
                datePicker.show();
            }
        });

        box2.getInputEdit().setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                AUDatePicker datePicker = new AUDatePicker(PickerActivity.this,AUDatePicker.YEAR_MONTH_DAY);
                datePicker.setTimeDate(new Date(2000,10,12),new Date(2020, 11,10));
                datePicker.setOnDatePickListener(new AUDatePicker.OnYearMonthDayPickListener() {
                    @Override
                    public void onDatePicked(String year, String month, String day) {
                        box2.getInputEdit().setText(year+"年"+month+"月"+day+"日");
                    }
                });
                datePicker.show();
            }
        });



        box3.getInputEdit().setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                AUCascadePicker datePicker = new AUCascadePicker(PickerActivity.this);
                datePicker.setDateData(datas);
                datePicker.setOnLinkagePickerListener(new AUCascadePicker.OnLinkagePickerListener() {
                    @Override
                    public void onLinkagePicked(PickerDataModel msg) {
                        PickerDataModel model = msg;
                        AuiLogger.info("onLinkagePicked", "onLinkagePicked:"+msg.name+ model);
                        StringBuilder sb = new StringBuilder();
                        while (msg != null){
                            sb.append(msg.name+" ");
                            if(msg.subList != null && msg.subList.size() > 0) {
                                msg = msg.subList.get(0);
                            }else {
                                msg = null;
                            }
                        }
                        box3.getInputEdit().setText(sb);
                    }
                });
                datePicker.show();


            }
        });

        final List<OptionPickerModel> optionPickerModelList = new ArrayList<>();
        optionPickerModelList.add(0, getOptionModel(0, 4, 0));
        optionPickerModelList.add(1, getOptionModel(1, 7, 3));
        optionPickerModelList.add(2, getOptionModel(2, 9, 2));

        box4.getInputEdit().setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                AUOptionPicker datePicker = new AUOptionPicker(PickerActivity.this);
                datePicker.setDateData(optionPickerModelList);
                datePicker.setOptionPickerListener(new AUOptionPicker.OptionPickerListener() {
                    @Override
                    public void onOptionPicked(List<OptionPickerModel> pickerModelList) {
                        StringBuilder sb = new StringBuilder();

                        if (pickerModelList != null){
                            for (OptionPickerModel pickerModel : pickerModelList) {
                                sb.append(pickerModel.optionStr.get(pickerModel.selected) + "  ");
                            }
                        }
                        box4.getInputEdit().setText(sb);
                    }
                });
                datePicker.show();


            }
        });
    }


    private OptionPickerModel getOptionModel(int location, int sum, int selected) {
        OptionPickerModel pickerModel = new OptionPickerModel();
        pickerModel.selected = selected;
        pickerModel.optionStr = getOptionStr(location, sum);
        return pickerModel;
    }


    private List<String> getOptionStr(int location, int sum) {
        List<String> stringList = new ArrayList<>();
        for (int i = 0; i < sum; i++) {
            stringList.add("选项" + String.valueOf(location) + ":" + String.valueOf(i));
        }
        return stringList;
    }
}
