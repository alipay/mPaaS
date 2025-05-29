import { AUDialogManager } from "@mpaas/antui";
import { PermissionAdapter, PermissionType } from "@mpaas/mpaas_permission_fortress";
import { common, Want } from "@kit.AbilityKit";

export class DemoPermissionAdapter extends PermissionAdapter {
  // type: 表示申请的权限类型，具体值参考文档后续部分，close：回调方法，弹窗取消后需要调用，goToSettings参数：true表示跳转设置页面并消失 false表示直接消失
  showGuideDialog(type: PermissionType, close: (goToSettings: boolean) => void): boolean {
    // 自定义弹窗逻辑，以下只是示例
    AUDialogManager.showNotice({
      onClose: () => {
        close(false) // 回调
      },
      title: '权限申请 ' + type, // 标题，根据业务情况
      message: '',  // 弹窗内容
      buttons: [{
        title: $r('app.string.go_to_set'),
        action: () => {
          close(true) // 回调
          let context = getContext(this) as common.UIAbilityContext;
          let want: Want = {
            bundleName: 'com.huawei.hmos.settings',
            abilityName: 'com.huawei.hmos.settings.MainAbility',
            uri: 'application_info_entry',
            parameters: { pushParams: '' }
          };
          context.startAbility(want).then((data) => {
            console.info('前往设置授权页面');
          })
        }
      }]
    })
    return true
  }
}