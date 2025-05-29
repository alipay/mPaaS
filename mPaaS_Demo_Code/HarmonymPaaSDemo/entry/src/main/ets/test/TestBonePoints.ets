import { image } from '@kit.ImageKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { fileIo } from '@kit.CoreFileKit';
import { skeletonDetection, visionBase } from '@kit.CoreVisionKit';
import { photoAccessHelper } from '@kit.MediaLibraryKit';
import { constant } from '@kit.ConnectivityKit';
import { Constants } from '../constants/Constants';
import { BoneListModel } from './BonePointModel';

@Entry
@Component
struct TestBonePoints {
  private imageSource: image.ImageSource | undefined = undefined;
  @State chooseImage: PixelMap | undefined = undefined
  @State dataValues: string = ''
  @State bonePointData: skeletonDetection.SkeletonDetectionResponse | null = null
  // private settings: RenderingContextSettings = new RenderingContextSettings(true)
  // private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)

  private context: DrawingRenderingContext = new DrawingRenderingContext()

  build() {
    Stack() {
      Column() {
        Image(this.chooseImage)
          .objectFit(ImageFit.Fill)
          .height('60%')

        Text(this.dataValues)
          .copyOption(CopyOptions.LocalDevice)
          .height('15%')
          .margin(10)
          .width('60%')

        Button('选择图片')
          .type(ButtonType.Capsule)
          .fontColor(Color.White)
          .alignSelf(ItemAlign.Center)
          .width('80%')
          .margin(10)
          .onClick(() => {
            // 拉起图库
            this.selectImage()
          })

        Button('开始骨骼点识别')
          .type(ButtonType.Capsule)
          .fontColor(Color.White)
          .alignSelf(ItemAlign.Center)
          .width('80%')
          .margin(10)
          .onClick(async () => {
            if (!this.chooseImage) {
              hilog.error(0x0000, 'skeletonDetectSample', `Failed to choose image. chooseImage: ${this.chooseImage}`);
              return;
            }
            // 调用骨骼点识别接口
            let request: visionBase.Request = {
              inputData: { pixelMap: this.chooseImage, }
            };
            let data: skeletonDetection.SkeletonDetectionResponse =
              await (await skeletonDetection.SkeletonDetector.create()).process(request);
            let poseJson = JSON.stringify(data);
            this.bonePointData = data
            this.bonePointData.skeletons[0].points.forEach((item) => {
              console.info(Constants.TAG,`坐标点 x:${item.point.x}  y:${ item.point.y}`)
              // this.context.fillRect(item.point.x, item.point.y, 20, 20)
              // this.context.canvas.drawCircle(200,200,100)
              this.context.canvas.drawCircle(px2vp(item.point.x), px2vp(item.point.y),30)
              this.context.invalidate()
            })
            this.dataValues = poseJson;
            console.info(Constants.TAG, `Succeeded in face detect：${this.bonePointData.skeletons.length} datavalue:${this.dataValues}}`)
          })
      }
      .width('100%')
      .height('100%')
      .justifyContent(FlexAlign.Center)

      Canvas(this.context)
        .width('100%')
        .height('100%')
        .backgroundColor(Color.Transparent)//事件透传
        .hitTestBehavior(HitTestMode.None)
        .onReady(() => {

        })
    }
    .width('100%')
    .height('100%')

  }

  private async selectImage() {
    let uri = await this.openPhoto()
    if (uri === undefined) {
      hilog.error(0x0000, 'skeletonDetectSample', "Failed to defined uri.");
    }
    this.loadImage(uri)
  }

  private openPhoto(): Promise<string> {
    return new Promise<string>((resolve, reject) => {
      let photoPicker: photoAccessHelper.PhotoViewPicker = new photoAccessHelper.PhotoViewPicker();
      photoPicker.select({
        MIMEType: photoAccessHelper.PhotoViewMIMETypes.IMAGE_TYPE, maxSelectNumber: 1
      }).then(res => {
        resolve(res.photoUris[0])
      }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'skeletonDetectSample',
          `Failed to get photo image uri. code：${err.code}，message：${err.message}`);
        reject('')
      })
    })
  }

  private loadImage(name: string) {
    setTimeout(async () => {
      let fileSource = await fileIo.open(name, fileIo.OpenMode.READ_ONLY);
      this.imageSource = image.createImageSource(fileSource.fd);
      this.chooseImage = await this.imageSource.createPixelMap();
    }, 100)
  }
}