//
//  NXKExtensionManager.h
//  NebulaKernel
//
//  Created by theone on 2018/8/23.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NXKExtensionProxy.h"

@class NXKNode;
@protocol NXKExtensionProtocol;
@protocol NXKExtensionPointLifeCycleProtocol;
@protocol NXKExtensionPoint;
@protocol NXKExtensionFilterProtocol;
@protocol NXKExtensionSorterProtocol;


@interface NXKExtensionManager : NSObject
+ (instancetype)defaultExtensionManager;

- (id)createExtensionPoint:(Protocol *)point
                                       node:(NXKNode *)node
                                   delegate:(id<NXKExtensionPointLifeCycleProtocol>)delegate;

- (id)createExtensionPoint:(Protocol *)point
                      node:(NXKNode *)node
                     event:(PSDEvent *)event
                  delegate:(id<NXKExtensionPointLifeCycleProtocol>)delegate;

- (void)setExtensionPointFilter:(Protocol *)point
                         filter:(id<NXKExtensionFilterProtocol>)filter;

- (void)setExtensionPointSorter:(Protocol *)point
                         sorter:(id<NXKExtensionSorterProtocol>)sorter;

+ (NXKExtensionProxyContext *)extension:(Protocol *)extension
                                   node:(NXKNode *)node
                               callback:(id<NXKExtensionPointLifeCycleProtocol>)callback;

@end
