//
//  PSDService.h
//  Poseidon
//
//  Created by chenwenhong on 14/7/25.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import "PSDKernel.h"

@class PSDSessionParam;
@class PSDSession;
@class PSDSceneParam;
@class PSDScene;
@class PSDViewParam;
@class PSDView;
@class PSDJsApiConfig;
@class PSDPluginConfig;
@class PSDJsApi;

//容器的服务类
@interface PSDService : PSDKernel

+ (instancetype)alloc UNAVAILABLE_ATTRIBUTE;

- (instancetype)init UNAVAILABLE_ATTRIBUTE;

- (id)copy UNAVAILABLE_ATTRIBUTE;

+ (instancetype)allocWithZone:(struct _NSZone *)zone UNAVAILABLE_ATTRIBUTE;

+ (instancetype)new UNAVAILABLE_ATTRIBUTE;

/**
 *  @brief 取得Service实例
 *
 *  @date 2014-08-07 vc
 *
 *  @return 返回Service实例
 */
+ (PSDService *)sharedInstance;

/**
 *  @brief 启动服务（加载所有默认配置，包含jsApi、插件）
 *
 *  @date 2015-08-14
 *
 *  @return 无
 */
- (void)start;

/**
 *  @brief 给定一个sessionParam参数，创建一个Session对象。注：service会strong引用该对象，需要手动调用session.removeFromSuperObject;
 *
 *  @date 2014-08-07
 *
 *  @param sessionParam 参数，不能为nil
 *
 *  @return 返回Session对象
 */
- (PSDSession *)createSessionWithSessionParam:(PSDSessionParam *)sessionParam;

- (PSDSession *)createSessionWithSessionParam:(PSDSessionParam *)sessionParam expando:(NSDictionary *)expandoDict;

/**
 *  @brief 给定一个sceneParam参数，创建一个Scene对象。注：service会strong引用该对象，需要手动调用scene.removeFromSuperObject;
 *
 *  @date 2014-08-08
 *
 *  @param sceneParam 参数，不能为nil
 *
 *  @return 返回Scene对象
 */
- (PSDScene *)createSceneWithSceneParam:(PSDSceneParam *)sceneParam;

- (PSDScene *)createSceneWithSceneParam:(PSDSceneParam *)sceneParam parentObject:(PSDKernel *)parentObject;

/**
 *  @brief 给定一个viewParam参数，创建一个View对象。注：service会strong引用该对象，需要手动调用view.removeFromSuperObject;
 *
 *  @date 2014-08-08
 *
 *  @param viewParam 参数，不能为nil
 *
 *  @return 返回View对象
 */
- (PSDView *)createViewWithViewParam:(PSDViewParam *)viewParam;

- (PSDView *)createViewWithViewParam:(PSDViewParam *)viewParam parentObject:(PSDKernel *)parentObject;

#pragma mark - service api

/**
 *  @brief 注册一个JsApi，在特定分组下
 *
 *  @date 2014-09-03
 *
 *  @param jsApi   jsApi对象
 *  @param groupId 分组id
 *
 *  @return 无
 */
- (void)registerJsApi:(PSDJsApi *)jsApi groupId:(NSString *)groupId;

/**
 *  @brief 注册一组JsApi，在特定分组下
 *
 *  @date 2014-09-03
 *
 *  @param jsApis   jsApi对象的数组
 *  @param groupId 分组id
 *
 *  @return 无
 */
- (void)registerJsApis:(NSArray *)jsApis groupId:(NSString *)groupId; // PSDJsApi

/**
 *  @brief 注册一个JsApi，在默认分组下
 *
 *  @date 2014-09-03
 *
 *  @param jsApi   jsApi对象
 *
 *  @return 无
 */
- (void)registerJsApi:(PSDJsApi *)jsApi; // 默认分组kSharedJsApiGroupId

/**
 *  @brief 注册一组JsApi，在默认分组下
 *
 *  @date 2014-09-03
 *
 *  @param jsApis   jsApi对象的数组
 *
 *  @return 无
 */
- (void)registerJsApis:(NSArray *)jsApis; // PSDJsApi 默认分组kSharedJsApiGroupId

/**
 *  @brief 反注册一个JsApi，在默认分组下
 *
 *  @date 2014-09-03
 *
 *  @param jsApi   jsApi对象
 *
 *  @return 无
 */
- (void)unregisterJsApi:(PSDJsApi *)jsApi;

/**
 *  @brief 反注册一组JsApi，在特定分组下
 *
 *  @date 2014-09-03
 *
 *  @param jsApis  jsApi对象的数组
 *  @param groupId 分组id
 *
 *  @return 无
 */
- (void)unRegisterJsApis:(NSString *)groupId;

/**
 *  @brief 获取指定分组和名字的JsApi对象
 *
 *  @date 2014-09-03
 *
 *  @param name    JsApi名字
 *  @param groupId 分组id
 *
 *  @return 返回指定分组和名称的JsApi对象
 */
- (PSDJsApi *)jsApi:(NSString *)name groupId:(NSString *)groupId;

/**
 *  @brief 获取默认分组和名字的JsApi对象
 *
 *  @date 2014-09-03
 *
 *  @param name    JsApi名字
 *
 *  @return 返回默认分组和名称的JsApi对象
 */
- (PSDJsApi *)jsApi:(NSString *)name;

/**
 *  @brief 获取指定分组下所有JsApi对象
 *
 *  @date 2014-09-03
 *
 *  @param groupId 分组id
 *
 *  @return 返回指定分组下所有的JsApi对象
 */
- (NSArray *)jsApis:(NSString *)groupId;

/**
 *  @brief 获取默认分组下所有JsApi对象
 *
 *  @date 2014-09-03
 *
 *  @return 返回默认分组下所有的JsApi对象
 */
- (NSArray *)jsApis;

#pragma mark - service plugin

/**
 *  @brief 获取特定分组下的所有插件
 *
 *  @date 2014-09-03
 *
 *  @param groupId 分组id
 *
 *  @return 返回特定分组下的所有插件
 */
- (NSArray *)plugins:(NSString *)groupId;

/**
 *  @brief 获取默认分组下的所有插件
 *
 *  @date 2014-09-03
 *
 *  @return 返回默认分组下的所有插件
 */
- (NSArray *)plugins;

/**
 *  @brief 根据分组id和插件名称，获取插件
 *
 *  @date 2014-09-03
 *
 *  @param name    插件名称
 *  @param groupId 分组id
 *
 *  @return 返回找到的插件
 */
- (id<PSDPluginProtocol>)plugin:(NSString *)name groupId:(NSString *)groupId;

/**
 *  @brief 查找（默认分组和）插件名称，获取插件
 *
 *  @date 2014-09-03
 *
 *  @param name    插件名称
 *
 *  @return 返回找到的插件
 */
- (id<PSDPluginProtocol>)plugin:(NSString *)name;

/**************************************************Config JSApi******************************************************/
#pragma mark - Config JSApi

/**
 *  @brief 注册一个JsApi，在默认分组下（注：对于scope是kPSDScope_Service，直接作用到service上。否则，只能作用于到新创建的内核实例上）
 *
 *  @date 2014-09-03
 *
 *  @param jsApiCfg   jsApiCfg对象
 *
 *  @return 无
 */
- (void)registerJsApiCfg:(PSDJsApiConfig *)jsApiCfg; // 默认分组

/**
 *  @brief 注册一组JsApi，在默认分组下（注：对于scope是kPSDScope_Service，直接作用到service上。否则，只能作用于到新创建的内核实例上）
 *
 *  @date 2014-09-03
 *
 *  @param jsApiCfgs   jsApiCfg对象的数组
 *
 *  @return 无
 */
- (void)registerJsApiCfgs:(NSArray *)jsApiCfgs; // PSDJsApiConfig

/**
 *  @brief 反注册一个JsApi，在默认分组下（注：对于scope是kPSDScope_Service，直接作用到service上。否则，只能作用于到新创建的内核实例上）
 *
 *  @date 2014-09-03
 *
 *  @param jsApiCfg   jsApiCfg对象
 *
 *  @return 无
 */
- (void)unregisterJsApiCfg:(PSDJsApiConfig *)jsApiCfg;

/**
 *  @brief 反注册一组JsApi，在默认分组下（注：对于scope是kPSDScope_Service，直接作用到service上。否则，只能作用于到新创建的内核实例上）
 *
 *  @date 2014-09-03
 *
 *  @param jsApiCfgs  jsApiCfg对象的数组
 *
 *  @return 无
 */
- (void)unregisterJsApiCfgs:(NSArray *)jsApiCfgs; // PSDJsApiConfig

/**************************************************Config Plugin******************************************************/
#pragma mark - config Plugin

/**
 *  @brief 注册一个插件，并赋予默认的分组（注：对于scope是kPSDScope_Service，直接作用到service上。否则，只能作用于到新创建的内核实例上）
 *
 *  @date 2014-09-03
 *
 *  @param pluginCfg 插件配置对象
 *
 *  @return 无
 */
- (void)registerPluginCfg:(PSDPluginConfig *)pluginCfg;

/**
 *  @brief 注册一组插件，并赋予默认的分组（注：对于scope是kPSDScope_Service，直接作用到service上。否则，只能作用于到新创建的内核实例上）
 *
 *  @date 2014-09-03
 *
 *  @param pluginCfgs 插件配置对象的数组
 *
 *  @return 无
 */
- (void)registerPluginCfgs:(NSArray *)pluginCfgs; // PSDPluginConfig

/**
 *  @brief 在默认分组下，反注册一个插件（注：对于scope是kPSDScope_Service，直接作用到service上。否则，只能作用于到新创建的内核实例上）
 *
 *  @date 2014-09-03
 *
 *  @param pluginCfg 插件配置对象
 *  @param groupId   分组id
 *
 *  @return 无
 */
- (void)unregisterPluginCfg:(PSDPluginConfig *)pluginCfg;

/**
 *  @brief 在默认分组下，反注册一组插件（注：对于scope是kPSDScope_Service，直接作用到service上。否则，只能作用于到新创建的内核实例上）
 *
 *  @date 2014-09-03
 *
 *  @param pluginCfgs 插件配置对象的数组
 *  @param groupId   分组id
 *
 *  @return 无
 */
- (void)unregisterPluginCfgs:(NSArray *)pluginCfgs; // PSDPluginConfig


/**
 *  注册一个Component
 *
 *  @param name component名称
 *  @param clsName component对应的实现类名
 *  @return 无
 */
- (void)registerComponentWithName:(NSString *)name clsName:(NSString *)clsName;


/**
 *  反注册一个Component
 *
 *  @param name component名称
 *  @return 无
 */
- (void)unRegisterComponentWithName:(NSString *)name;

/**
 *  所有已经注册的Component
 *
 *  @return 已经注册的Component
 */
- (NSDictionary *)components;

@end

