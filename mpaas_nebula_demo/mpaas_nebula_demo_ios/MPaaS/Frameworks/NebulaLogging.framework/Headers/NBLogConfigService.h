//
//  NBLogConfigServiceDelegate.h
//  NebulaLogging
//
//  Created by Glance on 2017/8/5.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "NBLogConfigServiceDelegate.h"

@interface NBLogConfigService : NSObject <NBLogConfigServiceDelegate>

+ (BOOL)useAsyncLogThread;
+ (BOOL)isCurrentWifi;
+ (int)reportAbnormalResourceSize;
+ (int)reportAbnormalResourceSizeWarn;
+ (int)reportAbnormalPageRenderLimitSec;
+ (int)reportAbnormalPageRenderWifiLimitSec;
+ (BOOL)logNebulaTechEnable;
+ (NSArray *)logWebAppWhitelist;
+ (NSArray *)jsapiResultErrorLogBlackList;
+ (NSDictionary *)logNewBlankScreenConfig;
+ (NSString *)jsUrl4SPMLog;
+ (float)stopLoadingWaitingTime;
+ (NSArray *)performceApiLogBlackList;
+ (BOOL)shouldCollectUnfinishedUrl;
+ (NSString *)logGroup;

@end
