package com.mpaas.antui.viewdemo;

import android.app.Activity;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;

import com.mpaas.antui.R;
import com.alipay.mobile.antui.basic.AUProcessButton;
import com.alipay.mobile.antui.keyboard.AUNumberKeyboardView;
import com.alipay.mobile.antui.keyboard.AUNumberKeyboardWindow;

public class ButtonActivity extends Activity {

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		View layout = LayoutInflater.from(this).inflate(R.layout.view_button, null);
		setContentView(layout);
		final AUNumberKeyboardWindow auNumberKeyBoardWindow = new AUNumberKeyboardWindow(this, AUNumberKeyboardView.STYLE_POINT, new AUNumberKeyboardView.OnActionClickListener() {
			@Override
			public void onNumClick(View view, CharSequence num) {

			}

			@Override
			public void onDeleteClick(View view) {

			}

			@Override
			public void onConfirmClick(View view) {

			}

			@Override
			public void onCloseClick(View view) {

			}
		});

		final AUProcessButton processButton = (AUProcessButton)findViewById(R.id.progress_button);
		processButton.setProcessStyle(AUProcessButton.MAIN_PROCESS_STYLE);
		processButton.setOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View v) {
				processButton.startProcess();
				auNumberKeyBoardWindow.show();
			}
		});

		final AUProcessButton subProcessButton = (AUProcessButton)findViewById(R.id.sub_progress_button);
		subProcessButton.setProcessStyle(AUProcessButton.SUB_PROCESS_STYLE);
		subProcessButton.setOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View v) {
				subProcessButton.startProcess("loading");
			}
		});


//		processButton.setCompoundDrawables(null, getResources().getDrawable(R.drawable.rotate_process_bar), null, null);
	}

}
