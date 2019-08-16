//
//  PSDJsBridge.h
//  Poseidon
//
//  Created by chenwenhong on 14-8-13.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "PSDJsApi.h"

@class PSDPage;
@class PSDContentView;
@class PSDPageParam;

//JsBridge类，用来处理Native和Js的相互调用
@interface PSDJsBridge : NSObject<UIWebViewDelegate>

/**
 *  @brief 创建一个JsBridge对象
 *
 *  @date 2014-08-20
 *
 *  @param page     关联的PSDPage对象
 *  @param webView  关联的contentView对象
 *  @param delegate contentView的代理
 *
 *  @return 返回一个JsBridge对象
 */
+ (instancetype)bridge4Page:(PSDPage *)page contentView:(PSDContentView *)contentView webViewDelegate:(id<UIWebViewDelegate>)delegate;


/**
 *  @brief 创建一个JsBridge对象
 *
 *  @date 2014-08-20
 *
 *  @param page     关联的PSDPage对象
 *  @param webView  关联的contentView对象
 *  @param delegate contentView的代理
 *
 *  @return 返回一个JsBridge对象
 */
+ (instancetype)bridge4Page:(PSDPage *)page contentView:(PSDContentView *)contentView pageParam:(PSDPageParam *)pageParam;


/**
 *  @brief 日志打印开关
 *
 *  @date 2014-08-20
 *
 *  @return 无
 */
+ (void)enableLogging;

/**
 *  @brief 返回bridge是否准备好（已经注入基本的bridge）
 *
 *  @date 2014-11-21
 *
 *  @return 返回是否准备好
 */
- (BOOL)isBridgeReady;

/**
 *  @brief Native调用Js
 *
 *  @date 2014-08-20
 *
 *  @param message 传递的消息参数
 *
 *  @return 无
 */
- (void)send:(NSDictionary *)message;

/**
 *  @brief Native调用Js
 *
 *  @date 2014-08-20
 *
 *  @param message          传递的消息参数
 *  @param responseCallback 回调
 *
 *  @return 无
 */
- (void)send:(NSDictionary *)message responseCallback:(PSDJsApiResponseCallbackBlock)responseCallback;

/**
 *  @brief Native调用Js
 *
 *  @date 2014-08-20
 *
 *  @param handlerName js函数
 *
 *  @return 无
 */
- (void)callHandler:(NSString *)handlerName;

/**
 *  @brief Native调用Js
 *
 *  @date 2014-08-20
 *
 *  @param handlerName js函数
 *  @param data        传递的消息参数
 *
 *  @return 无
 */
- (void)callHandler:(NSString *)handlerName data:(NSDictionary *)data;

/**
 *  @brief Native调用Js
 *
 *  @date 2014-08-20
 *
 *  @param handlerName      js函数
 *  @param data             传递的消息参数
 *  @param responseCallback 回调
 *
 *  @return 无
 */
- (void)callHandler:(NSString *)handlerName data:(NSDictionary *)data responseCallback:(PSDJsApiResponseCallbackBlock)responseCallback;

- (void)callJsApi:(NSString *)jsApiName
              url:(NSString *)url
             data:(NSDictionary *)data
 responseCallback:(PSDJsApiResponseCallbackBlock)responseCallback;

/**
 *  @brief 向html插入本地js文件
 *
 *  @date 2014-08-20
 *
 *  @param webView 关联的webView对象
 *
 *  @return 无
 */
- (void)loadJSBridgeFileWithDynamicInjectJsCodeSnippets:(NSString *)dynamicInjectJsCodeSnippets;

/**
 *  @brief 注入js
 *
 *  @date 2014-11-21
 *
 *  @param js js片段
 *
 *  @return 无
 */
- (void)loadJS:(NSString *)js;

/**
 *  @brief 重置JsBridge状态
 *
 *  @date 2014-08-20
 *
 *  @return 无
 */
- (void)reset;


/**
 转化ResponseData，支持ArrayBuffer

 @param NSDictionary 原始数值
 @return 转化后的数据
 */
- (NSDictionary *)transformResponseData:(id)responseData;

@end
