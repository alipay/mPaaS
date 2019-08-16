//
//  ATContext.h
//  ATrack
//
//  Created by 卡迩 on 2018/4/23.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ATLogger.h"
#import "ATParameters.h"
#import "ATAppenderMgr.h"
#import "ATActionMgr.h"
#import "ATConfigMgr.h"
#import "AntLogSampleCenter.h"

@class ATUploadMgr;

extern NSString *const ATBaseLoggerName;        /**< 默认Logger name*/
extern NSString *const ATBehaviorLoggerName;    /**< 行为埋点Logger name*/

#ifdef SDK_IS4_ALIPAY
extern NSString *const ATPerformanceLoggerName; /**< 性能埋点Logger name*/
extern NSString *const ATDataFlowLoggerName;    /**< 流量监控埋点Logger name*/
extern NSString *const ATCrashLoggerName;       /**< Crash埋点Logger name*/
extern NSString *const ATMonitorLoggerName;     /**< 性能管理埋点Logger name*/
extern NSString *const ATLinkLoggerName;        /**< 全链路监控埋点Logger name*/
extern NSString *const ATEventLoggerName;       /**< 事件管理埋点Logger name*/
#endif
extern NSString *const ATCustomLoggerName;

/**
 * ATrack全局上下文
 */
@interface ATContext : NSObject

@property (class, nonatomic, strong) ATParameters *parameters;   /**< 全局参数*/
@property (class, nonatomic, strong) ATAppenderMgr *appenderMgr; /**< Appender管理器*/
@property (class, nonatomic, strong) ATUploadMgr *uploadMgr;     /**< Upload管理器*/
@property (class, nonatomic, strong) ATActionMgr *actionMgr;     /**< Action管理器*/
@property (class, nonatomic, strong) ATConfigMgr *configMgr;     /**< 策略管理器*/
@property (class, nonatomic, strong) AntLogSampleCenter *sampleCenter; /**< 抽样控制管理器*/

/**
 * ATContext单例
 */
+ (ATContext *)sharedInstance;

/**
 * 设置 \c name 对应的Logger实例
 * @param logger ATLogger子类
 * @param name Logger名
 */
- (void)setLogger:(ATLogger *)logger forName:(NSString *)name;

/**
 * 根据名称获取Logger实例
 * @param name Logger名称
 */
- (ATLogger *)loggerForName:(NSString *)name;

@end

#ifdef __cplusplus
extern "C" {
#endif
    
    /**
     * 获取ATContext实例
     */
    ATContext * ATContextGet(void);
    
#ifdef __cplusplus
}
#endif
