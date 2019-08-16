//
//  NBServiceDefines.h
//  NBService
//
//  Created by chenwenhong on 15/8/21.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#ifndef NBService_NBServiceDefines_h
#define NBService_NBServiceDefines_h

#define kNBBundleName                          @"NebulaSDK.bundle"

// session expando
#define kNBSessionPopData                       @"kNBSessionPopData"
#define kNBSessionResumeParams                  @"kNBSessionResumeParams"
#define kNBSessionOriginalParams                @"kNBSessionOriginalParams"

//*******************************Notification***************************//
#pragma mark - Notification
// 配置信息更新
#define kNBNotif_Configuration_Update               @"kNBNotif_Configuration_Update"
#define kNBNotif_Configuration_Update_Key_Status    @"status"
// app列表状态
typedef NS_ENUM(NSUInteger, NBConfigurationUpdateStatus) {
    NBConfigurationUpdateStatus_Updating = 0, // 更新中
    NBConfigurationUpdateStatus_Success, // 更新成功
    NBConfigurationUpdateStatus_Fail, // 更新失败
};


//*******************************Function***************************//
#pragma mark - Function

#define NB_DEFINE_FUNCTION(returnType, var)               \
- (id)var                                                 \
{                                                         \
if (_##var == nil) {                                  \
_##var = [[returnType alloc] init];               \
}                                                     \
return _##var;                                        \
}

#define NB_ASSERT(condition) \
if (!condition) {\
NSString *reason = [NSString stringWithFormat:@"\n\n***********************************************************\nNebula抛出的断言（Kernel Assert）:\n函数:%s-%d \ncondition=%s\n\n", __FUNCTION__, __LINE__, #condition];\
NSAssert(condition, reason);\
}

#define NB_ASSERT2(condition, desc) \
if (!condition) {\
NSString *reason = [NSString stringWithFormat:@"\n\n***********************************************************\nNebula抛出的断言（Kernel Assert）:\n函数:%s-%d \ncondition=%s desc=%@\n\n", __FUNCTION__, __LINE__, #condition, desc];\
NSAssert(condition, reason);\
}


#define kNBWebView_Options                             @"__webview_options__"

//*******************************Options***************************//
#pragma mark - Options

#define kNBOptions_NBLId                          @"nbl_id"
#define kNBOptions_NBLId2                         @"appId"
#define kNBOptions_Url                            @"url"
#define kNBOptions_DefaultTitle                   @"defaultTitle"
#define kNBOptions_ShowTitleBar                   @"showTitleBar"
#define kNBOptions_ShowStatusBar                  @"showStatusBar"
#define kNBOptions_ShowLoading                    @"showLoading"
#define kNBOptions_CloseButtonText                @"closeButtonText"
#define kNBOptions_ReadTitle                      @"readTitle"
#define kNBOptions_BizScenario                    @"bizScenario"
#define kNBOptions_BackBehavior                   @"backBehavior"
#define kNBOptions_PullRefresh                    @"pullRefresh"
#define kNBOptions_ToolbarMenu                    @"toolbarMenu"
#define kNBOptions_ShowProgress                   @"showProgress"
#define kNBOptions_DefaultSubtitle                @"defaultSubtitle"
#define kNBOptions_BackgroundColor                @"backgroundColor"
#define kNBOptions_GestureBack                    @"gestureBack"
#define kNBOptions_CanPullDown                    @"canPullDown"
#define kNBOptions_ShowOptionMenu                 @"showOptionMenu"
#define kNBOptions_ShowTitleLoading               @"showTitleLoading"
#define kNBOptions_ShowDomain                     @"showDomain"
#define kNBOptions_PushingURLString               @"pushingURLString"

#define kNBOptions_UrlShort                       @"u"
#define kNBOptions_DefaultTitleShort              @"dt"
#define kNBOptions_ShowTitleBarShort              @"st"
#define kNBOptions_ShowStatusBarShort             @"ss"
#define kNBOptions_ShowLoadingShort               @"sl"
#define kNBOptions_CloseButtonTextShort           @"cb"
#define kNBOptions_ReadTitleShort                 @"rt"
#define kNBOptions_BizScenarioShort               @"bz"
#define kNBOptions_BackBehaviorShort              @"bb"
#define kNBOptions_PullRefreshShort               @"pr"
#define kNBOptions_ToolbarMenuShort               @"tm"
#define kNBOptions_ShowProgressShort              @"sp"
#define kNBOptions_DefaultSubtitleShort           @"ds"
#define kNBOptions_BackgroundColorShort           @"bc"
#define kNBOptions_GestureBackShort               @"gb"
#define kNBOptions_CanPullDownShort               @"pd"
#define kNBOptions_ShowOptionMenuShort            @"so"
#define kNBOptions_ShowTitleLoadingShort          @"tl"
#define kNBOptions_ShowDomainShort                @"sd"

// back behavior
#define kNBBackBehaviorPop     @"pop"
#define kNBBackBehaviorBack    @"back"

//*******************************Session Events***************************//
#pragma mark - Session Events

#define kNBEvent_Session_Pause         @"session.pause"   // 保活功能，退出使用，到后台保活
#define kNBEvent_Session_Resume        @"session.resume"  // 保活功能，从后台保活恢复使用

//*******************************Scene Events***************************//
#pragma mark - Scene Events

// title View
#define kNBEvent_Scene_TitleView_Create_Before         @"scene.titleView.create.before" // 监听该事件，可以调用preventDefault阻止默认行为（创建默认的titleView），若要自定义titleView，则设置其`titleView`，自定义的titleView要实现协议NBNavigationTitleViewProtocol
#define kNBEvent_Scene_TitleView_Create_After          @"scene.titleView.create.after" // 监听该事件，可以获取titleView，并可以改变它的属性
#define kNBEvent_Scene_TitleView_Title_Set             @"scene.titleView.title.set" // 监听该事件，可以获取或设置title
#define kNBEvent_Scene_TitleView_Title_Click           @"scene.titleView.title.click" // 监听该事件，可以调用preventDefault阻止默认行为（默认是向h5页面发送事件kNBPageJSApi_TitleClick）
#define kNBEvent_Scene_TitleView_Subtitle_Click        @"scene.titleView.subtitle.click" // 监听该事件，可以调用preventDefault阻止默认行为（默认是向h5页面发送事件kNBPageJSApi_SubtitleClick）
#define kNBEvent_Scene_TitleView_RightIcon_Click        @"scene.titleView.righticon.click" // 监听该事件，可以调用preventDefault阻止默认行为（默认是向h5页面发送事件kNBEvent_Scene_TitleView_RightIcon_Click）
#define kNBEvent_Scene_TitleView_All                   @"scene.titleView.*"


// navitaion item btn
#define kNBEvent_Scene_NavigationItem_Left_Back_Create_Before   @"scene.navigationItem.left.back.create.before" // 监听该事件，可以调用preventDefault阻止默认行为（创建默认的返回按钮），若要自定义返回按钮，则设置其`customView`
#define kNBEvent_Scene_NavigationItem_Left_Back_Create_After    @"scene.navigationItem.left.back.create.after" // 监听该事件，可以获取返回按钮，并设置它的属性
#define kNBEvent_Scene_NavigationItem_Left_Back_Click           @"scene.navigationItem.left.back.click" // 监听该事件，可以调用preventDefault阻止默认行为（默认是返回行为），并自己实现返回逻辑
#define kNBEvent_Scene_NavigationItem_Left_Back_All             @"scene.navigationItem.left.back.*"


#define kNBEvent_Scene_NavigationItem_Left_Close_Create_Before  @"scene.navigationItem.left.close.create.before" // 监听该事件，可以调用preventDefault阻止默认行为（创建默认的关闭按钮），若要自定义关闭按钮，则设置其`customView`
#define kNBEvent_Scene_NavigationItem_Left_Close_Create_After   @"scene.navigationItem.left.close.create.after" // 监听该事件，可以获取关闭按钮，并设置其属性
#define kNBEvent_Scene_NavigationItem_Left_Close_Click          @"scene.navigationItem.left.close.click" // 监听该事件，可以调用preventDefault阻止默认行为（默认是关闭行为），并自己实现关闭行为
#define kNBEvent_Scene_NavigationItem_Left_Close_All            @"scene.navigationItem.left.close.*"


#define kNBEvent_Scene_NavigationItem_Right_Setting_Create_Before  @"scene.navigationItem.right.setting.create.before" // 监听该事件，可以调用preventDefault阻止默认行为（默认是创建设置按钮），若要自定义设置按钮，则设置其`customView`，自定义的customView要实现协议NBSettingButtonProtocol
#define kNBEvent_Scene_NavigationItem_Right_Setting_Create_After   @"scene.navigationItem.right.setting.create.after" // 监听该事件，可以获取设置按钮，并设置其属性

#define kNBEvent_Scene_NavigationItem_Right_Setting_Click          @"scene.navigationItem.right.setting.click" // 监听该事件，可以调用preventDefault阻止默认行为（默认是打开分享等控制面板），并自己实现设置行为

#define kNBEvent_Scene_NavigationItem_Right_Setting_Change         @"scene.navigationItem.right.setting.change" //

#define kNBEvent_Scene_NavigationItem_Right_Setting_All            @"scene.navigationItem.right.setting.*"


#define kNBEvent_Scene_NavigationItem_Right_SubSetting_Create_Before  @"scene.navigationItem.right.subsetting.create.before"
#define kNBEvent_Scene_NavigationItem_Right_SubSetting_Create_After   @"scene.navigationItem.right.subsetting.create.after"
#define kNBEvent_Scene_NavigationItem_Right_SubSetting_Click          @"scene.navigationItem.right.subsetting.click"


// toolbar Menu
#define kNBEvent_Scene_ToolbarMenu_Create_Before           @"scene.toolbarMenu.create.before" // 监听该事件，可以调用preventDefault阻止默认行为（默认是创建toolbarMenu），若要自定义toolbarMenu，则设置其`toolbarMenu`，自定义的toolbarMenu要实现协议NBToolbarMenuProtocol
#define kNBEvent_Scene_ToolbarMenu_Create_After            @"scene.toolbarMenu.create.after" // 监听该事件，可以获取toolbarMenu，并设置其属性
#define kNBEvent_Scene_ToolbarMenu_Select                  @"scene.toolbarMenu.select"
#define kNBEvent_Scene_ToolbarMenu_Create_All              @"scene.toolbarMenu.*"


// progress View
#define kNBEvent_Scene_ProgressView_Create_Before          @"scene.progressView.create.before" // 监听该事件，可以调用preventDefault阻止默认行为（默认是创建进度条），若要自定义进度条，则设置其`progressView`，自定义的progressView需要实现协议NBProgressViewProtocol
#define kNBEvent_Scene_ProgressView_Create_After           @"scene.progressView.create.after" // 监听该事件，可以获取进度条progressView，并设置其属性
#define kNBEvent_Scene_ProgressView_Create_All             @"scene.progressView.create.*"

// request
#define kNBEvent_Scene_LoadRequest_First                   @"scene.loadRequest.first" //
#define kNBEvent_Scene_LoadRequest_All                     @"scene.loadRequest.*" //


// layout
#define kNBEvent_Scene_Layout_WebView_Before               @"scene.layout.webview.before"
#define kNBEvent_Scene_Layout_WebView_After                @"scene.layout.webview.after"
#define kNBEvent_Scene_Layout_WebView_All                  @"scene.layout.webview.*"

// service发出的事件：scene create event
#define kNBEvent_Scene_Create_Before                       @"scene.create.before" // 监听该事件，可以获取context
#define kNBEvent_Scene_ContentView_Fallback                @"scene.ContentView.Fallback" // 监听该事件，可以获取context

//scrollView
#define kNBEvent_Scene_ScrollView_DidScroll                @"scene.scrollview.didscroll"

//component
#define kNBEvent_Scene_Component_FullScreen                @"scene.component.fullScreen"
//**********************************JSApis******************************//
#pragma mark - JSApis

// titlebar
#define kNBJSApi_ShowTitleBar                          @"showTitlebar"
#define kNBJSApi_HideTitleBar                          @"hideTitlebar"
#define kNBJSApi_ShowStatusBar                         @"showStatusBar"
#define kNBJSApi_HideStatusBar                         @"hideStatusBar"

// navigation title view
#define kNBJSApi_SetTitle                              @"setTitle"
#define kNBJSApi_ShowTitleLoading                      @"showTitleLoading"
#define kNBJSApi_HideTitleLoading                      @"hideTitleLoading"

// loadingView
#define kNBJSApi_ShowLoading                           @"showLoading"
#define kNBJSApi_HideLoading                           @"hideLoading"

// option Menu
#define kNBJSApi_SetOptionMenu                         @"setOptionMenu"
#define kNBJSApi_ShowOptionMenu                        @"showOptionMenu"
#define kNBJSApi_HideOptionMenu                        @"hideOptionMenu"

// toolbar Menu
#define kNBJSApi_ShowToolbar                           @"showToolbar"
#define kNBJSApi_HideToolbar                           @"hideToolbar"
#define kNBJSApi_SetToolbarMenu                        @"setToolbarMenu"

// monitor
#define kNBJSApi_H5Monitor                             @"h5Monitor"
#define kNBJsApi_H5Report                              @"h5Report"

//**********************************Page JSApis******************************//
#define kNBPageJSApi_OptionMenu                        @"optionMenu"
#define kNBPageJSApi_TitleClick                        @"titleClick"
#define kNBPageJSApi_SubtitleClick                     @"subtitleClick"
#define kNBPageJSApi_AppDidReceiveMemoryWarning        @"appDidReceiveMemoryWarning"
#define kNBPageJSApi_AppWillResignActive               @"appWillResignActive"
#define kNBPageJSApi_AppDidBecomeActive                @"appDidBecomeActive"
#define kNBPageJSApi_ToolbarMenuClick                  @"toolbarMenuClick"

//**********************************Dom Event******************************//
#define kNBDomEvent_AppPause                           @"appPause"
#define kNBDomEvent_AppResume                          @"appResume"
#define kNBDomEvent_PagePause                          @"pagePause"
#define kNBDomEvent_PageResume                         @"pageResume"
#define kNBDomEvent_Pause                              @"pause"
#define kNBDomEvent_Resume                             @"resume"


//**********************************Monitor******************************//
#define kNBMonitor_LogId_PagePerformance                @"monitor.logId.pagePerformance"
#define kNBMonitor_PagePerformance_Key_ContentViewPage  @"contentViewPage" // value NBContentViewPageProfile

//**********************************expandProperty******************************//
#define kNBViewControllerReadTitle                      @"readTitle"
#define kNBViewControllerProxyPassData                  @"kNBViewControllerProxyPassData"


//**********************************Other**************************************//
#pragma mark - Other




#endif


