import { router } from '@kit.ArkUI';
import { Constants } from '../constants/Constants';
import RouterManager from '../constants/RouterManager';
import { JSON } from '@kit.ArkTS';
import { BannerModel } from '../rpc/EntityModel';
import { MPFramework } from '@mpaas/framework';
import { setStartEndTime } from '../constants/Global';


@Entry
@Component
struct PageLogin {
  @State message: string = 'Hello World';

  // private navPathStack: NavPathStack = new NavPathStack()
  //
  // aboutToAppear(): void {
  //   RouterManager.createNavPathStack(this.navPathStack)
  // }

  aboutToAppear(): void {
    setStartEndTime()
  }

  /**
   * 跳转到首页，需要在首页Index中
   */
  async openMain() {
    //模拟用户登录
    MPFramework.instance.userId = "duofupoc"
    router.replaceUrl({
      url: 'pages/PageMain',
      params: {
        data1: 'message'
      }
    }, callBack => {
      console.info(Constants.TAG, `关闭启动页，跳转首页`)
    });
  }

  build() {
    // Navigation(this.navPathStack) {
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
        TextInput({
          placeholder: "请输入账号",
          text: "https://appgallery.huawei.com/link/invite-test-wap?taskId=035829b210b284c62cc035cb9e250d18"
        })
          .placeholderColor(Color.Red)
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
            // router.pushUrl({
            //   url: Constants.PAGE_MAIN
            // })
            this.openMain()
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

  // .onAppear(() => {
  //   let bannnerModel: BannerModel = new BannerModel()
  //   bannnerModel.desc = "navgateion跳转传参"
  //   let navPathInfo = new NavPathInfo("PageMain", bannnerModel, (popinfo: PopInfo) => {
  //     let result = popinfo.result as BannerModel
  //     console.info(Constants.TAG, `回执传参：${JSON.stringify(result)}`)
  //   })
  //   RouterManager.pushPath(navPathInfo, true)
  // })
  // .hideNavBar(true)

  // }
}