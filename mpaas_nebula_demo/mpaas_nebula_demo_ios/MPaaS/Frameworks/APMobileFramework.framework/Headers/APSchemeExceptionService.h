//
//  APSchemeExceptionService.h
//  APMobileFramework
//
//  Created by liangbao.llb on 16/4/12.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DTService.h"

@interface APSchemeExceptionService : NSObject <DTService>

/**
 *  处理Scheme启动异常。
 *
 *  @param params 参数。
 *
 *  @return YES 处理成功，否则处理失败。
 */
- (BOOL)handleSchemeException:(NSDictionary *)params;

/**
 * 注册一个处理类，这个类会追加到处理类链表的末尾。
 *
 * @param handlerClass 一个 URL 处理类，这个类必须是 \code APStartAppSchemeExceptionHandler 的了类。
 *
 * @return 如果注册成功，返回YES，否则返回NO。
 */
- (BOOL)registerHandlerClass:(Class)handlerClass;

/**
 * 在处理类链表中的指定位置处，注册一个处理类。
 *
 * @param handlerClass 一个 URL 处理类，这个类必须是 \code APStartAppSchemeExceptionHandler 的了类。
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

#pragma mark - 注意：以下内部接口外部不要直接使用
/**
 * 处理启动App失败。注意：内部接口外部不要直接使用
 *
 * @param name      AppId。
 * @param params    启动App参数。
 * @param sourceId  启动App来源。
 */
- (void)handleStartAppException:(NSString *)name params:(NSDictionary *)params sourceId:(NSString *)sourceId;

/**
 * 显示启动App失败提示页面。注意：内部接口外部不要直接使用
 * 页面显示：应用版本小于App store版本会提示升级，否则提示稍后再试。
 *
 * @param params 启动App参数。
 */
- (void)showStartAppExceptionView:(NSDictionary *)params;

@end
