package com.mpaas.demo.nebula;

import com.alibaba.fastjson.JSONObject;
import com.alipay.mobile.h5container.api.H5BridgeContext;
import com.alipay.mobile.h5container.api.H5Event;
import com.alipay.mobile.h5container.api.H5EventFilter;
import com.alipay.mobile.h5container.api.H5SimplePlugin;

/**
 * Created by omg on 2018/7/30.
 */

public class MyJSApiPlugin extends H5SimplePlugin {

    private static final String API_1 = "myapi1";
    private static final String API_2 = "myapi2";

    @Override
    public void onPrepare(H5EventFilter filter) {
        super.onPrepare(filter);
        filter.addAction(API_1);
        filter.addAction(API_2);
    }

    @Override
    public boolean interceptEvent(H5Event event, H5BridgeContext context) {
        String action = event.getAction();
        if (API_1.equalsIgnoreCase(action)) {
            // handleEvent won't be called if interceptEvent returns true when myapi1 is invoked from JS.
            JSONObject params = event.getParam();
            String param = params.getString("param1");
            JSONObject result = new JSONObject();
            result.put("success", true);
            result.put("message", API_1 + " with " + param + " was intercepted by native.");
            context.sendBridgeResult(result);
            return true;
        }
        return false;
    }

    @Override
    public boolean handleEvent(H5Event event, H5BridgeContext context) {
        String action = event.getAction();
        if (API_2.equalsIgnoreCase(action)) {
            JSONObject params = event.getParam();
            String param = params.getString("param2");
            JSONObject result = new JSONObject();
            result.put("success", true);
            result.put("message", API_2 + " with " + param + " was handled by native.");
            context.sendBridgeResult(result);
            return true;
        }
        return false;
    }

}
