import { MPFramework } from '@mpaas/framework';
import { H5WebClientProvider, Page } from '@mpaas/hriver';
import { JSON, util } from '@kit.ArkTS';
import { Constants } from '../constants/Constants';
import { abilityAccessCtrl, common, Permissions } from '@kit.AbilityKit';
import { checkPermissionGrant, reqPermissionsFromUser } from '../constants/PermissionUtils';
import { curUIAbilityContext, curUIContext } from '../constants/Global';
import { promptAction } from '@kit.ArkUI';
import { HriverPageUtils } from '../constants/HriverPageUtils';

export class H5WebClientProviderImpl extends H5WebClientProvider {
  private context = getContext(this) as common.UIAbilityContext;

  onControllerAttached(page: Page | undefined): void {
    let session = page?.getSession()
    let pages = session?.getPages()
    console.info(Constants.TAG, `H5WebClientProviderImpl#onControllerAttached():${page?.pageUrl}  ${pages?.length}`)
  }

  onPageBegin(page: Page | undefined, url: string | undefined): void {
    let session = page?.getSession()
    let pages = session?.getPages()
    console.info(Constants.TAG, `H5WebClientProviderImpl#onPageBegin():${page?.pageUrl}  ${url}    ${pages?.length}`)
  }

  onPageEnd(page: Page | undefined, url: string | undefined): void {
    let session = page?.getSession()
    let pages = session?.getPages()
    if (page && pages && pages.length > 1) {
      page.titleBarData.showCloseBtn = true
    }
    HriverPageUtils.getInstance().addPageNum()
    console.info(Constants.TAG, `H5WebClientProviderImpl#onPageEnd():${page?.pageUrl}  ${url}    ${pages?.length}`)
  }

  onErrorReceive(page: Page | undefined, request: WebResourceRequest | undefined,
    err: WebResourceError | undefined): boolean {
    let errorUrl = request?.getRequestUrl()
    let errorCode = err?.getErrorCode()
    if (errorCode == 403 || errorCode == 404) {
      // keep same with ios,not show errorPage for 404 and 403
      // log(TAG, "ignoreErrorPage 404 or 403, return ");
      return true;
    }
    let lastUrl = page?.webcontroller?.getUrl()
    if (errorUrl == page?.pageUrl || errorUrl == `${page?.pageUrl}/`) {
      // rawfile demo_custom_err.html
      let dataBytes = MPFramework.instance.context.resourceManager.getRawFileContentSync('70000000/customErr.html')
      // let dataBytes = MPFramework.instance.context.resourceManager.getRawFileContentSync('index.html')
      let textDecoder = new util.TextDecoder("utf-8", {
        fatal: false,
        ignoreBOM: false
      })
      let html = textDecoder.decodeWithStream(new Uint8Array(dataBytes), {
        stream: true
      })
      page?.webcontroller?.loadData(html, "text/html", "utf-8", lastUrl)
      return true
    }
    return false
  }

  onPermissionRequest(page: Page | undefined, request: PermissionRequest | undefined): void {
    console.info(Constants.TAG, `${request?.getOrigin()}   ${JSON.stringify(request?.getAccessibleResource())}`)
    if (request?.getAccessibleResource().concat("TYPE_AUDIO_CAPTURE")) {
      let permissionsList: Array<Permissions> = ['ohos.permission.MICROPHONE'];
      this.checkPermissions(permissionsList, request)
    }
  }

  async checkPermissions(permissions: Array<Permissions>, request: PermissionRequest | undefined): Promise<void> {
    let grantStatus: abilityAccessCtrl.GrantStatus = await checkPermissionGrant(permissions[0]);
    if (grantStatus === abilityAccessCtrl.GrantStatus.PERMISSION_GRANTED) {
      // 已经授权，可以继续访问目标操作
    } else {
      // 申请定位权限
      reqPermissionsFromUser(permissions, curUIAbilityContext()).then(() => {
        request?.grant(request?.getAccessibleResource())
        promptAction.showToast({
          message: "授权成功"
        })
      }).catch((err: Error) => {
        request?.deny()
        promptAction.showToast({
          message: "授权失败"
        })
      })
    }
  }
}
