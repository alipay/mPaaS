//
//  ExternalSupport.h
//  ThreadMgrDemo
//
//  Created by myy on 16/10/10.
//  Copyright © 2016年 myy. All rights reserved.
//

#import <Foundation/Foundation.h>


// 该文件主要用来做解耦适配。
// 情况：一些底层OC调用，框架底层需要监控起来，但是有些模块要独立输出，不依赖框架的库，不能直接调用框架的接口。
// 方法：这些模块集成这个.h和.m文件，替换下面宏里ThisModuleName字符串为自己的模块名(区分大小写)。
// 影响：没什么影响，这些模块还是独立输出，不需要任何改动。
// 可能的疑问：这个文件的引入也算一定程度的耦合，但现实就是框架底层的任何接口修改都会导致大量依赖修改。
#ifndef EX_MAIN_CALL
#define EX_MAIN_CALL
#ifdef __cplusplus
extern "C" {
#endif

typedef void (*ExMainCallFuncType)(int bizType, const char* tag, double delayTime, enum NSOperationQueuePriority priority, dispatch_block_t block);

#define EX_MAIN_CALL_DECLARE(module) \
    extern ExMainCallFuncType gExMainCallFunc_##module; \
    extern ExMainCallFuncType gExMainACallFunc_##module; \
    extern int gExMainCallBizType_##module; \
    extern void ExMainCall_##module(const char* tag, double delayTime, enum NSOperationQueuePriority priority, dispatch_block_t block); \
    extern void ExMainACall_##module(const char* tag, double delayTime, enum NSOperationQueuePriority priority, dispatch_block_t block);

    
#define EX_MAIN_CALL_DEFINE(module) \
    ExMainCallFuncType gExMainCallFunc_##module = 0; \
    ExMainCallFuncType gExMainACallFunc_##module = 0; \
    int gExMainCallBizType_##module = 0; \
    void ExMainCall_##module(const char* tag, double delayTime, enum NSOperationQueuePriority priority, dispatch_block_t block) \
    { \
        if(gExMainCallFunc_##module) \
        { \
            gExMainCallFunc_##module(gExMainCallBizType_##module, tag, delayTime, priority, block); \
        } \
        else if(delayTime <= 0) \
        { \
            if ([NSThread isMainThread]) \
            { \
                block(); \
                return; \
            } \
            dispatch_async(dispatch_get_main_queue(), block); \
        } \
        else \
        { \
            if(delayTime >= 1000000) delayTime /= NSEC_PER_SEC; \
            dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(delayTime * NSEC_PER_SEC)), dispatch_get_main_queue(), block); \
        } \
    } \
    void ExMainACall_##module(const char* tag, double delayTime, enum NSOperationQueuePriority priority, dispatch_block_t block) \
    { \
        if(gExMainACallFunc_##module) \
        { \
            gExMainACallFunc_##module(gExMainCallBizType_##module, tag, delayTime, priority, block); \
        } \
        else if(delayTime <= 0) \
        { \
            dispatch_async(dispatch_get_main_queue(), block); \
        } \
        else \
        { \
            if(delayTime >= 1000000) delayTime /= NSEC_PER_SEC; \
                dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(delayTime * NSEC_PER_SEC)), dispatch_get_main_queue(), block); \
        } \
    }


#define EX_MAIN_CALL_SETTING(module, func, funcA, bizType) \
    gExMainCallFunc_##module = (ExMainCallFuncType)func; \
    gExMainACallFunc_##module = (ExMainCallFuncType)funcA; \
    gExMainCallBizType_##module = (int)bizType;

#ifdef __cplusplus
}
#endif
#endif // EX_MAIN_CALL


#ifdef __cplusplus
extern "C" {
#endif
// 模块相关主线程函数声明。
//#error ThisModuleName需要替换为自己模块名（区分大小写），替换后注释该错误提示。------ （第1个替换）------ （20161012注：共4个替换）
EX_MAIN_CALL_DECLARE(NebulaSDK)
#ifdef __cplusplus
}
#endif


// ------------------ 调用函数：模块内统一使用该接口切换主线程。------------------
//
// 功能：需要主线程执行block时调用。
// 原理：如果外部设置了主线程切换替换函数，则调用外部函数；否则，还走系统默认的API调用。
// 说明：主要做主线程使用的统一接管，监控和主线程性能分析定位问题使用，对使用者无性能等影响；使用模块，依然独立输出，不需要因为这个接口改动代码。
//  MAIN_CALL 和 MAINA_CALL的区别：(业务需要)
//       MAIN_CALL  - 如果主线程调用，block是同步调用的，不会异步；等同if([NSThread isMainThread])block();
//       MAINA_CALL - 如果主线程调用，block是异步调用的；等同dispatch_async(dispatch_get_main_queue(), block);
// 参数：
//     tag        统一填__FUNCTION__
//     delayTime  延迟执行时间，单位：秒。不延迟填0即可。------- !!! 注意：单位是秒，精度为浮点数。
//     priority   优先级 同NSOperationQueuePriority定义默认填0优先级。
//
//#error ThisModuleName需要替换为自己模块名（区分大小写），替换后注释该错误提示。------ （第2个替换）------
#define MAIN_CALL ExMainCall_NebulaSDK // MAIN_CALL(tag, delayTime, priority, block)
//#error ThisModuleName需要替换为自己模块名（区分大小写），替换后注释该错误提示。------ （第3个替换）------
#define MAINA_CALL ExMainACall_NebulaSDK  // MAINA_CALL(tag, delayTime, priority, block)



