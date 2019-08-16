//
//  NXKConfigManager.h
//  NebulaKernel
//
//  Created by theone on 2018/9/10.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
@protocol NXKConfigManagerProtocol
@optional
- (BOOL)shouldLoadConfigurationMod:(NSString *)mod;
@end

@interface NXKConfigManager : NSObject
@property(nonatomic, readonly)   NSDictionary *defaultConfig;
@property(nonatomic, weak)       id<NXKConfigManagerProtocol> configurationDelegate;
+ (instancetype)defaultConfigManager;
- (void)loadAllConfiguration;
- (void)registerConfigurationMod:(NSString *)mod;
@end
