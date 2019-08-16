//
//  PSDProxy.h
//  Poseidon
//
//  Created by silentcloud on 8/13/14.
//  Copyright (c) 2014 Alipay. All rights reserved.
//
#import <UIKit/UIKit.h>
#import "PSDResponse.h"

@class PSDKernel;

@interface PSDProxy : PSDKernel

//禁止创建实例
+ (instancetype)alloc UNAVAILABLE_ATTRIBUTE;

- (instancetype)init UNAVAILABLE_ATTRIBUTE;

- (id)copy UNAVAILABLE_ATTRIBUTE;

+ (instancetype)allocWithZone:(struct _NSZone *)zone UNAVAILABLE_ATTRIBUTE;

+ (instancetype)new UNAVAILABLE_ATTRIBUTE;


// 启动仅仅是初始化，如果要启用，需要调用enableProxy
+ (void)startWithCanInterceptWebRequest:(BOOL)canInterceptWebRequest
                     canProcessResponse:(BOOL)canProcessResponse
                             canMonitor:(BOOL)canMonitor
                      canIgnoreSSLError:(BOOL)canIgnoreSSLError;

+ (void)enableProxy;

+ (void)disableProxy;

+ (BOOL)canMonitor;

+ (BOOL)canProcessResponse;

+ (BOOL)canIgnoreSSLError;

+ (void)setUseDiskCache:(BOOL)use;

+ (BOOL)canUseDiskCache;

+ (BOOL)canUseNSURLSession;

+ (void)setCanUseNSURLSession:(BOOL)use;

+ (void)setNSURLSessionExtraProtocolClasses:(NSArray<Class> *)classes;

+ (NSArray<Class> *)nSURLSessionExtraProtocolClasses;

/**
 *  清除WKBody缓存
 */
+ (void)clearWKBodyCache;

/**
 *  给EventTarget对像添加事件监听者
 *
 *  @param eventType     事件类型
 *  @param eventListener 事件监听者：weak引用，不会strong
 *  @param useCapture    是否捕获消息
 */
+ (void)addEventListener:(NSString *)eventType
            withListener:(id<PSDPluginProtocol>)eventListener
              useCapture:(BOOL)useCapture;

/**
 *  给EventTarget对象移除事件监听对象
 *
 *  @param eventType     事件类型
 *  @param eventListener 事件监听者
 *  @param useCapture    是否捕获事件
 */
+ (void)removeEventListener:(NSString *)eventType
               withListener:(id<PSDPluginProtocol>)eventListener
                 useCapture:(BOOL)useCapture;

@end

