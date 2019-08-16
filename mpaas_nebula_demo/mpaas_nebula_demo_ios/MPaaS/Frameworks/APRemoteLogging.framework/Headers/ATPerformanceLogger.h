//
//  ATPerformanceLogger.h
//  APRemoteLogging
//
//  Created by 卡迩 on 2018/6/26.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import "ATLogger.h"
#import "AntPerformance.h"

/**
 * 性能埋点Logger
 */
@interface ATPerformanceLogger : ATLogger

/**
 * 性能埋点
 * @param perf 性能埋点参数对象 @see \c AntPerformance
 */
- (void)logPerformance:(AntPerformance *)perf;

@end

#ifdef __cplusplus
extern "C" {
#endif
    
    /**
     * 获取性能Logger实例
     */
    ATPerformanceLogger * ATPerfLoggerGet();
    
#ifdef __cplusplus
}
#endif
