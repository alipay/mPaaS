//
//  BEECity.h
//  ALPDiscoveryWidget
//
//  Created by yukai44444 on 14-3-5.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@interface BEECity : NSObject
/**
 * 省名
 */

@property(nonatomic, strong) NSString *province;
/**
 * 城市名称
 */

@property(nonatomic, strong) NSString *city;
/**
 * 城市名称全拼
 */

@property(nonatomic, strong) NSString *pinyin;

/**
 * 区码
 */

@property(nonatomic, strong) NSString *adcode;

/**
 * 境内或境外标识
 */
@property (nonatomic, assign) BOOL oversea;

/**
 *  扩展参数
 */
@property (nonatomic, strong) NSString *externParam;

/**
 *  跳转链接
 */
@property (nonatomic, strong) NSString *schemaUrl;

/**
 *  地理位置信息
 */
@property (nonatomic, strong) CLLocation *location;

@end
