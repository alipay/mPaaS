//
//  MPUnification.h
//  APMPaaS
//
//  Created by qiwei on 2017/1/16.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>


/**
 统一设置全局状态的操作
 */
@interface MPUnification : NSObject

/**
 显示网络活动标识
 @param show YES:显示; NO:隐藏
 @param tag 调用方标识
 */
+ (void)showNetworkActivityIndicator:(BOOL)show tag:(NSString*)tag;

/**
 禁止自动锁屏
 @param disable YES:禁止自动锁屏; NO:恢复自动锁屏
 @param tag 调用方标识
 */
+ (void)disableAutoLockScreen:(BOOL)disable tag:(NSString*)tag;

@end
