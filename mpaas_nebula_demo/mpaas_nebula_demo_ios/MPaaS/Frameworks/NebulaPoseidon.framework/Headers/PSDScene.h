//
//  PSDScene.h
//  Poseidon
//
//  Created by chenwenhong on 14-8-8.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import "PSDKernel.h"
#import <UIKit/UIKit.h>

@class PSDSceneParam;
@class PSDSession;
@class PSDView;

//Scene类：类似一个ViewController。
@interface PSDScene : PSDKernel

@property(nonatomic, strong) PSDView *psdView;

- (PSDSceneParam *)createParam;

- (UIViewController *)viewController;

- (NSArray *)dynamicJsUrls;

- (NSString *)startupParamsJs;

- (NSString *)codeSnippets4InsertAlipayJsBridgeFile;

- (NSArray *)independenceUserScripts;

- (NSArray *)relayOnAlipayJsBridgeUserScripts;

- (void)injectIndependenceJs; // 注入单独的JS文件

- (void)injectJsRelyOnAlipayJsBridge; // 依赖于AlipayJSBridge

/**
 *  @brief 给定一个sceneParam参数，创建一个Scene对象，该Scene对象包含一个View对象
 *
 *  @date 2014-08-08
 *
 *  @param sceneParam 要创建所需要的参数，不能为nil
 *
 *  @return 返回Scene对象
 */
+ (instancetype)sceneWithSceneParam:(PSDSceneParam *)sceneParam parentObject:(PSDKernel *)parentObject;

@end


/**
 *  @brief 创建Scene的参数类
 *
 *  @date 2014-08-08
 *
 *  @return 无
 */
@interface PSDSceneParam : NSObject

@property(nonatomic, strong) Class          viewControllerCls; // default is PSDViewController
@property(nonatomic, strong) Class          contentViewCls; // default is PSDWebVeiw
@property(nonatomic, copy) NSString         *url;
@property(nonatomic, strong) NSDictionary   *expandParams;

@end
