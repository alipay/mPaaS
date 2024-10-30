
package com.example.scan.widget;

import android.content.Context;
import android.util.AttributeSet;
import android.view.animation.AccelerateDecelerateInterpolator;
import android.view.animation.Animation;
import android.view.animation.ScaleAnimation;
import android.widget.ImageView;

/**
 * 负责绘制扫描射线
 */
public class RayView extends ImageView {

    private FinderView mFinderView;
    private ScaleAnimation scanAnimation;
    private int[] location = new int[2];

    public RayView(Context context, AttributeSet attrs) {
        super(context, attrs);
    }

    public RayView(Context context) {
        super(context);
    }

    @Override
    protected void onLayout(boolean changed, int left, int top, int right, int bottom) {
        super.onLayout(changed, left, top, right, bottom);

        // 设置 FinderView 中扫码窗口的位置
        getLocationOnScreen(location);
        if (mFinderView != null) {
            mFinderView.setScanWindowLocation(location[0], location[1], location[0] + getWidth(), location[1] + getHeight());
        }
    }

    public void startScanAnimation() {
        setVisibility(VISIBLE);
        if (scanAnimation == null) {
            scanAnimation = new ScaleAnimation(1.0f, 1.0f, 0.0f, 1.0f);
            scanAnimation.setDuration(3000L);
            scanAnimation.setFillAfter(true);
            scanAnimation.setRepeatCount(Animation.INFINITE);
            scanAnimation.setInterpolator(new AccelerateDecelerateInterpolator());
        }
        startAnimation(scanAnimation);
    }

    public void stopScanAnimation() {
        setVisibility(INVISIBLE);
        if (scanAnimation != null) {
            this.clearAnimation();
            scanAnimation = null;
        }
    }

    public void setFinderView(FinderView FinderView) {
        mFinderView = FinderView;
    }
}
