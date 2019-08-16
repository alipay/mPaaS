//
//  DTRpcClient2.h
//  APMobileNetwork
//
//  Created by WenBi on 13-4-18.
//  Copyright (c) 2013年 Alipay. All rights reserved.
//

#import "DTRpcConfigScope.h"

extern NSString * const kDTRpcErrorCauseError;
extern NSString * const kDTRpcErrorTrafficControl;

@class DTRpcConfig;
@class DTRpcMethod;
@class DTRpcOperation;
@class DTCustomContext;

@protocol DTRpcInterceptor;
@protocol DTRpcOperationDelegate;

/**
 * PRC client。
 */
@interface DTRpcClient : NSObject

@property(nonatomic, strong) id <DTRpcInterceptor> interceptor;
/**
 * 获取PRC client单例。
 */
+ (DTRpcClient *)defaultClient;

/**
 * 根据指定的 \code DTRpcMethod 执行一个 RPC 请求。
 *
 * @param method 一个 \code DTRpcCode 类型的实例，描述了 RPC 请求的相头信息。
 * @param params RPC 请求需要的参数。
 * @param field  添加到request里面的head
 * @param responseBlock 回调方法
 *
 * @return 如果请求成功，返回指定类型的对象，否则返回 nil。
 */
- (id)executeMethod:(DTRpcMethod *)method params:(NSArray *)params requestHeaderField:(NSDictionary*)field responseHeaderFields:(void (^)(NSDictionary* allHeaderFields))responseBlock;

/**
 * 根据指定的 \code DTRpcMethod 执行一个 RPC 请求。
 *
 * @param method 一个 \code DTRpcCode 类型的实例，描述了 RPC 请求的相头信息。
 * @param params RPC 请求需要的参数。
 *
 * @return 如果请求成功，返回指定类型的对象，否则返回 nil。
 */
- (id)executeMethod:(DTRpcMethod *)method params:(NSArray *)params;

/**
 * 根据指定的 \code DTRpcMethod 执行一个 RPC 请求。
 *
 * @param operation \code DTRpcOperation 的对象。
 *
 * @return 如果请求成功，返回指定类型的对象，否则返回 nil。
 */
- (id)executeOperation:(DTRpcOperation *)operation;

/**
 * 根据指定的operationType和params执行一个 RPC 请求。
 *
 * @param operationType 接口名
 * @param params 请求参数，必须是JSONArray
 * @param options 其他配置参数
 *
 * @return 如果请求成功，返回JSON字符串，否则返回 nil。
 */
- (NSString *)executeRpc:(NSString *)operationType params:(NSString *)params options:(NSDictionary *)options;

/**
 * 获取指定作用域中生效的配置信息。如果指定的作用域是临时的作用域，\code configForScope: 总是返回默认的配置对象。
 * 
 * @param scope 要获取 PRC 配置的作用域。
 *
 * @return \code DTRpcConfig 类的一个实例，其中包含 PRC 相关的配置信息。
 */
- (DTRpcConfig *)configForScope:(DTRpcConfigScope)scope;

/**
 * 设置在指定的作用域中生效的配置对象。
 * 
 * @param config 一个 \code DTRpcConfig 类型的对象，其中包含了 RPC 相关的配置信息。
 * @param scope RPC 配置生效的范围，该范围有效的值定义在 \code DTRpcConfigScope 枚举中。
 */
- (void)setConfig:(DTRpcConfig *)config forScope:(DTRpcConfigScope)scope;

/**
 * 取消operation请求。
 *
 * @param thread 当前运行operation的线程。
 */
- (void)cancelAllOperationsInThread:(NSThread *)thread;
/**
 * 取消所有请求操作
 */
- (void)cancelAllOperations;
/**
 * 清除所有CDN的请求配置
 */
- (void)removeAllCDNConfig;
/**
 * 清除所有重发配置
 */
- (void)removeResendConfig;
/**
 * 添加重发标志
 */
-(void)addRetryableOperationType:(NSString*)operationType value:(NSString*)resend;
/**
 * 根据指定的 \code DTRpcMethod 执行一个 RPC 请求。
 *
 * @param method 一个 \code DTRpcCode 类型的实例，描述了 RPC 请求的相头信息。
 * @param params RPC 请求需要的参数。
 * @param field  添加到request里面的head
 * @param context  上下文
 * @param responseBlock 回调方法
 *
 * @return 如果请求成功，返回指定类型的对象，否则返回 nil。
 */
- (id)executeMethod:(DTRpcMethod *)method params:(NSArray *)params requestHeaderField:(NSDictionary*)field customContext:(DTCustomContext*)context responseHeaderFields:(void (^)(NSDictionary* allHeaderFields))responseBlock;
/**
 * 根据指定的 \code DTRpcMethod 执行一个 RPC 请求。
 *
 * @param method 一个 \code DTRpcCode 类型的实例，描述了 RPC 请求的相头信息。
 * @param data 请求参数，NSData
 * @param field  添加到request里面的head
 * @param responseBlock 回调方法
 *
 * @return 如果请求成功，返回指定类型的对象，否则返回 nil。
 */
- (id)executeMethod:(DTRpcMethod *)method data:(NSData *)data requestHeaderField:(NSDictionary*)field responseHeaderFields:(void (^)(NSDictionary* allHeaderFields))responseBlock;
/**
 * 根据指定的 \code DTRpcMethod 执行一个 RPC 请求。
 *
 * @param method 一个 \code DTRpcCode 类型的实例，描述了 RPC 请求的相头信息。
 * @param data 请求参数，NSData
 * @param field  添加到request里面的head
 * @param context  上下文
 * @param responseBlock 回调方法
 *
 * @return 如果请求成功，返回指定类型的对象，否则返回 nil。
 */
- (id)executeMethod:(DTRpcMethod *)method data:(NSData *)data requestHeaderField:(NSDictionary*)field customContext:(DTCustomContext*)context responseHeaderFields:(void (^)(NSDictionary* allHeaderFields))responseBlock;
@end
