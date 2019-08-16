//
//  DFLoadingPageManager.h
//  APMobileFramework
//
//  Created by liangbao.llb on 2017/8/1.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DFLoadingPageHandlerProtocol.h"

#define DFLoadingPageAppId @"20001120"
extern NSString * kLoadingPageAnimationKey;

@class APBaseLoadingView;

@interface DFLoadingPageManager : NSObject

#pragma mark - 外部使用接口

+ (instancetype)sharedInstance;

/**
 * 注册启动中间页处理对象。注意：如果不用后要注销掉。
 *
 * @param handler 启动中间页处理对象。
 */
- (void)registerLoadingPageHandler:(id<DFLoadingPageHandlerProtocol>)handler;

/**
 * 注销启动中间页处理对象。
 *
 * @param handler 启动中间页处理对象。
 */
- (void)unregisterLoadingPageHandler:(id<DFLoadingPageHandlerProtocol>)handler;

/**
 * 显示中间页。
 *
 * @param appId  启动App id。
 * @param params 启动App参数。
 * @param sourceId 启动App的调用者。
 */
- (BOOL)startLoading:(NSString *)appId params:(NSDictionary *)params sourceId:(NSString *)sourceId;

/**
 * 停止显示中间页。
 *
 * @param appId  启动App id。
 */
- (BOOL)stopLoading:(NSString *)appId;

/**
 * 查找启动App关联的中间页。
 *
 * @param appId  启动App id。
 * 
 * @return 成功返回中间页对象，否则返回nil。
 */
- (APBaseLoadingView *)findLoading:(NSString *)appId;

#pragma mark - 内部使用接口，业务请问直接使用
/**
 * 框架自动检查启动App是否需要显示中间页。
 */
- (BOOL)checkStartLoading:(NSString *)appId params:(NSDictionary *)params sourceId:(NSString *)sourceId;

/**
 * 当用户点击页面的“返回”按钮，取消等待App启动。
 */
- (void)cancelStartLoading;

@end
