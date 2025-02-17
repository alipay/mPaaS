import { MPFramework } from '@mpaas/framework';
import { RPCException, RpcInterceptor, RpcInvokeContext } from '@mpaas/rpc';
import { Constants } from '../constants/Constants';
import { JSON } from '@kit.ArkTS';

export class MyInterceptor implements RpcInterceptor {
  async getMpaasUtdid() {
    let udid = await MPFramework.instance.udid;
    console.error(Constants.TAG, `请求参数-设备标识：${udid}`)
  }

  preHandle(rpcInvokeContext: RpcInvokeContext): boolean {
    //模拟拦截器里添加header
    rpcInvokeContext.addHeader("rpcHeader3","测试header3")
    //模拟添加公共参数
    let requestObj = rpcInvokeContext.getRequestArg()
    requestObj["commonParam"] = "aaaaa"
    console.log(Constants.TAG, `请求参数：${JSON.stringify(requestObj)}`)

    //打印header
    let requestHeaders = rpcInvokeContext.getRequestHeader()
    requestHeaders.forEach((value, key) => {
      console.log(Constants.TAG, `请求头：key:${key}  value:${value}`)
    });

    this.getMpaasUtdid()
    return true;
  }

  postHandle(rpcInvokeContext: RpcInvokeContext): boolean {
    let resultObj = rpcInvokeContext.getLastResultObj()
    console.log(Constants.TAG, `响应参数：${JSON.stringify(resultObj)}`)
    //打印header
    let responseHeaders = rpcInvokeContext.getResponseHeader()
    console.log(Constants.TAG, `响应头:${JSON.stringify(responseHeaders)}  ${responseHeaders['mgw-traceid']}}`)
    return true;
  }

  handleException(rpcInvokeContext: RpcInvokeContext, exception: RPCException): boolean {
    console.log(Constants.TAG, `响应参数:${exception.message}`)
    return false
  }
}