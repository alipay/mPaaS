//
//  PSDPluginConfig.h
//  Poseidon
//
//  Created by chenwenhong on 14-8-11.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

//插件配置类
@interface PSDPluginConfig : NSObject

@property(nonatomic, readonly, copy) NSString   *name; // 插件类名
@property(nonatomic, readonly, copy) NSString   *scope; // 作用域
@property(nonatomic, readonly, strong) NSArray  *events; // 插件要监听的事件名列表，PSDPluginConfigEvent

/**
 *  @brief 创建一个插件配置对象
 *
 *  @date 2014-08-11
 *
 *  @param name       插件类名
 *  @param events     插件要监听的事件列表，PSDPluginConfigEvent
 *  @param useCapture 是否是捕获消息，否则是冒泡消息，默认是NO
 *
 *  @return 返回插件配置对象，以便进行插件的创建等处理
 */
+ (instancetype)pluginCfgWithName:(NSString *)name
                            scope:(NSString *)scope
                           events:(NSArray *)events;

/**
 *  @brief 创建一个插件配置对象
 *
 *  @date 2014-08-11
 *
 *  @param name       插件类名
 *  @param events     插件要监听的事件名列表
 *  @param useCapture 是否是捕获消息，否则是冒泡消息，默认是NO
 *
 *  @return 返回插件配置对象，以便进行插件的创建等处理
 */
+ (instancetype)pluginCfgWithName:(NSString *)name
                            scope:(NSString *)scope
                       eventNames:(NSArray *)eventNames
                       useCapture:(BOOL)useCapture;

@end

//插件配置事件类
@interface PSDPluginConfigEvent : NSObject

@property(nonatomic, readonly, copy) NSString   *event; // 事件名称
@property(nonatomic, readonly, assign) BOOL     useCapture; // 是否捕获

/**
 *  @brief 创建一个插件配置事件对象
 *
 *  @date 2014-08-20
 *
 *  @param event      插件名称
 *  @param useCapture 是否捕获
 *
 *  @return 返回一个插件配置事件对象
 */
+ (instancetype)pluginConfigEvent:(NSString *)event useCapture:(BOOL)useCapture;

@end