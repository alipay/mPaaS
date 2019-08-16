//
//  NebulaPackageService.h
//  NebulaAppBiz
//
//  Created by 扶瑶 on 16/2/18.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NAOpenPlatformDefine.h"
#import <NebulaAppManager/NebulaAppManager.h>
#import "NebulaAppDefine.h"

@interface NebulaAppService : NSObject <DTService>

/**
 *  准备Nebula应用信息
 *  
 *  注:
 *   NebulaApp判断方式: extra->launchMode==NebulaApp
 *   appId: ACApp->appId
 *   version: ACApp->extra->NebulaVersion 版本号未配置或配置为*,则校验失败,不操作
 */
- (void)prepareWithAppId:(NSString *)appId;

/**
 *  查找指定id和版本号的应用信息
 *
 *  逻辑:
 *      一. NebulaApp:
 *             1. 版本号获取方式: ACApp->extra->NebulaVersion
 *             2. 版本号校验: 不支持配置nil或*, 如果版本号校验失败, 返回nil
 *
 *      二. 非NebulaApp:从应用中心获取ACApp并转化为NAMApp
 *
 *  @return 返回指定appid和应用中心版本号的NAMApp对象
 */
- (NAMApp *)findApp:(NSString *)appId;



/**
 根据指定的 appId 和 version 返回应用，不返回已下线的应用

 @param appId
 @param version
 @return
 */
-(NAMApp*)findApp:(NSString *)appId withVersion:(NSString *)version;

/**
 *  批量应用请求
 *
 *  注: 
 *      9.9.9前: 请求成功后Wifi下自动下载离线包,非Wifi只下载auto_install为YES的离线包
 *      9.9.9及之后: 可针对每个应用配置下载时机, 通过服务端配置, 默认WIFI下载
 *
 *  @param apps   请求应用ID列表
 *  @param param  请求参数 预留参数,暂时无用,可传nil
 *  @param finish 完成回调
 */
- (void)requestApps:(NSDictionary *)apps
              param:(NSDictionary *)param
             finish:(NAMRequestFinish)finish;

/**
 *  注意: 此接口仅限业务内部使用, 外部业务请勿直接调用该接口 !!
 *
 *  安装应用
 *  安装步骤: 下载->解压,异步,通过回调通知
 *  注意: 下载不区分网络环境, 为强制下载
 *
 *  @param app     应用对象
 *  @param process 安装过程回调, 包含下载、解压
 *  @param finish  完成回调
 */
- (void)installApp:(NAMApp *)app
           process:(NAMAppInstallProcess)process
            finish:(NAMAppInstallFinish)finish;


/**
 *  查看指定appId的应用是否为NebulaApp
 *
 *  @param appId    查看应用ID
 *  @param version  返回入口配置的NebulaVersion
 */
- (BOOL)isNebulaAppId:(NSString *)appId nebulaVersion:(NSString **)version;

/**
 *  验签指定应用安装文件
 *
 *  @param  app 指定应用对象
 *  @return BOOL 是否验签成功
 */
- (BOOL)verifyApp:(NAMApp *)app;

/**
 *  判断是否满足指定版本要求
 *
 *  @param  opversin  应用中心版本
 *          nbversion Nebula版本
 *  @return 是否满足要求 (本地版本>=期望版本时匹配成功)
 */
- (BOOL)isVersionValid:(NSString *)appId
             opversion:(NSString *)opversin
             nbversion:(NSString *)nbversion;

/**
 *  是否开启了NebulaHandler模式
 */
- (BOOL)enableNebulaHandler;

/**
 *  返回应用中心App类型
 */
- (ACAppType)appType:(NSString *)appId;

/**
 *  配置Debug模式, 仅限NebulaDebug调试模式使用, 其他场景勿用!
 */
- (void)setDebugDelegate:(id<NADebugProtocol>)delegate;

/**
 *  添加公共资源应用列表
 *
 *  说明: 暂仅用于应用更新, 为了统一请求入口, 提高公共资源更新率, 每次请求时查看公共资源是否过期一并请求
 *
 *  @param  list  应用ID列表, e.g. ['20000196','20000202']
 */
- (void)addCommonApps:(NSArray *)list;

/*
 * 清理amr/tar磁盘缓存
 *
 * @param ignoreCheckTime 是否忽略检测频率
 *
 * 注意: 清理操作在调用线程执行
 */
- (void)clearStorage:(BOOL)ignoreCheckTime;

/**
 *  小程序线上/线下切换模式配置, 仅限NebulaDebug调试模式使用, 其他场景勿用!
 */
- (BOOL)enableTinySwitchMode;

/**
 *  判断应用启动链路Nebula是否已处理完毕
 */
- (BOOL)isNebulaHanlerProcessed:(DTMicroApplication *)application params:(NSDictionary *)params;

/**
 *  注册NebulaAppService维度handler
 */
- (void)registerHandler:(id<NebulaAppHandlerProtocol>)handler;

/**
 *  创建Nebula应用处理器
 */
- (id<NebulaStartHandlerProtocol>)createNebulaStartHandler;

@end
