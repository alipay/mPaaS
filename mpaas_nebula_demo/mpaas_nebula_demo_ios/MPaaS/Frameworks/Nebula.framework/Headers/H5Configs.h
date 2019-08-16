//
//  H5Configs.h
//  H5Service
//
//  Created by tgf on 14-3-20.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

BOOL          H5ConfigServiceBool(NSString *key);    // BOOLEAN类型开关
NSInteger     H5ConfigServiceInteger(NSString *key); // 整型类型开关
double        H5ConfigServiceDouble(NSString *key);  // 浮点类型开关
NSString     *H5ConfigServiceString(NSString *key);  // 字符串类型开关
NSArray      *H5ConfigServiceArray(NSString *key);   // 数组类型开关
NSDictionary *H5ConfigServiceDict(NSString *key);    // 字典类型开关
BOOL H5IsSwitchOn(NSString* switchKey, NSString *appId, BOOL defaultValue);//form tinyappservice

@interface H5Configs : NSObject


@property(nonatomic, readonly) NSDictionary *safePayUrls; // ok
@property(nonatomic, readonly) NSArray *aliWhitelist;// 8.5及以后使用 // ok
@property(nonatomic, readonly) NSArray *alipayWhitelist;// 9.9.9及以后使用 // ok
@property(nonatomic, readonly) NSArray *seriousAliWhitelist;// 9.9.9及以后使用 // ok
@property(nonatomic, readonly) NSArray *partnerWhitelist;// 8.5及以后使用 // ok
@property(nonatomic, readonly) NSArray *rpcWhitelist;// 9.9.9及以后使用 // ok


@property(nonatomic, readonly) BOOL entranceMainSwitch; // ok
@property(nonatomic, readonly) BOOL entranceJsApiSwitch; // ok
@property(nonatomic, readonly) BOOL entranceSsoLoginSwitch; // ok

@property(nonatomic, readonly) NSDictionary *requestSsoLoginSetting; // ok

@property(nonatomic, readonly) BOOL canEnableAlipayAutoLogin; // ok

@property(nonatomic, readonly) NSArray *dynamicScriptRulesGroups; // ok
@property(nonatomic, readonly) NSArray *dynamicScriptSyncRulesGroups; // ok
@property(nonatomic, readonly) NSArray *openRpcWhiteList; // ok

@property(nonatomic, readonly) int preRenderMax; // ok

@property(nonatomic, readonly) BOOL canEnableInterceptAuth; // ok
@property(nonatomic, readonly) NSArray *interceptAuthBlackList; // ok
@property(nonatomic, readonly) NSString *interceptAuthWhiteList; // ok

@property(nonatomic, readonly) NSString *shareChannels; // ok


@property(nonatomic, readonly) NSDictionary *competitiveList;
@property(nonatomic, readonly) BOOL canEnableCustomAnimator;
@property(nonatomic, readonly) NSRegularExpression *titleReg;

//入口RPC业务场景白名单
@property(nonatomic, readonly) BOOL shouldUseNewAuthRPC;
@property(nonatomic, readonly) NSString *supportAuthScopeList;

@property(nonatomic, readonly) NSArray *parseHostList;

@property(nonatomic, readonly) BOOL shouldUseDiskCache;
@property(nonatomic, readonly) NSArray *SSLVerifyDomain;

@property(nonatomic, readonly) NSDictionary *debugModeSwitch;

//埋点日志相关开关
@property(nonatomic, readonly) NSDictionary *h5AutoLoggerSwitch; // ok
@property(nonatomic, readonly) NSArray *allowedRemoteLogAppIdListWhenPageDestruct;
@property(nonatomic, readonly) NSString *imageMonitor;
@property(nonatomic, readonly) BOOL logNebulaTechEnable;
@property(nonatomic, readonly) NSArray *logWebAppWhitelist;
@property(nonatomic, readonly) NSDictionary *logNewBlankScreenConfig;
@property(nonatomic, readonly) NSArray *massProxyWhitelist;
@property(nonatomic, readonly) NSArray *massProxyMainDocumentWhitelist;
@property(nonatomic, readonly) NSArray *documentRefererWhitelist;




/**
 *  新免登接口开关
 *  aliAutoLoginWhiteList:      白名单
 *  aliAutoLoginSwitch:         全量开、全量关、走白名单
 *  aliAutoLoginSpecialChannel: 特别线程通道, 业务层仅资源同步免登时候调用, 免登sdk默认都走特殊通道, 默认:YES
 */
@property(nonatomic, readonly) NSArray *aliAutoLoginWhiteList;
@property(nonatomic, readonly) NSString *aliAutoLoginSwitch;
@property(nonatomic, readonly) BOOL aliAutoLoginSpecialChannel;
@property(nonatomic, readonly) BOOL aliAutoLoginDefaultBind;
@property(nonatomic, readonly) BOOL aliAutoLoginBindNewVC;

// 芝麻信用登录是否使用Flag限制频次开关
@property(nonatomic, readonly) BOOL zhimaLoginFlagSwitch;

// WebP 转换相关配置
@property(nonatomic, readonly) BOOL enableWebPTranslation;
@property(nonatomic, readonly) NSArray *cdnDomainsForWebPTranslation;
@property(nonatomic, readonly) NSArray *imageTypesForWebPTranslation;
@property(nonatomic, readonly) NSDictionary *rpcAppKeyConfig;

// iOS 10拦截发RPC降级开关
@property(nonatomic, readonly) BOOL canInterceptSinceiOS10;
@property(nonatomic, readonly) BOOL asyncAliAutoLoginSinceiOS10;
@property(nonatomic, readonly) NSDictionary *sinceIOS10InterceptConfig;

// 紧急止血页面检测开关
@property(nonatomic, readonly) BOOL enableBloodCheckState;

// 紧急止血session应用版本检测开关
@property(nonatomic, readonly) BOOL enableBloodCheckSessionVer;

// WebView 侧滑GoBack
@property(nonatomic, readonly) NSDictionary *webViewPanBackConfig; // testing

@property(nonatomic, readonly) NSDictionary *rpcExceptionConfig;    // 处理H5业务RPC总开关
@property(nonatomic, readonly) BOOL enableHandleRpcException;       // 是否处理H5业务方异常

// SPDYProxyConfig
@property(nonatomic, readonly) BOOL         isSPDYProxyHttpsOpen;
@property(nonatomic, readonly) BOOL         isSPDYProxyGo;
@property(nonatomic, readonly) BOOL         isSPDYProxyGoAs;
@property(nonatomic, readonly) NSArray      *SPDYProxyForceHostWhiteList;
@property(nonatomic, readonly) NSArray      *SPDYProxyHostWhiteList;
@property(nonatomic, readonly) NSArray      *SPDYProxyHostBlackList;
@property(nonatomic, readonly) NSArray      *SPDYProxyHostAsWhiteList;
@property(nonatomic, readonly) NSArray      *SPDYProxyHostAsBlackList;
@property(nonatomic, readonly) BOOL         isSPDYProxyAbroadGo;
@property(nonatomic, readonly) NSArray      *SPDYProxyResourceHostBlackList;
@property(nonatomic, readonly) NSArray      *SPDYProxyResourceTypeList;
@property(nonatomic, readonly) NSDictionary *networkParams;
@property(nonatomic, readonly) NSArray      *SPDYProxyTinyResourceAppIdBlackList;


//jailbreak
@property(nonatomic, readonly) BOOL         shouldVerifyApp;

// 入口检测开关
@property(nonatomic, readonly) BOOL         enableCheckEntrance;
@property(nonatomic, readonly) BOOL         enableSchemeWithOpenUrl;
@property(nonatomic, readonly) BOOL         enableStartAppWithScheme;

// landing页去除功能开关
@property(nonatomic, readonly) BOOL stripLandingEnable;

//
@property(nonatomic, readonly) NSDictionary *jsApiPermissionConfig;
@property(nonatomic, readonly) BOOL shouldCheckSpecialPermission;
@property(nonatomic, readonly) NSDictionary *secondjsApiPermissionConfig;

//
@property(nonatomic, readonly) NSArray *resetUAConfig;

//

//WK
@property(nonatomic, readonly) BOOL canEnableWK;
@property(nonatomic, readonly) NSArray *tinyAppWKBlackList;
@property(nonatomic, readonly) NSArray *appOpenWithWKWhiteList;
@property(nonatomic, readonly, assign) CGFloat  WKCheckAliveDuration;
@property(nonatomic, readonly, assign) int  WKRetryTimes;
@property(nonatomic, readonly) BOOL shouldWKUseShareProcess;
@property(nonatomic, readonly) BOOL shouldWKShowForceExitTip;
@property(nonatomic, readonly) BOOL shouldWKSyncMainProcessCookie;
@property(nonatomic, readonly) NSArray *appForceOpenWithWKWhiteList;
@property(nonatomic, readonly) NSArray *WKSKipVersionList;
@property(nonatomic, readonly) NSArray *appOnlineOpenWithWKWhiteList;
@property(nonatomic, assign, readonly) BOOL  WKShouldRunsAtForegroundPriority;
@property(nonatomic, assign, readonly) BOOL  WKShouldUseSubViewMode;
@property(nonatomic, assign, readonly) BOOL  WKShouldUseNewPullRefresh;
@property(nonatomic, assign, readonly) BOOL  WKShouldUseNewMethodSyncCookie;

//app keep alive
@property(nonatomic, readonly) BOOL shouldAppKeepAlive;
@property(nonatomic, readonly) NSTimeInterval appKeepAliveDuration;
@property(nonatomic, readonly) NSArray *notKeepAliveSceneList;

@property(nonatomic, readonly) BOOL shouldCloseWhenAlipaySchemeRedirect;

//JSCBridge
@property(nonatomic, readonly) BOOL shouldUseJSCInjectJS;
@property(nonatomic, readonly) NSArray *useJSCInjectJSHostBlackList;

// BizWindow
@property(nonatomic, readonly) NSDictionary *bizWindowUrlConfig;

// BizService
@property(nonatomic, readonly) NSDictionary *bizServiceConfig;

// error page config
@property(nonatomic, readonly) NSDictionary *errorPageConfig;

// 炫酷loading动画 #1034
@property(nonatomic, readonly) NSDictionary *coolLoadingConfig;

// kH5LdcLevelConfig
@property(nonatomic, readonly) NSDictionary *ldcLevelConfig;

@property(nonatomic, readonly, assign) BOOL shouldStripWindowHeight;

@property(nonatomic, readonly) NSString *cookieKeepWhiteList;

// keyboard
@property(nonatomic, readonly) BOOL shouldH5UseCustomKeyboard;
@property(nonatomic, readonly) NSArray *keyBoardAppIdWhiteList;
@property(nonatomic, readonly) NSArray *keyBoardFixElementAppIdWhiteList;



@property(nonatomic, readonly) NSArray  *jsapiResultErrorLogBlackList;
@property(nonatomic, readonly) BOOL  shouldTabChangeSupportWaitRender;
@property(nonatomic, readonly) BOOL  shouldEnableSnapshotDiagnose;

@property(nonatomic, readonly) BOOL  shouldEnableHAR;


//forceExitConfig
@property(nonatomic, readonly) BOOL  shouldForceExit;
@property(nonatomic, readonly, assign) CGFloat forceExitDuration;

@property(nonatomic, readonly, assign) BOOL shouldUsePreRender;
@property(nonatomic, readonly, assign) BOOL shouldUsePreRender4TabBar;
@property(nonatomic, readonly) NSString *prerenderPage;

@property(nonatomic, readonly) NSDictionary *tabBarOptimizeConfig;
@property(nonatomic, readonly) NSDictionary *abTestConfig;

// Transparent switch
// enable transparent animate close animation
@property(nonatomic, readonly) BOOL shouldTransCloseAnimate;

//httpRequestConfig
@property(nonatomic, readonly) BOOL shouldDelayHttpRequest;
@property(nonatomic, readonly) float delayHttpRequestDration;

//jsapi check
@property(nonatomic, assign, readonly) BOOL      shouldCheckJsApiArguments;
@property(nonatomic, readonly)   NSArray   *skipJsApiCheckBlackList;

//urlsession
@property(nonatomic, assign, readonly) BOOL      shouldUseNSURLSession;
@property(nonatomic, readonly)   NSArray   *nsURLSessioneUrlWhiteList;
@property(nonatomic, readonly)   float   nsURLSessionLogRatio;

//collectDestroyJsApi
@property(nonatomic, readonly)   NSDictionary   *collectDestroyJsApiConfig;

//旧的通讯消息替换有问题，换用新方法
@property(nonatomic, readonly)   BOOL shouldUseNewMessageReplacing;


@property(nonatomic, readonly)   NSDictionary *blankCheckSampleConfig;

//proxy request
@property(nonatomic, readonly)   BOOL shouldProxyBridgeRequest;


// cors
@property(nonatomic, readonly) NSDictionary *corsConfig;

//normal
@property(nonatomic, readonly)   BOOL shouldUseNetworkIndicator;
@property(nonatomic, readonly)   BOOL shouldHookWebGL;
@property(nonatomic, readonly)   BOOL shouldSendAppResumeEvent;
@property(nonatomic, readonly)   NSArray *jsApiDelayCallList;
@property(nonatomic, readonly)   BOOL shouldUseConditionalResponse;
@property(nonatomic, readonly)   BOOL shouldLogResponse;
@property(nonatomic, readonly)   BOOL shoulduseNewSnapshot;
@property(nonatomic, readonly)   BOOL shouldGetURLWithNewMethod;
@property(nonatomic, readonly)   BOOL shouldCallJSAPIWithToken;

//app resume的时候是否需要打开新app
@property(nonatomic, readonly)  NSArray *reStartAppIdList;

//wk
@property(nonatomic, readonly) NSArray *appUseShareProcessWhiteList;
@property(nonatomic, readonly) NSArray *WKUrlBlackList;

//sec api log
@property(nonatomic, readonly)   NSDictionary *secJsApiCallConfig;

//错误页
@property(nonatomic, readonly)   BOOL enableNewErrorPage;

//退出应用的默认方式，是退出当前，还是栈顶
@property(nonatomic, readonly)   NSString *exitAppDefaultType;

//全屏域名白名单
@property(nonatomic,readonly) NSArray *enableFullscreenList;

//jsapinotfound repair
@property(nonatomic, readonly)   BOOL enableJsApiReapair;
@property(nonatomic, readonly)   BOOL enableCheckReadPlist;

//popViewController fail repair
@property(nonatomic, readonly) BOOL retrySystemPop;

//locationDialogPermitWhiteList
@property(nonatomic,readonly) NSArray *locationDialogPermitWhiteList;

@property(nonatomic, readonly) NSString *errorPageFeedBackType;
@property(nonatomic, readonly) NSDictionary *stripLandingConfig;
@property(nonatomic, readonly) BOOL shouldCheckTabBarJsonVersion;
@property(nonatomic, readonly) BOOL shouldCheckMainurlDegrade;

//小程序真机调试log输出
@property (nonatomic, assign, readonly) BOOL enableTinyAppRemoteDebugLog;

+ (H5Configs *)sharedConfigs;

/* 弃用记录
@property(nonatomic, readonly) NSArray *entryWhitelist;// 8.4弃用
@property(nonatomic, readonly, copy) NSString *forbidAccessWarningText; // ok
@property(nonatomic, readonly) int onceToLoadNo; // ok
@property(nonatomic, readonly) float freeMemoryLimit; // ok
@property(nonatomic, readonly) NSDictionary *totalMobileFlow; // ok
@property(nonatomic, readonly) BOOL preloadGlobalSwitch; // ok
@property(nonatomic, readonly) BOOL h5PreloadGlobal; // ok
@property(nonatomic, readonly) BOOL preload3GSwitch; // ok
@property(nonatomic, readonly) int preloadForUserPercent; // ok
@property(nonatomic, readonly, copy) NSString *dynamicScriptUrl; // ok
@property(nonatomic, readonly, copy) NSString *preloadExpression; // ok
@property(nonatomic, readonly) BOOL canEnableWK;  ok
@property(nonatomic, readonly, copy) NSString *firstJumpURL; // ok
@property(nonatomic, readonly, copy) NSString *checkPermission; // ok
@property(nonatomic, readonly) BOOL canEnableHKFS; // ok
//不走SPDY的域名黑名单
//@property(nonatomic, readonly) NSArray *SPDYHostBlackList;
//@property(nonatomic, readonly) NSArray *SPDYHostWhiteList;

// 995删除
@property(nonatomic, readonly) NSDictionary *share2ALPTimeLineSwitch; // ok
@property(nonatomic, readonly) BOOL canInterceptWebRequest; // ok
@property(nonatomic, readonly) BOOL canProcessWebRequestResponse; // ok
@property(nonatomic, readonly) BOOL canMonitorWebRequest; // ok
@property(nonatomic, readonly) NSDictionary *canEnableNetworkPerformance; // ok
@property(nonatomic, readonly,copy) NSString *reportAbnormalPageMenuItemText; // ok
@property(nonatomic, assign) int reportAbnormalPageRelatedDiagnoseNum; // ok
@property(nonatomic, readonly) NSDictionary *imageResizeConfig; // testing
 @property(nonatomic, readonly) NSString *firstSHKClsName; // ok
 @property(nonatomic, readonly) NSString *firstSHKMthName; // ok

 
 */
//from tinyappservice
-(BOOL)shouldTradePayCheck;
//-(BOOL)shouldCheckLifestyleRelationSame;
-(BOOL)shouldCheckNavigateRelationSame;
-(BOOL)shouldHideSetShortCut;
-(BOOL)canUseWebview;
-(BOOL)canInterceptBack;
-(NSArray*)navigateWhiteList;
-(NSArray*)webviewJsapiWhiteList;
-(NSArray*)internalAPIWhiteList;
-(NSArray*)authorizationWhiteList;
-(BOOL)shouldGoSpdy;
-(NSArray*)forceGoSpdyBlackList;
-(NSArray*)shareMenuBlackList;
-(NSArray*)webviewSudoList;
-(NSArray*)postMsgTypeWhiteList;
-(NSArray*)favoriteActionBlackList;
-(BOOL)shouldShowRecently;
-(BOOL)shouldUseCustomTransition;
-(NSArray*)spdyBlackList;
-(NSArray*)globleApiWhiteList;
-(NSInteger)popMenuTimeOut;
- (BOOL)enableAliAutoLogin:(NSString *)appId;

@end
