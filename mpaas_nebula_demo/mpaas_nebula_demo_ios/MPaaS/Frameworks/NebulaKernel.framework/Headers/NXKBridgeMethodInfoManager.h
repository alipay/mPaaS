//
//  NXKBridgeMethodInfoManager.h
//  NebulaKernel
//
//  Created by theone on 2018/9/27.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class NXKBridgeMethodInfo;

@interface NXKBridgeMethodInfoManager : NSObject
+ (instancetype)defaultMethodInfoManager;
- (void)addMethodInfo:(NXKBridgeMethodInfo *)info;
- (NXKBridgeMethodInfo *)findBridgeMethodInfoWithJsapiName:(NSString *)jsapiName;
@end

NS_ASSUME_NONNULL_END
