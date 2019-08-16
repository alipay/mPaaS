//
//  PSDDefine.h
//  Poseidon
//
//  Created by chenwenhong on 14/7/25.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, PSDEventPhase) {
    PSDEventPhase_Capture,
    PSDEventPhase_Target,
    PSDEventPhase_Bubbling,
};

typedef NS_ENUM(NSInteger, PSDPluginPriority) {
    PSDPluginPriority_High = 2,
    PSDPluginPriority_Default = 0,
    PSDPluginPriority_Low = -2,
};

#define kPSDBundleName                          [PSDConfigurationGet() pluginsBundleName]
#define kJSBridgeFileName                       @"h5_bridge"
#define kJSPerformanceFileName                  @"h5_performance"
#define kJSDelegateGeoFileName                  @"h5_delegateGeo"
#define kJSShareFileName                        @"h5_share"

#define kJSBridgeFileReplaceString              @"\"JS_BRIDGE_JS_***_REPLACE_STRING_***_SJ_EGDIRB_SJ\""
#define kJSBridgeFileReplaceVariable            @"\"H5_BRIDGE_JS_REPLACE_STRING\""
#define kPSDScope_Proxy                         @"proxy" // global级别
#define kPSDScope_Service                       @"service" // global级别
#define kPSDScope_Session                       @"session" // global级别，对所有session生效
#define kPSDScope_Scene                         @"scene" // global级别，对所有scene生效

// proxy--request的headers中包含以下key会走拦截
#define kPSDProxyRequestHeaderKey               @"kPSDProxyRequestHeaderKey"
#define kPSDProxyRequestHeaderKey1              @"kPSDProxyRequestHeaderKey1"
// ChannelId（id获取优先级：header > ua）
#define kPSDProxyRequestHeaderChannelIdKey      @"kPSDProxyRequestHeaderChannelIdKey" // --> 同一个页面配置相同的ChannelId

#define kPSDProxyRequestFromSDK                 @"Nebula"

#define KPSDWKFakePersistentCookie              @"KPSDWKFAKEPERSISTENTCOOKIE"
#define KPSDWKSharedCookies                     @"KPSDWKSharedCookies"
#define KPSDDocumentHref                        @"document.location.href"
#define KPSDMainUrlFallback                     @"KPSDMainUrlFallback"
#define KPSDUrlFromHttpRequest                  @"KPSDUrlFromHttpRequest"

//*******************************Events***************************//
#define kEvent_All                              @"*.*"
#define kEvent_None                             @"-"

//**********************Application Events************************//
#define kEvent_Application_Start                @"application.start"
#define kEvent_Application_Pause                @"application.pause"
#define kEvent_Application_Resume               @"application.resume"
#define kEvent_Application_Exit                 @"application.exit"
#define kEvent_Application_All                  @"application.*"

//**********************Session     Events************************//
#define kEvent_Session_Create                   @"session.create"
#define kEvent_Session_Destroy                  @"session.destroy"
#define kEvent_Session_All                      @"session.*"

//**********************Scene       Events************************//
#define kEvent_Scene_Create                     @"scene.create"
#define kEvent_Scene_Appear_Before              @"scene.appear.before"
#define kEvent_Scene_Appear_After               @"scene.appear.after"
#define kEvent_Scene_Load                       @"scene.load"
#define kEvent_Scene_Didload                    @"scene.didload"
#define kEvent_Scene_Ready                      @"scene.ready"
#define kEvent_Scene_Layout                     @"scene.layout"
#define kEvent_Scene_DidUnload                  @"scene.didunload"
#define kEvent_Scene_Disappear_Before           @"scene.disappear.before"
#define kEvent_Scene_Disappear_After            @"scene.disappear.after"
#define kEvent_Scene_Destroy_Before             @"scene.destroy.before"
#define kEvent_Scene_Destroy                    @"scene.destroy"
#define kEvent_Scene_All                        @"scene.*"
#define kEvent_Scene_Start_FirstRequest         @"scene.start.firstrequest" // 监听该事件，可以调用preventDefault阻止默认行为（默认会自动加载第一个url）

//**********************View        Events************************//
#define kEvent_View_Create                      @"view.create"
#define kEvent_View_Resize                      @"view.resize"
#define kEvent_View_Destroy                     @"view.destroy"
#define kEvent_View_Config                      @"view.config"
#define kEvent_View_Inject_JS                   @"view.inject.js"
#define kEvent_View_Show_Panel                  @"view.show.panel"
#define kEvent_View_Reload_Fail                 @"view.reload.fail" //WK进程crash，重试几次后依然失败的事件
#define kEvent_View_All                         @"view.*"

//**********************Page        Events************************//
#define kEvent_Page_Create                      @"page.create"
#define kEvent_Page_Load_Start                  @"page.load.start"
#define kEvent_Page_Load_FirstByte              @"page.load.firstbyte"
#define kEvent_Page_Load_Progress               @"page.load.progress"
#define kEvent_Page_Load_DomReady               @"page.load.domready"
#define kEvent_Page_Load_Complete               @"page.load.complete"
#define kEvent_Page_Load_Error                  @"page.load.error"
#define kEvent_Page_Destroy                     @"page.destroy"
#define kEvent_Page_All                         @"page.*"

//**********************Navigation   Events***********************//
#define kEvent_Navigation_Start                 @"navigation.start" // 监听该事件，可以调用preventDefault阻止默认行为（默认是将要开始加载请求），若阻止了，则不会进行加载
#define kEvent_Navigation_Complete              @"navigation.complete"
#define kEvent_Navigation_Error                 @"navigation.error"
#define kEvent_Navigation_All                   @"navigation.*"

//**********************Invocation   Events***********************//
#define kEvent_Invocation_Invocation_Before     @"invocation.invoke.before" // 监听该事件，可以阻止事件

#define kEvent_Invocation_Event_Start           @"invocation.event.start" // 监听该事件，可以调用preventDefault阻止默认行为（默认是询问是否可以执行），若阻止了，则不会往下执行调用
#define kEvent_Invocation_Start                 @"invocation.start" // 监听该事件，可以调用preventDefault阻止默认行为（默认是询问是否可以执行），若阻止了，则不会往下执行调用
#define kEvent_Invocation_Permit                @"invocation.permit" // 监听该事件，可以调用preventDefault阻止默认行为（默认是询问是否可以执行），若阻止了，则不会往下执行调用 10.1.58 专用于JSAPI权限管控专用
#define kEvent_Invocation_Invoke                @"invocation.invoke" // 监听该事件，可以调用preventDefault阻止默认行为（默认是将要开始执行方法），若要自定义执行方法，则需要执行`responseCallback`将结果回调给页面
#define kEvent_Invocation_Complete              @"invocation.complete"
#define kEvent_Invocation_Error                 @"invocation.error"
#define kEvent_Invocation_All                   @"invocation.*"

//**********************Proxy      Events***********************//
#define kEvent_Proxy_Request_Start_Handler      @"proxy.request.start.handle" // 监听该事件，可以调用preventDefault阻止默认行为（默认是将要开始加载请求），如阻止了，则不会进行加载；若要自定义请求，则可以设置`request`或者设置其headers
#define kEvent_Proxy_Request_Start_Dest         @"proxy.request.start.dest"
#define kEvent_Proxy_Request_Response_Handler   @"proxy.request.response.handle" // 监听该事件，可以调用preventDefault阻止默认行为（默认是继续加载请求），若阻止了默认行为，则可以设置`willRedirectRequest`、并会重定向到当前的`request`（一般用途是处理登录后重新发出请求）
#define kEvent_Proxy_Request_ReceiveResponse    @"proxy.request.response.receive" // 监听该事件，可以处理`response`，比如修改或者新增headers
#define kEvent_Proxy_Request_Redirect_Before    @"proxy.request.redirect.before"
#define kEvent_Proxy_Request_ReceiveData        @"proxy.request.data.receive" // 监听该事件，可以处理`willHoldReceiveData`和`reveiceData`，如果willHoldReceiveData=YES，则数据会被暂时持有在内存 处理：分段data，处理过程中不会response已有的receive data
#define kEvent_Proxy_Request_FinishReceiveData  @"proxy.request.data.finish" // 监听该事件，可以处理`receiveData` 处理：完整data，并response回去
#define kEvent_Proxy_Request_Finish             @"proxy.request.finish"
#define kEvent_Proxy_Request_Finish_Metrics     @"proxy.request.finish.metrics"
#define kEvent_Proxy_Request_Cancel             @"proxy.request.cancel"   //请求取消事件


//**********************ProxyMonitor Events***********************//
#define kEvent_ProxyMonitor_Report_Profile      @"proxy.monitor.report.profile"


//**********************Monitor Events***********************//
#define kEvent_Monitor_Log_Before               @"monitor.log.before"

//**********************Message Handler***********************//

#define KPSDBRIDGEMESSAGEHANDLER        @"PSDBRIDGEMESSAGEHANDLER"
#define KPSDBRIDGEDOMREADY              @"PSDBRIDGEDOMREADY"
#define KPSDXMLHTTPREQUESTMESSAGE       @"PSDXMLHTTPREQUESTMESSAGE"
#define KPSDXNEBULAXMLHTTPREQUEST       @"X-NEBULAXMLHTTPREQUEST"
#define KPSDXMSGID                      @"msgId"
#define KPSDXMSGCOOKIE                  @"msgCookie"
#define KPSDXMSGMAINURL                 @"msgMainUrl"
#define KPSDXMSGVAL                     @"val"
#define KPSDXMSGTYPE                    @"type"
#define KPSDXMSGENCTYPE                 @"FormEnctype"
#define KPSDXMSGACCEPTCHARSET           @"AcceptCharset"
#define KPSDXMSGDOCUMENTCHARSET         @"DocumentCharset"
#define KPSDXMSGISSTREAM                @"IsStream"
#define KPSDXMSGNAME                    @"name"
#define KPSDXMSGVALUE                   @"value"
#define KPSDFORMENCTYPEOFURLENCODE      @"application/x-www-form-urlencoded"
#define KPSDFORMENCTYPEOFPLAIN          @"text/plain"
#define kPSDSceneInjectRequest          @"kPSDSceneInjectRequest"
#define KPSDXMSGTK                      @"msgKt"
#define KPSDXMSGREQUESTURL              @"msgRequestUrl"

//********************** other ***********************//
//可以通过runtime的方式获得当前request是否是主文档的请求
#define kPSDWEBVIEWISMAINFRAMEREQUEST   @"kPSDWEBVIEWISMAINFRAMEREQUEST"

