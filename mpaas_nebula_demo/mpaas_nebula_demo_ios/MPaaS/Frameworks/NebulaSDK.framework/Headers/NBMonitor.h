//
//  NBMonitor.h
//  Nebula
//
//  Created by chenwenhong on 15/10/8.
//  Copyright © 2015年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString *const NBMonitorParamsAppId;
extern NSString *const NBMonitorParamsUrl;
extern NSString *const NBMonitorParamsVersion;
extern NSString *const NBMonitorParamsLogStr;

@protocol PSDLoggerProtocol;

@protocol NBMonitorDelegate;

@interface NBMonitor : NSObject <NAMLogProtocol, PSDLoggerProtocol>

@property(nonatomic, weak) id<NBMonitorDelegate> delegate;

+ (instancetype)defaultMonitor;

- (void)logWithLogId:(NSString *)logId params:(NSDictionary *)params;
- (void)logWithLogId:(NSString *)logId params:(NSDictionary *)params target:(PSDKernel *)target;


//禁止创建实例
+ (instancetype)alloc UNAVAILABLE_ATTRIBUTE;

- (instancetype)init UNAVAILABLE_ATTRIBUTE;

- (id)copy UNAVAILABLE_ATTRIBUTE;

+ (instancetype)allocWithZone:(struct _NSZone *)zone UNAVAILABLE_ATTRIBUTE;

+ (instancetype)new UNAVAILABLE_ATTRIBUTE;

@end


@protocol NBMonitorDelegate <NSObject>

- (void)monitor:(NBMonitor *)monitor logWithLogId:(NSString *)logId params:(NSDictionary *)params;

@optional

- (void)monitor:(NBMonitor *)monitor logWithLogId:(NSString *)logId params:(NSDictionary *)params target:(PSDKernel *)target;


@end
