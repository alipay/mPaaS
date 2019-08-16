//
//  EventTargetProtocol.h
//  Poseidon
//
//  Created by chenwenhong on 14/7/24.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PSDPluginProtocol.h"

@class PSDEvent;

//事件目标对象协议
@protocol PSDEventTargetProtocol <NSObject>

/**
 *  给EventTarget对像添加事件监听者
 *
 *  @param eventType     事件类型
 *  @param eventListener 事件监听者：weak引用，不会strong
 *  @param useCapture    是否捕获消息
 */
- (void)addEventListener:(NSString *)eventType withListener:(id<PSDPluginProtocol>)eventListener useCapture:(BOOL)useCapture;

/**
 *  给EventTarget对象移除事件监听对象
 *
 *  @param eventType     事件类型
 *  @param eventListener 事件监听者
 *  @param useCapture    是否捕获事件
 */
- (void)removeEventListener:(NSString *)eventType withListener:(id<PSDPluginProtocol>)eventListener useCapture:(BOOL)useCapture;

@end
