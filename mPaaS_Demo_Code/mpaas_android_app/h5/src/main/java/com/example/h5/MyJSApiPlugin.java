package com.example.h5;


import android.content.pm.PackageInfo;
import android.content.pm.PackageManager;
import android.widget.Toast;

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
    private static final String TINY_TO_NATIVE = "tinyToNative";
    private static final String GET_APP_VERSION = "getAppVersion";

    @Override
    public void onPrepare(H5EventFilter filter) {
        super.onPrepare(filter);
        filter.addAction(API_1);
        filter.addAction(API_2);
        filter.addAction(TINY_TO_NATIVE);
        filter.addAction(GET_APP_VERSION);
        filter.addAction(CommonEvents.H5_PAGE_PHYSICAL_BACK);
        filter.addAction("h5ToolbarBack");

    }

    @Override
    public boolean interceptEvent(H5Event event, H5BridgeContext context) {
        String action = event.getAction();
        if ("h5ToolbarBack".equalsIgnoreCase(action)){
            Toast.makeText(event.getActivity(), "h5ToolbarBack", Toast.LENGTH_SHORT).show();
            return true;
        }
        if (API_1.equalsIgnoreCase(action)) {
            // handleEvent won't be called if interceptEvent returns true when myapi1 is invoked from JS.
            JSONObject params = event.getParam();
            String param = params.getString("param1");
            JSONObject result = new JSONObject();
            result.put("success", true);
            result.put("message", "这是前端调用native的自定义jsapi【myapi1】");
            context.sendBridgeResult(result);
            return true;
        }
        return false;
    }

    @Override
    public boolean handleEvent(H5Event event, H5BridgeContext context) {
        String action = event.getAction();
        if ("h5ToolbarBack".equalsIgnoreCase(action)){
            Toast.makeText(event.getActivity(), "h5ToolbarBack", Toast.LENGTH_SHORT).show();
            return true;
        }
        if (API_2.equalsIgnoreCase(action)) {
            JSONObject params = event.getParam();
            String param = params.getString("param2");
            JSONObject result = new JSONObject();
            result.put("success", true);
            result.put("message", "这是前端调用native的自定义jsapi【myapi2】");
            context.sendBridgeResult(result);
//            h5Page.getBridge().sendDataWarpToWeb("h5NetworkChange", param, null);
            return true;
        }
        if (TINY_TO_NATIVE.equalsIgnoreCase(action)) {
            JSONObject params = event.getParam();
            String param1 = params.getString("param1");
            String param2 = params.getString("param2");
            JSONObject result = new JSONObject();
            result.put("success", true);
            result.put("message", "这是小程序调用native的自定义jsapi【tinyToNative】");
            context.sendBridgeResult(result);
//            h5Page.getBridge().sendDataWarpToWeb("h5NetworkChange", param, null);
            return true;
        }
        if (GET_APP_VERSION.equalsIgnoreCase(action)) {
            PackageManager pm = context.getActivity().getPackageManager();
            String ver = "";
            //获取包信息
            try {
                PackageInfo packageInfo = pm.getPackageInfo(context.getActivity().getPackageName(), 0);
                ver = packageInfo.versionName;
            } catch (PackageManager.NameNotFoundException e) {
                e.printStackTrace();
            }
            JSONObject result = new JSONObject();
            result.put("success", true);
            result.put("message", "app version is " + ver);
            context.sendBridgeResult(result);
            return true;
        }
        if ((CommonEvents.H5_PAGE_PHYSICAL_BACK.equals(event.getAction()))) {

            String appVersion = event.getH5page().getPageData().getAppVersion();
            Toast.makeText(context.getActivity(), appVersion, Toast.LENGTH_SHORT).show();

            return false;
        }

        return false;
    }


}
