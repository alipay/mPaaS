//
//  NAMService.h
//  NebulaAppManager
//
//  Created by 扶瑶 on 16/3/3.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NAMAppSourceManager.h"

@protocol NAMInterface <NSObject>

/**
 *  查找指定id和版本号的应用信息
 *
 *  @param appId   应用id
 *  @param version 应用版本号, 支持版本号模糊匹配 e.g. '*' 匹配最高版本号 '1.*' 匹配1开头的版本号总最高版本号等,最长4位
 *
 *  @return 返回某个appid指定版本号应用对象
 *
 *  注意:
 *      1. 不区分应用上下线 (即下线的应用也会通过该接口返回)
 *      2. 函数内通过NAMAppInterface协议判断是否支持NebulaApp, 并且在未找到应用的情况下通过协议函数:findApp查找.
 *      NAMAppInterface协议可通过 NAMConfigurationGet().appInterface 指定
 */
- (NAMApp *)findApp:(NSString *)appId version:(NSString *)version;

/**
 *  查找指定id和版本号的可用应用信息
 *
 *  注意: 过滤已下线应用
 */
- (NAMApp *)findAvailableApp:(NSString *)appId version:(NSString *)version;


/**
 *  准备应用信息
 *
 *  @param appId   应用id
 *  @param version 应用版本号, 支持版本号模糊匹配 e.g. '*' 匹配最高版本号 '1.*' 匹配1开头的版本号总最高版本号等,最长4位
 *  @param process 准备过程回调, 过程包含:更新包信息(频率限制)->异步下载离线包->解压离线包
 *  @param finish  完成回调
 */
- (void)prepareApp:(NSString *)appId
           version:(NSString *)version
           process:(NAMAppPrepareProcess)process
            finish:(NAMAppPrepareFinish)finish;
- (void)prepareApp:(NSString *)appId
           version:(NSString *)version
            params:(NSDictionary *)params
           process:(NAMAppPrepareProcess)process
            finish:(NAMAppPrepareFinish)finish;


/**
 *  定制准备应用方式，可自行设置同步、异步策略
 *
 *  @param appId        应用id
 *  @param version      应用版本号, 支持版本号模糊匹配 e.g. '*' 匹配最高版本号 '1.*' 匹配1开头的版本号总最高版本号等,最长4位
 *  @param reqType      请求方式: 同步更新、异步更新
 *  @param offlineType  离线方式: 同步离线、异步离线
 *  @param finish       完成结果回调
 */
- (void)prepareApp:(NSString *)appId
           version:(NSString *)version
           reqType:(NAMActionReqType)reqType
       offlineType:(NAMActionOfflineType)offlineType
            finish:(NAMAppPrepareFinish)finish;

/**
 *  定制准备应用方式
 *
 *  @param appId        应用id
 *  @param version      应用版本号, 支持版本号模糊匹配 e.g. '*' 匹配最高版本号 '1.*' 匹配1开头的版本号总最高版本号等,最长4位
 *  @param reqType      请求方式: 同步尝试更新、同步强制更新、异步更新
 *  @param offlineType  离线方式: 同步离线、异步离线
 *  @param params       参数, 现支持:
 *  @param finish  完成回调
 */
- (BOOL)prepareApp:(NSString *)appId
           version:(NSString *)version
            params:(NSDictionary *)params
           reqType:(NAMActionReqType)reqType
       offlineType:(NAMActionOfflineType)offlineType
         processor:(NAMAppPrepareProcessor)processor
            finish:(NAMAppPrepareFinishWithInfo)finish;


/**
 *  安装应用
 *
 *  @param app     应用对象
 *  @param process 安装过程回调, 过程包含: 异步下载离线包->解压离线包
 *  @param finish  完成回调
 */
- (void)installApp:(NAMApp *)app
           process:(NAMAppInstallProcess)process
            finish:(NAMAppInstallFinish)finish;


/**
 *  全量请求
 *
 *  注:
 *      9.9.9前: 请求成功后Wifi下自动下载离线包,非Wifi只下载auto_install为YES的离线包
 *      9.9.9及之后: 可针对每个应用配置下载时机, 通过服务端配置, 默认WIFI下载
 *
 *  @param param  请求参数 预留参数,暂时无用,可传nil
 *  @param finish 完成回调
 */
- (void)requestAllApps:(NSDictionary *)param
                finish:(NAMRequestFinish)finish;


/**
 *  单个应用请求
 *
 *  注:
 *      9.9.9前: 请求成功后Wifi下自动下载离线包,非Wifi只下载auto_install为YES的离线包
 *      9.9.9及之后: 可针对每个应用配置下载时机, 通过服务端配置, 默认WIFI下载
 *
 *  @param apps   请求列表 格式:{appid:version},可传多个appid,不指定version时传空传,默认取最高版本
 *                支持版本号模糊匹配 e.g. '*' 匹配最高版本号 '1.*' 匹配1开头的版本号总最高版本号等,最长4位
 *  @param param  请求参数 预留参数,暂时无用,可传nil
 *  @param finish 完成回调
 */
- (void)requestApps:(NSDictionary *)apps
              param:(NSDictionary *)param
             finish:(NAMRequestFinish)finish;

/**
 *  全量下载
 *
 *  注:
 *      9.9.9前: 请求成功后Wifi下自动下载离线包,非Wifi只下载auto_install为YES的离线包
 *      9.9.9及之后: 可针对每个应用配置下载时机, 通过服务端配置, 默认WIFI下载
 */
- (void)downloadAllApps;

/**
 *  触发批量下载 (根据应用配置的下载时机决定是否下载)
 *
 *  @param apps 字典{appId:version},指定要下载的appId和版本号,从包管理池中读取并下载
 */
- (void)downloadApps:(NSDictionary *)apps;

/**
 *  触发批量下载 (根据应用配置的下载时机决定是否下载)
 *
 *  @param apps 字典{appId:version},指定要下载的appId和版本号,从包管理池中读取并下载
 *  @param params 下载参数，埋点时使用
 */
- (void)downloadApps:(NSDictionary *)apps params:(NSDictionary *)params;


/**
 *  获取请求失败的应用列表
 *  
 *  注: 该应用列表会跟随下次请求一起发出
 *
 *  @return 返回列表字典, 格式:{appid:version}字典
 */
- (NSDictionary *)failedRequestApplist;

/**
 *  需要强制同步更新的应用列表 (仅在支付宝内使用)
 */
- (NSArray *)unavailableApplist;
- (void)addUnavailableApplist:(NSArray *)list;

/**
 *  添加应用
 *
 *  注: 应用的更新时间自动置为最新
 *
 *  @param apps 应用数组, 格式:NAMApp对象数组
 *  @param download 是否触发下载 (是:根据应用下载时机判断是否下载 否:不下载)
 *  @param source 更新来源
 */
- (void)addApps:(NSArray *)apps source:(NAMAppSource)source download:(BOOL)download;
- (void)addApps:(NSArray *)apps source:(NAMAppSource)source scene:(NSString *)scene download:(BOOL)download;


/**
 *  更新客户端配置
 *
 *  @param config 配置字典, 格式:{key:value}
 */
- (void)updateClientConfig:(NSDictionary *)config;

/**
 *  取消所有离线包下载任务 (排除:down_type!=wifi强制下载的离线包,即只能取消down_type==WIFI的包)
 */
- (void)cancelAllDownloadTask;

/**
 *  入口安全校验
 *  
 *  校验逻辑: 对于主入口url,首先匹配和main_url的scheme和host是否完全匹配,不匹配时再sub_url对比,都不匹配时候校验失败
 *  注意
 *      1. 如果urlString为/或file://开头,则直接通过校验
 *      2. SDK内默认对入口URL不做安全校验, 如业务方有安全校验需求可以调用该接口校验
 */
- (BOOL)isMainUrlValid:(NSString *)urlString app:(NAMApp *)app;

/**
 *  获取指定应用本地已有资源的版本
 *  
 *  逻辑: 查找 已安装版本 -> 预置版本 -> 业务方定制的应用版本
 *  现应用场景: 加载公共资源包资源时,如果本地离线包未安装,会触发加载本地已安装的版本(因降级受包特性影响, 只有纯资源并且和版本无关的应用类型才支持降级。SDK降级开关默认:关, 业务方如需配置请联系@扶瑶, 其他场景勿用)。
 */
- (NAMApp *)findResourcesPreparedApp:(NSString *)appId;

/**
 *  版本号比对
 *
 *  @return 
 *          version1 > version2 : 1
 *          version1 = version2 : 0
 *          version1 < version2 : -1
 */
- (NSInteger)compareVersions:(NSString *)version1 withVersion:(NSString *)version2;

/**
 *  添加公共资源应用列表
 *
 *  说明: 暂仅用于应用更新, 为了统一请求入口, 提高公共资源更新率, 每次请求时查看公共资源是否过期一并请求
 *
 *  @param  list  应用ID列表, e.g. ['20000196','20000202']
 */
- (void)addCommonApps:(NSArray *)list;

/**
 * 查询已安装应用列表
 *
 * @param list 字典 {appId:version}
 */
- (NSDictionary *)installApps:(NSDictionary *)list;

/**
 * 查询全量ID列表
 *
 * @param array 数组 [appId,appId...]
 */
- (NSArray *)allAppIds;

/**
 * 判断指定appId是否为资源型应用
 * 
 * @param 指定应用appId
 */
- (BOOL)isResApp:(NSString *)appId;

/**
 * 解压状态为「预解压」的应用
 */
- (void)preUnzipAllApps;
- (void)preUnzipApps:(NSArray *)apps;

/**
 *  清除指定appId更新时间戳
 *  作用: 清除后, 再进入应用可触发'同步尝试更新'
 *
 *  @param arrAppId [appId,...] appId字符串数组
 */
- (void)clearUpdateTime:(NSArray *)arrAppId;

/**
 * 获取池中指定appId的所有版本应用实例
 *
 * @param appId 指定应用Id数组
 * @return NSDictionary 池中该appId的所有版本实例 {appId:[NAMApp, ...], ...}
 */
- (NSDictionary *)allAppsForAppId:(NSArray *)arrAppId;

/**
 * 删除回滚的包信息
 */
- (void)removeDiscardApp:(NSString *)appId version:(NSString *)version;
/**
 *  @brief 删除本地应用信息(包括包信息、amr以及安装目录)
 *
 *  @date 2019-02-28
 *
 *  @return
 */
-(void)clearAllAppInfo:(NSString *)appId;

#pragma mark - credit

/*
 * 触发获取智能列表请求
 *
 * 注意: 业务可选取时机手动触发, 内部有频率控制, 默认24小时
 */
- (void)requestCreditlist:(NSDictionary *)params
                   finish:(void (^)(NSError *error))finish;

- (NSString *)creditForApp:(NSString *)appId;

#pragma mark -
/*
 * 通过包信息中的publicURL列表匹配appId
 */
- (NSString *)findAppIdByURL:(NSString *)URLString;

/*
 * 通过publicURL匹配主文档的开关
 */
- (BOOL)enableMatchMainURLByPublicURL;

/*
 * 通过header.json匹配header的开关
 */
- (BOOL)enableMatchHeaders;

#pragma mark - AppSourceManager
/*
 * 记录、获取包信息和包文件的来源
 */
- (void)setAppInfoSource:(NSString *)appId version:(NSString *)version source:(NAMAppInfoSource)source;
- (void)setAppsInfoSource:(NSDictionary *)apps source:(NAMAppInfoSource)source;
- (void)setAppPackageSource:(NSString *)appId version:(NSString *)version source:(NAMAppPackageSource)source;
- (void)setAppsPackageSource:(NSDictionary *)apps source:(NAMAppPackageSource)source;

- (NAMAppInfoSource)appInfoSource:(NSString *)appId version:(NSString *)version;
- (NAMAppPackageSource)appPackageSource:(NSString *)appId version:(NSString *)version;

@end


@class NAMApp;
@class NAMAppDataSource;
@interface NAMService : NSObject <NAMInterface>

/**
 *  获取应用数据源对象
 *
 *  @param appId   应用id
 *  @param version 应用版本号
 *
 *  @return 返回应用数据源对象
 */
- (NAMAppDataSource *)findAppDataSource:(NSString *)appId version:(NSString *)version;

/**
 *  添加Log, 最终通过NBMonitor输出
 */
- (void)log:(NAMLogContext *)context;


/**
 * 其他渠道数据更新处理
 */
- (void)processData:(NSDictionary *)data reqlist:(NSDictionary *)reqlist autoDownload:(BOOL)autoDownload;

@end






#pragma mark - Unavalilable

@interface NAMService (UNAVAILABLE)

/**
 *  不可分配内存空间
 */
+ (instancetype)alloc UNAVAILABLE_ATTRIBUTE;

/**
 *  不可分配内存空间
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone UNAVAILABLE_ATTRIBUTE;

/**
 *  不可分配内存空间
 */
+ (instancetype)new UNAVAILABLE_ATTRIBUTE;

/**
 *  不可初始化
 */
- (instancetype)init UNAVAILABLE_ATTRIBUTE;

/**
 *  不可复制
 */
- (id)copy UNAVAILABLE_ATTRIBUTE;

@end


#ifdef __cplusplus
extern "C" {
#endif
    NAMService * NAMServiceGet();
#ifdef __cplusplus
}
#endif

