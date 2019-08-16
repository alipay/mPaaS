//
//  TianYan.h
//  TianYan
//
//  Created by myy on 16/3/30.
//  Copyright © 2016年 myy. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <TianYan/TianYanConfig.h>
#import <TianYan/TianYanDelegate.h>



/**
 *  天眼SDK版本字符串，如：1.0.0
 */
FOUNDATION_EXPORT const unsigned char TianYanVersionString[];



/**
 *  天眼SDK主接口。
 */
@interface TianYan : NSObject
@property (nonatomic, strong, readonly) TianYanConfig* config;                  /** 天眼SDK配置参数属性，必现在开始监控前设置 */
@property (nonatomic, weak) id<TianYanRealtimeParamDelegate>  paramDelegate;  /** 天眼SDK配置delegate属性，必现在开始监控前设置 */
@property (nonatomic, weak) id<TianYanLogAndReportDelegate>   reportDelegate; /** 天眼SDK配置delegate属性，必现在开始监控前设置 */
@property (nonatomic, weak) id<TianYanEventDelegate>          eventDelegate;  /** 天眼SDK配置delegate属性，必现在开始监控前设置 */

/**
 *  获取天眼SDK接口单例。
 */
+ (TianYan*)sharedInstance;

/**
 *  启动所有监控，包括：性能、电量、内存、存储、流量等。
 *  建议在用户看到App启动完成后调用。
 */
- (void)startMonitor;

/**
 *  获取当前已使用内存
 */
+ (double)usedMemory;

/**
 *  获取当前进程CPU使用率，如0.1即表示10%
 */
+ (float)cpuUsage;

/**
 * 获取当前已使用磁盘存储，返回：存储字节、存储计算时间、上次清理磁盘时间。
 * 如果存储占用还没算好，返回nil；否则返回dict，dict内容：
 *     DISK_STAT_BYTES          磁盘存储占用字节
 *     DISK_STAT_ELAPSED_TIME   上次统计存储过去时间，单位秒
 *     CLEAN_DISK_ELAPSED_TIME  上次清理磁盘过去时间，单位秒
 */
+ (NSDictionary*)usedStorageInfo;

@end













