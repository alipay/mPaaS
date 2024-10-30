import { AbilityConstant, common, UIAbility, Want } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { promptAction, window } from '@kit.ArkUI';
import { Constants } from '../constants/Constants';
import { BusinessError } from '@kit.BasicServicesKit';
import { curSystemStatusBarHeight, setContext, setSystemStatusBarHeight, setWindowStage } from '../constants/Global';
import { HRiver } from '@mpaas/hriver';
import { getWindowAvoidArea, setUIAbilityContext } from '../constants/Global';
import { RpcDemoClient } from '../rpc/RpcDemoClient';
import { REQ_MODEL } from '../rpc/REQ_MODEL';
import { BannerJsonPostReq } from '../rpc/BannerJsonPostReq';
import { BannerArrayModel } from '../rpc/EntityModel';

export default class EntryAbility extends UIAbility {
  private windowObj?: window.Window

  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onCreate');
    setUIAbilityContext(this.context)
  }

  onDestroy(): void {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onDestroy');
  }

  onWindowStageCreate(windowStage: window.WindowStage): void {
    getWindowAvoidArea(this.context).then(area => {
      setSystemStatusBarHeight(area?.topRect.height!!)
      console.info(Constants.TAG, `状态栏高度：${curSystemStatusBarHeight()}`)
    })
    // Main window is created, set main page for this ability
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onWindowStageCreate');
    //沉浸式
    windowStage.getMainWindow().then((window) => {
      window.setWindowLayoutFullScreen(true)
    })
    setWindowStage(windowStage)

    //全屏扫码
    let isLayoutFullScreen = true;
    try {
      this.windowObj?.setWindowLayoutFullScreen(isLayoutFullScreen, (err: BusinessError) => {
        const errCode: number = err.code;
        if (errCode) {
          console.error('Failed to set the window layout to full-screen mode. Cause:' + JSON.stringify(err));
          return;
        }
        console.info('Succeeded in setting the window layout to full-screen mode.');
      });
    } catch (exception) {
      console.error('Failed to set the window layout to full-screen mode. Cause:' +
      JSON.stringify(exception));
    }

    windowStage.loadContent(Constants.PAGE_SPLASH, (err, data) => {
      if (err.code) {
        hilog.error(0x0000, 'testTag', 'Failed to load the content. Cause: %{public}s', JSON.stringify(err) ?? '');
        return;
      }
      hilog.info(0x0000, 'testTag', 'Succeeded in loading the content. Data: %{public}s', JSON.stringify(data) ?? '');
    });
  }

  onWindowStageDestroy(): void {
    // Main window is destroyed, release UI related resources
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onWindowStageDestroy');
  }

  onForeground(): void {
    // Ability has brought to foreground
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onForeground');
  }

  onBackground(): void {
    // Ability has back to background
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onBackground');
  }


  //post
  rpcPost() {
    let userName: string = "aaa"
    let passWord: string = "bbb"
    //构造请求类
    let client = new RpcDemoClient()
    //构造请求体
    let reqModel: REQ_MODEL = {
      userName: userName,
      password: passWord
    }
    let bannerJsonPostReq: BannerJsonPostReq = {
      _mPaaSCustomBody: reqModel
    }
    //调用请求方法
    client.bannerJsonPost(bannerJsonPostReq).then((result: BannerArrayModel) => {
      promptAction.showToast({
        message:`${JSON.stringify(JSON.stringify(result))}`
      })
    }).catch((e: Error) => {
      //通过e.message可以拿到具体的报错原因
      promptAction.showToast({
        message:`${JSON.stringify(JSON.stringify(e))}`
      })
    });
  }
}
