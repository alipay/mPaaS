package com.mpaas.mindemo;

import com.alibaba.ariver.app.api.Page;
import com.mpaas.mas.adapter.api.MPLogger;
import com.mpaas.mriver.integration.proxy.TinyEmbedUrlInterceptProxy;

public class TinyH5UrlProvider implements TinyEmbedUrlInterceptProxy {

    @Override
    public String intercept(String s, Page page, boolean b) {
        MPLogger.error("拦截url1111", s+"     page:"+page+"    b:"+b);
        return s;
    }
}
