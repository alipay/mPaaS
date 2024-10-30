package com.mpaas.antui.viewdemo;

import android.app.Activity;
import android.os.Bundle;


/**
 * Created by minghui on 2017/7/6.
 */

public class AUImagePickerActivity extends Activity{

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
//        setContentView(R.layout.image_picker);
//        final AUImagePickerSkeleton imagePickerSkeleton = (AUImagePickerSkeleton)
//                findViewById(R.id.image_picker_skeleton);
//        imagePickerSkeleton.setMaxNum(10);
//        imagePickerSkeleton.setPickerClickListener(new AUImagePickerSkeleton.OnPickerClickListener() {
//            @Override
//            public void onPickerClick() {
////                imagePickerSkeleton.resetState();
//                ArrayList<AUPickerBitmap> bitmaps = new ArrayList<AUPickerBitmap>();
//                Resources res = getResources();
//                Bitmap    bmp = BitmapFactory.decodeResource(res, R.drawable.icon_result_alipay);
//                AUPickerBitmap pickerBitmap = new AUPickerBitmap();
//                pickerBitmap.bitmap = bmp;
//                pickerBitmap.uploadState = AUImagePickerSkeleton.UPLOAD_STATE_ERROR;
//                bitmaps.add(pickerBitmap);
//                ImagePickerModel model = new ImagePickerModel();
//                model.bitmapList = bitmaps;
//                imagePickerSkeleton.setData(model);
//            }
//
//            @Override
//            public void onImageClick(View view) {
////                imagePickerSkeleton.resetState();
//                if(view.getTag() != null) {
//                    if (view.getTag() instanceof AUPickerBitmap) {
//                        AUPickerBitmap bitmap = (AUPickerBitmap) view.getTag();
//                        imagePickerSkeleton.setDeleteAction(view, bitmap);
//                    }
//                }
//            }
//
//        });
    }
}
