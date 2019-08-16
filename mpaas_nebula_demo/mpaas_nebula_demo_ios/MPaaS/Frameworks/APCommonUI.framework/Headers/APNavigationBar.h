//
//  APNavigationBar.h
//  APCommonUI
//
//  Created by wenbi on 14-2-11.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

//#import <UIKit/UIKit.h>
#import <AntUI/AUNavigationBar.h>

//@interface UINavigationBar (APNavigationBarExtensions)
//
///**
// *  返回框架导航栏默认title颜色，默认为#000000
// *
// *  @return
// */
//+ (UIColor*)getNavigationBarTitleDefaultColor;
//
///**
// *  返回框架导航栏上item颜色，默认为#108EE9
// *
// *  @return
// */
//+ (UIColor*)getNavigationBarButtonItemDefaultColor;
//
///**
// *  返回框架导航栏颜色，默认为#fffff
// *
// *  @return
// */
//+ (UIColor*)getNavigationBarDefaultColor;
//
///**
// *  获取导航栏底部横线的颜色，默认为#e1e1e1
// *
// *  @return
// */
//+ (UIColor*)getNavigationBarBotLineColor;
//
///**
// * 注意：
// * 1、基类DTViewController在ViewWillAppear里设置了导航栏的默认样式；
// * 2、业务可以通过系统接口或者下面提供的接口来修改导航栏的样式，一般在ViewWillAppear设置；
// * 3、如果VC是DTViewController的子类必须在ViewWillAppear里设置，否则会被覆盖；
// * 4、保证修改后在ViewWillDisappear时通过setNavigationBarDefaultStyle恢复默认样式；
// * 5、如果VC是在UITabBarController容器的首页，不要做上面4的处理，否则切换tab时有覆盖问题。
// */
//
///**
// *
// * 设置默认的导航栏背景，默认设置背景色#ffffff，底部横线#e1e1e1
// *
// */
//- (void)setNavigationBarDefaultStyle;
//
///**
// *
// * 设置默认的导航栏标题样式
// *
// */
//- (void)setNavigationBarDefaultTitleTextAttributes;
//
///**
// *
// * 设置导航栏标题颜色，请在ViewWillAppear里设置，否则会被框架默认颜色覆盖
// *
// */
//- (void)setNavigationBarTitleTextAttributesWithTextColor:(UIColor *)textColor;
//
///**
// *
// * 设置导航栏透明样式
// * 注意：此方法设置导航栏全透明后，返回的动画过程中会产生闪白问题，目前无解，业务请勿使用。如需使用，请评估影响是否可接受
// */
//- (void)setNavigationBarTranslucentStyle;
//
///**
// * 指定导航栏颜色，当translucent为Yes时，有毛玻璃效果
// * 注意：调用此接口后，如有需要，请在此方法之后调用设置底部横线的接口，否则底部横线颜色会被默认颜色#e1e1e1覆盖
// *
// * @param color          显示颜色
// * @param translucent    是否透明
// *
// */
//- (void)setNavigationBarStyleWithColor:(UIColor *)color translucent:(BOOL)translucent;
//
///**
// *  导航栏下面可能有分割线，导致界面不符合一些UI的要求，使用这个方法设置
// *  注意：若自定义了导航栏背景，（包括调用setNavigationBarStyleWithColor：或重写 opaqueNavigationBarColor）
// *  请在修改背景色方法之后调用此接口，否则底部横线颜色会被默认颜色#e1e1e1覆盖
// */
//- (void)setNavigationBarBottomLineColor:(UIColor*)color;
//
///**
// *  业务使用系统方法setBarTintColor,setBackGroundImage,setBackgroundColor设置导航栏颜色时，先调用此方法消除默认效果
// *  否则默认颜色会与系统设置色叠加产生色差
// */
//- (void)resetNavigationBarColor;
//
///**
// *
// *  屏蔽右滑返回取消时，导航栏闪烁的问题，业务方请勿调用
// */
//- (void)setNavigationBarMaskLayerWithtColor:(UIColor *)color;
//
///**
// *  返回导航栏当前的背景色
// *  注意：如果设置了 BarTintColor 或者 BackgroundImage 的话，则获取不到 CurrentColor ，会返回 nil
// *  @return 导航栏当前的背景色
// *  注意：如果设置了 BarTintColor 或者 BackgroundImage 的话，则获取不到 CurrentColor ，会返回 nil
// */
//- (UIColor*)getNavigationBarCurrentColor;
//@end
