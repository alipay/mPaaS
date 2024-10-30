package com.mpaas.antui.viewdemo;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;

import com.alipay.mobile.antui.basic.AUNetErrorView;
import com.alipay.mobile.antui.basic.AUTitleBar;
import com.mpaas.antui.R;

/**
 * Created by xuanmu on 16/10/11.
 */
public class NetErrorViewActivity extends Activity {

    private int typeCount = 0;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        setContentView(R.layout.view_net_error);

        final AUTitleBar auTitleBar = (AUTitleBar) findViewById(R.id.net_title);
        final AUNetErrorView netErrorView = (AUNetErrorView) findViewById(R.id.net_error);
        auTitleBar.getRightButton().setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                netErrorView.setIsSimpleType(false);
                netErrorView.setButtonBottom(false);
                switch (typeCount) {
                    case 0:
                        netErrorView.resetNetErrorType(AUNetErrorView.TYPE_SIGNAL);
                        netErrorView.setButtonBottom(true);
                        netErrorView.setAction(new View.OnClickListener() {
                            @Override
                            public void onClick(View v) {

                            }
                        });
                        netErrorView.setButtonBlueStyle();
                        auTitleBar.setTitleText("第 " + typeCount + " 页 : " + "Signal+BottomButton");
                        break;
                    case 1:
                        netErrorView.resetNetErrorType(AUNetErrorView.TYPE_EMPTY);
                        netErrorView.getActionButton().setVisibility(View.VISIBLE);
                        netErrorView.setTips("主标题主标题");
                        netErrorView.setSubTips("副标题副标题");
                        netErrorView.setButtonBottom(false);
                        auTitleBar.setTitleText("第 " + typeCount + " 页 : " + "Empty+Button");
                        break;
                    case 2:
                        netErrorView.resetNetErrorType(AUNetErrorView.TYPE_WARNING);
                        netErrorView.setButtonBottom(true);
                        auTitleBar.setTitleText("第 " + typeCount + " 页 : " + "Warning");
                        break;
                    case 3:
                        netErrorView.resetNetErrorType(AUNetErrorView.TYPE_OVER_FLOW);
                        netErrorView.setTimer(4, "再试一次", "#D83B1E", new View.OnClickListener() {
                            @Override
                            public void onClick(View v) {

                            }
                        });
                        netErrorView.setButtonBottom(true);
                        auTitleBar.setTitleText("第 " + typeCount + " 页 : " + "OverFlow+Timer+BottomButton");
                        break;
                    case 4:
                        netErrorView.resetNetErrorType(AUNetErrorView.TYPE_NOTFOUND);
                        auTitleBar.setTitleText("第 " + typeCount + " 页 : " + "NotFound");
                        break;
                    case 5:
                        netErrorView.resetNetErrorType(AUNetErrorView.TYPE_EMPTY);
                        netErrorView.setAction(new View.OnClickListener() {
                            @Override
                            public void onClick(View v) {

                            }
                        });
                        netErrorView.setSubAction(new View.OnClickListener() {
                            @Override
                            public void onClick(View v) {

                            }
                        });
                        auTitleBar.setTitleText("第 " + typeCount + " 页 : " + "Empty+DoubleAction");
//                        netErrorView.setButtonPostion(true);
                        break;
                    case 6:
                        netErrorView.setIsSimpleType(true);
                        netErrorView.resetNetErrorType(AUNetErrorView.TYPE_SIGNAL);
                        auTitleBar.setTitleText("第 " + typeCount + " 页 : " + "Simple_Signal");
                        break;
                    case 7:
                        netErrorView.setIsSimpleType(true);
                        netErrorView.resetNetErrorType(AUNetErrorView.TYPE_EMPTY);
                        netErrorView.getActionButton().setVisibility(View.VISIBLE);
                        auTitleBar.setTitleText("第 " + typeCount + " 页 : " + "Simple_Empty");
                        break;
                    case 8:
                        netErrorView.setIsSimpleType(true);
                        netErrorView.resetNetErrorType(AUNetErrorView.TYPE_WARNING);
//                        netErrorView.setTimer(4, "再试一次", "#D83B1E", new View.OnClickListener() {
//                            @Override
//                            public void onClick(View v) {
//
//                            }
//                        });
                        auTitleBar.setTitleText("第 " + typeCount + " 页 : " + "Simple_Warning");
                        break;
                    case 9:
                        netErrorView.setIsSimpleType(true);
                        netErrorView.resetNetErrorType(AUNetErrorView.TYPE_OVER_FLOW);
                        netErrorView.setSubAction("修复", new View.OnClickListener() {
                            @Override
                            public void onClick(View v) {

                            }
                        });
                        auTitleBar.setTitleText("第 " + typeCount + " 页 : " + "Simple_OverFlow");
//                        netErrorView.getActionButton().setVisibility(View.VISIBLE);
                        break;
                    case 10:
                        netErrorView.setIsSimpleType(true);
                        netErrorView.resetNetErrorType(AUNetErrorView.TYPE_SIGNAL);
                        netErrorView.setAction(new View.OnClickListener() {
                            @Override
                            public void onClick(View v) {

                            }
                        });
                        auTitleBar.setTitleText("第 " + typeCount + " 页 : " + "Simple_Signal+Action");
                        break;
                    case 11:
                        netErrorView.resetNetErrorType(AUNetErrorView.TYPE_USER_LOGOUT);
                        netErrorView.setAction(new View.OnClickListener() {
                            @Override
                            public void onClick(View v) {

                            }
                        });
                        netErrorView.setButtonBottom(true);
                        auTitleBar.setTitleText("第 " + typeCount + " 页 : " + "Logout+Action");
                        break;
                    case 12:
                        netErrorView.setIsSimpleType(true);
                        netErrorView.resetNetErrorType(AUNetErrorView.TYPE_USER_LOGOUT);
                        netErrorView.setAction(new View.OnClickListener() {
                            @Override
                            public void onClick(View v) {

                            }
                        });
                        auTitleBar.setTitleText("第 " + typeCount + " 页 : " + "Simple_Logout+Action");
                        break;
                    default:
                        break;
                }
                if (typeCount > 11) {
                    typeCount = 0;
                } else {
                    typeCount++;
                }

            }
        });
    }
}
