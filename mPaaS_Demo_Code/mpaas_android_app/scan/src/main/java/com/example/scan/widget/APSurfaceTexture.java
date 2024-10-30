package com.example.scan.widget;

import android.annotation.TargetApi;
import android.graphics.SurfaceTexture;
import android.os.Build;

import com.alipay.mobile.common.logging.api.LoggerFactory;

import java.lang.reflect.Method;

/**
 * Created by hogan on 16/6/14.
 */
public class APSurfaceTexture extends SurfaceTexture {

    private static final String TAG = "APSurfaceTexture";

    public SurfaceTexture mSurface;

    public APSurfaceTexture() {
        super(0);
    }

    @TargetApi(Build.VERSION_CODES.JELLY_BEAN)
    @Override
    public void attachToGLContext(int texName) {
        mSurface.attachToGLContext(texName);
    }

    @TargetApi(Build.VERSION_CODES.JELLY_BEAN)
    @Override
    public void detachFromGLContext() {
        try {
            mSurface.detachFromGLContext();
        } catch (Exception ex) {
            try {
                Method nativeMethod = SurfaceTexture.class.getDeclaredMethod("nativeDetachFromGLContext");
                nativeMethod.setAccessible(true);
                int retCode = (Integer) nativeMethod.invoke(mSurface);
                LoggerFactory.getTraceLogger().debug(TAG, "nativeDetachFromGLContext invoke retCode:" + retCode);
            } catch (Exception e) {
                LoggerFactory.getTraceLogger().error(TAG, "nativeDetachFromGLContext invoke exception:" + e.getMessage());
            }
            LoggerFactory.getTraceLogger().error(TAG, "mSurface.detachFromGLContext() exception:" + ex.getMessage());
        }
    }

    @Override
    public boolean equals(Object o) {
        return mSurface.equals(o);
    }

    @Override
    public long getTimestamp() {
        return mSurface.getTimestamp();
    }

    @Override
    public void getTransformMatrix(float[] mtx) {
        mSurface.getTransformMatrix(mtx);
    }

    @Override
    public void release() {
        super.release();
        mSurface.release();
    }

    @Override
    public int hashCode() {
        return mSurface.hashCode();
    }

    @TargetApi(Build.VERSION_CODES.KITKAT)
    @Override
    public void releaseTexImage() {
        mSurface.releaseTexImage();
    }

    @TargetApi(Build.VERSION_CODES.ICE_CREAM_SANDWICH_MR1)
    @Override
    public void setDefaultBufferSize(int width, int height) {
        mSurface.setDefaultBufferSize(width, height);
    }

    @Override
    public void setOnFrameAvailableListener(OnFrameAvailableListener listener) {
        mSurface.setOnFrameAvailableListener(listener);
    }

    @Override
    public String toString() {
        return mSurface.toString();
    }

    @Override
    public void updateTexImage() {
        mSurface.updateTexImage();
    }
}
