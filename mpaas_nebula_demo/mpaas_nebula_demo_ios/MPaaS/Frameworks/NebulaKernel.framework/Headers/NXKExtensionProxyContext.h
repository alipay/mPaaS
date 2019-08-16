//
//  NXKExtensionProxyContext.h
//  NebulaKernel
//
//  Created by theone on 2018/8/24.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol NXKExtensionPointLifeCycleProtocol;
@class NXKNode;
@class PSDEvent;

@interface NXKExtensionProxyContext : NSObject
@property(nonatomic, strong)  NSArray *targetList;
@property(nonatomic) Protocol *point;
@property(nonatomic) id<NXKExtensionPointLifeCycleProtocol>  delegate;
//for dataStorage
@property(nonatomic, weak)    NXKNode   *node;
@property(nonatomic, weak)    PSDEvent  *event;
@end
