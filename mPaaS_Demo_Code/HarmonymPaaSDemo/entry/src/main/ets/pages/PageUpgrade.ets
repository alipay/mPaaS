import { TitleComponent } from '../component/TitleComponent';
import { MPUpgradeService } from '@mpaas/upgrade';
import { HRiver } from '@mpaas/hriver';
import { upgradeRes } from '@mpaas/upgrade/src/main/ets/a/b';
import { Constants } from '../constants/Constants';

@Entry
@Component
struct PageUpgrade {
  @State message: string = 'Hello World';

  build() {
    Flex({ direction: FlexDirection.Column }) {
      TitleComponent({ title: "升级" })
      Scroll() {
        Column() {
          Button("检查升级（默认弹窗）")
            .fontSize(16)
            .margin({ top: 10 })
            .fontWeight(FontWeight.Bold)
            .onClick(() => {
              MPUpgradeService.checkNewVersionAndShow()
            })
          Button("检查升级（自定义弹窗）")
            .fontSize(16)
            .margin({ top: 10 })
            .fontWeight(FontWeight.Bold)
            .onClick(() => {
              MPUpgradeService.checkNewVersion().then((response: upgradeRes | Error | null) => {
                let str = JSON.stringify(response)
                AlertDialog.show(
                  {
                    title: '升级检测结果',
                    message: str,
                    autoCancel: true,
                    offset: { dx: 0, dy: -20 },
                    gridCount: 3,
                    confirm: {
                      value: '确认', action: () => {
                        let downRUl  = (response as upgradeRes).downloadURL
                        console.info(Constants.TAG,`下载地址：${downRUl}`)
                        if (response == null) {
                          return
                        }
                        if (response instanceof Error) {
                          return
                        }
                        HRiver.startUrl(downRUl)
                      }
                    },
                    cancel: () => {
                      console.info('Closed callbacks')
                    }
                  })
              })
            })
          Button("静默周期")
            .fontSize(16)
            .margin({ top: 10 })
            .fontWeight(FontWeight.Bold)
            .onClick(() => {
              MPUpgradeService.defaultUpdateInterval = 1
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
    .width('100%')
    .height('100%')
  }
}