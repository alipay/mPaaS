//
//  MPFakeOpenPlatform.h
//  NebulaAppBiz
//
//  参考 OpenPlatfrom/OPAppManageService.h
//
//  Created by 张光宇 on 2019/2/27.
//  Copyright © 2019 Alipay. All rights reserved.
//
#import <Foundation/Foundation.h>
#import "OpenPlatfromAllRPC.h"



typedef enum {
    ACAppNativeApp,         //  native应用
    ACAppH5App,             //  H5容器应用
    ACAppIndependantApp,    //  第三方应用
    ACAppHCFApp,            //  鸟巢应用
    ACAppTinyApp,           //  小程序
} ACAppType;


// app标记，目前用户标识应用特性
typedef enum {
    ACAppSourceTagOthers = 0,       // 其它，包括外部小程序及其它
    ACAppSourceTagInnerTinyApp = 1, // 内部小程序
    ACAppSourceTagResource = 2,     // 资源型应用
    ACAppSourceTagTemplate = 3,     // 模板小程序
    ACAppSourceTagPlugin = 5,       // 插件小程序
    ACAppSourceTagAliGroup = 6,     // 阿里集团小程序
} ACAppSourceTag;

typedef enum {
    ACAppStatusOnline = 0,  //  上线
    ACAppStatusUninstall,   //  未安装
    ACAppStatusInstalling,  //  安装中
    ACAppStatusOffline,     //  下线
}ACAppStatusCode;

#define OPCommonRequestHandleProtocol NSObject
#define APSearchDataProtocol NSObject

typedef void(^ACAppServiceOpenAppProcess)(NSUInteger tag, id info);   //  启动过程回调，tag：过程标识，info：附属信息
typedef void(^ACAppServiceOpenAppFailure)(NSError *error);  //  启动失败回调，error：错误信息
typedef void(^ACAppServiceOpenAppSuccess)(void);            //  启动成功回调

@interface ACApp : NSObject <NSCopying, APSearchDataProtocol>

//  基本信息
@property (nonatomic, strong) NSDictionary *extra;                //  H5应用配置信息
@property (nonatomic, strong) NSString *appId;                    //  应用id
@property (nonatomic, strong) NSString *name;                     //  应用名称
@property (nonatomic, strong) NSString *version;                  //  应用版本
@property (nonatomic, strong) NSString *slogan;                   //  应用宣传语
@property (nonatomic, strong) NSString *desc;                     //  应用描述
@property (nonatomic, strong) NSString *iconUrl;                  //  图标链接
@property (nonatomic, strong) NSString *pkgSize;                  //  包大小
@property (nonatomic, strong) NSString *pkgUrl;                   //  下载地址
@property (nonatomic, strong) NSString *pkgType;                  //  包类型
@property (nonatomic, strong) NSString *incrementPkgUrl;          //  增量包下载地址
@property (nonatomic, strong) NSString *h5AppCdnBaseUrl;          //  H5在线fallback基地址
@property (nonatomic, strong) NSString *thirdPkgName;             //  第三方包名
@property (nonatomic, strong) NSString *schemeUri;                //  跳转地址
@property (nonatomic, strong) NSString *md5;                      //  应用包md5码
@property (nonatomic, strong) NSString *pageUrl;                  //  自定义详情页地址
@property (nonatomic, strong) NSString *appSource DEPRECATED_ATTRIBUTE; //  应用来源
@property (nonatomic, assign) BOOL autoStatus;                    //  是否强制安装
@property (nonatomic, assign) BOOL alipayApp;                     //  是否支付宝应用
@property (nonatomic, assign) BOOL needAuthorize;                 //  是否需要授权
@property (nonatomic, assign) BOOL autoAuthorize;                 //  是否自动授权

//  布局信息 (展台相关)
@property (nonatomic, strong) NSString *stageExtProp;             //  安全展台校验字段
@property (nonatomic, assign) BOOL movable;                       //  是否可移动
@property (nonatomic, assign) BOOL display;                       //  是否隐藏
//@property (nonatomic, assign) ACAppRecommendStatus recommendStatus DEPRECATED_ATTRIBUTE; //  应用NEW标记

// 9.6.8新增
@property (nonatomic, strong) NSString *bundleExtra;
@property (nonatomic, strong) NSString *stageSchemeUri;

// 10.0.12新增，标记应用是否为小程序
@property (nonatomic, assign) BOOL tinyApp;

//  预装时的默认图标，可能为空（主线程调用）
//  ----获取预装默认图标时，支持分展台获取，stageCode非必填参数（stageCode为“父展台”code！！！）
//  ----MarketStage直接调用defaultIcon接口即可，其它展台必须传stageCode
//  ----stageCode为nil时，查找以appId命名的预装图片；非nil时查找以appId_stageCode命名的预装图片, 查找不到时再次查找以appId命名的图片
//  ----isForce 为YES时, 只查找命名为appId_stageCode的图片, 默认为NO
- (UIImage *)defaultIcon;
- (UIImage *)defaultIcon:(NSString *)stageCode;
- (UIImage *)defaultIcon:(NSString *)stageCode isForce:(BOOL)isForce;

/**
 *  静态方法，取应用默认图标。（主线程调用）
 *  目前预置图标的展台有：应用市场（marketStage）
 *                    社交（contactStage，groupStage，socialContact）
 *                    财富首页（WealthHome）
 *
 *  @param appId 应用id
 *  @param stageName 父展台code（应用市场展台传nil，其它展台必须传入）
 *
 *  @return 默认图标（UIImage）
 */
+ (UIImage *)defaultIconForApp:(NSString *)appId stageName:(NSString *)stageName;
 

//  应用可以启动
- (BOOL)isInstalled;

//  资源解压缩路径
- (NSString *)unzipFilePath;

//  应用类型
@property (nonatomic, assign) BOOL appType;
@property (nonatomic, assign) ACAppSourceTag appSourceTag;
@property (nonatomic, assign) ACAppStatusCode appStatus;

@end

@interface OPAppManageService : NSObject

- (void)installApp:(ACApp *)app param:(NSDictionary *)param process:(ACAppServiceOpenAppProcess)process success:(ACAppServiceOpenAppSuccess)success failure:(ACAppServiceOpenAppFailure)failure;

- (ACApp *)findApp:(NSString *)appId stageCode:(NSString *)stageCode;

- (void)requestAppBaseInfos:(NSArray *)appIds
                    success:(void(^)(NSArray<ACApp *>*))success
                    failure:(void(^)(NSError *error))failure __deprecated_msg("废弃，业务请勿继续使用");

/**
 *  应用信息、包信息合并rpc请求接口（限制调用）
 *
 *  @param appIds 应用id列表
 *  @param onSuccess 成功回调
 *  @param onFail 失败回调
 *
 *  @return void
 */
- (void)requestCommonAppInfos:(NSArray *)appIds
                      success:(void(^)(void))onSuccess
                      failure:(void(^)(NSError *error))onFail;
/**
 *  调用“应用中心+包管理”公用RPC
 *  ## 该接口仅供包管理调用 ##
 *  ## 该接口在当前线程同步执行，且不会catch异常，需要调用方在子线程调用并处理异常 ##
 *
 *  @param reqType     请求类型：包应用场景:  1包全量  2 包非全量 3 hpmweb
 *  @param appIds      将请求的应用基础信息appId列表，可为空
 *  @param packInfoReq 包请求对象
 *
 *  @return rpc_response
 */
- (mobileappconfigAppBaseInfoRes *)queryAppInfoWithReqType:(int)reqType
                                                    appIds:(NSArray *)appIdList
                                               packInfoReq:(mobileappconfigPackInfoReq *)packInfoReq;

/**
 *  注册“应用中心+包管理”公用RPC处理器delegate
 *  ## 该接口仅供包管理调用 ##
 *
 *  @see OPCommonRequestHandleProtocol
 *  @param delegate
 *
 *  @return void
 */
- (void)registerCommonRequestHandleDelegate:(id<OPCommonRequestHandleProtocol>)delegate;


- (NSDictionary *)currentAppVersions:(NSArray *)appIds;

- (BOOL)updateDevelopingAppInfo:(NSDictionary *)dicInfo;

- (NSArray<NSString *> *)pkgVersionsWithDevAppId:(NSString *)appId;

@end
