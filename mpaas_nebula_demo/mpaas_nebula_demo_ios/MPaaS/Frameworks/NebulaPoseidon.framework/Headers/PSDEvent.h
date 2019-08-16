//
//  PSDEvent.h
//  Poseidon
//
//  Created by chenwenhong on 14/7/21.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PSDEventTargetProtocol.h"
#import "PSDDefine.h"

@class PSDContext;

@interface PSDEvent : NSObject

@property(nonatomic, readonly) BOOL bubbles;                           // 事件是否可以冒泡
@property(nonatomic, readonly) BOOL cancelable;                        // 事件是否可以被取消
@property(nonatomic, assign)   PSDEventPhase eventPhase;               // 事件处理阶段
@property(nonatomic, readonly) NSTimeInterval timeStamp;               // 事件发生的时间戳
@property(nonatomic, readonly, copy) NSString *eventType;                    // 事件类型
@property(nonatomic, strong)   id<PSDEventTargetProtocol> target;         // 事件产生的目标对象
@property(nonatomic, strong)   id<PSDEventTargetProtocol> currentTarget;  // 事件的当前处理对象
@property(nonatomic, strong)   PSDContext *context;                    // 事件的上下文

@property(nonatomic, readonly) BOOL isCancelled;                       // 事件是否已经取消了
@property(nonatomic, readonly) BOOL isStoped;                          // 事件是否已经停止传递
@property(nonatomic, copy)   NSDictionary *psdEventData;                  // 事件的携带数据


/**
 *  @brief 创建一个对象，给定对象的类型、是否冒泡、是否可取消
 *
 *  @date 2014-07-31
 *
 *  @param eventType  事件类型
 *  @param canBubble  是否可以冒泡
 *  @param cancelable 是否可以被取消
 *
 *  @return 返回一个事件
 */
- (instancetype)initWithEventType:(NSString *)eventType canBubble:(BOOL)canBubble cancelable:(BOOL)cancelable;

/**
 *  @brief 停止事件传递
 *
 *  @date 2014-07-31
 *
 *  @return 无
 */
- (void)stopPropagation;

/**
 *  @brief 取消事件传递，如果可取消的话
 *
 *  @date 2014-07-31
 *
 *  @return 无
 */
- (void)preventDefault;

@end
