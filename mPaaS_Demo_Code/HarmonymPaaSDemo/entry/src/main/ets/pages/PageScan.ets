import { Constants } from '../constants/Constants';
import { BaseTitleComponent } from 'library/Index';
import { ScanInterface, ScanManager } from '@mpaas/scanapp';
import { promptAction, router } from '@kit.ArkUI';

@Entry
@Component
struct PageScan {
  @State message: string = '';

  onPageShow(): void {
    console.info(Constants.TAG, `scan pageshow`)
  }

  onPageHide(): void {
    console.info(Constants.TAG, `scan pagehide`)
  }

  build() {
    Column() {
      BaseTitleComponent({ title: "扫一扫" })
      Button("跳转系统相机扫一扫")
        .fontSize(16)
        .margin({ top: 10 })
        .fontWeight(FontWeight.Bold)
        .onClick(() => {
          ScanManager.defaultManager(new ScanDefault())
          // router.pushNamedRoute({
          //   name: 'CustomScan',
          //   params: {
          //     hasOptions: true, // 开启相机支持的参数
          //   }
          // })
          router.pushNamedRoute({
            name: 'mPaasScanPage'
          })
        })
    }
    .width('100%')
    .height('100%')
  }
}

const params: Map<string, Object> = new Map()
params.set('showAlbum', true) //是否显示相册入口
params.set('open', '轻触照亮') // 环境提示文案 不超过4个字符
params.set('close', '轻触关闭') // 环境提示文案 不超过4个字符
params.set('more', '多码识别') // 多码识别提示文案
params.set('targetColor', Color.Red) // 命中二维码后 效果颜色

class ScanDefault implements ScanInterface {
  getResult(result: string): void { // 获取扫码结果
    try {
      promptAction.showDialog({
        message: result,
      })
      console.info(Constants.TAG, `scan success:${result}`)
    } catch (error) {
      console.error(Constants.TAG, 'scan fail error = ' + JSON.stringify(error))
    }
    //这里处理路由逻辑
    //router.back()
    router.pushUrl({
      url: Constants.PAGE_LOGIN_CALLBACK
    }).catch((err: Error) => {
      console.error(Constants.TAG, "跳转报错：%{s}", err)
    });
  }

  customParams?: Map<string, Object> | undefined = params
}
