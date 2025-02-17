import { BaseTitleComponent } from './Base/BaseTitleComponent';
import { ConnectionListener } from '@mpaas/sync_service/Index';
import { ConnectionEvent } from '@mpaas/sync_service/Index';
import { ConnectionType } from '@mpaas/sync_service/Index';
import { MPSync } from '@mpaas/sync_service/Index';
import { ISyncCallback } from '@mpaas/sync_service/Index';
import { SyncMessage } from '@mpaas/sync_service/Index';
import { SyncCommand } from '@mpaas/sync_service/Index';

let hasInit = false;

@Entry
@Component
struct OtherPageSync {
  @State message: string = 'Hello World';
  @State connectionMsg: string = '未知';
  connectListener: ConnectionListener = {
    onConnectionStateChanged: (connectionEvent: ConnectionEvent) => {
      let type = connectionEvent.getEventType();
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
    }
  }

  onPageShow(): void {
    if (!hasInit) {
      MPSync.initialize();
      hasInit = true;
    }
    MPSync.appToForeground();
    MPSync.addConnectionListener(this.connectListener)
  }

  onPageHide(): void {
    MPSync.appToBackground();
    MPSync.removeConnectionListener(this.connectListener)
  }

  callBack: ISyncCallback = {
    onReceiveMessage: (message: SyncMessage): void => {
      let msg = message.msgData;
      this.message = msg;
      MPSync.reportMsgReceived(message)
    },
    onReceiveCommand: (command: SyncCommand): void => {

    }
  }

  build() {
    Flex({ direction: FlexDirection.Column }) {
      BaseTitleComponent({ title: "Base数据同步" })
      Scroll() {
        Column() {
          Text(`返回数据:${this.message}`)
            .fontSize(16)
          Text(`连接状态:${this.connectionMsg}`)
            .fontSize(16)
          Button("绑定用户")
            .fontSize(16)
            .margin({ top: 10 })
            .fontWeight(FontWeight.Bold)
            .onClick(() => {
              MPSync.updateUserInfo("harmony_session")
            })
          Button("注册biz")
            .fontSize(16)
            .margin({ top: 10 })
            .fontWeight(FontWeight.Bold)
            .onClick(() => {
              MPSync.registerBiz("oneUserSync", this.callBack) //注册biz，
            })
          Button("解绑")
            .fontSize(16)
            .margin({ top: 10 })
            .fontWeight(FontWeight.Bold)
            .onClick(() => {
              MPSync.clearUserInfo()
              MPSync.unregisterBiz("oneUserSync") //注册biz，
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
}