package com.example.h5;

import android.annotation.SuppressLint;
import android.net.Uri;
import android.util.Log;
import android.webkit.MimeTypeMap;
import android.webkit.WebResourceResponse;

import com.alipay.mobile.common.logging.api.LoggerFactory;
import com.alipay.mobile.h5container.api.H5Page;
import com.alipay.mobile.nebula.provider.H5ResProvider;
import com.alipay.mobile.nebula.provider.MPH5ContentProviderPreWebProvider;
import com.mpaas.mas.adapter.api.MPLogger;

import java.io.IOException;
import java.io.InputStream;
import java.net.URL;

public class NativeMPH5ContentProviderPreWebProvider implements MPH5ContentProviderPreWebProvider {
    public final static String TAG = "NativeMPH5ContentProviderPreWebProvider";

    @SuppressLint("LongLogTag")
    @Override
    public boolean needIntercept(Uri uri, String s, H5Page h5Page, boolean b, boolean b1, boolean b2, String s1) {
        return true;
    }

    @SuppressLint("LongLogTag")
    @Override
    public WebResourceResponse preWeb(Uri uri, String s, H5Page h5Page, boolean b, boolean b1, boolean b2, String s1) {
//        MPLogger.error(TAG, "WebResourceResponse  uri:" + uri + "  s:" + s + "   h5Page:" + h5Page + "  b:" + b + "    b1:" + b1 + "    b2:" + b1 + "    s1:" + s1);
        long startTime = System.currentTimeMillis();
        MPLogger.error(TAG,"WebResourceResponse   pageUrl:"+h5Page.getUrl() +"    pageId:"+ h5Page.getSession().getId());
        MPLogger.error(TAG, "WebResourceResponse  uri:" + uri + "+  startTime:" + startTime);
        WebResourceResponse webResourceResponse = getUtf8EncodedWebResourceResponse(s);
        long endTime = System.currentTimeMillis();
        long limt = System.currentTimeMillis() - startTime;
        MPLogger.error(TAG, "WebResourceResponse  uri:" + uri + "+  endTime:" + endTime);
        MPLogger.error(TAG, "WebResourceResponse uri:" + uri + "+  limt:" + limt);
        return webResourceResponse;
    }

    private WebResourceResponse getUtf8EncodedWebResourceResponse(String s) {
        InputStream inputStream = null;
        try {
            inputStream = new URL(s).openStream();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return new WebResourceResponse(MimeTypeMap.getSingleton().getMimeTypeFromExtension(MimeTypeMap.getFileExtensionFromUrl(s)), "UTF-8", inputStream);
    }
}
