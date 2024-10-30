import { TitleComponent } from '../component/TitleComponent';
import { HRiver } from '@mpaas/hriver';
import { Constants } from '../constants/Constants';
import { H5CustomPlugin } from '../hriver/H5CustomPlugin';
import { CustomInputRSA } from '../component/CustomInputRSA';
import { CustomInputSM2 } from '../component/CustomInputSM2';
import { CustomInputCustom } from '../component/CustomInputCustom';

@Entry
@Component
struct PageKeyBoard {

  control = new TextInputController()
  build() {
    Flex({ direction: FlexDirection.Column }) {
      TitleComponent({ title: "安全键盘" })
      Scroll() {
        Column() {
          CustomInputRSA()
            .margin({ top: 10 })
          CustomInputSM2()
            .margin({ top: 10 })
          CustomInputCustom()
            .margin({ top: 10 })
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
