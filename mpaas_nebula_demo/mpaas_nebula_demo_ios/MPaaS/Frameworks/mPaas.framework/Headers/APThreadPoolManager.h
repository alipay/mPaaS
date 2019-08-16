//
//  APThreadPoolManager.h
//  APMobileFoundation
//
//  Created by wenbi on 14-11-10.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@class APThreadPool;

@interface APThreadPoolManager : NSObject

@property(nonatomic, strong, readonly) APThreadPool *defaultThreadPool;
@property(nonatomic, strong, readonly) APThreadPool *preloadThreadPoolForLogin;
@property(nonatomic, strong, readonly) APThreadPool *networkProcessThreadPool;
@property(nonatomic, strong, readonly) APThreadPool *loginRPCProcessThreadPool;
@property(nonatomic, strong, readonly) APThreadPool *coreProcessThreadPool;
@property(nonatomic, strong, readonly) APThreadPool *homeShowThreadPool;


+ (APThreadPoolManager *)sharedThreadPoolManager;

@end
