#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_TitleBar_AUCustomNavigationBar//程序自动生成
//
//  APCustomNavigationView.h
//  APExtUI
//
//  Created by yangwei on 16/6/1.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AUView.h"
#import "AUButton.h"


//#########################################################
//文档地址 : https://yuque.antfin-inc.com/antui/auidoc/ios_aucustomnavigationbar
//#########################################################
/*
 自定义导航栏使用说明：
 1、iOS和Android的titleView接口的最大高度  我们不做限制（但最大不会超过导航栏的高度）
 2、UED对titleView有个高度限制（目前是30个逻辑像素），但考虑到现在titleview在业务方使用的多样性（无法用一个高度限制住业务），这个高度我们在接口层面不做强制限制，但我们会提供一个参数如kNavBarPreferTitleViewHeight，来提供给业务调用
 3、导航栏titleView的优先级大于title，也就是说导航栏有titleView的情况下，title的任何设置，对导航栏的视觉无影响
 */
// 蚂蚁规范导航栏自定义titleview最大高度 30

#define UI_AUCustomNavigationBar

/**
 自定义透明导航栏，主要用于导航栏需要透明的场景
 主要是用原生的导航栏切换会有视觉体验问题，故写此类
 注意：title和titleview同时存在的情况下优先展示titleview，titleview被置空后如果title有值则展示出titlelabel，与系统导航栏展示逻辑保持一致
 */
@interface AUCustomNavigationBar : UIView

@property(nonatomic, strong) UIView *backgroundView;              // 毛玻璃背景view

@property(nonatomic, strong) NSString *backButtonTitle;           // 返回按钮title（默认无）
@property(nonatomic, strong) UIColor *backButtonTitleColor;       // 返回按钮title颜色
@property(nonatomic, strong) UIImage *backButtonImage;            // 返回按钮图片

@property(nonatomic, strong) NSString *title;                     // 标题
@property(nonatomic, strong) UIColor *titleColor;                 // 标题颜色

@property(nonatomic, strong) NSString *rightItemTitle;            // 右侧item title
@property(nonatomic, strong) UIColor *rightItemTitleColor;        // 右侧item title颜色
@property(nonatomic, strong) UIImage *rightItemImage;             // 右侧item 图片
@property(nonatomic, strong) UIView *titleView;                   // 自定义titleview
@property(nonatomic, strong) NSArray <AUButton *> *rightItemList; // 右侧支持多个item
/**
 * 右侧item的VoiceOver提示文案,
 * 左侧item默认为“返回”
 * 右侧item默认是rightItemTitle，如果没有设置rightItemTitle，需要手动设置此属性来支持VoiceOver
 */
@property(nonatomic,strong) NSString *rightItemVoiceOverText;

@property(nonatomic,strong) NSString *leftItemVoiceOverText;

/**
 *  创建指定透明的导航栏View。
 *
 *  （1）此导航栏默认在左侧显示返回箭头图片，不显示返回文本。若当前页面需设置与框架逻辑一致的返回文案，请在VC中重写<code> - (UIView *)customNavigationBar </code>方法
 *  （2）如需设置标题、右侧item、毛玻璃背景，请调用相关接口
 *
 *  @param currentVC 当前VC
 *
 *  @return 透明的导航栏View
 */
+ (AUCustomNavigationBar *)navigationBarForCurrentVC:(UIViewController *)currentVC;

+ (CGFloat) defaultHeight ;

/*  调用navigationBarForCurrentVC方法自带默认的返回样式以及点击事件响应，提供以下方式重置返回item的点击事件
 *  @param target 自定义LeftItem的target
 *  @param action 自定义LeftItem的action
 */
- (void)resetNaviBarLeftItemTarget:(id)target action:(SEL)action;

/**
 *  设置毛玻璃背景View，默认透明度为0
 */
- (void)setNavigationBarBlurEffective;

// 自定义毛玻璃效果类型
- (void)setNavigationBarBlurEffectiveWithStyle:(UIBlurEffectStyle)style;

/**
 *  创建导航栏右侧item
 *
 *  @param rightItemTitle    显示的文本
 *  @param target            target
 *  @param action            action
 *
 */
- (void)setNavigationBarRightItemWithTitle:(NSString *)rightItemTitle target:(id)target action:(SEL)action;

/**
 *  创建导航栏右侧item
 *
 *  @param rightItemImage    显示的图片
 *  @param target            target
 *  @param action            action
 *
 */
- (void)setNavigationBarRightItemWithImage:(UIImage *)rightItemImage target:(id)target action:(SEL)action;


/**
 *  创建导航栏左侧item
 *
 *  @param leftItemTitle     显示的文本
 *  @param target            target
 *  @param action            action
 *
 */
- (void)setNavigationBarLeftItemWithTitle:(NSString *)leftItemTitle target:(id)target action:(SEL)action;

/**
 *  创建导航栏左侧item
 *
 *  @param leftItemImage     显示的图片
 *  @param target            target
 *  @param action            action
 *
 */
- (void)setNavigationBarLeftItemWithImage:(UIImage *)leftItemImage target:(id)target action:(SEL)action;

/**
 * 展示title边上的小菊花
 * 注意，与系统导航栏上展示的菊花逻辑保持相同，只有设置title才会展示菊花，设置titleview不会展示菊花
 * 注意：标题字数少于5个使用
 */
- (void)startTitleLoading;

/**
 * 消失title边上的小菊花
 * 注意：标题字数少于5个使用
 */
- (void)stopTitleLoading;

/**
 * 修改title边上菊花色值
 * @param trackColor 修改的是
 */
- (void)updateTitleLoadingTrackColor:(UIColor *)trackColor
                       progressColor:(UIColor *)progressColor;

@end



#endif//程序自动生成
