//
//  NBPluginBase.h
//  Nebula
//
//  Created by chenwenhong on 15/9/1.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NBPluginBase : NSObject <PSDPluginProtocol>

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
