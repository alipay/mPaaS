import { Constants } from './Constants'

class Router007Manager {
  pageNavPathStack: NavPathStack | null = null

  createNavPathStackByPage(n1: NavPathStack) {
    this.pageNavPathStack = n1
  }

  //跳转页面
  pushPath(info: NavPathInfo, animated?: boolean) {
    this.pageNavPathStack?.pushPath(info, animated)
  }

  pop1(animated?: boolean): NavPathInfo | undefined {
    return this.pageNavPathStack?.pop(animated)
  }

  //返回
  pop(result: Object, animated?: boolean): NavPathInfo | undefined {
    return this.pageNavPathStack?.pop(result, animated)
  }

  //移除某个router by name
  removeByName(name: string) {
    this.pageNavPathStack?.removeByName(name)
  }

  //移除某个router by name
  clear(animated?: boolean) {
    this.pageNavPathStack?.clear(animated)
  }
}

export default new Router007Manager()