//
//  APDynamicDeploymentModelFactory.h
//  DynamicDeployment
//
//  Created by majie on 16/6/12.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "APDynamicDeploymentBusinessRequestModel.h"

@interface APDynamicDeploymentModelFactory : NSObject

+ (APDynamicDeploymentBusinessRequestModel *)createBusinessRequestModelWithName:(NSString *)businessName
                                                           interactionClassName:(NSString *)interactionClassName;

@end
