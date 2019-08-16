//
//  NAMConfiguration.h
//  NebulaAppManager
//
//  Created by chenwenhong on 15/9/16.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NAMProtocol.h"


// 服务器环境
typedef NS_ENUM(NSUInteger, NAMEnvironment) {
    NAMEnvironment_Online = 0,  // 线上
    NAMEnvironment_Pre,         // 预发
    NAMEnvironment_Test,        // 测试
    NAMEnvironment_Dev,         // 开发
};

// 渠道
typedef NS_ENUM(NSUInteger, NAMChannel) {
    NAMChannel_Offical = 0,     // 正式
    NAMChannel_RC,              // RC
};


@interface NAMConfiguration : NSObject

@property (nonatomic, readonly, copy) NSString *sdkVersion;                     // SDK版本号
@property (nonatomic, readonly, copy) NSString *systemVersion;                  // 设备系统版本号
@property (nonatomic, readonly, copy) NSString *platform;                       // 平台:ios
@property (nonatomic, readonly, assign) NSTimeInterval updateReqRate;           // 单个应用更新频率,过期后触发异步更新, default:30分钟
@property (nonatomic, readonly, assign) NSTimeInterval preReqRate;              // 单个应用'前置'更新频率,过期后触发同步更新, default:30天
@property (nonatomic, readonly, assign) NSTimeInterval forcePreReqRate;         // 单个应用'前置'强制更新频率,过期后触发同步强制更新，default:0（无效值）
@property (nonatomic, readonly, assign) NSTimeInterval limitReqRate;            // 单个应用限流频率, default:10分钟
@property (nonatomic, readonly, assign) NSTimeInterval resMainDocInvalidTime;   // 资源应用主文档失效时间, default:3天
@property (nonatomic, readonly, strong) NSMutableArray *commonAppList;          // 公共应用列表

@property (nonatomic, assign) NSInteger appPoolCapacity;                        // 应用池容量, default:3
@property (nonatomic, assign) NAMEnvironment environment;                       // 服务器环境, default:NAMEnvironment_Online
@property (nonatomic, assign) NAMChannel channel;                               // 应用渠道, default:NAMChannel_Offical
@property (nonatomic, assign) BOOL cacheReqTime;                                // 是否缓存更新时间,默认:否
@property (nonatomic, assign) BOOL userMode;                                    // 用户模式, 如需使用灰度功能等用户维度的功能此值必须配置YES, default:NO
@property (nonatomic, assign) NSTimeInterval prepareTimeLimit;                  // 准备应用超时时间, default:10s

@property (nonatomic, assign) BOOL enableSceneCheck;                            //是否检查服务器下发的scene字段，默认YES

@property (nonatomic, copy) NSString *internalConfigPath;                       // 配置文件路径,默认NAMConfig.plist
@property (nonatomic, copy) NSString *documentDirectoryPath;                    // 沙盒根目录, default:Documents
@property (nonatomic, copy) NSString *dataRootPath;                             // 数据总路径, default:Documents/NAMAPP
@property (nonatomic, copy) NSString *unzipRootPath;                            // 解压总路径, default:Documents/NAMAPP_UNZIP
@property (nonatomic, copy) NSString *downloadRootPath;                         // 下载总路径, default:Documents/NAMAPP_AMR
@property (nonatomic, copy) NSString *templateConfigRootPath;                   // 模版小程序配置信息总路径，default:Documents/TEMPLATECONFIG
@property (nonatomic, copy) NSString *presetApplistPath;                        // 预置应用列表路径, default:nil
@property (nonatomic, copy) NSString *presetAppPackagePath;                     // 预置离线资源包路径, default:nil
@property (nonatomic, copy) NSString *insideCustomPresetBundlePath;                 // Inside运行客户自定义自己的预制包bundle
@property (nonatomic, copy) NSString *insideCustomPresetApplistPath;                 // Inside运行客户自定义预置应用列表路径
@property (nonatomic, copy) NSString *clientBundleId;                           // 客户端id, default:nil
@property (nonatomic, copy) NSString *clientVersion;                            // 客户端版本号, default:1.0.0.0
@property (nonatomic, copy) NSString *serverURLString4UpdateApps;               // 服务器地址:更新app
@property (nonatomic, strong) NSDictionary *grayRules;                          // 业务方自定义灰度规则列表
@property (nonatomic, strong) NSString *signPublicKey;                          // 业务方指定的验证包签名的公钥

@property (nonatomic, strong) NSDictionary *performanceOpt;                     //性能优化配置开关

/**
 *  自定义代理
 */
@property (nonatomic, strong) id<NAMDynamicConfigProtocol> dynamicConfigManager;    // 动态配置
@property (nonatomic, strong) id<NAMDownloadProtocol> downloadManager;              // 下载
@property (nonatomic, strong) id<NAMZipArchiveProtocol> zipArchiveManager;          // 解压
@property (nonatomic, strong) id<NAMDataStorageProtocol> dataStorage;               // 存储
@property (nonatomic, strong) id<NAMRequestProtocol> requestManager;                // 请求
@property (nonatomic, strong) id<NAMLogProtocol> logManager;                        // Log
@property (nonatomic, strong) id<NAMAppInterface> appInterface;                     // App相关接口
@property (nonatomic, strong) id<NAMCreditProtocol> creditManager;                  // 智能列表

/**
 *  动态根据配置文件配置代理
 */
- (void)presetMobileRuntime;

/**
 *  获取客户端配置
 */
- (id)serverConfigValueForKey:(NSString *)key  class:(Class)valueClass;

/**
 *  渠道名
 *
 *  Rc包: rc
 *  其他: offical
 */
- (NSString *)channelName;

/**
 *  环境名
 *
 *  预发环境:preppub 
 *  其他:production
 */
- (NSString *)environmentName;

/**
 *  获取通过代理过滤过的公共资源列表
 *
 *  可通过代理函数:supportNebulaApp配置是否支持为NebulaApp,如果为配置该协议默认返回配置的公共列表
 *  @return 过滤后的公共应用id及对应版本号, e.g. {'20000196':'1.0.0'}
 */
- (NSDictionary *)filteredCommonApplist;

/**
 *  添加公共资源应用ID
 *
 *  @param list 应用id列表, e.g. ['20000196','20000202']
 */
- (void)addCommonApps:(NSArray *)list;

@end



#pragma mark - Unavalilable

@interface NAMConfiguration (UNAVAILABLE)

/**
 *  不可分配内存空间
 */
+ (instancetype)new UNAVAILABLE_ATTRIBUTE;

/**
 *  不可初始化
 */
- (instancetype)init UNAVAILABLE_ATTRIBUTE;

/**
 *  不可重写
 */
- (id)copy UNAVAILABLE_ATTRIBUTE;

@end

#ifdef __cplusplus
extern "C" {
#endif
    
    NAMConfiguration * NAMConfigurationGet();
    
#ifdef __cplusplus
}
#endif
