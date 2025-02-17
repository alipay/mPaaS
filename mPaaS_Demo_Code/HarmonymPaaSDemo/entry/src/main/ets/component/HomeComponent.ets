import { hilog } from '@kit.PerformanceAnalysisKit';
import { MPFramework } from '@mpaas/framework';
import { Constants } from '../constants/Constants';
import { router } from '@kit.ArkUI';
import { bundleManager, common } from '@kit.AbilityKit';
import RouterManager from '../constants/RouterManager';
import { BannerModel } from '../rpc/EntityModel';

@Component
export struct HomeComponent {
  @State message: string = 'Hello World';
  private context = getContext(this) as common.UIAbilityContext;
  scroller: Scroller = new Scroller()

  async getMpaasUtdid() {
    let udid = await MPFramework.instance.udid;
    console.error(Constants.TAG, "设备标识", udid)
  }

  build() {
    NavDestination() {
      Row() {
        Scroll(this.scroller) {
          Column() {
            Button("harmony基础")
              .fontSize(16)
              .margin({ top: 50 })
              .fontWeight(FontWeight.Bold)
              .width('80%')
              .onClick(() => {
                let bannnerModel: BannerModel = new BannerModel()
                bannnerModel.desc = "this params from PageHarmonyBaase"
                let navPathInfo = new NavPathInfo("PageHarmonyBaase", bannnerModel, (popinfo: PopInfo) => {
                  let result = popinfo.result as BannerModel
                  console.info(Constants.TAG, `回执传参：${JSON.stringify(result)}`)
                })
                RouterManager.pushPath(navPathInfo, true)
              })
            Button("小程序")
              .fontSize(16)
              .margin({ top: 10 })
              .width('80%')
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
            Button("设备标识")
              .fontSize(16)
              .margin({ top: 10 })
              .width('80%')
              .fontWeight(FontWeight.Bold)
              .onClick(() => {
                hilog.error(0, Constants.TAG, "click->设备标识")
                this.getMpaasUtdid()
              })
            Button("扫一扫")
              .fontSize(16)
              .margin({ top: 10 })
              .width('80%')
              .fontWeight(FontWeight.Bold)
              .onClick(() => {
                hilog.error(0, Constants.TAG, "click->扫一扫")
                router.pushUrl({
                  url: Constants.PAGE_SCAN
                }).catch((err: Error) => {
                  console.error(Constants.TAG, `跳转出错 ${err.name}  ${err.message}  ${err.stack?.toString()}`)
                });
              })
            Button("存储")
              .fontSize(16)
              .margin({ top: 10 })
              .width('80%')
              .fontWeight(FontWeight.Bold)
              .onClick(() => {
                let bannnerModel: BannerModel = new BannerModel()
                bannnerModel.desc = "this params from PageDataCenterA"
                let navPathInfo = new NavPathInfo("PageDataCenterA", bannnerModel, (popinfo: PopInfo) => {
                  let result = popinfo.result as BannerModel
                  console.info(Constants.TAG, `回执传参：${JSON.stringify(result)}`)
                })
                RouterManager.pushPath(navPathInfo, true)
              })
            Button("移动网关")
              .fontSize(16)
              .margin({ top: 10 })
              .width('80%')
              .fontWeight(FontWeight.Bold)
              .onClick(() => {
                hilog.error(0, Constants.TAG, "click->移动网关")
                router.pushUrl({
                  url: Constants.PAGE_RPC,
                  params: {
                    userName: "lilin",
                    passWord: "taogev587"
                  }
                }).catch((err: Error) => {
                  hilog.error(0, Constants.TAG, "跳转报错：%{s}", err)
                });
              })
            Button("离线包")
              .fontSize(16)
              .margin({ top: 10 })
              .width('80%')
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
            Button("移动分析")
              .fontSize(16)
              .margin({ top: 10 })
              .width('80%')
              .fontWeight(FontWeight.Bold)
              .onClick(() => {
                hilog.error(0, Constants.TAG, "click->移动分析")
                router.pushUrl({
                  url: Constants.PAGE_LOGGER
                }).catch((err: Error) => {
                  console.log(Constants.TAG, `跳转出错${err}`)
                });
              })
            Button("升级")
              .fontSize(16)
              .margin({ top: 10 })
              .width('80%')
              .fontWeight(FontWeight.Bold)
              .onClick(() => {
                hilog.error(0, Constants.TAG, "click->升级")
                router.pushUrl({
                  url: Constants.PAGE_UPGRADE
                }).catch((err: Error) => {
                  console.log(Constants.TAG, `跳转出错${err}`)
                });
              })
            Button("开关")
              .fontSize(16)
              .margin({ top: 10 })
              .width('80%')
              .fontWeight(FontWeight.Bold)
              .onClick(() => {
                let bannnerModel: BannerModel = new BannerModel()
                bannnerModel.desc = "this params from PageConfig"
                let navPathInfo = new NavPathInfo("PageConfig", bannnerModel, (popinfo: PopInfo) => {
                  let result = popinfo.result as BannerModel
                  console.info(Constants.TAG, `回执传参：${JSON.stringify(result)}`)
                })
                RouterManager.pushPath(navPathInfo, true)
              })
            Button("数据同步")
              .fontSize(16)
              .margin({ top: 10 })
              .width('80%')
              .fontWeight(FontWeight.Bold)
              .onClick(() => {
                hilog.error(0, Constants.TAG, "click->数据同步")
                router.pushUrl({
                  url: Constants.PAGE_SYNC
                }).catch((err: Error) => {
                  console.log(Constants.TAG, `跳转出错${err}`)
                });
              })
            Button("Other数据同步")
              .fontSize(16)
              .margin({ top: 10 })
              .width('80%')
              .fontWeight(FontWeight.Bold)
              .onClick(() => {
                hilog.error(0, Constants.TAG, "click->打开Other数据同步")
                router.pushUrl({
                  url: '@bundle:com.mpaas.harmonydemo/BasicSharedModule/ets/pages/OtherPageSync',
                  params: {
                    userName: "lilin",
                    passWord: "taogev587"
                  }
                }).catch((err: Error) => {
                  console.error(Constants.TAG, `跳转报错 ${err}`)
                });
              })
            Button("获取安全键盘licenc")
              .fontSize(16)
              .margin({ top: 10 })
              .width('80%')
              .fontWeight(FontWeight.Bold)
              .onClick(() => {
                let bundleInfo =
                  bundleManager.getBundleInfoForSelfSync(bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_HAP_MODULE |
                  bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_SIGNATURE_INFO)
                let bundleName = bundleInfo.name
                let fingerprint = bundleInfo.signatureInfo.fingerprint
                let appIdentifier = bundleInfo.signatureInfo.appIdentifier
                console.info(Constants.TAG, "bundleName: " + bundleName)
                console.info(Constants.TAG, "fingerprint: " + fingerprint)
                console.info(Constants.TAG, "appIdentifier: " + appIdentifier)
              })
              .backgroundColor(Color.Gray)
            Button("获取图片fingerPrint")
              .fontSize(16)
              .margin({ top: 10 })
              .width('80%')
              .fontWeight(FontWeight.Bold)
              .onClick(() => {
                let info =
                  bundleManager.getBundleInfoForSelfSync(bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_SIGNATURE_INFO);
                let finger = info.signatureInfo.fingerprint;
                console.info(Constants.TAG, `无线保镖图片：${finger}`)
              })
              .backgroundColor(Color.Gray)
            Button("安全键盘")
              .fontSize(16)
              .margin({ top: 10 })
              .width('80%')
              .fontWeight(FontWeight.Bold)
              .onClick(() => {
                hilog.error(0, Constants.TAG, "click->安全键盘")
                router.pushUrl({
                  url: Constants.PAGE_KEYBOARD
                }).catch((err: Error) => {
                  console.log(Constants.TAG, `跳转出错${err}`)
                });
              })
            Button("消息推送")
              .fontSize(16)
              .margin({ top: 10 })
              .width('80%')
              .fontWeight(FontWeight.Bold)
              .onClick(() => {
                hilog.error(0, Constants.TAG, "click->消息推送")
                router.pushUrl({
                  url: Constants.PAGE_PUSH
                }).catch((err: Error) => {
                  console.log(Constants.TAG, `跳转出错${err}`)
                });
              })
            Button("OCR")
              .fontSize(16)
              .margin({ top: 10 })
              .width('80%')
              .fontWeight(FontWeight.Bold)
              .onClick(() => {
                let bannnerModel: BannerModel = new BannerModel()
                bannnerModel.desc = "this params from PageOcr"
                let navPathInfo = new NavPathInfo("PageOcr", bannnerModel, (popinfo: PopInfo) => {
                  let result = popinfo.result as BannerModel
                  console.info(Constants.TAG, `回执传参：${JSON.stringify(result)}`)
                })
                RouterManager.pushPath(navPathInfo, true)
              })
            Button("测试H5容器加载离线包")
              .fontSize(16)
              .visibility(Visibility.Hidden)
              .margin({ top: 10 })
              .width('80%')
              .fontWeight(FontWeight.Bold)
              .onClick(() => {
                hilog.error(0, Constants.TAG, "click->测试H5容器加载离线包送")
                router.pushUrl({
                  url: Constants.PAGE_H5_CONTAINER
                }).catch((err: Error) => {
                  console.log(Constants.TAG, `跳转出错${err}`)
                });
              })
          }
          .justifyContent(FlexAlign.Start)
          .width('100%')
        }
        .scrollable(ScrollDirection.Vertical) // 滚动方向纵向
        .scrollBar(BarState.On) // 滚动条常驻显示
        .scrollBarColor(Color.Gray) // 滚动条颜色
        .scrollBarWidth(10) // 滚动条宽度
        .edgeEffect(EdgeEffect.None)
      }
      .width('100%')
      .height('100%')
    }
  }
}