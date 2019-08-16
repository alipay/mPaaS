//
//  APMDeviceInfo.h
//  APMUtils
//
//  Created by tao zeng on 2018/7/30.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

/*!
 @enum         kAPMDeviceType
 @abstract     iOS设备类型
 */
typedef enum {
    kAPMDevice_IPHONE = 0,
    kAPMDevice_IPad,
    kAPMDevice_ITouch,
} kAPMDeviceType ;

@interface APMDeviceInfo : NSObject

/*
 @function      sharedAPMDeviceInfo
 @abstract      得到 APMDeviceInfo 的单例对象
 @return        APMDeviceInfo 的单例对象
 */
+ (APMDeviceInfo *)sharedAPMDeviceInfo;

/*
 @function      deviceVersion
 @abstract      得到平台版本
 @discussion    如“iPhone5,1”
 @return        平台版本
 */
+ (NSString*)deviceVersion;

/*
 @function      deviceType
 @abstract      得到设备类型
 @return        设备类型
 */
- (kAPMDeviceType)deviceType;

@end
