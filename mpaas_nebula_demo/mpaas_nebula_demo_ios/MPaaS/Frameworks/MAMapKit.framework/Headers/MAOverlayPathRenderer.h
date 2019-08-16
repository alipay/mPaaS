//
//  MAOverlayPathRenderer.h
//  MAMapKit
//
//
//  Copyright (c) 2011年 Autonavi Inc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MAOverlayRenderer.h"

/**
 *  该类设置overlay绘制的属性，可以使用该类的子类MACircleRenderer, MAPolylineRenderer, MAPolygonRenderer或者继承该类
 */
@interface MAOverlayPathRenderer : MAOverlayRenderer

/**
*  填充颜色,默认是kMAOverlayRendererDefaultFillColor
*/
@property (retain) UIColor *fillColor;

/**
 *  笔触颜色,默认是kMAOverlayRendererDefaultStrokeColor
 */
@property (retain) UIColor *strokeColor;

/**
 *  笔触宽度,默认是0
 */
@property CGFloat lineWidth;

/**
 *  LineJoin,默认是kMALineJoinBevel
 */
@property MALineJoinType lineJoinType;

/**
 *  LineCap,默认是kMALineCapButt
 */
@property MALineCapType lineCapType;

/**
 *  MiterLimit,默认是10.f
 */
@property CGFloat miterLimit;

/**
 *  是否绘制成虚线, 默认是NO
 */
@property BOOL lineDash;


@end
