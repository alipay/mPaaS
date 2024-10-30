package com.mpaas.demo.h55;

import android.content.Context;
import android.view.ViewGroup;

import com.alipay.mobile.nebula.provider.H5ViewProvider;
import com.alipay.mobile.nebula.view.H5NavMenuView;
import com.alipay.mobile.nebula.view.H5PullHeaderView;
import com.alipay.mobile.nebula.view.H5TitleView;
import com.alipay.mobile.nebula.view.H5WebContentView;

public class H5ViewProviderImpl implements H5ViewProvider {
    @Override
    public H5TitleView createTitleView(Context context) {
        return new MyH5TitleView();
    }

    @Override
    public H5NavMenuView createNavMenu() {
        return null;
    }

    @Override
    public H5PullHeaderView createPullHeaderView(Context context, ViewGroup viewGroup) {
        return null;
    }

    @Override
    public H5WebContentView createWebContentView(Context context) {
        return null;
    }
}