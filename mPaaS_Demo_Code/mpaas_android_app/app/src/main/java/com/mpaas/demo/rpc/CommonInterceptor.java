package com.mpaas.demo.rpc;

import android.app.Application;
import android.os.Handler;
import android.os.Looper;
import android.util.Log;
import android.widget.Toast;

import com.alipay.mobile.antui.basic.AUToast;
import com.alipay.mobile.antui.utils.PublicResources;
import com.alipay.mobile.common.rpc.RpcException;
import com.alipay.mobile.common.rpc.RpcInterceptor;
import com.alipay.mobile.common.rpc.RpcInvocationHandler;
import com.alipay.mobile.common.rpc.RpcInvokeContext;
import com.alipay.mobile.framework.LauncherApplicationAgent;
import com.mpaas.demo.R;
import com.mpaas.demo.request.FriendJsonGetReq;
import com.mpaas.demo.request.PostlimitPostReq;

import java.lang.annotation.Annotation;
import java.lang.reflect.Method;
import java.lang.reflect.Proxy;
import java.util.Map;

/**
 * Created by xingcheng on 2018/7/27.
 */

public class CommonInterceptor implements RpcInterceptor {

    private Handler handler = new Handler(Looper.getMainLooper());

    /**
     * 拦截请求
     * <p>
     * 前置拦截：发送 RPC 之前回调。
     *
     * @param o            RPC 代理对象
     * @param threadLocal
     * @param bytes
     * @param aClass       RPC 模型类，可以判断当前调用的是哪个 RPC 模型类
     * @param method       调用的方法
     * @param objects      请求参数
     * @param annotation   调用方法的注解，OperationType
     * @param threadLocal1
     * @return true 表示继续向下执行，false 表示中断当前请求，抛出 RpcException，错误码：9
     */
    @Override
    public boolean preHandle(Object o, ThreadLocal<Object> threadLocal, byte[] bytes, Class<?> aClass, Method method, Object[] objects, Annotation annotation, ThreadLocal<Map<String, Object>> threadLocal1) throws RpcException {
        // 修改请求参数
        if (objects != null) {
            Object object = objects[0];
            if (object instanceof FriendJsonGetReq) {
                FriendJsonGetReq req = (FriendJsonGetReq) object;
                Log.d("preHandle" ,"preHandle --objects =" +req.name);
            } else if (object instanceof FriendJsonGetReq) {
                PostlimitPostReq req = (PostlimitPostReq) object;
                Log.d("preHandle" ,"preHandle --objects =" +req._requestBody.password);
            }
        }

       // Log.d("preHandle" ,"preHandle --bytes =" + bytes.length);
        Log.d("preHandle" ,"preHandle --objects1 =" + objects.length + objects[0].toString());

        // 修改请求头
        RpcInvocationHandler rpcInvocationHandler = (RpcInvocationHandler) Proxy.getInvocationHandler(o);
        RpcInvokeContext rpcInvokeContext = rpcInvocationHandler.getRpcInvokeContext();
        rpcInvokeContext.addRequestHeader("key", "value");

        return true;
    }

    /**
     * 拦截响应
     *
     * @return true 表示继续向下执行，false 表示中断当前请求，抛出 RpcException，错误码：9
     */
    @Override
    public boolean postHandle(Object o, ThreadLocal<Object> threadLocal, byte[] bytes, Class<?> aClass, Method method, Object[] objects, Annotation annotation) throws RpcException {
        return true;
    }

    /**
     * 异常拦截：发起 RPC 失败之后回调。
     *
     * @param e 表示当前 RPC 出错异常。
     * @return true 表示将当前异常继续向上抛出，false 表示不要抛出异常，正常返回，没有特殊需求，切勿返回 false。
     */
    @Override
    public boolean exceptionHandle(Object o, ThreadLocal<Object> threadLocal, byte[] bytes, Class<?> aClass, Method method, Object[] objects, final RpcException e, Annotation annotation) throws RpcException {
        if ("com.antcloud.request.exception".equals(e.getOperationType())) {
            handler.post(new Runnable() {
                @Override
                public void run() {
                    Application context = LauncherApplicationAgent.getInstance().getApplicationContext();
                    AUToast.makeToast(context,
                            PublicResources.Toast_False, context.getString(R.string.rpc_exception_toast, e.getCode()), Toast.LENGTH_SHORT).show();
                }
            });
            return false;
        }
        return true;
    }
}
