package com.mpaas.mindemo;

import android.app.Activity;
import android.content.Context;
import android.graphics.Bitmap;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

import com.alibaba.ariver.app.api.Page;
import com.mpaas.mriver.base.view.ITitleEventDispatcher;
import com.mpaas.mriver.base.view.TitleBarFrameLayout;
import com.mpaas.mriver.base.view.TitleBarTheme;
import com.mpaas.mriver.base.view.title.ITitleView;

public class CustomTitleView implements ITitleView {
    protected TitleBarFrameLayout contentView;
    private Context mContext;

    public CustomTitleView(Context context) {
        this.mContext = context;
        ViewGroup parent = null;
        if (context instanceof Activity && ((Activity) context).getWindow
                () != null) {
            parent = ((Activity) mContext).findViewById(android.R.id.content);
        }
        contentView = (TitleBarFrameLayout) LayoutInflater.from(context).inflate(R.layout.title_my_mini,parent,false);
    }

    @Override
    public void setPage(Page page) {

    }

    @Override
    public void setStatusBarColor(int i) {
        Log.e("状态栏颜色",""+i);

    }

    @Override
    public void setBackgroundColor(int i) {

    }

    @Override
    public void setAlpha(int i, boolean b) {

    }

    @Override
    public View getContentView() {
        return contentView;
    }

    @Override
    public void setTitle(String s) {

    }

    @Override
    public String getTitle() {
        return null;
    }

    @Override
    public void showTitleLoading(boolean b) {
        Log.e("aaaaaaaaa","b："+b);
    }

    @Override
    public void showBackButton(boolean b) {

    }

    @Override
    public void showOptionMenu(boolean b) {

    }

    @Override
    public View getDivider() {
        return null;
    }

    @Override
    public void onRelease() {

    }

    @Override
    public void setOptionMenu(Bitmap bitmap) {

    }

    @Override
    public void setTitleImage(Bitmap bitmap, String s) {

    }

    @Override
    public void showHomeButton(boolean b) {

    }

    @Override
    public void setTitleEventDispatcher(ITitleEventDispatcher iTitleEventDispatcher) {

    }

    @Override
    public void addCapsuleButtonGroup(View view) {

    }

    @Override
    public void setTitlePenetrate(boolean b) {

    }

    @Override
    public void applyTheme(TitleBarTheme titleBarTheme) {

    }

    @Override
    public boolean isShowHomeButton() {
        return false;
    }

    @Override
    public View getOptionMenuContainer() {
        return null;
    }

    @Override
    public View getOptionMenuContainer(int i) {
        return null;
    }
}
