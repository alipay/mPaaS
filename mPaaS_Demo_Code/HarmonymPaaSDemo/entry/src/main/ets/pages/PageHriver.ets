import { BroadcastManager, CustomUIBuilderProvider, HRiver } from '@mpaas/hriver';
import { Constants } from '../constants/Constants';
import { H5CustomPlugin } from '../hriver/H5CustomPlugin';
import { CustomUIBuilderProviderImpl } from '../hriver/CustomUIBuilderProviderImpl';
import { promptAction } from '@kit.ArkUI';
import { BaseTitleComponent } from 'library';
import AlertExit from '../component/CustomLoadingDialog';
import { ArrayList } from '@kit.ArkTS';
import request from '@ohos.request';
import { BusinessError } from '@ohos.base';
import { rcp } from '@kit.RemoteCommunicationKit';

@Builder
export function getPageHriver(): void {
  PageHriver()
}

@Component
struct PageHriver {
  @State message: string = 'Hello World';

  build() {
    NavDestination() {
      Flex({ direction: FlexDirection.Column }) {
        BaseTitleComponent({ title: "离线包" })
        Scroll() {
          Column() {
            Text("含义：" + "forceStatusBar:是否要状态栏高度\n" +
              "动态控制(原生/h5)导航栏，注释forceStatusBar,如果H5有导航栏，原生调用page.sendEvent(showTitleBar/hideTitleBar),如果原生有导航栏，H5调用AlipayJsbridge.call(showTitleBar/hideTitleBar)")
              .width('80%')
              .fontSize(14)
              .fontColor(Color.Gray)
              .margin({ top: 10 })
            Button("在线url")
              .width('80%')
              .fontSize(16)
              .margin({ top: 10 })
              .fontWeight(FontWeight.Bold)
              .onClick(() => {
                // HRiver.startUrl("https://www.aliyun.com")
                let startParams: Map<string, Object> = new Map();
                startParams.set('defaultTitle', 'edg无畏');
                startParams.set('query', 'uuuuuuuua');
                // HRiver.startUrl("https://cdn.cqdcg.com/static/upload/ykb/luban/pages/opluban_you.html", startParams)
                // HRiver.startUrl("http://30.172.64.146:5500/index.html",startParams)
                HRiver.startUrl("https://wwww.aliyun.com", startParams)
                // HRiver.startUrl("http://192.168.162.161:5500/index.html",startParams)
                // HRiver.startUrl("https://ykmappxc.cqdcg.com/mpt/citycode-universalcode-h5/#/?caring=true",startParams)
              })
            Button("录音地址测试")
              .width('80%')
              .fontSize(16)
              .margin({ top: 10 })
              .fontWeight(FontWeight.Bold)
              .onClick(() => {
                HRiver.startUrl("https://xiangyuecn.github.io/Recorder/")
              })
            Button("自定义加载页/错误页")
              .width('80%')
              .fontSize(16)
              .margin({ top: 10 })
              .fontWeight(FontWeight.Bold)
              .onClick(() => {
                //设置transparent 状态高度
                let startParams: Map<string, Object> = new Map();
                //加载阶段显示默认标题
                startParams.set('defaultTitle', '默认标题');
                // startParams.set('url', '/test/index.html#/C');
                HRiver.startApp('81818181', startParams)
              })
            Button("自定义在线错误页")
              .width('80%')
              .fontSize(16)
              .margin({ top: 10 })
              .fontWeight(FontWeight.Bold)
              .onClick(() => {
                HRiver.startUrl("http://30.207.32.131:5173")
              })
            Button("设置ua")
              .width('80%')
              .fontSize(16)
              .margin({ top: 10 })
              .fontWeight(FontWeight.Bold)
              .onClick(() => {
                HRiver.setUserAgent("duofu-uatest")
              })
            Button("更新离线包")
              .fontSize(16)
              .width('80%')
              .margin({ top: 10 })
              .fontWeight(FontWeight.Bold)
              .onClick(() => {
                HRiver.updateApp(["70000000"], (result: boolean, code: number) => {
                  console.info(Constants.TAG, `result：${result}  code：${code}`)
                  promptAction.showToast({
                    message: `result：${result}  code：${code}`
                  })
                  if (result) {
                    HRiver.startApp("70000000")
                  }
                })
                // HRiver.startUrl("http://30.207.32.131:5173")
              })

            Button("预置离线包")
              .fontSize(16)
              .width('80%')
              .margin({ top: 10 })
              .fontWeight(FontWeight.Bold)
              .onClick(() => {
                HRiver.loadOfflineResource('h5_json.json', (result: string) => {
                  console.log(Constants.TAG, `加载预置离线包${result}`)
                  promptAction.showToast({
                    message: `加载预置报完成，如果出现预置包打不开的情况，请检查是否有开启验签`
                  })
                })
              })
            Button("自定义导航栏")
              .fontSize(16)
              .width('80%')
              .margin({ top: 10 })
              .fontWeight(FontWeight.Bold)
              .onClick(() => {
                HRiver.setProvider(CustomUIBuilderProvider.name, new CustomUIBuilderProviderImpl())
                promptAction.showToast({
                  message: "开启自定义导航栏完成"
                })
              })
            Button("自定义jsapi")
              .fontSize(16)
              .width('80%')
              .margin({ top: 10 })
              .fontWeight(FontWeight.Bold)
              .onClick(() => {
                //注册自定义jsapi
                HRiver.registerPlugin({ H5CustomPlugin })
                promptAction.showToast({
                  message: "注册自定义jsapi完成"
                })
              })
            Button("打开本地网页")
              .width('80%')
              .fontSize(16)
              .margin({ top: 10 })
              .fontWeight(FontWeight.Bold)
              .onClick(() => {
                //打开本地网页
                let list = new ArrayList<string>()
                list.add("Navi首页");
                list.add("navi");
                let startParams: Map<string, Object> = new Map()
                startParams.set("keyList", list)
                HRiver.startUrl('resource://rawfile/70000000/index.html', startParams)
                // HRiver.startUrl('resource://rawfile/dist/index.html')
                // HRiver.startUrl('resource://rawfile/yukuaiban.html')
              })
            Button("打开离线包指定页面")
              .fontSize(16)
              .margin({ top: 10 })
              .width('80%')
              .fontWeight(FontWeight.Bold)
              .onClick(() => {
                let startParams: Map<string, Object> = new Map();
                //加载阶段显示默认标题
                startParams.set('defaultTitle', '默认标题');
                startParams.set('url', '/switch.html')
                HRiver.startApp('70000000', startParams)
              })
            Button("打开远程离线包")
              .width('80%')
              .fontSize(16)
              .margin({ top: 10 })
              .fontWeight(FontWeight.Bold)
              .onClick(() => {
                let startParams: Map<string, Object> = new Map();
                //加载阶段显示默认标题
                startParams.set('defaultTitle', '默认标题')
                //启动参数隐藏导航栏
                // startParams.set('showTitleBar', false)
                // startParams.set('showBottomLine', false)

                // HRiver.startApp("80808080", startParams)
                HRiver.startApp("70000000", startParams)
              })

            Button("打开预置离线包")
              .width('80%')
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
            Button("Navigation")
              .fontSize(16)
              .width('80%')
              .margin({ top: 10 })
              .fontWeight(FontWeight.Bold)
              .onClick(() => {
                //现在使用的全局navigation模式
                let param: Map<string, Object> = new Map<string, Object>()
                HRiver.startApp('70000000', param)
              })
            Button("添加通知")
              .width('80%')
              .fontSize(16)
              .margin({ top: 10 })
              .fontWeight(FontWeight.Bold)
              .onClick(() => {
                BroadcastManager.getInstance()
                  .register(Constants.ACTION_TEST_EVENT, (msg: String, result: ESObject) => {
                    console.error(Constants.TAG, `result ${result}`)
                    promptAction.showToast({
                      message: "native-添加通知成功"
                    })
                  })
              })
            Button("移除通知")
              .width('80%')
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
              .width('80%')
              .fontSize(16)
              .margin({ top: 10 })
              .fontWeight(FontWeight.Bold)
              .onClick(() => {
                BroadcastManager.getInstance().notify(Constants.ACTION_TEST_EVENT, "native-测试通知数据")
              })
            Button("zhengzhou")
              .width('80%')
              .fontSize(16)
              .margin({ top: 10 })
              .fontWeight(FontWeight.Bold)
              .onClick(() => {
                //打开本地网页
                HRiver.startApp('20240913')
              })
            Button("amr下载失败，request验证")
              .width('80%')
              .fontSize(16)
              .margin({ top: 10 })
              .fontWeight(FontWeight.Bold)
              .onClick(() => {
                this.testDownloadAmr()
              })
            Button('amr下载失败，rpc验证')
              .width('80%')
              .fontSize(16)
              .margin({ top: 10 })
              .fontWeight(FontWeight.Bold)
              .onClick(() => {
                this.testDownloadAmrRpc()
              })
            Button("xxx1")
              .width('80%')
              .fontSize(16)
              .margin({ top: 10 })
              .fontWeight(FontWeight.Bold)
              .onClick(() => {
                // //设置transparent 状态高度
                // let startParams: Map<string, Object> = new Map();
                // //加载阶段显示默认标题
                // startParams.set('defaultTitle', '默认标题');
                // startParams.set('url', '/test/index.html#/C');
                // HRiver.startApp('20200101', startParams)
                AlertExit.showAlertEx((err, data) => {

                })
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
    }
    .hideTitleBar(true)
    .width('100%')
    .height('100%')
  }

  /**
   * 下载文件
   * @param url: URL
   * @param toPath: 文件保存路径
   *
   * @returns 通过回调返回
   */
  async downloadFile(url: string, filename: string, progressCallback: (progress: number) => void,) {
    // Define a custom response handler
    const customHttpEventsHandler: rcp.HttpEventsHandler = {
      onDownloadProgress: (totalSize: number, transferredSize: number) => {
        // Custom logic for handling download progress
        console.info(Constants.TAG, transferredSize, "of", totalSize);
        let proc = Math.ceil(transferredSize / totalSize * 100);
        progressCallback(proc);
      }
    };

    // Configure tracing settings
    const tracingConfig: rcp.TracingConfiguration = {
      verbose: true,
      infoToCollect: {
        textual: true,
        incomingHeader: true,
        outgoingHeader: true,
        incomingData: true,
        outgoingData: true,
        incomingSslData: true,
        outgoingSslData: true,
      },
      collectTimeInfo: true,
      httpEventsHandler: customHttpEventsHandler,
    };

    // Use the configuration in the session creation
    const session = rcp.createSession({ requestConfiguration: { tracing: tracingConfig } });

    try {
      let file = getContext(this).tempDir + `/${Date.now()}`
      console.info(Constants.TAG, `executeJSFunc AppDownloader start download: ${file}`);
      let downloadToFile: rcp.DownloadToFile = {
        kind: "file",
        file: file + '.amr',
      } as rcp.DownloadToFile

      await session.downloadToFile(url, downloadToFile);
      console.log('success')
    } catch (err) {
      console.log('err')
    }
  }

  testDownloadAmrRpc() {
    let url =
      'https://mtpmds.hfbank.com.cn:441/B2FBDE7060907-product/20201117/4.0.0.19_harmony/nebula/20201117_4.0.0.19.amr'
    try {
      this.downloadFile(url, '123', (progress: number) => {
        console.info(Constants.TAG, `executeJSFunc AppDownloader downloading ${progress}`);
      })
    }catch (err){
      console.info(Constants.TAG,
        `executeJSFunc AppDownloader Invoke downloadFile failed, code is ${err.code}, message is ${err.message}`);
    }
  }

  testDownloadAmr() {
    try {
      let file = `/data/storage/el2/base/cache/CRVDownloadRes/testfile`
      console.info(Constants.TAG, `executeJSFunc AppDownloader start download: ${file}`);
      request.downloadFile(getContext(this), {
        url: "https://mtpmds.hfbank.com.cn:441/B2FBDE7060907-product/20201117/4.0.0.19_harmony/nebula/20201117_4.0.0.19.amr",
        filePath: file
      }).then((downloadTask: request.DownloadTask) => {
        downloadTask.on('complete', () => {
          console.info(Constants.TAG, 'executeJSFunc AppDownloader download complete');
        })
        downloadTask.on('fail', (err) => {
          console.info(Constants.TAG, 'executeJSFunc AppDownloaderDownload task failed. Cause:' + err);
        })
      }).catch((err: BusinessError) => {
        console.info(Constants.TAG,
          `executeJSFunc AppDownloader Invoke downloadTask failed, code is ${err.code}, message is ${err.message}`);
      });
    } catch (error) {
      let err: BusinessError = error as BusinessError;
      console.info(Constants.TAG,
        `executeJSFunc AppDownloader Invoke downloadFile failed, code is ${err.code}, message is ${err.message}`);
    }
  }
}