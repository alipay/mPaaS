//
//  AULoggerShell.h
//  AntUIShell
//
//  Created by niki on 2019/4/3.
//  Copyright © 2019年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AULoggerBaseShell : NSObject

/*
 埋点协议 APMonitor
 */
//按钮的actionName的埋点协议
+ (void)setButtonActionLog:(UIButton *)button
             actionNameLog:(NSString *)actionName;

// 埋点上报
+ (void)remoteLogging:(NSString*)seed
                 ucId:(NSString *)ucId
               exInfo:(NSArray*)exInfo;

+ (void)remoteLogging:(NSString*)seed exInfo:(NSArray*)exInfo;

+ (void)MTBIZReport:(NSString *) bizName
            subName:(NSString* )subName
           failCode:(NSInteger) failCode
             params:(NSDictionary*) params;

+ (void)performanceLog:(NSString *)biztype controlName:(NSString *)controlName;

/**
 * 新的事件埋点
 *
 */
+ (void)eventLog:(NSString*)eventId params:(NSDictionary*)params;

@end


@interface AULoggerShell : AULoggerBaseShell

@end

Class AUGetLogger();




NS_ASSUME_NONNULL_END
