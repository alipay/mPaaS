//
//  APRemoteLogger+AntLog.h
//  APRemoteLogging
//
//  Created by 卡迩 on 2017/9/29.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <APRemoteLogging/APRemoteLogging.h>
#import "AntBehavior.h"
#ifdef SDK_IS4_ALIPAY
#import "AntPerformance.h"
#endif

@interface APRemoteLogger (AntLog)
/**
 开/关Log功能
 
 @param enable 传入YES开启，否则关闭。默认开启。
 */
+ (void)enableLog:(BOOL)enable;

/**
 行为埋点接口
 
 @param behavior 行为埋点信息. @see \c AntBehavior.
 */
+ (void)logBehavior:(AntBehavior *)behavior;

#ifdef SDK_IS4_ALIPAY
/**
 性能埋点接口
 
 @param performance 性能埋点信息. @see \c AntPerformance.
 */
+ (void)logPerformance:(AntPerformance *)performance;

#endif

@end
