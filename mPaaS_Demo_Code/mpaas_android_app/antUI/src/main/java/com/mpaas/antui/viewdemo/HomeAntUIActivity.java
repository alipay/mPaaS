package com.mpaas.antui.viewdemo;

import android.os.Bundle;
import android.view.View;

import androidx.fragment.app.Fragment;
import androidx.fragment.app.FragmentActivity;
import androidx.fragment.app.FragmentPagerAdapter;
import androidx.viewpager.widget.ViewPager;

import com.alipay.mobile.antui.bar.AUTabBarItem;
import com.mpaas.antui.R;
import com.mpaas.antui.viewdemo.fragment.ComponentFragment;
import com.mpaas.antui.viewdemo.fragment.OriginalFragment;
import com.mpaas.antui.viewdemo.fragment.SceneFragment;


import java.util.ArrayList;
import java.util.List;


public class HomeAntUIActivity extends FragmentActivity implements ViewPager.OnPageChangeListener, View.OnClickListener {

    private ViewPager mViewPager;
    private FragmentPagerAdapter mPagerAdapter;
    private List<Fragment> mFragmentList = new ArrayList<Fragment>();

    private AUTabBarItem mTab_1;
    private AUTabBarItem mTab_2;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_home_antui);
        // AntUIExecutorManager.getInstance().setLottieViewExecutor(new TestLottieExecutorImpl());
        mViewPager = (ViewPager) findViewById(R.id.viewpager);
        mTab_1 = (AUTabBarItem) findViewById(R.id.tab_1);
        mTab_2 = (AUTabBarItem) findViewById(R.id.tab_2);

        mTab_1.setOnClickListener(this);
        mTab_2.setOnClickListener(this);

        mTab_1.setSelected(true);


        initFragmentList();
        initFragments();
    }

    private void initFragmentList() {
        ComponentFragment componentFragment = new ComponentFragment();
        SceneFragment sceneFragment = new SceneFragment();
        OriginalFragment originalFragment = new OriginalFragment();
        mFragmentList.add(componentFragment);
        mFragmentList.add(sceneFragment);
        mFragmentList.add(originalFragment);
    }

    private void initFragments() {

        mPagerAdapter = new FragmentPagerAdapter(this.getSupportFragmentManager()) {
            @Override
            public int getCount() {
                return mFragmentList.size();
            }

            @Override
            public Fragment getItem(int i) {
                return mFragmentList.get(i);
            }
        };
        mViewPager.setAdapter(mPagerAdapter);
        mViewPager.setOnPageChangeListener(this);
        mViewPager.setOffscreenPageLimit(2);
        /** 选择首先展示的页面 并加载页面值 */
        mViewPager.setCurrentItem(0);
    }

    @Override
    public void onPageScrolled(int i, float v, int i1) {
    }

    @Override
    public void onPageSelected(int i) {
        if (i == 0) {
            mTab_1.setSelected(true);
            mTab_2.setSelected(false);
        } else {
            mTab_1.setSelected(false);
            mTab_2.setSelected(true);
        }
    }

    @Override
    public void onPageScrollStateChanged(int i) {
    }

    @Override
    public void onClick(View v) {
        if (v == mTab_1) {
            mViewPager.setCurrentItem(0);
        } else if (v == mTab_2) {
            mViewPager.setCurrentItem(1);
        }
    }
}
