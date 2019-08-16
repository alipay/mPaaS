//
//  TYPowerReporter.h
//  TianYan
//
//  Created by NianXi on 16/2/18.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>


typedef NS_ENUM(NSUInteger, TYPowerApplicationMode) {
    TYPowerApplicationForegroundMode,
    TYPowerApplicationBackgroundMode,
    TYPowerApplicationUnknownMode,
};

@interface TYPowerReporter : NSObject

+ (void)startMonitor;

/**
 *  计算power
 *
 *  @param mode 耗电指数模式
 *
 *  @return power
 */
+ (NSInteger)calcPowerHealthScoreWithMode:(TYPowerApplicationMode)mode;
@end
