package com.example.scan.demo.custom;

import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Matrix;
import android.graphics.Point;
import android.media.ExifInterface;
import android.net.Uri;
import android.os.Build;
import android.os.ParcelFileDescriptor;
import android.text.TextUtils;
import android.widget.Toast;

import com.alipay.mobile.bqcscanservice.Logger;
import com.alipay.mobile.common.logging.api.LoggerFactory;
import com.example.scan.demo.custom.model.BitmapInfo;

import java.io.File;
import java.io.FileDescriptor;
import java.io.InputStream;

/**
 * Created by xingcheng on 2018/8/10.
 */

public class Utils {

    private static String TAG = "Utils";

    public static void toast(Context context, String msg) {
        Toast.makeText(context, msg, Toast.LENGTH_SHORT).show();
    }

    public static Bitmap changeBitmapColor(Bitmap bitmap, int color) {
        int bitmap_w = bitmap.getWidth();
        int bitmap_h = bitmap.getHeight();
        int[] arrayColor = new int[bitmap_w * bitmap_h];

        int count = 0;
        for (int i = 0; i < bitmap_h; i++) {
            for (int j = 0; j < bitmap_w; j++) {

                int originColor = bitmap.getPixel(j, i);
                // 非透明区域
                if (originColor != 0) {
                    originColor = color;
                }

                arrayColor[count] = originColor;
                count++;
            }
        }
        return Bitmap.createBitmap(arrayColor, bitmap_w, bitmap_h, Bitmap.Config.ARGB_8888);
    }

    public static Bitmap uri2Bitmap(Context context, Uri uri) {
        Bitmap bitmap = null;
        InputStream in;
        try {
            in = context.getContentResolver().openInputStream(uri);
            if (in != null) {
                bitmap = BitmapFactory.decodeStream(in);
                in.close();
            }
        } catch (Exception e) {
            LoggerFactory.getTraceLogger().error(TAG, "uri2Bitmap: Exception " + e.getMessage());
        }
        return bitmap;
    }

    public static BitmapInfo processImage(Context context, String path, int longSide){
        if(TextUtils.isEmpty(path)){
            return null;
        }
        BitmapInfo resultBitmap;
        if ((Build.VERSION.SDK_INT > 28 || Build.VERSION.SDK_INT == 28 && Build.VERSION.PREVIEW_SDK_INT > 0)
                && (path.startsWith("content://"))) {
            resultBitmap = decodeByFd(context, path, longSide);
        } else {
            if (path.startsWith("file://")) {
                path = path.substring(7);
            }
            resultBitmap = decodeByPath(path,longSide);
        }
        if(resultBitmap == null){
            return null;
        }
        return resultBitmap;
    }

    private static BitmapInfo decodeByFd(Context context, String fdPath, int longSide) {
        if (TextUtils.isEmpty(fdPath)) {
            return null;
        }
        try {
            Logger.d(TAG, new Object[]{"codeDecodePictureWithQr uriStr=", fdPath});
            Uri imageUri = Uri.parse(fdPath);
            return createThumbBitmapFromFd(context, imageUri,longSide);
        } catch (Exception e) {
            //ignore
        }
        return null;
    }

    private static BitmapInfo decodeByPath(String path,int longSide) {
        File srcImageFile = new File(path);
        if (srcImageFile == null || !srcImageFile.exists()) {
            return null;
        }
        return createThumbBitmapFromFile(srcImageFile,longSide);
    }

    public static final BitmapInfo createThumbBitmapFromFd(Context context, Uri imageUri, int longSide) {
        if (Build.VERSION.SDK_INT < 24) {
            return null;
        }
        if (imageUri != null) {
            int orientation = 0;
            ParcelFileDescriptor parcelFileDescriptor = null;
            try {
                parcelFileDescriptor =
                        context.getContentResolver().openFileDescriptor(imageUri, "r");
                if (parcelFileDescriptor == null) {
                    return null;
                }
                FileDescriptor fd = parcelFileDescriptor.getFileDescriptor();
                ExifInterface exif = new ExifInterface(fd);
                int rotationAttr = exif.getAttributeInt(ExifInterface.TAG_ORIENTATION,
                        ExifInterface.ORIENTATION_UNDEFINED);
                if (rotationAttr == ExifInterface.ORIENTATION_ROTATE_90) {
                    orientation = 90;
                } else if (rotationAttr == ExifInterface.ORIENTATION_ROTATE_180) {
                    orientation = 180;
                } else if (rotationAttr == ExifInterface.ORIENTATION_ROTATE_270) {
                    orientation = 270;
                } else {
                    orientation = 0;
                }
            } catch (Exception e) {
                orientation = 0;
            } finally {
                if (parcelFileDescriptor != null) {
                    try {
                        parcelFileDescriptor.close();
                    } catch (Exception e) {
                        Logger.e(TAG, new Object[]{"createThumbBitmapFromFd error1:", e.getMessage()});
                    }
                }
            }
            try {
                BitmapFactory.Options opts = new BitmapFactory.Options();
                opts.inJustDecodeBounds = true;
                parcelFileDescriptor =
                        context.getContentResolver().openFileDescriptor(imageUri, "r");
                if (parcelFileDescriptor == null) {
                    return null;
                }
                FileDescriptor fd = parcelFileDescriptor.getFileDescriptor();
                BitmapFactory.decodeFileDescriptor(fd, null, opts);
                int rawImageWidth = opts.outWidth;
                int rawImageHeight = opts.outHeight;

                // 计算图片缩放比例
                int inSampleSize = computeSampleSize(opts, longSide);
                opts.inSampleSize = inSampleSize;
                opts.inJustDecodeBounds = false;
                opts.inInputShareable = true;
                opts.inPurgeable = true;
                Bitmap resultBitmap = BitmapFactory.decodeFileDescriptor(fd, null, opts);
                if (resultBitmap == null) {
                    Logger.d(TAG, new Object[]{"createBitmapFromFd: decodeFile=null"});
                    return null;
                }
                Bitmap.Config type = resultBitmap.getConfig();
                Logger.d(TAG, new Object[]{"相册多码, Fd读取方式的原始图片 Width= ", rawImageWidth,
                        ", Height=", rawImageHeight, ", rotation=", orientation, ",longSide=", longSide,
                        ", type=", type.name()});

                if (resultBitmap != null) {
                    BitmapInfo bitmapInfo = new BitmapInfo();
                    bitmapInfo.bitmap = resultBitmap;
                    bitmapInfo.exifRotation = orientation;
                    bitmapInfo.inSampleSize = inSampleSize;

                    bitmapInfo = adjustRotation(bitmapInfo);
                    bitmapInfo.beforeHeight = rawImageHeight;
                    bitmapInfo.beforeWidth = rawImageWidth;
                    bitmapInfo.afterHeight = bitmapInfo.bitmap.getHeight();
                    bitmapInfo.afterWidth = bitmapInfo.bitmap.getWidth();
                    return bitmapInfo;
                }
            } catch (Throwable t) {
                Logger.e(TAG, new Object[]{"createThumbBitmapFromFd error2:", t.getMessage()});
            } finally {
                if (parcelFileDescriptor != null) {
                    try {
                        parcelFileDescriptor.close();
                    } catch (Exception e) {
                        Logger.e(TAG, new Object[]{"error:", e.getMessage()});
                    }
                }
            }
        }
        return null;
    }

    public static final BitmapInfo createThumbBitmapFromFile(File srcImageFile,int longSide) {
        if (null != srcImageFile && srcImageFile.exists()) {
            int orientation;
            try {
                ExifInterface exif = new ExifInterface(srcImageFile.getAbsolutePath());
                int rotationAttr = exif.getAttributeInt(ExifInterface.TAG_ORIENTATION,
                        ExifInterface.ORIENTATION_UNDEFINED);
                if (rotationAttr == ExifInterface.ORIENTATION_ROTATE_90) {
                    orientation = 90;
                } else if (rotationAttr == ExifInterface.ORIENTATION_ROTATE_180) {
                    orientation = 180;
                } else if (rotationAttr == ExifInterface.ORIENTATION_ROTATE_270) {
                    orientation = 270;
                } else {
                    orientation = 0;
                }
            } catch (Exception e) {
                orientation = 0;
            }
            Bitmap resultBitmap = null;
            BitmapFactory.Options opts = new BitmapFactory.Options();
            opts.inJustDecodeBounds = true;
            BitmapFactory.decodeFile(srcImageFile.getPath(), opts);

            // 计算初始图片长宽
            int rawImageWidth = opts.outWidth;
            int rawImageHeight = opts.outHeight;
            // 计算图片缩放比例
            int inSampleSize = computeSampleSize(opts, longSide);
            opts.inSampleSize = inSampleSize;
            opts.inJustDecodeBounds = false;
            opts.inInputShareable = true;
            opts.inPurgeable = true;
            try {
                resultBitmap = BitmapFactory.decodeFile(srcImageFile.getPath(), opts);
                if (resultBitmap == null) {
                    Logger.d(TAG, new Object[]{"createThumbBitmapFromFile: decodeFile=null"});
                    return null;
                }
                Bitmap.Config type = resultBitmap.getConfig();
                Logger.d(TAG, new Object[]{"相册多码, File读取方式的原始图片 Width=", rawImageWidth,
                        ", Height=", rawImageHeight, ", rotation=", orientation, ",longSide=", longSide,
                        ", type=", type.name()});
            } catch (Throwable e) {
                Logger.d(TAG, new Object[]{"createThumbBitmapFromFile", e.getLocalizedMessage()});
            }
            if (resultBitmap != null) {
                BitmapInfo bitmapInfo = new BitmapInfo();
                bitmapInfo.bitmap = resultBitmap;
                bitmapInfo.exifRotation = orientation;
                bitmapInfo.inSampleSize = inSampleSize;

                bitmapInfo = adjustRotation(bitmapInfo);

                bitmapInfo.beforeHeight = rawImageHeight;
                bitmapInfo.beforeWidth = rawImageWidth;
                bitmapInfo.afterHeight = bitmapInfo.bitmap.getHeight();
                bitmapInfo.afterWidth = bitmapInfo.bitmap.getWidth();

                return bitmapInfo;
            }
            return null;
        }
        return null;
    }

    private static final int computeSampleSize(BitmapFactory.Options options,

                                               int longSide) {
        int w = options.outWidth;
        int h = options.outHeight;
        Logger.d(TAG, new Object[]{"computeInitialSampleSize w=", w, ",h=", h});
        int bitmapLongSide = (int) (w < h ? h : w);
        if(bitmapLongSide < longSide) {
            return 1;
        }
        int initialSize = (w <= longSide ? 1 : bitmapLongSide / longSide);
        int roundedSize;
        if (initialSize <= 8) {
            roundedSize = 1;
            while (roundedSize <= initialSize) {
                roundedSize <<= 1;
            }
        } else {
            roundedSize = (initialSize + 7) / 8 * 8;
        }
        return roundedSize;
    }

    private static BitmapInfo adjustRotation(BitmapInfo bitmapInfo) {

        if (bitmapInfo != null && bitmapInfo.exifRotation != 0) {
            Matrix matrix = new Matrix();
            matrix.postRotate(bitmapInfo.exifRotation, bitmapInfo.bitmap.getWidth() / 2,
                    bitmapInfo.bitmap.getHeight() / 2);
            Bitmap rotatedBitmap = Bitmap.createBitmap(
                    bitmapInfo.bitmap,
                    0,
                    0,
                    bitmapInfo.bitmap.getWidth(),
                    bitmapInfo.bitmap.getHeight(),
                    matrix,
                    true);
            bitmapInfo.bitmap.recycle();
            if (rotatedBitmap != null) {
                bitmapInfo.bitmap = rotatedBitmap;
            } else {
                bitmapInfo = null;
            }
            return bitmapInfo;
        }
        return bitmapInfo;
    }

    public static final Point transformImageCoordinatesForRotation(int x, int y,
                                                                   int width, int height,
                                                                   int rotation,
                                                                   int objWidth, int objHeight) {
        float scaleX;
        float scaleY;
        if(rotation == 90 || rotation == 270){
            scaleX = objWidth * 1.f / height;
            scaleY = objHeight * 1.f / width;
        }else{
            scaleX = objWidth * 1.f / width;
            scaleY = objHeight * 1.f / height;
        }
        Matrix matrix = new Matrix();
        matrix.postTranslate(-width / 2, -height / 2);
        matrix.postRotate(rotation);
        matrix.postScale(scaleX, scaleY);
        matrix.postTranslate(objWidth / 2, objHeight / 2);
        float[] objCoordinates = new float[2];
        objCoordinates[0] = x;
        objCoordinates[1] = y;
        matrix.mapPoints(objCoordinates);
        Point resultPoint = new Point();
        resultPoint.x = (int) objCoordinates[0];
        resultPoint.y = (int) objCoordinates[1];
        return resultPoint;
    }
}
