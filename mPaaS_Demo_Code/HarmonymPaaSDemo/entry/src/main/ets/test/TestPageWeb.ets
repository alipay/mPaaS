import { window } from '@kit.ArkUI'
import { BusinessError } from '@kit.BasicServicesKit'
import web_webview from '@ohos.web.webview';


web_webview.once("webInited", () => {
  console.log("setCookie")
})

@Entry
@Component
struct TestPageWeb {
  @State testModel: TestModel = new TestModel();
  @State webResult: string = '';
  @State isShowSubWindow: boolean = false
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  aboutToAppear(): void {

  }


  build() {
    RelativeContainer() {
      if (this.testModel.hideTitle) {
        Row()
          .alignRules({
            top: { anchor: '__container__', align: VerticalAlign.Top },
            left: { anchor: '__container__', align: HorizontalAlign.Start }
          })
          .width("100%")
          .height('20%')
          .backgroundColor(Color.Blue)
          .id("row1")
      }
      Web({ src: 'resource://rawfile/70000000/webIndex.html', controller: this.controller })
        .alignRules({
          top: { anchor: "row1", align: VerticalAlign.Bottom },
          bottom: { anchor: "__container__", align: VerticalAlign.Bottom }
        })//将对象注入到web端,h5->native
        .javaScriptProxy({
          object: this.testModel,
          name: "testModelName",
          methodList: ["nativeTest"],
          controller: this.controller
        })
        .javaScriptAccess(true)
        .onPageEnd(e => {
          try {
            //native->h5
            this.controller.runJavaScript(
              'h5test()',
              (error, result) => {
                if (error) {
                  console.error(`myweb008 run JavaScript error, ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
                  return
                }
                if (result) {
                  this.webResult = result;
                  console.info(`myweb008 The test() return value is: ${result}`);
                }
              });
            if (e) {
              console.info('myweb008 url: ', e.url);
            }
          } catch (error) {
            console.error(`myweb008 ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
        .backgroundColor(Color.Yellow)
        .id("column1")
    }
    .width('100%')
    .height('100%')

  }
}

export class TestModel {
  hideTitle: boolean = true;
  model: Model = new Model(() => {
  })

  query() {
    this.model.callback = () => {
      this.hideTitle = false;
    }
    this.model.query();
  }

  nativeTest(): string {
    // 这里监听H5的调用，动态修改component里的state变量（hideTitle）
    this.query()
    return 'native数据';
  }
}

export class Model {
  callback: () => void

  constructor(cb: () => void) {
    this.callback = cb;
  }

  query() {
    this.callback();
  }
}