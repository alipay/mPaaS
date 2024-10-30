import { HRiver } from '@mpaas/hriver'
import { window } from '@kit.ArkUI'
import { BusinessError } from '@kit.BasicServicesKit'
import web_webview from '@ohos.web.webview';

web_webview.once("webInited", () => {
  console.log("setCookie")
})

@Entry
@Component
struct PageWeb {
  @State isShowSubWindow: boolean = false
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  build() {
    Column() {
      Web({ src: 'http://192.168.149.213:5500/testPage/page.html', controller: this.controller })
    }
  }

}