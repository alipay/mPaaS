package com.example.scan.demo.custom.widget;
import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.Color;
import android.graphics.Point;
import android.graphics.Rect;
import android.util.AttributeSet;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.RelativeLayout;

/**
 * 背景预览图View
 * */
public class BgPreviewContainer extends RelativeLayout {
    private ImageView bgImg;

    public BgPreviewContainer(Context context) {
        this(context, null);
    }

    public BgPreviewContainer(Context context, AttributeSet attrs) {
        super(context, attrs);
        bgImg = new ImageView(getContext());
        LayoutParams params = new LayoutParams(
                ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.MATCH_PARENT);
        bgImg.setScaleType(ImageView.ScaleType.FIT_XY);
        params.addRule(CENTER_IN_PARENT);
        addView(bgImg, params);
        setBackgroundColor(Color.BLACK);
    }

    public Rect getBgImageBorderRect(){
        if(bgImg != null){
            int left = (int) bgImg.getX();
            int top = (int) bgImg.getY();
            int right = left + bgImg.getWidth();
            int bottom = top + bgImg.getHeight();
            return new Rect(
                    left > 0 ? left : 0,
                    top > 0 ? top : 0,
                    right > 0 ? right : 0,
                    bottom > 0 ? bottom : 0);
        }
        return new Rect(0,0,0,0);
    }

    public void clear(){
        if(bgImg != null){
            LayoutParams params = new LayoutParams(
                    ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.MATCH_PARENT);
            bgImg.setLayoutParams(params);
            bgImg.setImageBitmap(null);
        }
        LayoutParams params = (LayoutParams) getLayoutParams();
        if(params != null){
            params.setMargins(0,0,0,0);
        }
    }

    public Point setBgImageBitmap(Bitmap bitmap, int maxWidth, int maxHeight) {
        bgImg.setImageBitmap(bitmap);
        //这里的bitmap是已经摆正的图片
        if (maxHeight > 0 && maxWidth > 0) {
            int bmpWidth = bitmap.getWidth();
            int bmpHeight = bitmap.getHeight();
            int finalHeight;
            int finalWidth;
            if (bmpWidth >= bmpHeight) {
                float scale = maxWidth * 1.f / bmpWidth;
                finalHeight = (int) (scale * bmpHeight);
                if(finalHeight > maxHeight){
                    scale = maxHeight * 1.f /bmpHeight;
                    finalWidth = (int) (scale * bmpWidth);
                    finalHeight = maxHeight;
                }
                finalWidth = maxWidth;
            } else {
                float scale = maxHeight * 1.f / bmpHeight;
                finalWidth = (int) (scale * bmpWidth);
                if(finalWidth > maxWidth){
                    scale = maxWidth * 1.f / bmpWidth;
                    finalHeight = (int) (scale * bmpHeight);
                    finalWidth = maxWidth;
                }else{
                    finalHeight = maxHeight;
                }
            }
            LayoutParams params = (LayoutParams) bgImg.getLayoutParams();
            if (params != null) {
                //bgImage 居中显示，后面要取居中后的border
                params.height = finalHeight;
                params.width = finalWidth;
                params.addRule(CENTER_IN_PARENT);
                bgImg.setLayoutParams(params);
                return new Point(finalWidth, finalHeight);
            }
        }
        return null;
    }
}