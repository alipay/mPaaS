import { Constants } from '../constants/Constants';
import { TaskModel } from '../rpc/EntityModel';
import MineViewModel from '../viewmodel/MineViewModel';

@Preview({
  title: "TaskListItem"
})
@Component
struct TaskListItemComponent {
  @State message: string = 'Hello World';
  @State taskModel: TaskModel = new TaskModel(null, null, null);
  //是否编辑
  @Link isEditable: boolean
  //是否展开
  @State isExpanded: boolean = false
  @Link selectArr: Array<boolean>;
  public index: number = 0
  @Link @Watch('clickIndexCallBack') clickIndex: number

  clickIndexCallBack() {
    console.log(Constants.TAG, `clieckIndex:${this.clickIndex}  index:${this.index}`)
    if (this.clickIndex != this.index) {
      this.isExpanded = false
    }
  }

  build() {
    Column() {
      Row({ space: 15 }) {
        Text(`${this.taskModel.taskName}`)
          .fontSize(14)
        Row() {
          Column() {
            Column() {
              Text(`进度：${this.taskModel.progress}%`)
                .fontSize(14)
              Text(`${this.taskModel.updateDate}`)
                .fontSize(14)
            }
            .alignItems(HorizontalAlign.End)
            .justifyContent(FlexAlign.End)
          }

          if (this.isEditable) {
            Checkbox()
              .select(this.selectArr[this.index])
              .onChange((isCheck: boolean) => {
                console.error(Constants.TAG, `${this.index} 是否选中：${isCheck}`)
                this.selectArr[this.index] = isCheck;
                console.error(Constants.TAG, `${this.selectArr.toString()}`)
              })
              .margin({ left: 10 })
          }
        }
      }
      .width("100%")
      .height(55)
      .justifyContent(FlexAlign.SpaceBetween)

      if (this.isExpanded) {
        Row() {
          Progress({ value: 24, total: 100, type: ProgressType.Linear })
        }
        .width('100%')
        .height(55)
      }
    }
    .onClick(() => {
      //点击展开
      this.clickIndex = this.index
      this.isExpanded = !this.isExpanded
    })
    .width('100%')
    .height(this.isExpanded ? '110' : '55')
    .borderRadius(15)
    .justifyContent(FlexAlign.SpaceBetween)
    .alignItems(HorizontalAlign.Start)
    .backgroundColor(this.selectArr[this.index] ? Color.Orange : Color.Grey)
  }
}

export { TaskListItemComponent }