//
//  APDynamicDeploymentConfig.h
//  DynamicDeployment
//
//  Created by majie on 16/7/6.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface APDynamicDeploymentConfig : NSObject

@property (nonatomic,strong) NSString* productId;
@property (nonatomic,strong) NSString* productVersion;
@property (nonatomic,strong) NSString* releaseVersion;
@property (nonatomic,strong) NSString* utdid;
@property (nonatomic,strong) NSString* clientId;
@property (nonatomic,strong) NSString* phoneBrand;
@property (nonatomic,strong) NSString* phoneModel;
@property (nonatomic,strong) NSString* osVersion;
@property (nonatomic,strong) NSString* userId;

+ (instancetype)sharedInstance;

/**
 用于从开关中获取值
 */
- (NSString *)stringValueForKey:(NSString *)key;

@end
