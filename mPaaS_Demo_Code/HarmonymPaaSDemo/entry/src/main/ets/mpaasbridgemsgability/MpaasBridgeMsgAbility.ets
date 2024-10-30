import { Ability, AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { window } from '@kit.ArkUI';
import { MpaasNcAbility } from '@mpaas/push';
import { BusinessError } from '@kit.BasicServicesKit';
import { Constants } from '../constants/Constants';

export default class MpaasBridgeMsgAbility extends MpaasNcAbility {
  static tag: string = "MpaasBridgeMsgAbility"

  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
    super.onCreate(want, launchParam)
    console.info(Constants.TAG,`start MpaasBridgeMsgAbility onCreate`)
  }

  onForeground() {
    console.info(Constants.TAG,`MpaasBridgeMsgAbility onBackground`)
    try {
      // 销毁掉中间过渡的Ability
      this.context.terminateSelf((err: BusinessError) => {
        if (err.code) {
          // 处理业务逻辑错误
          console.error(Constants.TAG, `terminateSelf failed, code is ${err.code}, message is ${err.message}`);
          return;
        }
        // 执行正常业务
        console.info(Constants.TAG,'terminateSelf succeed');
      });
    } catch (err) {
      // 捕获同步的参数错误
      let code = (err as BusinessError).code;
      let message = (err as BusinessError).message;
      console.error(Constants.TAG, `terminateSelf failed, code is ${code}, message is ${message}`);
    }
  }
}