//
//  APDynamicDeploymentCenterContext.h
//  DynamicDeployment
//
//  Created by majie on 16/6/11.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "APDynamicDeploymentDef.h"
#import "APDynamicDeploymentBusinessRequestModel.h"
#import "UnionResourcePb.pb.h"

@class APDynamicDeploymentBusiness;

@interface APDynamicDeploymentCenterContext : NSObject

+ (instancetype)sharedInstance;

@property (nonatomic, strong) NSMutableDictionary *businessDictionary;

//正在进行rpc的业务请求集合，请求返回从数组中删除
@property (nonatomic, strong) NSMutableArray *businessRequestArray;

- (APDynamicDeploymentRegisterBusinessStatus)registerBusiness:(APDynamicDeploymentBusiness *)business;

- (BOOL)containsBusinessRequestForName:(NSString *)name;
- (void)removeBusinessRequestForName:(NSString *)name;
- (void)clearBusinessRequests;
- (BOOL)addBusinessRequest:(APDynamicDeploymentBusinessRequestModel *)request;
- (void)removeBusinessRequest:(APDynamicDeploymentBusinessRequestModel *)request;
- (NSString *)interactionClassNameForBusinessName:(NSString *)name;
- (APDynamicDeploymentBusinessRequestModel *)requestModelForName:(NSString *)name;
- (BOOL)validBusinessForName:(NSString *)name;
- (NSArray *)registerBusinessNames;
- (void)updateRequestDateForName:(NSString *)name;
- (APDynamicDeploymentBusiness *)businessForName:(NSString *)name;
- (UnionResourceBizType)bizTypeForInteractionClassName:(NSString *)className;

@end
