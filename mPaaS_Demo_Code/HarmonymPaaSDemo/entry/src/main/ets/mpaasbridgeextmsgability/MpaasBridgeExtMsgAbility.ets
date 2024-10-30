import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { window } from '@kit.ArkUI';
import { MpaasExtDefaultNcAbility } from '@mpaas/push';
import { data } from '@kit.TelephonyKit';
import { emitter } from '@kit.BasicServicesKit';
import { Constants } from '../constants/Constants';

export default class MpaasBridgeExtMsgAbility extends MpaasExtDefaultNcAbility {
  async onCreate(): Promise<void> {
    // 收到eventId为9999的事件后执行回调函数
    emitter.on({
      eventId: 1
    }, (data) => {
      if (data.data != null) {
        console.info(Constants.TAG, "onCreate receivedMsg=" + JSON.stringify(data.data["receivedMsg"]))
      } else {
        console.info(Constants.TAG, "onCreate receivedMsg=" + data.data)
      }
    });
    await super.onCreate()
  }
}
