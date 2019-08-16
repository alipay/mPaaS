//
//  APMVideoUtils.h
//  APMUtils
//
//  Created by aspling on 16/6/23.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger,APMCameraPermissionType) {
    APMCameraPermissionGranted,           // 已授权
    APMCameraPermissionNoVideo,           // 摄像头无权限
    APMCameraPermissionNoAudio,           // 麦克风无权限
};

typedef NS_OPTIONS(NSUInteger, APMDevicePermission) {
    APMDevicePermissionVideo = 1 << 0,
    APMDevicePermissionAudio = 1 << 1,
};

@interface APMVideoUtils : NSObject

+ (void)requestCameraPermission:(void (^)(APMCameraPermissionType granted))block;
+ (void)requestDevicePermission:(APMDevicePermission)requestedPermission completion:(void (^)(APMCameraPermissionType granted))completion;

+ (NSDictionary *)defaultAudioOuputSetting;

@end

extern NSString *const kAPMCameraFrameNotification;
extern NSString *const kAPMCameraFrameSampleBufferKey;
