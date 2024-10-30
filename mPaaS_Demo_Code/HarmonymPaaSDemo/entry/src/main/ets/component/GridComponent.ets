import {
  AppManager,
  AppNode,
  getProxy,
  H5EmbedPageLifeCycleProvider,
  H5PageLifeCycleProvider,
  H5WebClientProvider,
  HRBuilder,
  HRiver,
  Page,
  RouterUtils,
  XRiverProxy
} from '@mpaas/hriver';
import { Constants } from '../constants/Constants';
import { H5EmbedPageLifeCycleProviderImpl } from '../hriver/H5EmbedPageLifeCycleProviderImpl';
import { H5PageLifeCycle } from '../hriver/H5PageLifeCycle';
import { H5WebProivder } from '../hriver/H5WebProivder';
import { MineModel } from '../rpc/EntityModel';
import { MineViewModel } from '../viewmodel/MineViewModel';


@Component
struct GridComponent {
  mineViewModel: MineViewModel = new MineViewModel()
  listData: Array<MineModel> = this.mineViewModel.getSettingList()
  pageInfos: NavPathStack = new NavPathStack()
  mPaaSHRiverBuilder: WrappedBuilder<[string, ESObject]> = wrapBuilder(HRBuilder);
  scroller: Scroller = new Scroller()
  @Link @Watch('myOnPageShow') clickIndexMyOnPageShow: number
  @Link @Watch('myOnPageHide') clickIndexMyOnPageHide: number


  myOnPageShow() {
    console.log(Constants.TAG, `clieckIndex:${this.clickIndexMyOnPageShow}`)
    if (this.clickIndexMyOnPageShow == 1) {
      let appManager = getProxy(XRiverProxy.AppManager) as AppManager
      let appNode: AppNode | null = appManager.findTopApp()
      if (appNode != null) {
        let page: Page | null = appNode.getActivePage()
        if (page != null) {
          page.sendToWeb('testAction', { data: '这条数据来自于嵌入式H5的原生页面的onResume()'})
        }
      }
    }
  }
  myOnPageHide() {
    console.log(Constants.TAG, `clieckIndex:${this.clickIndexMyOnPageHide}`)
    if (this.clickIndexMyOnPageHide == 1) {

    }
  }

  aboutToAppear(): void {
    console.log(Constants.TAG, `嵌入式离线包-aboutToAppear`)
    let param: Map<string, Object> = new Map<string, Object>()
    param.set("showBackButton", false)
    //主入口
    // param.set('url', '/index/index.html#/newIndexPage');
    // HRiver.startApp('20201011', param, this.pageInfos)
    // 显示不全的问题  内嵌必须加
    param.set("embedPage", "YES")
    //原生跟hriver嵌套滚动  https://developer.huawei.com/consumer/cn/doc/harmonyos-references-V5/ts-container-scroll-V5
    param.set("scrollForward", 2)
    param.set("scrollBackward", 1)
    // param.set("bottomSafe", "YES")
    HRiver.startApp('70000000', param, this.pageInfos)
    // HRiver.startUrl("https://ykmappxc.cqdcg.com/mpt/citycode-universalcode-h5/#/?caring=true",param,this.pageInfos)
    // 避免白屏不需要下面这行代码了
    // HRiver.setProvider(H5EmbedPageLifeCycleProvider.name, new H5EmbedPageLifeCycleProviderImpl(this.pageInfos))
    // 只需要拦截退出事件就可以按退出手势后正常退出，避免内嵌页面白屏。
    HRiver.setProvider(H5PageLifeCycleProvider.name, new H5PageLifeCycle())
    HRiver.setProvider(H5WebClientProvider.name, new H5WebProivder())
  }

  @Builder
  PagesMap(name: string, params: ESObject) {
    if (RouterUtils.isMPHRiverPage(name)) {
      this.mPaaSHRiverBuilder.builder(name, params)
    }
  }

  build() {
    Scroll(this.scroller) {
      Column() {
        Grid() {
          ForEach(this.listData, (item: MineModel, index) => {
            GridItem() {
              this.listItem(item)
            }
          })
        }
        .columnsTemplate('1fr 1fr 1fr 1fr')
        .columnsGap(10)
        .width('100%')
        .height('20%')

        Navigation(this.pageInfos) {
          //@{@"status":e_usually_success, @"message":@"", @"payload":@{@"homeType":@"wealth"}}
        }
        .mode(NavigationMode.Stack)
        .navDestination(this.PagesMap)
        .width('100%')
        // .hideTitleBar(true)
        .hideNavBar(true)
        // .hideBackButton(true)
        .animation({ duration: 0 })

      }
      .backgroundColor(Color.Yellow)
      .onVisibleAreaChange([0.0, 1.0], (isVisible: boolean, currentRatio: number) => {
      })
      .width('100%')
    }
    .scrollable(ScrollDirection.Vertical) // 滚动方向为垂直方向
    .scrollBar(BarState.On) // 滚动条常驻显示
    .width('100%')
    .height('100%')
    .onScrollFrameBegin((offset: number, s: ScrollState) => {
      console.info(Constants.TAG, `滚动 ${offset}  ${s} ${this.scroller.currentOffset().yOffset}`)
      return { offsetRemain: offset };
    })
    .onScroll((xOffset: number, yOffset: number) => {
      console.info(Constants.TAG, `onScroll滚动 ${xOffset}  ${yOffset}  ${this.scroller.currentOffset().yOffset}`)
    })
  }

  @Builder
  listItem(item: MineModel) {
    Column() {
      Image(item.img)
        .width(25)
        .height(25)
        .objectFit(ImageFit.Auto)
        .backgroundColor(Color.Black)
      Text(`${item.desc}`)
        .margin({ top: 10 })
    }
    .justifyContent(FlexAlign.Center)
    .width('100%')
    .margin({ top: 16 })
    .onClick(() => {
      let appManager = getProxy(XRiverProxy.AppManager) as AppManager
      let appNode: AppNode | null = appManager.findTopApp()
      if (appNode != null) {
        let page: Page | null = appNode.getActivePage()
        if (page != null) {
          page.sendToWeb('testAction', { data: 'native sendtoweb 啊啊啊啊' })
        }
      }
    })
  }
}

export { GridComponent }