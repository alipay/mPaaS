import { AUCustomIcon, AUIcon, IconFontKey } from '@mpaas/antui';
import { CRVPage } from '@mpaas/nebulaintegration';

import { CapsuleState, FrontColor, NavigationBarState, NavigationBarUtils } from '@mpaas/xriverohos';

@Component
export struct DemoNavComponent {
  page ?: CRVPage // 当前page
  needHideBackButton: boolean = false; // 是否显示返回键
  @ObjectLink navigationBarState: NavigationBarState // 标题栏数据

  aboutToAppear(): void {
  }

  aboutToDisappear() {
  }

  build() {
    Row() {
      // Back button
      if (!this.needHideBackButton) {
        Button({
          type: ButtonType.Normal,
          stateEffect: true
        }) {
          AUIcon({
            icon: IconFontKey.ICONFONT_BACK,
            fontSize: 22,
            fontColor: this.navigationBarState.backButtonIconColor
          })
            .margin({
              top: 11,
              right: 2,
              bottom: 11,
              left: 0
            })
            .onAreaChange((oldValue: Area, newValue: Area): void => {
              this.navigationBarState.backButtonIconArea = newValue
            })
        }
        .visibility((this.navigationBarState.backButtonVisibility === 0) ? Visibility.Visible : Visibility.None)
        .backgroundColor('#00000000')
        .margin({
          top: 0,
          right: 0,
          bottom: 0,
          left: 8
        })
        .onClick((event: ClickEvent) => {
          // 返回键点击
          if (this.navigationBarState.backButtonOnClickListener !== undefined
          ) {
            this.navigationBarState.backButtonOnClickListener(event)
          }
        })
        .onAreaChange((oldValue: Area, newValue: Area): void => {
          this.navigationBarState.backButtonInteractiveArea = newValue
        })
      }
      // Left close button
      Button({
        type: ButtonType.Normal,
        stateEffect: true
      }) {
        AUIcon({
          icon: IconFontKey.ICONFONT_AD_CLOSE,
          fontSize: 22,
          fontColor: this.navigationBarState.leftCloseButtonIconColor
        })
          .margin({
            top: 11,
            right: 5,
            bottom: 11,
            left: 5
          })
      }
      .visibility((this.navigationBarState.leftCloseButtonVisibility === 0) ? Visibility.Visible : Visibility.None)
      .backgroundColor('#00000000')
      .margin({
        top: 0,
        right: 0,
        bottom: 0,
        left: 3
      })
      .onClick((event) => {
        // 关闭按钮
        if (this.navigationBarState.leftCloseButtonOnClickListener !==
          undefined) {
          this.navigationBarState.leftCloseButtonOnClickListener(event)
        }
      })

      // Home button
      Button({
        type: ButtonType.Normal,
        stateEffect: true
      }) {
        AUCustomIcon({
          text: "\ue67d",
          // fontSrc: $rawfile('tiny_iconfont.ttf'),
          fontSrc: "",
          fontSize: 22,
          fontColor: this.navigationBarState.homeButtonIconColor
        })
          .margin({
            top: 11,
            right: 2,
            bottom: 11,
            left: 2
          })
          .onAreaChange((oldValue: Area, newValue: Area): void => {
            this.navigationBarState.homeButtonIconArea = newValue
          })
      }
      .visibility((this.navigationBarState.homeButtonVisibility === 0) ? Visibility.Visible : Visibility.None)
      .backgroundColor('#00000000')
      .margin({
        top: 0,
        right: 0,
        bottom: 0,
        left: 8
      })
      .onClick((event) => {
        // 回到首页按钮点击
        if (this.navigationBarState.homeButtonOnClickListener !== undefined) {
          this.navigationBarState.homeButtonOnClickListener(event)
        }
      })
      .onAreaChange((oldValue: Area, newValue: Area): void => {
        this.navigationBarState.homeButtonInteractiveArea = newValue
      })

      // Title
      Row() {
        Column() {
          // Title text
          Text(this.navigationBarState.titleText)
            .visibility((this.navigationBarState.titleVisibility === 0)
              ? Visibility.Visible : Visibility.None)
            .fontSize(18)
            .fontStyle(FontStyle.Normal)
            .fontColor(this.navigationBarState.titleTextColor)
            .textOverflow({ overflow: TextOverflow.Ellipsis })// .textOverflow({ overflow: TextOverflow.Clip })
            .maxLines(1)
            .onClick((clickEvent: ClickEvent): void => {
              // 标题点击
              if (this.navigationBarState.titleOnClickListener !== undefined) {
                this.navigationBarState.titleOnClickListener(clickEvent
                )
              }
            })
        }
        .alignItems(HorizontalAlign.Start)
      }
      .width(0)
      .layoutWeight(1)
      .margin({
        top: 0,
        right: 0,
        bottom: 0,
        left: ((this.navigationBarState.backButtonVisibility === 1)
          && (this.navigationBarState.leftCloseButtonVisibility === 1)
          && (this.navigationBarState.homeButtonVisibility === 1)) ? 16
          : 6
      })

      // // Placeholder
      // Blank()
      // .layoutWeight(1)
      // Right buttons
      if (this.navigationBarState.capsuleState.visibility === 0) {
        // WTF: Conditional rendering here is not working...
        // Capsule style
        RightButtonComponent({
          capsuleState: this.navigationBarState.capsuleState
        })
          .animation({ duration: 300 })
      }
    }
    .visibility((this.navigationBarState.visibility === 0) ? Visibility.Visible : Visibility.None)
    .width('100%')
    //隐藏导航栏设置0
    .height('0')
    .alignItems(VerticalAlign.Center)
    .justifyContent(FlexAlign.Start)
    .backgroundColor(NavigationBarUtils.alterColorWithAlpha(
      this.navigationBarState.backgroundColor,
      this.navigationBarState.backgroundAlpha))
    .hitTestBehavior(this.navigationBarState.penetrable ? HitTestMode.Transparent : HitTestMode.Default)
    .borderStyle(BorderStyle.Solid)
    .borderWidth({
      top: 0,
      right: 0,
      bottom: (this.navigationBarState.bottomLineVisibility === 0) ? '1px' : 0,
      left: 0
    })
    .borderColor(NavigationBarUtils.alterColorWithAlpha(
      this.navigationBarState.bottomLineColor,
      this.navigationBarState.bottomLineAlpha))
  }
}

@Component
export struct RightButtonComponent {
  aboutToAppear(): void {
  }

  @ObjectLink capsuleState: CapsuleState

  build() {
    // Capsule with more and close buttons
    Row() {
      // More button
      AUIcon({
        icon: this.capsuleState.moreButtonIconfont as IconFontKey,
        fontSize: 22,
        fontColor: (this.capsuleState.frontColor === FrontColor.Black) ?
          '#FF333333' : '#FFFFFFFF'
      })
        .visibility((this.capsuleState.moreButtonVisibility === 0) ? Visibility.Visible : Visibility.None)
        .margin({
          top: '4vp',
          right: '11vp',
          bottom: '4vp',
          left: '11vp'
        })
        .onClick((clickEvent: ClickEvent) => {
          // 更多菜单点击
          if (this.capsuleState.moreButtonOnClickListener !== undefined) {
            this.capsuleState.moreButtonOnClickListener(clickEvent)
          }
        })
      // Divider
      Row()
        .borderStyle(BorderStyle.Solid)
        .borderWidth('1px')
        .borderColor('#1A000000')
        .width('1px')
        .height('22vp')
      // Close button
      AUIcon({
        icon: this.capsuleState.closeButtonIconfont as IconFontKey,
        fontSize: 22,
        fontColor: (this.capsuleState.frontColor === FrontColor.Black) ?
          '#FF333333' : '#FFFFFFFF'
      })
        .visibility((this.capsuleState.closeButtonVisibility === 0) ? Visibility.Visible : Visibility.None
        )
        .margin({
          top: '4vp',
          right: '11vp',
          bottom: '4vp',
          left: '11vp'
        })
        .onClick((clickEvent: ClickEvent) => {
          // 关闭按钮点击
          if (this.capsuleState.closeButtonOnClickListener !== undefined) {
            this.capsuleState.closeButtonOnClickListener(clickEvent)
          }
        })
    }
    .visibility((this.capsuleState.visibility === 0) ? Visibility.Visible
      : Visibility.Hidden)
    .borderStyle(BorderStyle.Solid)
    .borderWidth('1px')
    .borderColor('#1A000000')
    .borderRadius('10000px')
    .backgroundColor(this.capsuleState.frontColor === FrontColor.White ?
      '#16000000' : '#00000000')
    .margin({
      top: '9vp',
      right: '4vp',
      bottom: '9vp',
      left: 0
    })
    .onAreaChange((oldValue: Area, newValue: Area): void => {
      this.capsuleState.capsuleArea = newValue
    })
  }
}