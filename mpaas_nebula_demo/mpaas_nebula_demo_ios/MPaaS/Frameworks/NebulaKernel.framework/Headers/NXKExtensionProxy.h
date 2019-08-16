//
//  NXKExtensionProxy.h
//  NebulaKernel
//
//  Created by theone on 2018/8/24.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NXKNode.h"

@protocol NXKExtensionPointLifeCycleProtocol;
@class NXKExtensionProxyContext;

@interface NXKExtensionProxy<ProtocolType> : NSProxy
@property(nonatomic, readonly)  NXKExtensionProxyContext *context;
- (instancetype)initWithContext:(NXKExtensionProxyContext *)context;

- (ProtocolType)proxyWithExtension:(Protocol *)extension
                              node:(NXKNode *)node
                          callback:(id<NXKExtensionPointLifeCycleProtocol>)callback;

- (ProtocolType)proxyWithExtension:(Protocol *)extension
                              node:(NXKNode *)node
                             event:(PSDEvent *)event
                          callback:(id<NXKExtensionPointLifeCycleProtocol>)callback;
@end
