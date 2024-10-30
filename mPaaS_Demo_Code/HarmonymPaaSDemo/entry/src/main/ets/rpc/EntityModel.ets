import { ArrayList } from '@kit.ArkTS';

export class BannerArrayModel {
  data: ArrayList<BannerModel> = new ArrayList();
}

export class BannerModel {
  desc: string = "";
}

export class MineModel {
  img: Resource;
  desc: String;
  other: Resource | null;

  constructor(img: Resource, desc: String, other: Resource | null) {
    this.img = img;
    this.desc = desc;
    this.other = other;
  }
}

export class TaskModel {
  taskName: String | null | Resource;
  progress: String | null | Resource;
  updateDate: String | null | Resource;

  constructor(taskName: String | null | Resource, progress: String | null | Resource, updateDate: String | null | Resource) {
    this.taskName = taskName;
    this.progress = progress;
    this.updateDate = updateDate;
  }
}