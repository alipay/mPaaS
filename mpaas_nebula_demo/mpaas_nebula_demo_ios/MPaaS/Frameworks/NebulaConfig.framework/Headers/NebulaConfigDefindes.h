//
//  NebulaConfigDefindes.h
//  NebulaConfig
//
//  Created by theone on 2019/2/14.
//  Copyright © 2019 Alipay. All rights reserved.
//

#ifndef NebulaConfigDefindes_h
#define NebulaConfigDefindes_h

//**********************************APConfig******************************//

#define kH5NewCompetitiveList          @"h5_newcompetitiveList"
#define kH5SyncInjectJS                @"h5_syncinjectjs"
#define kH5ConstrainedToH5             @"h5_cashierPopWindow" // 与收银台合并开关，并且不缓存，popWindow操作时，限定退出当前session的最顶上一个H5窗口
#define kH5EnableCleanUrl              @"h5_enableCleanUrl" // 埋点非唯一信息的url内容，均将query和fragment去除
#define kH5MaxUrlLogLength             @"h5_maxUrlLogLength" // 唯一信息的URL内容，限制长度
#define kH5MaxRouterUrlLogLength       @"h5_maxRouterUrlLogLength" // 性能埋点中的router记录，限制长度
#define kH5SwitchTabUseAppRoot         @"h5_SwitchTabUseAppRoot" //switchTab时，回退到root操作，使用app.rootViewController
#define kH5RouterRule4IndustryService  @"h5_routerRule4IndustryService" //行业专用路由配置
#define kH5RouterRuleGeneral           @"h5_routerRuleGeneral" //通用路由配置
#define kH5JSBridgeRewriteStr          @"h5_jsBridgeRewriteStr"  //同步js重写的字符串
#define kH5JsapiAndPluginsConfig       @"h5_jsapiandPluginsConfig"  //js和plugin动态配置列表  since 10.1.22
#define kH5ShouldCheckNBSession        @"h5_shouldCheckNBSession"   //是否在离线包匹配的时候检查是否是当前session的请求
#define kH5ThirdDisclaimerRules        @"h5_thirdDisclaimer_rules"  //第三方提示规则
#define kH5MainLinkConfig              @"h5_mainLinkConfig" //主链路监控配置
#define kH5ShouldHookUserDefault       @"h5_shouldHookUserDefault" //wk是否应该hook userdefault
#define kH5ShouldUseNewRelanch         @"h5_shouldUseNewRelanch" //是否要使用新的relanch方案 10.1.28
#define kH5NewJsapiPermissionConfig    @"h5_newJsapiPermissionConfig" //新权限开关控制开关 10.1.28
#define kH5NewJsapiDomainWhiteList     @"h5_newJsapiDomainWhiteList"
#define kH5NewJsapiClearCache          @"h5_newJsapiClearCache"
#define kH5NetworkChannelConfig        @"h5_networkChannel"           // network channel config
#define kH5NetStatLog                  @"h5_netstatlog"               // network perf log
#define kH5ForceWKWhiteList            @"h5_forceWKWhiteList"         // force WK white list
#define kH5ShouldFixTitleView          @"h5_shouldFixTitleView"       //是否需要修复TitleView问题，全局性的所以加一个开关
#define kH5FetCountryCode              @"h5_fetchCountrycode"         // 10.1.28(获取城市码防护性开关,无问题后续可移除)
#define kH5PayPrompt                   @"h5_payPrompt"                //快捷提示条是否展示开关
#define kH5PayPromptAddOrderStrParam   @"h5_payPromptAddOrderStrParam"  //是否给支付追加字符串
#define kTASceneValueMap               @"ta_scene_cfg"                  //10.1.30小程序场景值映射
#define kH5WKShouldFixUrlProtocol      @"h5_WKShouldFixUrlProtocol"     //10.1.30WK是否修复urlprotocolbug
#define kH5PushWindowDelayTask         @"h5_pushWindowDelayTask"        //10.1.30PushWindow支持延迟任务
#define kH5ShouldCallJSAPIWithService  @"h5_shouldCallJSAPIWithService" //10.1.30 session已销毁时，不回调"接口找不到"
#define kH5AdjustTitleViewFrame        @"h5_adjustTitleViewFrame"       //10.1.30 界面出现后检查标题栏
#define kH5ShouldFixTinyAppRelease     @"h5_shouldFixTinyAppRelease"    //10.1.30是否需要修复小程序内嵌WebView问题
#define kH5NewGetAuthCode              @"h5_newGetAuthCodeConfig"       //10.1.32新的授权逻辑相关配置
#define kH5DataFlowConfig              @"h5_dataFlowConfig"             //10.1.32 流量管控开关
#define kH5WKShouldUseUrlSchemeHandler @"h5_WKShouldUseUrlSchemeHandler" //10.1.32 iOS是否用新的拦截协议
#define kH5EnableCancelEventLog        @"h5_enableCancelEventLog"        //10.1.32 是否上报取消事件埋点
#define kH5WKShouldFixScrollHorizontal @"h5_WKShouldFixScrollHorizontal" //10.1.32 是否修复WK水平滚动问题
#define kH5TinyAppPublicUrl            @"h5_tinyAppPublicUrl"            //10.1.32 套壳小程序中的h5全局资源加速开关
#define kH5ShouldFixUIWebViewBridge    @"h5_shouldFixUIWebViewBridge"    //10.1.32修复UIWebview iframe 引起Bridge重新创建的问题
#define kH5SchemeCensorEnable          @"h5_schemeCensorEnable"          //10.1.32框架scheme管控配合改造
#define kH5RPCPrefetchSPM              @"h5_rpc_prefetch_spm"            //10.1.32道朗RPC时在WK下主动读取SPM
#define kH5AuthAutoRPCEnable           @"h5_authAutoRPCEnable"           //10.1.32开启OPENAUTH转RPC
#define kH5DeprecateShowTitleBar       @"h5_deprecateShowTitleBar"       //10.1.32废弃SDK使用启动参数showTitleBar
#define kH5TransparentCustomedPopGesture       @"h5_transparentCustomedPopGesture"       //10.1.32侧滑手势到transpent页面时，优化白条
#define kH5UnifyNetworkCallbackThread  @"h5_unifyNetworkCallbackThread"  //10.1.32是否统一网络请求回调到同一个线程中
#define kTATransferH5ToTiny             @"ta_h5TransferTiny"             //10.1.32H5改小程序样式appId列表
#define kH5ShouldCollectUnfinishedUrl   @"h5_shouldCollectUnfinishedUrl"  //10.1.32未完成url采集逻辑有改动，开关控制是否采集
#define kH5EnableGlobalPreloadTask     @"h5_enableGlobalPreloadTask"     //10.1.32启动加载时预创建WKWebView
#define kH5ShouldFixResumeUnique       @"h5_shouldFixResumeUnique"       //10.1.32修复不动唯一启动单例APP
#define kH5GetReferWithAppId           @"h5_getReferWithAppId"           //10.1.35iOS小程序http请求追加referer
#define kH5ShouldWKAutoLoginSyncCookie @"h5_shouldWKAutoLoginSyncCookie" //10.1.32是否在给WKWebView同步Cookie加保护
#define kH5ShouldRecordCookieUserConfig @"h5_shouldRecordCookieUserConfig"  //10.1.32记录用户cookie的白名单用于排查问题
#define kH5ShouldWKInPageRenderConfig   @"h5_WKInPageRenderConfig"  //10.1.35同层渲染开关
#define kH5ResourceFilter1             @"h5_ResourceFilter1"              //10.1.35通过开关黑名单过滤子资源，开关1
#define kH5ResourceFilter2             @"h5_ResourceFilter2"              //10.1.35通过开关黑名单过滤子资源，开关2
#define kH5GetSharedDataFix             @"h5_getSharedDataFix"            //10.1.35支持屏蔽NSUserDefault读取
#define kH5SyncAutoLoginConfig         @"h5_syncAutoLogin"                //10.1.35同步免登开关
#define kH5LogGroup                    @"h5_logGroup"                     //10.1.35异常埋点打标标记用户类型
#define kH5TinyAppRemoteDebugLog       @"h5_tinyAppRemoteDebugLog"        //10.1.35小程序真机调试日志输出
#define kH5WKWebViewFix                @"h5_wkWebViewFix"                 //10.1.35修复历史版本对线上页面的使用问题
#define kH5WKWebViewArbitrary          @"h5_wkArbitrary"                  //10.1.35全量开启WKWebView
#define kH5WKWebViewBlackList          @"h5_wkBlackList"                  //10.1.35容器紧急止血
#define kH5ShouldWKDispatchStartEvent  @"h5_shouldWKDispatchStartEvent"   //10.1.35容器WKWebView是否需要针对非http请求派发事件
#define kH5SkipCustomPrompt            @"h5_skipCustomPrompt"             //10.1.35修复电话弹两次的问题
#define kH5ShouldWKDispatchStartEvent  @"h5_shouldWKDispatchStartEvent"   //10.1.35容器WKWebView是否需要针对非http请求派发事件
#define TA_SAFE_COOKIE_STORAGE_WHITE_LIST   @"ta_cookie_part_wl"              //10.1.35小程序 cookie 安全，同一域下不同小程序分离存储白名单
#define kH5TextareaSwitch            @"h5_TextareaSwitch"             //10.1.35 textarea 开关
#define kH5CheckAppPkgStatus           @"h5_checkAppPkgStatus"            //10.1.35容器checkApp接口是否返回包状态开关
#define kH5PingIgnoreUnexpectedPacket  @"h5_pingIgnoreUnexpectedPacket"   //10.1.38容器pingHelper忽略异常包开关
#define kH5ShouldSubViewDispatchAppEvent     @"h5_shouldSubViewDispatchAppEvent" //10.1.38容器subview是否派发appResume/appPause事件
#define kH5WKUseDaemonView     @"h5_wkUseDaemonView" //10.1.38容器wkwebivew使用栈顶view保活进程
#define kH5ShouldFixGetAuthCode     @"h5_shouldFixGetAuthCode" //10.1.38兜底处理框架currentVisibleViewController取到为nil，导致高德授权弹不出
#define kH5ShouldFixVideoStatusBar   @"h5_shouldFixVideoStatusBar" //10.1.38修复视屏播放全屏退出后状态栏丢失问题
#define kH5APDataStorageConfig       @"h5_apDataStorageConfig" //10.1.38对setAPDataStorage和getAPDataStorage安全加固
#define kH5ShouldKeyboardFixCursor   @"h5_shouldKeyboardFixCursor"//10.1.38修复删除的时候光标到末尾问题
#define kH5AsyncUnzipWhenLaunching   @"h5_asyncUnzipWhenLaunching"  //10.1.50进入应用时是否开启异步解压以防止卡顿
#define kH5RemoveMessageHandlerEarly   @"h5_removeMessageHandlerEarly"  //10.1.50WK在scene销毁或vc销毁时中断bridge通信
#define kH5DisableSPDYInScan         @"h5_disableSPDYInScan"    //10.1.50扫码场景下关闭mobileproxy
#define kH5PreRPCRequest             @"h5_preRPCRequest"        //10.1.50红包预取RPC
#define kH5FixMassproxyFallback      @"h5_fixMassproxyFallback"     //10.1.50修复massproxy在fallback时无法去除response缓存的问题
#define kH5NotSupportFileConfig      @"h5_notSupportFileConfig"  //10.1.50非主动帧中断时白名单URL不强制识别为不支持文件类型
#define kH5ShouldFixWKScreenshot     @"h5_shouldFixWKScreenshot"  //10.1.50修复snapshot jsapi在viewport和document入参调用
#define kH5ShouldCancelInjectJS      @"h5_shouldCancelInjectJS"  //10.1.50保护性开关不执行CancelInjectJS
#define kH5ScanAppPreloadConfig      @"h5_scanAppPreloadConfig"  //10.1.50扫码rpc时预先执行容器任务
#define kH5DomainConvergence         @"h5_domainConverge"        //10.1.50 是否开启域名收敛
#define kH5NewJsapiNamesLog          @"h5_newJsapiNamesLog"        //10.1.50 PERFORMANCE埋点记录jsapi耗时
#define kH5NewAuthViewSize           @"h5_newAuthViewSize"        //10.1.50 authview的尺寸计算时，使用新方法
#define kH5EnableInPageInput         @"h5_EnableInpageInput"  //10.1.50 input同层渲染开关
#define kH5FixUploadFileParamOrder         @"h5_FixUploadFileParamOrder"  //10.1.50 将UploadFile的file参数移动到postbody的最下
#define kH5KernelMainThreadDeallocConfig         @"h5_kernelMainThreadDeallocConfig"  //10.1.50 kernel实例在主线程释放时，强制children在主线程释放
#define kH5RequestProxy4Tinyapp      @"ta_requestProxyList"       // 10.1.52 小程序httprequest走代理
#define kH5LimitControl4Tinyapp      @"ta_limitControlList"       // 10.1.52 小程序限流管控
#define KH5EventThroughWorker        @"h5_eventThroughWorker" //10.1.52 小程序通过woker触发的事件
#define kH5UseAPWebP                 @"h5_useAPWebP"              //是否使用多媒体提供的webp接口
#define kH5OpenUrlWhiteList1             @"h5_openUrl_whitelist1"  //10.1.52 场景一、疑似下载场景，需打开外部浏览器的白名单
#define kH5OpenUrlWhiteList              @"h5_openUrl_whitelist"  //10.1.52 统一收口，需打开外部浏览器的白名单
#define kH5StartAppCensorEnable          @"h5_startAppCensorEnable"  //10.1.52 对startApp调用做校验
#define kH5ShouldClearAllKeepedApp       @"h5_shouldClearAllKeepedApp" //10.1.52是否清除所有保活app
#define kH5ShouldUseWindowCenterX        @"h5_shouldUseWindowCenterX" //10.1.52是否使用window来计算中心点
#define kH5FixNetLogInfoCrash            @"h5_fixNetLogInfoCrash"     //10.1.52修复massproxy埋点并发闪退
#define kH5FixUIWebViewiOS12KeyBoard     @"h5_fixUIWebViewiOS12KeyBoard"   //10.1.52修复massproxy埋点并发闪退
#define kH5EnableWebpDecodeLog           @"h5_enableWebpDecodeLog"    //10.1.52是否上报webp解码相关埋点
#define kH5InPageInputBlackList          @"h5_inPageInputBlackList"  //10.1.52 input同层input黑名单
#define kH5ShouldCheckKeboardParam       @"h5_shouldCheckKeboardParam"  //10.1.52 是否要检查input参数
#define kH5ShouldPSDViewDeallocUseMainThread @"h5_shouldPSDViewDeallocUseMainThread" //10.1.52 PSDView销毁时强制逻辑主线程执行
#define kH5IFrameValidConfig             @"h5_iFrameValidConfig" //10.1.52 IFRAME能加载URL的校验
#define kH5HttpJsApiUseMassproxy         @"h5_httpJsApiUseMassproxy"   //10.1.55 httpRequest jsapi是否走massproxy
#define kH5FixTransitionWhiteTitle       @"h5_fixTransitionWhiteTitle" //10.1.55 修复首页切换到transparenttilte-auto时nav会白闪的问题
#define kH5RemoveIsOriginStartFromExternal  @"h5_removeIsOriginStartFromExternal" //10.1.58 删除对外暴露的可能不准确的外部标识
#define kH5TinyAppPreRenderUseDomReady      @"h5_tinyAppPreRenderUseDomReady" //10.1.58 预渲染使用domReady事件
#define kH5TinyAppTitleViewAlignLeftConfig  @"h5_tinyAppTitleViewAlignLeftConfig" //10.1.55 小程序标题样式更改
#define kH5TinyAppComponentWebviewLoadUrl  @"h5_tinyAppComponentWebviewLoadUrl" //10.1.55 小程序webview的url加载方式修改
#define kH5ShouldFixFastJumpTitleBar       @"h5_shouldFixFastJumpTitleBar"       //10.1.55 透明navbar的小程序跳转到聊天页，会导致后者UI异常 issue #3657
#define kH5InpageRenderDirectRenderList    @"h5_inpageRenderDirectRenderList"    //10.1.55为了兼容Swiper闪的问题，直接同层的appId列表
#define kH5FixPageResumeAtStart            @"h5_fixPageResumeAtStart"            //10.1.58修复外部url唤起h5应用时触发resume事件的问题
#define kH5FixWebViewTouchSlow      @"h5_fixWebViewTouchSlow"      //10.1.58修复WebView touch事件触发变慢问题
#define kH5MassproxyFix                    @"h5_massproxyFix"                   //10.1.58massproxy30x跳转、206等问题修复
#define KH5TinyPulldownTextBlackList    @"h5_tiny_pulldown_text_blacklist"      // 10.1.58 小程序下拉显示安全文案
#define kH5ThowJSExecException          @"h5_plugin_throwException" //10.1.58 是否抛出JS异常，默认NO
#define kH5ShouldDipatchContextPresentEvent @"h5_shouldDipatchContextPresentEvent" //10.1.58 对透明弹窗的交互过程增加事件派发
#define kH5NonusualNetworkReqLog              @"h5_nonusualNetworkReqLog"       //10.1.58特殊网络请求埋点
#define kH5InPageRenderInputWhiteList         @"h5_inPageRenderInputWhiteList"  //10.1.58同层input白名单
#define kH5InputForceLayoutWhiteList          @"h5_inputForceLayout"            //10.1.58强制布局白名单
#define kH5TinyNotUseSPDY                     @"h5_tinyNotUseSpdyCfg"           //10.1.58小程序走spdy控制开关
#define kH5ShouldRedirectHSTS                  @"h5_shouldRedirectHSTS"           //10.1.60修复HSTS取location.href出错
#define kH5ShouldFixTansparentTitleAutoPageFinish                  @"h5_shouldFixTansparentTitleAutoPageFinish"           //10.1.60修复transparentTitle auto在pageFinish较晚时的异常
#define kH5TinyResUseSPDY                  @"h5_tinyResUseSpdy"                //10.1.60小程序子资源是否走spdy开关
#define kH5EmbedWebViewSetOptionMenuWhiteList  @"h5_embedWebviewSetOptionMenuWhiteList" // 10.1.60开始不允许内嵌webview操作小程序的optionmenu，该开关增加白名单
#define kH5TadePayOpenUrlDelay  @"h5_tradePay_openUrlDelay" // 10.1.60支付完成xx秒后不能外跳非alipay的scheme
#define kH5ShouldInputChangeFrameWithDom   @"h5_shouldInputChangeFrameWithDom" //10.1.60  input位置是否随着dom变更来变更
#define kH5ShouldFixCFNetworkCrash         @"h5_shouldFixCFNetworkCrash"       //10.1.60  cfnetwork闪退埋点与修复
#define kH5NotQueryTinyAppMdapConfig       @"h5_notQueryTinyAppMdapConfig"  //10.1.60  添加小程序埋点配置开关


//**********************************TAConfig******************************//
#define TINY_APP_CONFIG             @"ta_cfg"
#define TA_KEEP_ALIVE_CONFIG        @"ta_ka_cfg"             //小程序保活总开关
#define TA_USE_NATIVE_SHARE_CONFIG  @"use_native_share_cfg"  //小程序navtive分享总开关
#define TA_SCENE_CONFIG             @"ta_scene_cfg"          //小程序启动场景值映射表开关
#define TA_RPC_API_CONFIG           @"ta_rpc_api_cfg"        //小程序Rpc oprationType映射表开关
#define TA_EMBEDWEBVIEW_DOMAIN_NEWREGEX @"ta_embedwebview_domain_newRegex" // 内嵌webview 跳过jsapi权限校验百名单校验规则 10.1.55 支持，验证之后可去除
#define TA_EMBEDWEBVIEW_WHITE_DOMAIN_LIST  @"ta_embedwebview_white_domain_list"  //内嵌webview 跳过jsapi权限校验百名单 10.1.32支持
#define TA_EMBEDWEBVIEW_WHITE_DOMAIN_LIST_WITH_NB  @"ta_embedwebview_white_domain_list_nb"  //内嵌 webview 是否是仅需要容器 jsapi 权限校验域名百名单 10.1.50 支持
#define TA_EMBEDWEBVIEW_WHITE_APPID_LIST_WITH_NB  @"ta_webviewNBAppIdList"  // 内嵌 webview 是否是仅需要容器 jsapi 权限校验 appid 百名单 10.1.52 支持
#define TA_HIDE_ABOUT_ITEM_BLACK_LIST @"ta_hide_about_item_blacklist" // 开关配置根据appid去除"关于"按钮 10.1.32支持
#define TA_SHOW_ABOUT_ITEM_WHITE_LIST @"ta_show_about_item_whitelist" // 开关配置根据appid显示主体信息 10.1.52支持，全量之后可去除
#define TA_NAVIGATE_ALIPAY_PAGES     @"ta_navigate_alipay_pages"      // 小程序中跳转到支付宝业务和运营活动 10.1.32支持
#define TA_USE_TINYAPP_HANDLER      @"ta_useTinyAppManagerProcess"    //包管理切面开关 10.1.32
#define TA_SET_MINAPPX_BLACK_LIST   @"ta_setMinAppxBlacklist"         //支持设置appx版本开关 10.1.32
#define TA_SWITCH_H5_TO_TINY_WHITE  @"ta_h5TransferTiny"              //H5应用转小程序样式  10.1.32
#define TA_Webview_Open_AppIdList   @"ta_webviewOpenAppIdList"        //内嵌H5打开离线列表  10.1.32
#define TA_ENABLE_REMOTE_DEBUG      @"remote_debug_mode"              //是否打开远程真机调试 10.1.32
#define TA_QRCODESHARE_USE_RPCSERVICE @"ta_qrcodeshare_use_rpcservice"      // 二维码分享是否使用服务端生成图片 10.1.32
#define TA_NAVIGATE_APP_DEBUG   @"ta_navigate_app_debug"              //是否打开“跳转指定版本小程序”功能 10.1.32
#define TA_HTTP_DOMAIN_BLACKLIST    @"ta_http_domain_blacklist"       //httpRequest黑名单 10.1.35
#define TA_APPX_RPC_WHITELIST_CFG    @"ta_appx_rpc_whitelist_cfg" // 10.1.35新增，白名单控制appx可访问的rpc
#define TA_EmbedWebview_showProgress @"ta_webview_sp"
#define TA_PRESENT_LAUNCH_SWITCH @"ta_present_launch_switch" // 预埋总开关配置控制动画切换，可随启动动画改造下线
#define TA_SPDY_GLOBAL_CONFIG   @"ta_spdy_global_config"        // spdy全局控制开关，默认打开， 10.1.35
#define TA_MAX_WORKER_COUNT      @"ta_maxWorkerCount"           //最大worker数
#define TA_LAUNCH_APP_JSAPI_BLACKLIST    @"ta_launch_app_jsapi_blacklist"   // 10.1.35 回跳第三方APP，禁止回跳黑名单
#define TA_TAOBAO_APP_INFO   @"ta_taobao_app_info"        // 10.1.35  星巴克互通，临时方案，下发淘宝需要的appkey等信息
#define TA_CLOSE_APP_APIR   @"ta_closeAppPair"
#define TA_STARTPRELOAD @"ta_startPreload"      // 10.1.35 关闭淘宝小程序预建链
#define TA_ADD_FAVORITE_ALERT_WHITELIST @"ta_add_favorite_alert_whitelist" // 添加到收藏接口支持白名单控制是否要展示弹窗
#define TA_CLOSE_WEBVIEWSCHEMAWHITELIST @"ta_close_webviewSchemaWhiteList"     // 10.1.38 关闭内嵌webview openSchema 白名单功能
#define TA_RESET_FRAME_CUSTOM_TRANSITION    @"ta_resetframe_custom_transition"    // 10.1.38 启动动画引起首页frame异常
#define TA_USE_WHOLE_PACKAGE                @"ta_useWholePkg"                     // 10.1.38 分包降级到整包
#define TA_RENDER_JSAPI_BLACKLIST           @"ta_renderJsapiBList"                // 10.1.38 一二方插件包 render 调用 jsapi 黑名单
#define TA_INJECT_ChInfo                    @"ta_injectChInfo"                    // 10.1.38 小程序注入启动参数添加chInfo
#define TA_USE_TLS_WHITELIST                @"ta_useTlsWhitelist"                 // 10.1.38 强制https白名单
#define TA_SSL_APP_ID                       @"ta_ssl_appid"                       // 10.1.50 新增时间戳控制新增小程序强制走https/wss
#define TA_NAVI_IS_NEW_MENU                 @"ta_navi_is_new_menu" // 右上角菜单面板改版支持按照appId或者全部切回老样式
#define TA_NAVI_SHOW_FAVORITE_WL            @"ta_navi_is_show_favorite" // 开关控制导航栏右上角是否展示收藏图标入口
#define TA_IS_OPEN_RECENT_APP_PANEL         @"ta_is_open_recent_app_panel" // 开关控制是否打开全量展示新menu的最近使用列表
#define TA_IS_UPDATE_MENU_INTERVAL_LIST     @"ta_is_update_menu_interval_list" // 导航栏新menu对应RPC的缓存有效时间
#define TA_Pre_Prepare                      @"ta_pre_prepare"                     // 10.1.50 扫码预判提前准备p包信息
#define TA_NEW_MENU_HIDE_ALPHA              @"ta_new_menu_hide_alpha" // 新菜单隐藏时的动画效果
#define TA_SHOW_BACK_HOME_NOTIFY             @"ta_show_back_home_notify" // 10.1.50预埋一个版本，52可以下架
#define TA_NAVIBAR_POPTIP_MAX_COUNT         @"ta_navibar_poptip_max_count" // 导航栏右上角五角星提示框最多允许展示的次数
#define TA_EDGE_CFG                         @"ta_edge_cfg"          // 10.1.52 edge sdk配置
#define TA_COMP_PERMISSION_CHECK_APPID_WHITELIST       @"ta_compsPermissionWhiteList" //组件权限校验，appid白名单
#define TA_COMP_PERMISSION_CHECK_TYPE_LIST  @"ta_compsNeedCheck"     // 组件权限校验typelist  在typelist中才校验组件
#define TALimitControlList                 @"ta_limitControlList"       // 10.1.52 行业小程序限流
#define TARequestProxyList                 @"ta_requestProxyList"       // 10.1.52 httprequest代理
#define TAUseCustomShareContent            @"ta_useCustomShareContent"  // 10.1.52 自定义分享可以修改icon,标题，描述
#define TAFavoriteRefreshInterval          @"ta_favoriteSynchronisedTime"  // 10.1.52 全量拉取收藏列表间隔
#define TAMaxAddFavoriteSize               @"ta_maxAddFavoriteSize"          // 10.1.52 最大收藏数
#define TAFavoriteDisableCache             @"ta_favoriteUseRpc"              // 10.1.52 收藏相关接口都不使用缓存
#define TAQueryAllFavoriteCacheTime        @"ta_queryAllFavoriteCacheTime"   // 10.1.52 查询我的收藏缓存有效时间
#define TADisableCanvasMeasureText         @"ta_disableCanvasMeasureText"    // 10.1.52 开关控制不使用alipaycanvas计算文本宽度
#define kTARequestRequestHTTPBody           @"ta_request_record_httpbody" //10.1.52 request api 允许记录 httpBody
#define kTAEmbedWebviewHideBackWhiteList    @"ta_embed_webview_hide_back_wl" //10.1.52 内嵌webview 首页隐藏返回按钮白名单（名单内不隐藏返回，支持["all"]）
#define kTAShowBackHomeCheckNebulaBackButton    @"ta_show_back_home_check_nebula_back_button" //10.1.52 显示小房子前检查showBackButton api显示的back按钮，做例外处理
#define TA_PKGRES_ENABLEFORCE                @"ta_pkgRes_enableforce"  // 10.1.52 二方组件开启强制获取包信息
#define TAFQueryEmergency                    @"ta_queryEmergency"      // 收藏功能应急开关
#define TAPreInitTAFCache                    @"ta_preInitTAFCache"     // 提前初始化收藏缓存开关
#define TAFavoriteSpmTracker                 @"ta_spmTAFSwitch"        // 收藏相关埋点开关
#define TA_WEBVIEW_ALIPAYS_WHITELIST                @"ta_webview_alipays_whitelist"  // 10.1.55 内嵌 webview 支持 xx.com?scheme=alipaysxxx 跳转的白名单
#define TAFavoriteTipAB                     @"ta_favorite_tip_ab" // 10.1.55 收藏气泡提示AB样式
#define TABANMPEXTSCHEMELIST                @"ta_banmp_extschemelist"     // 10.1.55 主文档非http/https scheme请求，和安卓对齐默认放过权限，开关控制黑名单
#define TAUSENEBULATAHANDLE              @"ta_use_nebula_ta_handle"    // 10.1.55 模版小程序用容器切面，默认yes
#define kTAShowSharePadSync                 @"ta_sharePad_sync"        // 10.1.55 是否等二维码准备完后在唤起分享面板，默认no
#define TASENDMTOPINAPPDEGREDE            @"ta_sendmtop_inapp_degrade"  // 10.1.55 sendMtop发送是否仍在小程序
#define TAQuery4DynamicConfigChange        @"ta_q4dcc"                  //动态配置由rpc变更为缓存时
#define TASendMtopResponseDegrade           @"ta_sendMtop_res_degrade"  //10.1.58 sendMtop response处理回退
#define TAHTMLSnapshotWhiteList             @"ta_snapshotWhiteList"     //10.1.58 snapshot白名单
#define TAHTMLSnapshotBlckList              @"ta_snapshotBlackList"     //10.1.58 snapshot黑名单
#define TASnapshot2WhiteList                @"ta_snapshot2WhiteList"    //10.1.58 snapshot 在scene disappear的时候保存快早修改是否使用的白民单

#define TAInternalApiList                   @"ta_internalAPIList"       // 10.1.58 ta_cfg开关拆分 internalAPI 白名单
#define TASPDYBlackList                     @"ta_spdyBlackList"         // 10.1.58 ta_cfg开关拆分 spdy 黑名单
#define TAWebviewAppIdWhiteList             @"ta_webviewAppIdWhiteList" // 10.1.58 ta_cfg开关拆分 webview内超级权限，所有jsapi随便调
#define TAFavoriteMenuBlackList             @"ta_favoriteMenuBlackList" // 10.1.58 ta_cfg开关拆分 收藏黑名单
#define TAWebviewJsapiList                  @"ta_webviewJsapiList"      // 10.1.58 ta_cfg开关拆分 webview jsapi可用的名单
#define TANavigateWhiteList                 @"ta_navigateWhiteList"     // 10.1.58 ta_cfg开关拆分 小程序互跳白民单
#define TAHarewareNoticeBlackList           @"ta_hareware_notice_blacklist" // 10.1.58 小程序显示硬件使用icon

#define TACheckNavigateRelation           @"ta_checkNavigateRelation" // 10.1.60 ta_cfg开关拆分 antns
#define TAHideSetShortCut                 @"ta_hideSetShortCut" // 10.1.60 ta_cfg开关拆分 hssc
#define TAPermissionDialogBlackList       @"ta_permissionDialogBlackList" // 10.1.60 ta_cfg开关拆分 awl
#define TAGoSPDY                          @"ta_goSPDY" // 10.1.60 ta_cfg开关拆分 hus
#define TAGoSPDYBlackList                 @"ta_goSPDYBlackList" // 10.1.60 ta_cfg开关拆分 husb
#define TAShareMenuBlackList              @"ta_shareMenuBlackList" // 10.1.60 ta_cfg开关拆分 smb
#define TALongClickShowPanel              @"ta_longClickShowPanel" // 10.1.60 ta_cfg开关拆分 slsp
#define TAUseCustomTransition             @"ta_useCustomTransition" // 10.1.60 ta_cfg开关拆分 suplm
#define TAGlobleApiWhiteList              @"ta_globleApiWhiteList" // 10.1.60 ta_cfg开关拆分 gawl
#define TAPostMsgTypeWhiteList            @"ta_postMsgTypeWhiteList" // 10.1.60 ta_cfg开关拆分 pmtwl
#define TAAsyncGetPublicMessage            @"ta_asyncGetPublicMessage" // 10.1.60 获取生活号红点时使用异步方法

#endif /* NebulaConfigDefindes_h */
