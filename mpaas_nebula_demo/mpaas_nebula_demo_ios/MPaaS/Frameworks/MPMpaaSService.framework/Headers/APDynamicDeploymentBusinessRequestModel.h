//
//  APDynamicDeploymentBusinessRequestModel.h
//  DynamicDeployment
//
//  Created by majie on 16/6/12.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import "APDynamicDeploymentModel.h"
#import "APDynamicDeploymentBaseInteraction.h"

@interface APDynamicDeploymentBusinessRequestModel : APDynamicDeploymentModel

@property (nonatomic, copy) NSString *name;
@property (nonatomic, strong) APDynamicDeploymentBaseInteraction *interaction;

@end
