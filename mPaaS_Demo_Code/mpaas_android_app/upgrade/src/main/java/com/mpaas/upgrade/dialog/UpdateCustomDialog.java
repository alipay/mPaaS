package com.mpaas.upgrade.dialog;

import android.content.Context;
import android.content.DialogInterface;
import android.graphics.drawable.Drawable;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup.LayoutParams;
import android.view.ViewTreeObserver;
import android.view.Window;
import android.view.WindowManager;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.TextView;
import com.alipay.mobile.upgrade.adapter.AdapterDialog;
import com.alipay.mobile.upgrade.widget.APLinearLayout;
import com.alipay.mobile.upgrade.widget.utils.DensityUtil;
import com.mpaas.upgrade.R;

public class UpdateCustomDialog extends AdapterDialog {

    private static boolean mIsCancelable = false;
    private static boolean isForceUpgrade = false;//是否强制升级
    private static final int MSG_MAX_ROW = 5;

    public UpdateCustomDialog(Context context) {
        super(context);
    }

    public UpdateCustomDialog(Context context, int theme) {
        super(context, theme);
    }
    
    public UpdateCustomDialog(Context context, boolean cancelable, OnCancelListener cancelListener) {
        super(context, cancelable, cancelListener);
    }


    public static class Builder {
        private Context context;
        private Drawable icon;
        private String title;
        private String message;
        private String positiveButtonText;
        private String negativeButtonText;
        private OnKeyListener onKeyListener;
        private OnClickListener positiveButtonClickListener,
                negativeButtonClickListener;

        public Builder(Context context) {
            this.context = context;
        }

        public Builder setMessage(String message) {
            this.message = message;
            return this;
        }

        public Builder setMessage(int message) {
            this.message = (String) context.getText(message);
            return this;
        }

        public Builder setIcon(Drawable icon) {
            this.icon = icon;
            return this;
        }
        
        public Builder setTitle(int title) {
            this.title = (String) context.getText(title);
            return this;
        }

        public Builder setTitle(String title) {
            this.title = title;
            return this;
        }
        
        public Builder setPositiveButton(int positiveButtonText,
                                         OnClickListener listener) {
            this.positiveButtonText = (String) context.getText(positiveButtonText);
            this.positiveButtonClickListener = listener;
            return this;
        }

        public Builder setPositiveButton(String positiveButtonText,
                                         OnClickListener listener) {
            this.positiveButtonText = positiveButtonText;
            this.positiveButtonClickListener = listener;
            return this;
        }
        
        public Builder setOnKeyListener(OnKeyListener onKeyListener){
            this.onKeyListener = onKeyListener;
            return this;
        }

        public Builder setCancelable(boolean cancelable) {

            mIsCancelable = cancelable;
            return this;
        }

        public Builder setForceUpgrade(boolean isForceUpgrade){
            isForceUpgrade = isForceUpgrade;
            return this;
        }

        public Builder setNegativeButton(int negativeButtonText,
                                         OnClickListener listener) {
            this.negativeButtonText = (String) context.getText(negativeButtonText);
            this.negativeButtonClickListener = listener;
            return this;
        }

        public Builder setNegativeButton(String negativeButtonText,
                                         OnClickListener listener) {
            this.negativeButtonText = negativeButtonText;
            this.negativeButtonClickListener = listener;
            return this;
        }

        public UpdateCustomDialog show() {
            UpdateCustomDialog dialog = create();
            dialog.show();
            return dialog;
        }

        public UpdateCustomDialog create() {
            LayoutInflater inflater = (LayoutInflater) context
                .getSystemService(Context.LAYOUT_INFLATER_SERVICE);

            // instantiate the dialog with the custom Theme
            final UpdateCustomDialog dialog = new UpdateCustomDialog(context, R.style.mp_aliupgrade_updateCommonDialogTheme);
            dialog.setCancelable(mIsCancelable);
            dialog.setCanceledOnTouchOutside(mIsCancelable);

            View layout = inflater.inflate(R.layout.update_dialog, null);
            ImageView updateDialogIcon = (ImageView) layout.findViewById(R.id.update_icon_iv);
            TextView updateTitleVersionTv = (TextView) layout.findViewById(R.id.update_title_tv);
            final LinearLayout updateMsgLL = (LinearLayout) layout.findViewById(R.id.update_msg_ll);
            final TextView updateMsgTv = (TextView) layout.findViewById(R.id.update_msg_tv);
            TextView updateCancelBtn = (TextView) layout.findViewById(R.id.update_cancel_tv);
            TextView updateConfirmBtn = (TextView) layout.findViewById(R.id.update_confirm_tv);
            View updateLineTwo = (View) layout.findViewById(R.id.update_line_viewtwo);

            if(isForceUpgrade){
                updateCancelBtn.setVisibility(View.GONE);
            }

            if(icon != null){
                updateDialogIcon.setImageDrawable(icon);
            }
            // set the dialog title
            updateTitleVersionTv.setText(title);
            // set the confirm button
            if (positiveButtonText != null) {

                updateConfirmBtn.setText(positiveButtonText);

                if (positiveButtonClickListener != null) {

                    updateConfirmBtn.setOnClickListener(new View.OnClickListener() {

                            public void onClick(View v) {
                                positiveButtonClickListener.onClick(dialog, DialogInterface.BUTTON_POSITIVE);
                                dialog.dismiss();
                            }
                        });
                }
            } else {
                updateConfirmBtn.setVisibility(View.GONE);
            }
            if (negativeButtonText != null) {

                updateCancelBtn.setText(negativeButtonText);
                if (negativeButtonClickListener != null) {
                    updateCancelBtn.setOnClickListener(new View.OnClickListener() {

                            public void onClick(View v) {

                                negativeButtonClickListener.onClick(dialog,
                                    DialogInterface.BUTTON_NEGATIVE);

                                dialog.dismiss();
                            }
                        });
                }
            } else {
                LinearLayout.LayoutParams params = (LinearLayout.LayoutParams) updateConfirmBtn.getLayoutParams();
                params.weight = 2;
                updateConfirmBtn.setLayoutParams(params);
                updateConfirmBtn.setBackgroundResource(R.drawable.update_common_dialog_force_confirm_btn_bg_selector);
                updateCancelBtn.setVisibility(View.GONE);
                updateLineTwo.setVisibility(View.GONE);
            }

            if(onKeyListener != null){
                dialog.setOnKeyListener(onKeyListener);
            }
            
            ViewTreeObserver vto = updateMsgTv.getViewTreeObserver();
            vto.addOnPreDrawListener(new ViewTreeObserver.OnPreDrawListener() {
                @Override
                public boolean onPreDraw() {
                    int updateMsgLineCount = updateMsgTv.getLineCount();
                    if(updateMsgLineCount > MSG_MAX_ROW){
                        APLinearLayout.LayoutParams layoutParams = new APLinearLayout.LayoutParams(LayoutParams.FILL_PARENT, DensityUtil.dip2px(context, 95));
                        layoutParams.setMargins(DensityUtil.dip2px(context, 20), DensityUtil.dip2px(context, 10), DensityUtil.dip2px(context, 12), DensityUtil.dip2px(context, 20));
                        updateMsgLL.setLayoutParams(layoutParams);
                    }
                    return true;
                }
            });
            
            if (message != null) {
                updateMsgTv.setText(message);
            } 
            dialog.setContentView(layout);
            Window dialogWindow = dialog.getWindow();
            WindowManager.LayoutParams lp = dialogWindow.getAttributes();
            lp.width = DensityUtil.dip2px(context, 280);
            lp.height = LayoutParams.WRAP_CONTENT;
            dialogWindow.setAttributes(lp);
            return dialog;
        }
    }

}
