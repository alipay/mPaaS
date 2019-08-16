//
//  MAHeatMapTileOverlay.h
//  test2D
//
//  Created by xiaoming han on 15/4/21.
//  Copyright (c) 2015年 AutoNavi. All rights reserved.
//

#if MA_INCLUDE_OVERLAY_HEATMAP

#import "MATileOverlay.h"

/**
 *  热力图节点
 */
@interface MAHeatMapNode : NSObject

/**
 *  经纬度
 */
@property (nonatomic, assign) CLLocationCoordinate2D coordinate;

/**
 *  强度
 */
@property (nonatomic, assign) float intensity;

@end

/**
 *  热力图渐变属性
 */
@interface MAHeatMapGradient : NSObject<NSCopying>

/**
 *  颜色 default [blue,green,red]
 */
@property (nonatomic, readonly) NSArray *colors;

/**
 *  default [@(0.2),@(0.5),@(0,9)]
 */
@property (nonatomic, readonly) NSArray *startPoints;


/**
 *  重新设置gradient的时候，需要执行 MATileOverlayView 中的 reloadData 方法
 *
 *  @param colors      颜色
 *  @param startPoints startPoints
 *
 *  @return instance
 */
- (instancetype)initWithColor:(NSArray *)colors andWithStartPoints:(NSArray *)startPoints;

@end

/**
 *  热力图tileOverlay
 */
@interface MAHeatMapTileOverlay : MATileOverlay

/**
 *  MAHeatMapNode array
 */
@property (nonatomic, strong) NSArray *data;

/**
 *  热力图半径，默认为12，范围:0-100 screen point
 */
@property (nonatomic, assign) NSInteger radius;

/**
 *  透明度，默认为0.6，范围：0-1
 */
@property (nonatomic, assign) CGFloat opacity;

/**
 *  热力图梯度
 */
@property (nonatomic, strong) MAHeatMapGradient *gradient;

/**
 *  是否开启高清热力图，默认关闭
 */
@property (nonatomic, assign) BOOL allowRetinaAdapting;

@end

#endif


