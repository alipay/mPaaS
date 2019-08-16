package com.mpaas.demo.nebula;

import com.alibaba.fastjson.JSONObject;
import com.alipay.mobile.antui.basic.AUToast;
import com.alipay.mobile.h5container.api.H5BridgeContext;
import com.alipay.mobile.h5container.api.H5Event;
import com.alipay.mobile.h5container.api.H5EventFilter;
import com.alipay.mobile.h5container.api.H5Param;
import com.alipay.mobile.h5container.api.H5SimplePlugin;
import com.alipay.mobile.h5container.service.H5Service;
import com.alipay.mobile.nebula.util.H5Utils;
import com.mpaas.framework.adapter.api.MPFramework;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by larry.cl.
 * 该plugin用于拦截指定url，并重定向到相应合法url.
 */
public class MyUrlInterceptPlugin extends H5SimplePlugin {

    private static final List<String> INTERCEPTED_URLS =
            new ArrayList<String>() {
                {
                    add("http://www.abc.com");
                    add("https://www.def.com");
                }
            };

    private static final String REDIRECTED_URL = "https://tech.antfin.com";

    @Override
    public void onPrepare(H5EventFilter filter) {
        super.onPrepare(filter);
        filter.addAction(CommonEvents.H5_PAGE_SHOULD_LOAD_URL);
    }

    @Override
    public boolean interceptEvent(H5Event event, H5BridgeContext context) {
        String action = event.getAction();
        if (CommonEvents.H5_PAGE_SHOULD_LOAD_URL.equals(action)) {
            String url = H5Utils.getString(event.getParam(), H5Param.LONG_URL);
            if (INTERCEPTED_URLS.contains(url)) {
                JSONObject eventParam = event.getParam();
                eventParam.put("url", REDIRECTED_URL);
                H5Event.Builder builder = new H5Event.Builder();
                builder.action(CommonEvents.H5_PAGE_DO_LOAD_URL)
                        .param(eventParam)
                        .target(event.getTarget());
                H5Service h5Service = MPFramework.getMicroApplicationContext()
                        .findServiceByInterface(H5Service.class.getName());
                h5Service.sendEvent(builder.build());
                String interceptTips =
                        url + " 已被拦截并重定向到了 " + REDIRECTED_URL;
                AUToast.makeToast(MPFramework.getApplicationContext(), 0, interceptTips, 2000).show();
                return true;
            } else {
                return false;
            }
        }
        return false;
    }

    @Override
    public boolean handleEvent(H5Event event, H5BridgeContext context) {
        return super.handleEvent(event, context);
    }

}
