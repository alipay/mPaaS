//
//  APDynamicDeploymentRequestCenter.h
//  DynamicDeployment
//
//  Created by majie on 16/7/7.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "APDynamicDeploymentDef.h"

@interface APDynamicDeploymentRequestCenter : NSObject

+ (instancetype)sharedInstance;

//所有策略
@property (atomic, strong) NSMutableArray *policys;

- (void)doRequestForPolicyType:(APDynamicDeploymentPolicyType)type;

@end
