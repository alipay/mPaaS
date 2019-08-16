//
//  MAMultiPolyline.h
//  MapKit_static
//
//  Created by yi chen on 12/11/15.
//  Copyright © 2015 songjian. All rights reserved.
//

#import "MAPolyline.h"

/**
 *  此类用于定义一个由多个点相连的多段线，绘制时支持分段采用不同颜色（纹理）绘制，点与点之间尾部相连但第一点与最后一个点不相连, 通常MAMultiPolyline是
 *  MAMultiColoredPolylineRenderer（分段颜色绘制）或MAMultiTexturePolylineRenderer（分段纹理绘制）的model
 */
@interface MAMultiPolyline : MAPolyline

/**
*  绘制索引数组(纹理、颜色索引数组), 成员为NSNumber, 且为非负数
*/
@property (nonatomic, strong, readonly) NSArray *drawStyleIndexes;

/**
 *  分段绘制，根据map point数据生成多段线
 *  分段纹理绘制：其对应的MAMultiTexturePolylineRenderer必须使用 - (BOOL)loadStrokeTextureImages:(NSArray *)textureImages; 加载纹理图片, 否则使用默认的灰色纹理绘制
 *  分段颜色绘制：其对应的MAMultiColoredPolylineRenderer必须设置strokeColors属性
 *
 *  @param points           指定的直角坐标点数组
 *  @param count            坐标点的个数
 *  @param drawStyleIndexes 纹理索引数组(颜色索引数组), 成员为NSNumber, 且为非负数
 *
 *  @return 生成的折线对象
 */
+ (instancetype)polylineWithPoints:(MAMapPoint *)points count:(NSUInteger)count drawStyleIndexes:(NSArray*) drawStyleIndexes;

/**
 *  分段绘制，根据经纬度坐标数据生成多段线
 *  分段纹理绘制：其对应的MAMultiTexturePolylineRenderer必须使用 - (BOOL)loadStrokeTextureImages:(NSArray *)textureImages; 加载纹理图片, 否则使用默认的灰色纹理绘制
 *  分段颜色绘制：其对应的MAMultiColoredPolylineRenderer必须设置strokeColors属性
 *
 *  @param coords           指定的经纬度坐标点数组
 *  @param count            坐标点的个数
 *  @param drawStyleIndexes 纹理索引数组(颜色索引数组), 成员为NSNumber, 且为非负数
 *
 *  @return 生成的折线对象
 */
+ (instancetype)polylineWithCoordinates:(CLLocationCoordinate2D *)coords count:(NSUInteger)count drawStyleIndexes:(NSArray*) drawStyleIndexes;

@end
