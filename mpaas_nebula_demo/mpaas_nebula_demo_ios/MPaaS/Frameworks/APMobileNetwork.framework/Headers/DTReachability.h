//
//  DTReachability.h
//  APMobileNetwork
//
//  Created by 朱建 on 13-4-10.
//  Copyright (c) 2013年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DTNetReachability.h"
#import <CoreTelephony/CTTelephonyNetworkInfo.h>


/*!
 @class     DTReachability
 @abstract  网络访问类型工具类
 */
@interface DTReachability : NSObject

/*!
 @property      networkStatus
 @abstract      当前的网络类型
 @discussion    可以判断的网络类型包括：无数据网络；wifi网络；移动数据网络
 */
@property(nonatomic, assign) MPAASNetworkStatus networkStatus;

/*!
 @property      networkStatus 10.1.12添加 灰度中 业务暂不要用
 @abstract      当前的网络类型
 @discussion    可以更准确的判断的网络类型包括：无数据网络,2G,3G,4G,wifi网络
 */
@property(nonatomic, assign) MPAASNNetworkStatus currentNetworkStatus;

/*!
 @function      sharedDTReachability
 @abstract      得到 DTReachability 的单例对象
 @return        DTReachability 的单例对象
 */
+ (DTReachability *)sharedDTReachability;

/*!
 @function      refreshReachability
 @abstract      手工刷新当前网络状态
 */
- (void)refreshReachability;

/*!
 @function      isReachable
 @abstract      判断当前网络是否连通
 */
- (BOOL)isReachable;

/*!
 @function      isReachableVia4G
 @abstract      判断当前网络是否是4G网络
 */
- (BOOL)isReachableVia4G;

/*!
 @function      isReachableVia3G
 @abstract      判断当前网络是否是3G网络
 */
- (BOOL)isReachableVia3G;

/*!
 @function      isReachableVia2G
 @abstract      判断当前网络是否是2G网络
 */
- (BOOL)isReachableVia2G;

/**
 * CTTelephonyNetworkInfo实例
 *
 *  @return CTTelephonyNetworkInfo Instance
 */
-(CTTelephonyNetworkInfo *)telephonyInfo;

/**
 *  iOS7以下      WIFI|WWAN|NotReachable
 *  iOS7及以上    WIFI|GPRS|WCDMA|HSDPA|HSUPA|CDMA1X|CDMAEVDOREV0|CDMAEVDOREVA|CDMAEVDOREVB|HRPD|LTE|UNKNOWN|NotReachable
 *
 *  @return 网络类型名称
 */
+ (NSString *)networkName;

@end
