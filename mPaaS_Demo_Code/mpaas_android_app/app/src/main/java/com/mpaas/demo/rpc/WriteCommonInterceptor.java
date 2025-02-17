package com.mpaas.demo.rpc;

import android.util.Log;

import com.alipay.mobile.common.rpc.RpcException;
import com.alipay.mobile.common.rpc.RpcInterceptor;
import com.alipay.mobile.common.rpc.RpcInvocationHandler;
import com.alipay.mobile.common.rpc.RpcInvokeContext;

import java.lang.annotation.Annotation;
import java.lang.reflect.Method;
import java.lang.reflect.Proxy;
import java.util.HashMap;
import java.util.Map;

public class WriteCommonInterceptor implements RpcInterceptor {
    /**
     * 前置拦截：发送 RPC 之前回调。

     */
    @Override
    public boolean preHandle(Object o, ThreadLocal<Object> threadLocal, byte[] bytes, Class<?> aClass, Method method, Object[] objects, Annotation annotation, ThreadLocal<Map<String, Object>> threadLocal1) {
        UserInfoSP. getInstance(). getUserResponse() ;
        RpcInvocationHandler rpcInvocationHandler = (RpcInvocationHandler) Proxy.getInvocationHandler(o);
        RpcInvokeContext rpcInvokeContext = rpcInvocationHandler.getRpcInvokeContext();
        Map<String, String> headerMap = new HashMap<>();
        headerMap.put("mgw-userId", "fqfdc0a80129166115945160278153002");
//        headerMap.put("mgw-userToken", UserInfoSP.USER_TOKEN);
        Log.d("WriteCommonInterceptor","userToken : "+UserInfoSP.USER_TOKEN + "\nuserId:fqfdc0a80129166115945160278153002");
        rpcInvokeContext.setRequestHeaders(headerMap);
        return true;
    }

    /**后置拦截：发起 RPC 成功之后回调。
     *@return true 表示继续向下执行，false 表示中断当前请求，抛出 RpcException，错误码：9。
     */
    @Override
    public boolean postHandle(Object o, ThreadLocal<Object> threadLocal, byte[] bytes, Class<?> aClass, Method method, Object[] objects, Annotation annotation) {

        // 修改请求头
        RpcInvocationHandler rpcInvocationHandler = (RpcInvocationHandler) Proxy.getInvocationHandler(o);
        RpcInvokeContext rpcInvokeContext = rpcInvocationHandler.getRpcInvokeContext();
//        Map<String, String> responseList= rpcInvokeContext.getResponseHeaders();
//        if (responseList!=null){
//            String userToken=responseList.get("mgw-userToken");
//            Log.d("WriteCommonInterceptor","postHandle--userToken : " + userToken);
//        }

        return true;
    }
    /**
     * 异常拦截：发起 RPC 失败之后回调。
     * @return true 表示将当前异常继续向上抛出，false 表示不要抛出异常，正常返回，没有特殊需求，切勿返回 false。
     */
    @Override
    public boolean exceptionHandle(Object o, ThreadLocal<Object> threadLocal, byte[] bytes, Class<?> aClass, Method method, Object[] objects, RpcException e, Annotation annotation) {
        return true;
    }
}
