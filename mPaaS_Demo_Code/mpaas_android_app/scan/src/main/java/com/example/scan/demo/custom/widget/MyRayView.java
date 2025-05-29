
package com.example.scan.demo.custom.widget;

import android.content.Context;
import android.os.Looper;
import android.util.AttributeSet;
import android.view.ViewGroup;
import android.view.animation.Animation;
import android.view.animation.LinearInterpolator;
import android.view.animation.Transformation;
import android.widget.FrameLayout;
import android.widget.ImageView;

import com.example.scan.demo.R;


public class MyRayView extends FrameLayout {
    public static final String TAG = "NScanRayView";
    private ImageView mAnimationView;
    private boolean isAnimated = false;

    private Animation scanAnimator;

    public MyRayView(Context context) {
        this(context, null);
    }

    public MyRayView(Context context, AttributeSet attrs) {
        super(context, attrs);
        mAnimationView = new ImageView(context);
        mAnimationView.setScaleType(ImageView.ScaleType.FIT_XY);
        mAnimationView.setBackgroundResource(R.drawable.my_scan_ray);
        mAnimationView.setVisibility(INVISIBLE);
        this.addView(mAnimationView, new LayoutParams(
                ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.WRAP_CONTENT));
    }

    public void startAnimation() {
        if (getHeight() <= 0) {
            return;
        }
        if (isAnimated) {
            return;
        }
        final int cornerSize = getResources().getDimensionPixelSize(R.dimen.my_scan_window_corner_width);
        isAnimated = true;
        mAnimationView.setVisibility(VISIBLE);
        scanAnimator = new Animation() {
            @Override
            protected void applyTransformation(float interpolatedTime, Transformation t) {
                if (interpolatedTime <= 0.2) {
                    float alpha = (float) (interpolatedTime / 0.2);
                    mAnimationView.setAlpha(alpha);
                }
                float translateY = cornerSize / 2 + interpolatedTime * (getHeight() - cornerSize - mAnimationView.getHeight());
                mAnimationView.setTranslationY(translateY);
                if (interpolatedTime >= 0.8) {
                    float alpha = (float) ((1 - interpolatedTime) / 0.2);
                    mAnimationView.setAlpha(alpha);
                }
            }
        };
        scanAnimator.setInterpolator(new LinearInterpolator());
        scanAnimator.setRepeatCount(-1);
        scanAnimator.setDuration(2000);
        mAnimationView.startAnimation(scanAnimator);
    }

    @Override
    protected void onDetachedFromWindow() {
        super.onDetachedFromWindow();
        if (scanAnimator != null) {
            mAnimationView.clearAnimation();
        }
    }

    public void stopAnimation() {
        if (Looper.myLooper() == Looper.getMainLooper()) {
            doStopAnimation();
        } else {
            post(new Runnable() {
                @Override
                public void run() {
                    doStopAnimation();
                }
            });
        }
    }

    private void doStopAnimation() {
        if (scanAnimator != null) {
            scanAnimator.cancel();
        }
        mAnimationView.clearAnimation();
        mAnimationView.setVisibility(INVISIBLE);
        isAnimated = false;
    }
}
