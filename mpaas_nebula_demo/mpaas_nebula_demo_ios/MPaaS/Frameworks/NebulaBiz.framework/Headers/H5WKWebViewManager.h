//
//  H5WKWebViewManager.h
//  NebulaBiz
//
//  Created by theone on 16/12/2.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface H5WKWebViewManager : NSObject
+ (BOOL)shouldUseWKWebViewWithAppId:(NSString *)appId
                                url:(NSString *)url
                          isSubView:(BOOL)isSubView
                             params:(NSDictionary *)params;
+ (void)on;
+ (void)un;
+ (WKWebView *)globalWKWebView;
+ (void)recreateGlobalWKWebView;
+ (void)recreateGlobalWKWebView:(BOOL)newProcessPool;
+ (WKWebViewConfiguration *)createWKWebViewConfiguration;
+ (BOOL)shouldUseSharedProcess:(NSDictionary *)expandParams;
+ (BOOL)hasRegisterProtocol;
//+ (void)setRunAtForegroundPriorityWithConfig:(WKWebViewConfiguration *)configuration;
+ (void)syncCookieWithHeaders:(NSDictionary *)headers
                      psdView:(PSDView *)psdview
                  responseUrl:(NSURL *)responseUrl;
@end
