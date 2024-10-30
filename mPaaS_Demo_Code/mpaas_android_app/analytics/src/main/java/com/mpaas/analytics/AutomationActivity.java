package com.mpaas.analytics;


import android.os.Bundle;

import androidx.fragment.app.Fragment;
import androidx.fragment.app.FragmentTransaction;

import com.alipay.mobile.framework.app.ui.BaseFragmentActivity;
import com.google.android.material.tabs.TabItem;
import com.google.android.material.tabs.TabLayout;
import com.mpaas.analytics.fragment.Fragment1;
import com.mpaas.analytics.fragment.Fragment2;

/**
 * Created by xingcheng on 2018/7/27.
 *
 * 继承mpaas框架提供的BaseActivity、BaseFragmentActivity
 * 即可被自动化日志记录
 */
public class AutomationActivity extends BaseFragmentActivity {

    private Fragment[] fragments = new Fragment[2];
    private int selectedTab = -1;
    TabLayout a;
    TabItem s;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_automation);

        // 开启自动化日志
        // 开发者可在 MockLauncherActivityAgent.postInit() 中调用
       // MPLogger.enableAutoLog();

        TabLayout tabLayout = (TabLayout) findViewById(R.id.tab);
        tabLayout.setOnTabSelectedListener(new TabLayout.OnTabSelectedListener() {
            @Override
            public void onTabSelected(TabLayout.Tab tab) {
                changeFragment(tab.getPosition());
            }

            @Override
            public void onTabUnselected(TabLayout.Tab tab) {
            }

            @Override
            public void onTabReselected(TabLayout.Tab tab) {
            }
        });

        fragments[0] = new Fragment1();
        fragments[1] = new Fragment2();
        changeFragment(0);
    }

    private void changeFragment(int tab) {
        if (selectedTab != tab) {
            FragmentTransaction transaction = getSupportFragmentManager().beginTransaction();
            if (selectedTab != -1) {
                transaction.hide(fragments[selectedTab]);
            }
            selectedTab = tab;
            Fragment f = fragments[tab];
            if (!f.isAdded()) {
                transaction.add(R.id.container, f).commitAllowingStateLoss();
            } else {
                transaction.show(f).commitAllowingStateLoss();
            }
        }
    }
}
