//
//  PSDViewControllerProtocol.h
//  Poseidon
//
//  Created by chenwenhong on 14-9-3.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@class PSDSceneParam;
@class PSDView;
@class PSDScene;
@class PSDSession;
@class PSDContentView;

@protocol PSDViewControllerDelegate;

@protocol PSDViewControllerProtocol <NSObject>

@optional

- (NSArray *)dynamicJsUrls; // 动态注入js数组

- (NSString *)startupParamsJs; // 启动参数js

- (NSString *)codeSnippets4InsertAlipayJsBridgeFile; // 动态插入js片段；该方法是在插入js之前修改js文件

- (void)startFirstLoadRequest:(NSURL *)url; // 如果实现了该方法，需要自己loadRequest；该方法是第一次进入页面发起的请求

- (NSArray *)independenceUserScripts; // PSDWebViewUserScript

- (NSArray *)relayOnAlipayJsBridgeUserScripts; // PSDWebViewUserScript

- (void)injectIndependenceJs; // 注入单独的JS文件

- (void)injectJsRelyOnAlipayJsBridge; // 依赖于AlipayJSBridge

- (NSString *)allJsInjectToJSC; //通过JSC注入的JS

- (BOOL)shouldSkipHandleLoadWithRequest:(NSURLRequest *)request navigationType:(UIWebViewNavigationType)navigationType;//当前VC是否需要忽略特殊的请求
//@required

- (void)associateWeakScene:(PSDScene *)scene sceneParam:(PSDSceneParam *)sceneParam; // scene请用weak引用

- (void)initUI:(PSDView *)contentView delegate:(id<PSDViewControllerDelegate>)delegate;

- (PSDScene *)psdScene;

- (PSDSession *)psdSession;

- (PSDView *)psdView;

- (PSDContentView *)psdContentView;

- (UIViewController *)viewController;

- (void)callHandler:(NSString *)handlerName
             data:(id)data
 responseCallback:(void(^)(id responseData))callback;

- (void)callHandler:(NSString *)handlerName
             data:(id)data
callbackImmediatelyIfJSBridgeNotReady:(BOOL)callbackImmediatelyIfJSBridgeNotReady
 responseCallback:(void (^)(id responseData))callback;

@end

//VC类代理接口
@protocol PSDViewControllerDelegate <NSObject>

- (void)viewController:(UIViewController *)vc loadView:(BOOL)_;

- (void)viewController:(UIViewController *)vc viewDidLoad:(BOOL)_;

- (void)viewController:(UIViewController *)vc viewDidUnLoad:(BOOL)_;

- (void)viewController:(UIViewController *)vc viewWillAppear:(BOOL)_;

- (void)viewController:(UIViewController *)vc viewDidAppear:(BOOL)_;

- (void)viewController:(UIViewController *)vc viewDidLayoutSubviews:(BOOL)_;

- (void)viewController:(UIViewController *)vc viewWillDisappear:(BOOL)_;

- (void)viewController:(UIViewController *)vc viewDidDisappear:(BOOL)_;

- (void)viewController:(UIViewController *)vc viewWillDestroy:(BOOL)_;

@end
