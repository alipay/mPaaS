import { TitleComponent } from '../component/TitleComponent';
import { ConfigChangeListener, MPConfigService } from '@mpaas/configservice';
import { List } from '@kit.ArkTS';
import { Constants } from '../constants/Constants';
import { BannerModel } from '../rpc/EntityModel';
import RouterManager from '../constants/RouterManager';
// import { BaseTitleComponent } from 'library/Index';
import { Page } from '@mpaas/hriver';

@Builder
export function getPageConfig(): void {
  PageConfig()
}

@Component
export struct PageConfig {
  @State message: string = "暂无数据"
  @State isAddListener: boolean = false

  onBackPress(): boolean | void {
    let bannerModel = new BannerModel()
    bannerModel.desc = "开关回执传参"
    RouterManager.pop(bannerModel, true)
  }

  build() {
    NavDestination() {
      Flex({ direction: FlexDirection.Column }) {
        // BaseTitleComponent({
        //   title: "开关配置",
        //   leftClickEvent: (): void => {
        //     let bannerModel = new BannerModel()
        //     bannerModel.desc = "开关回执传参"
        //     RouterManager.pop(bannerModel, true)
        //   }
        // })
        Scroll() {
          Column() {
            Text(`本地开关值：${this.message}`)
              .fontSize(16)
            Button("获取本地开关")
              .fontSize(16)
              .margin({ top: 10 })
              .fontWeight(FontWeight.Bold)
              .backgroundColor(this.isAddListener ? Color.Blue : Color.Gray)
              .enabled(this.isAddListener ? true : false)
              .onClick(() => {
                this.message = MPConfigService.getConfig("harmony_config_key")
              })
            Button("请求远程开关")
              .fontSize(16)
              .margin({ top: 10 })
              .fontWeight(FontWeight.Bold)
              .backgroundColor(this.isAddListener ? Color.Blue : Color.Gray)
              .enabled(this.isAddListener ? true : false)
              .onClick(() => {
                MPConfigService.loadConfig()
              })
            Button("请求远程开关并立即刷新本地的值")
              .fontSize(16)
              .margin({ top: 10 })
              .fontWeight(FontWeight.Bold)
              .backgroundColor(this.isAddListener ? Color.Blue : Color.Gray)
              .enabled(this.isAddListener ? true : false)
              .onClick(() => {
                // 触发刷新，立刻刷新
                MPConfigService.loadConfigImmediately()
              })
            Button("添加监听")
              .fontSize(16)
              .margin({ top: 10 })
              .fontWeight(FontWeight.Bold)
              .backgroundColor(this.isAddListener ? Color.Gray : Color.Blue)
              .onClick(() => {
                this.isAddListener = true
                MPConfigService.addConfigChangeListener("myFilter", new MyListener())
              })
            Button("移除监听")
              .fontSize(16)
              .margin({ top: 10 })
              .fontWeight(FontWeight.Bold)
              .backgroundColor(this.isAddListener ? Color.Blue : Color.Gray)
              .enabled(this.isAddListener ? true : false)
              .onClick(() => {
                MPConfigService.removeConfigChangeListener("myFilter")
              })
            Button("简单示例")
              .fontSize(16)
              .margin({ top: 10 })
              .fontWeight(FontWeight.Bold)
              .backgroundColor(this.isAddListener ? Color.Gray : Color.Blue)
              .onClick(() => {
                let myMyListener = new MyListener()
                myMyListener.onCallBackConfigChange = (key: string, value: string) => {
                  this.message = value
                }
                MPConfigService.addConfigChangeListener("myFilter", myMyListener)
                let valuea = MPConfigService.getConfig("harmony_config_key")
                if (!valuea) {
                  MPConfigService.loadConfig()
                } else {
                  this.message = valuea
                }
              })
            Button("打开小程序")
              .fontSize(16)
              .margin({ top: 10 })
              .fontWeight(FontWeight.Bold)
              .backgroundColor(Color.Blue)
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
  onCallBackConfigChange: Function = (key: string, value: string) => null

  getKeys(): List<string> {
    let filter = new List<string>()
    filter.add("harmony_config_key")
    return filter;
  }

  onConfigChange(key: string, value: string): void {
    // 这里通知开关有变化
    console.log(Constants.TAG, `${key}有变化，值为${value}`)
    // 应该如何在这里修改Component中@state的变量(message)呢？
    if (this.onCallBackConfigChange) {
      this.onCallBackConfigChange(key, value)
    }
  }
}


