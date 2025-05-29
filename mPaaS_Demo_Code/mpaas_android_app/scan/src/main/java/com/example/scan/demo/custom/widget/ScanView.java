package com.example.scan.demo.custom.widget;

import android.content.Context;
import android.graphics.Rect;
import android.hardware.Camera;
import android.util.AttributeSet;
import android.view.LayoutInflater;
import android.view.MotionEvent;
import android.view.View;
import android.widget.RelativeLayout;

import com.alipay.mobile.bqcscanservice.Logger;
import com.alipay.mobile.bqcscanservice.MPaasScanService;
import com.example.scan.demo.R;


/**
 * 负责管理扫码相关的View、与扫码引擎的交互
 */
public class ScanView extends RelativeLayout implements View.OnTouchListener {

    private static final String TAG = "ScanView";

    private RayView mRayView;

    public ScanView(Context context) {
        super(context);
        init(context);
    }

    public ScanView(Context context, AttributeSet attrs) {
        super(context, attrs);
        init(context);
    }

    public ScanView(Context context, AttributeSet attrs, int defStyle) {
        super(context, attrs, defStyle);
        init(context);
    }

    private void init(Context ctx) {
        LayoutInflater.from(ctx).inflate(R.layout.view_scan, this, true);
        FinderView finderView = (FinderView) findViewById(R.id.finder_view);
        mRayView = (RayView) findViewById(R.id.ray_view);
        mRayView.setFinderView(finderView);
        setOnTouchListener(this);
    }

    public void onStartScan() {
        mRayView.startScanAnimation();
    }

    public void onStopScan() {
        mRayView.stopScanAnimation();
    }

    public float getCropWidth() {
        return mRayView.getWidth() * 1.1f;
    }

    public Rect getScanRect(Camera camera, int previewWidth, int previewHeight) {
        if (camera == null) {
            return null;
        }
        // 直接使用 RayView 的 Rect，
        // getLocationOnScreen 取到的数据在 oppo 折叠屏机型，非填满屏幕的显示比例下和实际有差距
        Rect r = mRayView.getRect();
        Camera.Size size;
        try {
            size = camera.getParameters().getPreviewSize();
        } catch (Exception e) {
            return null;
        }
        if (size == null) {
            return null;
        }
        double rateX = (double) size.height / (double) previewWidth;
        double rateY = (double) size.width / (double) previewHeight;
        // 裁剪框大小 = 网格动画框大小＊1.1
        int expandX = (int) (mRayView.getWidth() * 0.05);
        int expandY = (int) (mRayView.getHeight() * 0.05);
        Rect resRect = new Rect(
                (int) ((r.top - expandY) * rateY),
                (int) ((r.left - expandX) * rateX),
                (int) ((r.bottom + expandY) * rateY),
                (int) ((r.right + expandX) * rateX));

        Rect finalRect = new Rect(
                resRect.left < 0 ? 0 : resRect.left,
                resRect.top < 0 ? 0 : resRect.top,
                resRect.width() > size.width ? size.width : resRect.width(),
                resRect.height() > size.height ? size.height : resRect.height());

        Rect rect1 = new Rect(
                finalRect.left / 4 * 4,
                finalRect.top / 4 * 4,
                finalRect.right / 4 * 4,
                finalRect.bottom / 4 * 4);

        int max = Math.max(rect1.right, rect1.bottom);
        int diff = Math.abs(rect1.right - rect1.bottom) / 8 * 4;

        Rect rect2;
        if (rect1.right > rect1.bottom) {
            rect2 = new Rect(rect1.left, rect1.top - diff, max, max);
        } else {
            rect2 = new Rect(rect1.left - diff, rect1.top, max, max);
        }
        return rect2;
    }

    // 增加手势操作判断
    private long lastActionUp;
    private float lastSingleFingerPositionY;
    private float lastTwoFingerDistance;
    private int ZOOM_PACE = 30;

    private MPaasScanService mPaasScanService;

    public void setMPaasScanService(MPaasScanService mPaasScanService) {
        this.mPaasScanService = mPaasScanService;
    }

    @Override
    public boolean onTouch(View v, MotionEvent event) {
        if(v != this) {
            return false;
        }
        if(event.getAction() == MotionEvent.ACTION_UP) {
            lastTwoFingerDistance = 0;
            long time = System.currentTimeMillis();
            if(time - lastActionUp < 300) {
                Logger.d(TAG, new Object[]{"double click"});
                // 完成双指操作
                mPaasScanService.setZoom(Integer.MIN_VALUE);
                lastActionUp = 0;
            } else {
                lastActionUp = time;
            }
            return true;
        } else if(event.getAction() == MotionEvent.ACTION_MOVE) {
            if(event.getPointerCount() == 2) {
                if(lastTwoFingerDistance < 0.1f) {
                    float x1 = event.getX(0);
                    float y1 = event.getY(0);
                    float x2 = event.getX(1);
                    float y2 = event.getY(1);
                    lastTwoFingerDistance = (float)(Math.sqrt(Math.pow((double)(x1 - x2), 2)
                            + Math.pow((double)(y1-y2), 2)));
                } else {
                    float x1 = event.getX(0);
                    float y1 = event.getY(0);
                    float x2 = event.getX(1);
                    float y2 = event.getY(1);
                    float distance = (float)(Math.sqrt(Math.pow((double)(x1 - x2), 2)
                            + Math.pow((double)(y1-y2), 2)));
                    Logger.d(TAG, new Object[]{"lastTwoFingerDistance is ", lastTwoFingerDistance,
                            ", distance is ", distance});
                    int rate = (int)(distance - lastTwoFingerDistance) / ZOOM_PACE;
                    if(Math.abs(rate) > 1) {
                        mPaasScanService.setZoom(rate);
                    }
                }
                return true;
            } else if(event.getPointerCount() == 1) {
                return true;
            } else {
                return false;
            }
        } else {
            lastTwoFingerDistance = 0;
            lastSingleFingerPositionY = 0.f;
            return true;
        }
    }
}
