import { abilityAccessCtrl, bundleManager, common, Permissions } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { promptAction } from '@kit.ArkUI';
import { Constants } from './Constants';

export const permissionsList: Array<Permissions> =
  ['ohos.permission.LOCATION', 'ohos.permission.APPROXIMATELY_LOCATION','ohos.permission.MICROPHONE'];


//检查授权
export async function checkPermissionGrant(permission: Permissions): Promise<abilityAccessCtrl.GrantStatus> {
  let atManager: abilityAccessCtrl.AtManager = abilityAccessCtrl.createAtManager();
  let grantStatus: abilityAccessCtrl.GrantStatus = abilityAccessCtrl.GrantStatus.PERMISSION_DENIED;

  // 获取应用程序的accessTokenID
  let tokenId: number = 0;
  try {
    let bundleInfo: bundleManager.BundleInfo =
      await bundleManager.getBundleInfoForSelf(bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_APPLICATION);
    let appInfo: bundleManager.ApplicationInfo = bundleInfo.appInfo;
    tokenId = appInfo.accessTokenId;
  } catch (error) {
    const err: BusinessError = error as BusinessError;
    console.error(Constants.TAG, `检查权限异常 = Code is ${err.code}, message is ${err.message}`);
  }

  // 校验应用是否被授予权限
  try {
    grantStatus = await atManager.checkAccessToken(tokenId, permission);
    console.error(Constants.TAG, `检查权限 = ${grantStatus}`);
  } catch (error) {
    const err: BusinessError = error as BusinessError;
    console.error(Constants.TAG, `检查权限2异常 = Code is ${err.code}, message is ${err.message}`);
  }
  return grantStatus;
}

//申请授权
// 使用UIExtensionAbility：将common.UIAbilityContext 替换为common.UIExtensionContext
export function reqPermissionsFromUser(permissions: Array<Permissions>, context: common.UIAbilityContext): Promise<boolean> {
  return new Promise((resolve,reject)=>{
    let atManager: abilityAccessCtrl.AtManager = abilityAccessCtrl.createAtManager();
    // requestPermissionsFromUser会判断权限的授权状态来决定是否唤起弹窗
    atManager.requestPermissionsFromUser(context, permissions).then((data) => {
      let grantStatus: Array<number> = data.authResults;
      let length: number = grantStatus.length;
      for (let i = 0; i < length; i++) {
        if (grantStatus[i] === 0) {
          // 用户授权，可以继续访问目标操作
          resolve(true)
          console.info(Constants.TAG, `申请权限异常 true`);
        } else {
          reject(false)
          console.error(Constants.TAG, `申请权限异常 false`);
          return;
        }
      }
      // 授权成功
    }).catch((err: BusinessError) => {
      reject(false)
      console.error(Constants.TAG, `申请权限异常 = Code is ${err.code}, message is ${err.message}`);
    })
  })

}
