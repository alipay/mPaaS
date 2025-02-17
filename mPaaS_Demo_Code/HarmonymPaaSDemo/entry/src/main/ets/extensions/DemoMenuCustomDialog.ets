import { CRVPage } from '@mpaas/nebulaintegration'
import { TinyMenuButtonState, TinyMenuState } from '@mpaas/xriverohos'
import { window } from '@kit.ArkUI'
import { AUCustomIcon } from '@mpaas/antui'
import { Constants } from '../constants/Constants'

@CustomDialog
export struct DemoMenuCustomDialog {
  @ObjectLink tinyMenuState: TinyMenuState
  customDialogController?: CustomDialogController
  @State isFullScreen: boolean = false
  @State paddingBottom: Length = 0
  page?: CRVPage

  aboutToAppear(): void {
    window.getLastWindow(getContext(this)).then((win: window.Window) => {
      this.isFullScreen = win.getWindowProperties().isLayoutFullScreen
      let area = win.getWindowAvoidArea(window.AvoidAreaType.TYPE_NAVIGATION_INDICATOR
      )
      if (area.visible && area.bottomRect.height > 0) {
        this.paddingBottom = px2vp(area.bottomRect.height)
      }
    })
    console.info(Constants.TAG, `小程序page:${this.page?.getPageData().getPageUrl()}`)
    let pageUrl = this.page?.getPageData().getPageUrl()
    if (pageUrl) {
      //这里根据url来显示不同菜单栏
      this.tinyMenuState.appName = "自定义模版"
      let model1 = new TinyMenuButtonState()
      model1.title = "顶部分享"
      model1.image = $r('app.media.loading_page_icon')
      let arrayTop: Array<TinyMenuButtonState> = [model1]
      this.tinyMenuState.tinyMenuButtonStateArrayTop = arrayTop

      let model2 = new TinyMenuButtonState()
      model2.title = "底部分享"
      model2.image = $r('app.media.loading_page_icon')
      let arrayBottom: Array<TinyMenuButtonState> = [model2]
      this.tinyMenuState.tinyMenuButtonStateArrayBottom = arrayBottom
    }
  }

  build() {
    Column() {
      Row() {
        Image(this.tinyMenuState.appIconImageUrl)
          .width((this.tinyMenuState.appIconImageUrl && this.tinyMenuState.appIconImageUrl.length > 0) ? '35vp' : '2vp')
          .height('35vp')
          .borderRadius('50vp')
          .borderWidth('0px')
          .margin({
            top: '18vp',
            right: '8vp',
            left: '16vp',
            bottom: '18vp',
          })
        Text(this.tinyMenuState.appName)
          .fontSize(16)
          .fontStyle(FontStyle.Normal)
          .fontWeight(FontWeight.Bold)
          .fontColor('#333333')
      }
      .width('100%')
      .alignItems(VerticalAlign.Center)

      // Divider
      Row() {
        Row()
          .width('100%')
          .height('1px')
          .backgroundColor('#cccccc')
      }
      .width('100%')
      .margin({
        top: 0,
        right: '16vp',
        bottom: 0,
        left: '16vp'
      })

      // Top tiny menu buttons
      Row() {
        ForEach(
          this.tinyMenuState.tinyMenuButtonStateArrayTop,
          (tinyMenuButtonState: TinyMenuButtonState, index: number) => {
            TinyMenuButtonComponent({
              tinyMenuButtonState: tinyMenuButtonState,
              menuButtonOnClickListener: new MenuButtonOnClickListener((mid: string): void => {
                // Close this dialog first
                this.customDialogController?.close()
                // Trigger click event logic
                if (this.tinyMenuState.menuButtonOnClickListener) {
                  this.tinyMenuState.menuButtonOnClickListener(mid)
                }
              })
            }

            )
          }

        )
      }.width('100%')
      .height('95vp')

      // Bottom tiny menu buttons
      Scroll(new Scroller()) {
        Row() {
          ForEach(this.tinyMenuState.tinyMenuButtonStateArrayBottom,
            (tinyMenuButtonState: TinyMenuButtonState, index: number) => {
              TinyMenuButtonComponent({
                tinyMenuButtonState: tinyMenuButtonState,
                menuButtonOnClickListener: new MenuButtonOnClickListener(
                  (mid: string): void => {
                    // Close this dialog first
                    this.customDialogController?.close()
                    // Trigger click event logic
                    if (this.tinyMenuState.menuButtonOnClickListener) {
                      this.tinyMenuState.menuButtonOnClickListener(mid)
                    }
                  })
              })
            })
        }

        .height('95vp')
      }

      .scrollable(ScrollDirection.Horizontal)
      .scrollBar(BarState.Off)
      .width('100%')
      .align(Alignment.Start)

      Text('取消')
        .fontSize(18)
        .fontStyle(FontStyle.Normal)
        .fontColor('ff333333')
        .backgroundColor('#FFFFFF')
        .width('100%')
        .height('57vp')
        .textAlign(TextAlign.Center)
        .onClick((event: ClickEvent) => {
          this.customDialogController?.close()
        })
      Row()
        .width('100%')
        .height(this.isFullScreen ? this.paddingBottom : 0)
        .backgroundColor('#FFFFFF')
    }
    .width('100%')
    .backgroundColor('#fff5f4f3')
    .borderRadius({
      topLeft: '12vp',
      topRight: '12vp',
      bottomLeft: 0,
      bottomRight: 0
    })
  }
}

/**
 * Menu button in the tiny menu.
 */
@Component
struct TinyMenuButtonComponent {
  @ObjectLink tinyMenuButtonState: TinyMenuButtonState
  @ObjectLink menuButtonOnClickListener: MenuButtonOnClickListener

  build() {
    Column() {
      // Icon
      Row() {
        // Image
        Image(this.tinyMenuButtonState.image)
          .width('26vp')
          .height('26vp')
          .visibility(this.tinyMenuButtonState.image ? Visibility.Visible
            : Visibility.None)
          .objectFit(ImageFit.Contain)
        // Iconfont
        AUCustomIcon({
          text: this.tinyMenuButtonState.iconfont,
          // fontSrc: $rawfile('tiny_iconfont.ttf'),
          fontSrc: "",
          fontSize: 26,
          fontColor: this.tinyMenuButtonState.iconfontColor
        })
          .visibility(this.tinyMenuButtonState.image ? Visibility.None :
          Visibility.Visible)
          .align(Alignment.Center)
      }
      .width('45vp')
      .height('45vp')
      .backgroundColor('#ffffff')
      .borderRadius('10vp')
      .borderStyle(BorderStyle.Solid)
      .borderWidth(0)
      .alignItems(VerticalAlign.Center)
      .justifyContent(FlexAlign.Center)

      // Title
      Text(this.tinyMenuButtonState.title)
        .fontColor('#333333')
        .fontSize('10vp')
        .margin({
          top: '2vp'
        })
        .maxLines(2)
        .ellipsisMode(EllipsisMode.END)
    }
    .width('65vp')
    .justifyContent(FlexAlign.Center)
    .onClick((clickEvent: ClickEvent): void => {
      if (this.menuButtonOnClickListener.onClickListener) {
        this.menuButtonOnClickListener.onClickListener(this.tinyMenuButtonState.mid)
      }
    })
  }
}

@Observed
class MenuButtonOnClickListener {
  public onClickListener: ((mid: string) => void) | undefined

  public constructor(onClickListener: ((mid: string) => void) | undefined
  ) {
    this.onClickListener = onClickListener
  }
}