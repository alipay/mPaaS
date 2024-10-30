import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { window } from '@kit.ArkUI';
import { Constants } from '../constants/Constants';

export default class PushLandingAbility extends UIAbility {
  private static TAG: string = "mPaaSLOG"
  private pushData: object = JSON.parse("{}");
  private pushKey: string = "";
  public para: Record<string, string> = {
    'msg_id': "default", 'msg_data': "default"
  };
  public storageData: LocalStorage = new LocalStorage(this.para);
  landingWindowStage: window.WindowStage | undefined = undefined;

  async onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): Promise<void> {
    hilog.info(0x0000, PushLandingAbility.TAG, 'PushLandingAbility create. Data: %{public}s',
      JSON.stringify(want.parameters) ?? '');
    let k: string = ""
    let v: object = JSON.parse("{}")
    if (want.parameters) {
      if (want.parameters["msg_id"]) {
        k = want.parameters["msg_id"] as string
        console.info(Constants.TAG, `onNewWant ${k}`)
      }
      if (want.parameters["msg_data"]) {
        v = want.parameters["msg_data"]
        console.info(Constants.TAG, `onNewWant ${v}`)
      }
    }
    this.storageData.set('msg_id', k)
    this.storageData.set('msg_data', JSON.stringify(v))
    console.info(Constants.TAG, `push_msgkey ${this.storageData.get("msg_id")}`)
    console.info(Constants.TAG, `push_msgdata ${JSON.stringify(this.storageData.get("msg_data"))}`)
  }

  async onNewWant(want: Want, launchParam: AbilityConstant.LaunchParam): Promise<void> {
    let k: string = ""
    let v: object = JSON.parse("{}")
    if (want.parameters) {
      if (want.parameters["msg_id"]) {
        k = want.parameters["msg_id"] as string
        console.info(Constants.TAG, `onNewWant ${k}`)
      }
      if (want.parameters["msg_data"]) {
        v = want.parameters["msg_data"]
        console.info(Constants.TAG, `onNewWant ${v}`)
      }
    }
    this.storageData.set('msg_id', k)
    this.storageData.set('msg_data', JSON.stringify(v))
    console.info(Constants.TAG, `push_msgkey ${this.storageData.get("msg_id")}`)
    console.info(Constants.TAG, `push_msgdata ${JSON.stringify(this.storageData.get("msg_data"))}`)
    if (this.landingWindowStage != null) {
      await this.landingWindowStage.loadContent('pushpages/pushLandingPage', this.storageData)
    }
  }

  onDestroy(): void {
    console.info(Constants.TAG, `onDestroy`)
  }

  async onWindowStageCreate(windowStage: window.WindowStage): Promise<void> { // Main window is created, set main page for this ability
    // 创建新实例并使用给定对象初始化
    this.landingWindowStage = windowStage
    hilog.info(0x0000, PushLandingAbility.TAG, 'this.pushKey= % {public}s', this.storageData.get("msg_id"));
    hilog.info(0x0000, PushLandingAbility.TAG, 'this.pushData= %{public}s',
      JSON.stringify(this.storageData.get("msg_data")));
    try {
      await windowStage.loadContent('pushpages/pushLandingPage', this.storageData)
      console.info(Constants.TAG, `push_msgkey ${this.storageData.get("msg_id")}`)
      console.info(Constants.TAG, `push_msgdata ${JSON.stringify(this.storageData.get("msg_data"))}`)
    } catch (e) {
      console.info(Constants.TAG, `err msg= ${e.message}`)
      return
    }
  }

  onWindowStageDestroy(): void {
    console.info(Constants.TAG, `Ability onWindowStageDestroy`)
  }

  onForeground(): void {
    console.info(Constants.TAG, `Ability onForeground`)
  }

  onBackground(): void {
    console.info(Constants.TAG, `Ability onBackground`)
  }
}

