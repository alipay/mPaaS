//
//  PSDContext.h
//  Poseidon
//
//  Created by chenwenhong on 14/7/21.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@class PSDEvent;

//上下文对象
@interface PSDContext : NSObject

@property(nonatomic, readonly, weak) PSDEvent *event;
@property(nonatomic, readonly, strong) NSArray *eventTargetList; // 事件链路

/**
 *  @brief 创建一个上下文对象
 *
 *  @date 2014-08-20
 *
 *  @param eventTargetList 事件链路
 *
 *  @return 返回一个上下文对象
 */
+ (instancetype)contextWithEvent:(PSDEvent *)event eventTargetList:(NSArray *)eventTargetList;

@end
