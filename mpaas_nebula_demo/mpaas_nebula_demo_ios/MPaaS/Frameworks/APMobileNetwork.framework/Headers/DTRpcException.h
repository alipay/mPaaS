//
//  DTRpcException.h
//  APMobileNetwork
//
//  Created by WenBi on 13-4-19.
//  Copyright (c) 2013年 Alipay. All rights reserved.
//

#import "DTRpcErrorCode.h"

/** The name of the RPC exception. */
extern NSString * const kDTRpcException;

/**
 * NSException is used to implement exception handling and contains information about an RPC exception. 
 */
@interface DTRpcException : NSException

@property(nonatomic, assign) DTRpcErrorCode code;
/**
 *  上报异常
 *
 *  @param code    异常码
 *  @param message 异常原因
 */
+ (void)raise:(DTRpcErrorCode)code message:(NSString *)message;
/**
 *  上报异常
 *
 *  @param code    异常码
 *  @param message 异常原因
 *  @param userInfo 异常信息
 */
+ (void)raise:(DTRpcErrorCode)code message:(NSString *)message userInfo:(NSDictionary*)userInfo;
/**
 *  上报异常 不需要错误原因
 *
 *  @param code    异常码
 */
+ (void)raise:(DTRpcErrorCode)code;
/**
 * 如果response是NSHTTPURLResponse返回response的allHeaderFields
 */
-(NSDictionary *)allResponseHeaderFields;
@end
