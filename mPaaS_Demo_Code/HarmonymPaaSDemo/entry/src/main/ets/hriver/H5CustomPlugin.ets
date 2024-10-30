import {
  AppManager,
  BroadcastManager,
  CommonEvents,
  getProxy,
  H5BridgeContext,
  H5Event,
  H5EventFilter,
  H5Param,
  H5Session,
  H5SimplePlugin,
  HRiver,
  Page,
  XRiverProxy
} from '@mpaas/hriver';
import { DialogMyCustom } from '../component/DialogMyCustom';
import { BannerModel } from '../rpc/EntityModel';
import AlertExit from '../component/CustomLoadingDialog';
import { promptAction, router } from '@kit.ArkUI';
import { Constants } from '../constants/Constants';
import { hilog } from '@kit.PerformanceAnalysisKit';
import RouterManager from '../constants/RouterManager';
import { MPFileUtils } from '../constants/MPFileUtils';
import { REQ_MODEL } from '../rpc/REQ_MODEL';
import { JSON } from '@kit.ArkTS';
import { systemDateTime } from '@kit.BasicServicesKit';

class H5CustomPlugin extends H5SimplePlugin {
  private select: number | number[] = 0
  private fruits: string[] = ['apple1', 'orange2', 'peach3', 'grape4', 'banana5']

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

  onPrepare(filter: H5EventFilter): void {
    filter.addAction('myapi1')
    filter.addAction('myapi2')
    filter.addAction('customHideTitleBar')
    filter.addAction('getPage')
    filter.addAction('plugin_dialog')
    filter.addAction("h5PagePhysicalBack")
    filter.addAction("jBack")
    filter.addAction("J_BACK_RESULT")
    filter.addAction("toNativeCallback")
    filter.addAction("removePage")
    filter.addAction("notifyN2h")
    filter.addAction("h5ToolbarBack")
    filter.addAction("J_BACK_SendEvent")
    filter.addAction('h5ToolbarMenuBt')
    filter.addAction('optionMenu')
    filter.addAction('getAPDataStorage')
    filter.addAction('hideStatusBar007')
    filter.addAction('showStatusBar007')
    filter.addAction("jBackResultPackage")
    filter.addAction("changeColor")
    filter.addAction("showCloseX")
    filter.addAction("sendMsgToPreviousPage")
    filter.addAction("h5ToolbarClose")
    filter.addAction("h5PageFinished")
    // filter.addAction("setTitle")
  }

  innerPlugin(): boolean {
    return true;
  }

  handleEvent(event: H5Event, context: H5BridgeContext): Boolean {
    // if ('setTitle' == event.action) {
    //   console.info(Constants.TAG, `titleinfo:${JSON.stringify(event.param)}`)
    //   let page = event.target as Page
    //   page.titleBarData.title = event.param
    //   return true
    // }
    // 默认导航栏 三个点的拦截事件
    // if ('optionMenu' == event.action) {
    //   promptAction.showToast({
    //     message: "拦截了三个点的点击"
    //   })
    //   return true
    // }
    if ('h5PageFinished' == event.action) {
      let page = event.target as Page
      if (page) {
        let a = page?.getSession().getActivePageCount()
        if (a > 1) {
          page.titleBarData.showCloseBtn = true
        }
      }
      return true
    }
    if ("h5ToolbarClose" == event.action) {
      //拦截导航栏的X
      HRiver.exitAllSession()
      return true
    }
    if ("sendMsgToPreviousPage" == event.action) {
      //给某个页面 resume 发消息---不生效
      let page = event.target as Page
      if (page) {
        let session = page.getSession()
        let pages = session?.getPages()
        if (pages && pages.length > 0) {
          for (let index = 0; index < pages.length - 1; index++) {
            let item = pages[index]
            console.info(Constants.TAG, `pageItem: ${item.pageUrl}`)
            if (item.pageUrl.includes('test.html')) {
              let h5Data = page.h5Session?.getData()
              h5Data?.set("h5_session_pop_param", JSON.stringify({ data: "也无风雨也无晴" }));
              page.sendEvent('h5PageResume')
              return true;
            }
          }
        }
      }
      return true
    }

    if ("getAllSessionPage" == event.action) {
      let appManager = getProxy(XRiverProxy.AppManager) as AppManager
      let listSession = appManager.getAllSession()
      for (let session of listSession) {
        console.log(Constants.TAG, `当前session: ${session}`)
        let pages = session?.getPages()
        if (pages && pages.length > 0) {
          for (let index = 0; index < pages.length - 1; index++) {
            let item = pages[index]
            console.info(Constants.TAG, `page: ${item.pageUrl}`)
          }
        }
      }
      return true
    }
    if ("changeColor" == event.action) {
      let page = event.target as Page
      //修改导航栏颜色
      page.titleBarData.titleColor = 0xffffff
      page.titleBarData.buttonColor = 0xffffff
      page.titleBarData.titleBackground = 0xff12de
      page.titleBarData.showBottomLine = false
      return true
    }
    if ("jBackResultPackage" == event.action) {
      let appManager = getProxy(XRiverProxy.AppManager) as AppManager
      let listSession = appManager.getAllSession()
      let resultData: REQ_MODEL = {
        userName: "夸包返回数据",
        password: "999999"
      }
      listSession[0].getData().set("h5_session_pop_param", JSON.stringify(resultData))
      context.sendBridgeResult({
        success: true,
        data: `返回跨包传参`
      })
      return true
    }
    if ("J_BACK_RESULT" == event.action) {
      //返回携带参数
      let page = event.target as Page
      let h5Data = page.getSession()?.getData()
      let resultData: REQ_MODEL = {
        userName: "同包返回数据",
        password: "1229993"
      }
      h5Data?.set("h5_session_pop_param", JSON.stringify(resultData));
      return true
    }
    if ("showCloseX" == event.action) {
      let page = event.target as Page
      console.info(Constants.TAG, `H5活动页数量： ${page.getSession().getActivePageCount()}`)
      if (page.getSession().getActivePageCount() > 1) {
        //判断是不是第一个page
        //是否显示X
        page.titleBarData.showCloseBtn = true
      }
      return true
    }
    if ("showStatusBar007" == event.action) {
      //非沉浸式 -没有标题，返回键
      let page = event.target as Page
      page.titleBarData.setTitleBarState(true)
      return true;
    }
    if ("hideStatusBar007" == event.action) {
      let page = event.target as Page
      //沉浸式 -没有标题，返回键
      page.titleBarData.setTitleBarState(false)
      //沉浸式2  有返回键和标题
      // page.titleBarData.setTitleTransparent('auto')

      // //是否显示X
      // page.titleBarData.showCloseBtn = true
      // //点击X调用的jsapi
      // page.sendEvent(CommonEvents.H5_PAGE_CLOSE)
      return true
    }
    if ("getAPDataStorage" == event.action) {
      promptAction.showToast({
        message: "拦截getAPDataStorage"
      })
      let params: ESObject = event.param
      let ckey = params['key'] as string
      MPFileUtils.getInstance().getFileByName(ckey).then(result => {
        context.sendBridgeResult({
          success: true,
          data: result
        })
      })
      return true
    }
    if ("h5PagePhysicalBack" == event.action) {
      let page = event.target as Page
      page.backClickEvent()
      console.info(Constants.TAG, `物理返回键返回`)
      promptAction.showToast({
        message: "物理返回键返回"
      })
      return true;
    }
    if ("removePage" == event.action) {
      //删除上一页，直接返回首页
      let page = event.target as Page
      let session = page.getSession()
      let pages = session?.getPages()
      if (pages && pages.length > 0) {
        for (let index = 0; index < pages.length - 1; index++) {
          let item = pages[index]
          console.info(Constants.TAG, `pageItem: ${item.pageUrl}`)
          if (item.pageUrl.includes('switch.html')) {
            item.sendEvent(CommonEvents.H5_PAGE_CLOSE)
            return true;
          }
        }
      }
      return true;
    }
    if ("getPage" == event.action) {
      let page: Page | undefined = event.target as Page
      // let a: string = event.param['param2'];
      console.log(Constants.TAG, `getPage99999 ${JSON.stringify(event.param)}`);
    }

    if ("toNativeCallback" == event.action) {
      context.sendBridgeResult({
        success: true,
        data: `跳转登录页获取返回值`
      })

      // //关闭离线包
      // let page = event.target as Page
      // page.backClickEvent()

      //router   打开登录页
      router.pushUrl({
        url: Constants.PAGE_LOGIN_CALLBACK
      }).catch((err: Error) => {
        hilog.error(0, Constants.TAG, "跳转报错：%{s}", err)
      });

      //Navigation  打开开关页
      // let bannnerModel: BannerModel = new BannerModel()
      // bannnerModel.desc = "this params from PageConfig"
      // let navPathInfo = new NavPathInfo("PageConfig", bannnerModel, (popinfo: PopInfo) => {
      //   let result = popinfo.result as BannerModel
      //   console.info(Constants.TAG, `回执传参：${JSON.stringify(result)}`)
      // })
      // RouterManager.pushPath(navPathInfo, true)

      return true;
    }
    //西安银行
    if ("goHome" == event.action) {
      let page = event.target as Page
      page.backClickEvent()
      return true;
    }

    if ("J_BACK_SendEvent" == event.action) {
      //这是通过sendEvent H5_PAGE_CLOSE移除指定页的方式
      let page = event.target as Page
      let session = page.getSession()
      let pages = session?.getPages()
      if (pages && pages.length > 0) {
        for (let index = pages.length - 1; index > 0; index--) {
          let item = pages[index]
          console.info(Constants.TAG, `pageItem: ${item.pageUrl}`)
          if (item.pageUrl.includes('switch.html')) {
            item.sendEvent(CommonEvents.H5_PAGE_CLOSE)
          }
          if (item.pageUrl.includes('test.html')) {
            item.sendEvent(CommonEvents.H5_PAGE_CLOSE)
          }
          if (item.pageUrl.includes('test2.html')) {
            item.sendEvent(CommonEvents.H5_PAGE_CLOSE)
          }
        }
      }
      return true;
    }
    if ("jBack" == event.action) {
      // let page = event.target as Page
      // if (page.webcontroller?.accessBackward()) {
      //   page.webcontroller?.backward()
      // } else {
      //   page.getApp().exit()
      // }

      //这是navigation移除指定page的方式
      RouterManager.removeByIndexes([2, 3])
      return true;
    }
    if ('plugin_dialog' == event.action) {
      //弹个窗助助兴
      AlertExit.showAlertEx((err, data) => {

      })
      // this.datePick(context)
      // this.textPick(context)

      let page = event.target as Page
      page.sendToWeb('testAction', { data: 'native sendtoweb 啊啊啊啊' })
      return true;
    }
    if ('notifyN2h' == event.action) {
      BroadcastManager.getInstance().notify("fortest", "native-测试通知数据")
      return true;
    }
    if ('customHideTitleBar' == event.action) {
      let page: Page | undefined = event.target as Page
      let isSetTitleBarState: string = event.param.param2
      if (isSetTitleBarState == 'YES') {
        page.titleBarData.setTitleBarState(true)
      } else if (isSetTitleBarState == 'NO') {
        page.titleBarData.setTitleBarState(false)
      }
    }
    if ('myapi1' == event.action) {
      let a: string = event.param['param1'];
      RouterManager.stackInfo()

      context.sendBridgeResultWithCallbackKept({
        success: true,
        data: `myapi1调用成功1，入参：${a}`
      })
      context.sendBridgeResultWithCallbackKept({
        success: true,
        data: `myapi1调用成功2，入参：${a}`
      })
      context.sendBridgeResultWithCallbackKept({
        success: true,
        data: `myapi1调用成功3，入参：${a}`
      })

      //这是页面退出的方法
      let page = event.target as Page
      // event.param
      // page.getApp().exit()

      //自定义导航栏数据
      page.titleBarData.title = "这是自定义标题"
      page.titleBarData.readTitle = false

      //导航栏底部分割线
      // page.titleBarData.showBottomLine = false
      //状态栏颜色
      // page.titleBarData.statusBarColor = Color.Transparent
      //是否显示状态栏  无效
      page.titleBarData.forceShowStatusBar = false
      /**
       * 这俩方法不能共用 showTitleBar  setTitleBarState
       */
      //隐藏标题栏   H5加载的时候调研自定义jsapi隐藏导航栏
      // page.titleBarData.showTitleBar = false
      //方法控制titlebar是否显示
      page.titleBarData.setTitleBarState(true)
      // page.titleBarData.barBottomLineColor =  0xff12de

      //有效
      let aNum = Math.random() * 100 | 0
      let titleModel = new BannerModel();
      titleModel.desc = `${aNum}`
      page.titleBarData.customData = titleModel;

      //有效
      let bNum = Math.random() * 100 | 0
      page.titleBarData.customData['imgUrl'] = `imgUrl-${bNum}`
      return true
    }

    if ('myapi2' == event.action) {
      // context.sendBridgeResult({
      //   success: true,
      //   data: 'myapi2调用成功'
      // })
      //这是页面退出的方法
      let page = event.target as Page
      // event.param
      // page.getApp().exit()

      //to be verify 这是检测页面退出的方法,适用于前端router跳转的退出方法， 针对this.$router.push的跳转方式
      // if (page.webcontroller?.accessBackward()) {
      //   page.webcontroller?.backward()
      // } else {
      //   page.getApp().exit()
      // }
      //还有一个回退方法
      // page.backClickEvent()

      //全部退出，退出所有打开的离线包
      // HRiver.exitAllSession(true)

      // console.info(Constants.TAG, `模拟异步请求 0`)
      // this.executeMockSync()
      // console.info(Constants.TAG, `模拟异步请求 1`)


      console.info(Constants.TAG, `异步执行开始`)
      //测试异步-promise
      this.mockSyncPromise().then((str: String) => {
        console.info(Constants.TAG, `异步执行完成 ${str}`)
        context.sendBridgeResult({
          success: true,
          data: 'myapi2调用成功'
        })
      })
      return true
    }
    return super.handleEvent(event, context);
  }

  //模拟await请求===============================start
  async executeMockSync() {
    console.info(Constants.TAG, `模拟异步请求 2`)
    await this.mockSync()
    console.info(Constants.TAG, `模拟异步请求 3`)
  }

  mockSync(): string {
    console.info(Constants.TAG, `模拟异步请求 4`)
    setTimeout(() => {
      console.info(Constants.TAG, `模拟异步请求 6`)
      return "mockSync sync finish"
    }, 3000)
    console.info(Constants.TAG, `模拟异步请求 5`)
    return "mockSync finish"
  }

  //模拟await请求===============================end


  //模拟promise请求===============================start
  mockSyncPromise(): Promise<string> {
    return new Promise((resolve) => {
      setTimeout(() => {
        resolve("完事拉")
      }, 2000)
    })
  }

  //模拟promise请求===============================end

  interceptEvent(event: H5Event, context: H5BridgeContext): Boolean {
    console.info(Constants.TAG, `插件拦截-interceptEvent ${event.action}}`)
    //默认导航栏 右上3个点内部弹窗的点击事件（注意这里不是3个点的点击事件）
    // if ('h5ToolbarMenuBt' == event.action) {
    //   //从tag类型判断按钮
    //   let param: ESObject = event.param
    //   let tag = param[H5Param.MENU_TAG] as string
    //   promptAction.showToast({
    //     message: "拦截了三个点内部弹框的点击"
    //   })
    //   return false
    // }
    if ('h5ToolbarBack' == event.action) {
      console.info(Constants.TAG, `hriver导航栏返回`)
      promptAction.showToast({
        message: "hriver导航栏返回"
      })
      return false
    }
    return false;
  }
  datePick(context:H5BridgeContext){
    let selectedDate: Date = new Date("2010-1-1")
    DatePickerDialog.show({
      start: new Date("2000-1-1"),
      end: new Date("2100-12-31"),
      selected: selectedDate,
      showTime:true,
      useMilitaryTime:false,
      disappearTextStyle: {color: Color.Pink, font: {size: '22fp', weight: FontWeight.Bold}},
      textStyle: {color: '#ff00ff00', font: {size: '18fp', weight: FontWeight.Normal}},
      selectedTextStyle: {color: '#ff182431', font: {size: '14fp', weight: FontWeight.Regular}},
      onDateAccept: (value: Date) => {
        // 通过Date的setFullYear方法设置按下确定按钮时的日期，这样当弹窗再次弹出时显示选中的是上一次确定的日期
        selectedDate = value
        console.info("DatePickerDialog:onDateAccept()" + value.toString())
        let a  =  context.sendBridgeResultWithCallbackKept({
          success: true,
          data: `点了弹窗的onAccept`
        })
      },
      onCancel: () => {
        console.info("DatePickerDialog:onCancel()")
        let a  = context.sendBridgeResultWithCallbackKept({
          success: true,
          data: `点了弹窗的onAccept`
        })
      },
      onDateChange: (value: Date) => {
        console.info("DatePickerDialog:onDateChange()" + value.toString())
        let a  =  context.sendBridgeResultWithCallbackKept({
          success: true,
          data: `点了弹窗的onDateChange`
        })
      }
    })
  }

  textPick(context:H5BridgeContext){
    TextPickerDialog.show({
      range: this.fruits,
      selected: this.select,
      disappearTextStyle: {color: Color.Red, font: {size: 15, weight: FontWeight.Lighter}},
      textStyle: {color: Color.Black, font: {size: 20, weight: FontWeight.Normal}},
      selectedTextStyle: {color: Color.Blue, font: {size: 30, weight: FontWeight.Bolder}},
      onAccept: (value: TextPickerResult) => {
        // 设置select为按下确定按钮时候的选中项index，这样当弹窗再次弹出时显示选中的是上一次确定的选项
        this.select = value.index
        console.log(this.select + '')
        // 点击确定后，被选到的文本数据展示到页面
        // this.v = value.value as string
        console.info(Constants.TAG,"TextPickerDialog:onAccept()" + JSON.stringify(value))
        context.sendBridgeResult({
          success: true,
          data: `点了弹窗的onAccept`
        })
      },
      onCancel: () => {
        console.info(Constants.TAG,"TextPickerDialog:onCancel()")
        context.sendBridgeResultWithCallbackKept({
          success: true,
          data: `点了弹窗的onCancel`
        })
      },
      onChange: (value: TextPickerResult) => {
        console.info(Constants.TAG,"TextPickerDialog:onChange()" + JSON.stringify(value))
        context.sendBridgeResultWithCallbackKept({
          success: true,
          data: `点了弹窗的onChange`
        })
      }
    })

  }
}


export { H5CustomPlugin }

// if (page.getApp().getPageByIndex(0).pageUrl == page.pageUrl){
//   //判断是不是第一个page
//   //是否显示X
//   page.titleBarData.showCloseBtn = true
//   //点击X调用的jsapi
//   page.sendEvent(CommonEvents.H5_PAGE_CLOSE)
// }