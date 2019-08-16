//
//  H5WKWebView.h
//  NebulaBiz
//
//  Created by theone on 16/12/1.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <WebKit/WebKit.h>

@protocol H5WebViewObserveProtocol;

@interface H5WKWebView : WKWebView
@property(nonatomic, weak) id<H5WebViewObserveProtocol> h5webViwObserveProtocol;
- (void)addObserveWithKeyPath:(NSString *)keyPath options:(NSKeyValueObservingOptions)options context:(void *)context;
@end
