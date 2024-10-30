import { TaskModel } from '../rpc/EntityModel';
import MineViewModel from '../viewmodel/MineViewModel'
import { TaskListItemComponent } from './TaskListItemComponent';

@Component
struct TaskListComponent {
  //state 组件内的数据同步
  @State message: string = 'Hello World'
  //父子组件双向同步
  @Link taskListData: Array<TaskModel>
  //是否编辑
  @Link isEditable: Boolean
  @Link selectArr: Array<boolean>
  /**
   * 这块记录下为啥要把 clickIndex放在父组件
   * 需求：点击某条item，某条item展示，其他收起
   * 在父类记录clieckIndex，把引用传给子组件，任何一个子组件改变了clickIndex的值，其他子组件都会收到回调，然后判断跟当前的index是否一致，一直则展开，不一致则收起
   */
  @State clickIndex: number = -1

  build() {
    if (this.taskListData.length > 0) {
      List() {
        ForEach(this.taskListData, (item: TaskModel, index: number | undefined) => {
          ListItem() {
            TaskListItemComponent({
              taskModel: item,
              index: index,
              isEditable: $isEditable,
              selectArr: $selectArr,
              clickIndex:$clickIndex
            })
          }
        })
      }
      .divider({ strokeWidth: 10, color: Color.White })
    } else {
      Text("暂无数据")
        .fontColor(Color.Gray)
        .fontSize(18)
        .width('100%')
        .height('100%')
        .textAlign(TextAlign.Center)
    }
  }
}

export { TaskListComponent }