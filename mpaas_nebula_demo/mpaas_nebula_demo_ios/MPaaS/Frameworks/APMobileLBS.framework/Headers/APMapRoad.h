//
//  APMapRoad.h
//  APMap
//
//  Created by Wanlei on 14-5-5.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//


@protocol APMapRoad <NSObject>

/**
 * 道路ID
 */

@property(nonatomic, strong) NSString *id;
/**
 * 道路名称
 */

@property(nonatomic, strong) NSString *name;
/**
 * 方位
 */

@property(nonatomic, strong) NSString *direction;
/**
 * 距离
 */

@property(nonatomic, assign) double distance;
/**
 * 纬度
 */

@property(nonatomic, assign) double latitude;
/**
 * 经度
 */

@property(nonatomic, assign) double longitude;



@end
