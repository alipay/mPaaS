//
//  APDynamicDeploymentPolicy.h
//  DynamicDeployment
//
//  Created by majie on 16/7/7.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "APDynamicDeploymentDef.h"
#import "APDynamicDeploymentModel.h"

@interface APDynamicDeploymentPolicy : APDynamicDeploymentModel

//业务名字（cmd，hotpatch）
@property (nonatomic, strong) NSString *name;

//类型（启动，登录，后台切前台）
@property (nonatomic, assign) APDynamicDeploymentPolicyType type;

//延后时间
@property (nonatomic, assign) int64_t delta;


@end


@interface APDynamicDeploymentPolicyFactory : NSObject

+ (NSMutableArray *)policysFromString:(NSString *)string;
+ (NSMutableArray *)policysFromDictionary:(NSDictionary *)dict;

@end