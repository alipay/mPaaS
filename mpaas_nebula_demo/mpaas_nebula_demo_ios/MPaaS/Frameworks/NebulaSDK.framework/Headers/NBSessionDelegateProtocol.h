//
//  NBSessionDelegate.h
//  NBService
//
//  Created by chenwenhong on 15/8/26.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@class NBSession;

@protocol NBSessionDelegateProtocol <NSObject>

@required

/**
 * 请求应用对象的代理返回根视图控制器。
 *
 * @param session 应用对象。
 *
 * @return 应用的根视图控制器。
 */
- (UIViewController *)rootViewControllerInSession:(NBSession *)session;

@optional

/**
 * 通知应用代理，应用对象已经对经被实例化。
 *
 * @param session 应用对象。
 */
- (void)sessionDidCreate:(NBSession *)session;

/**
 * 通知应用代理，应用将要启动。
 *
 * @param session 启动的应用对象。
 * @param options 应用运行参数。
 */
- (void)session:(NBSession *)session willStartLaunchingWithOptions:(NSDictionary *)options;

/**
 * 通知应用代理，应用已启动。
 *
 * @param session 启动的应用对象。
 */
- (void)sessionDidFinishLaunching:(NBSession *)session;

/**
 * 通知应用代理，应用即将暂停进入后台运行。
 *
 * @param session 启动的应用对象。
 */
- (void)sessionWillPause:(NBSession *)session;

/**
 * 通知应用代理，应用暂停进入后台运行。
 *
 * @param session 启动的应用对象。
 */
- (void)sessionDidPause:(NBSession *)session;

/**
 * 通知应用代理，应用将被重新激活。
 *
 * @param session 要激活的应用对象。
 */
- (void)session:(NBSession *)session willResumeWithOptions:(NSDictionary *)options;

/**
 * 通知应用代理，应用已经被激活。
 *
 * @param session 要激活的应用对，带上参数的版本。
 */
- (void)session:(NBSession *)session didResumeWithOptions:(NSDictionary *)options;

/**
 * 通知应用的代理，应用将要退出。
 *
 * @param session 应用对象。
 * @param animated 是否以动画方式退出。
 */
- (void)sessionWillTerminate:(NBSession *)session animated:(BOOL)animated;

/**
 * 询问应用的代理，应用是否可以启动。
 * 注意：只用特殊情况返回：NO，要保证默认是YES才可以启动的。
 *
 * @param session 应用对象。
 * @param params      启动参数。
 * @param launchMode  启动方式。
 *
 * @return 是否可以启动
 */
- (BOOL)sessionShouldStart:(NBSession *)session params:(NSDictionary *)params;

/**
 * 询问应用的代理，应用是否可以退出。
 * 注意：只用特殊情况返回：NO，要保证默认是YES才可以退出的。
 *
 * @param session 应用对象。
 *
 * @return 是否可以退出
 */
- (BOOL)sessionShouldTerminate:(NBSession *)session;

@end
