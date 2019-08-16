//
//  H5TabbarManager+Private.h
//  NebulaBiz
//
//  Created by lyusheng on 2019/1/17.
//  Copyright © 2019 Alipay. All rights reserved.
//

#ifndef H5TabbarManager_Private_h
#define H5TabbarManager_Private_h

@interface H5TabbarManager(PrivateDeclare)


/**
 缓存tabBar未创建前的tabBar操作指令
 */
@property(nonatomic, readwrite, strong)  NSMutableArray<void (^)() >* delayTabBarTasks;

/**
 是否是在切换Tab过程中
 */
@property(nonatomic, assign) BOOL isSwitching;

/**
 使用大icon图标
 */
@property(nonatomic, assign) BOOL isLargeIconSize;

/**
 用于占位的tabBar
 */
//@property(nonatomic, strong) UITabBar *placeholderTabBar;

/**
 主Tab的导航栏用于显示各当前选中Tab
 新建变量用于持有主Tab的原有导航栏
 */
@property(nonatomic, strong) UINavigationItem *origNavigationItem;

/**
 各TabItem的创建参数
 */
@property(nonatomic, strong) NSMutableArray<H5TabBarItemData *> *arrItemData;


@property(nonatomic, weak) NSLayoutConstraint *cstTabBarBottom;
@property(nonatomic, weak) NSLayoutConstraint *cstPlaceholdTabBarBottom;
@property(nonatomic, weak) NSLayoutConstraint *cstTabBarHeight;

/**
 创建UITabBar
 
 @param items UITabBarItem数组
 @param backgroundImage TabBar的背景色
 @param shadowImage TabBar分隔线的背景色
 @param selectedIndex 创建时的初始选中项
 */
- (void)p_createTabBarWithItems:(NSArray<H5TabBarItem *> *)items  backgroundImage:(UIImage *)backgroundImage shadowImage:(UIImage *)shadowImage selectedIndex:(NSUInteger)selectedIndex disableOnInit:(BOOL)disableOnInit;

/**
 设置UITabBarItem的图标
 
 @param icon 图标的base64或者url
 @param defaultColor 没有图标时默认方块的颜色
 @param item 所设置的UITabBarItem
 @param is4Selected 设置选中状态或不选中
 */
- (void)p_displayIcon:(NSString *)icon defaultColor:(NSNumber *)color scale:(float)scale atBarItem:(H5TabBarItem *)item forSelected:(BOOL)is4Selected;

/**
 用颜色方块设置UITabBarItem的图标
 
 @param dict 设置参数
 */
- (void)p_placeholdTabBarImage:(NSDictionary *)dict;


/**
 新建或取出缓存的子VC
 
 @param tag VC对应的TabBarItem的identifier
 @return 新建或查询结果
 */
- (H5WebViewController *)p_viewController4Tag:(NSString *)tag;

/**
 转换对应identifier的下标序号
 
 @param tag TabBarItem的identifier
 @return 转换结果
 */
- (NSInteger)index4TabBarItemTag:(NSString *)tag;


/**
 转换对应下标号的identifier
 
 @param index TabBarItem的下标
 @return 转换结果
 */
- (NSString *)p_tag4TabBarIndex:(NSUInteger)index;

// newAdded
@property(nonatomic) NSString *tagAtTabBarController;
@property(nonatomic,weak) id nxTabDelegate;

@end

#endif /* H5TabbarManager_Private_h */
