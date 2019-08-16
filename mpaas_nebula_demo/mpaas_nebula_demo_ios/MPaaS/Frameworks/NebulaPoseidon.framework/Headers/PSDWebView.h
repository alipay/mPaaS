//
//  PSDWebView.h
//  Poseidon
//
//  Created by chenwenhong on 14-8-8.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>

@protocol PSDContentViewDelegate;
@protocol PSDExternalWebViewDelegate;
@class PSDContentViewConfiguration;
@protocol PSDViewControllerProtocol;
@protocol PSDContentViewNavigationDelegate;
@protocol PSDContentViewUIDelegate;

@protocol PSDContentViewProtocol <NSObject>
NS_ASSUME_NONNULL_BEGIN
@optional
@property(nonatomic, weak) id<PSDExternalWebViewDelegate>           psdExternalWebViewDelegate;
@property(nonatomic, weak) id<PSDViewControllerProtocol>            psdViewController;
@property(nonatomic, weak) id<PSDContentViewDelegate>               psdContentViewDelegate;
@property(nonatomic, weak) id<PSDContentViewNavigationDelegate>     psdContentViewNavigationDelegate;
@property(nonatomic, weak) id<PSDContentViewUIDelegate>             psdContentViewUIDelegate;
@property(nonatomic, nullable, strong) PSDContentViewConfiguration  *psdConfiguration;
//WKWebView compatible for UIWebView
- (void)loadData:(NSData *)data MIMEType:(NSString *)MIMEType textEncodingName:(NSString *)textEncodingName baseURL:(NSURL *)baseURL;

//@required
@property(nonatomic, readonly, weak) UIView                         *view; // 获取UIView对象
@property(nullable, nonatomic, readonly) UIWindow                   *window;
@property(nonatomic, readonly, nullable, strong) UIScrollView       *scrollView; // only h5
@property(nonatomic, readonly, nullable, strong) NSURLRequest       *request;
@property(nonatomic, readonly) BOOL                                 isLoading;
@property(nonatomic, readonly) BOOL                                 canGoBack;
@property(nonatomic, weak) id                                       delegate;
@property(nonatomic, nullable, copy) NSString                       *channelId;
@property(nonatomic) BOOL                                           scalesPageToFit;
@property(nonatomic) BOOL                                           detectsPhoneNumbers;
@property(nonatomic) UIDataDetectorTypes                            dataDetectorTypes;
@property(nonatomic) BOOL                                           allowsInlineMediaPlayback; // iPhone Safari defaults to NO. iPad Safari defaults to YES
@property (nullable, nonatomic, readonly, copy) NSURL               *URL;//for same with wkwebview
- (void)evaluateJavaScript:(nullable NSString *)js completionHandler:(nullable void (^)(id result, NSError *error))completionHandler;

- (void)loadRequest:(nullable NSURLRequest *)request;
- (void)loadHTMLString:(nullable NSString *)string baseURL:(nullable NSURL *)baseURL;
- (void)reload;
- (void)stopLoading;

- (void)goBack;
- (void)goForward;
NS_ASSUME_NONNULL_END
@end


// 对外接口参数，为了方便调用
@interface PSDContentView : UIView <PSDContentViewProtocol>

@end


//webView基类
@interface PSDWebView : UIWebView <PSDContentViewProtocol>

@end


//webView代理接口
@protocol PSDContentViewDelegate <NSObject>
@optional
- (BOOL)contentView:(nullable PSDContentView *)contentView resizeFrame:(CGRect)frame;

@end

//webView代理接口
@protocol PSDExternalWebViewDelegate <UIWebViewDelegate>

@end


typedef NS_ENUM(NSInteger, PSDContentViewUserScriptInjectionTime) {
    PSDContentViewUserScriptInjectionTimeAtDocumentStart,
    PSDContentViewUserScriptInjectionTimeAtDocumentEnd
};

#ifdef __IPHONE_8_0

@protocol PSDContentViewNavigationDelegate <WKNavigationDelegate>
@end

@protocol PSDContentViewUIDelegate <WKUIDelegate>
@end

@class PSDContentViewUserContentController;

// 配置
@interface PSDContentViewConfiguration : WKWebViewConfiguration

@end


@class PSDContentViewUserScript;
//
@interface PSDContentViewUserContentController : WKUserContentController

@end


/*! A @link WKUserScript @/link object represents a script that can be injected into webpages.
 */
@interface PSDContentViewUserScript : WKUserScript <NSCopying>

@end

#else

@class PSDContentViewUserContentController;

// 配置
@interface PSDContentViewConfiguration : NSObject

@property (nonatomic, strong) PSDContentUserContentController *userContentController;

@end


@class PSDContentViewUserScript;
//
@interface PSDContentViewUserContentController : NSObject

@property (nonatomic, readonly, copy) NSArray *userScripts;

- (void)addUserScript:(PSDContentViewUserScript *)userScript;

- (void)removeAllUserScripts;

@end


/*! A @link WKUserScript @/link object represents a script that can be injected into webpages.
 */
@interface PSDContentUserScript : NSObject <NSCopying>

/* @abstract The script source code. */
@property (nonatomic, readonly, copy) NSString *source;

/* @abstract When the script should be injected. */
@property (nonatomic, readonly) PSDContentViewUserScriptInjectionTime injectionTime;

/* @abstract Whether the script should be injected into all frames or just the main frame. */
@property (nonatomic, readonly, getter=isForMainFrameOnly) BOOL forMainFrameOnly;

/*! @abstract Returns an initialized user script that can be added to a @link WKUserContentController @/link.
 @param source The script source.
 @param injectionTime When the script should be injected.
 @param forMainFrameOnly Whether the script should be injected into all frames or just the main frame.
 */
- (instancetype)initWithSource:(NSString *)source injectionTime:(PSDContentViewUserScriptInjectionTime)injectionTime forMainFrameOnly:(BOOL)forMainFrameOnly;

@end

#endif


