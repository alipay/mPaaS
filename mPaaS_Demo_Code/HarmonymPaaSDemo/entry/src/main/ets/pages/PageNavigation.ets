import { H5EmbedPageLifeCycleProvider, H5PageLifeCycleProvider, HRBuilder, HRiver, RouterUtils } from '@mpaas/hriver';
import RouterManager from '../constants/RouterManager';
import { H5EmbedPageLifeCycleProviderImpl } from '../hriver/H5EmbedPageLifeCycleProviderImpl';
import { H5PageLifeCycle } from '../hriver/H5PageLifeCycle';

@Entry
@Component
struct PageNavigation {
  @State message: string = 'Hello World';
  // pageInfos: NavPathStack = new NavPathStack()


  aboutToAppear(): void {
    let param: Map<string, Object> = new Map<string, Object>()
    // param.set("showBackButton", false)
    HRiver.startApp('70000000', param)
    HRiver.setProvider(H5EmbedPageLifeCycleProvider.name, new H5EmbedPageLifeCycleProviderImpl(RouterManager.pageNavPathStack))
    HRiver.setProvider(H5PageLifeCycleProvider.name, new H5PageLifeCycle())
  }



  build() {
    Column() {
      // Text('页面顶部内容')
      //   .margin(20)
      // Text('页面中间内容')
      //   .margin(20)
      // Navigation(RouterManager.pageNavPathStack) {
      //   Row() {
      //     Column() {
      //       // 业务页面
      //
      //     }
      //     .width('100%')
      //   }
      // }
      // .navDestination(this.PagesMap)
      // .backgroundColor(Color.Transparent)
      // .height('100%')

      // Text('页面底部内容')
      //   .margin(20)
    }
    .width('100%')
    .height('100%')
    .backgroundColor(Color.Yellow)
  }
}