import { TaskListComponent } from '../component/TaskListComponent';
import { Constants } from '../constants/Constants';
import { TaskModel } from '../rpc/EntityModel';
import MineViewModel from '../viewmodel/MineViewModel';

@Entry
@Component
struct PageTask {
  //state 组件内的数据同步，增加完数据，更新此变量
  @State taskListData: Array<TaskModel> = MineViewModel.getTaskList()
  @State isEditable: Boolean = false
  //state 如果想让子组件修改数据，可以用state修饰，然后将引用传给子组件
  @State selectArr: Array<boolean> = []

  build() {
    Column() {
      Row() {
        Text("目标列表")
        if (this.isEditable) {
          Row() {
            Text("取消")
              .onClick(() => {
                this.selectArr = MineViewModel.disSelectAll()
                this.isEditable = !this.isEditable
              })
            Text("全选")
              .onClick(() => {
                this.selectArr = MineViewModel.selectAll()
              })
              .margin({ left: 10 })
          }
        } else {
          Text("编辑")
            .onClick(() => {
              this.isEditable = !this.isEditable
            })
        }
      }
      .justifyContent(FlexAlign.SpaceBetween)
      .width('100%')

      TaskListComponent({
        taskListData: $taskListData,
        isEditable: $isEditable,
        selectArr: $selectArr
      })
        .width('100%')
        .height('80%')
        .margin({ top: 10 })
      Button(this.isEditable ? "删除目标" : "添加目标")
        .width(100)
        .height(55)
        .fontSize(14)
        .onClick(() => {
          if (this.isEditable) {
            //编辑中->删除
            MineViewModel.delTaskList(this.selectArr)
          } else {
            //非编辑->添加
            MineViewModel.addTaskList(`测试目标-${MineViewModel.getTaskList().length}`)
          }
          console.error(Constants.TAG, this.selectArr.toString())
          this.taskListData = MineViewModel.getTaskList()
          this.isEditable = false
          //清空选中的数据，避免打开再次勾选，这是清空数组的方式，啊啊啊啊啊啊啊~什么垃圾语法
          this.selectArr.length = 0
        })
    }
    .justifyContent(FlexAlign.Center)
    .width('100%')
    .height('100%')
    .padding(16)
  }
}