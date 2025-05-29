import { ArrayList } from "@kit.ArkTS";

export class BoneListModel {
  skeletons: SkeletonsModel | null = null;
  requestId: string = ""
}

export class SkeletonsModel {
  points: ArrayList<pointModel> | null = null;
  boundingBox: BoundingBoxModel | null = null;
  score: string = ""
}

export class BoundingBoxModel {
  left: number = 0;
  top: number = 0;
  width: number = 0
  height: number = 0
}

export class pointModel {
  score: string = "";
  point: PointModel | undefined | null = null;
  type: string = ""
}

export class PointModel {
  x: string = "";
  y: string = "";
}