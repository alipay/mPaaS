package com.mpaas.antui.viewdemo;

import android.app.Activity;
import android.graphics.Paint;
import android.os.Bundle;
import android.view.View;

import com.mpaas.antui.R;
import com.alipay.mobile.antui.basic.AUTitleBar;
import com.alipay.mobile.antui.status.AUFlowResultView;
import com.alipay.mobile.antui.status.AUResultView;
import com.alipay.mobile.antui.status.FlowResult;
import com.alipay.mobile.antui.status.ResultConstant;
import com.alipay.mobile.antui.status.ResultStatusIcon;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Created by wilson on 10/3/16.
 */
public class StatusActivity extends Activity {

    private int i = 1;
    private AUResultView resultView1;
    private AUResultView resultView2;
    private AUFlowResultView flowResultView;

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.view_status);

        resultView1 = (AUResultView) findViewById(R.id.result_view);
        resultView2 = (AUResultView) findViewById(R.id.result_view2);
        flowResultView = (AUFlowResultView) findViewById(R.id.flow_result_view);

        AUTitleBar titleBar = (AUTitleBar) findViewById(R.id.result_title);
        titleBar.getRightButton().setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (i == 0) {
                    resultView1.setVisibility(View.VISIBLE);
                    resultView2.setVisibility(View.GONE);
                    flowResultView.setVisibility(View.GONE);
                    i++;
                } else if (i == 1) {
                    resultView1.setVisibility(View.GONE);
                    resultView2.setVisibility(View.VISIBLE);
                    flowResultView.setVisibility(View.GONE);
                    i++;
                } else if (i == 2) {
                    resultView1.setVisibility(View.GONE);
                    resultView2.setVisibility(View.GONE);
                    flowResultView.setVisibility(View.VISIBLE);
                    i = 0;
                }

            }
        });


        int flags = resultView2.getThirdTitleText().getPaintFlags();
        resultView2.getThirdTitleText().setPaintFlags(flags | Paint.STRIKE_THRU_TEXT_FLAG);
        resultView2.setButtonText("主要操作", "辅助操作");

        List<FlowResult> flows = new ArrayList<FlowResult>();
        flows.add(new FlowResult(ResultConstant.RESULT_STATUS_ENUM_OK, ResultStatusIcon.OK,
                "支付成功", Arrays.asList("辅助说明文本", "辅助说明文本")));
        flows.add(new FlowResult(ResultConstant.RESULT_STATUS_ENUM_OK, ResultStatusIcon.PENDING,
                "标签文本", Arrays.asList("辅助说明文本", "辅助说明文本")));
        flows.add(new FlowResult(ResultConstant.RESULT_STATUS_ENUM_NORMAL, ResultStatusIcon.PENDING,
                "标签文本", Arrays.asList("辅助说明文本", "辅助说明文本")));
        flowResultView.setFlows(flows);
    }
}