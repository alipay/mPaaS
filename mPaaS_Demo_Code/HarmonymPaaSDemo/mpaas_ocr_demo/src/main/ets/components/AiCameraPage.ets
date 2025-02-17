// // import common from '@ohos.app.ability.common';
// // import { data } from '@kit.TelephonyKit';
// import abilityAccessCtrl from '@ohos.abilityAccessCtrl';
// import { MediaBean } from '../utils/MediaBean';
// import { MediaHelper } from '../utils/MediaHelper';
// import image from '@ohos.multimedia.image';
// import fs from '@ohos.file.fs';
// import {
//   CoreBizOCRResult,
//   XMediaCoreBizStateCode,
//   XMediaCoreCameraView,
//   XMediaCoreCameraViewController,
//   XMediaPreviewSize,
//   XMVideoFrame
// } from '@mpaas/mpaas_xmediacorebiz/Index';
// import { hilog } from '@kit.PerformanceAnalysisKit';
// import { mPaaSOCRCardType, mPaaSOCRService, OcrAnalyzeMode } from '@mpaas/mpaas_ocr_core/Index';
// import { xMedia } from '@alipay/mpaas_xmedia';
// import { JSON } from '@kit.ArkTS';
//
// const TAG = "AiCameraPage";
//
// let isShowData: boolean = true;
//
// @Component
// export struct AiCameraPage {
//   pageInfos: NavPathStack = new NavPathStack();
//   @State mediaBean: MediaBean = new MediaBean();
//   private mXMediaViewController: XMediaCoreCameraViewController = new XMediaCoreCameraViewController()
//   private mediaHelper: MediaHelper = new MediaHelper(getContext());
//   @Prop private cardType: mPaaSOCRCardType = mPaaSOCRCardType.CoreBizTypeIdCardFront
//   @State textValue: string = ''
//   @State image: image.PixelMap = null!
//   @State roiImage: image.PixelMap = null!
//   dialogController: CustomDialogController = new CustomDialogController({
//     builder: CustomDialogExample({
//       confirm: this.onAccept,
//       resultStr: this.textValue,
//
//       objectImage: this.image,
//       roiImage: this.roiImage,
//     }),
//     cancel: this.exitApp,
//     autoCancel: true,
//     alignment: DialogAlignment.Center,
//     offset: { dx: 0, dy: -20 },
//     gridCount: 4,
//     customStyle: false
//   })
//
//   async aboutToAppear() {
//     hilog.debug(0, TAG, "aboutToAppear")
//     this.setupCameraService()
//
//   }
//
//   aboutToDisappear() {
//     this.mXMediaViewController?.stopPreview()
//     this.dialogController = null! // 将dialogController置空
//
//   }
//
//   setupCameraService() {
//
//     let atManager: abilityAccessCtrl.AtManager = abilityAccessCtrl.createAtManager()
//     atManager.requestPermissionsFromUser(getContext(), ['ohos.permission.CAMERA']).then((data) => {
//       this.initOCR()
//
//     })
//
//   }
//
//   /**
//    * 初始化
//    */
//   initOCR() {
//     mPaaSOCRService.sharedService.startServiceAsync(OcrAnalyzeMode.OcrAnalyzeModePhoto, this.cardType,
//       (stateCode: XMediaCoreBizStateCode, processId: string) => {
//         hilog.info(0, TAG, 'xmServiceStart1');
//         let rst = [stateCode, processId];
//         if (rst[0] == XMediaCoreBizStateCode.CoreBizNoError) {
//           // 当前非沉浸式的布局，需要把状态栏的高度先算出来
//           this.mXMediaViewController.setPreviewSize(XMediaPreviewSize.P1920x1080)
//           this.mXMediaViewController.startPreview(AppStorage.Get('context')!)
//           this.mXMediaViewController.setOnFrameData((data: ArrayBuffer, width: number, height: number,
//             rotation: number) => {
//             let frame: XMVideoFrame = {
//               imageW: width,
//               imageH: height,
//               data: data,
//               format: 9
//             }
//             this.ocrBankCardVideoConfig(frame, this.cardType, rotation);
//           })
//         } else {
//           hilog.info(0, TAG, '初始化失败' + rst[0] + ", " + rst[1]);
//         }
//       });
//   }
//
//   build() {
//     NavDestination() {
//       Stack() {
//         XMediaCoreCameraView({ controller: this.mXMediaViewController })
//           .width('100%')
//           .height('100%')
//         RelativeContainer() {
//           RelativeContainer() {
//
//             // 按钮点击事件
//             Button("相册")
//               .onClick(() => {
//                 this.handleClick();
//               })
//               .id("photo_album")
//               .alignRules({
//                 'center': { anchor: '__container__', align: VerticalAlign.Center },
//                 'right': { anchor: '__container__', align: HorizontalAlign.End }
//               })
//               .backgroundColor(Color.Transparent)
//
//           }
//           .height(48)
//           .width("100%")
//           .backgroundColor(Color.Transparent)
//           .alignRules({
//             'top': { anchor: '__container__', align: VerticalAlign.Top }
//           })
//           .id("navi_bar")
//
//           Text('扫描证件')
//             .width("100%")
//             .height(30)
//             .fontSize(22)
//             .fontColor(0xFFFFFF)
//             .textAlign(TextAlign.Center)
//             .id("scan_bankcard")
//             .alignRules({
//               'top': { anchor: 'navi_bar', align: VerticalAlign.Bottom },
//               'middle': { anchor: '__container__', align: HorizontalAlign.Center }
//             })
//             .backgroundColor(Color.Transparent)
//
//
//           Image($r('app.media.scan_box'))
//             .width(360)
//             .height(258)
//             .id("scan_box")
//             .alignRules({
//               'top': { anchor: 'scan_bankcard', align: VerticalAlign.Bottom },
//               'middle': { anchor: '__container__', align: HorizontalAlign.Center }
//             })
//             .backgroundColor(Color.Transparent)
//             .offset({ y: 20 })
//
//           Text('将证件正面对准此区域')
//             .width("100%")
//             .height(30)
//             .fontSize(22)
//             .fontColor(0xFFFFFF)
//             .textAlign(TextAlign.Center)
//             .id("scan_bankcard_text")
//             .alignRules({
//               'top': { anchor: 'scan_box', align: VerticalAlign.Bottom },
//               'middle': { anchor: '__container__', align: HorizontalAlign.Center }
//             })
//             .backgroundColor(Color.Transparent)
//             .offset({ y: 50 })
//
//         }
//         .backgroundColor(Color.Transparent)
//         .width("100%")
//         .height("100%")
//
//       }
//
//     }
//     .title('AiCameraPage')
//   }
//
//   //视频流解析入参设置
//   async ocrBankCardVideoConfig(frame: XMVideoFrame, cardType: mPaaSOCRCardType, rotation: number) {
//     this.xmediaCoreBizAnalyze(OcrAnalyzeMode.OcrAnalyzeModeVideo, cardType, rotation, { videoSource: frame });
//
//   }
//
//   //图片解析入参设置
//   async ocrBankCardPhotoConfig(url: string) {
//     hilog.info(0, TAG, 'ocrBankCardPhotoConfig image url path:' + url);
//     if (url == null || url == undefined) {
//       return;
//     }
//     const file = fs.openSync(url, fs.OpenMode.READ_ONLY);
//     const numSize = fs.statSync(file.fd).size;
//     let buf = new ArrayBuffer(numSize);
//     let readLen = fs.readSync(file.fd, buf);
//     hilog.info(0, TAG, 'readSync data to file succeed and buffer size is:' + readLen);
//     fs.closeSync(file);
//     const imageSource = image.createImageSource(buf);
//     let pixelMap = await imageSource.createPixelMap({});
//
//     let source = pixelMap as image.PixelMap;
//
//     this.xmediaCoreBizAnalyze(OcrAnalyzeMode.OcrAnalyzeModePhoto, mPaaSOCRCardType.CoreBizTypeBankCard, 0, {
//       photoSource: source
//     });
//
//   }
//
//   //模型解析
//   xmediaCoreBizAnalyze(type: OcrAnalyzeMode, cardType: mPaaSOCRCardType, rotation: number, source: Source) {
//     // 初始化成功后调用异步process接口获取CV识别结果
//     if (type == OcrAnalyzeMode.OcrAnalyzeModePhoto) {
//       console.info("mPaaSLog", `开始解析1 ${JSON.stringify(source.videoSource)}`)
//       mPaaSOCRService.sharedService.asyncProcess(source.photoSource!, rotation, (result) => {
//         let res = result as CoreBizOCRResult;
//         hilog.info(0, TAG, '解析成功')
//         if (res?.result !== undefined && res?.result !== null) {
//           hilog.info(0, TAG, '666666666==========' + JSON.stringify(res?.result));
//           this.handleOcrResult(res?.result, res.objectImage!, res.roiImage!);
//         } else {
//           hilog.info(0, TAG, `执行失败1 ${JSON.stringify(res)}`);
//         }
//       });
//     } else if (type == OcrAnalyzeMode.OcrAnalyzeModeVideo) {
//       console.info("mPaaSLog", `开始解析2 ${JSON.stringify(source.videoSource)}`)
//       mPaaSOCRService.sharedService.processCameraFrame(source.videoSource!, rotation).then(rst => {
//         hilog.info(0, TAG, '解析成功')
//         let res = rst as CoreBizOCRResult;
//         if (rst.error == null && res?.result !== undefined && res?.result !== null) {
//           hilog.info(0, TAG, '666666666==========' + JSON.stringify(res?.result));
//           this.handleOcrResult(res?.result, res.objectImage!, res.roiImage!);
//         } else {
//           hilog.info(0, TAG, `执行失败2 ${JSON.stringify(res)}`);
//         }
//       });
//     }
//   }
//
//   //解析结果回调
//   handleOcrResult(result: xMedia.AlgoResult[], objectImage: image.PixelMap, roiImage: image.PixelMap) {
//     if (!isShowData) {
//       return
//     }
//     isShowData = false
//
//     let data = "结果："
//
//     for (let index = 0; index < result.length; index++) {
//       data += result[index].label + "-可信度：" + result[index].conf + "\n"
//       hilog.info(0, TAG, '666666666==========' + data);
//     }
//
//     this.textValue = data
//
//     this.image = objectImage
//     this.roiImage = roiImage
//
//     this.dialogController.open()
//
//
//   }
//
//   onAccept() {
//     isShowData = true
//   }
//
//   exitApp() {
//     isShowData = true
//   }
//
//   async handleClick() {
//     let mediaBean: MediaBean = new MediaBean();
//
//     mediaBean = await this.mediaHelper.selectPicture();
//
//     if (mediaBean) {
//
//       this.mediaBean = mediaBean;
//
//     }
//     mPaaSOCRService.sharedService.startServiceAsync(OcrAnalyzeMode.OcrAnalyzeModePhoto, this.cardType,
//       (stateCode: XMediaCoreBizStateCode, processId: string) => {
//         hilog.info(0, TAG, 'xmServiceStart1');
//         let rst = [stateCode, processId];
//         if (rst[0] == XMediaCoreBizStateCode.CoreBizNoError) {
//           this.ocrBankCardPhotoConfig(this.mediaBean.localUrl);
//         } else {
//           hilog.info(0, TAG, '初始化失败' + rst[0] + ", " + rst[1]);
//         }
//       });
//
//   }
// }
//
// // 定义一个接口来描述参数
// interface Source {
//   videoSource?: XMVideoFrame;
//   photoSource?: image.PixelMap | string;
// }
//
//
// @CustomDialog
// struct CustomDialogExample {
//   @Link resultStr: string
//   @Link objectImage: image.PixelMap
//   @Link roiImage: image.PixelMap
//   controller?: CustomDialogController
//   confirm: () => void = () => {
//   }
//
//   build() {
//     Column() {
//       Column() {
//         Image(this.roiImage).height(200)
//         Image(this.objectImage).height(50)
//         Text(this.resultStr).fontColor("#333")
//         Button("确定").margin({ top: 20 }).onClick(() => {
//           this.controller?.close()
//           this.confirm()
//
//         })
//       }.borderRadius(10)
//       .width("90%")
//     }.borderRadius(10)
//   }
// }
//
//

// import common from '@ohos.app.ability.common';
// import { data } from '@kit.TelephonyKit';
import abilityAccessCtrl from '@ohos.abilityAccessCtrl';
import { MediaBean } from '../utils/MediaBean';
import { MediaHelper } from '../utils/MediaHelper';
import image from '@ohos.multimedia.image';
import fs from '@ohos.file.fs';
import {
  CoreBizOCRResult,
  XMediaCoreBizStateCode,
  XMediaCoreCameraView,
  XMediaCoreCameraViewController,
  XMediaPreviewSize,
  XMVideoFrame
} from '@mpaas/mpaas_xmediacorebiz/Index';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { mPaaSOCRCardType, mPaaSOCRService, OcrAnalyzeMode } from '@mpaas/mpaas_ocr_core/Index';
import { xMedia } from '@alipay/mpaas_xmedia';
import { AsyncCallback } from '@kit.BasicServicesKit';
import { display } from '@kit.ArkUI';

const TAG = "mPaaSLog";

let isShowData: boolean = true;

@Component
export struct AiCameraPage {
  pageInfos: NavPathStack = new NavPathStack();
  @State mediaBean: MediaBean = new MediaBean();
  private mXMediaViewController: XMediaCoreCameraViewController = new XMediaCoreCameraViewController()
  private mediaHelper: MediaHelper = new MediaHelper(getContext());
  private cardType: mPaaSOCRCardType = mPaaSOCRCardType.CoreBizTypeBankCard
  @State textValue: string = ''
  @State image: image.PixelMap = null!
  @State roiImage: image.PixelMap = null!
  dialogController: CustomDialogController = new CustomDialogController({
    builder: CustomDialogExample({
      confirm: this.onAccept,
      resultStr: this.textValue,

      objectImage: this.image,
      roiImage: this.roiImage,
    }),
    cancel: this.exitApp,
    autoCancel: true,
    alignment: DialogAlignment.Center,
    offset: { dx: 0, dy: -20 },
    gridCount: 4,
    customStyle: false
  })

  async aboutToAppear() {
    hilog.debug(0, TAG, "aboutToAppear")
    this.setupCameraService()

  }

  aboutToDisappear() {
    this.mXMediaViewController?.stopPreview()
    this.dialogController = null! // 将dialogController置空
  }

  setupCameraService() {
    let atManager: abilityAccessCtrl.AtManager = abilityAccessCtrl.createAtManager()
    atManager.requestPermissionsFromUser(getContext(), ['ohos.permission.CAMERA']).then((data) => {
      this.initOCR()
    })
  }

  /**
   * 初始化
   */
  initOCR() {
    mPaaSOCRService.sharedService.startServiceAsync(OcrAnalyzeMode.OcrAnalyzeModePhoto, this.cardType,
      (stateCode: XMediaCoreBizStateCode, processId: string) => {
        hilog.info(0, TAG, 'xmServiceStart1');
        let rst = [stateCode, processId];
        if (rst[0] == XMediaCoreBizStateCode.CoreBizNoError) {
          // 当前非沉浸式的布局，需要把状态栏的高度先算出来
          let displayClass: display.Display | null = null;
          try {
            displayClass = display.getDefaultDisplaySync();
            console.info(TAG,`屏幕信息 width:${displayClass.width}  height:${displayClass.height}  rotation:${displayClass.rotation}`)
          } catch (exception) {
            console.error(TAG,'Failed to obtain the default display object. Code: ' + JSON.stringify(exception));
          }
          this.mXMediaViewController.setPreviewSize(XMediaPreviewSize.P1920x1080)
          this.mXMediaViewController.startPreview(AppStorage.Get('context')!)
          this.mXMediaViewController.setOnFrameData((data: ArrayBuffer, width: number, height: number,
            rotation: number) => {
            console.info(TAG,`width:${width}  height:${height}  rotation:${rotation}`)
            let frame: XMVideoFrame = {
              imageW: width,
              imageH: height,
              data: data,
              format: 9
            }
            this.ocrBankCardVideoConfig(frame, this.cardType, rotation);
          })
        } else {
          hilog.info(0, TAG, '初始化失败' + rst[0] + ", " + rst[1]);
        }
      });
  }

  build() {
    NavDestination() {
      Stack() {
        XMediaCoreCameraView({ controller: this.mXMediaViewController })
          .width('100%')
          .height('100%')
        RelativeContainer() {
          RelativeContainer() {

            // 按钮点击事件
            Button("相册")
              .onClick(() => {
                this.handleClick();
              })
              .id("photo_album")
              .alignRules({
                'center': { anchor: '__container__', align: VerticalAlign.Center },
                'right': { anchor: '__container__', align: HorizontalAlign.End }
              })
              .backgroundColor(Color.Transparent)

          }
          .height(48)
          .width("100%")
          .backgroundColor(Color.Transparent)
          .alignRules({
            'top': { anchor: '__container__', align: VerticalAlign.Top }
          })
          .id("navi_bar")

          Text('扫描证件')
            .width("100%")
            .height(30)
            .fontSize(22)
            .fontColor(0xFFFFFF)
            .textAlign(TextAlign.Center)
            .id("scan_bankcard")
            .alignRules({
              'top': { anchor: 'navi_bar', align: VerticalAlign.Bottom },
              'middle': { anchor: '__container__', align: HorizontalAlign.Center }
            })
            .backgroundColor(Color.Transparent)


          Image($r('app.media.scan_box'))
            .width(360)
            .height(258)
            .id("scan_box")
            .alignRules({
              'top': { anchor: 'scan_bankcard', align: VerticalAlign.Bottom },
              'middle': { anchor: '__container__', align: HorizontalAlign.Center }
            })
            .backgroundColor(Color.Transparent)
            .offset({ y: 20 })

          Text('将证件正面对准此区域')
            .width("100%")
            .height(30)
            .fontSize(22)
            .fontColor(0xFFFFFF)
            .textAlign(TextAlign.Center)
            .id("scan_bankcard_text")
            .alignRules({
              'top': { anchor: 'scan_box', align: VerticalAlign.Bottom },
              'middle': { anchor: '__container__', align: HorizontalAlign.Center }
            })
            .backgroundColor(Color.Transparent)
            .offset({ y: 50 })

        }
        .backgroundColor(Color.Transparent)
        .width("100%")
        .height("100%")
      }
    }
    .title('AiCameraPage')
    // .hideTitleBar(true)
    .onReady(ctx => {
      let bannerModel = ctx.pathInfo.param as mPaaSOCRCardType
      if (bannerModel) {
        this.cardType = bannerModel
        console.info("mPaaSLog", `跳转传参：${JSON.stringify(bannerModel)}`)
      }
    })
  }

  //视频流解析入参设置
  async ocrBankCardVideoConfig(frame: XMVideoFrame, cardType: mPaaSOCRCardType, rotation: number) {
    this.xmediaCoreBizAnalyze(OcrAnalyzeMode.OcrAnalyzeModeVideo, cardType, rotation, { videoSource: frame });
  }

  //图片解析入参设置
  async ocrBankCardPhotoConfig(url: string) {
    hilog.info(0, TAG, 'ocrBankCardPhotoConfig image url path:' + url);
    if (url == null || url == undefined) {
      return;
    }
    const file = fs.openSync(url, fs.OpenMode.READ_ONLY);
    const numSize = fs.statSync(file.fd).size;
    let buf = new ArrayBuffer(numSize);
    let readLen = fs.readSync(file.fd, buf);
    hilog.info(0, TAG, 'readSync data to file succeed and buffer size is:' + readLen);
    fs.closeSync(file);
    const imageSource = image.createImageSource(buf);
    let pixelMap = await imageSource.createPixelMap({});

    let source = pixelMap as image.PixelMap;

    this.xmediaCoreBizAnalyze(OcrAnalyzeMode.OcrAnalyzeModePhoto, mPaaSOCRCardType.CoreBizTypeBankCard, 0, {
      photoSource: source
    });
  }

  //模型解析
  xmediaCoreBizAnalyze(type: OcrAnalyzeMode, cardType: mPaaSOCRCardType, rotation: number, source: Source) {
    hilog.info(0, TAG,
      `开始解析：videoSource:${source.videoSource?.data}\n photoSource:${source.photoSource?.toString()}`)
    // 初始化成功后调用异步process接口获取CV识别结果
    if (type == OcrAnalyzeMode.OcrAnalyzeModePhoto) {
      mPaaSOCRService.sharedService.asyncProcess(source.photoSource!, rotation, (result) => {
        let res = result as CoreBizOCRResult;
        hilog.info(0, TAG, '解析成功')
        if (res?.result !== undefined && res?.result !== null) {
          hilog.info(0, TAG, '666666666==========' + JSON.stringify(res?.result));
          this.handleOcrResult(res?.result, res.objectImage!, res.roiImage!);
        }
      });
    } else if (type == OcrAnalyzeMode.OcrAnalyzeModeVideo) {
      mPaaSOCRService.sharedService.processCameraFrame(source.videoSource!, rotation).then(rst => {
        hilog.info(0, TAG, '解析成功')
        let res = rst as CoreBizOCRResult;
        if (rst.error == null && res?.result !== undefined && res?.result !== null) {
          hilog.info(0, TAG, '666666666==========' + JSON.stringify(res?.result));
          this.handleOcrResult(res?.result, res.objectImage!, res.roiImage!);
        } else {
          hilog.info(0, TAG, "执行失败");
        }
      });
    }
  }

  //解析结果回调
  handleOcrResult(result: xMedia.AlgoResult[], objectImage: image.PixelMap, roiImage: image.PixelMap) {
    if (!isShowData) {
      return
    }
    isShowData = false
    let data = "结果："
    for (let index = 0; index < result.length; index++) {
      data += result[index].label + "-可信度：" + result[index].conf + "\n"
      hilog.info(0, TAG, '666666666==========' + data);
    }
    this.textValue = data
    this.image = objectImage
    this.roiImage = roiImage
    this.dialogController.open()
  }

  onAccept() {
    isShowData = true
  }

  exitApp() {
    isShowData = true
  }

  async handleClick() {
    let mediaBean: MediaBean = new MediaBean();

    mediaBean = await this.mediaHelper.selectPicture();

    if (mediaBean) {

      this.mediaBean = mediaBean;

    }
    mPaaSOCRService.sharedService.startServiceAsync(OcrAnalyzeMode.OcrAnalyzeModePhoto, this.cardType,
      (stateCode: XMediaCoreBizStateCode, processId: string) => {
        hilog.info(0, TAG, 'xmServiceStart1');
        let rst = [stateCode, processId];
        if (rst[0] == XMediaCoreBizStateCode.CoreBizNoError) {
          this.ocrBankCardPhotoConfig(this.mediaBean.localUrl);
        } else {
          hilog.info(0, TAG, '初始化失败' + rst[0] + ", " + rst[1]);
        }
      });

  }
}

// 定义一个接口来描述参数
interface Source {
  videoSource?: XMVideoFrame;
  photoSource?: image.PixelMap | string;
}


@CustomDialog
struct CustomDialogExample {
  @Link resultStr: string
  @Link objectImage: image.PixelMap
  @Link roiImage: image.PixelMap
  controller?: CustomDialogController
  confirm: () => void = () => {
  }

  build() {
    Column() {
      Column() {
        Image(this.roiImage).height(200)
        Image(this.objectImage).height(50)
        Text(this.resultStr).fontColor("#333")
        Button("确定").margin({ top: 20 }).onClick(() => {
          this.controller?.close()
          this.confirm()

        })
      }.borderRadius(10)
      .width("90%")
    }.borderRadius(10)
  }
}



