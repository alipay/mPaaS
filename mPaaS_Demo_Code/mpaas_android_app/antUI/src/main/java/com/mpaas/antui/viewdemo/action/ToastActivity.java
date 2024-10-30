package com.mpaas.antui.viewdemo.action;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.widget.Toast;

import com.alipay.mobile.antui.basic.AUToast;
import com.alipay.mobile.antui.dialog.AUProgressDialog;
import com.alipay.mobile.antui.utils.PublicResources;
import com.alipay.mobile.antui.utils.ToolUtils;
import com.mpaas.antui.R;


public class ToastActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.view_toast_button);
    }

    public void onSuccessToast(View view){
        AUToast.showToastWithSuper(ToastActivity.this, PublicResources.Toast_OK, "已保存到系统相册, " + "凹面屏 : " + ToolUtils.isConcaveScreen(this), Toast.LENGTH_SHORT);
    }

    public void onFailToast(View view){
        AUToast.makeToast(ToastActivity.this, PublicResources.Toast_False, "已保存到系统相册已保存到系", Toast.LENGTH_SHORT).show();
    }

    public void onWarningToast(View view){
        AUToast.makeToast(ToastActivity.this, PublicResources.Toast_Warn, "警示提示", Toast.LENGTH_SHORT).show();
    }

    public void onProgressToast(View view){
        AUProgressDialog dialog = new AUProgressDialog(this);
        dialog.setMessage("加载中");
        dialog.show();
    }

    public void onTextToastShort(View view){
        AUToast.showToastWithSuper(ToastActivity.this, 0, "最长文案不超过14个字", Toast.LENGTH_LONG);
    }

    public void onTextToastLong(View view){
        AUToast.showToastWithSuper(ToastActivity.this, 0, "最长文案不超过14个字最长文案不超过14个字最长文案不超过14个字", Toast.LENGTH_SHORT);
    }

}
