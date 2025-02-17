import { H5PageLifeCycleProvider, Page } from '@mpaas/hriver';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { promptAction, router } from '@kit.ArkUI';
import { Constants } from '../constants/Constants';
import data from '@ohos.telephony.data';
import { webview } from '@kit.ArkWeb';
import { HriverPageUtils } from '../constants/HriverPageUtils';

//拦截嵌入式H5的返回事件
export class H5PageLifeCycle extends H5PageLifeCycleProvider {
  count: number = 0

  onBackPress(page?: Page | undefined): boolean {
    // 默认写法
    // let navPathStack: NavPathStack|undefined = page?.getSession()?.getRouter()?.getNavPathStack()
    // let activePageSize = page?.getSession()?.getActivePageCount() || 0
    // if (navPathStack && page && page.embedPage && navPathStack.size() == 1 && activePageSize == 1) {
    //   router.back()
    //   return true;
    // }
    // return super.onBackPress(page);


    console.info(Constants.TAG, `H5PageLifeCycle onBackPress=${page?.pageUrl}`)
    let navPathStack: NavPathStack | undefined = page?.getSession()?.getRouter()?.getNavPathStack()
    let activePageSize = page?.getSession()?.getActivePageCount() || 0
    if (navPathStack && page && page.embedPage && navPathStack.size() == 1 && activePageSize == 1) {
      console.info(Constants.TAG, `触发返回`)
      setTimeout(() => {
        this.count = 0
      }, 500)
      if (this.count == 0) {
        this.count++
        promptAction.showToast({
          message: "返回两次退出"
        })
        return true
      }
      if (this.count > 0) {
        router.back()
        this.count = 0
      } else {
        this.count++
        promptAction.showToast({
          message: "返回两次退出"
        })
      }
      return true;
    }
    return super.onBackPress(page);
  }

  onPageShow(routerName: string, page?: Page | undefined): void {
    super.onPageShow(routerName, page);
    let navPathStack: NavPathStack | undefined = page?.getSession()?.getRouter()?.getNavPathStack()
    if (navPathStack && page) {
      let array: String[] | undefined = navPathStack.getAllPathName()
      if (array != undefined) {
        console.info(Constants.TAG, `stack is：${JSON.stringify(array)}`)
      } else {
        console.info(Constants.TAG, `stack is null`)
      }
    }
    let sessiona = page?.getSession()
    let pages = sessiona?.getPages
    // if (page) {
    //   page.sendToWeb('testAction', { data: 'this data from native lifecycle onPageShow()' })
    // }
    console.info(Constants.TAG, `H5PageLifeCycle onPageShow=${page?.pageUrl}  page数量：${pages?.length} nav数量：${page?.getSession()?.getRouter()?.getNavPathStack()?.size()}`)
  }

  onPageHide(routerName: string, page?: Page | undefined): void {
    super.onPageHide(routerName, page);
    let sessiona = page?.getSession()
    let pages = sessiona?.getPages
    console.info(Constants.TAG, `H5PageLifeCycle onPageHide=${page?.pageUrl}  page数量：${pages?.length} nav数量：${page?.getSession()?.getRouter()?.getNavPathStack()?.size()}`)
  }

  onPageCreate(page?: Page | undefined): void {
    super.onPageCreate(page);
    let sessiona = page?.getSession()
    let pages = sessiona?.getPages
    // if (page) {
    //   page.sendToWeb('testAction', { data: 'this data from native lifecycle onPageCreate()' })
    // }
    console.info(Constants.TAG, `H5PageLifeCycle onPageCreate=${page?.pageUrl}  page数量：${pages?.length} nav数量：${page?.getSession()?.getRouter()?.getNavPathStack()?.size()}`)
  }

  onPageExit(page?: Page | undefined): void {
    super.onPageExit(page);
    let sessiona = page?.getSession()
    let pages = sessiona?.getPages
    HriverPageUtils
      .getInstance()
      .removePageNum()
    console.info(Constants.TAG, `H5PageLifeCycle onPageExit=${page?.pageUrl}  page数量：${pages?.length} nav数量：${page?.getSession()?.getRouter()?.getNavPathStack()?.size()}`)
  }
}