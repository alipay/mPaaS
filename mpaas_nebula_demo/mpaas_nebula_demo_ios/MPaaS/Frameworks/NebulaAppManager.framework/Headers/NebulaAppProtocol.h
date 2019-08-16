//
//  NebulaAppResponseProtocol.h
//  NebulaSDK
//
//  Created by nico on 2018/11/16.
//  Copyright © 2018 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol NebulaAppProtocol <NSObject, NSCopying>

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
 *  获取离线包Url
 *
 *  @return 增量包返回patchUrl,全量包返回全量packageUrl
 */
- (NSString *)downloadUrl;

/**
 *  获取应用状态
 */
//- (NAMAppStatus)appStatus;

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
 *  TODO: 新老容器枚举不统一，状态暂不开放
 */
//- (NAMAppAutoScene)sceneType;

/**
 *  api权限配置
 */
- (NSDictionary *)apiPermission;

/**
 *  清除上次更新时间
 */
- (void)clearLastRefreshTime;
@end
NS_ASSUME_NONNULL_END
