import { H5PageLifeCycleProvider, H5RouterNavStackProvider, HRBuilder, HRiver, RouterUtils } from '@mpaas/hriver';
import { AppPage, HRiverMini } from '@mpaas/hrivermini';
import { GridComponent } from '../component/GridComponent';
import { HomeComponent } from '../component/HomeComponent';
import { MineComponent } from '../component/MineComponent';
import { Constants } from '../constants/Constants';
import RouterManager from '../constants/RouterManager';
import { BannerModel } from '../rpc/EntityModel';
import { common } from '@kit.AbilityKit';
import { promptAction } from '@kit.ArkUI';
import { getPageConfig } from './PageConfig';
import { getPageMini } from './PageMini';
import { getPageHriver } from './PageHriver';
import { getPageDataCenterA } from './PageDataCenterA';
import { getPageHarmonyBaase } from './PageHarmonyBaase';
import { NavStackProvider } from '../hriver/NavStackProvider';
import { H5PageLifeCycle } from '../hriver/H5PageLifeCycle';
import { getPageOcr } from './PageOcr';
import { AiCameraPage } from '@mpaas/mpaas_ocr_demo/Index';
import { mPaaSOCRCardType } from '@mpaas/mpaas_ocr_core/Index';

// @Builder
// export function getPageMain(): void {
//   PageMain()
// }

@Entry
@Component
export struct PageMain {
  @State message: string = 'Hello World';
  mPaaSHRiverBuilder: WrappedBuilder<[string, ESObject]> = wrapBuilder(HRBuilder);
  private navPathStack: NavPathStack = new NavPathStack()
  private context = getContext(this) as common.UIAbilityContext;
  @State clickIndexMyOnPageShow: number = 0
  @State clickIndexMyOnPageHide: number = 0
  tempCurrentIndex: number = 0

  aboutToAppear(): void {
    //管理原生路由栈
    RouterManager.createNavPathStackByPage(this.navPathStack)
    //设置离线包全局路由
    HRiver.setProvider(H5RouterNavStackProvider.name, new NavStackProvider(RouterManager.pageNavPathStack))
    //设置监听页面生命周期
    HRiver.setProvider(H5PageLifeCycleProvider.name, new H5PageLifeCycle())
    //小程序设置路由栈
    HRiverMini.notifyNavigationCreate(this.context, RouterManager.pageNavPathStack)
  }

  @Builder
  PagesMap(name: string, params: ESObject) {
    if (RouterUtils.isMPHRiverPage(name)) {
      //hriver
      this.mPaaSHRiverBuilder.builder(name, params)
    } else if (name == "PageConfig") {
      //暂时先这么处理，等暴漏出hriver和miniprogram的路由信息在改造
      getPageConfig()
    } else if (name == "PageMini") {
      getPageMini()
    } else if (name == "PageHriver") {
      getPageHriver()
    } else if (name == "PageDataCenterA") {
      getPageDataCenterA()
    } else if (name == "PageHarmonyBaase") {
      getPageHarmonyBaase()
    } else if (name == "PageOcr") {
      getPageOcr()
    } else if (name == 'AiCameraPage') {
      //OCR
      AiCameraPage();
    } else {
      //miniprogram
      AppPage(name, (params as Map<string, Object>))
    }
  }

  build() {
    Navigation(this.navPathStack) {
      Row() {
        Column() {
          Tabs({ barPosition: BarPosition.End }) {
            TabContent() {
              // Text('首页的内容').fontSize(30)
              HomeComponent()
            }
            .tabBar('首页')

            TabContent() {
              GridComponent({
                clickIndexMyOnPageShow: $clickIndexMyOnPageShow,
                clickIndexMyOnPageHide: $clickIndexMyOnPageHide
              })
            }
            .tabBar('推荐')

            TabContent() {
              Text('发现的内容').fontSize(30)
            }
            .tabBar('发现')

            TabContent() {
              MineComponent()
            }
            .tabBar("我的")
          }
          .onChange((index: number) => {
            this.tempCurrentIndex = index
            this.clickIndexMyOnPageShow = this.tempCurrentIndex
          })
        }
        .width('100%')
      }
      .height('100%')
    }.navDestination(this.PagesMap)
    .hideTitleBar(true)
  }

  onPageShow(): void {
    console.log(Constants.TAG, `pageMain-onPageShow`)
    this.clickIndexMyOnPageShow = this.tempCurrentIndex
  }

  onPageHide(): void {
    console.log(Constants.TAG, `pageMain-onPageHide`)
    this.clickIndexMyOnPageHide = this.tempCurrentIndex
  }
}

