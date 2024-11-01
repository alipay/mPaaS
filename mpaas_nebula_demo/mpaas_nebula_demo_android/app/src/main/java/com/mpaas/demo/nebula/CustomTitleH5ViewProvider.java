package com.mpaas.demo.nebula;

import android.content.Context;
import android.view.ViewGroup;

import com.alipay.mobile.nebula.provider.H5ViewProvider;
import com.alipay.mobile.nebula.view.H5NavMenuView;
import com.alipay.mobile.nebula.view.H5PullHeaderView;
import com.alipay.mobile.nebula.view.H5TitleView;
import com.alipay.mobile.nebula.view.H5WebContentView;

/**
 * Created by omg on 2018/7/23.
 */
public class CustomTitleH5ViewProvider implements H5ViewProvider {
    @Override
    public H5TitleView createTitleView(Context context) {
        return new H5TitleViewImpl(context);
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
