//
//  NetworkStatusManager.h
//  APMultimedia
//
//  Created by aspling on 16/4/11.
//  Copyright © 2016年 Alipay. All rights reserved.
//


/**
   Posted when network reachability changes.
   This notification assigns no notification object. The `userInfo` dictionary contains an `NSNumber` object under the `AFNetworkingReachabilityNotificationStatusItem` key, representing the `AFNetworkReachabilityStatus` value for the current network reachability.

   @warning In order for network reachability to be monitored, include the `SystemConfiguration` framework in the active target's "Link Binary With Library" build phase, and add `#import <SystemConfiguration/SystemConfiguration.h>` to the header prefix of the project (`Prefix.pch`).
 */
extern NSString * const APMNetReachabilityDidChangeNotification;
extern NSString * const APMNetReachabilityNotificationStatusItem;

typedef NS_ENUM (NSInteger, APMNetworkReachabilityStatus) {
    APMNetReachabilityStatusUnknown = -1,
    APMNetReachabilityStatusNotReachable = 0,
    APMNetReachabilityStatusReachableViaWWAN = 1,
    APMNetReachabilityStatusReachableViaWWAN2G = 2,
    APMNetReachabilityStatusReachableViaWWAN3G = 3,
    APMNetReachabilityStatusReachableViaWWAN4G = 4,
    APMNetReachabilityStatusReachableViaWiFi = 5,
};

typedef void (^APMNetStatusChangeBlock)(APMNetworkReachabilityStatus oldStatus,APMNetworkReachabilityStatus newStatus);

/**
 *  当前网络类型及网络切换监控类
 *  网络切换通过广播方式通知
 *
 */
@interface APMNetworkStatusManager : NSObject

/**
 *  singleTon
 *
 *  @return
 */
+ (instancetype)manager;

/**
 *  当前网络类型
 *
 *  @return
 */
- (APMNetworkReachabilityStatus)currentNetworkStatus;
/**
 *  变化前网络类型
 *
 *  @return
 */
- (APMNetworkReachabilityStatus)previousNetworkStatus;
/**
 *  是否是飞行模式
 *
 *  @return 如是返回YES，否则返回NO
 */
- (BOOL)isAirplaneMode;
/**
 *  将网络转态枚举转成human readable String
 *
 *  @param status 网络状态枚举
 *
 *  @return human readable String
 */
+ (NSString*)stringOfNetworkStatus:(APMNetworkReachabilityStatus)status;


/**
 *  开始监听网络变化
 *  网络监听变化需要调用start方法
 */
- (void)startMonitoring;

@end
