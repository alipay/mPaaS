package com.example.scan.demo.util;

import android.app.Activity;
import android.app.AlertDialog;
import android.content.DialogInterface;
import android.os.Looper;
import android.widget.EditText;

import com.example.scan.demo.R;


public class DialogUtil {

    public interface AlertCallback {
        void onConfirm();
    }

    public interface PromptCallback {
        void onConfirm(String msg);
    }

    public interface RadioCallback {
        void onConfirm(int which);
    }

    public interface MultiplyCallback {
        void onConfirm(boolean[] isChecked);
    }

    public static void alert(Activity activity, String msg) {
        alert(activity, msg, null);
    }

    public static void alert(final Activity activity, final String msg, final AlertCallback callback) {
        if (Looper.myLooper() == Looper.getMainLooper()) {
            doAlert(activity, msg, callback);
        } else {
            ThreadUtil.runOnMainThread(new Runnable() {
                @Override
                public void run() {
                    doAlert(activity, msg, callback);
                }
            });
        }
    }

    private static void doAlert(Activity activity, String msg, final AlertCallback callback) {
        new AlertDialog.Builder(activity)
                .setMessage(msg)
                .setPositiveButton(R.string.confirm, new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                        if (callback != null) {
                            callback.onConfirm();
                        }
                    }
                })
                .create()
                .show();
    }

    public static void prompt(Activity activity, final PromptCallback callback) {
        final EditText edit = new EditText(activity);
        new AlertDialog.Builder(activity)
                .setTitle("输入文字")
                .setView(edit)
                .setPositiveButton("确定"
                        , new DialogInterface.OnClickListener() {
                            @Override
                            public void onClick(DialogInterface dialog, int which) {
                                if (callback != null) {
                                    String text = edit.getText().toString().trim();
                                    callback.onConfirm(text);
                                }
                                dialog.dismiss();
                            }
                        })
                .setNegativeButton("取消", new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                        dialog.dismiss();
                    }
                })
                .create()
                .show();
    }

    public static void radio(Activity activity, String title, String[] items, final RadioCallback callback) {
        final int[] result = new int[1];
        new AlertDialog.Builder(activity)
                .setTitle(title)
                .setSingleChoiceItems(items, 0, new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                        result[0] = which;
                    }
                })
                .setPositiveButton("确定"
                        , new DialogInterface.OnClickListener() {
                            @Override
                            public void onClick(DialogInterface dialog, int which) {
                                if (callback != null) {
                                    callback.onConfirm(result[0]);
                                }
                                dialog.dismiss();
                            }
                        })
                .setNegativeButton("取消", new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                        dialog.dismiss();
                    }
                })
                .create()
                .show();
    }

    public static void multiply(Activity activity, String title, String[] items, final MultiplyCallback callback) {
        final boolean[] isCheck = new boolean[items.length];
        for (int i = 0; i < isCheck.length; i++) {
            isCheck[i] = false;
        }
        new AlertDialog.Builder(activity)
                .setTitle(title)
                .setMultiChoiceItems(items, isCheck
                        , new DialogInterface.OnMultiChoiceClickListener() {
                            @Override
                            public void onClick(DialogInterface dialog, int which, boolean isChecked) {
                                isCheck[which] = isChecked;
                            }
                        })
                .setPositiveButton("确定", new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                        if (callback != null) {
                            callback.onConfirm(isCheck);
                        }
                        dialog.dismiss();
                    }
                })
                .setNegativeButton("取消", new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                        dialog.dismiss();
                    }
                })
                .create()
                .show();
    }

}
