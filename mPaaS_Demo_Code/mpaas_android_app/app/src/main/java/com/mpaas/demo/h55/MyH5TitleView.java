package com.mpaas.demo.h55;

import android.view.View;
import android.widget.TextView;

import com.alipay.mobile.nebula.view.AbsTitleView;
import com.mpaas.demo.MainApplication;

import java.util.List;

public class MyH5TitleView extends AbsTitleView {
    @Override
    public View getContentView() {
        View view = View.inflate(MainApplication.getContext(), com.mpaas.H5.R.layout.title_my_h5,null);
        return view;
    }

    @Override
    public int getBackgroundColor() {
        return 0;
    }

    @Override
    public void setBackgroundAlphaValue(int i) {

    }

    @Override
    public void setBackgroundColor(int i) {

    }

    @Override
    public void resetTitle() {

    }

    @Override
    public String getTitle() {
        return null;
    }

    @Override
    public void setTitle(String s) {

    }

    @Override
    public void setSubTitle(String s) {

    }

    @Override
    public TextView getMainTitleView() {
        return null;
    }

    @Override
    public TextView getSubTitleView() {
        return null;
    }

    @Override
    public void showCloseButton(boolean b) {

    }

    @Override
    public void showBackButton(boolean b) {

    }

    @Override
    public void showBackHome(boolean b) {

    }

    @Override
    public void showTitleLoading(boolean b) {

    }

    @Override
    public void showOptionMenu(boolean b) {

    }

    @Override
    public View getOptionMenuContainer(int i) {
        return null;
    }

    @Override
    public void setOptionMenu(boolean b, boolean b1, boolean b2, List<MenuData> list) {

    }

    @Override
    public View getPopAnchor() {
        return null;
    }
}
