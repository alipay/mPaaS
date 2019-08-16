//
//  MyWebView.h
//  simplewebview
//
//  Created by tgf on 14-8-28.
//  Copyright (c) 2014年 tgf. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>

@protocol H5WebViewObserveProtocol <NSObject>
- (void)h5webViewObserveValueForKeyPath:(NSString *)keyPath ofObject:(id)object change:(NSDictionary *)change context:(void *)context;
@end

///
@interface H5WebView : UIWebView
@property(nonatomic, weak) id<H5WebViewObserveProtocol> h5webViwObserveProtocol;
- (void)addObserveWithKeyPath:(NSString *)keyPath options:(NSKeyValueObservingOptions)options context:(void *)context;
@end

#pragma mark - WebView兼容WKWebView接口

@interface UIWebView ()
@property (nullable, nonatomic, readonly, copy) NSURL               *URL;//for same with wkwebview
- (void)evaluateJavaScript:(NSString *)javaScriptString completionHandler:(void (^)(id result, NSError *error))completionHandler;

@end
