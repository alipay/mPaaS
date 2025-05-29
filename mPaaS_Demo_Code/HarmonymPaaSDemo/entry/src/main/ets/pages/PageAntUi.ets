import { AUButton, AUInputBox, AUInputField, AUListItem, AUPanelManager, AUText, } from "@mpaas/antui"
// import { BaseTitleComponent } from "library"
import { MineModel } from "../rpc/EntityModel"
import { MineViewModel } from '../viewmodel/MineViewModel';

@Builder
export function getPageAntUi(): void {
  PageAntUi()
}

@Component
export struct PageAntUi {
  @State isShowListener: boolean = false
  mineViewModel: MineViewModel = new MineViewModel()
  listData: Array<MineModel> = this.mineViewModel.getSettingList()

  build() {
    NavDestination() {
      Flex({ direction: FlexDirection.Column }) {
        // BaseTitleComponent({
        //   title: "AntUI",
        //   leftClickEvent: (): void => {
        //
        //   }
        // })
        Column() {
          Row() {
            AUText({ text: "用户名" })
            AUInputField({
              placeholder: "AntUI输入框",
            })
              .margin({ left: 10 })
          }
          .width('100%')
          .height('55')

          Row() {
            AUText({ text: "密  码" })
            AUInputField({
              placeholder: "AntUI输入框",
            })
              .margin({ left: 10 })
          }
          .width('100%')
          .height('55')

          AUButton({
            title: "AntUI弹窗",
            buttonSize: { width: "200", height: "40" }
          })
            .margin({ top: 10 })
            .onClick(() => {
              AUPanelManager.showConfirmFrom(this, {
                title: "AntUI弹窗标题", content: "AntUI弹窗内容", buttons: [{
                  title: "取消", action: () => {

                  }
                }, {
                  title: "确认", action: () => {

                  }
                }]
              })
            })
          AUButton({
            title: "AntUI条目",
            buttonSize: { width: "200", height: "40" }
          }).margin({ top: 10 })
            .onClick(() => {
              this.isShowListener = !this.isShowListener
            })

          List() {
            ForEach(this.mineViewModel.getSettingList(), (item: MineModel, index) => {
              AUListItem({ title: "AUListItem", image: $r('app.media.startIcon') })
            })
          }
          .visibility(this.isShowListener ? Visibility.Visible : Visibility.Hidden)
          .margin({ top: 10 })
          .divider({ strokeWidth: 10, color: Color.White })
          .borderRadius(15)
          .backgroundColor(Color.Orange)
          .width('100%')
        }
        .justifyContent(FlexAlign.Start)
        .width('100%')
        .height('100%')
      }
      .width('100%')
      .height('100%')
    }
    .hideTitleBar(true)
  }
}
