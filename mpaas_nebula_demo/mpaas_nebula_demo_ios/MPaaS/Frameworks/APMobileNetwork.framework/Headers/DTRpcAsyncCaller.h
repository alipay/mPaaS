 //
//  DTRpcAsyncCaller.h
//  APMobileNetwork
//
//  Created by WenBi on 13-4-20.
//  Copyright (c) 2013年 Alipay. All rights reserved.
//

//#import "DTRpcAsyncCaller.h"

@interface DTRpcAsyncCaller : NSObject
/**
 *  异步执行block，去掉主线程参与
 *  区别：该方法和callAsyncBlock的区别是completion保持子线程回调。
 *  目的：减少默认的主线程抢占导致的UI性能问题，从而数据处理等默认都在子线程;
 *       只有在有必要的UI处理时，业务主动调用框架API（如：APTMainCall）切换到主线程。
 *  建议：业务使用该方法，callAsyncBlock将逐步废弃。
 *
 *  @param block      执行block
 *  @param completion 结束block
 *
 *  @return
 */
+ (DTRpcAsyncCaller*)callNoMainThreadAsyncBlock:(void (^)(void))block completion:(void (^)(void))completion;

/**
 *  异步block，completion会在主线程回调
 *
 *  @param block      相关操作
 *  @param completion block完成后的处理
 *
 *  @return DTRpcAsyncCaller
 */
+ (DTRpcAsyncCaller *)callAsyncBlock:(void (^)(void))block completion:(void (^)(void))completion;


/**
 swift异步block，completion会在主线程回调

 *  @param block      相关操作
 *  @param completion block完成后的处理
 *
 *  @return DTRpcAsyncCaller
 */
+ (DTRpcAsyncCaller*)callSwiftAsyncBlock:(void (^)(void))block completion:(void (^)(NSError *error))completion;
/**
 *  异步block
 *  区别：该方法和startAsyncBlock的区别是completion保持子线程回调。
 *  目的：减少默认的主线程抢占导致的UI性能问题，从而数据处理等默认都在子线程;
 *       只有在有必要的UI处理时，业务主动调用框架API（如：APTMainCall）切换到主线程。
 *  建议：业务使用该方法，startAsyncBlock将逐步废弃。
 *
 *  @param block      执行block
 *  @param completion 结束block
 */
- (void)startNoMainThreadAsyncBlock:(void (^)(void))block completion:(void (^)(void))completion;

/**
 *  异步block，completion会在主线程回调
 *
 *  @param block      异步block
 *  @param completion block完成后的处理
 */
- (void)startAsyncBlock:(void (^)(void))block completion:(void (^)(void))completion;

/**
 *  取消任务
 */
- (void)cancel;
/**
 *  任务是否完成
 *
 *  @return yes/no
 */
- (BOOL)isFinished;
/**
 *  任务是否取消
 *
 *  @return yes/no
 */
- (BOOL)isCancelled;
/**
 *  获取当前异步线程
 *
 *  @return 当前线程
 */
- (NSThread *)asyncThread;
/**
 *  处理异常
 *
 *  @param exception 异常
 */
- (void)handleException:(NSException *)exception;

/**
 *  swift适配接口 异步block，completion会在主线程回调
 *
 *  @param block      异步block
 *  @param completion block完成后的处理 oc exception会被捕获 通过error参数返回给业务 框架不在处理exception
 */
- (void)startSwiftAsyncBlock:(void (^)(void))block completion:(void (^)(NSError *error))completion;


@end
