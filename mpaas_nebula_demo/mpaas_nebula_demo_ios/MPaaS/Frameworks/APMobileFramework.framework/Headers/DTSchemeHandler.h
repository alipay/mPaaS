//
//  DTSchemeHandler.h
//  MobileRuntime
//
//  Created by WenBi on 13-4-16.
//  Copyright (c) 2013年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * \code DFSchemeHandler 类用于处理操作系统对 [UIApplicationDelegate application:openURL:sourceApplication:annotation] 的
 * 调用机制。
 */
@interface DTSchemeHandler : NSObject

/**
 * 试图注册一个 <code>DFSchemeHandler</code> 的子类，使其可以处理打开链接。
 *
 * @param handlerClass 要注册的 <code>DFSchemeHandler</code> 的子类。
 *
 * @return 注册成功返回YES， 否则返回NO。如果出现注册失败的唯一情况就是，指定的类不是 DFURLCommandHandler 的一个子类。
 */
+ (BOOL)registerClass:(Class)handlerClass;

/**
 * 反注册 open URL 的处理类。
 *
 * @param handlerClass open URL 的处理类。
 */
+ (void)unregisterClass:(Class)handlerClass;

/**
 *  检查是否能够处理指定的URL。
 *
 *  @param aURL 指定的URL。
 *
 *  @return 能够处理返回YES，否则返回NO。
 */
+ (BOOL)canHandleOpenURL:(NSURL *)aURL;

/**
 *  处理指定的URL。
 *
 *  @param aURL     指定的URL。
 *  @param userInfo 扩展参数。
 *
 *  @return 处理成功返回YES，否则返回NO。
 */
- (BOOL)handleOpenURL:(NSURL *)aURL userInfo:(NSDictionary *)userInfo;

@end
