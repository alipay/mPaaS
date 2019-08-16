//
//  TEXProjectFunctor.h
//  Texel
//
//  Created by feihu on 2018/11/28.
//  Copyright © 2018 Alipay. All rights reserved.
//

#import "TEXFunctor.h"
#import <CoreGraphics/CoreGraphics.h>

@interface TEXProjectFunctor : TEXFunctor

@property (nonatomic, assign) CGPoint modelLeftTop; // 模型空间中xy平面中左上角的位置，默认是(-1, 1)
@property (nonatomic, assign) CGPoint modelRightBottom; // 模型空间中xy平面中右下角的位置，默认是(1, -1)
@property (nonatomic, assign) float *matrix; // 目标的3D空间矩阵，OpenCV坐标系，以中心点为原点，x向右，y向下，z向里

@end
