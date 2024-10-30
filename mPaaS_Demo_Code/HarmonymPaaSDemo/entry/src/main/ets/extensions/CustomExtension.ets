import {
  ApiBaseExtension,
  BridgeCallback,
  defineJSAPIClass,
  ExtensionParameter,
  MyExtHubContext,
  registerJSAPI,
  required
} from '@mpaas/exthub'
import { EngineUtils, HRiverMiniEngine } from '@mpaas/hrivermini'
import { promptAction } from '@kit.ArkUI'
import { Constants } from '../constants/Constants'
import RouterManager from '../constants/RouterManager'
import { REQ_MODEL } from '../rpc/REQ_MODEL'
import { JSON } from '@kit.ArkTS'

@defineJSAPIClass((): ApiBaseExtension => {
  return new CustomExtension()
})
export class CustomExtension extends ApiBaseExtension {
  /**
   * 小程序调用native 自定义jsapi，并给小程序回执
   * @param param
   * @param context
   * @param callback
   */
  @registerJSAPI
  tinyToNative(@required(ExtensionParameter.CallParameters) param: Record<string, Object>,
    @required(ExtensionParameter.MyExtHubContext) context: MyExtHubContext,
    @required(ExtensionParameter.BridgeCallback) callback: BridgeCallback) {
    //接收小程序数据
    let param1 = param["param1"]
    console.info(Constants.TAG, `this data:${param1} from miniapp`)

    //给小程序回执
    callback.sendSuccessResponse({ message: "this data from native callback" })
    RouterManager.stackInfo()
  }

  /**
   * 小程序调用native 自定义jsapi，native主动给小程序推送消息
   * @param param
   * @param context
   * @param callback
   */
  @registerJSAPI
  tinyToNativeAndNativePushData(@required(ExtensionParameter.CallParameters) param: Record<string, Object>,
    @required(ExtensionParameter.MyExtHubContext) context: MyExtHubContext,
    @required(ExtensionParameter.BridgeCallback) callback: BridgeCallback) {
    //接收小程序数据
    let param1 = param["param1"]
    console.info(Constants.TAG, `this data:${param1} from miniapp`)

    //主动给小程序发消息
    let nativeToMiniData: Record<string, Object> = {
      "data": "this data from native push"
    }
    HRiverMiniEngine.sendToRender(EngineUtils.getPageFromContext(context)?.getRender() || null, 'nativeToTiny',
      nativeToMiniData, {
        onCallBack: (result: Record<string, object>) => {
          console.info(Constants.TAG, JSON.stringify(result))
        }
      })
    RouterManager.stackInfo()
  }
}