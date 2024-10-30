import { Constants } from './Constants'
import { JSON } from '@kit.ArkTS'

class RouterManager {
  pageNavPathStack: NavPathStack | null = null

  createNavPathStackByPage(n1: NavPathStack) {
    this.pageNavPathStack = n1
    this.stackInfo()
  }

  //跳转页面
  pushPath(info: NavPathInfo, animated?: boolean) {
    this.pageNavPathStack?.pushPath(info, animated)
    this.stackInfo()
  }

  pop1(animated?: boolean): NavPathInfo | undefined {
    let a: NavPathInfo | undefined = this.pageNavPathStack?.pop(animated)
    this.stackInfo()
    return a
  }

  replacePathByName(name: string, param: Object, animated?: boolean) {
    this.pageNavPathStack?.replacePathByName(name, param, animated)
    this.stackInfo()
  }

  removeByIndexes(indexes: Array<number>): number | undefined {
    let a: number | undefined = this.pageNavPathStack?.removeByIndexes(indexes)
    this.stackInfo()
    return a
  }

  //返回
  pop(result: Object, animated?: boolean): NavPathInfo | undefined {
    let a: NavPathInfo | undefined = this.pageNavPathStack?.pop(result, animated)
    this.stackInfo()
    return a
  }

  //移除某个router by name
  removeByName(name: string) {
    this.pageNavPathStack?.removeByName(name)
    this.stackInfo()
  }

  //移除某个router by name
  clear(animated?: boolean) {
    this.pageNavPathStack?.clear(animated)
    this.stackInfo()
  }

  //栈信息
  stackInfo() {
    let array: String[] | undefined = this.pageNavPathStack?.getAllPathName()
    if (array != undefined) {
      console.info(Constants.TAG, `stack is：${JSON.stringify(array)}`)
    } else {
      console.info(Constants.TAG, `stack is null`)
    }
  }
}

export default new RouterManager()