//
//  ATNetEnvUtil.h
//  AntLog
//
//  Created by 卡迩 on 2017/2/20.
//  Copyright © 2017年 Alipay. All rights reserved.
//
#import <Foundation/Foundation.h>
/**
 详细的网络类型.
 */
typedef NS_ENUM(NSInteger, ATNetEnv) {
    ATNetEnvUnknown         = -1, //未知网络环境
    ATNetEnvNotReachable    = 0,  //无连接
    ATNetEnvGPRS,
    ATNetEnvEdge,
    ATNetEnvWCDMA,
    ATNetEnvHSDPA,
    ATNetEnvHSUPA,
    ATNetEnvCDMA1x,
    ATNetEnvCDMAEVDOREV0,
    ATNetEnvCDMAEVDOREVA,
    ATNetEnvCDMAEVDOREVB,
    ATNetEnvHRPD,
    ATNetEnvLTE,
    ATNetEnvWWAN,
    ATNetEnvWiFi
};

/**
 粗粒度的网络类型.
 */
typedef NS_ENUM(NSInteger, ATNetEnvRaw) {
    ATNetEnvRawUnknown = -1,
    ATNetEnvRawNotReachable,
    ATNetEnvRaw2G,
    ATNetEnvRaw3G,
    ATNetEnvRaw4G,
    ATNetEnvRawWIFI
};

@interface ATNetEnvUtil : NSObject

+ (void)setup;

+ (ATNetEnv)currentNetEnv;

+ (NSString *)currentNetEnvString;

+ (ATNetEnvRaw)currentNetEnvRaw;

+ (NSString *)currentNetEnvRawString;

+ (NSString *)currentCarrierName;

@end
