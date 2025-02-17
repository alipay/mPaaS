package com.mpaas.upgrade.dialog;

import android.content.Context;

import java.util.Locale;

public class LanguageUtils {

    /*判断当前环境是否为中文环境*/
    public static boolean isZh(Context context) {
        Locale locale = context.getResources().getConfiguration().locale;
        String language = locale.getLanguage();
        if (language.endsWith("zh"))
            return true;
        else
            return false;
    }


}
