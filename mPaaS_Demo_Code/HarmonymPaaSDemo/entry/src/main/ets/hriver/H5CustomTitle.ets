import { AppManager, AppNode, CommonEvents, getProxy, Page, TitleBarData, XRiverProxy } from '@mpaas/hriver'
import { BannerModel } from '../rpc/EntityModel'
import { promptAction, router } from '@kit.ArkUI'
import { curSystemStatusBarHeight } from '../constants/Global'

@Builder
export function CustomUIBuilder(name: string, p: Page) {
  if (name === 'titleBar') {
    CustomTitleBarComponent({ titleBarData: p.titleBarData, page: p })
  }
}

@Component
export struct CustomTitleBarComponent {
  @Prop titleBarData: TitleBarData
  page: Page | null = null

  aboutToAppear(): void {
    this.titleBarData.showTitleBar = false
    this.titleBarData.showBottomLine = false
  }

  build() {
    //目前开启沉浸式后，需要把导航栏隐藏掉，然后自己在离线包内部自己处理导航栏。这是一个已知问题，目前只能这么处理。
    Column() {
      Text()
        .backgroundColor(Color.Red)
        .width('100%')
        .height(`${curSystemStatusBarHeight()}px`)
      //判断是否显示导航栏
      if (this.titleBarData.showTitleBar) {
        Row() {
          //判断是否显示返回键
          if (this.titleBarData.showBackButton) {
            Image($r("app.media.ic_back_white"))
              .width('48')
              .height('48')
              .objectFit(ImageFit.None)
              .backgroundColor(Color.Black)
              .onClick(() => {
                promptAction.showToast({
                  message: "点击了自定义导航栏返回按钮"
                })
                // this.page?.sendEvent("h5ToolbarBack")
                //针对this.$router.push的跳转方式
                if (this.page?.webcontroller?.accessBackward()) {
                  this.page?.webcontroller?.backward()
                } else {
                  router.back()
                }

                //mPaaS跳转方式
                // this.page?.backClickEvent()
              })
          }
          if (this.titleBarData.showCloseBtn){
            Text(" X ")
              .fontSize('30')
              .fontColor(Color.White)
          }
          Text(this.titleBarData.title)
            .fontSize('16')
            .fontColor(Color.White)
          if (this.titleBarData.customData != undefined) {
            Text((this.titleBarData.customData as BannerModel).desc)
              .fontSize('16')
              .fontColor(Color.White)
              .backgroundColor(Color.Green)
          }
          if (this.titleBarData.customData != undefined) {
            Text(this.titleBarData.customData['imgUrl'])
              .fontSize('16')
              .fontColor(Color.White)
              .width(40)
              .height(40)
              .backgroundColor(Color.Yellow)
          }
          Image($r("app.media.startIcon"))
            .width('48')
            .height('48')
            .objectFit(ImageFit.None)
            .onClick(() => {
              //自定义action
              this.page?.sendToWeb('testAction', { data: 'native sendtoweb 啊啊啊啊' })
              //内部action
              // this.page?.sendEvent()
            })
            .backgroundColor(Color.Red)
        }
        .justifyContent(FlexAlign.SpaceAround)
        .backgroundColor(Color.Blue)
        .width('100%')
        .height('48')
      }
    }
  }
}


@Builder
export function CustomUIBuilder0(name: string, p: Page) {
  if (name === 'titleBar') {
    CustomTitleBarComponent0({ titleBarData: p.titleBarData, page: p })
  }
}

@Component
export struct CustomTitleBarComponent0 {
  @Prop titleBarData: TitleBarData
  page: Page | null = null

  build() {
    Row()
      .width('0')
      .height('0')
  }
}