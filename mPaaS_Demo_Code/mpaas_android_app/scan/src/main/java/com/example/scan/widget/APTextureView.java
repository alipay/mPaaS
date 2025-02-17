package com.example.scan.widget;

import android.content.Context;
import android.graphics.SurfaceTexture;
import android.os.Build;
import android.util.AttributeSet;
import android.view.TextureView;

import com.alipay.mobile.common.logging.api.LoggerFactory;

import java.lang.reflect.Field;

/**
 * Created by hogan on 16/6/14.
 */
public class APTextureView extends TextureView {

    private static final String TAG = "APTextureView";

    private Field mSurfaceField;

    public APTextureView(Context context) {
        super(context);
    }

    public APTextureView(Context context, AttributeSet attrs) {
        super(context, attrs);
    }

    public APTextureView(Context context, AttributeSet attrs, int defStyleAttr) {
        super(context, attrs, defStyleAttr);
    }

    @Override
    protected void onDetachedFromWindow() {
        try {
            super.onDetachedFromWindow();
        } catch (Exception ex) {
            LoggerFactory.getTraceLogger().error(TAG, "onDetachedFromWindow exception:" + ex.getMessage());
        }
    }

    @Override
    public void setSurfaceTexture(SurfaceTexture surfaceTexture) {
        super.setSurfaceTexture(surfaceTexture);
        afterSetSurfaceTexture();
    }

    private void afterSetSurfaceTexture() {
        LoggerFactory.getTraceLogger().debug(TAG, "afterSetSurfaceTexture Build.VERSION.SDK_INT:" + Build.VERSION.SDK_INT);
        if (Build.VERSION.SDK_INT < 16 || Build.VERSION.SDK_INT > 20) {
            return;
        }

        try {
            if (mSurfaceField == null) {
                mSurfaceField = TextureView.class.getDeclaredField("mSurface");
                mSurfaceField.setAccessible(true);
            }

            SurfaceTexture innerSurface = (SurfaceTexture) mSurfaceField.get(this);
            if (innerSurface != null) {
                if (!(innerSurface instanceof APSurfaceTexture)) {
                    APSurfaceTexture wrapSurface = new APSurfaceTexture();
                    wrapSurface.mSurface = innerSurface;
                    mSurfaceField.set(this, wrapSurface);
                    LoggerFactory.getTraceLogger().debug(TAG, "afterSetSurfaceTexture wrap mSurface");
                }
            }
        } catch (Exception ex) {
            LoggerFactory.getTraceLogger().error(TAG, "afterSetSurfaceTexture exception:" + ex.getMessage());
        }
    }
}
