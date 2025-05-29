package com.example.scan.demo.custom.widget;

import android.content.Context;
import android.graphics.Point;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.RelativeLayout;

import com.alipay.android.phone.scancode.export.adapter.MPScanResult;
import com.example.scan.demo.R;

public class MyIconView extends ImageView {

    private ViewGroup parent;
    private MPScanResult result;
    private final RelativeLayout.LayoutParams layoutParams;
    private boolean selected;

    public MyIconView(Context context, ViewGroup parent, MPScanResult result) {
        super(context);
        this.parent = parent;
        this.result = result;
        setVisibility(INVISIBLE);
        setImageResource(R.drawable.my_scan_icon_enter);
        int width = context.getResources().getDimensionPixelSize(R.dimen.my_scan_multi_codes_icon_widths);
        layoutParams = new RelativeLayout.LayoutParams(width, width);
    }

    @Override
    public RelativeLayout.LayoutParams getLayoutParams() {
        return layoutParams;
    }

    public MPScanResult getResult() {
        return result;
    }

    @Override
    public void setSelected(boolean selected) {
        this.selected = selected;
    }

    @Override
    public boolean isSelected() {
        return selected;
    }

    public void show() {
        Point point = result.getCenterPoint();
        if (point == null) {
            return;
        }
        int showPosX = point.x;
        int showPosY = point.y;

        int width = getWidth();
        int height = getHeight();

        int x = Math.max((showPosX - width / 2), 0);
        int y = Math.max((showPosY - height / 2), 0);

        x = (x + width/2 > parent.getWidth() ? parent.getWidth() - width/2 : x);
        y = (y + height/2 > parent.getHeight() ? parent.getHeight() - height/2 : y);
        setX(x);
        setY(y);
        setVisibility(View.VISIBLE);
    }
}
