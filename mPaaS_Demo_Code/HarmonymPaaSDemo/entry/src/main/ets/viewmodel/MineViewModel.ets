import { MineModel, TaskModel } from '../rpc/EntityModel'
import { systemDateTime } from '@kit.BasicServicesKit';
import { Constants } from '../constants/Constants';

export class MineViewModel {
  public getSettingList(): Array<MineModel> {
    let listData: Array<MineModel> = [
      new MineModel($r('app.media.icon'), "移动网关", $r('app.media.ic_back_white')),
      new MineModel($r('app.media.icon'), "实时发布", $r('app.media.ic_back_white')),
      new MineModel($r('app.media.icon'), "小程序", $r('app.media.ic_back_white')),
      new MineModel($r('app.media.icon'), "离线包", null),
      new MineModel($r('app.media.icon'), "移动网关", $r('app.media.ic_back_white')),
      new MineModel($r('app.media.icon'), "实时发布", $r('app.media.ic_back_white')),
      new MineModel($r('app.media.icon'), "小程序", $r('app.media.ic_back_white')),
      new MineModel($r('app.media.icon'), "离线包", null),
    ]
    return listData;
  }

  private taskListData: Array<TaskModel> = new Array<TaskModel>()

  getTaskList(): Array<TaskModel> {
    return this.taskListData
  }

  //添加任务
  addTaskList(taskName: String) {
    let newTask: TaskModel = new TaskModel(taskName, "0", `更新日期：${systemDateTime.getTime(true)}`)
    this.taskListData.push(newTask)
  }

  //删除任务
  delTaskList(selectArr: Array<Boolean>) {
    // if (delArr.length == 0) {
    //   console.error(Constants.TAG, "请选择要删除的数据")
    //   return
    // }
    // for (let index = 0; index < delArr.length; index++) {
    //   if (delArr[index]) {
    //     this.taskListData.splice(index, 1)
    //   }
    // }

    if (!selectArr) {
      console.error(Constants.TAG, "请选择要删除的数据")
    }
    let dataLen = this.taskListData.length - 1;
    for (let i = dataLen; i >= 0; i--) {
      if (selectArr[i]) {
        this.taskListData.splice(i, 1);
      }
    }
  }

  delArr(): Array<Boolean> {
    let delArr: Array<Boolean> = new Array<Boolean>()
    for (let index = 0; index < this.taskListData.length; index++) {
      delArr.push(false);
    }
    return delArr
  }

  selectAll(): Array<boolean> {
    let selectAllArray: Array<boolean> = []
    for (let index = 0; index < this.getTaskList().length; index++) {
      selectAllArray[index] = true
    }
    return selectAllArray
  }

  disSelectAll(): Array<boolean> {
    let selectAllArray: Array<boolean> = []
    for (let index = 0; index < this.getTaskList().length; index++) {
      selectAllArray[index] = false
    }
    return selectAllArray
  }
}

export default new MineViewModel()
