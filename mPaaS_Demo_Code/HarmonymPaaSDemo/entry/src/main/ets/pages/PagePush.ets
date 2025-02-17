import { Constants } from '../constants/Constants';
import { CallResp, MpaasPushServiceImpl, MPPush } from '@mpaas/push';
import { MPFramework } from '@mpaas/framework';

@Entry
@Component
struct PagePush {
  scroller: Scroller = new Scroller()
  @State message: string = 'Hello World';
  @State tokenVal: string = '';
  @State bindState: string = '';

  async bindIdAndToken() {
    // token 就是 init 方法返回的 token 值
    // 其中 phoneNumber 可以为空
    console.info(Constants.TAG, `push绑定前打印  ${this.tokenVal}`)
    let res: CallResp = await MpaasPushServiceImpl.getInstance().bind(this.tokenVal,"15501196165")
    console.log("bind res=" + res.msg)
    if (res.success) {
      this.bindState = "绑定成功"
      console.info(Constants.TAG, `绑定成功`)
    } else {
      this.bindState = `绑定失败 ${res.code}  ${res.msg}`
      console.info(Constants.TAG, `绑定失败 ${res.code}  ${res.msg}`)
    }
  }

  async unbindIdAndToken() {
    // token 就是 init 方法返回的 token 值
    let res: CallResp = await MpaasPushServiceImpl.getInstance().unbind(this.tokenVal)
    console.log("unbind res=" + res.msg)
    if (res.success) {
      this.bindState = "解绑成功"
      console.info(Constants.TAG, `解绑成功`)
    } else {
      this.bindState = `解绑失败 ${res.code}  ${res.msg}`
      console.info(Constants.TAG, `解绑失败 ${res.code}  ${res.msg}`)
    }
  }

  async initPush() {
    let tokenGet: CallResp
    try {
      tokenGet = await MPPush.init()
      console.info(Constants.TAG, "CallResp=" + tokenGet)
      if (tokenGet.success) {
        this.tokenVal = tokenGet.msg
        this.bindState = `push初始化成功：${this.tokenVal}`
        console.info(Constants.TAG, `push初始化成功：${this.tokenVal}`)
      } else {
        this.bindState = `push初始化失败：${tokenGet.msg}  ${tokenGet.code}`
        console.info(Constants.TAG, `push初始化失败：${tokenGet.msg}  ${tokenGet.code}`)
      }
    } catch (e) {
      this.bindState = `push初始化异常：${e.message}`
      console.info(Constants.TAG, `push初始化异常：${e.message}`)
    }
  }

  build() {
    Row() {
      Scroll(this.scroller) {
        Column() {
          Button("初始化")
            .fontSize(16)
            .margin({ top: 10 })
            .width('80%')
            .fontWeight(FontWeight.Bold)
            .onClick(() => {
              this.initPush();
            })
          Button("绑定id和token")
            .fontSize(16)
            .margin({ top: 10 })
            .width('80%')
            .fontWeight(FontWeight.Bold)
            .onClick(() => {
              this.bindIdAndToken()
            })
          Button("解绑id和token")
            .fontSize(16)
            .margin({ top: 10 })
            .width('80%')
            .fontWeight(FontWeight.Bold)
            .onClick(() => {
              this.unbindIdAndToken()
            })
          Text(`${this.bindState}`)
            .margin({ top: 10 })
            .height(300)
            .width('90%')
            .borderWidth(2)
            .borderColor(Color.Blue)
            .textAlign(TextAlign.Start)

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