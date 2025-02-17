package com.mpaas.upgrade.dialog;

import android.app.Activity;
import android.app.AlertDialog;
import android.content.Context;
import android.os.Bundle;
import android.view.Display;
import android.view.Gravity;
import android.view.View;
import android.view.Window;
import android.view.WindowManager;
import android.widget.ProgressBar;
import android.widget.TextView;

import com.mpaas.upgrade.R;

public class APGenericProgressDialog extends AlertDialog {


    private ProgressBar progress;
    private TextView tvmessage;
    private CharSequence message;
    private boolean d =true;
    private boolean isShowProgress;//是否显示进度条

    private Context mContext;
    public APGenericProgressDialog(Context context) {
        super(context);
        this.mContext = context;
    }

    public APGenericProgressDialog(Context context, int theme) {
        super(context, theme);
    }

    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.generic_progress_dialog);
        progress = (ProgressBar)this.findViewById(R.id.progress);
        tvmessage = (TextView)this.findViewById(R.id.message);
        setViewState();

    }

    public APGenericProgressDialog init(){
        /*
         * 这里的方法先执行
         * */
        //获取到dialog窗口
        Window dialogWindow = this.getWindow();
        dialogWindow.getDecorView().setPadding(0, 0, 0, 0);

        //设置窗口在activity的最底下
        dialogWindow.setGravity(Gravity.CENTER);
        //dialogWindow.setWindowAnimations(R.style.BottomAnim); //设置窗口弹出动画

        WindowManager m = ((Activity) mContext).getWindowManager();
        Display d = m.getDefaultDisplay(); // 获取屏幕宽、高用

        WindowManager.LayoutParams p = dialogWindow.getAttributes();// 获取对话框当前的参数值
        int screenWidth = DensityUtil.getScreenWidth(mContext);
        p.width = DensityUtil.dip2px(mContext ,150 );
        p.height = DensityUtil.dip2px(mContext ,65 );
        //p.height = (int) (d.getHeight() *0.1);
        dialogWindow.setAttributes(p);


        return this;
    }

    private void setViewState() {
         tvmessage.setText(this.message);
        if (this.message == null || "".equals(this.message)) {
            tvmessage.setVisibility(View.GONE);
        }

        progress.setVisibility( View.VISIBLE );
    }

    public void setMessage(CharSequence message) {
        this.message = message;
    }

    public void setProgressVisiable(boolean progressVisiable) {
        this.isShowProgress = progressVisiable;
    }

    public void setIndeterminate(boolean indeterminate) {
        if (this.progress != null) {
            this.progress.setIndeterminate(indeterminate);
        } else {
            this.d = indeterminate;
        }
    }
}
