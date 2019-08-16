//
//  ATEventLogger.h
//  APRemoteLogging
//
//  Created by LiMengtian on 2018/10/29.
//  Copyright © 2018 Alipay. All rights reserved.
//

#import "ATLogger.h"

NS_ASSUME_NONNULL_BEGIN

/**
    事件管理Logger
 */
@class AntEvent;

@interface ATEventLogger : ATLogger

/**
    事件埋点
 */
- (void)log:(AntEvent *)event;

@end

#ifdef __cplusplus
extern "C" {
#endif
    
    /**
     * 获取事件Logger实例
     */
    ATEventLogger * ATEventLoggerGet();
    
#ifdef __cplusplus
}
#endif

NS_ASSUME_NONNULL_END
