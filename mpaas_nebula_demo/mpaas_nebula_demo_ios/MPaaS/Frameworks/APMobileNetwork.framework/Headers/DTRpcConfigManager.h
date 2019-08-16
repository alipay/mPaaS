//
//  DTRpcConfigManager.h
//  APMobileNetwork
//
//  Created by WenBi on 13-4-19.
//  Copyright (c) 2013年 Alipay. All rights reserved.
//

#import "DTRpcConfigScope.h"

#define RPCRetryableMapKey             @"RPCRetryableMapKey"
#define RPCRetryableMapValue           @"1"
#define RPCNotRetryableMapValue        @"0"

@class DTRpcConfig;

@interface DTRpcConfigManager : NSObject

- (DTRpcConfig *)configForScope:(DTRpcConfigScope)scope;
- (void)setConfig:(DTRpcConfig *)config forScope:(DTRpcConfigScope)scope;
- (DTRpcConfig *)preferredConfig:(NSString *)operationType;
- (void)removeCDNConfig;
- (void)removeResendConfig;

/**
 *  根据operationType获取重发列表的值
 */
-(NSString*)retryableValueOfOperationType:(NSString*)operationType;
/**
 *  添加operationType到重发列表
 */
-(void)addRetryableOperationType:(NSString*)operationType value:(NSString*)resend;
/**
 *  持久化重发标志
 */
-(void)saveRetryable;
@end
