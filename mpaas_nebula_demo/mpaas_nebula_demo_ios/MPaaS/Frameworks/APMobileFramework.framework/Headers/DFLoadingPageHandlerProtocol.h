//
//  DFLoadingPageHandlerProtocol.h
//  APMobileFramework
//
//  Created by liangbao.llb on 2017/8/1.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol DFLoadingPageHandlerProtocol <NSObject>

/**
 *  是否显示中间页。注意：同步返回，避免阻塞查询后再返回。
 *
 * @param appId  启动App id。
 * @param params 启动App参数。
 * @param sourceId 启动App的调用者。
 *
 *  @return 返回YES时，框架会自动显示中间页，否则不会。
 */
- (BOOL)isShowLoadingPage:(NSString *)appId params:(NSDictionary *)params sourceId:(NSString *)sourceId;


@optional

/**
 *  自定义中间页样式。
 *  注意：不保证是在主线程被调用的。
 *
 * @param appId  启动App id。
 * @param params 启动App参数。
 * @param sourceId 启动App的调用者。
 *
 *  @return 返回nil，框架会显示默认中间页样式，否则显示自定义样式。
 */
- (APBaseLoadingView *)createLoadingView:(NSString *)appId params:(NSDictionary *)params sourceId:(NSString *)sourceId;

/**
 中间页尾部Slogan

 @param appId 启动App id
 @param params 启动App参数
 @param sourceId 启动App的调用者
 @return slogan内容，返回nil或空字符串时不显示尾部slogan
 */
- (NSString *)loadingSloganForAppId:(NSString *)appId params:(NSDictionary *)params sourceId:(NSString *)sourceId;

/**
 中间页出现动画模式

 @param appId 启动App id
 @param params 启动App参数
 @param sourceId 启动App的调用者
 @return 中间页出现模式
 */
- (DTMicroApplicationLaunchMode)launchModeForAppId:(NSString *)appId
                                            params:(NSDictionary *)params
                                          sourceId:(NSString *)sourceId;

/**
 *  中间页显示回调。
 *
 * @param appId  启动App id。
 * @param params 启动App参数。
 * @param sourceId 启动App的调用者。
 *
 */
- (void)onStartLoadingPage:(NSString *)appId params:(NSDictionary *)params sourceId:(NSString *)sourceId;

/**
 中间页ViewController viewDidLoad回调

 @param viewController 中间页ViewController
 @param appId 启动App id。
 @param params 启动App参数。
 @param sourceId 启动App的调用者。
 */
- (void)onLoadingPageControllerDidLoad:(DTViewController *)viewController
                                 appId:(NSString *)appId
                                params:(NSDictionary *)params
                              sourceId:(NSString *)sourceId;

/**
 *  中间页消失回调。
 *
 * @param appId  启动App id。
 * @param params 启动App参数。
 * @param sourceId 启动 app 的调用者。
 *
 */
- (void)onStopLoadingPage:(NSString *)appId params:(NSDictionary *)params sourceId:(NSString *)sourceId;

/**
 *  中间页取消回调。（用户点击“返回”按钮）
 *
 * @param appId  启动App id。
 * @param params 启动App参数。
 * @param sourceId 启动 app 的调用者。
 *
 */
- (void)onCancelLoadingPage:(NSString *)appId params:(NSDictionary *)params sourceId:(NSString *)sourceId;

@end
