//
//  ATCrashLogger.h
//  APRemoteLogging
//
//  Created by 卡迩 on 2018/7/3.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import "ATLogger.h"
#import "ATCrash.h"

/**
 * Crash Logger
 */
@interface ATCrashLogger : ATLogger

/**
 * Crash埋点
 * @param crash crash埋点参数对象 @see \c ATCrash
 */
- (void)logCrash:(ATCrash *)crash;

@end

#ifdef __cplusplus
extern "C" {
#endif
    
    /**
     * 获取Crash Logger实例
     */
    ATCrashLogger * ATCrashLoggerGet();
    
#ifdef __cplusplus
}
#endif
