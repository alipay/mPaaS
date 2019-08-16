//
//  ATBehaviorLogger.h
//  ATrack
//
//  Created by 卡迩 on 2018/5/3.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import "ATLogger.h"
#import "AntBehavior.h"

/**
 * 行为Logger
 */
@interface ATBehaviorLogger : ATLogger

/**
 * 点击埋点
 * @param b 行为埋点参数对象 @see \c AntBehavior
 */
- (void)click:(AntBehavior *)b;

/**
 * 曝光埋点
 * @param b 行为埋点参数对象 @see \c AntBehavior
 */
- (void)exposure:(AntBehavior *)b;

/**
 * 通用行为事件
 * @param b 行为埋点参数对象 @see \c AntBehavior
 */
- (void)event:(AntBehavior *)b;

@end

#ifdef __cplusplus
extern "C" {
#endif
    
    /**
     * 获取行为Logger实例
     */
    ATBehaviorLogger * ATBehaviorLoggerGet();
    
#ifdef __cplusplus
}
#endif
