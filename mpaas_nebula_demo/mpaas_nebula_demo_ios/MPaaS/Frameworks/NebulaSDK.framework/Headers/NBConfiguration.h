//
//  NBServiceConfiguration.h
//  NBService
//
//  Created by chenwenhong on 15/8/21.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

// 服务器环境
typedef NS_ENUM(NSUInteger, NBEnvironment) {
    NBEnvironment_Online = 0, // 线上
    NBEnvironment_Pre, // 预发
    NBEnvironment_Test, // 测试
    NBEnvironment_Dev, // 开发
    NBEnvironment_Custom,//自定义
};

// 渠道
typedef NS_ENUM(NSUInteger, NBChannel) {
    NBChannel_Offical = 0,
    NBChannel_RC,
};

@interface NBConfiguration : NSObject

// common
@property(nonatomic, assign) NBEnvironment         environment; // default is `NAMEnvironment_Online`，服务器环境
@property(nonatomic, assign) NBChannel             channel; // default is `NAMChannel_Offical`，应用渠道
@property(nonatomic, copy) NSString                *clientBundleId; // defult is empty，请填写客户端id（bundleId）
@property(nonatomic, readonly, copy) NSString      *platform; // default is ios
@property(nonatomic, readonly, copy) NSString      *sdkVersion;
@property(nonatomic, copy) NSString                *clientVersion; // default is 1.0.0.0，请填写
@property(nonatomic, readonly, copy) NSString      *systemVersion;

// ui class
@property(nonatomic, strong) Class                  viewControllerClass; // default is NBViewController
@property(nonatomic, strong) Class                  contentViewClass; // default is NBWebView
@property(nonatomic, strong) Class                  optionsClass; // default is NBOptions. the class must be conforms `NBOptionsProtocol`
@property(nonatomic, readonly, copy) NSString       *defaultUserAgent;
@property(nonatomic, copy) NSString                 *userAgent; // default is defaultUserAgent + common

// app manager
@property(nonatomic, copy) NSString                *documentDirectoryPath; // default is document path
@property(nonatomic, strong) NSArray               *commonResourceAppList; // app_id列表，公共资源包，每个session打开都会有一份公共资源包, default is nil

// urls
@property(nonatomic, copy) NSString                *serverURLString4UpdateApps; // 服务器地址：更新app，default is empty
@property(nonatomic, readonly, copy) NSString      *serverURLString4UpdateConfigs; // 服务器地址：更新配置信息，default is empty

@property(nonatomic, assign) BOOL                  isNeed2VerifyApp; // 是否需要验签,default is YES
@property(nonatomic, assign) BOOL                  canIgnoreSSLError;  //是否忽略SSL证书错误,default is NO
//@property(nonatomic, assign) BOOL                shouldCacheFallback;  //是否会保存fallback缓存,default is NO sdk内部使用，目前已经不需要此属性


//monitor class
@property(nonatomic, strong) Class                 contentViewPageProfileClass;
@property(nonatomic, strong) Class                 pvReportClass;

//plugins
@property(nonatomic, copy) NSString                 *pluginsBundleName;
@property(nonatomic, copy) NSString                 *extraPluginsFilePath;

//WK
@property(nonatomic, assign) int                    WKRetryTimes;

//check
@property(nonatomic, assign) BOOL                   shouldCheckJsApiArguments;
@property(nonatomic, copy)   NSArray                *skipJsApiCheckBlackList;
//@property(nonatomic, assign) BOOL                   shouldCheckTabBarJsonVersion;
@property(nonatomic, assign) BOOL                   shouldCheckMainurlDegrade;
@property(nonatomic, assign) BOOL                   shouldCheckNBSession;

//cache
@property(nonatomic, assign) BOOL                   shouldUseConditionalResponse;
@property(nonatomic, assign) BOOL                   shouldLogResponse;

//URL
@property(nonatomic, assign) BOOL                   shouldGetURLWithNewMethod;

//Swizzle
@property(nonatomic, assign) BOOL                   shouldSwizzleMethod;

//禁用showTitleBar启动参数
@property(nonatomic, assign) BOOL                   shouldeDeprecateShowTitleBar; 

//小程序内嵌h5全局资源匹配开关
@property (nonatomic, strong) NSDictionary          *tinyAppPublicURL;

//WKWebView是否需要针对非http请求派发事件
@property(nonatomic, assign) BOOL                   shouldWKDispatchStartEvent;

//WKWebView不自己弹出提示
@property(nonatomic, assign) BOOL                   skipCustomPrompt;

//容器subview是否派发appResume/appPause事件
@property(nonatomic, assign) BOOL                   shouldSubViewDispatchAppEvent;

//修复外部url打开h5应用时触发resume事件的问题
@property (nonatomic, assign) BOOL                  fixPageResumeAtStart;

//透明弹窗时是否派发事件
@property(nonatomic, assign) BOOL                   shouldDipatchContextPresentEvent;

@property(nonatomic, copy)   NSArray                *embedWebViewSetOptionMenuWhiteList;

+ (instancetype)alloc UNAVAILABLE_ATTRIBUTE;

- (instancetype)init UNAVAILABLE_ATTRIBUTE;

- (id)copy UNAVAILABLE_ATTRIBUTE;

+ (instancetype)allocWithZone:(struct _NSZone *)zone UNAVAILABLE_ATTRIBUTE;

+ (instancetype)new UNAVAILABLE_ATTRIBUTE;

/**
 *  @brief 获取默认service配置
 *
 *  @date 2015-08-21
 *
 *  @return 返回默认的配置
 */
+ (instancetype)defaultConfiguration;

/*!
 *  应用信息相关配置
 */
- (NAMConfiguration *)appConfig;

/**
 *  @brief 根据key值获取配置内容
 *
 *  @date 2015-10-08
 *
 *  @param aKey 配置的key
 *
 *  @return 返回字符串类型的配置，若类型不匹配，返回nil
 */
- (NSString *)stringValueForKey:(NSString *)aKey;

/**
 *  @brief 根据key值获取配置内容
 *
 *  @date 2015-10-08
 *
 *  @param aKey 配置的key
 *
 *  @return 返回数组类型的配置，若类型不匹配，返回nil
 */
- (NSArray *)arrayValueForKey:(NSString *)aKey;

/**
 *  @brief 根据key值获取配置内容
 *
 *  @date 2015-10-08
 *
 *  @param aKey 配置的key
 *
 *  @return 返回字典类型的配置，若类型不匹配，返回nil
 */
- (NSDictionary *)dictionaryValueForKey:(NSString *)aKey;

@end

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
    
    NBConfiguration * NBServiceConfigurationGet();
    
#ifdef __cplusplus
}
#endif // __cplusplus
