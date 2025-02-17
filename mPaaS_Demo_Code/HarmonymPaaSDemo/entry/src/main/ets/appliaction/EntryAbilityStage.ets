import AbilityStage from '@ohos.app.ability.AbilityStage';
import { MPFramework } from '@mpaas/framework';
import { setStartTime } from '../constants/Global';
import { Constants } from '../constants/Constants';
import { AbilityLifecycleCallback, UIAbility } from '@kit.AbilityKit';
import { getTopAbility, setTopAbility } from '../constants/Global';

export default class EntryAbilityStage extends AbilityStage {
  tokenVal: string = "";

  async onCreate() {
    //记录当前时间戳，用于统计启动耗时
    setStartTime()
    const app = this.context;
    console.log(Constants.TAG, "mPaaS init start")
    MPFramework.create(app).then(() => {
      console.log(Constants.TAG, "mPaaS init finish")
    })
    let abilityLifecycleCallback = {
      onAbilityCreate(ability: UIAbility) {
        console.log(ability + ' onAbilityCreate.');
        setTopAbility(ability)
      },
      onAbilityDestroy(ability: UIAbility) {
        if (getTopAbility() === ability) {
          setTopAbility(undefined)
        }
      },
      onAbilityForeground(ability: UIAbility) {
        console.log(ability + ' onAbilityForeground.');
        setTopAbility(ability)
      },
      onAbilityBackground(ability: UIAbility) {
        console.log(ability + ' onAbilityBackground.');
      },
    } as AbilityLifecycleCallback;
    this.context.getApplicationContext().on("abilityLifecycle", abilityLifecycleCallback)
  }
}