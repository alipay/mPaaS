import { AsyncCallback } from '@kit.BasicServicesKit'


@CustomDialog
export struct CustomLoadingDialog {
  controller: CustomDialogController

  build() {
    Column() {
      Row() {
        Button("左侧")
          .height('50')
        Button("右侧")
          .height('50')
      }
      .width('100%')
      .justifyContent(FlexAlign.SpaceBetween)
      .alignItems(VerticalAlign.Top)

      Image($r("app.media.startIcon"))
        .width('100%')
        .height('100%')
        .objectFit(ImageFit.None)
    }
    .margin(10)
    .backgroundColor(Color.White)
    .width('100%')
    .height(200)
    .justifyContent(FlexAlign.Start)
  }
}

let _dialogController: CustomDialogController | null
let _callBack: AsyncCallback<boolean>

@Component
struct AlertExUtil {
  onCancel() {

  }

  build() {
  }

  showAlertEx(callBck: AsyncCallback<boolean>) {
    _dialogController = new CustomDialogController({
      builder: CustomLoadingDialog({}),
      cancel: this.onCancel,
      alignment: DialogAlignment.Bottom,
      customStyle: true,
      autoCancel: false
    })
    _callBack = callBck
    _dialogController.open()
  }

  hideLoadingEx() {
    if (_dialogController) {
      _dialogController.close()
    }
  }
}

export default new AlertExUtil()