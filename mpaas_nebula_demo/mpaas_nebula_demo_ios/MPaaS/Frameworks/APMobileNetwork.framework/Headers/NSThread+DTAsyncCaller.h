//
//  NSThread+DTAsyncCaller.h
//  APMobileNetwork
//
//  Created by WenBi on 13-5-13.
//  Copyright (c) 2013年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@class DTRpcAsyncCaller;

@interface NSThread (DTRpcAsyncCaller)

- (void)setAsyncCaller:(DTRpcAsyncCaller *)caller;
- (DTRpcAsyncCaller *)asyncCaller;

@end
