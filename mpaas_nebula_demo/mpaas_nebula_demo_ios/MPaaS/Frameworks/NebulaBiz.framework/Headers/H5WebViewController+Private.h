//
//  H5WebViewController+Private.h
//  H5Service
//
//  Created by chenwenhong on 15/7/16.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

@class AURefreshView;

@interface H5WebViewController (Private)<UIScrollViewDelegate>
@property(nonatomic) id<NBProgressViewProtocol> progressView;
@property(nonatomic) int titleBarColor;
@property(nonatomic) int bottomLineColor;
@property(nonatomic, strong) NSURLRequest *lastMainRequest;
@property(nonatomic, assign) BOOL isDissmissProcess;
@property(nonatomic, strong) UILabel *webviewDomainLabel;
@property(nonatomic, assign)  BOOL isFromStatusBarHidden;
@property(nonatomic, copy)  NSString *currentTransparentTitle;

@property(nonatomic, assign) BOOL    isWebLoading;

// 前向引用H5WebViewController中的属性，供navSearchBar使用
@property(nonatomic, strong)   NSMutableArray *delayExecList;
@property(nonatomic, readonly) BOOL    isTagViewReady;

// 标识窗口已做alipayScheme跳转
@property(nonatomic, readonly) BOOL    isAlipaySchemeDidRedirect;

//销毁切面标识，窗口已从视图中消失，但实例保持以执行延后逻辑
@property(nonatomic, assign) BOOL isTagEvicted;
@property(nonatomic) BOOL hasSetByBarButtonTheme;

@property(nonatomic, readonly) BOOL    isTilteViewAlignLeft; // 55版本添加，标识当前vc是否需标题栏左移

/**
 * 边缘留白设定，目前用于 TabBar (9.9.5)
 *
 * 如需修改请通过 `+= newValue` 调整，勿直接设置值，以免影响别人的设置。
 */
@property(nonatomic, assign) UIEdgeInsets contentEdgeInsets;

- (void)setErrorTitle:(NSString *)title;
- (void)setNavigationBarHidden:(BOOL)hidden animated:(BOOL)animated;
- (void)adjustWebviewContentInsets;
- (BOOL)isH5App;
- (NSString *)bizType;
- (NSURL *)fixGotoUrl:(NSString *)url;
- (NSString *)currentChannelId;
- (BOOL)isSubViewMode;
- (CGFloat)getOffSetTop;
- (void)updateLastMainRequest:(NSURLRequest *)lastMainRequest;
- (void)decideNavigationBarStyle;
- (void)clearAndBack;
- (BOOL)isWKWebView;
- (void)switchTransparentTitleMode:(BOOL)shouldSetDefault;
- (void)restStatus;
- (BOOL)isApplet;
- (void)setCurrentAppKeepAliveState;
- (void)setCurrentAppNotKeepAlive;
- (void)updateLastOptions:(H5Options *)oldOptions;
- (BOOL)shouldUseNewErrorPage;
- (BOOL)isCustomTitleBar;

- (void)doLoadRequest:(NSURLRequest *)request;

@property(nonatomic, strong) AURefreshView  *refreshHeaderView;
- (void)cusPullRefreshStart;
- (void)cusPullRefreshEnd;
- (void)p_updateLastOptionsArbitrary:(H5Options *)oldOptions;

// -----------------性能log
/**
 自身VC第一次出现的时间戳
 */
@property(nonatomic, assign) NSTimeInterval  firstAppearTS;
/**
 在H5Appdelegate中创建的窗口
 */
@property(nonatomic, assign) BOOL isFromStartApp;

@property(nonatomic, weak) UIImageView  *backgroundImageView;
@end
