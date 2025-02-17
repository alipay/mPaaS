import { TitleComponent } from '../component/TitleComponent';
import { BannerJsonPostReq } from '../rpc/BannerJsonPostReq';
import { REQ_MODEL } from '../rpc/REQ_MODEL';
import { RpcDemoClient } from '../rpc/RpcDemoClient';
import router from '@ohos.router';
import { DLogger } from '../logger/DLogger';
import { Constants } from '../constants/Constants';
import { AppManager, AppNode, getProxy, XRiverProxy } from '@mpaas/hriver';
import { BannerArrayModel } from '../rpc/EntityModel';
import { PostReqModle } from '../rpc/PostReqModle';
import { JSON, util } from '@kit.ArkTS';
import { ArticleList0JsonGetReq } from '../rpc/ArticleList0JsonGetReq';
import { BaseTitleComponent } from 'library/Index';
import { curContext, curUIContext } from '../constants/Global';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct PageRpc {
  @State message: string = 'Hello World';
  private btnSize: string[] = ["post", "post1", "router", "limit", "熔断前请求", "熔断后请求", "大数据请求"];
  @State params: object = router.getParams();

  funReq(item: string) {
    switch (item) {
      case "post":
        this.rpcPost()
        break
      case "post1":
        this.rpcPost1()
        break
      case "router":
        this.rpcRouter()
        break
      case "limit":
        this.rpclimit()
        break
      case "熔断前请求":
        this.rpcRongduanNormal()
        break
      case "熔断后请求":
        this.rpcRongduanError()
        break
      case "大数据请求":
        this.rpcBigData()
        break
    }
  }

  async getLoaclJson(): Promise<string> {
    return new Promise((resolve: Function, reject: Function) => {
      try {
        curContext().resourceManager.getRawFileContent("request.json", (err, value) => {
          if (!!err) {
            reject(err)
            return
          }
          let rawFile = value;
          let textDecoder = util.TextDecoder.create('utf-8', { ignoreBOM: true })
          let result = textDecoder.decodeWithStream(rawFile, { stream: false });
          resolve(result)
        });
      } catch (error) {
        let code = (error as BusinessError).code;
        let message = (error as BusinessError).message;
        console.error(`callback getRawFileContent failed, error code: ${code}, message: ${message}.`);
      }
    });
  }

  //post
  rpcBigData() {
    this.getLoaclJson().then(result => {
      console.info(Constants.TAG, `本地json：${result}`)

      let userName: string = this.params?.['userName'];
      let passWord: string = this.params?.['passWord'];
      let client = new RpcDemoClient()
      let reqModel: REQ_MODEL = {
        userName: userName,
        password: result
      }
      let bannerJsonPostReq: BannerJsonPostReq = {
        _mPaaSCustomBody: reqModel
      }
      client.bannerJsonPost(bannerJsonPostReq).then((result: BannerArrayModel) => {
        this.message = JSON.stringify(result)
      }).catch((e: Error) => {
        //通过e.message可以拿到具体的报错原因
        this.message = JSON.stringify(JSON.stringify(e))
      });
    }).catch((error: Error) => {
      console.info(Constants.TAG, `本地jsonerror：${JSON.stringify(error)}`)
    })
  }

  //post
  rpcPost() {
    let userName: string = this.params?.['userName'];
    let passWord: string = this.params?.['passWord'];
    //构造请求类
    let client = new RpcDemoClient()
    //构造请求体
    let reqModel: REQ_MODEL = {
      userName: userName,
      password: passWord
    }
    let bannerJsonPostReq: BannerJsonPostReq = {
      _mPaaSCustomBody: reqModel
    }
    //调用请求方法
    client.bannerJsonPost(bannerJsonPostReq).then((result: BannerArrayModel) => {
      this.message = JSON.stringify(result)
    }).catch((e: Error) => {
      //通过e.message可以拿到具体的报错原因
      this.message = JSON.stringify(JSON.stringify(e))
    });
  }

  //post
  rpcPost1() {
    let userName: string = this.params?.['userName'];
    let passWord: string = this.params?.['passWord'];
    let client = new RpcDemoClient()
    let postModle: PostReqModle = {
      username: userName,
      password: passWord
    }
    client.post1(postModle).then((result: string) => {
      this.message = JSON.stringify(result)
    }).catch((e: Error) => {
      this.message = JSON.stringify(e)
      //通过e.message可以拿到具体的报错原因
    });
  }

  //limit
  rpclimit() {
    let userName: string = this.params?.['userName'];
    let passWord: string = this.params?.['passWord'];
    let client = new RpcDemoClient()
    let postModle: PostReqModle = {
      username: userName,
      password: passWord
    }
    client.post1(postModle).then((result: string) => {
      this.message = JSON.stringify(result)
    }).catch((e: Error) => {
      this.message = JSON.stringify(e)
      //通过e.message可以拿到具体的报错原因
      console.error(Constants.TAG, JSON.stringify(e))
    });
  }

  //router
  rpcRouter() {
    let client = new RpcDemoClient()
    client.postRouter().then((result: string) => {
      this.message = JSON.stringify(result)
    }).catch((e: Error) => {
      this.message = JSON.stringify(e)
      //通过e.message可以拿到具体的报错原因
    });
  }

  //熔断前请求
  rpcRongduanNormal() {
    let postModle: ArticleList0JsonGetReq = {
      cid: "222"
    }
    let client = new RpcDemoClient()
    client.postRongduan(postModle).then((result: string) => {
      this.message = JSON.stringify(result)
    }).catch((e: Error) => {
      this.message = JSON.stringify(e)
      //通过e.message可以拿到具体的报错原因
    });
  }

  //熔断后请求
  rpcRongduanError() {
    let postModle: ArticleList0JsonGetReq = {
      cid: "输入123触发熔断"
    }
    let client = new RpcDemoClient()
    client.postRongduan(postModle).then((result: string) => {
      this.message = JSON.stringify(result)
    }).catch((e: Error) => {
      this.message = JSON.stringify(e)
      //通过e.message可以拿到具体的报错原因
    });
  }

  build() {
    Flex({ direction: FlexDirection.Column }) {
      BaseTitleComponent({ title: "移动网关" })
      Scroll() {
        Column() {
          ForEach(this.btnSize, (item: string) => {
            Button(`${item}`)
              .width('80%')
              .fontSize(16)
              .margin({ top: 10 })
              .fontWeight(FontWeight.Bold)
              .onClick(() => {
                this.funReq(item)
              })
          })
          Text(`返回数据:\n${this.message}`)
            .margin({ top: 10 })
            .height(300)
            .width('90%')
            .borderWidth(2)
            .borderColor(Color.Blue)
            .textAlign(TextAlign.Start)
        }
        .justifyContent(FlexAlign.Start)
        .alignItems(HorizontalAlign.Center)
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
    .width('100%')
    .height('100%')
  }
}