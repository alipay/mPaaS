//
//  NBAppDataSourceManager.h
//  Nebula
//
//  Created by chenwenhong on 15/9/21.
//  Copyright © 2015年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

// 资源降级标识
#define kNBDataSource_DegradedApp  @"kNBDataSource_DegradedApp"

@interface NBAppDataSourceManager : NSObject

@property(nonatomic, readonly, copy) NSString   *appid; // 主离线app
@property(nonatomic, readonly, strong) NAMApp   *app; // 主离线app
@property(nonatomic, readonly, assign) BOOL     isAppLoaded; // 是否已经加载

- (instancetype)initWithAppid:(NSString *)appid version:(NSString *)version;

/**
 *  NBAppDataSourceManager 初始化方法
 *
 *  @date 2018-03-29
 *
 *  @param appid     离线app的id
 *  @param version   版本号
 *  @param session   当前session
 *
 *  @return 返回是否验签成功（加载成功）
 */
- (instancetype)initWithAppid:(NSString *)appid
                      version:(NSString *)version
                      session:(NBSession *)session;

/**
 *  @brief 根据nbl_id加载离线app
 *
 *  @date 2015-09-21
 *
 *  @param nbl_id     离线app的id
 *  @param needVerify 是否需要验签
 *
 *  @return 返回是否验签成功（加载成功）
 */
- (BOOL)loadAppData:(NAMApp *)app needVerify:(BOOL)needVerify;

/**
 *  @brief 卸载app数据
 *
 *  @date 2015-10-08
 *
 *  @return 无
 */
- (void)unloadAppData;

/**
 *  @brief 获取主入口url
 *
 *  @date 2015-12-23
 *
 *  @return 返回主入口url
 */
- (NSString *)mainUrlString:(NSString *)urlString;

/**
 *  @brief 返回当前app的权限控制对象
 *
 *  @date 2016-12-12
 *
 *  @return 返回授权数据
 */
- (NSDictionary *)readPermissionConfig;

/**
 *  @brief 返回当前app配置数据源
 *
 *  @date 2017-03-06
 *
 *  @return 返回配置数据
 */
- (NSDictionary *)readAppConfig;

/**
 *  @brief 返回当前资源管理中指定url的离线缓存
 *
 *  @date 2017-03-06
 *
 *  @return 自定义离线数据源
 */
- (NAMAppResponse *)appResponseForUrl:(NSString *)url;
@end
