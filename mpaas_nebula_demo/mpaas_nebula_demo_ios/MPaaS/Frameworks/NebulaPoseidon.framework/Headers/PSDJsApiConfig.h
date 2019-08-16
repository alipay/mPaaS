//
//  PSDJsApiConfig.h
//  Poseidon
//
//  Created by chenwenhong on 14-8-20.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PSDJsApi.h"

//JsApi配置类
@interface PSDJsApiConfig : NSObject

@property(nonatomic, readonly, copy) NSString               *name; // JsApi实现类名
@property(nonatomic, readonly, copy) NSString               *alias;
@property(nonatomic, readonly, copy) NSString               *jsApi; // JsApi名称
@property(nonatomic, readonly, strong) PSDJsApiHandlerBlock handler; // JsApi处理函数
@property(nonatomic, readonly, copy) NSString               *scope; // 作用域， default is service
@property(nonatomic, readonly, assign) BOOL                 checkParams; // 检查参数（是否字典类型）
@property(nonatomic, readonly, assign) BOOL                 isPrivateAPI; // 私有api（决定是否能被反注册、覆盖）

/**
 *  @brief 插件一个JsApi配置对象
 *
 *  @date 2014-08-20
 *
 *  @param name  JsApi实现类名
 *  @param jsApi JsApi名称
 *
 *  @return 返回JsApi配置对象
 */
+ (instancetype)jsApiCfg:(NSString *)className
                   jsApi:(NSString *)jsApi;

/**
 *  @brief 插件一个JsApi配置对象
 *
 *  @date 2014-08-20
 *
 *  @param handler  JsApi处理函数block
 *  @param jsApi    JsApi名称
 *
 *  @return 返回JsApi配置对象
 */
+ (instancetype)jsApiCfgWithHandlerBlock:(PSDJsApiHandlerBlock)handler
                                   jsApi:(NSString *)jsApi;

/**
 *  @brief 插件一个JsApi配置对象
 *
 *  @date 2014-08-20
 *
 *  @param handler      JsApi处理函数block
 *  @param jsApi        JsApi名称
 *  @param checkParams  是否检查参数
 *  @param isPrivateAPI 是否私有api
 *  @param scope        作用域
 *
 *  @return 返回JsApi配置对象
 */
+ (instancetype)jsApiCfgWithHandlerBlock:(PSDJsApiHandlerBlock)handler
                                   jsApi:(NSString *)jsApi
                             checkParams:(BOOL)checkParams
                            isPrivateAPI:(BOOL)isPrivateAPI
                                   scope:(NSString *)scope;

/**
 *  @brief 插件一个JsApi配置对象
 *
 *  @date 2014-08-20
 *
 *  @param name  JsApi实现类名
 *  @param jsApi JsApi名称
 *  @param alias JsApi的别名
 *  @param checkParams 是否检查参数
 *  @param isPrivateAPI 是否私有api
 *  @param scope 作用域
 *
 *  @return 返回JsApi配置对象
 */
+ (instancetype)jsApiCfg:(NSString *)name
                   jsApi:(NSString *)jsApi
                   alias:(NSString *)alias
             checkParams:(BOOL)checkParams
            isPrivateAPI:(BOOL)isPrivateAPI
                   scope:(NSString *)scope;

@end
