//
//  APMTaskManager.h
//  APMultimedia
//
//  Created by aspling on 16/7/4.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "APMTask.h"

@interface APMTaskScheduler : NSObject
/**
 * 最大任务并发数
 */
@property (nonatomic,assign) NSUInteger maxConcurrentTasks;
/**
 * 是否打开Task统计开关，主要用于统计task是否阻塞
 */
@property (nonatomic,assign) BOOL openStatisticsFlag;

/**
 * 初始化，targetqueue非空则所有add进来的task都在该queue里执行，否则提供一个默认的NSOperationQueue
 */
+ (instancetype)instanceWithTargetQueue:(NSOperationQueue*)targetQueue name:(NSString*)name;
/**
 * 增加一个任务,内部处理去重逻辑
 */
- (void)addTask:(APMTask *)task;
/**
 * 删除一个任务
 */
- (void)removeTask:(APMTask *)task;
/**
 * 取消一个任务
 */
- (void)cancelTask:(NSString*)taskID;
/**
 * 根据任务ID获取一个任务
 */
- (id)getTask:(NSString*)taskID;
@end
