//
//  APDynamicDeploymentCenter.h
//  DynamicDeployment
//
//  Created by majie on 16/6/11.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "APDynamicDeploymentDef.h"
#import "UnionResourcePb.pb.h"

@class APDynamicDeploymentBusiness;
@class APDynamicDeploymentConfig;
@class APDynamicDeploymentBaseInteraction;

@interface APDynamicDeploymentCenter : NSObject

/**
 *  对发布中心进行业务注册，
 *
 *  @param business 必填，业务的注册对象
 *  @param error 可填，错误对象
 *  @return 是否注册成功
 */
+ (BOOL)registerBusiness:(APDynamicDeploymentBusiness *)business error:(NSError **)error;

/**
 *  向发布平台同步请求相关业务的资源数据，
 *
 *  @param businessName 必填，业务名称集合
 *  @param userId 可填，当前userid值。
 */
+ (void)requestForBusinessNames:(NSArray *)businessNames userId:(NSString *)userId;

/**
 *  启动监听长链接，
 *
 *  @param void
 *  @return void
 */
+ (void)startListenLongLink;

/**
 *  对策略的请求
 *
 *  @param APDynamicDeploymentPolicyType 策略类型
 *  @return void
 */
+ (void)requestForPolicyType:(APDynamicDeploymentPolicyType)type;

/**
 *  对交互对象相关rpc做请求
 *  @param interaction 交互对象
 *  @return void
 */
+ (void)requestForBusinessInteraction:(APDynamicDeploymentBaseInteraction *)interaction;

/**
 使用交互对象同步请求
 */
+ (BOOL)syncRequestForBusinessInteraction:(APDynamicDeploymentBaseInteraction *)interaction bizType:(UnionResourceBizType)bizType;

@end
