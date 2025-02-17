import { TitleComponent } from '../component/TitleComponent';
import { ConfigChangeListener, MPConfigService } from '@mpaas/configservice';
import { List } from '@kit.ArkTS';
import { Constants } from '../constants/Constants';
import { BannerModel } from '../rpc/EntityModel';
import RouterManager from '../constants/RouterManager';
import { BaseTitleComponent } from 'library/Index';

@Builder
export function getPageConfig(): void {
  PageConfig()
}

@Component
export struct PageConfig {
  @State message: string = '';

  onBackPress(): boolean | void {
    let bannerModel = new BannerModel()
    bannerModel.desc = "开关回执传参"
    RouterManager.pop(bannerModel, true)
  }

  build() {
    NavDestination() {
      Flex({ direction: FlexDirection.Column }) {
        BaseTitleComponent({
          title: "开关配置",
          leftClickEvent: (): void => {
            let bannerModel = new BannerModel()
            bannerModel.desc = "开关回执传参"
            RouterManager.pop(bannerModel, true)
          }
        })
        Scroll() {
          Column() {
            Text(`本地开关值：${this.message}`)
              .fontSize(16)
            Button("获取本地开关")
              .fontSize(16)
              .margin({ top: 10 })
              .fontWeight(FontWeight.Bold)
              .onClick(() => {
                this.message = MPConfigService.getConfig("test")
              })
            Button("获取远程开关")
              .fontSize(16)
              .margin({ top: 10 })
              .fontWeight(FontWeight.Bold)
              .onClick(() => {
                MPConfigService.loadConfig()
              })
            Button("立即刷新")
              .fontSize(16)
              .margin({ top: 10 })
              .fontWeight(FontWeight.Bold)
              .onClick(() => {
                // 触发刷新，立刻刷新
                MPConfigService.loadConfigImmediately()
              })
            Button("添加监听")
              .fontSize(16)
              .margin({ top: 10 })
              .fontWeight(FontWeight.Bold)
              .onClick(() => {
                MPConfigService.addConfigChangeListener("myFilter", new MyListener())
              })
            Button("移除监听")
              .fontSize(16)
              .margin({ top: 10 })
              .fontWeight(FontWeight.Bold)
              .onClick(() => {
                MPConfigService.removeConfigChangeListener("myFilter")
              })
            Button("打开小程序")
              .fontSize(16)
              .margin({ top: 10 })
              .fontWeight(FontWeight.Bold)
              .onClick(() => {
                let bannnerModel: BannerModel = new BannerModel()
                bannnerModel.desc = "this params from PageMini"
                let navPathInfo = new NavPathInfo("PageMini", bannnerModel, (popinfo: PopInfo) => {
                  let result = popinfo.result as BannerModel
                  console.info(Constants.TAG, `回执传参：${JSON.stringify(result)}`)
                })
                RouterManager.pushPath(navPathInfo, true)
              })
          }
        }
        .backgroundColor(0xDCDCDC)
        .scrollable(ScrollDirection.Vertical) // 滚动方向为垂直方向
        .scrollBar(BarState.On) // 滚动条常驻显示
        .scrollBarColor(Color.Gray) // 滚动条颜色
        .scrollBarWidth(10) // 滚动条宽度
        .edgeEffect(EdgeEffect.Spring) // 滚动到边沿后回弹
        .height('100%')
        .width('100%')
      }
      .width('100%')
      .height('100%')
    }
    .hideTitleBar(true)
    .onReady(ctx => {
      let bannerModel = ctx.pathInfo.param as BannerModel
      if (bannerModel) {
        console.info(Constants.TAG, `跳转传参：${JSON.stringify(bannerModel)}`)
      }
    })
  }
}

class MyListener implements ConfigChangeListener {
  getKeys(): List<string> {
    let filter = new List<string>()
    filter.add("test")
    return filter;
  }

  onConfigChange(key: string, value: string): void {
    // 这里通知开关有变化
    console.log(Constants.TAG, `${key}有变化，值为${value}`)
  }
}
