//
//  ATMonitorLogger.h
//  APRemoteLogging
//
//  Created by 卡迩 on 2018/7/4.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import "ATLogger.h"
#import "ATMonitor.h"

/**
 * 性能管理Logger
 */
@interface ATMonitorLogger : ATLogger

/**
 * 性能管理埋点
 * @param monitor 性能管理参数对象 @see \c ATMonitor
 */
- (void)monitor:(ATMonitor *)monitor;

@end

#ifdef __cplusplus
extern "C" {
#endif
    
    /**
     * 获取性能管理Logger实例
     */
    ATMonitorLogger * ATMonitorLoggerGet();
    
#ifdef __cplusplus
}
#endif
