@CustomDialog
export struct DialogMyCustom {
  controller?: CustomDialogController
  cancel: () => void = () => {
  }
  confirm: () => void = () => {
  }

  build() {
    Flex({ direction: FlexDirection.Row, justifyContent: FlexAlign.SpaceAround }) {
      Text("取消")
        .fontSize(16)
        .onClick(() => {
          this.cancel()
        })

      Text("确定")
        .fontSize(16)
        .onClick(() => {
          this.confirm()
        })
    }
    .width('100%')
    .height(300)
  }
}