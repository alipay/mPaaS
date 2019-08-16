//
//  DTSchemeService
//  MobileRuntime
//
//  Created by WenBi on 13-4-16.
//  Copyright (c) 2013年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DTService.h"

extern NSString * const DTSchemeIsLaunchingUserInfoKey;
extern NSString * const DTSchemeIsUserClickPushKey; // 定义iOS10及以上系统用户点击Push启动App
extern NSString * const DTSchemeLogMonitorKey;      // 定义scheme key: dtLogMonitor
extern NSString * const DTSchemeLogMonitorTimeKey;  // 定义scheme key: dtLogMonitorTime

/**
 * 处理 URL 调用的服务。
 */
@protocol DTSchemeService <DTService>

/**
 * 获取 scheme service 最后一次处理过的 URL.
 * 
 * @return 最后一次处理过的URL。
 */
- (NSURL *)lastURL;

/**
 * 注册一个处理类，这个类会追加到处理类链表的末尾。
 *
 * @param handlerClass 一个 URL 处理类，这个类必须是 \code DFSchemeHandler 的了类。
 *
 * @return 如果注册成功，返回YES，否则返回NO。
 */
- (BOOL)registerHandlerClass:(Class)handlerClass;

/**
 * 在处理类链表中的指定位置处，注册一个处理类。
 *
 * @param handlerClass 一个 URL 处理类，这个类必须是 \code DFSchemeHandler 的了类。
 * @param index 在指定的位置注册处理类。
 *
 * @return 如果注册成功，返回YES，否则返回NO。
 */
- (BOOL)registerHandlerClass:(Class)handlerClass atIndex:(NSInteger)index;

/**
 * 反注册指定的处理类。
 *
 * @param handlerClass 要反注册的处理类。
 */
- (void)unregisterHandlerClass:(Class)handlerClass;

/**
 * 返回指定处理类在处理类链表中所处的位置。
 *
 * @param handlerClass
 *
 * @return 指定处理类在链表中的位置。
 */
- (NSInteger)indexOfClass:(Class)handlerClass;

/**
 * 通知处理类处理 URL 调用请求。
 * 
 * @param aURL \code NSURL 对象，表示需要处理的URL。
 *
 * @return 如果处理成功，返回YES，否则返回NO。
 */
- (BOOL)handleURL:(NSURL *)aURL userInfo:(NSDictionary *)userInfo;

/**
 * 判断一个URL的scheme是不是应用定义的可以处理的scheme
 *
 *  @param aURL the NSURL
 *
 *  @return 返回是否是应用定义的scheme
 */
- (BOOL)isApplicationSchemeWithURL:(NSURL *)aURL;

@optional

/**
 * 注册一个Associated Domains处理类，这个类会追加到处理类链表的末尾。
 *
 * @param handlerClass 一个 URL 处理类，这个类必须是 \code DFSchemeHandler 的了类。
 *
 * @return 如果注册成功，返回YES，否则返回NO。
 */
- (BOOL)registerDomainHandlerClass:(Class)handlerClass;

/**
 * 在处理类链表中的指定位置处，注册一个处理类。
 *
 * @param handlerClass 一个 URL 处理类，这个类必须是 \code DFSchemeHandler 的了类。
 * @param index 在指定的位置注册处理类。
 *
 * @return 如果注册成功，返回YES，否则返回NO。
 */
- (BOOL)registerDomainHandlerClass:(Class)handlerClass atIndex:(NSInteger)index;

/**
 * 反注册指定的Associated Domains处理类。
 *
 * @param handlerClass 要反注册的处理类。
 */
- (void)unregisterDomainHandlerClass:(Class)handlerClass;

/**
 * 查询是否可以处理指定的URL请求。
 *
 * @param aURL \code NSURL 对象，表示需要处理的URL。
 *
 * @return 能否处理，返回YES，否则返回NO。
 */
- (BOOL)canHandleURL:(NSURL *)aURL;

/**
 *  根据指定的key获取启动钱包的scheme中对应的值。
 *
 *  @param key 指定的key
 *
 *  @return 成功返回对应的值，否则返回nil。
 */
- (id)getSchemeValueForKey:(NSString *)key;

/**
 *  保存启动钱包scheme对应key的值。
 *
 *  @param value 要保存的值
 *  @param key   指定的key
 *
 *  @return 成功返回YES，否则返回NO。
 */
- (BOOL)setSchemeValue:(id)value forKey:(NSString *)key;

/**
 * 获取UniversalLink跳转时的SceneParams
 * @param url universal link对应的url
 * @param userInfo 扩展参数
 * @return 跳转App时应该附加的场景参数
 */
- (NSDictionary *)domainSceneParamsInURL:(NSURL *)url
                                userInfo:(NSDictionary *)userInfo;

@end

typedef id<DTSchemeService> IDFSchemeService;

