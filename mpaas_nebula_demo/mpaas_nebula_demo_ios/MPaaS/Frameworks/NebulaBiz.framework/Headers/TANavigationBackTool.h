//
//  TANavigationBackTool.h
//  TinyappService
//
//  Created by wrl on 2018/10/30.
//  Copyright © 2018 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

// 内嵌webview 返回按钮隐藏的广播
#define TAEmbedWebViewDidHideBackButtonNotification @"TAEmbedWebViewDidHideBackButtonNotification"

// 内嵌webview 返回按钮显示的广播
#define TAEmbedWebViewDidShowBackButtonNotification @"TAEmbedWebViewDidShowBackButtonNotification"

#define kTATagBackHomeIcon 2018112312
#define TA_navbar_back_btn @"TA_navbar_back_btn"

NS_ASSUME_NONNULL_BEGIN

@interface TANavigationBackTool : NSObject
+ (BOOL)isHomePage:(H5WebViewController *)vc curApp:(NAMApp *)app;
+ (void)hideBackButtonForHomePage:(H5WebViewController *)vc;
+ (void)showBackBarButtonForEmbedWebView:(H5WebViewController *)vc;
@end

NS_ASSUME_NONNULL_END
