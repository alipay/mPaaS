//
//  TabBarProtocol.h
//  NebulaApp
//
//  Created by lyusheng on 2018/8/13.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol TabBarProtocol <NSObject>

/**
 用于占位的tabBar
 */
@property(nonatomic, strong) UITabBar *placeholderTabBar;
/**
 自定义TabBarController, tabBar控件
 */
@property(nonatomic, readonly) UITabBar *tabBar;

/**
 缓存tabBar未创建前的tabBar操作指令
 */
@property(nonatomic, readonly)  NSMutableArray<void (^)() >* delayTabBarTasks;

/**
 是否持有多Tab的其它子Tab
 */
@property(nonatomic, readonly) BOOL hasChildTab;

/**
 是否为多Tab的子Tab
 */
@property(nonatomic) BOOL isChildTab;

/**
 多Tab时，是否可见
 */
@property(nonatomic, readonly) BOOL isNotVisibleWhenMultiTab;

/**
 是否需要停止手动补齐appearance事件
 */
@property(nonatomic, assign) BOOL stopConstructAppearance;

/**
 持有的子Tab的数目
 */
@property(nonatomic, readonly) NSUInteger childTabCount;

/**
 设置/读取选中tag
 */
@property(nonatomic) NSString *selectedTag;

/**
 作为子Tab被执有的H5WebViewController
 */
@property(nonatomic, weak) H5WebViewController *cachedParentViewController;

/**
 多tab模式时，返回兄弟tab里选中的的H5WebViewController
 非tab模式时，直接返回调用的H5WebViewController
 */
@property(nonatomic, readonly) H5WebViewController *selectedViewController;

/**
 持有创建的子Tab对应的H5WebViewController
 键值对中，键名为对应Tab的identifier
 */
@property(nonatomic, strong) NSDictionary<NSString *, H5WebViewController *> *cachedChildViewControllers;

@property(nonatomic, assign) BOOL hasAlphaBackgroundColor;

/**
 创建UITab对象
 
 @param createConfig 创建参数
 @param index 初始选中Tab的下标
 */
- (void)createTabBarWithConfig:(NSDictionary *)createConfig selectedIndex:(NSUInteger)index;

// 适配VC类中的gapHeight
- (void)setTabBarGapHeight:(CGFloat)gapHeight;

// 适配iphonex
- (void)setTabBarHeight:(CGFloat)height;

- (void)adjustTabBarContentEdgeInsetsBottom:(CGFloat)bottom;

// 10.1.35 小程序显示tabBar
- (void)showTabBarWithAnimationType:(NSString *)animationType
                           animated:(BOOL)animated;

// 10.1.35 小程序隐藏tabBar
- (void)hideTabBarWithAnimationType:(NSString *)animationType
                           animated:(BOOL)animated;

/**
 入口url与tabBar配置的匹配算法
 
 @param createURLStr 入口url
 @param configDict tabBar配置
 @param isTinyApp 小程序区别编码
 @return 匹配结果，失败时为NSNotFound
 */
+ (NSInteger)indexWithUrl:(NSString *)createURLStr tabConfigDict:(NSDictionary *)configDict isTinyApp:(BOOL)isTinyApp;


/**
 在发起分享或收藏，生成的链接是否应加上enableTabBar=NO
 */
- (BOOL)shouldDisableTabBarWhenShare:(NSString *)url;

/**
 创建占位的UITab对象
 
 @param itemCount Tab上的icon个数
 */
- (void)placeholdTabBarWithItemCount:(NSUInteger)itemCount;

/**
 清除占位的UITab并调整UIWebView布局
 */
- (void)destroyPlaceholderTabBarIfExist;

/**
 设置tab的红点
 
 @param badgeValue -1隐藏红点，否则作为红圈中的字符串
 @param tag 要设置红点Tab的identifier
 */
- (void)setTabBarBadge:(NSString *)badgeValue tag:(NSString *)tag;


/**
 动态设置icon图标
 
 @param icon 图标的base64或者url
 @param tag 要设置红点Tab的identifier
 @param is4Selected 设置选中或普通状态
 */
- (void)setIcon:(NSString *)icon scale:(float)scale atTag:(NSString *)tag forSelected:(BOOL)is4Selected;

/**
 通过tag判断index是否存在
 
 @param tag 要设置红点Tab的identifier
 */
- (NSInteger)index4TabBarItemTag:(NSString *)tag;

- (NSString *)p_tag4TabBarIndex:(NSUInteger)index;

- (void)updateChildTabNavigationItems;
@end
