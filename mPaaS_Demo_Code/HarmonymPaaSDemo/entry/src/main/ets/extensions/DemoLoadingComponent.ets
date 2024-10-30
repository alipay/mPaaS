import { EntryInfo, RightButtonState } from '@mpaas/xriverohos';

type AnimationStep = () => void;

@Component
export struct DemoLoadingComponent {
  @State rightButtonState: RightButtonState = new RightButtonState();
  appId?: string = '' // 小程序id
  @Prop appInfo?: EntryInfo; // 加载信息
  @Prop loadingProgress: number = 0; // 加载进度
  @Prop errorCode: number = 0; // 错误码，非0表示错误
  @State progressRotateOptions: RotateOptions = {
    angle: 0,
    centerX: '50%',
    centerY: '50%',
  }
  private rotateAnimationStep1?: AnimationStep;
  private rotateAnimationStep2?: AnimationStep;
  private rotateAnimationStep3?: AnimationStep;

  build() {
    Column() {
      Row() {
        RightButtonComponent({
          rightButtonState: this.rightButtonState
        })
          .margin({
            top: 0,
            right: 12,
            bottom: 0,
            left: 0
          })
      }.width('100%').justifyContent(FlexAlign.End)

      Row().height('20%')
      Stack() {
        Progress({
          value: this.loadingProgress,
          total: 100,
          type: ProgressType.Ring
        })
          .width(55)
          .height(55)
          .color(this.errorCode <= 0 ? 0x1677ff : 0xdddddd)
          .backgroundColor(0xdddddd)
          .style({ strokeWidth: 1 })
          .rotate(this.progressRotateOptions)
        Image(this.appInfo?.iconUrl).alt($r('app.media.loading_page_icon'))
          .width(40).height(40).borderRadius(20)
      }

      Row().height(18)
      Text(this.appInfo?.title).fontColor(0x333333).fontSize(18).width(
        '100%').textAlign(TextAlign.Center)
      if (this.errorCode > 0) {
        Row().height(21)
        Text('网络不给力').fontColor(0x333333).fontSize(20).width('100%'
        ).textAlign(TextAlign.Center)
        Row().height(10)
        Text('请稍后再试').fontColor(0xaaaaaa).fontSize(14).width('100%'
        ).textAlign(TextAlign.Center)
      }
    }
    .width('100%')
  }

  aboutToAppear(): void {
    // rotate animation config
    this.rotateAnimationStep1 = this.generateAnimateStep(
      this.generateAnimateParam(() => {
        this.rotateAnimationStep2?.()
      }),
      120
    )
    this.rotateAnimationStep2 = this.generateAnimateStep(
      this.generateAnimateParam(() => {
        this.rotateAnimationStep3?.()
      }),
      240
    )
    this.rotateAnimationStep3 = this.generateAnimateStep(
      this.generateAnimateParam(() => {
        // reset rotateOptions
        this.progressRotateOptions = {
          angle: 0,
          centerX: '50%',
          centerY: '50%',
        }
        // repeat animation step
        if (this.errorCode <= 0) {
          this.rotateAnimationStep1?.()
        }
      }),
      360
    )
    setTimeout(() => {
      this.rotateAnimationStep1?.()
    }, 1000)
  }

  aboutToDisappear(): void {
  }

  private generateAnimateStep(value: AnimateParam, angle: number): AnimationStep {
    return () => {
      animateTo(value, () => {
        this.progressRotateOptions = {
          angle: angle,
          centerX: '50%',
          centerY: '50%',
        }
      })
    }
  }

  private generateAnimateParam(event: () => void):
    AnimateParam {
    return {
      duration: 300,
      tempo: 1,
      curve: Curve.Linear,
      iterations: 1,
      playMode: PlayMode.Normal,
      onFinish: () => {
        setTimeout(event, 5);
      }
    }
  }
}

@Component
export struct RightButtonComponent {
  @ObjectLink rightButtonState: RightButtonState

  build() {
    Button({
      type: ButtonType.Normal,
      stateEffect: false
    }) {
    }
    .visibility(Visibility.Visible)
    .backgroundColor('#00000000')
    .onClick((event) => {
      if (this.rightButtonState.onClickListener !== undefined) {
        this.rightButtonState.onClickListener(event);
      }
    })
  }
}