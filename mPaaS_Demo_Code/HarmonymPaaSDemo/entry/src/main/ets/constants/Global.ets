import { common, UIAbility } from '@kit.AbilityKit'
import { window } from '@kit.ArkUI'
import systemDateTime from '@ohos.systemDateTime'
import { ArkTSUtils, JSON, util } from '@kit.ArkTS'
import { Constants } from './Constants'
import { BusinessError } from '@kit.BasicServicesKit'

/**
 * 全局扩展
 */


/**
 * 获取当前的context
 */
let context: Context
let uiAbilityContext: common.UIAbilityContext
let windowStage: window.WindowStage
//app启动时间戳
let startTime: number
//app启动结束时间戳
let startEndTime: number
//app启动耗时时间戳
let startConsumeTime: number
//状态栏高度
let systemStatusBarHeight: number

export function setSystemStatusBarHeight(temp: number) {
  systemStatusBarHeight = temp
}

//当前状态栏高度
export function curSystemStatusBarHeight(): number {
  return systemStatusBarHeight
}

export function setContext(curContext: Context) {
  context = curContext
}

//当前context
export function curContext(): Context {
  return context
}

export function setWindowStage(windowS: window.WindowStage) {
  windowStage = windowS
}

//当前WindowStage
export function curWindowStage(): window.WindowStage {
  return windowStage
}

//当前UIContext
export function curUIContext(): UIContext {
  return curWindowStage().getMainWindowSync().getUIContext()
}

//当前context
export function setUIAbilityContext(a: common.UIAbilityContext) {
  uiAbilityContext = a
}

export function curUIAbilityContext(): common.UIAbilityContext {
  return uiAbilityContext
}





//退出app
export function exitApp() {
  (curContext() as common.UIAbilityContext).terminateSelf();
}

/**
 * ArkTS方法入参是接口，如何传参，以systemDateTime.getCurrentTime为例子，
 * 原始方法为：function getCurrentTime(isNano: boolean, callback: AsyncCallback<number>): void;
 * Q：callback需要如何传参？
 * A：需要先检查AsyncCallback内部的方法，可以看到是(err: BusinessError<E>, data: T): void;
 * 冒号前边是变量，冒号后边是类型，先看冒号前边，()包裹起来的，表示是一个方法，再看冒号后边，可以看到此方法的返回类型是void，所以可以直接先这么写
 * ()=>{
 * }
 * 然后再关注变量(方法)的入参，变量(err: BusinessError<E>, data: T)表示此方法的入参
 * 第一个参数为BusinessError<E>，不知道该怎么写，第二个参数T可以看到AsyncCallback的类型为AsyncCallback<number>，所以T为number
 * 其实这里也不可以不用关注类型，只需要知道是俩参数，然后把刚才的写法改造下
 * (a,b)=>{
 * }
 *
 * 还有一种场景，以HRiverMiniEngine.sendToRender为例子，
 * 原始方法为：static sendToRender(render: Render | null, eventName: string, data: Record<string, Object>, callback?: SendToRenderCallback | undefined): void;
 * 这里主要关注callback?: SendToRenderCallback | undefined
 * 接口里的原始方法是这样的：onCallBack: (result: Record<string, object>) => void;
 * 冒号前是变量，冒号后是类型
 * 可以看到变量是onCallBack，(result: Record<string, object>)，如上所述，()包裹起来的是方法，所以可以直接写成
 * ()=>{
 * }
 * 但发现会报错，那是因为这个方法赋值给了一个变量，所以要改下，至于为什么要这么写，我也不太清楚，记住就行
 * {
 *    onCallBack: (result: Record<string, object>) =>{
 *    }
 * }
 * 总结：
 * 1、如果方法的入参是一个接口，接口的方法有变量名，如下
 * a:()=>void,入参则要这么传
 * {
 *  a:()=>{
 *  }
 * }
 * 2、如果方法的入参是一个接口，接口的方法无变量名，如下
 * ():void,入参则要这么传
 * ()=>{
 * }
 *
 * 备注：()里的参数不变
 */


//app启动耗时  启动时间
export function setStartTime() {
  systemDateTime.getCurrentTime(false, (a, b) => {
    if (a != undefined) {
      console.info(Constants.TAG, `获取时间戳报错：${JSON.stringify(a)}`)
    }
    if (b != undefined) {
      console.info(Constants.TAG, `app启动开始获取时间戳：${b}`)
      startTime = b
    }
  })
}

//app启动耗时  启动时间
export function setStartEndTime() {
  systemDateTime.getCurrentTime(false, (a, b) => {
    if (a != undefined) {
      console.info(Constants.TAG, `获取时间戳报错：${JSON.stringify(a)}`)
    }
    if (b != undefined) {
      startEndTime = b
      startConsumeTime = startEndTime - startTime
      console.info(Constants.TAG, `app启动结束取时间戳：${b}`)
      console.info(Constants.TAG, `app启动耗时：${startConsumeTime}`)
    }
  })
}

//启动耗时
export function getStartConsumeTime(): number {
  return startConsumeTime
}

export function getLoaclJson(fileName: string): Promise<string> {
  return new Promise((resolve: Function, reject: Function) => {
    try {
      curContext().resourceManager.getRawFileContent(fileName, (err, value) => {
        if (!!err) {
          reject(err)
          return
        }
        let rawFile = value;
        let textDecoder = util.TextDecoder.create('utf-8', { ignoreBOM: true })
        let result = textDecoder.decodeWithStream(rawFile, { stream: false });
        resolve(result)
      });
    } catch (error) {
      let code = (error as BusinessError).code;
      let message = (error as BusinessError).message;
      console.error(`callback getRawFileContent failed, error code: ${code}, message: ${message}.`);
    }
  });
}

/**
 * 获取系统状态栏，导航栏高度
 * @param context
 * @returns
 */
export async function getWindowAvoidArea(context: common.UIAbilityContext): Promise<window.AvoidArea | null> {
  try {
    const mainWindow = await window.getLastWindow(context);
    const avoidAreaType = window.AvoidAreaType.TYPE_SYSTEM; // 系统默认区域，包括状态栏，导航栏
    const avoidArea = mainWindow.getWindowAvoidArea(avoidAreaType);
    const height = avoidArea.topRect.height;
    return avoidArea
  } catch (e) {
    console.error(Constants.TAG, 'getWindowAvoidArea fail');
    return null
  }
}

let topAbility: UIAbility | undefined

export function setTopAbility(ability: UIAbility | undefined) {
  // 首页真正退出时记得置空，避免内存泄漏
  topAbility = ability
}

export function getTopAbility() {
  return topAbility
}