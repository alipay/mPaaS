//
//  NAMApp.h
//  NebulaAppManager
//
//  Created by chenwenhong on 15/9/16.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NebulaAppProtocol.h"

// 下载时机,枚举值与服务端返回值对应
typedef NS_ENUM (int, NAMDownType){
    NAMDownTypeWifi = 0,
    NAMDownTypeAny,
    NAMDownTypeUse
};

// 安装类型,枚举值与服务端返回值对应
typedef NS_ENUM (int, NAMInstallType){
    NAMInstallTypeUse = 0,
    NAMInstallTypeAny,
};

// 应用类型
typedef NS_ENUM(int, NAMAppType){
    NAMAppTypeH5 = 1,   // H5
    NAMAppTypeRN = 5    // RN
};

// 应用来源
typedef NS_ENUM(int, NAMAppChannel) {
    NAMAppChannelAlipay = 1,        // 支付宝自建应用
    NAMAppChannelAlibaba,           // 集团应用
    NAMAppChannelThirdParty,        // 第三方
    NAMAppChannelApplet             // 小程序
};

@interface NAMApp : NSObject <NSCopying, NebulaAppProtocol>

@property (nonatomic, readonly, copy) NSString *nbl_id;             // 应用唯一标识, e.g. AP_20000001
@property (nonatomic, readonly, copy) NSString *app_id;             // 应用id, e.g. 20000001
@property (nonatomic, readonly, copy) NSString *name;               // 应用名称, e.g. 机票
@property (nonatomic, readonly, copy) NSString *version;            // 应用版本, e.g. 1.0.0.0
@property (nonatomic, readonly, copy) NSString *desc;               // 应用描述 (钱包内请勿使用该参数)
@property (nonatomic, readonly, copy) NSString *package_url;        // 应用离线包下载url
@property (nonatomic, readonly, copy) NSString *icon_url;           // 应用图标url (钱包内请勿使用该参数)
@property (nonatomic, readonly, copy) NSString *main_url;           // 主入口url
@property (nonatomic, readonly, copy) NSString *vhost;              // 虚拟域名
@property (nonatomic, readonly, copy) NSString *fallback_host;      // fallback地址
@property (nonatomic, readonly, copy) NSString *patch;              // 增量包url
@property (nonatomic, readonly, copy) NSString *third_platform;     // 第三方透传
@property (nonatomic, readonly, copy) NSString *scene;              // 场景, 10.0.5新增, ONLINE/DEBUG/TRIAL/PREVIEW
@property (nonatomic, readonly, copy) NSString *release_type;       // 发布类型, 10.0.5新增
@property (nonatomic, readonly, copy) NSString *api_permission;     // api权限, 10.0.12新增
@property (nonatomic, readonly, copy) NSString *package_nick;       // 包ID, 10.0.15新增
@property (nonatomic, readonly, copy) NSString *slogan;             // 小程序主体信息 (仅hpmweb下发,wapcenter不下发)
@property (nonatomic, readonly, copy) NSArray *sub_url;             // 限制入口url
@property (nonatomic, readonly, copy) NSDictionary *extend_info;    // 应用扩展信息
@property (nonatomic, readonly) BOOL isOnline;                      // 应用业务状态，如: 上线、下线
@property (nonatomic, readonly) int local_report;                   // 控制是否跟随localAppInfo配置, 默认:0, 10.0.15新增
@property (nonatomic, readonly) long long size;                     // 应用大小, Byte
@property (nonatomic, readonly) NAMDownType downType;               // 下载时机,10.0.2新增属性
@property (nonatomic, readonly) NAMAppType appType;                 // 应用类型 (钱包内请勿使用该参数)
@property (nonatomic, readonly) NAMAppChannel appChannel;           // 应用来源
@property (nonatomic, readonly) NAMInstallType installType;         // 安装类型

/**
 *  根据字典初始化对象
 *
 *  @return 字典格式非法、无appid、无version情况下返回nil
 */
- (instancetype)initWithDict:(NSDictionary *)dictionary;

/**
 *  将对象转为字典
 */
- (NSDictionary *)dictionary;

/**
 *  获取离线包地址
 *
 *  读取过程:
 *  1. 通过 NAMConfigurationGet().internalPackageAMRPath 读取预置离线包地址,离线包命名格式: appid_version.amr
 *  2. 预置离线包不存在时, 读取沙盒内下载的离线包地址
 */
- (NSString *)amrPath;

/**
 *  获取已安装包tar地址
 *
 *  读取过程:
 *  1. 未兼容老版本, 先读取 appid.tar
 *  2. appid.tar 不存在时候读取 nbl_id.tar
 */
- (NSString *)tarPath;

/**
 *  获取离线包解压地址
 *
 *  注:解压总文件夹地址可通过 NAMConfigurationGet().unzipRootPath 配置
 */
- (NSString *)unzipPath;

/**
 *  获取离线包下载地址
 */
- (NSString *)downloadPath;

/**
 * 获取模版小程序配置信息存储地址
 */
- (NSString *)templateConfigPath;

/**
 *  获取离线包Url
 *
 *  @return 增量包返回patchUrl,全量包返回全量packageUrl
 */
- (NSString *)downloadUrl;

/**
 *  获取应用状态
 */
- (NAMAppStatus)appStatus;

/**
 *  是否为模版小程序
 */
- (BOOL)isTemplateApp;

/**
 *  是否已安装
 */
- (BOOL)isInstalled;

/**
 *  是否为增量包
 */
- (BOOL)isIncremental;

/**
 *  是否需要下载
 */
- (BOOL)needDownload;

/**
 *  去除增量属性, 变为全量包
 */
- (void)removeIncrementalResource;

/**
 *  第三方信息 (开发平台下发ID)
 */
- (NSDictionary *)thirdPlatformInfo;

/**
 *  应用下发场景
 */
- (NAMAppAutoScene)sceneType;

/**
 *  api权限配置
 */
- (NSDictionary *)apiPermission;

/**
 *  清除上次更新时间
 */
- (void)clearLastRefreshTime;

@end

