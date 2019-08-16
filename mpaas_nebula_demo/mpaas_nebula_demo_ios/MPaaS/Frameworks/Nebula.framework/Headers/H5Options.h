//
//  H5Options.h
//  H5Service
//
//  Created by xuesi on 13-12-14.
//  Copyright (c) 2013年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

#define kBackBehaviorPop     @"pop"
#define kBackBehaviorBack    @"back"

@interface H5Options : NBOptions
@property(nonatomic) BOOL ssoLoginEnabled; // 8.6重新启用这个参数
@property(nonatomic) BOOL offlineH5SsoLoginFirst; // 8.6 有虚拟域名的离线包配置是否需要在入口处做免登
@property(nonatomic, copy) NSString *safePayContext;
@property(nonatomic, copy) NSString *webAppId;
@property(nonatomic) BOOL closeAfterPayFinish;
@property(nonatomic, copy) NSString *appId;
@property(nonatomic, copy) NSString *publicId;
@property(nonatomic) BOOL proxy; //8.3底层有bug，不支持
@property(nonatomic) BOOL prefetchLocation;

@property(nonatomic) BOOL smartToolBar; // 8.4 废弃，传进来的参数不认
@property(nonatomic) CGFloat paddingBottom; // 9.0 不透传
@property(nonatomic) double waitRender; // 9.0
@property(nonatomic, copy) NSString *shareChannels;
@property(nonatomic) BOOL isSsoLoginProMode; // 9.0.1 未绑定淘宝的支付宝账号做免登时，是否要跳转到会员名补全页面，YES的话代表要跳
@property(nonatomic, assign) BOOL showFavorites; // 9.0.1 是否显示收藏，默认NO
@property(nonatomic, assign) BOOL showReportBtn; // 9.0.1 是否显示投诉按钮，默认NO
@property(nonatomic, assign) BOOL interceptJump; //9.0.1 是否拦截url跳出的行为, 默认NO
@property(nonatomic, assign) BOOL transparent; // 9.2 是否背景透明
@property(nonatomic, assign) BOOL transAnimate; // 10.0.18 transparent=YES时是否使用默认动画
@property(nonatomic, assign) BOOL networkIndicator;//9.3 是否显示网络加载小菊花
@property(nonatomic, copy) NSString *transparentTitle; //9.4 titlebar背景是否透明
@property(nonatomic) int titleBarColor; //9.5.2 指定titlebar背景色
@property(nonatomic, assign) double scrollDistance; //9.6.9 titleBar需要滚动多少像素来变成透明度为0.96的状态
@property(nonatomic) int bounceTopColor; //9.9.3  下拉至bounce间缝出现时的颜色，default is -1不设置
@property(nonatomic) int bounceBottomColor; //9.9.3 上拉至bounce间缝出现时的颜色，default is -1不设置

/**
 *  配置入口URL是否强制免登
 *
 *  preAliAutoLogin: 是否在入口URL处强制免登
 */
@property(nonatomic) BOOL preSSOLogin;
@property(nonatomic) BOOL preSSOLoginBindingPage;
@property(nonatomic, copy) NSString *preSSOLoginUrl;


@property(nonatomic) NSString *navSearchBar_type;  //9.9.9 搜索导航栏的类型 'entrance' - 入口页, 'search' - 搜索页
@property(nonatomic) NSString *navSearchBar_placeholder; //9.9.9 搜索导航栏的占位字符串
@property(nonatomic) NSString *navSearchBar_value; //9.9.9 搜索导航栏输入框中的字符串 search only
@property(nonatomic) NSNumber *navSearchBar_maxLength; //9.9.9 搜索导航栏输入框的最大文字长度  search only
@property(nonatomic, assign) BOOL navSearchBar_searchPlaceholder; //10.1.18 搜索导航栏的占位字符串用于搜索

//http://gitlab.alipay-inc.com/nebula/AlipayProjectManager/issues/463
@property(nonatomic, copy) NSString *backBtnImage;//10.0
@property(nonatomic, assign) int backBtnTextColor;//10.0
@property(nonatomic, assign) int titleColor;//10.0

@property(nonatomic, assign) BOOL transparentTitleTextAuto; //10.0.2 标题透明度支持transparentTitle - auto

@property(nonatomic, assign) BOOL canPullUp; // 10.0.20 是否支持上拉，默认是YES
@property(nonatomic, assign) BOOL isAutoSetNavBarStyle;  // 10.0.20 NATIVE创建嵌入区块时是否影响父VC的状态栏，透传给框架。默认为YES,即影响
@property(nonatomic, copy) NSString *audioCategory;  // 10.1.10 音频的category
@property(nonatomic, assign) BOOL hideCloseButton; //10.1.10  是否强制不显示关闭按钮
@property(nonatomic) NSDictionary *shareTokenParams; //10.1.18 吱口令参数
@property(nonatomic, copy) NSString *reportUrl; //10.1.20 举报url
@property(nonatomic, copy) NSString *landscapeOrientation; //10.1.20 旋转方向
@property(nonatomic, copy) NSString *pullRefreshStyle;//10.1.25下拉刷新样式，支持default,和transparent两种
@property(nonatomic, assign) BOOL showThirdDisclaimer;//nebula/AlipayProjectManager#2722
@property(nonatomic, copy) NSString *feedBackExtParams;//nebula/AlipayProjectManager#2766
@property(nonatomic, assign) double pullInterceptDistance;//nebula/AlipayProjectManager#3143 
@property(nonatomic, copy) NSString *backgroundImageUrl;//nebula/AlipayProjectManager#3143 
@property(nonatomic, assign) long long backgroundImageColor;//nebula/AlipayProjectManager#3143
@property(nonatomic, assign) BOOL titlePenetrate; // 10.1.52 导航栏点击穿透
@property(nonatomic, copy) NSString *barButtonTheme; // 10.1.52 导航栏按钮的主题设置 "light"/"default"


@property(nonatomic, strong) NSArray *segWidths; // 10.1.60 标题栏支持分段选择器
@property(nonatomic, strong) NSArray *segTitles;
@property(nonatomic, assign) int segSelectedIndex;
@property(nonatomic, assign) long long segColorNormal;
@property(nonatomic, assign) long long segColorActive;

- (void)mergeWithDictionary:(NSDictionary *)dict;
- (void)dynamicMergeWithDictionary:(NSDictionary *)dict;
// 返回与其它实例比较，不相同的键值对
- (NSDictionary *)diffWithOptions:(H5Options *)otherOptions;


@end
