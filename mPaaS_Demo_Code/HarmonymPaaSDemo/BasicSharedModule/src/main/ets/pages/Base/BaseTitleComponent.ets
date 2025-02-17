import router from '@ohos.router';

@Component
struct BaseTitleComponent {
  @State message: string = 'Hello World';
  title: string = "默认标题"

  build() {
    Column() {
      Text()
        .width('100%')
        .backgroundColor(Color.Yellow)
        .height('123px')
      Row() {
        Image($r('app.media.ic_back_white'))
          .objectFit(ImageFit.Contain)
          .width(28)
          .height(28)
          .onClick(() => {
            this.leftClickEvent()
          })
        Text(this.title)
          .fontSize(18)
          .alignSelf(ItemAlign.Center)
          .fontColor(Color.White)
        Image($r('app.media.app_icon'))
          .objectFit(ImageFit.Contain)
          .width(28)
          .height(28)
      }
      .justifyContent(FlexAlign.SpaceAround)
      .alignSelf(ItemAlign.Center)
      .width('100%')
      .height(48)
      .backgroundColor(Color.Blue)
    }
    .width('100%')
  }

  leftClickEvent: () => void = () => {
  }
}

export { BaseTitleComponent }