//
//  NBRegistery.h
//  NebulaSDK
//
//  Created by 张光宇 on 2019/5/17.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NBConfiguration.h"
NS_ASSUME_NONNULL_BEGIN

@class NBLogConfiguration;
@protocol NBConfigOverwriter<NSObject>

- (void)overwriteNBConfig:(NBConfiguration *_Nonnull)config;

- (void)overwriteNAMConfig:(NAMConfiguration *_Nonnull)config;

- (void)overwriteLogConfig:(NBLogConfiguration *_Nonnull)config;

@end

//! 注册表
@interface NBRegistery : NSObject
@property(nonatomic, strong)   id<NBConfigOverwriter>     configOverwriter;

+ (instancetype)sharedRegistery;

@end

NS_ASSUME_NONNULL_END
