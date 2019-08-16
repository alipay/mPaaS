//
//  H5WebViewInterface.h
//  Nebula
//
//  Created by Glance on 2018/9/20.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol H5ServiceDelegate;
@protocol H5WebViewInterface <NSObject>

#pragma mark Inspecting the View Information
// The scroll view associated with the web view.
@property (nonatomic, readonly, strong) UIScrollView *scrollView;
// The active URL.
@property (nullable, nonatomic, readonly, copy) NSURL *URL;

#pragma mark Responding to Web View Changes
// only set delegate if you use subView mode, maybe `H5Service createWebViewWithVC`, of nebula,
// else use `nebula events` instead of `delegate`, such as kEvent_Navigation_Start, kEvent_Navigation_Complete, kEvent_Navigation_Error,
// kEvent_Page_Load_Start, kEvent_Page_Load_Complete, kEvent_Page_Load_Error
@property (nonatomic, weak) id<H5ServiceDelegate> delegate;

#pragma mark Loading Content

// The URL request identifying the location of the content to load.
@property (nullable, nonatomic, readonly, strong) NSURLRequest *request;
// A Boolean value indicating whether the receiver is done loading content.
@property(nonatomic, readonly, getter=isLoading) BOOL loading;
// Sets the main page contents, MIME type, content encoding, and base URL.
- (void)loadData:(NSData *)data MIMEType:(NSString *)MIMEType textEncodingName:(NSString *)textEncodingName baseURL:(NSURL *)baseURL;
// Sets the main page content and base URL.
- (void)loadHTMLString:(NSString *)string baseURL:(nullable NSURL *)baseURL;
// The URL request identifying the location of the content to load.
- (void)loadRequest:(NSURLRequest *)request;
// Stops the loading of any web content managed by the receiver.
- (void)stopLoading;
// Reloads the current page.
- (void)reload;

#pragma mark Executing JavaScript
// Evaluates a JavaScript string.
- (void)evaluateJavaScript:(NSString *)javaScriptString completionHandler:(void (^ _Nullable)(_Nullable id, NSError * _Nullable error))completionHandler;

#pragma mark Navigating
// A Boolean value indicating whether the receiver can move backward.
@property (nonatomic, readonly, getter=canGoBack) BOOL canGoBack;
// A Boolean value indicating whether the receiver can move forward.
@property (nonatomic, readonly, getter=canGoForward) BOOL canGoForward;

// Loads the previous location in the back-forward list.
- (void)goBack;
// Loads the next location in the back-forward list.
- (void)goForward;

#pragma mark Setting Web Content Properties

// A Boolean value determining whether the webpage scales to fit the view and the user can change the scale.
@property (nonatomic) BOOL scalesPageToFit;

@end

NS_ASSUME_NONNULL_END
