//
//  MAMultiColoredPolylineRenderer.h
//  MapKit_static
//
//  Created by yi chen on 12/11/15.
//  Copyright © 2015 songjian. All rights reserved.
//

#import "MAPolylineRenderer.h"
#import "MAMultiPolyline.h"

/**
 此类用于绘制MAMultiPolyline对应的多段线，支持分段颜色绘制
 */
@interface MAMultiColoredPolylineRenderer : MAPolylineRenderer

/**
*  根据指定的MAPolyline生成一个多段线Renderer
*
*  @param multiPolyline 指定MAMultiPolyline
*
*  @return 新生成的多段线Renderer
*/
- (instancetype)initWithMultiPolyline:(MAMultiPolyline *)multiPolyline;

/**
 *  关联的MAMultiPolyline model
 */
@property (nonatomic, readonly) MAMultiPolyline *multiPolyline;

/**
 *  分段绘制的颜色
 *  需要分段颜色绘制时，必须设置（内容必须为UIColor）
 */
@property (nonatomic, strong) NSArray *strokeColors;

/**
 *  颜色是否渐变
 */
@property (nonatomic, getter=isGradient) BOOL gradient;

@end
