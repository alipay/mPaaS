package com.example.scan.demo.custom.widget;

import android.app.Activity;
import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.Point;
import android.graphics.Rect;
import android.view.LayoutInflater;
import android.view.View;
import android.widget.ImageView;
import android.widget.TextView;

import com.alipay.android.phone.scancode.export.adapter.MPScanError;
import com.alipay.android.phone.scancode.export.adapter.MPScanResult;
import com.alipay.mobile.scansdk.ui2.MPCustomScanView;
import com.example.scan.demo.R;
import com.example.scan.demo.custom.Utils;
import com.example.scan.demo.custom.model.BitmapInfo;
import com.example.scan.demo.util.DialogUtil;

import java.util.ArrayList;
import java.util.List;

public class MyScanView extends MPCustomScanView implements View.OnClickListener {

    private static final String TAG = "MyScanView";

    private MyRayView rayView;
    private View torchView;
    private ImageView ivTorch;
    private TextView tvTorchDesc;
    private boolean isTorchOn;
    private final List<MyIconView> iconViews = new ArrayList<>();
    private Callback callback;
    private BgPreviewContainer bgPreviewContainer;


    public MyScanView(Context context) {
        super(context);
        inflate(context);
        setOnTouchListener(this);
    }

    private void inflate(Context context) {
        LayoutInflater.from(context).inflate(R.layout.view_my_scan, this, true);
        findViewById(R.id.iv_back).setOnClickListener(this);
        findViewById(R.id.iv_gallery).setOnClickListener(this);
        rayView = findViewById(R.id.ray);
        torchView = findViewById(R.id.ll_torch);
        torchView.setOnClickListener(this);
        ivTorch = findViewById(R.id.iv_torch);
        tvTorchDesc = findViewById(R.id.tv_torch_desc);
        bgPreviewContainer = findViewById(R.id.ll_bgPreview);
    }

    public interface Callback {

        void onBackClicked(View view);

        void onGalleryClicked(View view);

        void onMaIconClicked(View view, MPScanResult mpScanResult);
    }

    public void setCallback(Callback callback) {
        this.callback = callback;
    }

    @Override
    public void onCameraOpenFailed() {
        rayView.stopAnimation();
        DialogUtil.alert((Activity) getContext(), "无法打开相机");
    }

    @Override
    public void onStartScan() {
        rayView.startAnimation();
    }

    @Override
    public void onPreviewShow() {
        rayView.startAnimation();
    }

    @Override
    public void onStopScan() {
        rayView.stopAnimation();
    }

    @Override
    public void onGetAvgGray(int gray) {
        if (gray < 50) {
            if (!isTorchVisible()) {
                post(new Runnable() {
                    @Override
                    public void run() {
                        updateTorchView();
                        torchView.setVisibility(VISIBLE);
                    }
                });
            }
        } else if (gray > 90) {
            if (isTorchVisible() && !isTorchOn) {
                post(new Runnable() {
                    @Override
                    public void run() {
                        updateTorchView();
                        torchView.setVisibility(INVISIBLE);
                    }
                });
            }
        }
    }

    @Override
    public void onScanFinished(Context context, List<MPScanResult> list) {
        showMaResultWithIcon(context, list);
    }

    public Point setBgPreviewBitmap(Bitmap bitmap, int maxWidth, int maxHeight){
        if(bgPreviewContainer != null){
            if(bgPreviewContainer.getVisibility() != View.VISIBLE){
                bgPreviewContainer.setVisibility(View.VISIBLE);
            }
            return bgPreviewContainer.setBgImageBitmap(bitmap,maxWidth,maxHeight);
        }
        return null;
    }

    public void adjustImageCoordinates(List<MPScanResult> maScanResults, int rawImageHeight,
                                       int rawImageWidth,
                                       int rotation,
                                       int previewViewHeight,
                                       int previewViewWidth,
                                       Rect borderRect){
        for (MPScanResult result : maScanResults) {
            if (result.getRect() != null) {
                int codePosCenterX = result.getRect().centerX();
                int codePosCenterY = result.getRect().centerY();
                if (codePosCenterX > 0 && codePosCenterY > 0) {
                    Point codePosUiCenter =
                            Utils.transformImageCoordinatesForRotation(
                                    codePosCenterX,
                                    codePosCenterY,
                                    rawImageWidth,
                                    rawImageHeight,
                                    0,
                                    previewViewWidth,
                                    previewViewHeight);

                    if(codePosUiCenter != null && borderRect != null){
                        codePosUiCenter.x += borderRect.left;
                        codePosUiCenter.y += borderRect.top;
                    }
                    result.setCenterPoint(codePosUiCenter);
                }
            }
        }
    }

    public void showMaResultWithIconForImage(Context context, List<MPScanResult> list, String imagePath){
        BitmapInfo bitmapInfo = Utils.processImage(context, imagePath, 1500);
        if (bitmapInfo != null && bitmapInfo.bitmap != null) {
            bgPreviewContainer.setVisibility(View.VISIBLE);
            final int rawImageWidth = bitmapInfo.beforeWidth;
            final int rawImageHeight = bitmapInfo.beforeHeight;
            final int rotation = bitmapInfo.exifRotation;

            int bgImageWidth = getMeasuredWidth();
            int bgImageHeight = getMeasuredHeight();
            Point fixedBgImage = setBgPreviewBitmap(bitmapInfo.bitmap,bgImageWidth,bgImageHeight);
            if (fixedBgImage != null) {
                bgImageWidth = fixedBgImage.x;
                bgImageHeight = fixedBgImage.y;
            }
            int leftBorderMargin = (getMeasuredWidth() - bgImageWidth) / 2;
            int topBorderMargin = (getMeasuredHeight() - bgImageHeight) / 2;

            Rect borderRect = new Rect(leftBorderMargin,topBorderMargin,leftBorderMargin+bgImageWidth,topBorderMargin+bgImageHeight);
            adjustImageCoordinates(list, rawImageHeight, rawImageWidth, rotation,
                    bgImageHeight, bgImageWidth, borderRect);
            showMaResultWithIcon(context, list);

            rayView.stopAnimation();
            rayView.setVisibility(View.GONE);
        }
    }


    public void showMaResultWithIcon(Context context, List<MPScanResult> list){
        for (final MPScanResult result : list) {
            final MyIconView iconView = new MyIconView(context, this, result);
            addView(iconView, iconView.getLayoutParams());
            iconViews.add(iconView);
            iconView.setOnClickListener(new OnClickListener() {
                @Override
                public void onClick(View v) {
                    iconView.setSelected(true);
                    for (MyIconView view : iconViews) {
                        if (view.isSelected()) {
                            continue;
                        }
                        view.setVisibility(GONE);
                    }
                    if (callback != null) {
                        callback.onMaIconClicked(iconView, iconView.getResult());
                    }
                }
            });
        }
        post(new Runnable() {
            @Override
            public void run() {
                for (MyIconView view : iconViews) {
                    view.show();
                }
            }
        });
    }

    @Override
    public void onScanFailed(Context context, MPScanError mpScanError) {
        DialogUtil.alert((Activity) context, mpScanError.getMsg());
    }

    @Override
    public void onClick(View v) {
        int id = v.getId();
        if (id == R.id.iv_back) {
            if (callback != null) {
                callback.onBackClicked(v);
            }
        } else if (id == R.id.iv_gallery) {
            if (callback != null) {
                callback.onGalleryClicked(v);
            }
        } else if (id == R.id.ll_torch) {
            onTorchViewClicked();
        }
    }

    private void onTorchViewClicked() {
        isTorchOn = switchTorch();
        updateTorchView();
        if (!isTorchOn) {
            torchView.setVisibility(INVISIBLE);
        }
    }

    private void updateTorchView() {
        if (isTorchOn) {
            ivTorch.setImageResource(R.drawable.my_torch_on);
            tvTorchDesc.setText("轻触关闭");
        } else {
            ivTorch.setImageResource(R.drawable.my_torch_off);
            tvTorchDesc.setText("轻触照亮");
        }
    }

    private boolean isTorchVisible() {
        return torchView != null && torchView.getVisibility() == VISIBLE;
    }

    public void removeAllIconViews() {
        if (iconViews.size() > 0) {
            for (MyIconView view : iconViews) {
                removeView(view);
            }
            iconViews.clear();
        }
    }
}
