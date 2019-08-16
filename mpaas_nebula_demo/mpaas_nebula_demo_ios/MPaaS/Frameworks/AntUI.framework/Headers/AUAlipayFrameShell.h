//
//  AUAlipayFrameShell.h
//  AntUIShell
//
//  Created by niki on 2019/4/3.
//  Copyright © 2019年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AUAlipayFrameShell : NSObject

+ (UINavigationController *)currentNaviController;

+ (UIViewController *)visibleViewController;

/////////////////////////////////////////////////////////////
//////////////////////  DTVC notify name  ///////////////////
/////////////////////////////////////////////////////////////

+ (UIWindow *_Nullable)contextWindow;

+ (UIViewController *_Nullable)currentTopController;

+ (NSString *_Nonnull)viewWillDisappearNotificationName;

+ (NSString *_Nonnull)viewDidAppearNotificationName;

/**
* 如果是Native应用，返回的是Controller的Class"Native:${ClassName}"
* 如果是WebViewController，返回的是"URL:${URL}"
*/
+ (NSString *_Nullable) currentTopControllerIdenfier;

/**
 打开URL
 
 @param urlString urlString
 */
+ (void)openURL:(NSString *)urlString;

/*
 * json 字符串解析，解析获取字典
 */
+ (id)jsonString_deserialize:(NSString *)jsonString;

/*
 * 获取H5域名
 */
//+ (NSURL *)getWebViewURL:(UIViewController *)vc;


/*
 * 获取H5appId
 */
+ (NSString *)getAppIdWithVC:(UIViewController *)vc;

/*
 * 判断当前H5页面是否是当前H5App的首页
 */
+ (BOOL)isHomePageForWebVC:(UIViewController *)vc;

/*
 * 获取当前字符串的md5值
 */
+ (NSString *)getMD5WithString:(NSString *)string;

@end

NS_ASSUME_NONNULL_END
