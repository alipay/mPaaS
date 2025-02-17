package com.mpaas.analytics.fragment;


import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import androidx.annotation.Nullable;

import com.mpaas.analytics.R;

/**
 * Created by xingcheng on 2018/7/27.
 */
public class Fragment1 extends BaseFragment {

    @Nullable
    @Override
    public View onCreateView(LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fragment_2, container, false);
        TextView tv = view.findViewById(R.id.tv_fragment);
        tv.setText(getString(R.string.automation_fragment1));
        return view;
    }
}
