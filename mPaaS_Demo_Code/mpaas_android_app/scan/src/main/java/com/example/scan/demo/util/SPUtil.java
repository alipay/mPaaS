package com.example.scan.demo.util;

import android.content.Context;
import android.content.SharedPreferences;

public class SPUtil {
    private static final String SP_NAME = "scan_demo_sp";
    public static int getInt(Context context, String name, int defVal){
        SharedPreferences sharedPreferences = context.getSharedPreferences(SP_NAME, Context.MODE_PRIVATE);
        return sharedPreferences.getInt(name, defVal);
    }

    public static void putInt(Context context, String name, int val){
        SharedPreferences sharedPreferences = context.getSharedPreferences(SP_NAME, Context.MODE_PRIVATE);
        sharedPreferences.edit().putInt(name, val).apply();
    }
}
