//
//  APDynamicDeploymentSyncHandler.h
//  DynamicDeployment
//
//  Created by majie on 16/7/1.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "APDynamicDeploymentSyncUtils.h"

@interface APDynamicDeploymentSyncHandler : NSObject

+ (void)responseLongLinkNotification:(NSDictionary *)notification forBizName:(NSString *)bizName utils:(APDynamicDeploymentSyncUtils *)utils;

- (void)resolveForNotification:(NSNotification *)notification;

@end
