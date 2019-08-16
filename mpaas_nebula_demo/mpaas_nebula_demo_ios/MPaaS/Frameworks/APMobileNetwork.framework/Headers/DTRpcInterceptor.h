//
//  DTRpcInterceptor.h
//  APMobileNetwork
//
//  Created by WenBi on 13-4-5.
//  Copyright (c) 2013年 Alipay. All rights reserved.
//

@class DTRpcOperation;

/**
 * 对 RPC 请求的拦截器。所有的 RPC 请求，在发送到服务端之前或从服务端接收到回应之后，
 * 都会经过拦截器，拦截器可以做相应的处理。
 */
@protocol DTRpcInterceptor <NSObject>

@optional

/**
 * RPC 请求的前置拦截器。在 RPC 请求开始之前，会调用该方法。
 *
 * @param operation 当前的 PRC 请求。
 */
- (DTRpcOperation *)beforeRpcOperation:(DTRpcOperation *)operation;

/**
 * RPC 请求后置拦截器。在 PRC 请求结束之后，会调用该方法。
 *
 * @param operation 当前的 RPC 请求。
 */
- (DTRpcOperation *)afterRpcOperation:(DTRpcOperation *)operation;
/**
 *  处理异常
 */
- (void)handleException:(NSException *)exception;
/**
 *  异常是否需要往后抛!!!    慎用!!!
 *  @return 返回值YES/NO  YES代表该exception 需要继续往后抛 NO代表不抛
 */
- (BOOL)needRaiseException:(NSException *)exception;

@end
