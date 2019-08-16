//
//  MAGeodesicPolyline.h
//  MapKit_static
//
//  Created by songjian on 13-10-23.
//  Copyright (c) 2013年 songjian. All rights reserved.
//

#if MA_INCLUDE_OVERLAY_GEODESIC

#import "MAPolyline.h"

/**
 *  大地曲线
 */
@interface MAGeodesicPolyline : MAPolyline

/**
 *  根据MAMapPoints生成大地曲线
 *
 *  @param points MAMapPoint点
 *  @param count  点的个数
 *
 *  @return 生成的大地曲线
 */
+ (instancetype)polylineWithPoints:(MAMapPoint *)points count:(NSUInteger)count;

/**
 *  根据经纬度生成大地曲线
 *
 *  @param coords 经纬度
 *  @param count  点的个数
 *
 *  @return 生成的大地曲线
 */
+ (instancetype)polylineWithCoordinates:(CLLocationCoordinate2D *)coords count:(NSUInteger)count;

@end

#endif
