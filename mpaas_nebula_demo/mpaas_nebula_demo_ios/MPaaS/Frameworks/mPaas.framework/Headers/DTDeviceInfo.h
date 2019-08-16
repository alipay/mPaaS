//
//  DTDeviceInfo.h
//  MobileFoundation
//
//  Created by 朱建 on 13-4-9.
//  Copyright (c) 2013年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

#if 1

// 这个类在mPaas里主要是为了一些以framework引入的模块的兼容问题，请不要直接使用

@class UIScreenMode;

/*!
 @enum         kDeviceType
 @abstract     iOS设备类型
 */
typedef enum {
    kDevice_IPHONE = 0,
    kDevice_IPad,
    kDevice_ITouch,
} kDeviceType ;

typedef enum {
    kDevice_Screen_LOW,         // not retina
    kDevice_Screen_IPHONE4,     // 4 or 4s
    kDevice_Screen_IPHONE5,     // 5 or 5s or 5c
    kDevice_Screen_IPHONE6,     // 6
    kDevice_Screen_IPHONE6p,    // 6 plus
    kDevice_Screen_IPAD,        // all pads
} kDeviceScreenCategory ;

/*!
 @class         DTDeviceInfo
 @abstract      设备信息类
 */
@interface DTDeviceInfo : NSObject

/*!
 @function      sharedDTDeviceInfo
 @abstract      得到 DTDeviceInfo 的单例对象
 @return        DTDeviceInfo 的单例对象
 */
+ (DTDeviceInfo *)sharedDTDeviceInfo;

/*!
 @function      osVersion
 @abstract      得到操作系统版本号
 @return        操作系统版本号
 */
+ (float)osVersion;

/*!
 @function      deviceName
 @abstract      得到设备名称
 @discussion    即[[UIDevice currentDevice] name]
 @return        设备名称
 */
+ (NSString *)deviceName;

/*!
 @function      totalDiskSpace
 @abstract      得到SD盘空间总大小
 @return        空间总大小
 */
+ (NSNumber *)totalDiskSpace;

/*!
 @function      freeDiskSpace
 @abstract      得到SD盘剩余的空闲空间大小
 @return        剩余的空闲空间大小
 */
+ (NSNumber *)freeDiskSpace;

/*!
 @function      screenMode
 @abstract      得到屏幕模式
 @discussion    即[UIScreen mainScreen].currentMode
 @return        屏幕模式
 */
- (UIScreenMode *)screenMode;

/*!
 @function      platformString
 @abstract      得到平台类型
 @discussion    如“iPhone 5 (CDMA)”、“iPad 3 (GSM)”
 @return        平台类型
 */
- (NSString *)platformString;

/*!
 @function      deviceVersion
 @abstract      得到平台版本
 @discussion    如“iPhone5,1”
 @return        平台版本
 */
+ (NSString*)deviceVersion;

/*!
 @function      deviceType
 @abstract      得到设备类型
 @return        设备类型
 */
- (kDeviceType)deviceType;

/**
 *  取屏幕类别，不过只能在真机上生效
 */
+ (kDeviceScreenCategory)deviceScreenCategory;

/*!
 @function      imei
 @abstract      得到设备imei
 @discussion    此处对移动快捷强依赖，取移动快捷的imei
 @return        imei
 */
- (NSString *)imei;

/*!
 @function      imsi
 @abstract      得到设备imsi
 @discussion    此处对移动快捷强依赖，取移动快捷的imsi
 @return        imsi
 */
- (NSString *)imsi;

/*!
 @function      tid
 @abstract      得到设备tid
 @discussion    此处对移动快捷强依赖，取移动快捷的tid
 @return        tit
 */
- (NSString *)tid;

/*!
 @function      clientId
 @abstract      得到设备ClientId
 @discussion    [imsi]|[imei]，与目前移动快捷另外生成的clientId(uuid)不同
 @return        clientId
 */
- (NSString *)clientId;

/*!
 @function      did
 @abstract      得到设备did
 @discussion    [imsi]|[imei]|[clientKey]
 @return        did
 */
- (NSString *)did;

/*!
 @function      apdid
 @abstract      得到设备指纹
 @return        apdid
 */
- (NSString *)apdid;

/*!
 @function      currentAwid
 @abstract      得到本次启动后的awid
 @return        awid
 */
- (NSString *)currentAwid;

/**
 * 判断本机是否被越狱。
 */
+ (BOOL)isJailbreak;

@end

#endif