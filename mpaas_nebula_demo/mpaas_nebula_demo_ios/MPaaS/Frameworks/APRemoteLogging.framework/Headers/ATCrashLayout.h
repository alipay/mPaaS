//
//  ATCrashLayout.h
//  APRemoteLogging
//
//  Created by 卡迩 on 2018/7/3.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import "ATLayout.h"

extern NSString *const kDefaultCrashHeader;/**< 默认Crash日志Header: e*/
extern NSString *const kCrashLogVersion;   /**< Crash日志版本*/

/**
 * Crash埋点Layout
 */
@interface ATCrashLayout : ATLayout

@end
