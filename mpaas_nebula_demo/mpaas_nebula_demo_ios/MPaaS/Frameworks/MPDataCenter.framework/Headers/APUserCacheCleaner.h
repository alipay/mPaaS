//
//  APUserCacheCleaner.h
//  MobileFoundation
//
//  Created by shenmo on 3/13/15.
//  Copyright (c) 2015 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, APCacheCleanPhase)
{
    APCacheCleanPhasePreCalculating = 0,    // 执行前扫描沙箱大小
    APCacheCleanPhaseCleaning,              // 正在清理
    APCacheCleanPhasePostCalculating,       // 执行完成扫描沙箱大小
    APCacheCleanPhaseDone,                  // 完成
};

/**
 *  执行清理完成发出的通知，子线程抛出
 */
extern NSString* const kAPUserCacheCleanerDidExecuted;

@interface APUserCacheCleaner : NSObject

/**
 *  异步执行清理。必须传一个回调方法。
 *  当phase返回APCacheCleanPhasePreCalculating，APCacheCleanPhaseCleaning，APCacheCleanPhasePostCalculating时，progress代表真实的进度。最大为1.0。
 *  当phase为APCacheCleanPhaseDone时，progress返回清理了多少MB的数据。
 *
 *  @param callback 回调方法
 */
+ (void)execute:(void(^)(APCacheCleanPhase phase, float progress))callback;

@end
