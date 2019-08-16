//
//  NAMApp+private.h
//  NebulaAppManager
//
//  Created by 扶瑶 on 16/3/25.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NAMApp.h"

@interface NAMApp (Private)
@property (nonatomic, assign) NSTimeInterval lastRefreshTime;   // 上次更新时间
@property (nonatomic, assign) BOOL limiting;                    // 异步请求被限流
@property (nonatomic, assign) BOOL strictlimiting;              // 强制请求被限流

/**
 *  是否已过期
 */
- (BOOL)expired;

/**
 *  前置过期时间, 过期意味着本地资源不可用, 触发前置强制更新
 */
- (BOOL)preReqExpired;

- (BOOL)forcePreReqExpired;

/**
 *  更新上次请求时间
 *
 *  @param time    时间
 *  @param limited 是否被限流
 */
- (void)refresh:(NSTimeInterval)time limited:(BOOL)limited strict:(BOOL)strict;

@end
