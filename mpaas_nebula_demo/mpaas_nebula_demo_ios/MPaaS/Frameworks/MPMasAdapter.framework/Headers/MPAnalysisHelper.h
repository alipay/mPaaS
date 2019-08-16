//
//  MPAnalysisHelper.h
//  MPAnalysis
//
//  Created by yangwei on 16/12/6.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MPAnalysisHelper : NSObject

+ (instancetype)sharedInstance;

/**
 * 启动 crash 监控
 */
+ (void)enableCrashReporterService;

/**
 * 设置开启卡顿监控的百分比（默认10%）, 需在startPerformanceMonitor调用之前设置
 * @param percent  取值范围 0 ~ 100
 */
+ (void)setLagMonitorPercent:(NSUInteger)percent;

//启动性能监控,一般在启动后立刻调用，例如didFinishLauncher中
+ (void)startPerformanceMonitor;


// 设置电量消耗的统计时间，默认为1800秒，也就是应用累计使用半个小时，将电量使用情况上报一次。最小设置值为300秒, 设置为0或不设置都是默认1800秒,如果需要设置，在启动性能监控前设置
+ (void)setBatteryMonitorPeriod:(NSTimeInterval)seconds;


/**
 *  后台回前台时，是否进行报活
 *  该方法默认实现为YES。
 */
- (void)setShouldLogReportActiveWillEnterForeground:(BOOL)shouldLog;

/**
 *  当使用日志报活功能时，可以配置从后台切回前台的报活最小间隔时间。
 *  从后台切回前台时，距离上次报活时间少于多少秒时，不再报活。如果传0，每次后台切回前台都会报活。
 *  这个不影响冷启动，如果冷启动，每次都会报活。
 *  该方法默认返回0，单位秒(s)
 */
- (void)setLogReportActiveMinInterval:(NSTimeInterval)timeInterval;

/**
 *  使用日志记录App启动的时间，根据业务需要在合适的时机调用此方法写入报活日志，一般启动时机为app启动到闪屏结束首页显示出来的时间。
 *  @param time          启动耗费的时间，单位毫秒(ms)
 */
- (void)writeLogForStartupWithTime:(NSTimeInterval )time;

/**
 *  是否存在闪退日志，如果有则上传日志
 *
 */
- (void)writeLogForCrashReporter;

/**
 *  使用日志记录的数据进行设备报活，根据业务需要在合适的时机调用此方法写入设备报活日志，一般每次冷启动算一次报活，可在didFinishLauncher中调用此方法。
 *  另外此方法默认会监听后台回前台的通知，可以配置从后台切回前台的报活最小间隔时间。
 *  从后台切回前台时，距离上次报活时间少于多少秒时，不再报活。默认最小报活间隔为0，即每次回前台都会报活一次
 *  业务可重写 - (NSTimeInterval)logReportActiveMinInterval 进行设置
 */
- (void)writeLogForReportActive;

/**
 *  使用日志记录的数据进行登录报活，一般在用户登录成功后调用此方法写入登录报活日志
 *
 *  @param style     指定登录的方式。如密码登录、指纹登录、免登等，业务自行设定字符串进行区分，相关数据会展示在mPaaS移动分析控制台 活跃用户 字段
 */
- (void)writeLogForLoginActiveWithStyle:(NSString *)style;

/**
 *  使用日志记录的数据进行注册报活，一般在用户注册成功后调用此方法写入注册报活日志
 *
 *  @param style     指定注册的方式。如用户名、手机号、第三方应用等，业务自行设定字符串进行区分，相关数据会以饼图形式展示在mPaaS移动分析控制台 注册用户 字段
 */
- (void)writeLogForRegistActiveWithStyle:(NSString *)style;

@end
