import { H5RouterNavStackProvider, Page } from '@mpaas/hriver';

export class NavStackProvider extends H5RouterNavStackProvider {
  navStack: NavPathStack // 全局的navPathStack栈
  constructor(navStack: NavPathStack) {
    super();
    this.navStack = navStack;
  }

  getNavPathStack(): NavPathStack {
    return this.navStack
  }

  getPagePathStack(page: Page): NavPathStack | undefined {
    if (page.embedPage) {
      // 内嵌场景，页面跳转时使用全局navPathStack。业务根据实际情况返回对应NavPathStack
      return this.getNavPathStack()
    }
    return super.getPagePathStack(page);
  }
}