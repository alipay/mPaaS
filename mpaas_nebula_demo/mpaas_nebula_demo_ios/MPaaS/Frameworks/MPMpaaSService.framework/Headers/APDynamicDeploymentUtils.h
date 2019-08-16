//
//  APDynamicDeploymentUtils.h
//  DynamicDeployment
//
//  Created by majie on 16/6/11.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "APDynamicDeploymentDef.h"
#import "UnionResourcePb.pb.h"


#define APDynamicDeploymentResourcePath(resName, resType) \
[[NSBundle mainBundle] pathForResource:[NSString stringWithFormat:@"DynamicDeployment.bundle/%@", resName] ofType:resType]


@interface APDynamicDeploymentConvertUtils : NSObject

+ (NSError *)errorFromStatus:(APDynamicDeploymentRegisterBusinessStatus)status;
+ (NSString *)bizNameFromBizType:(UnionResourceBizType)bizType;
+ (UnionResourceBizType)bizTypeFromBizName:(NSString *)bizName;
+ (APDynamicDeploymentPolicyType)policyTypeFromString:(NSString *)string;
+ (APDynamicDeploymentNetType)currentNetType;
+ (NSArray *)businessArrayFromRequest:(UnionResourceRequest*)request;

@end
