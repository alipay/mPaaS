//
//  NBService.h
//  NBService
//
//  Created by chenwenhong on 15/8/21.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <NebulaPoseidon/NebulaPoseidon.h>
#import <NebulaAppManager/NebulaAppManager.h>

@interface NBService : NSObject

+ (instancetype)alloc UNAVAILABLE_ATTRIBUTE;

- (instancetype)init UNAVAILABLE_ATTRIBUTE;

- (id)copy UNAVAILABLE_ATTRIBUTE;

+ (instancetype)allocWithZone:(struct _NSZone *)zone UNAVAILABLE_ATTRIBUTE;

+ (instancetype)new UNAVAILABLE_ATTRIBUTE;

/**
 *  @brief 获取service
 *
 *  @date 2015-08-21
 *
 *  @return 返回service
 */
+ (instancetype)sharedService;

/**
 *  @brief 启动service
 *
 *  @date 2015-08-21
 *
 *  @return 无
 */
- (void)start;

- (id<NAMInterface>)appCenter;

/**
 * 根据指定的名称启动另一个应用。
 *
 * @param name 要启动的应用名。
 * @param params 应动应用时，需要转递给另一个应用的参数。key为kNBOptions_xxx
 * @param animated 指定启动应用时，是否显示动画。
 *
 * @return 应用启动成功返回YES，否则返回NO。
 */
- (BOOL)startSession:(NSDictionary *)params animated:(BOOL)animated;

/**
 *  @brief 创建一个VC
 *
 *  @date 2015-09-23
 *
 *  @param params 启动参数
 *
 *  @return 返回一个vc实例
 */
- (id<PSDViewControllerProtocol>)createNBViewController:(NSDictionary *)params;

/**
 *  @brief 创建一个VC
 *
 *  @date 2015-09-23
 *
 *  @param params              启动参数
 *  @param viewControllerClass vc类名，若是是nil，则根据配置获取默认
 *  @param contentViewClass    一般是UIWebView子类，若是是nil，则根据配置获取默认
 *
 *  @return 返回一个vc实例
 */
- (id<PSDViewControllerProtocol>)createNBViewController:(NSDictionary *)params
                                    viewControllerClass:(Class)viewControllerClass
                                       contentViewClass:(Class)contentViewClass;

/**
 *  @brief 创建一个VC
 *
 *  @date 2015-09-23
 *
 *  @param params 启动参数
 *  @param withExpando 主要是用来传递给VC一初始化就需要使用到的一些扩展属性
 *
 *  @return 返回一个vc实例
 */
- (id<PSDViewControllerProtocol>)createNBViewController:(NSDictionary *)params
                                            withExpando:(NSDictionary *)expando;
/**
 *  @brief 创建一个VC
 *
 *  @date 2015-09-23
 *
 *  @param params              启动参数
 *  @param viewControllerClass vc类名，若是是nil，则根据配置获取默认
 *  @param contentViewClass    一般是UIWebView子类，若是是nil，则根据配置获取默认
 *  @param withExpando 主要是用来传递给VC一初始化就需要使用到的一些扩展属性
 *  @return 返回一个vc实例
 */
- (id<PSDViewControllerProtocol>)createNBViewController:(NSDictionary *)params
                                    viewControllerClass:(Class)viewControllerClass
                                       contentViewClass:(Class)contentViewClass
                                            withExpando:(NSDictionary *)expando;

#pragma mark - service jsapi

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
- (void)registerJSApi:(PSDJsApi *)jsApi groupId:(NSString *)groupId;

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
- (void)registerJSApis:(NSArray *)jsApis groupId:(NSString *)groupId; // PSDJsApi

/**
 *  @brief 注册一个JSApi
 *
 *  @date 2015-09-23
 *
 *  @param jsApi jsApi对象
 *
 *  @return 无
 */
- (void)registerJSApi:(PSDJsApi *)jsApi;

/**
 *  @brief 注册一组JsApi，在默认分组下
 *
 *  @date 2014-09-03
 *
 *  @param jsApis   jsApi对象的数组
 *
 *  @return 无
 */
- (void)registerJSApis:(NSArray *)jsApis; // PSDJsApi 默认分组kSharedJsApiGroupId

/**
 *  @brief 反注册一个JsApi，在默认分组下
 *
 *  @date 2014-09-03
 *
 *  @param jsApi   jsApi对象
 *
 *  @return 无
 */
- (void)unregisterJSApi:(PSDJsApi *)jsApi;

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

/********************************************Config JSApi*****************************************************/
#pragma mark - Config JSApi
/**
 *  @brief 注册一个JSApi（注：对于scope是kPSDScope_Service，直接作用到service上。否则，只能作用于到新创建的内核实例上）
 *
 *  @date 2015-09-23
 *
 *  @param jsApiCfg jsApiCfg对象
 *
 *  @return 无
 */
- (void)registerJSApiCfg:(PSDJsApiConfig *)jsApiCfg;

/**
 *  @brief 注册一组JSApi（注：对于scope是kPSDScope_Service，直接作用到service上。否则，只能作用于到新创建的内核实例上）
 *
 *  @date 2015-09-23
 *
 *  @param jsApiCfgs jsApiCfg对象数组
 *
 *  @return 无
 */
- (void)registerJSApiCfgs:(NSArray *)jsApiCfgs; // PSDJsApiConfig

/**
 *  @brief 反注册一个jsApi（注：对于scope是kPSDScope_Service，直接作用到service上。否则，只能作用于到新创建的内核实例上）
 *
 *  @date 2015-09-23
 *
 *  @param jsApiCfg jsApiCfg对象
 *
 *  @return 无
 */
- (void)unregisterJSApiCfg:(PSDJsApiConfig *)jsApiCfg;

/**
 *  @brief 反注册一组jsApi（注：对于scope是kPSDScope_Service，直接作用到service上。否则，只能作用于到新创建的内核实例上）
 *
 *  @date 2015-09-23
 *
 *  @param jsApiCfgs jsApiCfg对象数组
 *
 *  @return 无
 */
- (void)unregisterJSApiCfgs:(NSArray *)jsApiCfgs;

/********************************************Config Plugin*****************************************************/
#pragma mark - Config Plugin

/**
 *  @brief 注册一个插件，并赋予默认的分组（注：对于scope是kPSDScope_Service，直接作用到service上。否则，只能作用于到新创建的内核实例上）
 *
 *  @date 2015-09-30
 *
 *  @param pluginCfg 插件配置对象
 *
 *  @return 无
 */
- (void)registerPluginCfg:(PSDPluginConfig *)pluginCfg;

/**
 *  @brief 注册一组插件，并赋予默认的分组（注：对于scope是kPSDScope_Service，直接作用到service上。否则，只能作用于到新创建的内核实例上）
 *
 *  @date 2015-09-30
 *
 *  @param pluginCfgs 插件配置对象的数组
 *
 *  @return 无
 */
- (void)registerPluginCfgs:(NSArray *)pluginCfgs; // PSDPluginConfig

/**
 *  @brief 在特定分组下，反注册一个插件（注：对于scope是kPSDScope_Service，直接作用到service上。否则，只能作用于到新创建的内核实例上）
 *
 *  @date 2015-09-30
 *
 *  @param pluginCfg 插件配置对象
 *
 *  @return 无
 */
- (void)unregisterPluginCfg:(PSDPluginConfig *)pluginCfg;

/**
 *  @brief 在特定分组下，反注册一组插件（注：对于scope是kPSDScope_Service，直接作用到service上。否则，只能作用于到新创建的内核实例上）
 *
 *  @date 2015-09-30
 *
 *  @param pluginCfgs 插件配置对象的数组
 *  @param groupId   分组id
 *
 *  @return 无
 */
- (void)unregisterPluginCfgs:(NSArray *)pluginCfgs; // PSDPluginConfig

@end

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
    
    NBService * NBServiceGet();
    
#ifdef __cplusplus
}
#endif // __cplusplus
