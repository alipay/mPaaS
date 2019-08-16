//
//  DTRpcInterface.h
//  APMobileNetwork
//
//  Created by shenmo on 5/3/16.
//  Copyright © 2016 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@class DTRpcMethod;

@interface DTRpcInterface : NSObject

@property(atomic,strong) NSDictionary* mPaaSPrivateHeaders;     //mPaaS特有，配置中需要加的私有头
/**
 *  非对称加密
 *  AsymAlgorithmNone
 *  AsymAlgorithmRSA
 *  AsymAlgorithmECC
 *  AsymAlgorithmSM2
 */
typedef enum {
    AsymAlgorithmNone = 0,
    AsymAlgorithmRSA,
    AsymAlgorithmECC,
    AsymAlgorithmSM2,
}AsymAlgorithm;

/**
 *  获取单例
 */
+ (instancetype)sharedInstance;

#pragma mark - 配置方法，通过Category覆盖以下方法实现应用的自定义配置

/**
 *  拉取Rpc时使用的应用Id，默认实现为
 *      [[[NSBundle mainBundle] infoDictionary] objectForKey:@"Product ID"]
 *
 *  @return 应用Id
 */
- (NSString*)productId;

/**
 *  拉取Rpc时使用的应用版本号，默认实现为返回nil
 *
 *  @return 应用版本号
 */
- (NSString*)productVersion;

/**
 *  拉取Rpc时上报的userId。接入应用有自己的账户系统，需要实现这个方法，返回相应的userId值。如果是未登录态，可以返回nil。默认实现为返回nil
 *
 *  @return 当前的userId
 */
- (NSString*)userId;

/**
 *  系统的Cookie默认杀进程后就无效了，这个设置是否应用退出后，Cookie仍然保存。
 *  如果返回YES，还必须实现下面三个方法
        - (void)savePersistentObject:(id)object forKey:(NSString*)key user:(BOOL)user;
        - (id)getPersistentObjectForKey:(NSString*)key user:(BOOL)user;
        - (void)removePersistentObjectForKey:(NSString*)key user:(BOOL)user;
 *  默认返回NO
 */
- (BOOL)storePersistentCookies;

/**
 *  可以使用下面代码全局打开AMRPC功能：
 *      DTRpcConfig *config = [[DTRpcConfig alloc] init];
        config.isAMRPC = YES; // 全局设置打开AMRPC
        [[DTRpcClient defaultClient] setConfig:config forScope:kDTRpcConfigScopeGlobal];
 *  但是即使全局打开，或对某个RPC设置了使用AMRPC。框架在发送请求时，还会再调用下面方法，判断开关状态。如果返回NO，会不使用AMRPC
 *  默认返回YES。
 */
- (BOOL)isAMRPCEnabled;

/**
 *  RPC的服务器地址，默认返回钱包网关。格式为“https://mobilegw.alipay.com/mgw.htm”
 */
- (NSString*)gatewayURL;

/**
 *  RPC的AppId
 */
- (NSString *)AppId;

/**
 *  RPC的Platform
 */
- (NSString *)Platform;

/**
 *  RPC的组件网关服务器地址。格式为“http://alipay.com/mgw.htm”
 */
- (NSString *)uniformRpcGateway;

/**
 *  RPC的WorkspaceId
 */
- (NSString *)WorkspaceId;

/**
 *  RPC的ETag服务器地址，默认返回钱包网关使用的值。格式为“https://mobilegw.alipay.com/rpcetag.html”
 *  一般只需要重写gatewayURL即可，eTagURL系统会自动根据gatewayURL进行修改。
 */
- (NSString*)eTagURL;

/**
 *  实现此方法，RPC会使用应用自定义的超时时间，默认是20秒。如果希望实现WiFi和2G/3G/4G的不同策略，需要覆盖此方法，并配合Reachability实现。
 *
 *  @return NSTimeInterval，单位秒
 */
- (NSTimeInterval)timeoutInterval;

/**
 *  是否使用无线保镖提供的Atlas白盒签名功能，默认为NO。
 *
 *  @return 是否使用
 */
- (BOOL)useAtlasSignMethod;

/**
 *  RPC请求需要加签时，使用这个方法返回签名使用的密钥。默认返回nil。
 *
 *  @return 使用在无线保镖里保存的哪个密钥来签名请求。
 */
- (NSString*)signKeyForRequest:(NSURLRequest*)request;

/**
 *  默认的RPC拦截器容器类名，如果有这个方法，RPC初始化时，会使用这个类创建RPC拦截器。否则需要第三方应用自己设置拦截器。
 *  应用可能有多个RPC拦截器，需要将这些拦截器添加到一个容器拦截器中。所有拦截器，包括容器拦截器都需要实现接口 @protocol DTRpcInterceptor
 */
- (NSString*)commonInterceptorClassName;

/**
 *  最近一次页面点击时间戳，默认实现为调用APRemoteLogging模块的同名方法。
 *  当没有加入日志模块时，会取当前时间。
 *
 *  @return 时间戳
 */
- (unsigned long long)tokenTimestamp;

/**
 *  在将要执行method前会回调该方法，接入应用可以在这里做启动时白名单等功能。
 *  默认为空实现
 */
- (void)willExecuteMethod:(DTRpcMethod*)method params:(NSArray *)params requestHeaderField:(NSDictionary*)field;

/**
 *  持久化缓存的方法，默认为空实现
 */
- (void)savePersistentObject:(id)object forKey:(NSString*)key user:(BOOL)user;

/**
 *  根据key获取持久化的数据
 */
- (id)getPersistentObjectForKey:(NSString*)key user:(BOOL)user;

/**
 *  根据key移除持久化的数据
 */
- (void)removePersistentObjectForKey:(NSString*)key user:(BOOL)user;

/**
 *  读取info.plist里面配置的私有头，主要给mpass使用
 */
- (void)readPrivateHeadersFromPlist;

/**
 注册一个RPC方法使用MPaaS统一的服务地址。
 接入应用一般不需要调用这个方法，这个方法用于内部注册Hotpatch、升级等服务。
 
 @param operationType RPC操作名
 */
- (void)registerUniformRpcOperation:(NSString*)operationType;

/**
 *  是否在 "不需要建立连接的Background Fetch 回调" 中，此时不需要建立连接
 *  冷启动的首次 Background Fetch 还是正常建立连接。
 *  启动之后的 Background Fetch 不需要建立连接
 *  这个方法内部会处理"首次"和"启动之后"的情况。
 *  返回YES ：不建立连接。
 *  返回NO ：建立连接。
 */
- (BOOL)underBackgroundFetch;
/**
 *  管控层开关，默认yes，可通过开关关闭Background Fetch功能
 */
-(BOOL)isBackgroundFetchSwitchOpen;

/**
 *  download是否走spdy的开关
 *
 */
-(BOOL)shouldUseSPDYProxy;

/**
 *  download是否走asi的开关
 *
 */
-(BOOL)shouldUseASIProxy;
/**
 *  特殊rpc能否走特殊通道的开关(控制登录模块是否使用)
 *
 */
-(BOOL)isSpecialChannelOpen;
/**
 *  特殊rpc能否走特殊通道的灰度开关(网络层功能灰度)
 *
 */
-(BOOL)isSpecialChannelGrayHit;
/**
 *  资源文件日志是否打印
 *
 */
-(BOOL)isResourceLogPrint;
/**
 *  request head中是否添加无线保镖安全数据wua
 *
 */
-(BOOL)isAddWua;

/**
 *  对rpc大小进行管控
 *  method:获取operationType
 *  size:获取req或resp的大小
 *  isReq:是req或resp
 */
-(id)rpcSizeControl:(DTRpcMethod*)method size:(NSUInteger)len isReq:(BOOL)req;
/**
 *  是否启用loginrefresh模块
 *
 */
-(BOOL)isLoginRefresh;
/**
 *  是否需要设置过滤标志位
 *
 */
-(BOOL)isFetchFilter;


/**
 *  Header中是否添加App显示标记
 */
-(BOOL)isAddAppVisibleFlag;

/**
 *  Header中的App显示标记。
 *  目前值有 0 或 1 。0表示后台，1表示前台。
 */
-(NSString*)appVisibleFlag;
/**
 *  非对称加密算法
 */
-(AsymAlgorithm)asymAlgorithm;
/**
 *  是否需要加密
 */
-(BOOL)isCrypt;
/**
 *  获取publicKey
 */
-(NSString *)getPubKey;
/**
 *  是否在网关白名单 只有在白名单才会加密
 */
-(BOOL)isGWWhiteList:(NSString *)gateway;
/**
 *  是否使用ip直连
 */
-(BOOL)isHTTPDNS;

/**
 *  get group name
 */
-(NSString*)groupName:(NSString*)url;

@end
