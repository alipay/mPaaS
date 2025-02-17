package com.mpaas.analytics.fragment;


import androidx.fragment.app.Fragment;

import com.alipay.mobile.monitor.track.TrackPageConfig;
import com.mpaas.mas.adapter.api.MPTracker;

import java.util.Map;

/**
 * Created by xingcheng on 2018/10/16.
 *
 * 实现 TrackPageConfig 接口；
 * isTrackPage() 返回true；
 * getPageSpmId() 返回类名；
 * Fragment 即可被自动记录
 *
 */

public class BaseFragment extends Fragment implements TrackPageConfig {

    /**
     * 页面标识，一般使用类名
     * 不传会导致控制台页面分析中不显示
     */
    @Override
    public String getPageSpmId() {
        return this.getClass().getName();
    }

    /**
     * 其他额外参数
     */
    @Override
    public Map<String, String> getExtParam() {
        return null;
    }

    /**
     * 是否需要自动化记录页面
     **/
    @Override
    public boolean isTrackPage() {
        return true;
    }

    @Override
    public void onResume() {
        super.onResume();
        MPTracker.onFragmentResume(this);
    }

    @Override
    public void onPause() {
        super.onPause();
        MPTracker.onFragmentPause(this);
    }

    @Override
    public void onHiddenChanged(boolean hidden) {
        super.onHiddenChanged(hidden);
        MPTracker.onFragmentHiddenChanged(this, hidden);
    }

    @Override
    public void setUserVisibleHint(boolean isVisibleToUser) {
        super.setUserVisibleHint(isVisibleToUser);
        MPTracker.onFragmentSetUserVisibleHint(this, isVisibleToUser);
    }

    @Override
    public void onDestroy() {
        super.onDestroy();
        MPTracker.onFragmentDestroy(this);
    }

}
