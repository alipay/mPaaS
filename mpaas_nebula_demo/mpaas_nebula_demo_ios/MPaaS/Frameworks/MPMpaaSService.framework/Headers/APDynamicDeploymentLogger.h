//
//  APDynamicDeploymentLogger.h
//  DynamicDeployment
//
//  Created by majie on 16/8/15.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface APDynamicDeploymentLogger : NSObject

+ (void)writeLoggerWithParam1:(NSString *)param1 param2:(NSString *)param2 param3:(NSString *)param3;
+ (void)writeLoggerWithArray:(NSArray *)array param2:(NSString *)param2 param3:(NSString *)param3;

/**
 动态发布统一埋点接口

 @param bizType     业务类型。"HOTPATCH", "BIRDNEST", "COMMAND"..
 @param action      执行的操作。"RPC", "Process", "Execute"
 @param event       事件。"Start", "Success", "Fail", "Exception"
 @param resId       资源Id，可为空。
 @param extParams   扩展参数
 */
+ (void)writeDynamicReleaseLog:(NSString*)bizType
                        action:(NSString*)action
                         event:(NSString*)event
                         resId:(NSString*)resId
                     extParams:(NSDictionary*)extParams;

@end
