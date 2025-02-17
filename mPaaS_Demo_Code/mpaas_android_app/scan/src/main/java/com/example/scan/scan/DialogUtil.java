package com.example.scan.scan;

import android.app.Activity;
import android.app.AlertDialog;
import android.content.DialogInterface;

import android.widget.EditText;

import com.example.scan.R;

public class DialogUtil {

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
        new AlertDialog.Builder(activity)
                .setMessage(msg)
                .setPositiveButton(R.string.confirms, null)
                .create()
                .show();
    }

    public static void prompt(Activity activity, final PromptCallback callback) {
        final EditText edit = new EditText(activity);
        new AlertDialog.Builder(activity)
                .setTitle(activity.getString(R.string.input_text))
                .setView(edit)
                .setPositiveButton(activity.getString(R.string.confirms)
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
                .setNegativeButton(activity.getString(R.string.cancel), new DialogInterface.OnClickListener() {
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
                .setPositiveButton(activity.getString(R.string.confirms)
                        , new DialogInterface.OnClickListener() {
                            @Override
                            public void onClick(DialogInterface dialog, int which) {
                                if (callback != null) {
                                    callback.onConfirm(result[0]);
                                }
                                dialog.dismiss();
                            }
                        })
                .setNegativeButton(activity.getString(R.string.cancel), new DialogInterface.OnClickListener() {
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
                .setPositiveButton(activity.getString(R.string.confirms), new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                        if (callback != null) {
                            callback.onConfirm(isCheck);
                        }
                        dialog.dismiss();
                    }
                })
                .setNegativeButton(activity.getString(R.string.cancel), new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                        dialog.dismiss();
                    }
                })
                .create()
                .show();
    }

}
