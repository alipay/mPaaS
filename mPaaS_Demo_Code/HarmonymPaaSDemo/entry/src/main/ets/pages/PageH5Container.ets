import { TitleComponent } from '../component/TitleComponent';
import { BroadcastManager, CustomUIBuilderProvider, HRiver } from '@mpaas/hriver';
import { Constants } from '../constants/Constants';
import { H5CustomPlugin } from '../hriver/H5CustomPlugin';
import { CustomUIBuilderProviderImpl, CustomUIBuilderProviderImpl0 } from '../hriver/CustomUIBuilderProviderImpl';
import { promptAction, router } from '@kit.ArkUI';

@Entry
@Component
struct PageH5Container {
  @State message: string = 'Hello World';

  build() {
    Flex({ direction: FlexDirection.Column }) {
      TitleComponent({ title: "离线包" })
      Scroll() {
        Column() {
          Button("在线url")
            .fontSize(16)
            .margin({ top: 10 })
            .fontWeight(FontWeight.Bold)
            .onClick(() => {
              HRiver.startUrl("https://www.aliyun.com")
              // HRiver.startUrl("http://30.207.32.131:5173")
            })

          Button("预置离线包")
            .fontSize(16)
            .margin({ top: 10 })
            .fontWeight(FontWeight.Bold)
            .onClick(() => {
              HRiver.loadOfflineResource('h5_json.json', (result: string) => {
                console.log(Constants.TAG, `加载预置离线包${result}`)
                promptAction.showToast({
                  message: "预置离线包完成"
                })
              })
            })

          Button("注册自定义jsapi")
            .fontSize(16)
            .margin({ top: 10 })
            .fontWeight(FontWeight.Bold)
            .onClick(() => {
              //注册自定义jsapi
              HRiver.registerPlugin({ H5CustomPlugin })
              promptAction.showToast({
                message: "注册自定义jsapi完成"
              })
            })
          Button("打开离线包指定页面")
            .fontSize(16)
            .margin({ top: 10 })
            .fontWeight(FontWeight.Bold)
            .onClick(() => {
              let startParams: Map<string, Object> = new Map();
              //加载阶段显示默认标题
              startParams.set('defaultTitle', '默认标题');
              startParams.set('url', '/switch.html')
              HRiver.startApp('70000000', startParams)
            })
          Button("开启自定义导航栏")
            .fontSize(16)
            .margin({ top: 10 })
            .fontWeight(FontWeight.Bold)
            .onClick(() => {
              HRiver.setProvider(CustomUIBuilderProvider.name, new CustomUIBuilderProviderImpl())
              promptAction.showToast({
                message: "开启自定义导航栏完成"
              })
            })
          Button("Navigation")
            .fontSize(16)
            .margin({ top: 10 })
            .fontWeight(FontWeight.Bold)
            .onClick(() => {
              HRiver.setProvider(CustomUIBuilderProvider.name, new CustomUIBuilderProviderImpl0())
              router.pushUrl({
                url: Constants.PAGE_NAVIGATION
              })
            })
          Button("添加通知")
            .fontSize(16)
            .margin({ top: 10 })
            .fontWeight(FontWeight.Bold)
            .onClick(() => {
              BroadcastManager.getInstance().register(Constants.ACTION_TEST_EVENT, (msg:String,result:ESObject) => {
                console.error(Constants.TAG,`result ${result}`)
                promptAction.showToast({
                  message: "native-添加通知成功"
                })
              })
            })
          Button("移除通知")
            .fontSize(16)
            .margin({ top: 10 })
            .fontWeight(FontWeight.Bold)
            .onClick(() => {
              BroadcastManager.getInstance().unregister(Constants.ACTION_TEST_EVENT)
              promptAction.showToast({
                message: "native-移除通知成功"
              })
            })
          Button("发送通知")
            .fontSize(16)
            .margin({ top: 10 })
            .fontWeight(FontWeight.Bold)
            .onClick(() => {
              BroadcastManager.getInstance().notify(Constants.ACTION_TEST_EVENT, "native-测试通知数据")
            })
          Button("打开远程离线包")
            .fontSize(16)
            .margin({ top: 10 })
            .fontWeight(FontWeight.Bold)
            .onClick(() => {
              let startParams: Map<string, Object> = new Map();
              //加载阶段显示默认标题
              startParams.set('defaultTitle', '默认标题')
              // startParams.set('showTitleBar', false)
              startParams.set('showBottomLine', false)

              // HRiver.startApp("80808080", startParams)
              HRiver.startApp("70000000", startParams)
            })

          Button("打开预置离线包")
            .fontSize(16)
            .margin({ top: 10 })
            .fontWeight(FontWeight.Bold)
            .onClick(() => {
              //设置transparent 状态高度
              let startParams: Map<string, Object> = new Map();
              //加载阶段显示默认标题
              startParams.set('defaultTitle', '默认标题');
              // startParams.set("embedPage", "YES")
              HRiver.startApp('70000000', startParams)


              //打开本地网页
              // HRiver.startUrl('resource://rawfile/index.html')
            })
          Button("打开本地网页")
            .fontSize(16)
            .margin({ top: 10 })
            .fontWeight(FontWeight.Bold)
            .onClick(() => {
              //打开本地网页
              HRiver.startUrl('resource://rawfile/index.html')
            })
          Button("桂林银行")
            .fontSize(16)
            .margin({ top: 10 })
            .fontWeight(FontWeight.Bold)
            .onClick(() => {
              //设置transparent 状态高度
              let startParams: Map<string, Object> = new Map();
              //加载阶段显示默认标题
              startParams.set('defaultTitle', '默认标题');
              startParams.set('url', '/test/index.html#/C');
              HRiver.startApp('20200101', startParams)
            })
          Button("西安银行")
            .fontSize(16)
            .margin({ top: 10 })
            .fontWeight(FontWeight.Bold)
            .onClick(() => {
              //设置transparent 状态高度
              let startParams: Map<string, Object> = new Map();
              //加载阶段显示默认标题
              startParams.set('defaultTitle', '默认标题');
              // startParams.set('url', '/test/index.html#/C');
              HRiver.startApp('02007000', startParams)
            })
          Button("上海银行加载离线包")
            .fontSize(16)
            .margin({ top: 10 })
            .fontWeight(FontWeight.Bold)
            .onClick(() => {
              //设置transparent 状态高度
              let startParams: Map<string, Object> = new Map();
              //加载阶段显示默认标题
              startParams.set('defaultTitle', '默认标题');
              // startParams.set('url', '/test/index.html#/C');
              HRiver.startApp('20171228', startParams)
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