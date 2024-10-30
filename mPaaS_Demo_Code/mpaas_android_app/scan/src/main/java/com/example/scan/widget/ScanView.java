package com.example.scan.widget;

import android.content.Context;
import android.graphics.Rect;
import android.hardware.Camera;
import android.util.AttributeSet;
import android.view.LayoutInflater;
import android.widget.RelativeLayout;
import com.example.scan.R;


/**
 * 负责管理扫码相关的View、与扫码引擎的交互
 */
public class ScanView extends RelativeLayout {

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
        int[] location = new int[2];
        mRayView.getLocationOnScreen(location);
        Rect r = new Rect(location[0], location[1],
                location[0] + mRayView.getWidth(), location[1] + mRayView.getHeight());
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
}
