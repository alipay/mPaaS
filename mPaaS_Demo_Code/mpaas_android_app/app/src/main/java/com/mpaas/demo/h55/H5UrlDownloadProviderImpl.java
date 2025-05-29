package com.mpaas.demo.h55;

import com.alipay.mobile.h5container.api.H5Page;
import com.alipay.mobile.nebula.provider.H5UrlDownloadProvider;
import com.mpaas.mas.adapter.api.MPLogger;

public class H5UrlDownloadProviderImpl implements H5UrlDownloadProvider {
    @Override
    public void handleDownload(String s, String s1, String s2, String s3, long l, H5Page h5Page) {
        MPLogger.info("aaaaaaaaaaa",s +"\n"+ s1 +"\n"+ s2 +"\n"+ s3 +"\n"+ l);
//        h5Page.loadUrl("https://gw.alipayobjects.com/os/bmw-prod/c14e0064-8fc7-4091-a921-249fc7c040f6.pdf");
    }
}
