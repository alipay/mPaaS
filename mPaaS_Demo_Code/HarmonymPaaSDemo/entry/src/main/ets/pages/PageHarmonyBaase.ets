import { hilog } from '@kit.PerformanceAnalysisKit';
import { DialogMyCustom } from '../component/DialogMyCustom';
import { TitleComponent } from '../component/TitleComponent';
import { Constants } from '../constants/Constants';
import { DLogger } from '../logger/DLogger';
import { promptAction, router } from '@kit.ArkUI';
import { abilityAccessCtrl, bundleManager, common, Permissions, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { add } from 'library/Index';
import { BannerModel } from '../rpc/EntityModel';
import Router007Manager from '../constants/Router007Manager';
import RouterManager from '../constants/RouterManager';
import { checkPermissionGrant, permissionsList, reqPermissionsFromUser } from '../constants/PermissionUtils';
import { curUIAbilityContext } from '../constants/Global';
import AlertExit from '../component/CustomLoadingDialog';

@Builder
export function getPageHarmonyBaase(): void {
  PageHarmonyBaase()
}

@Component
export struct PageHarmonyBaase {
  @State message: string = 'Hello World';
  private context = getContext(this) as common.UIAbilityContext;
  // private navPathStack: NavPathStack = new NavPathStack()
  dialogController: CustomDialogController = new CustomDialogController({
    builder: DialogMyCustom({
      cancel: (): void => this.onCancel(),
      confirm: (): void => this.onAccept()
    }),
    cancel: this.exitApp,
    autoCancel: true,
    alignment: DialogAlignment.Bottom,
    offset: { dx: 0, dy: -20 },
    gridCount: 4,
    customStyle: false,
    cornerRadius: 10
  })

  onCancel() {
    console.info('Callback when the first button is clicked')
  }

  onAccept() {
    console.info('Callback when the second button is clicked')
  }

  exitApp() {
    console.info('Click the callback in the blank area')
  }

  aboutToAppear(): void {
    // Router007Manager.createNavPathStackByPage(this.navPathStack)
  }

  base1() {
    let a: string | number
    a = "test"
    DLogger.error("联合类型", a)
    a = 100;
    DLogger.error("联合类型", a + "")
  }

  //测试数据
  testArray() {
    let testArray: Array<string> = []
    testArray[3] = "张三"
    testArray[4] = "李四"
    console.error(Constants.TAG, testArray.toString())
    testArray[3] = "无敌"
    console.error(Constants.TAG, testArray.toString())
    testArray.length = 0
    console.error(Constants.TAG, testArray.toString())
  }

  private isShow: boolean = true;

  testPromise(): Promise<String> {
    return new Promise((reslove, reject) => {
      if (this.isShow) {
        console.log(Constants.TAG, `1`)
        setTimeout(() => {
          reslove("模拟请求返回数据")
        }, 2000)
        console.log(Constants.TAG, `2`)
      } else {
        reject("已拒绝")
      }
    })
  }

  //https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Promise/Promise
  testPromise1(): Promise<string> {
    const promise1 = new Promise<string>((resolve, reject) => {
      setTimeout(() => {
        resolve('foo');
      }, 300);
    });

    promise1.then((value) => {
      console.log(value);
      // Expected output: "foo"
    });

    console.log("hello world");
    //Argument of type 'Promise<string>' is not assignable to parameter of type 'string'.
    // console.log(promise1);
    // Expected output: [object Promise]

    return promise1
  }

  openPermissionSettings() {
    let bundleInfo = bundleManager.getBundleInfoForSelfSync(bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_APPLICATION)
    let wantInfo: Want = {
      bundleName: 'com.huawei.hmos.settings',
      abilityName: 'com.huawei.hmos.settings.MainAbility',
      uri: 'application_info_entry',
      parameters: {
        pushParams: bundleInfo.name
      }
    }
    this.context.startAbility(wantInfo).then(() => {
      console.info(Constants.TAG, `跳转系统设置:success`);
    }).catch((err: BusinessError) => {
      console.error(Constants.TAG, `跳转系统设置:${JSON.stringify(err)}}`);
    })
  }

  //获取授权
  async checkPermissions(permissions: Array<Permissions>): Promise<void> {
    let grantStatus: abilityAccessCtrl.GrantStatus = await checkPermissionGrant(permissions[0]);
    if (grantStatus === abilityAccessCtrl.GrantStatus.PERMISSION_GRANTED) {
      // 已经授权，可以继续访问目标操作

    } else {
      // 申请定位权限
      // 申请定位权限
      reqPermissionsFromUser(permissions, curUIAbilityContext()).then(() => {
        promptAction.showToast({
          message:"授权成功"
        })
      }).catch((err:Error)=>{
        promptAction.showToast({
          message:"授权失败"
        })
      })
    }
  }

  build() {
    NavDestination() {
      // Navigation(this.navPathStack) {
        Column() {
          TitleComponent({ title: "鸿蒙基础" })
          Scroll() {
            Column() {
              Button("获取定位权限")
                .width('90%')
                .fontSize(16)
                .onClick(() => {
                  this.checkPermissions(permissionsList)
                })
                .margin({ top: 10 })
              Button("跳转设置")
                .width('90%')
                .fontSize(16)
                .onClick(() => {
                  this.openPermissionSettings()
                })
                .margin({ top: 10 })
              Button("其他Router007Manager(mini)")
                .width('90%')
                .fontSize(16)
                .onClick(() => {
                  RouterManager.pop1(false)

                  let bannnerModel: BannerModel = new BannerModel()
                  bannnerModel.desc = "this params from PageMini"
                  let navPathInfo = new NavPathInfo("PageMini", bannnerModel, (popinfo: PopInfo) => {
                    let result = popinfo.result as BannerModel
                    console.info(Constants.TAG, `回执传参：${JSON.stringify(result)}`)
                  })
                  Router007Manager.pushPath(navPathInfo, true)
                })
                .margin({ top: 10 })
              Button("TestPageNavigationChild")
                .width('90%')
                .fontSize(16)
                .onClick(() => {
                  router.pushUrl({
                    url: Constants.TestPageNavigationChild
                  }).catch((err: Error) => {
                    hilog.error(0, Constants.TAG, "跳转报错：%{s}", err)
                  });
                })
                .margin({ top: 10 })
              Button("Navigation999")
                .width('90%')
                .fontSize(16)
                .onClick(() => {
                  router.pushUrl({
                    url: Constants.TEST_PAGENAVIGATION999
                  }).catch((err: Error) => {
                    hilog.error(0, Constants.TAG, "跳转报错：%{s}", err)
                  });
                })
                .margin({ top: 10 })
              Button("Navigation10")
                .width('90%')
                .fontSize(16)
                .onClick(() => {
                  router.pushUrl({
                    url: Constants.TEST_PAGENAVIGATION10
                  }).catch((err: Error) => {
                    hilog.error(0, Constants.TAG, "跳转报错：%{s}", err)
                  });
                })
                .margin({ top: 10 })
              Button("Navigation1")
                .width('90%')
                .fontSize(16)
                .onClick(() => {
                  router.pushUrl({
                    url: Constants.TEST_PAGENAVIGATION1
                  }).catch((err: Error) => {
                    hilog.error(0, Constants.TAG, "跳转报错：%{s}", err)
                  });
                })
                .margin({ top: 10 })
              Button("Navigation")
                .width('90%')
                .fontSize(16)
                .onClick(() => {
                  router.pushUrl({
                    url: Constants.TEST_PAGENAVIGATION
                  }).catch((err: Error) => {
                    hilog.error(0, Constants.TAG, "跳转报错：%{s}", err)
                  });
                })
                .margin({ top: 10 })
              Button("自定义弹窗")
                .width('90%')
                .fontSize(16)
                .onClick(() => {
                  // this.dialogController.open()
                  AlertExit.showAlertEx((err, data) => {

                  })
                })
                .margin({ top: 10 })
              Button("数组")
                .fontSize(16)
                .width('90%')
                .onClick(() => {
                  this.testArray()
                })
                .margin({ top: 10 })
              Button("promise")
                .fontSize(16)
                .width('90%')
                .onClick(() => {
                  this.testPromise().then((result) => {
                    console.log(Constants.TAG, `测试promise  ${result}`,)
                  }).catch((e: Error) => {
                    console.log(Constants.TAG, `error ${e.message}  ${e.name}`)
                  })
                })
                .margin({ top: 10 })
              Button("promise1")
                .fontSize(16)
                .width('90%')
                .onClick(() => {
                  this.testPromise1()
                })
                .margin({ top: 10 })
              Button("WEB")
                .fontSize(16)
                .width('90%')
                .onClick(() => {
                  router.pushUrl({
                    url: Constants.PAGE_WEB
                  }).catch((err: Error) => {
                    hilog.error(0, Constants.TAG, "跳转报错：%{s}", err)
                  });
                })
                .margin({ top: 10 })
              Button("@state @link @Watch")
                .fontSize(16)
                .width('90%')
                .onClick(() => {
                  router.pushUrl({
                    url: Constants.PAGE_TASK
                  })
                })
                .margin({ top: 10 })
              Button("@provide @Consume")
                .fontSize(16)
                .width('90%')
                .onClick(() => {
                  router.pushUrl({
                    url: Constants.PAGE_PROVIDE_COMSUME
                  })
                })
                .margin({ top: 10 })
              Button("打开其他module的ability")
                .fontSize(16)
                .width('90%')
                .margin({ top: 10 })
                .fontWeight(FontWeight.Bold)
                .onClick(() => {
                  let context: common.UIAbilityContext = this.context; // UIAbilityContext
                  let want: Want = {
                    deviceId: '', // deviceId为空表示本设备
                    bundleName: 'com.mpaas.harmonydemo',
                    moduleName: 'TestModule', // moduleName非必选
                    abilityName: 'TestModuleAbility',
                    parameters: {
                      // 自定义信息
                      info: '来自entry module的数据',
                    },
                  }
                  // context为调用方UIAbility的UIAbilityContext
                  context.startAbility(want).then(() => {
                    console.info(Constants.TAG, `Succeeded in starting ability.`);
                  }).catch((err: BusinessError) => {
                    console.error(Constants.TAG,
                      `Failed to start ability. Code is ${err.code}, message is ${err.message}`);
                  })
                })
              Button("router打开其他module page")
                .fontSize(16)
                .margin({ top: 10 })
                .width('90%')
                .fontWeight(FontWeight.Bold)
                .onClick(() => {
                  add(1, 1)
                  router.pushUrl({
                    url: '@bundle:com.mpaas.harmonydemo/BasicSharedModule/ets/pages/Index',
                    params: {
                      userName: "lilin",
                      passWord: "taogev587"
                    }
                  }).catch((err: Error) => {
                    console.error(Constants.TAG, `跳转报错 ${err}`)
                  });
                })
              Button("navigation打开其他module page")
                .fontSize(16)
                .margin({ top: 10 })
                .width('90%')
                .fontWeight(FontWeight.Bold)
                .onClick(() => {
                  let bannnerModel: BannerModel = new BannerModel()
                  bannnerModel.desc = "this params from PageHarmonyBaase"
                  let navPathInfo = new NavPathInfo("OtherPageMain", bannnerModel, (popinfo: PopInfo) => {
                    let result = popinfo.result as BannerModel
                    console.info(Constants.TAG, `回执传参：${JSON.stringify(result)}`)
                  })
                  RouterManager.pushPath(navPathInfo, true)
                })
              Button("scroll")
                .fontSize(16)
                .margin({ top: 10 })
                .width('90%')
                .fontWeight(FontWeight.Bold)
                .onClick(() => {
                  add(1, 1)
                  router.pushUrl({
                    url: Constants.PAGE_SCROLL,
                    params: {
                      userName: "lilin",
                      passWord: "taogev587"
                    }
                  }).catch((err: Error) => {
                    console.error(Constants.TAG, `跳转报错 ${err}`)
                  });
                })
            }
          }
          .backgroundColor(0xDCDCDC)
          .scrollable(ScrollDirection.Vertical) // 滚动方向为垂直方向
          .scrollBar(BarState.On) // 滚动条常驻显示
          .scrollBarWidth(10) // 滚动条宽度
          .edgeEffect(EdgeEffect.Spring) // 滚动到边沿后回弹
          .width('100%')
        }
        .width('100%')
        .height('100%')
      }
    // }
    // .hideTitleBar(true)
  }
}