package com.mpaas.demo;

import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.TextView;
import android.widget.Toast;

import com.alipay.mobile.common.rpc.RpcException;
import com.alipay.mobile.common.rpc.RpcInvokeContext;
import com.alipay.mobile.framework.LauncherApplicationAgent;
import com.alipay.mobile.framework.service.annotation.OperationType;
import com.alipay.mobile.framework.service.common.RpcService;
import com.alipay.mobile.framework.service.common.TaskScheduleService;
import com.mpaas.demo.base.BaseActivity;
import com.mpaas.demo.model.AccountInfo;
import com.mpaas.demo.model.UserInfo;
import com.mpaas.demo.request.ArticleList0JsonGetReq;
import com.mpaas.demo.request.BannerJsonPostReq;
import com.mpaas.demo.request.PostlimitPostReq;
import com.mpaas.demo.rpc.CommonInterceptor;
import com.mpaas.demo.rpc.RpcDemoClient;
import com.mpaas.framework.adapter.api.MPFramework;
import com.mpaas.mgs.adapter.api.MPRpc;

import java.util.HashMap;
import java.util.Map;

public class RpcMainActivity extends BaseActivity implements View.OnClickListener {

    private RpcDemoClient client;
    private TaskScheduleService taskService;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_rpc_main);

        // 获取 client 实例
        client = MPRpc.getRpcProxy(RpcDemoClient.class);
        taskService = MPFramework.getExternalService(TaskScheduleService.class.getName());

        initView();
        initRpcConfig();
    }

    private void initView() {
        findViewById(R.id.btn_get).setOnClickListener(this);
        findViewById(R.id.btn_post).setOnClickListener(this);
        findViewById(R.id.btn_limit).setOnClickListener(this);
        findViewById(R.id.btn_weights).setOnClickListener(this);
        findViewById(R.id.btn_exception).setOnClickListener(this);
        findViewById(R.id.btn_endorsed).setOnClickListener(this);
        findViewById(R.id.btn_mock).setOnClickListener(this);
    }

    private void initRpcConfig() {
        RpcInvokeContext rpcInvokeContext = MPRpc.getRpcInvokeContext(client);

        // 设置超时时间，单位ms
        rpcInvokeContext.setTimeout(60000);

        // 设置网关地址，如果不设置将以 portal 工程中的 AndroidManifest.xml 为准
//        String gwUrl = "https://cn-hangzhou-mgs-gw.cloud.alipay.com/mgw.htm";
//        rpcInvokeContext.setGwUrl(gwUrl);

        //设置请求头
        Map<String, String> headerMap = new HashMap<>();
        headerMap.put("key1", "val1");
        headerMap.put("key2", "val2");
        rpcInvokeContext.setRequestHeaders(headerMap);

        // 设置rpc拦截器
        // 全局设置，可在 MockLauncherApplicationAgent.postInit() 中设置
        MPRpc.addRpcInterceptor(OperationType.class, new CommonInterceptor());
    }

    @Override
    public void onClick(View v) {
        switch (v.getId()) {
            case R.id.btn_get:
                testGet();
                break;
            case R.id.btn_post:
                testPost();
                break;
            case R.id.btn_limit:
                testLimit();
                break;
            case R.id.btn_weights:
                testWeights();
                break;
            case R.id.btn_exception:
                testException();
                break;
            case R.id.btn_endorsed:
                testEndorsed();
                break;
            case R.id.btn_mock:
                testPost();
                break;

            default:
                break;
        }
    }

    private void testGet() {
        // rpc请求是同步的，这里使用了 mpaas 框架提供的线程池
        // 开发者也可使用自己的线程池
        taskService.parallelExecute(new Runnable() {
            @Override
            public void run() {
                try {
                    // 设置请求
                    ArticleList0JsonGetReq req = new ArticleList0JsonGetReq();
                    req.name = "123";
                    req.pass = "123";
                    String response = client.articleList0JsonGet(req);
                    if (response != null) {
                        showToast(20210715, response);
                    }
                } catch (RpcException e) {
                    e.printStackTrace();// 处理 RPC 请求异常
                    showToast(e.getCode(), e.getMsg());
                    Log.i("RpcException", " GET code: " + e.getCode() + " msg: " + e.getMsg());
                }
            }
        }, "rpc-get");
    }

    private void testPost() {
        taskService.parallelExecute(new Runnable() {
            @Override
            public void run() {
                try {
                    BannerJsonPostReq req = new BannerJsonPostReq();
                    req.password = "222";
                    req.username = "111";
                    String response = client.bannerJsonPost(req);
                    if (response != null) {
                        showToast(20210715, response);
                    }
                } catch (RpcException e) {
                    e.printStackTrace(); // 处理 RPC 请求异常
                    showToast(e.getCode(), e.getMsg());
                    Log.i("RpcException", "POST code: " + e.getCode() + " msg: " + e.getMsg());
                }
            }
        }, "rpc-post");
    }

    private void testLimit() {
        taskService.parallelExecute(new Runnable() {
            @Override
            public void run() {
                try {
                    AccountInfo accountInfo = new AccountInfo();
                    accountInfo.username = "123";
                    accountInfo.password = "123";
                    PostlimitPostReq req = new PostlimitPostReq();
                    req._requestBody = accountInfo;
                    UserInfo userInfo = client.postlimitPost(req);

                    if (userInfo != null) {

                        runOnUiThread(new Runnable() {
                            @Override
                            public void run() {
                                ((TextView) findViewById(R.id.tvLimitTip)).setText(RpcMainActivity.this.getString(R.string.limit_request_Data) + userInfo.name + ", age: " + userInfo.age + ", vipInfo expireTime: " + userInfo.vipInfo.expireTime + ", vipInfo level: " + userInfo.vipInfo.level);
                            }
                        });
                        //showToast(20210715, "LIMIT请求数据 :" + userInfo.name + ", age: " + userInfo.age + ", vipInfo expireTime: " + userInfo.vipInfo.expireTime + ", vipInfo level: " + userInfo.vipInfo.level);
//                        showToast(20210715,userInfo.name + ", age: " + userInfo.age + ", vipInfo expireTime: " + userInfo.vipInfo.expireTime + ", vipInfo level: " + userInfo.vipInfo.level);
                    }
                } catch (RpcException e) {
                    e.printStackTrace();// 处理 RPC 请求异常
                    showToast(e.getCode(), e.getMsg());
                    runOnUiThread(new Runnable() {
                        @Override
                        public void run() {
                            ((TextView) findViewById(R.id.tvLimitTip)).setText("limit code: " + e.getCode() + " msg: " + e.getMsg());
                        }
                    });
//                    Log.i("RpcException", "limit code: " + e.getCode() + " msg: " + e.getMsg());
                }
            }
        }, "rpc-post-limit");
    }

    private void testWeights() {
        taskService.parallelExecute(new Runnable() {
            @Override
            public void run() {
                try {
                    String result = client.weightsGet();
                    if (result != null) {
                        showToast(20210715, result);
                    }
                } catch (RpcException e) {
                    e.printStackTrace(); // 处理 RPC 请求异常
                    showToast(e.getCode(), e.getMsg());
                    Log.i("RpcException", "weightsGet code: " + e.getCode() + " msg: " + e.getMsg());
                }
            }
        }, "rpc-dynamic-weight");
    }

    private void testException() {
        taskService.parallelExecute(new Runnable() {
            @Override
            public void run() {
                try {
                    String result = client.exceptionGet();
                    if (result != null) {
                        showToast(20210715, result);
                    }
                } catch (RpcException e) {
                    e.printStackTrace();// 处理 RPC 请求异常
                    showToast(e.getCode(), e.getMsg());
                    Log.i("RpcException", "exceptionGet code: " + e.getCode() + " msg: " + e.getMsg());
                }
            }
        }, "rpc-exception");
    }

    private void testEndorsed() {
        taskService.parallelExecute(new Runnable() {
            @Override
            public void run() {
                try {
                    //加入未加签设置
                    RpcService rpcService = LauncherApplicationAgent.getInstance()
                            .getMicroApplicationContext().findServiceByInterface(RpcService.class.getName());

                    RpcDemoClient demoClient = rpcService.getRpcProxy(RpcDemoClient.class);
                    RpcInvokeContext context = rpcService.getRpcInvokeContext(demoClient);
                    context.setNeedSignature(false);

                    String result = client.wxarticleChaptersJsonGet();
                    if (result != null) {
                        showToast(20210715, result);
                    }
                } catch (RpcException e) {
                    e.printStackTrace();// 处理 RPC 请求异常
                    showToast(e.getCode(), e.getMsg());
                    Log.i("RpcException", "endorsed code: " + e.getCode() + " msg: " + e.getMsg());
                }
            }
        }, "rpc-endorsed");
    }

    private void showToast(final int code, final String msg) {
        runOnUiThread(new Runnable() {
            @Override
            public void run() {
                if (code == 20210715) {
                    Toast.makeText(RpcMainActivity.this, msg, Toast.LENGTH_SHORT).show();
                } else {
                    String error = "CODE : " + code + "\nMSG : " + msg;
                    Toast.makeText(RpcMainActivity.this, error, Toast.LENGTH_SHORT).show();
                }
            }
        });
    }

}