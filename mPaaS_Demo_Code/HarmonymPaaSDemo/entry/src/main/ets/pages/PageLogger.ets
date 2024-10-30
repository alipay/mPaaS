import { TitleComponent } from '../component/TitleComponent';
import { HRiver } from '@mpaas/hriver';
import { Constants } from '../constants/Constants';
import { H5CustomPlugin } from '../hriver/H5CustomPlugin';
import { MPRemoteLogger } from '@mpaas/masadapter';
import { getStartConsumeTime } from '../constants/Global';
import { promptAction } from '@kit.ArkUI';

@Entry
@Component
struct PageLogger {
  @State message: string = 'Hello World';

  build() {
    Flex({ direction: FlexDirection.Column }) {
      TitleComponent({ title: "移动分析" })
      Scroll() {
        Column() {
          Button("APP报活")
            .fontSize(16)
            .margin({ top: 10 })
            .fontWeight(FontWeight.Bold)
            .onClick(() => {
              MPRemoteLogger.reportActive();
              promptAction.showToast({ message: `app报活上报成功` })
            })
          Button("App启动速度")
            .fontSize(16)
            .margin({ top: 10 })
            .fontWeight(FontWeight.Bold)
            .onClick(() => {
              let startConsumeTime = getStartConsumeTime()
              MPRemoteLogger.reportStartupTime(startConsumeTime);
              promptAction.showToast({ message: `启动耗时${startConsumeTime}上报成功` })
            })
          Button("自定义埋点")
            .fontSize(16)
            .margin({ top: 10 })
            .fontWeight(FontWeight.Bold)
            .onClick(() => {
              // 可选 param.set('a', 'b');
              let param = new Map<string, string>();
              param['goodsPrice'] = "商品价格"
              param['goodsName'] = "商品名称"
              MPRemoteLogger.logBehavior('biz_event_pay0001', 'pay_goods(自定义事件)', param);
              promptAction.showToast({ message: `自定义埋点记录成功` })
            })
          Button("性能监控(crash、anr、自动化，启动卡死)")
            .fontSize(16)
            .margin({ top: 10 })
            .fontWeight(FontWeight.Bold)
            .onClick(() => {
              MPRemoteLogger.initPerformanceTrack();
              promptAction.showToast({ message: `性能监控初始化完成` })
            })
          Button("强制上报")
            .fontSize(16)
            .margin({ top: 10 })
            .fontWeight(FontWeight.Bold)
            .onClick(() => {
              MPRemoteLogger.uploadAllLog()
              promptAction.showToast({ message: `数据强制上报成功` })
            })
          Button('JS Crash')
            .fontSize(16)
            .margin({ top: 10 })
            .fontWeight(FontWeight.Bold)
            .onClick(() => {
              this.message = "触发JS闪退";
              //触发 JS 错误
              let ary = [1, 2, 3];
              let i = ary[5];
              let res = i.valueOf();
            })
            .width('90%')

          Button('Native Crash')
            .fontSize(16)
            .margin({ top: 10 })
            .fontWeight(FontWeight.Bold)
            .onClick(() => {
              // this.message = "触发Native闪退";
              // // Native Crash
              // console.log('wtf native log start')
              // let res = native.add(1, 2);
              // console.log('wtf native log ' + res)
              // console.log('wtf native log end')
              // let ii = res + 5;
              // console.log('w' + ii);
            })
            .width('90%')
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