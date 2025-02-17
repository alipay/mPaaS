import { CustomLoadingBuilderProvider, H5Router, HRLoadingData, LoadingStatus } from '@mpaas/hriver';
import { JSON } from '@kit.ArkTS';

export class CustomLoadingBuilderProviderImpl extends CustomLoadingBuilderProvider {
  getCustomUIBuilder(): WrappedBuilder<[string, HRLoadingData, H5Router]> {
    return wrapBuilder(CustomUIBuilder);
  }
}


export const Loading_STATE_Init = 0

export const Loading_STATE_Start = 1

export const Loading_STATE_End = 2

export const Loading_STATE_Err = 3

@Builder
export function CustomUIBuilder(name: string, loadingData: HRLoadingData, h5Router: H5Router) {
  if (name === 'loading') {
    CustomLoadingComponent({ loadingStatus: loadingData.loadingStatus, h5Router: h5Router })
  }
}

@Component
export struct CustomLoadingComponent {
  @ObjectLink loadingStatus: LoadingStatus
  h5Router?: H5Router

  build() {
    Row() {
      Text(`自定义加载页\n\n${JSON.stringify(this.loadingStatus)}`)
        .fontSize(20)
        .fontColor(Color.Blue)
        .width('100%')
        .height('100%')
        .textAlign(TextAlign.Center)
    }
    .backgroundColor(Color.Red)
    .justifyContent(FlexAlign.Center)
    .alignItems(VerticalAlign.Center)
    .width('100%')
    .height('100%')
  }
}