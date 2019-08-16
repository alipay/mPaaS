//
//  APCrashLogParamHelper.h
//  APRemoteLogging
//
//  Created by NianXi on 16/6/16.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <mach/mach.h>
#import <pthread.h>

@interface APCrashLogParamHelper : NSObject

/**
 *  闪退发生时最近浏览的一个H5页面
 *
 *  @return NSString型 URL , 可能为空
 */
+ (NSString *_Nullable)lastWebURL;

/**
 *  已生效的hotpatch脚本信息
 *
 *  @return NSString型 多个脚本以"|"分隔，如 ，可能为空
 */
+ (NSString *_Nullable)executedPatchsInfo;

/**
 *  iam扩展信息
 *
 *  @return NSString型 可能为空
 */
+ (NSString *_Nullable)ebcContextInfo;
+ (NSString *_Nullable)ebcContextInfo:(void *_Nullable)ucontext;

/**
 *  已经加载的bundle信息
 *
 *  @return NSString型 可能为空
 */
+ (NSString *_Nullable)bundleInfo;

/**
 *  进程存活时间，单位秒
 *
 *  @return time_t 存活秒数
 */
+ (time_t)survivalTime;

/**
    发生闪退的线程的Queue名称

 @return NSString * 队列名，可能为空
 */
+ (NSString *_Nullable)crashThreadQueueName:(thread_t)thread;

/**
    发生闪退的线程的线程名

 @return NSString * 线程名，可能为空
 */
+ (NSString *_Nullable)crashThreadName:(thread_t)thread;

/**
 *  字典格式化 转成 key=value^key=value^key=value 格式字符串
 *
 *  @param dic 字典
 *
 *  @return 格式化后的字符串
 */
+ (NSString *_Nullable)convertToLogFromDic:(NSDictionary *_Nonnull)dic;

/**
 *  数组格式化 转成 a|b|c|d 格式字符串
 *
 *  @param array 数组
 *
 *  @return 格式化后的字符串
 */
+ (NSString *_Nullable)convertToLogFromArray:(NSArray *_Nonnull)array;

/**
 *  用于日志的可读fetch状态字符
 *
 *  @return NSString *型 用于日志的可读fetch状态字符
 */
+ (NSString *_Nullable)backgroundFetchStateReadableString;

/**
 *  用于日志的可读hotspot状态字符
 *
 *  @return NSString *型 用于日志的可读hotspot状态字符
 */
+ (NSString *_Nullable)hotspotHelperStateReadableString;

/**
 *  用于日志的可读healthkit状态字符
 *
 *  @return NSString *型 用于日志的可读healthkit状态字符
 */
+ (NSString *_Nullable)healthkitStateReadableString;
+ (NSString *_Nullable)pushStateReadableString;
+ (NSString *_Nullable)watchStateReadableString;
+ (NSString *_Nullable)voipStateReadableString;

/**
 *  用于日志的可读函数覆盖率开关状态字符
 *
 *  @return NSString *型 用于日志的可读函数覆盖率开关状态字符
 */
+ (NSString *_Nullable)functionCoverageState;

/**
 *  获取非空的前后台状态值（通过UIApplicationState辅助二次校准）
 * 
 *  @return 非空的前后台状态字符串
 */
+ (nonnull NSString *)applicationStateReadableString;

/**
 *  当前appid
 *
 *  @return NSString *型
 */
+ (NSString *_Nullable)currentAppId;

/**
 *  当前H5应用的唯一标识（格式为：appid_version_releasetype)
 *
 *  @return NSString *型
 */
+ (NSString *_Nullable)currentH5AppUniqueId;

/**
 *  当前内存使用大小信息，可能为空
 *
 *  @return NSString *型
 */
+ (NSString *_Nullable)usedMemory;
@end
