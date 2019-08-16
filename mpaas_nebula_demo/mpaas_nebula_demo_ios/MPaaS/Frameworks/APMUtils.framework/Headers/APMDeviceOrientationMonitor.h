//
//  APMDeviceOrientationMonitor.h
//  APMUtils
//
//  Created by feihu on 2018/10/6.
//  Copyright © 2018 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

@class APMDeviceOrientationMonitor;
@protocol APMDeviceOrientationMonitorDelegate <NSObject>
- (void)orientationMonitor:(APMDeviceOrientationMonitor *)monitor changedToOrientation:(AVCaptureVideoOrientation)toOrientation fromOrientation:(AVCaptureVideoOrientation)fromOrientation;
@end

@interface APMDeviceOrientationMonitor : NSObject

+ (instancetype)sharedInstance;
- (void)registerListener:(id<APMDeviceOrientationMonitorDelegate>)listener;
- (void)unregisterListener:(id<APMDeviceOrientationMonitorDelegate>)listener;

@end
