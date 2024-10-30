package com.mpaas.demo.rpc;


import android.content.Context;
import android.os.Handler;
import android.os.Looper;
import android.text.TextUtils;
import android.widget.Toast;

import com.alipay.mobile.common.rpc.RpcInvokeContext;
import com.alipay.mobile.common.transport.utils.NetworkUtils;
import com.alipay.mobile.framework.LauncherApplicationAgent;
import com.alipay.mobile.framework.service.annotation.OperationType;
import com.alipay.mobile.framework.service.common.RpcService;
import com.alipay.mobile.framework.service.common.TaskScheduleService;
import com.mpaas.demo.MainApplication;
import com.mpaas.framework.adapter.api.MPFramework;

public class MeetingManager {

    /**
     * 实例
     */
    private static final MeetingManager INSTANCE = new MeetingManager();
    public MeetingClient client;
    public TaskScheduleService taskService;
    private RpcService rpcService;

    /**
     * 获取实例
     *
     * @return
     */
    public static MeetingManager getInstance() {
        return INSTANCE;
    }

    /**
     * 初始化请求Rpc
     */
    public void initRpc() {
        try {
            // 获取 client 实例
            rpcService = LauncherApplicationAgent.getInstance().getMicroApplicationContext().findServiceByInterface(RpcService.class.getName());
            client = rpcService.getRpcProxy(MeetingClient.class);
            taskService = MPFramework.getExternalService(TaskScheduleService.class.getName());
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    /**
     * 核销初始化拦截器
     */
    public void initRpcConfigWrite() {
        netWorkFitter(MainApplication.getContext());
        RpcInvokeContext rpcInvokeContext = rpcService.getRpcInvokeContext(client);
        // 设置超时时间，单位ms
        rpcInvokeContext.setTimeout(60000);

        // 设置网关地址，如果不设置将以 portal 工程中的 AndroidManifest.xml 为准


        // 设置rpc拦截器
        // 全局设置，可在 MockLauncherApplicationAgent.postInit() 中设置
        rpcService.addRpcInterceptor(OperationType.class, new WriteCommonInterceptor());



    }


    /**
     * 初始化拦截器
     */
    public void initRpcConfig() {
        netWorkFitter(MainApplication.getContext());
        RpcInvokeContext rpcInvokeContext = rpcService.getRpcInvokeContext(client);
        // 设置超时时间，单位ms
        rpcInvokeContext.setTimeout(60000);

        // 设置网关地址，如果不设置将以 portal 工程中的 AndroidManifest.xml 为准


        // 设置rpc拦截器
        // 全局设置，可在 MockLauncherApplicationAgent.postInit() 中设置
        rpcService.addRpcInterceptor(OperationType.class, new CommonInterceptor());



    }

    private void netWorkFitter(Context context){
        String currentNetWorkType = null;
        int networkType = NetworkUtils.getNetworkType(context);
        if (1 == networkType) {
            currentNetWorkType = "2G";
        } else if (2 == networkType) {
            currentNetWorkType = "3G";
        } else if (4 == networkType) {
            currentNetWorkType = "4G";
        } else if (3 == networkType) {
            currentNetWorkType = "WIFI";
        } else if (5 == networkType) {
            currentNetWorkType = "5G";
        }

        if( !TextUtils.isEmpty(currentNetWorkType) && (networkType ==1 ||networkType ==2||networkType ==3 ||networkType ==4||networkType ==5)){


        }else{
            new Handler(Looper.getMainLooper()).post(new Runnable() {
                @Override
                public void run() {
                    Toast.makeText(context ,"网络未链接",Toast.LENGTH_LONG).show();
                }
            });
            return;
        }
    }


}
