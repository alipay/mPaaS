import { CRVPage, MYNavigationBarAdapter } from '@mpaas/nebulaintegration';
import { TinyMenuState } from '@mpaas/xriverohos';
import { DemoLoadingComponent } from './DemoLoadingComponent';
import { DemoMenuCustomDialog } from './DemoMenuCustomDialog';
import { DemoNavComponent } from './DemoNavComponent';

@Builder
export function customDialogBuilder(state: TinyMenuState, controller: CustomDialogController, page: CRVPage) {
  // 菜单弹窗UI实现
  DemoMenuCustomDialog({
    tinyMenuState: state, // 菜单数据
    customDialogController: controller, // 自定义弹窗controller
    page: page // 小程序当前page，可以获取小程序相关数据
  })
}

@Builder
export function customNavComponentBuilder(data: ESObject) {
  // 标题栏实现
  DemoNavComponent({
    needHideBackButton: data.needHideBackButton, // 是否显示返回键
    navigationBarState: data.navigationBarState, // 标题栏的具体数据
    page: data.page // 小程序当前page，可以获取小程序相关数据
  })
}

@Builder
export function customLoadingComponentBuilder(data: ESObject) {
  DemoLoadingComponent({
    appId: data.appId,
    appInfo: data.appInfo,
    loadingProgress: data.loadingProgress,
    errorCode: data.errorCode,
    rightButtonState: data.rightButtonState
  })
}


export class DemoNavBarAdapter extends MYNavigationBarAdapter {
  getMenuCustomDialog(): WrappedBuilder<[TinyMenuState, CustomDialogController, CRVPage]> | undefined {
    return wrapBuilder(customDialogBuilder);
  }

  getNavBarComponent(): WrappedBuilder<[ESObject]> | undefined {
    return wrapBuilder(customNavComponentBuilder);
  }

  getLoadingComponent(): WrappedBuilder<[ESObject]> | undefined {
    return wrapBuilder(customLoadingComponentBuilder);
  }

  showPermissionDialog(component: Object, dlgData: ESObject, a174: Function, b174: Function): boolean {
    return false
  }
}

