//package com.example.h5;
//
//import com.alipay.mobile.common.logging.api.LoggerFactory;
//import com.alipay.mobile.nebula.provider.H5ResProvider;
//
//import java.io.InputStream;
//import java.net.URL;
//
//public class GapResProvider implements H5ResProvider {
//    public final static String TAG =  "GapResProvider";
//    @Override
//    public InputStream getResource(String sourceUrl) {
//        //从本地缓存中获取资源
//        if (isCache(sourceUrl)) {
//            if (ResourceCache.contains(sourceUrl)) {
//                try {
//                    InputStream inputStream = ResourceCache.getResource(sourceUrl);
//                    if (null == inputStream) {
//                        LoggerFactory.getTraceLogger().debug(TAG, "File null: " + sourceUrl);
//                        return new URL(sourceUrl).openStream();
//                    }
//                    LoggerFactory.getTraceLogger().debug(TAG, "getResource: " + sourceUrl);
//                    return inputStream;
//                } catch (Exception e) {
//                }
//            }
//        } else {
//            //从网络链接获资源
//            try {
//                return new URL(sourceUrl).openStream();
//            } catch (IOException e) {
//                e.printStackTrace();
//            }
//        }
//        return null;
//    }
//
//    @Override
//    public boolean contains(String sourceUrl) {
//        if (isCache(sourceUrl)) {
//            if (ResourceCache.contains(sourceUrl)) {
//                LoggerFactory.getTraceLogger().debug(TAG, "contains: " + sourceUrl);
//                //不拦截
//                return true;
//            } else {
//                ResourceCache.download(sourceUrl);
//                return false;
//            }
//        }
//        return false;
//    }
//}
