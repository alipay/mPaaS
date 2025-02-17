import { MineModel } from '../rpc/EntityModel';
import { MineViewModel } from '../viewmodel/MineViewModel';

@Component
struct MineComponent {
  @State message: string = 'Hello World';
  title: string = "我的"
  mineViewModel: MineViewModel = new MineViewModel()
  listData: Array<MineModel> = this.mineViewModel.getSettingList()

  build() {
    Column() {
      Row() {
        Image($r('app.media.icon'))
          .width(40)
          .height(40)
          .borderRadius(100)
        Column() {
          Text("taoge")
            .fontSize(14)
          Text("taoge@163.com")
            .fontSize(12)
        }
        .margin({ left: 10 })
        .alignItems(HorizontalAlign.Start)
      }
      .justifyContent(FlexAlign.Start)
      .width('100%')
      .height(78)
      .borderRadius(15)
      .backgroundColor(Color.Orange)

      List() {
        ForEach(this.mineViewModel.getSettingList(), (item: MineModel, index) => {
          this.listItem(item)
        })
      }
      .margin({ top: 10 })
      .divider({ strokeWidth: 10, color: Color.White })
      .borderRadius(15)
      .backgroundColor(Color.Orange)
      .width('100%')
    }
    .justifyContent(FlexAlign.Start)
    .alignItems(HorizontalAlign.Center)
    .width('100%')
    .height('100%')
    .padding(16)
  }

  @Builder
  listItem(item: MineModel) {
    Row({ space: 15 }) {
      Row() {
        Image(item.img)
          .width(55)
          .height(55)
          .objectFit(ImageFit.None)
        Text(`${item.desc}`)
      }

      if (item.other != null) {
        Image(item.other)
          .width(55)
          .height(55)
          .objectFit(ImageFit.None)
      } else {
        Toggle({ type: ToggleType.Switch, isOn: false })
      }
    }
    .justifyContent(FlexAlign.SpaceBetween)
    .alignItems(VerticalAlign.Center)
    .width('100%')
    .height('55')
  }
}

export { MineComponent }