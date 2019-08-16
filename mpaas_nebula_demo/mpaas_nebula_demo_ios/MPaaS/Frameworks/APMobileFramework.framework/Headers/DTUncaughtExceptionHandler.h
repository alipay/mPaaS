//
//  DTUncaughtExceptionHandler.h
//  MobileFramework
//
//  Created by WenBi on 13-5-28.
//  Copyright (c) 2013年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol DTUncaughtExceptionHandler <NSObject>

/**
 *  处理异常。
 *
 *  @param exception 指定的异常
 */
- (void)handleException:(NSException *)exception;

@end

/**
 *  获取异常处理器
 *
 *  @return 返回异常处理器
 */
id <DTUncaughtExceptionHandler> DTUncaughtExceptionHandlerGet();
