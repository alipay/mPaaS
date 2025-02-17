import { router } from '@kit.ArkUI';
import { Constants } from '../constants/Constants';
import { MPFramework } from '@mpaas/framework';
import { curUIAbilityContext, curWindowStage, exitApp, setContext } from '../constants/Global';
import { MyInterceptor } from '../rpc/MyInterceptor';
import {
  CustomLoadingBuilderProvider,
  H5CommonAppProvider,
  H5UrlInterceptProvider,
  H5WebClientProvider,
  HRiver
} from '@mpaas/hriver';
import { H5AppCommonProviderImpl } from '../hriver/H5AppCommonProviderImpl';
import { CustomLoadingBuilderProviderImpl } from '../hriver/CustomLoadingBuilderProviderImpl';
import { H5WebClientProviderImpl } from '../hriver/H5WebClientProviderImpl';
import { MyH5UrlInterceptProvider } from '../hriver/MyH5UrlInterceptProvider';
import { MPRemoteLogger } from '@mpaas/masadapter';
import { MPConfigService } from '@mpaas/configservice';
import { HRiverMini } from '@mpaas/hrivermini';
import { MPRpc } from '@mpaas/rpc';
import { getTopAbility } from '../constants/Global';
import { common } from '@kit.AbilityKit';
import { HomeAbilityContext } from '../extensions/HomeAbilityContext';
import Framework from '@mpaas/apframework';
import { H5CustomPlugin } from '../hriver/H5CustomPlugin';

@Entry
@Component
struct PageSplash {
  @State message: string = 'Hello World';

  onPageShow(): void {
    AlertDialog.show(
      {
        title: '隐私权限',
        message: "1、在stage里边初始化mPaaS，执行MPFramework.create(app)\n" +
          "2、在启动页弹窗，点同意后，调用MPFramework.instance.notifyPrivacyAgreed()和执行其他组件的初始化",
        autoCancel: true,
        offset: { dx: 0, dy: -20 },
        gridCount: 3,
        primaryButton: {
          value: '取消',
          action: () => {
            console.info(Constants.TAG, 'Callback when the first button is clicked')
            exitApp()
          }
        },
        secondaryButton: {
          enabled: true,
          defaultFocus: true,
          style: DialogButtonStyle.HIGHLIGHT,
          value: '确认',
          action: () => {
            MPFramework.instance.notifyPrivacyAgreed()
            this.initMpaas()
          }
        },
        cancel: () => {
          console.info(Constants.TAG, 'Closed callbacks')
        }
      })
  }

  initMpaas() {
    console.log(Constants.TAG, "mPaaS init other compoment")
    //初始化RPC
    MPRpc.init();
    //设置全局拦截器
    MPRpc.addGlobalInterceptor(new MyInterceptor());
    // MPFramework.instance.appSecret = "e9cc9c9261784e726657a52ab2f98615";
    const instance: MPFramework = MPFramework.instance;
    const ctx: Context = instance.context
    setContext(ctx)
    instance.fetchAppInfo().then(appInfo => {
      console.info(Constants.TAG, `appinfo：JSON.stringify(appInfo)`)
    })

    //设置离线包配置  hriver初始化之前设置
    HRiver.setProvider(H5CommonAppProvider.name, new H5AppCommonProviderImpl())
    //初始化hriver
    HRiver.init()
    //自定义loading页面
    HRiver.setProvider(CustomLoadingBuilderProvider.name, new CustomLoadingBuilderProviderImpl())
    //自定义错误页
    HRiver.setProvider(H5WebClientProvider.name, new H5WebClientProviderImpl())
    //防止startApp页面抖动
    HRiver.disableIndexPage()
    HRiver.enableDebug(true)
    //拦截url
    HRiver.setProvider(H5UrlInterceptProvider.name, new MyH5UrlInterceptProvider());

    //移动分析
    MPRemoteLogger.init();
    //性能监控(crash、anr、自动化，启动卡死)
    MPRemoteLogger.initPerformanceTrack();
    // App启动完成的时候，调用下述代码通知完成启动
    MPRemoteLogger.startupFinish();
    // app启动的时候，调用下报活api
    MPRemoteLogger.reportActive();

    //开关
    MPConfigService.init()

    this.initMpaasMini()

    let a: object = HRiver.getAppList()
    console.info(Constants.TAG, `APPLIST: ${JSON.stringify(a)}`)
    console.log(Constants.TAG, "mPaaS init finish other compoment")

    this.openLogin()
  }

  initMpaasMini() {
    //小程序
    HRiverMini.registerExtension(() => {
      import('../extensions/CustomExtension')
    })
    HRiverMini.init()
    let applicationManager: ESObject = Framework.microApplicationContext["applicationManger"]
    if (applicationManager) {
      // 获取第二步缓存的TopUIAbility
      applicationManager["mTopAbility"] = getTopAbility()
      if (applicationManager["mAbilityInfoMap"]) {
        let map: Map<common.UIAbilityContext, ESObject> =
          applicationManager["mAbilityInfoMap"] as Map<common.UIAbilityContext, ESObject>
        let homeContext = new HomeAbilityContext(curUIAbilityContext())
        homeContext.setWindowStage(curWindowStage())
        map.set(curUIAbilityContext(), homeContext)
      }
    }
  }

  openLogin() {
    router.replaceUrl({
      url: 'pages/PageLogin',
      params: {
        data1: 'message'
      }
    }, callBack => {

    });
  }

  build() {
    Column() {
      Text(`启\n动\n页`)
        .fontSize(50)
        .fontColor(Color.White)
        .margin({ top: 120 })
    }
    .backgroundColor(Color.Blue)
    .width('100%')
    .height('100%')
  }
}