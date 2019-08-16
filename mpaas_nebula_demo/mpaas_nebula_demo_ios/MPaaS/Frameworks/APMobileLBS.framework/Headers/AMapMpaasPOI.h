//
//  AMapMpaasPOI.h
//  APMap
//
//  Created by Wanlei on 14-5-5.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//


@protocol AMapMpaasPOI <NSObject>


/**
 * POI信息
 */

@property(nonatomic, strong) NSString *id;
/**
 * POI名称
 */

@property(nonatomic, strong) NSString *name;
/**
 * POI类型
 */

@property(nonatomic, strong) NSString *type;
/**
 * POI对应电话号码
 */

@property(nonatomic, strong) NSString *tels;
/**
 * POI方向
 */

@property(nonatomic, strong) NSString *direction;
/**
 * POI距离
 */

@property(nonatomic, assign) double distance;
/**
 * POI所在纬度
 */

@property(nonatomic, assign) double latitude;
/**
 * POI所在经度
 */

@property(nonatomic, assign) double longitude;
/**
 * POI所在地址
 */

@property(nonatomic, strong) NSString *address;
/**
 * POI权重
 */

@property(nonatomic, strong) NSString *poiwight;

/**
 * 是否来源支付宝口碑，true为来源自口碑，false表示来自高德
 */

@property(nonatomic, assign) BOOL isAlipay;

@end
