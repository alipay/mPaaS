//
//  NXKPluginBase.h
//  NebulaKernel
//
//  Created by theone on 2018/9/9.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
@protocol PSDPluginProtocol;

@interface NXKPluginBase : NSObject <PSDPluginProtocol>
@property(nonatomic, readonly, weak) PSDKernel  *target;
@property(nonatomic, copy) NSString             *scope;

- (void)pluginDidLoad; // will call `addPlugins` and `addJSApis`. If this method is overridden then the super implementation must be called.

- (void)addJSApis; // add your JSApis. If this method is overridden then the super implementation must be called.

- (void)addPlugins; // add your Plugins. If this method is overridden then the super implementation must be called.

- (PSDPluginConfig *)pluginConfigWithName:(NSString *)name
                                    scope:(NSString *)scope
                               eventNames:(NSArray *)eventNames
                               useCapture:(BOOL)useCapture;

- (void)registerJsApi2Target:(PSDJsApi *)jsApi;

- (void)registerPlugin2Target:(PSDPluginConfig *)pluginCfg;

- (BOOL)dispatchEvent:(PSDEvent *)event;

- (void)addDelayJSApiCallWithName:(NSString *)name data:(NSDictionary *)data;
@end
