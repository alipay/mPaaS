//
//  APMTask.h
//  APMultimedia
//
//  Created by aspling on 16/7/4.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

#define   APMultimedia_Error_Cancel                     (8603)        //任务取消
/**
 * 任务状态
 */
typedef NS_ENUM (NSUInteger,APMTaskStatus){
    APMTaskWaiting = 0,
    APMTaskRunning = 1,
    APMTaskCanceled = 2,
    APMTaskFailed = 3,
    APMTaskSuccess = 4,
    APMTaskInited = 100
};
/**
 * 任务优先级
 */
typedef NS_ENUM (NSUInteger,APMTaskPriority){
    APMTaskPriorityLow = 1,
    APMTaskPriorityDefault = 5,
    APMTaskPriorityHigh = 10
};
/**
 * 任务出队列方式
 */
typedef NS_ENUM (NSUInteger,APMTaskExecuteSequence){
    APMTaskExecuteSequenceFIFO = 1,//FIFO
    APMTaskExecutequenceLIFO     //LIFO
};
/**
 * 任务运行中的回调处理
 */
typedef void (^APMTaskRunningBlock)(id object,NSError *error,NSDictionary *runningInfo);
/**
 * 具体任务body block
 */
typedef void (^APMTaskBlock)();
/**
 * 任务结束时的回调处理
 */
typedef void (^APMTaskCompleteBlock)(id object,NSError *error,NSDictionary *userInfo);
@class APMTask;
@protocol APMTaskDelegate <NSObject>

-(void)taskFinished:(APMTask*)task;

@end

@interface APMTask : NSObject
/**
 * 任务名字，便于分析问题，建议设置
 */
@property (nonatomic,strong) NSString* taskAliasName;
/**
 * 任务ID
 */
@property (nonatomic,strong) NSString* taskId;
/**
 *任务优先级
 */
@property (nonatomic,assign) APMTaskPriority priority;
/**
 * 任务出队列顺序，是否是后进先出（LIFO）
 */
@property (nonatomic,assign) APMTaskExecuteSequence executeSequence;
/**
 * 任务状态
 */
@property (nonatomic,assign) APMTaskStatus taskStatus;
/**
 * 任务具体携带的待执行block
 */
@property (nonatomic,copy) APMTaskBlock taskBlock;
/**
 * 任务运行时回调
 */
@property (nonatomic,copy) APMTaskRunningBlock runningBlock;
/**
 * 任务运行结束时回调
 */
@property (nonatomic,copy) APMTaskCompleteBlock completeBlock;
/**
 * APMTaskRunningBlock and APMTaskCompleteBlock均在该queue上回调，如果为nil则任意线程回调
 */
@property (nonatomic,weak) dispatch_queue_t callbackQueue;
/**
 * delegate
 */
@property (nonatomic,weak) id<APMTaskDelegate> delegate;
/**
 * 去重的任务集合，不包括自己
 */
@property (nonatomic,strong,readonly) NSMutableArray *duplicateTasks;
/**
 * 任务加入到任务等待队列的时间点，用于后续计算
 */
@property (nonatomic,assign) CFAbsoluteTime taskAddedToWaitingListTime;
/**
 * 任务从加入到任务调度器到正式执行的队列等待时间
 */
@property (nonatomic,assign) CFAbsoluteTime taskWaitingTime;
/**
 * 任务从开始执行到任务执行结束的运行时间
 */
@property (nonatomic,assign) CFAbsoluteTime taskExecutingTime;
/**
 * 任务结束回调是否已经处理
 */
@property (nonatomic,assign,readonly,getter=isCompleteBlockHandled) BOOL completeBlockHandled;
/**
 * 包装taskBlock的NSOperation，用于cancel操作
 */
@property (nonatomic,weak) NSOperation *operation;


/**
 * 生成一个APMTask，默认是先进先出,runningblock completeBlock可以在init之后设置，如果要另外设置的话，必须在addTask之前设置
 * @param taskID
 * @param priority
 * @param callbackQueue
 */
-(instancetype)initWithTaskID:(NSString*)taskID priority:(APMTaskPriority)priority callbackQueue:(dispatch_queue_t)callbackQueue;
/**
 * 生成一个APMTask，默认是先进先出,优先级为APMTaskPriorityDefault
 * @param taskID
 * @param runningBlock
 * @param completeBlock
 * @param callbackQueue
 */
-(instancetype)initWithTaskID:(NSString*)taskID runningBlock:(APMTaskRunningBlock)runningBlock compelteBlock:(APMTaskCompleteBlock)completeBlock callbackQueue:(dispatch_queue_t)callbackQueue;

/**
 * 生成一个APMTask，默认是先进先出
 * @param taskID
 * @param priority
 * @param runningBlock
 * @param completeBlock
 */
- (instancetype)initWithTaskID:(NSString*)taskID priority:(APMTaskPriority)priority runningBlock:(APMTaskRunningBlock)runningBlock compelteBlock:(APMTaskCompleteBlock)completeBlock;
/**
 * 生成一个APMTask，sequence为APMTaskExecutequenceLIFO为后进先出，否则先进先出
 * @param taskID
 * @param priority
 * @param lifo
 * @param runningBlock
 * @param completeBlock
 */
- (instancetype)initWithTaskID:(NSString*)taskID priority:(APMTaskPriority)priority executeSequence:(APMTaskExecuteSequence)sequence runningBlock:(APMTaskRunningBlock)runningBlock compelteBlock:(APMTaskCompleteBlock)completeBlock;
/**
 * 生成一个APMTask，sequence为APMTaskExecutequenceLIFO为后进先出，否则先进先出；同时指定回调queue，不指定默认是任意线程回调
 * @param taskID
 * @param priority
 * @param lifo
 * @param runningBlock
 * @param completeBlock
 * @param callbackQueue
 */
- (instancetype)initWithTaskID:(NSString*)taskID priority:(APMTaskPriority)priority executeSequence:(APMTaskExecuteSequence)sequence runningBlock:(APMTaskRunningBlock)runningBlock compelteBlock:(APMTaskCompleteBlock)completeBlock callbackQueue:(dispatch_queue_t)callbackQueue;
/**
 * cancel功能，不同的业务处理规则可能不一样，涉及差异性的话，业务应该subclass APMTask这个类做些个性化操作。这里只是置状态为cancel,同时立即给出结束回调，携带错误码APMultimedia_Error_Cancel
 */
- (void)cancel;
@end
