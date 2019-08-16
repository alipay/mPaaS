//
//  PSDSessionEvent.h
//  Poseidon
//
//  Created by chenwenhong on 14-8-11.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import "PSDEvent.h"

@interface PSDSessionEvent : PSDEvent

/**
 *  @brief 创建一个all事件，可以监听所有Session事件
 *
 *  @date 2014-08-11
 *
 *  @return 返回一个all事件
 */
+ (instancetype)allEvent;

/**
 *  @brief 创建一个create事件：Session创建的事件
 *
 *  @date 2014-08-11
 *
 *  @return 返回一个create事件
 */
+ (instancetype)createEvent;

/**
 *  @brief 创建一个destroy事件：Session销毁的事件
 *
 *  @date 2014-08-11
 *
 *  @return 返回一个destroy事件
 */
+ (instancetype)destroyEvent;

@end
