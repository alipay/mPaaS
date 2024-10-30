import router from '@ohos.router';
import RouterManager from '../constants/RouterManager';
import { BannerModel } from '../rpc/EntityModel';

@Component
struct TitleComponent {
  @State message: string = 'Hello World';
  title: string = "默认标题"



  build() {
    Row() {
      Flex({ direction: FlexDirection.Row, justifyContent: FlexAlign.SpaceBetween }) {
        Image($r('app.media.ic_back_white'))
          .objectFit(ImageFit.Contain)
          .width($r('app.float.login_height'))
          .height($r('app.float.login_height'))
          .margin($r('app.float.main_padding_left'))
          .onClick(() => {
            let bannerModel = new BannerModel()
            bannerModel.desc = "回执传参"
            RouterManager.pop(bannerModel, true)
          })
        Text(this.title)
          .fontSize(18)
          .alignSelf(ItemAlign.Center)
        Image($r('app.media.app_icon'))
          .objectFit(ImageFit.Contain)
          .width($r('app.float.login_height'))
          .height($r('app.float.login_height'))
          .margin($r('app.float.main_padding_left'))
      }
      .width('100%')
      .height('100%')
      .backgroundColor(Color.Blue)
    }
    .width('100%')
    .height('50')
  }
}

export { TitleComponent }