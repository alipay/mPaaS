//
//  PSDApplicationEvent.h
//  Poseidon
//
//  Created by chenwenhong on 14-8-11.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import "PSDEvent.h"

@interface PSDApplicationEvent : PSDEvent

/**
 *  @brief 创建一个all事件，可以监听所有的application事件
 *
 *  @date 2014-08-11
 *
 *  @return 返回一个all事件
 */
+ (instancetype)allEvent;

/**
 *  @brief 创建一个start事件
 *
 *  @date 2014-08-11
 *
 *  @return 返回一个start事件
 */
+ (instancetype)startEvent;

/**
 *  @brief 创建一个pause事件
 *
 *  @date 2014-08-11
 *
 *  @return 返回一个pause事件
 */
+ (instancetype)pauseEvent;

/**
 *  @brief 创建一个resume事件
 *
 *  @date 2014-08-11
 *
 *  @return 返回一个resume事件
 */
+ (instancetype)resumeEvent;

/**
 *  @brief 创建一个exit事件
 *
 *  @date 2014-08-11
 *
 *  @return 返回一个exit事件
 */
+ (instancetype)exitEvent;

@end
