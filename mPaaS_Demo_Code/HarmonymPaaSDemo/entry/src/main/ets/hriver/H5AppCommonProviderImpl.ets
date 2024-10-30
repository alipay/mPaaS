import { H5CommonAppProvider } from '@mpaas/hriver';

export class H5AppCommonProviderImpl extends H5CommonAppProvider {
  configJSON(): string {
    return JSON.stringify({
      //自定义导航栏是否覆盖状态栏
      // titleBarAllCustom: 'YES',
      //是否要状态栏高度
      forceStatusBar: 'NO',
      //H5沉浸式
      forceTransparent:'NO',
      h5_nbmngconfig: "{\"config\":{\"al\":\"3\",\"pr\": {\"4\":\"86400\",\"common\":\"864000\"},\"ur\":\"1800\",\"fpr\": {\"common\":\"3888000\"}},\"switch\":\"yes\"}"
    })
  }

  shouldVerify(): boolean {
    return false
  }

  pubKey(): string {
    return "MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAvqmBixkx+L8kgbtLQvbsA8Cks80pJwYu+S7KJUZOZFSCM78SdXStEJ0UG9RohnaplLZTaUMlSGw4zB/ZA8ez/XDqaIEy2iAswwU2hmvC582W3Rzadjavm0/LIQi2xLWfVVIWWs81fHWtyPK+Cenbi+2BHQatfGGOwm763PDP7DbH1YleCSkphjXWjpGAbLD1MdYzoMi6DLuWRxHnfnFEUeQLr55EsXeYQxS+IrEXXq+VNQErHVlk/QUyCN8kHTZyrVkisILEHO45GXoF3KaWnHgXVz36oIK99//n9ac4Y3uAKg6Y0hYKwCuusFqAIV2mIWhybtmsrVIvwRE+HyLu8wIDAQAB"
  }
}