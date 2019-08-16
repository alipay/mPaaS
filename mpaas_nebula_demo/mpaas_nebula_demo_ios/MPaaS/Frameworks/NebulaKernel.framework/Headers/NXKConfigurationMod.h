//
//  NXKExtensionConfig.h
//  NebulaKernel
//
//  Created by theone on 2019/1/18.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol NXKConfigurationModProtocol <NSObject>
@optional
- (void)registerJsapis;
- (void)registerPlugins;
- (void)registerComponents;
- (void)registerExtensions;
@end

@interface NXKConfigurationMod : NSObject <NXKConfigurationModProtocol>
- (void)registerJsapiWithConfig:(NSDictionary *)dic;
- (void)registerPluginWithConfig:(NSDictionary *)dic;
- (void)registerComponentWithConfig:(NSDictionary *)dic;
- (void)registerExtensionWithConfig:(NSDictionary *)dic;
@end

NS_ASSUME_NONNULL_END
