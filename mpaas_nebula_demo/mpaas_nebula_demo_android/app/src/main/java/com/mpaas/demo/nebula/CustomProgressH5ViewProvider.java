package com.mpaas.demo.nebula;

import android.content.Context;
import android.view.ViewGroup;

import com.alipay.mobile.h5container.api.H5WebContentImpl;
import com.alipay.mobile.nebula.provider.H5ViewProvider;
import com.alipay.mobile.nebula.view.H5NavMenuView;
import com.alipay.mobile.nebula.view.H5Progress;
import com.alipay.mobile.nebula.view.H5PullHeaderView;
import com.alipay.mobile.nebula.view.H5TitleView;
import com.alipay.mobile.nebula.view.H5WebContentView;

/**
 * Created by mengfei on 2018/10/16.
 */

public class CustomProgressH5ViewProvider implements H5ViewProvider {
    @Override
    public H5NavMenuView createNavMenu() {
        return null;
    }

    @Override
    public H5PullHeaderView createPullHeaderView(Context context, ViewGroup viewGroup) {
        return null;
    }

    @Override
    public H5TitleView createTitleView(Context context) {
        return null;
    }

    @Override
    public H5WebContentView createWebContentView(Context context) {
        H5WebContentView contentView = new H5WebContentImpl(context);
        H5Progress progress = contentView.getProgress();
        progress.setProgressDrawable(context.getResources().getDrawable(R.drawable.h5_progress));
        return contentView;
    }
}
