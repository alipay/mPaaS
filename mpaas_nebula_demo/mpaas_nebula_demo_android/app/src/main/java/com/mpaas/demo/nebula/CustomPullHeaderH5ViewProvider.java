package com.mpaas.demo.nebula;

import android.content.Context;
import android.view.ViewGroup;

import com.alipay.mobile.h5container.api.H5PullHeader;
import com.alipay.mobile.nebula.provider.H5ViewProvider;
import com.alipay.mobile.nebula.view.H5NavMenuView;
import com.alipay.mobile.nebula.view.H5PullHeaderView;
import com.alipay.mobile.nebula.view.H5TitleView;
import com.alipay.mobile.nebula.view.H5WebContentView;

/**
 * Created by mengfei on 2018/10/23.
 */

public class CustomPullHeaderH5ViewProvider implements H5ViewProvider {
    @Override
    public H5WebContentView createWebContentView(Context context) {
        return null;
    }

    @Override
    public H5TitleView createTitleView(Context context) {
        return null;
    }

    @Override
    public H5PullHeaderView createPullHeaderView(Context context, ViewGroup viewGroup) {
        H5PullHeader header = new H5PullHeader(context, viewGroup);
        header.pbLoading.setIndeterminateDrawable(context.getResources().getDrawable(R.drawable.h5_pull_progress));
        return header;
    }

    @Override
    public H5NavMenuView createNavMenu() {
        return null;
    }
}
