import { router } from '@kit.ArkUI';
import { REQ_MODEL } from '../rpc/REQ_MODEL';
import { JSON } from '@kit.ArkTS';
import { AppManager, AppNode, getProxy, Page, XRiverProxy } from '@mpaas/hriver';

@Entry
@Component
struct PageLoginCallBack {
  @State message: string = 'Hello World';

  /**
   * 跳转到首页，需要在首页Index中
   */
  callbackResult() {
    let appManager = getProxy(XRiverProxy.AppManager) as AppManager
    let appNode: AppNode | null = appManager.findTopApp()
    if (appNode != null) {
      let page: Page | null = appNode.getActivePage()
      if (page != null) {
        //有效
        let h5Data = page.h5Session?.getData()
        let resultData: REQ_MODEL = {
          userName: "这个api回执必须是字符串",
          password: "1229993"
        }
        h5Data?.set("h5_session_pop_param", JSON.stringify(resultData));

        //有效
        page.sendToWeb('testAction', { data: 'action:testAction  callback:测试数据' })
      }
    }
    router.back()
  }

  build() {
    Column() {
      Column() {
        Image($r('app.media.app_icon'))
          .width(78)
          .height(78)
        Text("登入界面")
          .fontSize(25)
          .margin({ top: 10 })
          .width('100%')
          .textAlign(TextAlign.Center)
          .fontWeight(FontWeight.Bold)
        Text("登录界面使用更多服务")
          .fontSize(16)
          .margin({ top: 5 })
          .width('100%')
          .textAlign(TextAlign.Center)
        Text('模拟超出一行展示省略号模拟超出一行展示省略号模拟超出一行展示省略号模拟超出一行展示省略号模拟超出一行展示省略号模拟超出一行展示省略号')
          .fontSize(16)
          .margin({ top: 5 })
          .maxLines(1)
          .textOverflow({ overflow: TextOverflow.Ellipsis })
        TextInput({ placeholder: "请输入账号" })
          .placeholderColor(Color.Red)
          .type(InputType.Number)
          .margin({ top: 30 })
          .fontSize(16)
          .backgroundColor(Color.White)
        Text()
          .width('100%')
          .height(1)
          .backgroundColor(Color.Black)
        TextInput({ placeholder: "请输入密码" })
          .placeholderColor(Color.Red)
          .type(InputType.Password)
          .fontSize(16)
          .margin({ top: 10 })
          .backgroundColor(Color.White)
        Text()
          .width('100%')
          .height(1)
          .backgroundColor(Color.Black)
        Button("登录")
          .width(250)
          .height(50)
          .margin({ top: 70 })
          .onClick(() => {
            this.callbackResult()
          })
      }
      .width('100%')
      .height('80%')
      .justifyContent(FlexAlign.Center)

      Row() {
        Text("微信")
          .fontSize(16)
          .textAlign(TextAlign.Center)
        Text("支付宝")
          .fontSize(16)
          .textAlign(TextAlign.Center)
        Text("验证码")
          .fontSize(16)
          .textAlign(TextAlign.Center)
      }
      .width('100%')
      .height('20%')
      //主轴对齐方式
      .justifyContent(FlexAlign.SpaceAround)
      //交叉轴对齐方式
      .alignItems(VerticalAlign.Center)
    }
    .padding({ left: 16, right: 16 })
    .width('100%')
    .height('100%')
  }
}