//
//  H5Defines.h
//  H5Service
//
//  Created by xuesi on 13-12-14.
//  Copyright (c) 2013年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

#define SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(v)  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedAscending)

#define kH5RPCErrorDomain @"com.alipay.h5service"
#define kH5MopAppBizScenario @"scanApp"
#define kH5MopAppClassName @"APScanViewController"
#define kH5MopAppBizScenarioDefaultTitle __TEXT(@"NebulaBiz", @"NebulaBiz:扫码", @"扫码")
#define kH5SocialAppBizScenario @"HiChat"
#define kH5ScanAppId @"10000007"
#define kH5SanAppUseScan @"useScan"


#define kH5AlipayCustomScheme @"^(alipass|alipays|alipayqr|alipay|alipaywifi)$" // 因为这些scheme在rc包上加了rc后缀，所以要用openuRL来打开

// 动态插件Scheme
#define kJSCorePluginScheme @"jsplugin"
#define kJSCorePluginNotification @"jsPluginLoad"

#define H5Log(error) NSLog(@"%s %@", __func__, error)

// 服务端报错页面文案
#define kH5ServerErrorText __TEXT(@"NebulaBiz", @"NebulaBiz:服务暂不可用", @"服务暂不可用")

// 社交拦截错误页面
#define kH5CompetitiveLinkGoUrl @"https://ds.alipay.com/error/securityLink.htm"
#define kH5CompetitiveSchemeGoUrl @"https://ds.alipay.com/error/redirectLink.htm"
#define kH5CompetitiveNotSupportFileGoUrl @"https://ds.alipay.com/error/securityFile.htm"
#define kH5PermissionLinkGoUrl @"https://render.alipay.com/p/s/h5misc/resource_error"
#define kH5BridgePath  @"https://xalipaynebula/xalipaynebulabridge/xalipaynebulabridge.js"
#define kH5ReportUrl  @"https://securityassistant.alipay.com/flow/enterFlow.htm?flowId=complain_normal_h5&complainScene=complain&complainSubScene=normal_h5&oppositeUserId=2088232588425283&linkUrl=%@&complainSource=%@"


// 日志头
#define kH5LogHeaderError @"H-EM"
#define kH5LogHeaderBehavior @"H5-VM"
#define kH5LogHeaderBehaviorAuto @"HD-VM"
#define kH5LogHeaderCommon @"H-MM"

// 日志类型
#define kH5LogBizType135 @"135"
#define kH5LogBizTypeBehavior @"H5behavior"

// 公用
#define kH5CustomStorage  @"KH5CUSTOMSTORAGE"

//*******************************ExpandPropertyKeys***************************//
//#define kExpandPropertyKey_Beacon                @"kExpandPropertyKey_Beacon"
#define kExpandPropertyKey_RemoteLogCallCount    @"kExpandPropertyKey_RemoteLogCallCount"
#define kExpandPropertyKey_Pay                   @"kExpandPropertyKey_Pay"
#define kExpandPropertyKey_Share                 @"kExpandPropertyKey_Share"
#define kExpandPropertyKey_SpeechRecognizer      @"kExpandPropertyKey_SpeechRecognizer"
#define kExpandPropertyKey_NumberInput           @"kExpandPropertyKey_NumberInput"
#define kExpandPropertyKey_Contact               @"kExpandPropertyKey_Contact"
#define kExpandPropertyKey_ActionSheet           @"kExpandPropertyKey_ActionSheet"
#define kExpandPropertyKey_DatePicker            @"kExpandPropertyKey_DatePicker"
#define kExpandPropertyKey_City                  @"kExpandPropertyKey_City"
#define kExpandPropertyKey_Location              @"kExpandPropertyKey_Location"
#define kExpandPropertyKey_ImagePicker           @"kExpandPropertyKey_ImagePicker"
#define kExpandPropertyKey_ScanCode              @"kExpandPropertyKey_ScanCode"
#define kExpandPropertyKey_Sms                   @"kExpandPropertyKey_Sms"
#define kExpandPropertyKey_Sinasso               @"kExpandPropertyKey_Sinasso"
#define kExpandPropertyKey_ShouldStart           @"kExpandPropertyKey_ShouldStart"
#define kExpandPropertyKey_NotifyListener        @"kExpandPropertyKey_NotifyListener"
#define kExpandPropertyKey_RotateProxy           @"kExpandPropertyKey_RotateProxy"
#define kExpandPropertyKey_AppJSPermission       @"kExpandPropertyKey_AppJSPermission"
#define kExpandPropertyKey_AppShouldDelayRelease @"kExpandPropertyKey_AppShouldDelayRelease"
#define kExpandPropertyKey_JSCViewId             @"kExpandPropertyKey_JSCViewId"
#define kExpandPropertyKey_MainDocRequestFinish  @"kExpandPropertyKey_MainDocRequestFinish"
#define kExpandPropertyKey_CodeTriggerloading    @"kExpandPropertyKey_CodeTriggerloading"

#define kExpandPropertyKey_IsMainSession         @"kExpandPropertyKey_IsMainSession"
#define kExpandPropertyKey_PairSession           @"kExpandPropertyKey_PairSession"
#define kExpandPropertyKey_Processing            @"kExpandPropertyKey_Processing"
#define kExpandPropertyKey_ProcessResult         @"kExpandPropertyKey_ProcessResult"
#define kExpandPropertyKey_DestroyTask           @"kExpandPropertyKey_DestroyTask"
#define kExpandPropertyKey_SaveTask              @"kExpandPropertyKey_SaveTask"
#define kExpandPropertyKey_ReadyTask             @"kExpandPropertyKey_ReadyTask"
#define kExpandPropertyKey_CancelTask            @"kExpandPropertyKey_CancelTask"

#define kExpandPropertyKey_Snapshotting          @"kExpandPropertyKey_Snapshotting"
#define kExpandPropertyKey_SegmentControl        @"kExpandPropertyKey_SegmentControl"


#define kExpandPropertyKey_H5WebViewController_will_loadErrorHtml             @"H5WebViewController_will_loadErrorHtml"


// navBar动画 底部bar的tag
#define kH5NavigationBarImageViewTag             10000



// 新框架params字典key定义
#define kPSDSessionData             @"kPSDSessionData"
#define kPSDSessionPopData          @"kPSDSessionPopData"
#define kPSDSessionOriginalParams   @"kPSDSessionOriginalParams"
#define kPSDSessionResumeParams     @"kPSDSessionResumeParams"
#define kPSDSessionPSDType          @"kPSDSessionPSDType"
#define kPSDSessionPreRenderQueue   @"kPSDSessionPreRenderQueue"
#define kPSDSessionH5Mode           @"kPSDSessionH5Mode"
#define kPSDSessionH5IsAuthed       @"kPSDSessionH5IsAuthed"
#define kPSDSessionLaunchParams     @"kPSDSessionLaunchParams"
#define kPSDSessionReservedParams   @"kPSDSessionReservedParams"

#define kPSDSceneOptionsParam       @"kPSDSceneOptionsParam"
#define kPSDSceneStartRender        @"kPSDSceneStartRender"
#define kPSDSceneFinishRender       @"kPSDSceneFinishRender"
#define kPSDSceneFavoritesInfo      @"kPSDSceneFavoritesInfo"
#define kPSDSceneAddAsChildVc       @"kPSDSceneAddAsChildVc"
#define kPSDSceneIsPreRender        @"kPSDSceneIsPreRender"




//**********************************JSApis******************************//

#define kH5JSApi_numInput                           @"numInput"
#define kH5JSApi_inputFocus                         @"inputFocus"
#define kH5JSApi_inputBackFill                      @"inputBackFill"
#define kH5JSApi_numInputReset                      @"numInputReset"
#define kH5JSApi_inputBlur                          @"inputBlur"
#define kH5JSApi_hideCustomKeyBoard                 @"hideCustomKeyBoard"
#define kH5JSApi_resizeCustomKeyBoard               @"resizeNativeKeyBoardInput"
#define kH5JSApi_resetCustomKeyBoard                @"resetNativeKeyBoardInput"
#define kH5JSApi_UpdateCustomKeyBoard               @"updateNativeKeyBoardInput"
#define kH5JSApi_createInput                        @"createInput"
#define kH5JSApi_hideBackButton                     @"hideBackButton"
#define kH5JSApi_showBackButton                     @"showBackButton"
#define kH5JSApi_showAlert                          @"showAlert"
#define kH5JSApi_alert                              @"alert"
#define kH5JSApi_confirm                            @"confirm"
#define kH5JSApi_prompt                             @"prompt"
#define kH5JSApi_showFavorites                      @"showFavorites"
#define kH5JSApi_hideFavorites                      @"hideFavorites"
#define kH5JSApi_showPopMenu                        @"showPopMenu"
#define kH5JSApi_hidePopMenu                        @"hidePopMenu"
#define KH5JSApi_enableSPDY                         @"enableSPDY"




//**********************************Event******************************//

#define kH5Event_Scene_WebView_Reload                   @"scene.webview.reload"
#define kH5Event_Scene_NavigationBar_ChangeColor        @"scene.NavigationBar.ChangeColor"
#define kH5Event_Service_RPC_Finished                   @"service.rpc.finished"
#define kH5Event_Session_KeepAlive_Before               @"session.keepAlive.before"
#define kH5Event_Scene_Pre_Render                       @"scene.pre.render"
#define kNBEvent_Scene_LoadRequest_First_Start          @"scene.loadRequest.first.start" //
#define kH5Event_Service_Browser_RestartTrueAppId       @"service.browser.restartTrueAppId"
#define kH5Event_Scene_Jsapi_GetAuthCode_Before         @"scene_jsapi_getAuthCode_before"
#define kH5Event_Scene_Gesture_Start_Before             @"scene.gesture.start.before"
#define kH5Event_Service_App_Should_Delay_Release       @"service.app.should.delay.release"
#define kH5Event_Scene_BarButtonTheme_Set               @"scene.barButtonTheme.set"


//**********************************UI******************************//
#define kH5_NavigationBar_Default_Color             [UIColor whiteColor]




//**********************************ERROR******************************//

// 错误域
#define H5ErrorDomainNetwork  @"H5ErrorDomainNetwork"     // 网络错误
#define H5ErrorDomainVerify   @"H5ErrorDomainVerify"      // 校验错误

// 校验错误码
typedef NS_ENUM(NSInteger, H5VerifyErrorCode) {
    H5VerifyErrorCodeUrlVerifyFailed = 0    // 入口url校验失败
};

//**********************************FLAG******************************//

#define kH5Flag_independentSession @"kH5Flag_independentSession"
#define kH5Flag_currentappShouldForceExit  @"kH5Flag_currentappShouldForceExit"
#define kH5Flag_shouldForceNotUseCachedApp  @"kH5Flag_shouldForceNotUseCachedApp"
#define kH5DefaultColor 0xFFFFFFFF
#define kH5WhiteColor 0xFFFFFF
#define kH5Flag_didRedirectResponseOmitErrorPage  @"kH5Flag_didRedirectResponseOmitErrorPage"
