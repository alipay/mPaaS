package com.mpaas.antui.viewdemo.theme;

import com.mpaas.antui.R;
import com.alipay.mobile.antui.theme.AUAbsTheme;
import com.alipay.mobile.antui.theme.AUThemeKey;

/**
 * Created by xuanmu on 17/8/14.
 */

public class ChangeThemeImpl extends AUAbsTheme {

    private static final ChangeThemeImpl instance = new ChangeThemeImpl();

    public static final ChangeThemeImpl getInstance() {
        return instance;
    }

    private ChangeThemeImpl() {
        initTheme();
    }

    @Override
    protected void initTheme() {
        put(AUThemeKey.TITLEBAR_BACKGROUND_COLOR, R.drawable.change_titlebar_backgroud);
    }
}
