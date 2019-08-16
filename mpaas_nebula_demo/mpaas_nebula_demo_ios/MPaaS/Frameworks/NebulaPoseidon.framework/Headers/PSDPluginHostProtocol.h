//
//  PluginHostProtocol.h
//  Poseidon
//
//  Created by chenwenhong on 14/7/21.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

//插件管理协议
@protocol PSDPluginHostProtocol <NSObject>

- (void)addPlugin:(id<PSDPluginHostProtocol>)plugin;

- (void)removePlugin:(id<PSDPluginProtocol>)plugin;

@end
