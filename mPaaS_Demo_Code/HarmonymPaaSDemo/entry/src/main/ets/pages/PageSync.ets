import { BaseTitleComponent } from 'library/Index';
import { MPFramework } from '@mpaas/framework';
import { Constants } from '../constants/Constants';
import { JSON } from '@kit.ArkTS';
import { promptAction } from '@kit.ArkUI';
import {
  ConnectionEvent,
  ConnectionListener,
  ConnectionType,
  ISyncCallback,
  MPSync,
  SyncCommand,
  SyncMessage
} from '@mpaas/sync_service';

// import { MPUDID } from '@mpaas/udid'
let hasInit = false;

@Entry
@Component
struct PageSync {
  @State message: string = 'Hello World';
  @State connectionMsg: string = '未知';
  connectListener: ConnectionListener = {
    onConnectionStateChanged: (connectionEvent: ConnectionEvent) => {
      let type = connectionEvent.getEventType();
      console.log(Constants.TAG, `onConnectionStateChanged监听到sync状态 ${type}`)

      console.log(Constants.TAG, `sync状态 ${type}`)
      switch (type) {
        case ConnectionType.Connecting:
          this.connectionMsg = "连接中"
          break;
        case ConnectionType.Unknown:
          this.connectionMsg = "未知"
          break;
        case ConnectionType.Connected:
          this.connectionMsg = "已连接"
          break;
        case ConnectionType.Disconnected:
          this.connectionMsg = "已断开"
          break;
        case ConnectionType.ConnectFailed:
          let message = connectionEvent.getExtras();
          this.connectionMsg = message
          break;
      }
      promptAction.showToast({
        message: "connectionMsg为" + this.connectionMsg
      })
    }
  }

  onPageShow(): void {
    if (!hasInit) {
      MPSync.initialize();
      hasInit = true;
    }
    MPSync.addConnectionListener(this.connectListener)
    MPSync.appToForeground();
    //sync
    console.log(Constants.TAG, `sync状态：建联`)
    // this.getUtdid()
    this.getMpaasUtdid()
  }

  async getMpaasUtdid() {
    let udid = await MPFramework.instance.udid;
    console.error(Constants.TAG, "设备标识1", udid)
  }

  // async getUtdid() {
  //   let udid = await MPUDID.getUDID(MPFramework.instance.context)
  //   console.error(Constants.TAG, "设备标识2", udid)
  // }
  onPageHide(): void {
    MPSync.appToBackground();
    MPSync.removeConnectionListener(this.connectListener)
    console.log(Constants.TAG, `sync状态：断链`)
  }

  callBack: ISyncCallback = {
    onReceiveMessage: (value: SyncMessage): void => {
      this.message = JSON.stringify(value);
      console.log(Constants.TAG, `onReceiveMessage：${this.message}}`)
      promptAction.showToast({
        message: `sync状态：${this.message}}`
      })
      MPSync.reportMsgReceived(value)
    },
    onReceiveCommand: (command: SyncCommand): void => {
      this.message = JSON.stringify(command);
      console.log(Constants.TAG, `onReceiveCommand：${this.message}`)
    }
  }

  build() {
    Flex({ direction: FlexDirection.Column }) {
      BaseTitleComponent({ title: "Base数据同步" })
      Scroll() {
        Column() {
          Text(`数据同步依赖于用户信息和配置标识，请一定要绑定用户、注册biz`)
            .fontSize(14)
            .fontColor(Color.Gray)
            .margin({ top: 10 })
          Button("绑定用户")
            .fontSize(16)
            .margin({ top: 10 })
            .fontWeight(FontWeight.Bold)
            .onClick(() => {
              MPFramework.instance.userId = "duofupoc"
              let a = MPSync.updateUserInfo(MPFramework.instance.userId)
              this.connectionMsg = `${this.connectionMsg}\n userid：${MPFramework.instance.userId}\n绑定状态：${a}`
              console.log(Constants.TAG, `userid:${MPFramework.instance.userId}  绑定状态：${a}`)
            })
          Button("注册biz")
            .fontSize(16)
            .margin({ top: 10 })
            .fontWeight(FontWeight.Bold)
            .onClick(() => {
              MPSync.registerBiz("oneUserSync", this.callBack) //注册biz，
              MPSync.registerBiz("bizYT", this.callBack) //注册biz，
              console.log(Constants.TAG, `注册biz`)
              this.connectionMsg = `${this.connectionMsg}\n biz注册成功`
            })
          Button("解绑")
            .fontSize(16)
            .margin({ top: 10 })
            .fontWeight(FontWeight.Bold)
            .onClick(() => {
              MPSync.clearUserInfo()
              MPSync.unregisterBiz("oneUserSync") //注册biz，
              MPSync.unregisterBiz("bizYT") //注册biz，
              this.connectionMsg = `解绑成功`
            })
          Text(`连接状态:${this.connectionMsg}`)
            .fontSize(16)
            .margin({ top: 10 })
          Text(`返回数据:${this.message}`)
            .fontSize(16)
            .margin({ top: 10 })
        }
        .justifyContent(FlexAlign.Start)
        .alignItems(HorizontalAlign.Center)
        .height('100%')
        .width('100%')
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
}