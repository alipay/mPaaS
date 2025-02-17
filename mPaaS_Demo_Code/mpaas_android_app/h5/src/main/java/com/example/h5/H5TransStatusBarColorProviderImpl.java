package com.example.h5;

import android.graphics.Color;

import com.alipay.mobile.nebula.provider.H5TransStatusBarColorProvider;

public class H5TransStatusBarColorProviderImpl implements H5TransStatusBarColorProvider {
    @Override
    public int getColor() {
        return Color.argb(0, 0, 0, 1);
    }
}
