import { hilog } from '@kit.PerformanceAnalysisKit';
import { MPData, MPFile } from '@mpaas/datacenter';
import { MPFramework } from '@mpaas/framework';
import { Constants } from '../constants/Constants';
import { DLogger } from '../logger/DLogger';
import { BusinessError } from '@kit.BasicServicesKit';
import { TitleComponent } from '../component/TitleComponent';
// import { BaseTitleComponent } from 'library/Index';
import { getLoaclJson } from '../constants/Global';
import { MPFileUtils } from '../constants/MPFileUtils';
import { BaseTitleComponent } from 'basicsharedmodule';


@Builder
export function getPageDataCenterA(): void {
  PageDataCenterA()
}

@Component
struct PageDataCenterA {
  @State message: string = 'Hello World';
  readonly SAVE_KEY_GLOBE: string = "SAVE_KEY_GLOBE"
  readonly SAVE_KEY_USERID: string = "SAVE_KEY_USERID"
  readonly SAVE_KEY_ENCRYPT: string = "SAVE_KEY_ENCRYPT"
  fileUtil = new MPFile()

  saveDataByFile() {
    MPFileUtils.getInstance().saveFileByName("testFile").then((b) => {
      if (b) {
        this.message = `存文件：存储成功`
      }
    })
  }

  getDataByFile() {
    MPFileUtils.getInstance().getFileByName("testFile").then((result) => {
      console.info(Constants.TAG, `文件存储获取：${result}`)
      this.message = `取文件：${result}`
    }).catch((err: Error) => {
      console.info(Constants.TAG, `文件存储获取：${JSON.stringify(err)}`)
      this.message = `取文件：异常 ${err.message}`
    })
  }

  saveDataByKey() {
    getLoaclJson("pageIndexConfig.txt").then((result: string) => {
      console.info(Constants.TAG, `读取本地json：${result}`)
      MPData.put(this.SAVE_KEY_GLOBE, result).then(() => {
        this.message = `存数据-key:存储成功`
      }).catch((err: BusinessError) => {
        console.log(Constants.TAG, err)
        this.message = `存数据-key:存储异常 ${err.message}`
      })
    }).catch((error: Error) => {
      this.message = `存数据-key:存储异常 ${error.message}`
    })
  }

  getDataByKey() {
    MPData.get(this.SAVE_KEY_GLOBE).then((value => {
      if (typeof value == "string") {
        DLogger.error("取数据", value)
        this.message = `取数据-key：${value}`
      }
    })).catch((err: BusinessError) => {
      console.log(Constants.TAG, err)
      this.message = `取数据-key:存储异常 ${err.message}`
    })
  }

  saveDataByUserId() {
    DLogger.error("userid", MPFramework.instance.userId!!)
    DLogger.error("SAVE_KEY_USERID", this.SAVE_KEY_USERID)
    MPData.put(this.SAVE_KEY_USERID, "本自具足来自userid", { userId: "test0001" })
      .then(() => {
        this.message = `存数据-userid：存储成功`
      })
      .catch((error: BusinessError) => {
        this.message = `Failed to get data code is ${error.code},message is ${error.message}`
        console.error(`Failed to get data code is ${error.code},message is ${error.message}`);
      })
  }

  getDataByUserId() {
    DLogger.error("userid", MPFramework.instance.userId!!)
    DLogger.error("SAVE_KEY_USERID", this.SAVE_KEY_USERID)
    MPData.get(this.SAVE_KEY_USERID, { userId: "test0001" }).then((value => {
      if (typeof value == "string") {
        DLogger.error("userid取数据", value)
      }
      this.message = `取数据-userid：${value}`
    })).catch((error: BusinessError) => {
      this.message = `Failed to get data code is ${error.code},message is ${error.message}`
      console.error(`Failed to get data code is ${error.code},message is ${error.message}`);
    })
  }

  saveDataByEncrypt() {
    MPData.put(this.SAVE_KEY_ENCRYPT, "本自具足来自Encrypt", { encrypt: true }).then(() => {
      this.message = `存数据-加密：存储成功`
    }
    ).catch((error: BusinessError) => {
      console.error(`Failed to get data code is ${error.code},message is ${error.message}`);
    })
  }

  getDataByEncrypt() {
    MPData.get(this.SAVE_KEY_ENCRYPT, { encrypt: true }).then((value => {
      if (typeof value == "string") {
        DLogger.error("Encrypt取数据", value)
      }
      this.message = `取数据-加密：${value}`
    })).catch((error: BusinessError) => {
      console.error(`Failed to get data code is ${error.code},message is ${error.message}`);
    })
  }

  build() {
    NavDestination() {
      Column() {
        BaseTitleComponent({
          title: "存储",
          leftClickEvent: (): void => {

          }
        })
        Text(`${this.message}`)
          .maxLines(3)
          .margin({ top: 10 })
          .height(100)
          .width('90%')
          .borderWidth(2)
          .borderColor(Color.Blue)
          .textAlign(TextAlign.Start)
        Scroll() {
          Column() {
            Text(`全局存储，标准版`)
              .fontColor(Color.Gray)
              .fontSize(14)
              .margin({ top: 10 })
            Button("存数据-key")
              .fontSize(16)
              .margin(5)
              .fontWeight(FontWeight.Bold)
              .onClick(() => {
                this.saveDataByKey()
              })
            Button("取数据-key")
              .fontSize(16)
              .margin(5)
              .fontWeight(FontWeight.Bold)
              .onClick(() => {
                this.getDataByKey()
              })
            Text(`全局存储，userid版`)
              .fontColor(Color.Gray)
              .fontSize(14)
              .margin({ top: 10 })
            Button("存数据-userid")
              .fontSize(16)
              .margin(5)
              .fontWeight(FontWeight.Bold)
              .onClick(() => {
                this.saveDataByUserId()
              })
            Button("取数据-userid")
              .fontSize(16)
              .margin(5)
              .fontWeight(FontWeight.Bold)
              .onClick(() => {
                this.getDataByUserId()
              })
            Text(`全局存储，加密版`)
              .fontColor(Color.Gray)
              .fontSize(14)
              .margin({ top: 10 })
            Button("存数据-加密")
              .fontSize(16)
              .margin(5)
              .fontWeight(FontWeight.Bold)
              .onClick(() => {
                this.saveDataByEncrypt()
              })
            Button("取数据-加密")
              .fontSize(16)
              .margin(5)
              .fontWeight(FontWeight.Bold)
              .onClick(() => {
                this.getDataByEncrypt()
              })
            Text(`mPaaS自带的文件存储功能，大数据`)
              .fontColor(Color.Gray)
              .fontSize(14)
              .margin({ top: 10 })
            Button("文件-存数据(大数据)")
              .fontSize(16)
              .margin(5)
              .fontWeight(FontWeight.Bold)
              .onClick(() => {
                this.saveDataByFile()
              })
            Button("文件-取数据(大数据)")
              .fontSize(16)
              .margin(5)
              .fontWeight(FontWeight.Bold)
              .onClick(() => {
                this.getDataByFile()
              })
            Text(`mPaaS自带的文件存储功能，小数据`)
              .fontColor(Color.Gray)
              .fontSize(14)
              .margin({ top: 10 })
            Button("文件-存数据(小数据)")
              .fontSize(16)
              .margin(5)
              .fontWeight(FontWeight.Bold)
              .onClick(() => {
                let changeMessage = new ChangeMessage()
                changeMessage.onCallSave = (result: string) => {
                  this.message = result
                }
                this.fileUtil.saveFile('mPaaSFileStorage', "mPaaS自带的文件存储").then((state) => {
                  if (state) {
                    console.info(Constants.TAG, `文件存储成功 ${state}`)
                  }
                  changeMessage.callSave(state)
                }).catch((err: Error) => {
                  console.info(Constants.TAG, `文件存储异常 ${JSON.stringify(err)}`)
                })
              })
            Button("文件-取数据(小数据)")
              .fontSize(16)
              .margin(5)
              .fontWeight(FontWeight.Bold)
              .onClick(() => {
                let changeMessage = new ChangeMessage()
                changeMessage.onCallGet = (result: string) => {
                  this.message = result
                }
                this.fileUtil.getFileContent('mPaaSFileStorage').then((data) => {
                  console.info(Constants.TAG, `文件读取：${data}`)
                  changeMessage.callGet(data)
                }).catch((err: Error) => {
                  console.info(Constants.TAG, `文件读取异常 ${JSON.stringify(err)}`)
                })
              })
            Text(`业务存储，模拟native存数据，h5取数据，请在【离线宝】>【打开本地网页】>【goStorge】>【取-客户端存】获取数据`)
              .fontColor(Color.Gray)
              .fontSize(14)
              .margin({ top: 10 })
            Button("存-H5取")
              .fontSize(16)
              .margin(5)
              .fontWeight(FontWeight.Bold)
              .onClick(() => {
                let mpData: MPData = MPData.createData('dataStorage.json')
                mpData.put('key1', '客户端存的数据1')
                mpData.put('key2', '客户端存的数据2')
                // mpData.synchronize().then((never)=>{
                //
                // })
                this.message = `native存储数据成功，请在【离线宝】>【打开本地网页】>【goStorge】>【取-客户端存】获取数据`
              })
          }
          .margin({ bottom: 300 })
          .width('100%')
          //主轴对齐方式
          .justifyContent(FlexAlign.Start)
        }
        //scroll包裹的布局不要写高度，要不然没法滚动
        .scrollable(ScrollDirection.Vertical) // 滚动方向纵向
        .scrollBar(BarState.On) // 滚动条常驻显示
        .scrollBarColor(Color.Gray) // 滚动条颜色
        .scrollBarWidth(10) // 滚动条宽度
        .edgeEffect(EdgeEffect.None)
      }
      .height('100%')
      .width('100%')
    }
    .hideTitleBar(true)
  }
}

class ChangeMessage {
  onCallSave: Function = (state: boolean) => null
  onCallGet: Function = (data: string) => null

  callSave(state: boolean) {
    this.onCallSave(state)
  }

  callGet(data: string) {
    this.onCallGet(data)
  }
}
