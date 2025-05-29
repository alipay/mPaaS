import { H5CommonAppProvider } from '@mpaas/hriver';

export class H5AppCommonProviderImpl extends H5CommonAppProvider {
  configJSON(): string {
    return JSON.stringify({
      //自定义导航栏是否覆盖系统状态栏
      // titleBarAllCustom: 'YES',
      //安全区域
      bottomSafe: 'YES',
      //是否要状态栏高度
      forceStatusBar: 'NO',
      //H5沉浸式
      forceTransparent: 'NO',
      enableFallback: 'YES',
      h5_nbmngconfig: "{\"config\":{\"al\":\"3\",\"pr\": {\"4\":\"86400\",\"common\":\"864000\"},\"ur\":\"1\",\"fpr\": {\"common\":\"3888000\"}},\"switch\":\"yes\"}"
    })
  }

  shouldVerify(): boolean {
    return false
  }
}