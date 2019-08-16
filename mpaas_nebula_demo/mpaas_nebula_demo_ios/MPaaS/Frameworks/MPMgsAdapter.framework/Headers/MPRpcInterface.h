//
//  MPRpcInterface.h
//  MPMgsAdapter
//
//  Created by yemingyu on 2019/2/13.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <APMobileNetwork/APMobileNetwork.h>

NS_ASSUME_NONNULL_BEGIN

@interface MPRpcInterface : NSObject


/**
 初始化 MGS 组件，在调用第一个 RPC 之前必须调用，建议在 App 启动时较早时机调用
 */
+ (void)initRpc;

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
 * 添加RPC拦截器。
 *
 * @param RPCInterceptor 要添加的RPC拦截器对象。
 */
+ (void)addRpcInterceptor:(id<DTRpcInterceptor>)RPCInterceptor;

/**
 * 从现有的拦截器列表中移除RPC拦截器。
 *
 * @param RPCInterceptor 要移除的RPC拦截器对象。
 */
+ (void)removeRpcInterceptor:(id<DTRpcInterceptor>)RPCInterceptor;

/**
 * 返回当前DTRpcCommonInterceptor对象的拦截器列表。
 *
 * @return 拦截器列表数组。
 */
+ (NSArray*)interceptorList;

/**
 获取组件当前环境信息

 @return 字典类型，包括组件信息
 */
+ (NSDictionary *)getComponentEnv;

@end

NS_ASSUME_NONNULL_END
