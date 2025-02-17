import { Constants } from '../constants/Constants';
import { HRiverMini } from '@mpaas/hrivermini';
import RouterManager from '../constants/RouterManager';
import { BannerModel } from '../rpc/EntityModel';
import { MYNavigationBarAdapter, TinyAdapterUtils } from '@mpaas/nebulaintegration';
import { DemoNavBarAdapter } from '../extensions/DemoNavBarAdapter';
import { promptAction } from '@kit.ArkUI';

@Builder
export function getPageMini(): void {
  PageMini()
}

@Component
struct PageMini {
  @State message: string = 'Hello World';

  build() {
    NavDestination() {
      Column() {
        Button("远程小程序(无胶囊)")
          .fontSize(16)
          .margin({ top: 50 })
          .fontWeight(FontWeight.Bold)
          .width('80%')
          .onClick(event => {
            TinyAdapterUtils.setProvider(MYNavigationBarAdapter.name, new DemoNavBarAdapter())
            promptAction.showToast({
              message: "开启自定义导航栏，高度为0，隐藏胶囊和导航栏"
            })
            let startParams = new Map<string, Object>()
            startParams.set("query", "aa=bb")
            //这参数只是控制胶囊是否显示，如果要控制二级页的导航栏，需要自定义导航栏
            // startParams.set("disablePresetMenu", "YES")
            HRiverMini.startApp("0000000111111101", startParams)
          })
        Button("远程小程序(自定义菜单栏)")
          .fontSize(16)
          .margin({ top: 10 })
          .fontWeight(FontWeight.Bold)
          .width('80%')
          .onClick(event => {
            TinyAdapterUtils.setProvider(MYNavigationBarAdapter.name, new DemoNavBarAdapter())
            promptAction.showToast({
              message: "开启自定义导航栏，高度为0，隐藏胶囊和导航栏"
            })
            let startParams = new Map<string, Object>()
            startParams.set("query", "aa=bb")
            //这参数只是控制胶囊是否显示，如果要控制二级页的导航栏，需要自定义导航栏
            // startParams.set("disablePresetMenu", "YES")
            HRiverMini.startApp("0000000111111101", startParams)
          })
        Button("远程小程序(有胶囊)")
          .fontSize(16)
          .margin({ top: 10 })
          .fontWeight(FontWeight.Bold)
          .width('80%')
          .onClick(event => {
            TinyAdapterUtils.setProvider(MYNavigationBarAdapter.name, null)
            let startParams = new Map<string, Object>()
            startParams.set("query", "aa=bb")
            HRiverMini.startApp("0000000111111101", startParams)
          })
        Button("远程小程序uni版(有胶囊)")
          .fontSize(16)
          .margin({ top: 10 })
          .fontWeight(FontWeight.Bold)
          .width('80%')
          .onClick(event => {
            // TinyAdapterUtils.setProvider(MYNavigationBarAdapter.name, null)
            let startParams = new Map<string, Object>()
            startParams.set("query", "aa=bb")
            HRiverMini.startApp("8888888888888888", startParams)
          })

        Button("扫一扫")
          .fontSize(16)
          .margin({ top: 10 })
          .fontWeight(FontWeight.Bold)
          .width('80%')
          .onClick(event => {
            let startParams = new Map<string, Object>()
            HRiverMini.scan(getContext(this), startParams)
          })

        Button("打开小程序指定页面")
          .fontSize(16)
          .margin({ top: 10 })
          .fontWeight(FontWeight.Bold)
          .width('80%')
          .onClick(event => {
            let startParams = new Map<string, Object>()
            startParams.set("page", "/page/component/view/view")
            HRiverMini.startApp("0000000111111101", startParams)
          })
        Button("打开离线包")
          .fontSize(16)
          .margin({ top: 10 })
          .fontWeight(FontWeight.Bold)
          .onClick(() => {
            let bannnerModel: BannerModel = new BannerModel()
            bannnerModel.desc = "this params from PageHriver"
            let navPathInfo = new NavPathInfo("PageHriver", bannnerModel, (popinfo: PopInfo) => {
              let result = popinfo.result as BannerModel
              console.info(Constants.TAG, `回执传参：${JSON.stringify(result)}`)
            })
            RouterManager.pushPath(navPathInfo, true)
          })
      }
      .height('100%')
      .width('100%')
    }
    .hideTitleBar(true)
  }
}