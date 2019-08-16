package com.mpaas.demo.nebula;

import android.content.Context;
import android.view.ViewGroup;

import com.alipay.mobile.nebula.provider.H5ViewProvider;
import com.alipay.mobile.nebula.view.H5NavMenuView;
import com.alipay.mobile.nebula.view.H5PullHeaderView;
import com.alipay.mobile.nebula.view.H5TitleView;
import com.alipay.mobile.nebula.view.H5WebContentView;

/**
 * Created by xingcheng on 2018/10/8.
 */

public class CustomNaviMenuH5ViewProvider implements H5ViewProvider {

    @Override
    public H5TitleView createTitleView(Context context) {
        return null;
    }

    @Override
    public H5NavMenuView createNavMenu() {
        return new H5NavMenuViewImpl();
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
