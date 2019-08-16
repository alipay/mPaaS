//
//  H5WebViewController.h
//  H5Service
//
//  Created by tgf on 14-1-21.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <NebulaPoseidon/NebulaPoseidon.h>
#import <NebulaSDK/NebulaSDK.h>

@protocol H5WebViewInterface;
@protocol H5ServiceDelegate;
@class H5Options;
@class PSDScene;

@interface H5WebViewController : DTViewController <PSDPluginProtocol, PSDExpandoProtocol>

// JSBridge
@property(nonatomic, weak) id<H5ServiceDelegate>            serviceDelegate;
@property(nonatomic, readonly, strong) PSDView              *contentView;
@property(nonatomic, readonly) PSDScene *scene;
@property(nonatomic, weak) id<PSDViewControllerDelegate>    delegate;

// UI
@property(nonatomic, readonly) BOOL        isLoadingErrorPage;
@property(nonatomic, readonly) UIView<H5WebViewInterface>   *webView;
@property(nonatomic, readonly) UIView           *statesView;
@property(nonatomic, strong) NSArray <id <UIPreviewActionItem>> *customPreviewActionItems NS_AVAILABLE_IOS(9_0);//for 3d touch

// Function
@property(nonatomic, copy) NSString             *interceptUrl;
@property(nonatomic, strong) NSDictionary       *appConfig; // 钱包可用app字典，从Info.plist读取

// startup param
@property(nonatomic, readonly, strong) H5Options    *options;
@property(nonatomic, readonly, strong) NSURL        *url;

@property(nonatomic, strong) NSString *lastPageId;

// 3DTouch
@property(nonatomic, assign) BOOL is3DTouchPeek;
@property(nonatomic, assign) BOOL is3DTouchPop;
@property(nonatomic, readonly) NSString *titleLabelValue;


//右按钮是否可见
@property(nonatomic, assign) BOOL gestureBack;
@property(nonatomic, assign) BOOL isFromNavigationBarHidden;

// JSBridge APIs
/**
 *  注册JSAPI Native端处理逻辑
 *
 *  @param handerName 句柄名
 *  @param handler    处理block
 */
- (void)registerHandler:(NSString *)handerName
                handler:(PSDJsApiHandlerBlock)handler;

/**
 *  注册JSAPI Native端处理逻辑
 *
 *  @param handerName 句柄名
 *  @param isExtern   YES表示是外部业务注册，NO则是JSBridge内部默认回调
 *  @param handler    处理block
 */
- (void)registerHandler:(NSString *)handerName
               isExtern:(BOOL)isExtern
                handler:(PSDJsApiHandlerBlock)handler;

/**
 *  从Native发送消息给H5页面JS
 *
 *  @param message  消息内容
 *  @param callback JS端执行完后回调处理block
 */
- (void)send:(id)message responseCallback:(void(^)(id))callback;

/**
 *  从Native调用H5页面JS函数
 *
 *  @param handlerName 函数名
 *  @param data        函数参数
 *  @param callback    JS端执行完后回调处理block
 */
- (void)callHandler:(NSString *)handlerName
               data:(id)data
   responseCallback:(void(^)(id responseData))callback;

/**
 *  清除当前webview数据并回退一步
 *
 */
- (void)clearAndBack;

/**
 *  确保在ViewDidAppear之后再pushvc到navigationalController
 *
 *  @param viewController vc
 */
- (void)pushViewController:(UIViewController *)viewController animated:(BOOL)animated;

/**
 *  确保在ViewDidAppear之后vc再popTo
 *
 *  @param viewController vc
 */
- (void)popToViewController:(UIViewController *)viewController animated:(BOOL)animated;

- (PSDSession *)session;

- (void)popToWindowOfIndex:(NSInteger)indexPopTo;

- (void)addDelayExecuteTask:(void(^)())task;

@end
