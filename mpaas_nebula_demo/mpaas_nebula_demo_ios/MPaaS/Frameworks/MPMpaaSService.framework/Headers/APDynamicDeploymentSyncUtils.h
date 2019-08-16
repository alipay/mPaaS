//
//  APDynamicDeploymentSyncUtils.h
//  DynamicDeployment
//
//  Created by majie on 16/7/1.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface APDynamicDeploymentSyncUtils : NSObject

@property(nonatomic, strong) NSString *MDSSyncType;

#pragma mark sync silence
/**
 * 判断sync是否在静默期，如果在静默期，丢弃
 */
- (BOOL)isBeyondSyncSilentTime;

/**
 * 保持sync静默期的最大时间间隔，默认3分钟
 */
- (NSUInteger)keepSilentMaxTimeinterval;

/**
 * 设置客户端接收sync的最大时间间隔，sync下发，默认3分钟
 */
- (BOOL)setKeepSilentMaxTime:(NSUInteger)maxTimeinterval;

/**
 上次收到sync的时间，用来计算sync静默期
 
 @return 上次sync接收时间
 */
- (NSTimeInterval)lastSyncSilentBeginTime;

/**
 记录收到sync的当前时间，用来计算sync静默期
 
 @return 当前时间
 */
- (BOOL)setSyncSilentBeginTime;


#pragma mark monitor
/*!
 * sync接收
 */
- (void)monitorSyncArrived;

/*!
 * sync data 解析失败
 */
- (void)monitorSyncDataParseError;

/*!
 * sync data 数据不合法
 */
- (void)monitorSyncDataInavilade;

/*!
 * rpc data 数据不合法
 */
- (void)monitorRPCDataInavilade;

/*!
 * sync不在静默期内，有效
 */
- (void)monitorSyncArrivedAndNotInSilent;

/*!
 * 处理升级sync data
 */
- (void)monitorUpgradeWithSyncData:(NSString *)newVersion;

/*!
 * 升级sync下发需要再次请求rpc
 */
- (void)monitorUpgradeWithSyncRPC:(NSString *)newVersion;

+ (NSObject *)dataFromUserInfo:(NSNotification *)notification forKey:(NSString *)key;


@end
