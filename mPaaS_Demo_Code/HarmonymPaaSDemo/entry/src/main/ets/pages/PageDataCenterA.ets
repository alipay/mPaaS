import { hilog } from '@kit.PerformanceAnalysisKit';
import { MPData, MPFile } from '@mpaas/datacenter';
import { MPFramework } from '@mpaas/framework';
import { Constants } from '../constants/Constants';
import { DLogger } from '../logger/DLogger';
import { BusinessError } from '@kit.BasicServicesKit';
import { TitleComponent } from '../component/TitleComponent';
import { BaseTitleComponent } from 'library/Index';
import { getLoaclJson } from '../constants/Global';
import { MPFileUtils } from '../constants/MPFileUtils';


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

  saveDataByFile() {
    getLoaclJson("pageIndexConfig.txt").then((result: string) => {
      console.info(Constants.TAG, `读取本地json：${result}`)
      MPFileUtils.getInstance().saveFileByName("testFile")
    }).catch((error: Error) => {
      console.error(Constants.TAG, `读取数据error ${JSON.stringify(error)}`)
    })
  }

  getDataByFile() {
    MPFileUtils.getInstance().getFileByName("testFile").then((result) => {
      console.info(Constants.TAG, `文件存储获取：${result}`)
    }).catch((err: Error) => {
      console.info(Constants.TAG, `文件存储获取：${JSON.stringify(err)}`)
    })
  }

  saveDataByKey() {
    getLoaclJson("pageIndexConfig.txt").then((result: string) => {
      console.info(Constants.TAG, `读取本地json：${result}`)
      MPData.put(this.SAVE_KEY_GLOBE, result).then().catch((err: BusinessError) => {
        console.log(Constants.TAG, err)
      })
    }).catch((error: Error) => {
    })
  }

  getDataByKey() {
    MPData.get(this.SAVE_KEY_GLOBE).then((value => {
      if (typeof value == "string") {
        DLogger.error("取数据", value)
      }
    })).catch((err: BusinessError) => {
      console.log(Constants.TAG, err)
    })
  }

  saveDataByUserId() {
    DLogger.error("userid", MPFramework.instance.userId!!)
    DLogger.error("SAVE_KEY_USERID", this.SAVE_KEY_USERID)
    MPData.put(this.SAVE_KEY_USERID, "本自具足来自userid", { userId: "test0001" })
      .then()
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
    })).catch((error: BusinessError) => {
      this.message = `Failed to get data code is ${error.code},message is ${error.message}`
      console.error(`Failed to get data code is ${error.code},message is ${error.message}`);
    })
  }

  saveDataByEncrypt() {
    MPData.put(this.SAVE_KEY_ENCRYPT, "本自具足来自Encrypt", { encrypt: true }).then().catch((error: BusinessError) => {
      console.error(`Failed to get data code is ${error.code},message is ${error.message}`);
    })
  }

  getDataByEncrypt() {
    MPData.get(this.SAVE_KEY_ENCRYPT, { encrypt: true }).then((value => {
      if (typeof value == "string") {
        DLogger.error("Encrypt取数据", value)
      }
    })).catch((error: BusinessError) => {
      console.error(`Failed to get data code is ${error.code},message is ${error.message}`);
    })
  }

  build() {
    NavDestination() {
      Row() {
        Column() {
          BaseTitleComponent({
            title: "存储",
            leftClickEvent: (): void => {

            }
          })
          Scroll() {
            Column() {
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

              Button("文件-存数据")
                .fontSize(16)
                .margin(5)
                .fontWeight(FontWeight.Bold)
                .onClick(() => {
                  this.saveDataByFile()
                })
              Button("文件-取数据")
                .fontSize(16)
                .margin(5)
                .fontWeight(FontWeight.Bold)
                .onClick(() => {
                  this.getDataByFile()
                })
            }
          }
          .backgroundColor(0xDCDCDC)
          .scrollable(ScrollDirection.Vertical) // 滚动方向为垂直方向
          .scrollBar(BarState.On) // 滚动条常驻显示
          .scrollBarColor(Color.Gray) // 滚动条颜色
          .scrollBarWidth(10) // 滚动条宽度
          .edgeEffect(EdgeEffect.Spring) // 滚动到边沿后回弹
          .height('100%')
          .width('100%')
        }
        .height('100%')
        .width('100%')
      }
      .height('100%')
      .width('100%')
    }
    .hideTitleBar(true)
  }
}
