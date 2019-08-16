//
//  MAUserLocation+Offset.h
//  APMap
//
//  Created by 去疾 on 16/10/10.
//  Copyright © 2016年 Alipay. All rights reserved.
//
#import <MAMapKit/MAUserLocation.h>
#import <CoreLocation/CoreLocation.h>


@interface MAUserLocation (Offset)

/**
 *  坐标系偏移，原来实现在老版本高德SDK中，现已移除，这里做适配处理
 *
 *  @param coordinate GPS坐标
 *
 *  @return 高德坐标
 */
+ (CLLocationCoordinate2D)offsetCoordinate:(CLLocationCoordinate2D)coordinate;

@end
