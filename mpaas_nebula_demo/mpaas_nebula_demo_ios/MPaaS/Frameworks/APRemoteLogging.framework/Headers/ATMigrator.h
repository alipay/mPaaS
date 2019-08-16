//
//  ATMigrator.h
//  APRemoteLogging
//
//  Created by 卡迩 on 2018/6/14.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ATContext.h"
#import "ATConfigMgr.h"
#import "ATBehaviorLogger.h"

@interface ATMigrator : NSObject
#ifdef SDK_IS4_ALIPAY
<AntLogInterface>
#endif

+ (ATMigrator *)sharedInstance;

#ifdef SDK_IS4_ALIPAY

@property (nonatomic, strong) id<AntLogInterceptor> interceptor;
@property (nonatomic, strong) id<AutoTrackerObserver> observer;
@property (nonatomic, strong) id<ABTestInfoProvider> provider;
#endif

- (void)setupPeriodExecutionTimer;

- (void)addPeriodicallyExecutedBlock:(void (^)(void))block;

@end

