import { Ability, AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { window } from '@kit.ArkUI';
import { MpaasNcAbility } from '@mpaas/push';
import { BusinessError } from '@kit.BasicServicesKit';
import { Constants } from '../constants/Constants';

export default class MpaasBridgeMsgAbility extends MpaasNcAbility {
  static tag: string = "MpaasBridgeMsgAbility"
  msgWant: Want | undefined = undefined

  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
    hilog.info(0x0000, MpaasBridgeMsgAbility.tag, "start MpaasBridgeMsgAbility onCreate")
    //如果自己处理跳转，这个去掉
    super.onCreate(want, launchParam)
    this.msgWant = want
  }

  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info("child onWindowStageCreate")
    this.processMessage(this.msgWant)
  }

  processMessage(want?: Want): void {
    // 将 Want 中携带的数据转换为 NotificationInfo
    if (want == null || want.parameters == null) {
      console.error("want is undefined=")
      return;
    }
    let pushData = want.parameters["com_harmony_push"] as JSON
    // let pushAllData = want.parameters as JSON
    let pushDataStr: string = JSON.stringify(pushData);
    console.info(Constants.TAG, `推送消息：${pushDataStr}`)
  }

  onForeground() {
    console.log('MpaasBridgeMsgAbility onForeground');
  }
}