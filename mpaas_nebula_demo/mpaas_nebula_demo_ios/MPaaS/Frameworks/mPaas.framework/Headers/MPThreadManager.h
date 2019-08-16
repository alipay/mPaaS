//
//  MPThreadManager.h
//  MPThreadManager
//
//  Created by shenmo on 12/28/14.
//  Copyright (c) 2014 shenmo. All rights reserved.
//

#import <UIKit/UIKit.h>

#pragma mark APThreadManager.h

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
    
    typedef enum _APTBizType
    {
        APTBiz_Unknown  = 0,
        
        APTBiz_Home         = 10000,
        APTBiz_O2O          = 20000,
        APTBiz_O2OPurchase  = 21000,
        APBiz_O2OCommon     = 22000,
        APBiz_O2OMist       = 23000,
        APBiz_O2ORect       = 24000,
        APTBiz_Social       = 30000,
        APTBiz_PublicPlatform = 31000,
        APTBiz_Wealth       = 40000,
        APTBiz_CDP          = 50000,
        APTBiz_MovieTicket  = 60000,
        APTBiz_Bill         = 70000,
        APTBiz_CardSDK      = 80000,
        APBiz_BeeHive       = 90000,
        APBiz_ScanCode      = 100000,
        APBiz_OnsitePay     = 110000,
        APBiz_ALPPass       = 120000,
        APTBiz_RedEnvelope  = 130000,
        
        APTBiz_Frame         = 1000000,
        APTBiz_Network       = 1010000,
        APTBiz_Media         = 1020000,
        APTBiz_Account       = 1030000,
        APTBiz_Monitor       = 1040000,
        
        
        // 其它业务类型,挨着扩展小类型
        // ...
    }APTBizType;
    
    /**
     *  异步到主线程执行block。
     *  APTMainCall和APTMainACall的区别：(业务需要)
     *        APTMainCall  - 如果主线程调用，block是同步调用的，不会异步；等同if([NSThread isMainThread])block();
     *        APTMainACall - 如果主线程调用，block是异步调用的；等同dispatch_async(dispatch_get_main_queue(), block);
     *
     *  @param bizType      调用的业务类型，方便框架统一针对当前所处业务进行线程使用调优。无特殊的和不确定的，统一填0。
     *  @param tag          调用的标识串，方便跟进调用方，跟进性能、线程资源消耗等问题。目前统一填__FUNCTION__。
     *  @param delayTime    延迟执行时间，单位：秒。不延迟填0即可。
     *  @param priority     优先级，方便排队管理。系统定义的5级优先级＋扩展优先级。
     *                      扩展优先级（10000:最高优先执行，不排队；后面扩展优先级，支持各种策略）。
     *                      原则：先管理，然后内部消化。默认填0优先级。
     *  注意：参数类型不要随便改。比如：用double就和业务模块一致都用double，不能改成NSTimeInterval等。底层接口都是改个参数都影响其它模块。
     */
    void APTMainCall(APTBizType bizType, const char* tag, double delayTime, NSOperationQueuePriority priority, dispatch_block_t block);
    void APTMainACall(APTBizType bizType, const char* tag, double delayTime, NSOperationQueuePriority priority, dispatch_block_t block);
    
    /**
     *  封装异步线程调用方法，方便线程的使用监控。
     *
     *  @param bizType      调用的业务类型，方便框架统一针对当前所处业务进行线程使用调优。无特殊的和不确定的，统一填0。
     *  @param tag          调用的标识串，方便跟进调用方，跟进性能、线程资源消耗等问题。目前统一填__FUNCTION__。
     *  @param delayTime    延迟执行时间，单位：秒。不延迟填0即可。
     *  @param queue        block运行的queue。
     *  注意：参数类型不要随便改。比如：用double就和业务模块一致都用double，不能改成NSTimeInterval等。底层接口都是改个参数都影响其它模块。
     */
    void APTAsyncCall(APTBizType bizType, const char *tag, double delayTime, dispatch_queue_t queue, dispatch_block_t block);
    void APTAsyncOperationQueueCall(APTBizType bizType, const char *tag, NSOperationQueue *queue, dispatch_block_t block);
    
    /**
     * 内部使用defaultThreadPool进行处理。
     */
    void APAsyncCall(NSOperationQueuePriority priority, dispatch_block_t block);
    
    
    // Deprecated use functions above
    void APMainCall(dispatch_block_t block) __deprecated;
    void APPrimitiveAsyncCall(const char *function, int line, NSOperationQueuePriority priority, dispatch_block_t block) __deprecated;
    void APMainThreadCall(const char *function, int line, dispatch_block_t block) __deprecated;
    
#ifdef __cplusplus
}
#endif // __cplusplus

#pragma mark APThreadPool.h

typedef NS_ENUM(NSInteger, APTaskPriority) {
    APTaskPriorityVeryLow   = -8L,
    APTaskPriorityLow       = -4L,
    APTaskPriorityNormal    = 0,
    APTaskPriorityHigh      = 4,
    APTaskPriorityVeryHigh  = 8
};

/**
 *  线程池
 */
@interface APThreadPool : NSObject

@property NSInteger maxConcurrentTaskCount;

@property (getter = isSuspended) BOOL suspended; // 设置线程池是否挂起。
@property (getter = isPaused)    BOOL paused;    // 挂起线程池时，是否有任务暂停。

/**
 *  默认线程池，有10个线程同时处理任务。
 *
 *  @return 默认的线程池对象。
 */
+ (APThreadPool *)defaultThreadPool;

/**
 *  处理登录事件的线程池，有2个线程同时处理任务。这个线程池只有在登录之后才会执行。
 *
 *  @return 登录后的线程池对象。
 */
+ (APThreadPool *)preloadThreadPoolForLogin;

/**
 *  处理网络初始化和启动过程中rpc(非登录)的线程池，有5个线程同时处理任务。这个线程池在某些情况下会降级到冷启动完成后再执行。
 *
 *  @return 处理网络初始化和启动过程中rpc(非登录)线程池对象。
 */
+ (APThreadPool *)networkProcessThreadPool;

/**
 *  处理启动过程中登录rpc事件的线程池，未设置并发数。这个线程池在某些情况下会降级到冷启动完成后再执行。
 *
 *  @return 处理登录rpc线程池对象。
 */
+ (APThreadPool *)loginRPCProcessThreadPool;

/**
 *  处理核心业务操作的线程池，最大并发数cpu个数2倍，且不大于10。
 *
 *  @return 核心业务操作的线程池对象。
 */
+ (APThreadPool *)coreProcessThreadPool;

/**
 *  处理首页5个Tab显示相关的线程池，最大并发数cpu个数2倍，且不大于10。
 *
 *  @return 处理首页显示的线程池对象。
 */
+ (APThreadPool *)homeShowThreadPool;

/**
 *  添加任务到当前的线程池。
 *
 *  @param taskId   字符串，用于标识要添加到线程池中的任务。
 *  @param priority 优先级
 *  @param block    block
 */
- (void)addTask:(NSString *)taskId priority:(APTaskPriority)priority block:(void (^)(void))block;

/**
 *  添加任务，如果线程是挂起的，则加入到当前线程池中等待执行。如果是未挂起的，则直接在当前线程执行任务
 *
 *  @param taskId   字符串，用于标识要添加到线程池中的任务。
 *  @param priority 优先级
 *  @param block    block
 */
- (void)addTaskIfSuspended:(NSString *)taskId priority:(APTaskPriority)priority block:(void (^)(void))block;

@end
