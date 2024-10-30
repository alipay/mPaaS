package com.mpaas.antui.viewdemo;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Toast;

import com.mpaas.antui.R;
import com.alipay.mobile.antui.input.AUTextCodeInputBox;
import com.alipay.mobile.antui.input.OnSendCallback;
import com.alipay.mobile.antui.input.SendResultCallback;

public class InputActivity extends Activity {
    private static final String TAG = "InputActivity";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        View v = View.inflate(this, R.layout.view_input, null);
        setContentView(v);

        final AUTextCodeInputBox textCodeInputBox =
                (AUTextCodeInputBox) findViewById(R.id.au_textcode_input);
        textCodeInputBox.setOnSendCallback(new OnSendCallback() {
            @Override
            public void onSend(final SendResultCallback callback) {
                // 这里rpc请求服务端发送验证码..
                boolean resendSmsRpcSuccess = true;
                if (resendSmsRpcSuccess) {
                    // 发送验证码成功，开始倒计时
                    callback.onSuccess();
                    // 收到验证码..
                    Toast.makeText(InputActivity.this, "收到验证码: 123456", Toast.LENGTH_SHORT)
                            .show();
                    textCodeInputBox.setText("123456");
                    Log.d(TAG, "输入的验证码为：" + textCodeInputBox.getInputedText());
                } else {
                    // 发送验证码失败，重新enable发送按钮
                    callback.onFail();
                }
            }
        });
    }
}
