// import { Constants } from '../constants/Constants';
// import { BannerModel } from '../rpc/EntityModel';
// import RouterManager from '../constants/RouterManager';
// import { BaseTitleComponent } from 'library/Index';
// import { mPaaSOCRCardType } from '@mpaas/mpaas_ocr_core/Index';
//
// @Builder
// export function getPageOcr(): void {
//   PageOcr()
// }
//
// @Component
// export struct PageOcr {
//   @State message: mPaaSOCRCardType = mPaaSOCRCardType.CoreBizTypeBankCard;
//
//   onBackPress(): boolean | void {
//     let bannerModel = new BannerModel()
//     bannerModel.desc = "开关回执传参"
//     RouterManager.pop(bannerModel, true)
//   }
//
//   build() {
//     NavDestination() {
//       Flex({ direction: FlexDirection.Column }) {
//         BaseTitleComponent({
//           title: "开关配置",
//           leftClickEvent: (): void => {
//             let bannerModel = new BannerModel()
//             bannerModel.desc = "开关回执传参"
//             RouterManager.pop(bannerModel, true)
//           }
//         })
//         Scroll(){
//           Column() {
//             // 按钮点击事件
//             Button("银行卡识别")
//               .margin(10)
//               .onClick(() => {
//                 console.info("测试:")
//                 this.message = mPaaSOCRCardType.CoreBizTypeBankCard;
//                 RouterManager.pushPath({ name: 'AiCameraPage' })
//               })
//             Button("身份证正面识别")
//               .margin(10)
//               .onClick(() => {
//                 this.message = mPaaSOCRCardType.CoreBizTypeIdCardFront;
//                 RouterManager.pushPath({ name: 'AiCameraPage' })
//               })
//
//             Button("身份证反面识别")
//               .margin(10)
//               .onClick(() => {
//                 this.message = mPaaSOCRCardType.CoreBizTypeIdCardBack;
//                 RouterManager.pushPath({ name: 'AiCameraPage' })
//               })
//             Button("营业执照")
//               .margin(10)
//               .onClick(() => {
//                 this.message = mPaaSOCRCardType.CoreBizTypeBusinessLicense;
//                 RouterManager.pushPath({ name: 'AiCameraPage' })
//               })
//
//             Button("车牌")
//               .margin(10)
//               .onClick(() => {
//                 this.message = mPaaSOCRCardType.CoreBizTypePlateNumber;
//                 RouterManager.pushPath({ name: 'AiCameraPage' })
//               })
//
//             Button("汽车VIN码")
//               .margin(10)
//               .onClick(() => {
//                 this.message = mPaaSOCRCardType.CoreBizTypeVinCode;
//                 RouterManager.pushPath({ name: 'AiCameraPage' })
//               })
//
//             Button("驾驶证正面")
//               .margin(10)
//               .onClick(() => {
//                 this.message = mPaaSOCRCardType.CoreBizTypeDriverLicenseFront;
//                 RouterManager.pushPath({ name: 'AiCameraPage' })
//               })
//
//             Button("驾驶证反面")
//               .margin(10)
//               .onClick(() => {
//                 this.message = mPaaSOCRCardType.CoreBizTypeDriverLicenseBack;
//                 RouterManager.pushPath({ name: 'AiCameraPage' })
//               })
//
//             Button("行驶证正面")
//               .margin(10)
//               .onClick(() => {
//                 this.message = mPaaSOCRCardType.CoreBizTypeVehicleFront;
//                 RouterManager.pushPath({ name: 'AiCameraPage' })
//               })
//
//             Button("行驶证反面")
//               .margin(10)
//               .onClick(() => {
//                 this.message = mPaaSOCRCardType.CoreBizTypeVehicleBack;
//                 RouterManager.pushPath({ name: 'AiCameraPage' })
//               })
//
//             Button("护照")
//               .margin(10)
//               .onClick(() => {
//                 this.message = mPaaSOCRCardType.CoreBizTypePassport;
//                 RouterManager.pushPath({ name: 'AiCameraPage' })
//               })
//             Button("燃气表示数")
//               .margin(10)
//               .onClick(() => {
//                 this.message = mPaaSOCRCardType.CoreBizTypeGasMeters;
//                 RouterManager.pushPath({ name: 'AiCameraPage' })
//               })
//
//           }
//
//         }
//         .backgroundColor(0xF5F5F5)
//         .width('100%')
//         .height('100%')
//       }
//       .width('100%')
//       .height('100%')
//     }
//     .hideTitleBar(true)
//     .onReady(ctx => {
//       let bannerModel = ctx.pathInfo.param as BannerModel
//       if (bannerModel) {
//         console.info(Constants.TAG, `跳转传参：${JSON.stringify(bannerModel)}`)
//       }
//     })
//   }
// }

import { mPaaSOCRCardType } from '@mpaas/mpaas_ocr_core/Index';
import { AiCameraPage } from '@mpaas/mpaas_ocr_demo/Index';
import { Constants } from '../constants/Constants';
import RouterManager from '../constants/RouterManager';
import { BannerModel } from '../rpc/EntityModel';

@Builder
export function getPageOcr(): void {
  PageOcr()
}

@Component
struct PageOcr {
  @State message: mPaaSOCRCardType = mPaaSOCRCardType.CoreBizTypeBankCard;

  pushAICamera() {
    let navPathInfo = new NavPathInfo("AiCameraPage", this.message, (popinfo: PopInfo) => {
      let result = popinfo.result as BannerModel
      console.info(Constants.TAG, `回执传参：${JSON.stringify(result)}`)
    })
    RouterManager.pushPath(navPathInfo, true)
  }

  build() {
    NavDestination() {
      Scroll() {
        Column() {
          // 按钮点击事件
          Button("银行卡识别")
            .margin(10)
            .onClick(() => {
              console.info("测试:")
              this.message = mPaaSOCRCardType.CoreBizTypeBankCard;
              this.pushAICamera()

            })
          Button("身份证正面识别")
            .margin(10)
            .onClick(() => {
              this.message = mPaaSOCRCardType.CoreBizTypeIdCardFront;
              this.pushAICamera()
            })

          Button("身份证反面识别")
            .margin(10)
            .onClick(() => {
              this.message = mPaaSOCRCardType.CoreBizTypeIdCardBack;
              this.pushAICamera()
            })
          Button("营业执照")
            .margin(10)
            .onClick(() => {
              this.message = mPaaSOCRCardType.CoreBizTypeBusinessLicense;
              // this.pagelsy.pushPath({ name: 'AiCameraPage' })
              this.pushAICamera()
            })

          Button("车牌")
            .margin(10)
            .onClick(() => {
              this.message = mPaaSOCRCardType.CoreBizTypePlateNumber;
              // this.pagelsy.pushPath({ name: 'AiCameraPage' })
              this.pushAICamera()
            })

          Button("汽车VIN码")
            .margin(10)
            .onClick(() => {
              this.message = mPaaSOCRCardType.CoreBizTypeVinCode;
              // this.pagelsy.pushPath({ name: 'AiCameraPage' })
              this.pushAICamera()
            })

          Button("驾驶证正面")
            .margin(10)
            .onClick(() => {
              this.message = mPaaSOCRCardType.CoreBizTypeDriverLicenseFront;
              // this.pagelsy.pushPath({ name: 'AiCameraPage' })
              this.pushAICamera()
            })


          Button("驾驶证反面")
            .margin(10)
            .onClick(() => {
              this.message = mPaaSOCRCardType.CoreBizTypeDriverLicenseBack;
              // this.pagelsy.pushPath({ name: 'AiCameraPage' })
              this.pushAICamera()
            })

          Button("行驶证正面")
            .margin(10)
            .onClick(() => {
              this.message = mPaaSOCRCardType.CoreBizTypeVehicleFront;
              // this.pagelsy.pushPath({ name: 'AiCameraPage' })
              this.pushAICamera()
            })

          Button("行驶证反面")
            .margin(10)
            .onClick(() => {
              this.message = mPaaSOCRCardType.CoreBizTypeVehicleBack;
              // this.pagelsy.pushPath({ name: 'AiCameraPage' })
              this.pushAICamera()
            })

          Button("护照")
            .margin(10)
            .onClick(() => {
              this.message = mPaaSOCRCardType.CoreBizTypePassport;
              // this.pagelsy.pushPath({ name: 'AiCameraPage' })
              this.pushAICamera()
            })
          Button("燃气表示数")
            .margin(10)
            .onClick(() => {
              this.message = mPaaSOCRCardType.CoreBizTypeGasMeters;
              // this.pagelsy.pushPath({ name: 'AiCameraPage' })
              this.pushAICamera()
            })
        }
      }
      .backgroundColor(0xF5F5F5)
      .width('100%')
      .height('100%')
    }
    .title('mPaaS_OCR')
  }
}
