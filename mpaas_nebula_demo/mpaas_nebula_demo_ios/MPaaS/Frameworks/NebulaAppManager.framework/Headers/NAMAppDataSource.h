//
//  H5AppDataSource.h
//  H5AppManager
//
//  Created by chenwenhong on 15-4-28.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NebulaAppDataSourceProtocol.h"
#import "NebulaAppProtocol.h"

// App数据响应对象: 离线数据对象
@class NAMAppDataSource;
@interface NAMAppResponse : NSObject<NebulaAppResponseProtocol>

@property (nonatomic, copy) NSString *absoluteUrlString;    // 绝对地址
@property (nonatomic, copy) NSString *mimeType;             // mimeType
@property (nonatomic, strong) NSData *contentData;          // content data
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wincompatible-property-type"
@property (nonatomic, weak) NAMAppDataSource *dataSource;   // dataSource
#pragma clang diagnostic push
@property (nonatomic, strong) NSDictionary *headers;

@end

// App数据源对象: 离线数据的获取
@interface NAMAppDataSource: NSObject <NebulaAppDataSourceProtocol>
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wincompatible-property-type"
@property (nonatomic, readonly, strong) NAMApp *app;
#pragma clang diagnostic pop
@property (nonatomic, readonly, assign) BOOL verifyResult;
@property (nonatomic, strong) NSMutableArray *loadedSubPackageList;

/**
 *  @brief 创建一个H5App数据源，步骤：1.验签app 2.验签成功，将app内容全部加载至内存
 *
 *  @date 2015-04-28
 *
 *  @param nbl_id 应用id
 *
 *  @return 返回数据源对象
 */
- (instancetype)initWithApp:(NAMApp *)app;

/**
 *  @brief 加载app离线数据
 *
 *  @date 2015-09-17
 *
 *  @param verify 是否验签
 *
 *  @return 返回是否加载成功
 */
- (NSInteger)loadAppData:(BOOL)needVerifyApp;

/**
 *  @brief app启动初始url
 *
 *  @date 2015-04-29
 *
 *  @return 返回完整的url str
 */
- (NSString *)launchUrlString:(NSString *)urlString;

/**
 *  @brief 根据相对路径，得到绝对url路径
 *
 *  @date 2015-04-28
 *
 *  @param urlString 相对、绝对路径
 *
 *  @return 返回绝对路径
 */
- (NSString *)absoluteUrlString:(NSString *)urlString;

/**
 *  @brief 获取指定url（相对、绝对）的response
 *
 *  @date 2015-04-28
 *
 *  @param urlString 相对、绝对路径
 *
 *  @return 返回response，nil表示未能获取到离线数据（此时应该走网络）
 */
- (NAMAppResponse *)responseWithUrlString:(NSString *)urlString;

/**
 *  @brief 验签安装文件
 *
 *  @param alert 验签失败时是否显示提示框
 *
 *  @return BOOL 是否验签成功.如果验签失败,会将应用安装目录删除,如果为增量包则会删除增量字段,下次触发下载时下载全量包
 */
- (BOOL)verifyWithAlert:(BOOL)alert;

/**
 *  @brief 返回当前app的权限控制对象
 *
 *  @date 2016-12-12
 *
 *  @return 返回授权数据
 */
- (NSDictionary *)readPermissionConfig;

/**
 *  @brief 返回当前app的配置
 *
 *  @date 2017-03-06
 *
 *  @return 返回配置数据
 */
- (NSDictionary *)readNBAppConfig;

/**
 *  @brief 通过指定key(路径)获取内存中对应离线内容
 *         调用前需使用loadAppData加载离线资源
 *
 *  @param key 路径
 *  @return 返回内存中对应离线内容
 */
- (NSData *)tarDataForKey:(NSString *)key;



/**
 @brief 合并子包数据到主包tarData

 @param subTarData 子包数据
 */
- (void)mergeTarData:(NSDictionary *)subTarData;

@end
