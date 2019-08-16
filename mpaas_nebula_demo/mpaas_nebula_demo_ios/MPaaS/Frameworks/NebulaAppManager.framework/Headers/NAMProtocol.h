//
//  NAMProtocol.h
//  NebulaAppManager
//
//  Created by 扶瑶 on 16/3/11.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#ifndef NAMProtocol_h
#define NAMProtocol_h

#import "NAMDefine.h"

#pragma mark - Download

@protocol NAMDownloadProtocol <NSObject>

/**
 *  取消下载任务
 *
 *  @param task 任务唯一标识
 */
- (void)cancel:(id)task;

@optional

/**
 *  下载指定url资源
 *
 *  @param url       资源url
 *  @param process   进度回调
 *  @param complete  完成回调
 *
 *  @return 任务唯一标识
 */
- (id)downloadUrl:(NSURL *)url
           params:(NSDictionary *)params
          process:(void (^)(float percent, NSUInteger readBytes, NSUInteger totalBytes))process
         complete:(void (^)(NSString *path, NSData *data, NSError *error))complete;

- (id)downloadUrl:(NSURL *)url
          process:(void (^)(float percent, NSUInteger readBytes, NSUInteger totalBytes))process
           finish:(void (^)(NSString *path, NSError *error))finish;

@end


#pragma mark - Zip

@protocol NAMZipArchiveProtocol <NSObject>

/**
 *  解压文件
 *
 *  @param file      待解压文件地址
 *  @param path      解压后文件地址
 *  @param overwrite 解压时是否覆盖
 *
 *  @return 是否成功
 */
- (BOOL)unzipFile:(NSString *)file
           toPath:(NSString *)path
        overwrite:(BOOL)overwrite;
@end


#pragma mark - Request

extern NSString *NAMREQ_PARAMKEY_INSTALLED_APPS;
extern NSString *NAMREQ_PARAMKEY_LOCAL_APPS;
extern NSString *NAMREQ_PARAMKEY_SCENE;
extern NSString *NAMREQ_PARAMKEY_FORCE;             // 强制请求,忽略请求频率
extern NSString *NAMREQ_PARAMKEY_REQTYPE;           // 请求类型 异步async/同步尝试synctry/同步强制syncforce
extern NSString *NAMREQ_PARAMKEY_RESAPP;            // 请求的资源应用Id [appId, ...]
extern NSString *NAMREQ_PARAMKEY_STABLE;            // 强大rpc标记
extern NSString *NAMREQ_PARAMKEY_REQ_NUM_LIMIT;     // rpc个数是否限制
extern NSString *NAMREQ_PARAMKEY_TRIGGER_SOURCE;    // 请求触发来源 (默认:normal, 网关全网化:sideMgw)
extern NSString *NAMREQ_PARAMKEY_APPINFO_SOURCE;    //
extern NSString *NAMREQ_PARAMKEY_APPPACKAGE_SOURCE;

extern NSString *NAMREQ_RESPONSEKEY_DATA;
extern NSString *NAMREQ_RESPONSEKEY_CONFIG;
extern NSString *NAMREQ_RESPONSEKEY_REMOVELIST;
extern NSString *NAMREQ_RESPONSEKEY_SCENE;
extern NSString *NAMREQ_RESPONSEKEY_DISCARDDATA;

@protocol NAMRequestProtocol <NSObject>

/**
 *  请求应用列表
 *
 *  @param dicApps 应用列表{appid:version}
 *  @param params  参数
 *  @param finish  完成回调
 */
- (void)requestApps:(NSDictionary *)dicApps
             params:(NSDictionary *)params
             finish:(void (^)(id data, NSError *error))finish;
@end

#pragma mark - Data Storage



@protocol NAMDataStorageProtocol <NSObject>

/**
 *  获取所有应用信息
 *
 *  @return {appId:{version:NAMApp对象}}
 */
- (NSDictionary *)allApps:(NAMAppAutoScene)autoscene;

/**
 *  保存应用信息
 *
 *  注意: 因灰度功能, 应用信息需要'用户维度'存储
 *
 *  @param apps {appId:{version:NAMApp对象}} 待保存应用列表
 *
 *  @return 是否成功
 */
- (BOOL)saveApps:(NSDictionary *)apps scene:(NAMAppAutoScene)autoscene;

/**
 *  获取已安装应用信息
 *
 *  @return {appid:已安装应用版本号version}
 */
- (NSDictionary *)installedApps:(NAMAppAutoScene)autoscene;

/**
 *  保存已安装应用信息
 *
 *  @param installedApps {appid:已安装应用版本号version}
 *
 *  @return 是否成功
 */
- (BOOL)saveInstalledApps:(NSDictionary *)installedApps scene:(NAMAppAutoScene)autoscene;

/**
 *  获取客户端配置
 *
 *  @return {key:value}
 */
- (NSDictionary *)clientConfigs;

/**
 *  保存客户端配置
 *
 *  @param clientConfigs {key:value}
 *
 *  @return 是否成功
 */
- (BOOL)saveClientConfigs:(NSDictionary *)clientConfigs;

/**
 *  获取指定信息
 *
 *  @param key 键值
 *
 *  @return value
 */
- (id)valueForKey:(NSString *)key;

/**
 *  保存指定信息
 *
 *  @param data 数据
 *  @param key  键值
 *
 *  @return 是否成功
 */
- (BOOL)saveData:(id)data forKey:(NSString *)key;


@optional

#pragma mark - credit

/**
 *  保存智能列表配置
 *
 *  @param list {key:value}
 *
 *  @return 是否成功
 */
- (BOOL)saveCreditList:(NSDictionary *)list;

/**
 *  获取智能列表配置
 *
 *  @param list {key:value}
 *
 *  @return 是否成功
 */
- (NSDictionary *)creditList;

/**
 *  保存本地的包信息中的publicURL配置
 *
 *  @return 是否成功
 */
- (BOOL)savePublicURLs:(NSDictionary *)publicURLs;

/**
 *  获取存储的publicURL配置
 */
- (NSDictionary *)publicURLs;


- (BOOL)saveAppInfoSource:(NSDictionary *)appInfoSource;
- (NSDictionary *)appInfoSource;
- (BOOL)saveAppPackageSource:(NSDictionary *)appPackageSource;
- (NSDictionary *)appPackageSource;


#pragma mark - deprecated

- (NSDictionary *)allApps __deprecated;
- (BOOL)saveApps:(NSDictionary *)apps __deprecated;
- (NSDictionary *)installedApps __deprecated;
- (BOOL)saveInstalledApps:(NSDictionary *)installedApps __deprecated;

@end


#pragma mark - credit

/*
 * 数据返回格式指定key
 *
 * NAMCreditResponseData   常用应用列表, value:[{'appId':'','credit':''},...]
 * NAMCreditResponseConfig 优惠策略, value:{'分数':'策略,十六进制'}
 */
extern NSString *const NAMCreditResponseData;
extern NSString *const NAMCreditResponseConfig;

/*
 * 配置说明
 *
 * NAMCreditConfigReqRate               列表请求频率, 默认:24小时
 * NAMCreditConfigReqLimitRate          列表限流频率, 默认:10分钟
 */
extern NSString *const NAMCreditConfigReqRate;
extern NSString *const NAMCreditConfigReqLimitRate;

/*
 * 请求参数
 *
 * NAMCreditReqParamsForce 强制请求,不受频率限制
 */
extern NSString *const NAMCreditReqParamsForce;

@protocol NAMCreditProtocol <NSObject>

/*
 * 业务需定制获取智能列表通道, SDK暂无默认通道, 必须接入rpc
 * data格式见上述「数据返回格式」
 */
- (void)fetchCreditlist:(NSDictionary *)params finish:(void (^)(id data, NSError *error))finish;

/*
 * 智能统计行为配置, 见上述「配置说明」
 */
- (NSDictionary *)config;

@end


#pragma mark - Log

extern NSString *const NAMLogParamApp;
extern NSString *const NAMLogParamAppId;
extern NSString *const NAMLogParamVersion;
extern NSString *const NAMLogParamCustom;
extern NSString *const NAMLogParamBizType;

extern NSString *const NAMLogParamBizTypeWebstat;

typedef NS_ENUM (NSUInteger, NAMLogStep) {
    NAMLogStepBegin = 0,
    NAMLogStepFinished,
};

/**
 *  包管理原始埋点类型, 已通过NebulaSDK中NBMonitor输出, 业务方直接使用NBMonitor代理即可
 *
 *  埋点seedId:
 *
 *      NAMLogTypePrepareApp            H5_APP_PREPARE
 *      NAMLogTypeDownloadApp           H5_APP_DOWNLOAD
 *      NAMLogTypeUnzipApp              H5_APP_UNZIP
 *      NAMLogTypeVerifyApp             H5_APP_VERIFY
 *      NAMLogTypeRequestApps           H5_APP_REQUEST
 *      NAMLogTypeAppPool               H5_APP_POOL
 *      NAMLogTypeExceptionHandler      H5_APP_EXCEP
 *
 */
typedef NS_ENUM (NSUInteger, NAMLogType) {
    NAMLogTypeUnknown = 0,
    NAMLogTypePrepareApp,           // 准备应用
    NAMLogTypeDownloadApp,          // 下载应用
    NAMLogTypeUnzipApp,             // 解压应用 (增量更新)
    NAMLogTypeVerifyApp,            // 验签应用
    NAMLogTypeRequestApps,          // 请求应用
    NAMLogTypeAppPool,              // 包管理池变更,增、删、改
    NAMLogTypeExceptionHandler,     // 异常管理, 1. 强制请求列表增、删 2. 验证url

    // Webstat
    NAMLogTypeWebstatZhuangjiliang, // 装机量埋点
    
    // Netstat
    NAMLogTypeNetstatChannel        // 网络性能埋点
};

@class NAMApp;
@interface NAMLogContext : NSObject;
@property (nonatomic, assign) NAMLogType type;
@property (nonatomic, assign) NAMLogStep step;
@property (nonatomic, strong) NSError *error;
@property (nonatomic, strong) NSDictionary *data;
@property (nonatomic, copy) NSString *customStep;
@property (nonatomic, copy) NSString *seedId;

+ (NAMLogContext *)type:(NAMLogType)type
                   step:(NAMLogStep)step;

+ (NAMLogContext *)type:(NAMLogType)type
                   step:(NAMLogStep)step
                  error:(NSError *)error
                   data:(NSDictionary *)data;

+ (NAMLogContext *)type:(NAMLogType)type
                cusStep:(NSString *)cusStep
                   data:(NSDictionary *)data;

+ (NAMLogContext *)type:(NAMLogType)type
                cusStep:(NSString *)cusStep
                  error:(NSError *)error
                   data:(NSDictionary *)data;

+ (NAMLogContext *)type:(NAMLogType)type
                   data:(NSDictionary *)data;

/**
 *  获取log唯一标识
 *
 *  @return string
 */
- (NSString *)seedId;

/**
 *  获取log参数
 *
 *  @return {key:value}
 */
- (NSDictionary *)params;

@end


@protocol NAMLogProtocol <NSObject>
@optional

/**
 *  输出log
 *
 *  @param context log上下文
 */
- (void)log:(NAMLogContext *)context;
@end

#pragma mark - Config

@protocol NAMDynamicConfigProtocol <NSObject>
@optional

/**
 *  是否为覆盖安装
 *
 *  说明: 如果配置了预置应用列表, 覆盖安装时候会用预置列表覆盖一次磁盘缓存
 */
- (BOOL)coverInstall;

/**
 *  返回用户userId
 *
 *  注意: 该值只在开启用户模式下生效
 *  说明: 默认加入灰度规则中, 为nil时候认为未登录
 */
- (NSString *)currentUserId;

/**
 *  返回网络状态, 辅助判断下载时机等
 */
- (NAMNetworkStatus)networkStatus;

/**
 *  是否强制下载离线包
 *
 *  说明: 请求成功后会判断是否需要下载离线包, 可通过该方法配置, 如果应用配置了auto_install=YES,则不受该方法限制,强制下载
 *  
 *  已废弃,下载时机统一由平台通过参数配置,请实现networkStatus函数返回网络环境辅助判断
 */
- (BOOL)forcedDownload __deprecated;


/**
 *  是否使用mmap方式读取tar文件
 */
- (BOOL)useMmapReadTar;

/**
 *  离线资源匹配附加功能开关，如publicUrls匹配
 */
- (NSDictionary *)resManifestSwitchers;

/**
 * 是否允许预下载, 默认:是
 */
- (BOOL)enablePreDownload:(NSString *)appId;

/**
 * 指定appId启动超时时间, 无配置需返回-1, >=0内部均会执行
 */
- (double)prepareTimeLimit:(NSString *)appId;

/**
 指定appId降级后设置的启动超时时间, 无配置需返回-1, >=0内部均会执行
 @return 超时时间
 */
- (double)packageDowngradePrepareTimeLimit:(NSString *)appId;

/**
 * 是否允许进入app时异步解压包文件
 */
- (BOOL)enableAsyncUnzipWhenLaunchingApps;

/**
 4G预下载增加开关白名单管控
 @return 白名单列表AppId
 */
- (BOOL)isPackageDowngradeSwitchOn;

/**
 4G预下载增加开关白名单管控
 @return 白名单列表AppId
 */
- (BOOL)enablePreDownloadWith4G:(NSString *)appId;

/*
 * 是否开启包信息来源埋点
 */
- (BOOL)enableAppInfoSourceLog;

/**
 * 是否开启包文件来源埋点
 */
- (BOOL)enableAppPackageSourceLog;

/**
 * 在解压结束后是否使用高优先级队列进行回调
 */
- (BOOL)callbackInHighPriorityAfterUnzip;

/**
 * 客户端配置, 默认读取nebulamng客户端配置, 可定制读取内容
 *
 * @param  key       字符串, 指定具体开关key
 *         shortKey  字符串, key缩写
 *         error     指针地址, error不为空时降级使用nebulamng客户端配置
 * @return id        开关值
 */
- (id)clientConfigForKey:(NSString *)key shortKey:(NSString *)shortKey error:(NSError **)error;

@end

#pragma mark - App Interface

@protocol NAMAppInterface <NSObject>
@optional

/**
 *  是否支持NebulaApp
 *
 *  说明: 
 *      支持: 从包管理池中读取对象, 如果对象不存在, 则通过以下findApp:version:方法读取定制的应用对象
 *      不支持: 直接通过以下 findApp:version: 方法读取定制的应用对象
 */
- (BOOL)supportNebulaApp:(NSString *)appid version:(NSString *)version __deprecated;
- (BOOL)supportNebulaApp:(NSString *)appid version:(NSString *)version nebulaVersion:(NSString **)nebulaVersion;

/**
 *  定制应用对象
 */
- (NAMApp *)findApp:(NSString *)appid version:(NSString *)version;

/**
 *  配置指定应用id不被删除的版本号
 *
 *  说明: 应用信息池受容量控制, 当超过最大容量时会默认删除最小版本号应用信息, 可通过该方法配置不可删除的版本
 */
- (NSArray *)permanentVersionsForApp:(NSString *)appid sceneType:(NAMAppAutoScene)sceneType;

/**
 *  在公共离线资源未下载完成的场景下, 是否允许离线包降级至已安装版本
 *
 *  说明: 可降级至已安装版本/预置版本, 默认:NO
 */
- (BOOL)enableCommonResourceDegrade:(NSString *)appid;


/**
 *  获取应用场景
 *  注: 仅钱包内调试模式使用
 */
- (NSString *)sceneForApp:(NSString *)appId;

/**
 *  是否允许强大request, sdk默认允许
 */
- (BOOL)enableStableReq;

/**
 *  是否支持加载指定公共appId资源
 */
- (BOOL)enableLoadPubAppId:(NSString *)appid contextApp:(NAMApp *)contextApp version:(NSString **)version;

/**
 * 是否允许加载业务资源包, 默认:是
 */
- (BOOL)enableLoadPkgResApps:(NSNumber **)numLimit;

/**
 * 是否允许忽略预置信息入口版本, 取最高版本, 默认:是
 */
- (BOOL)enableIgnorePresetVersion;

/**
 * 是否是资源型应用
 */
- (BOOL)isResApp:(NSString *)appId;

/**
 * 是否允许强制下载时取消已存在任务 10.1.10
 */
- (BOOL)enableForceDownloadCancel;

/**
 * 查看预置离线包信息
 */
- (NSDictionary *)presetAmrApps;

/**
 * 是否允许同步解压预置资源
 */
- (BOOL)enableSyncUnzipPresetAmr;

/**
 * 是否允许取消正在下载中高优先级下载任务
 */
- (BOOL)disableCancelHighPriorityTask;

@end


#endif /* NAMProtocol_h */
