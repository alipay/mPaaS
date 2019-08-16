//
//  DTNavigationBarAppearanceProtocol.h
//  APMobileFramework
//
//  Created by yangwei on 16/5/19.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol DTNavigationBarAppearanceProtocol <NSObject>

@optional

/**
 *  这个DTViewController是否要自动隐藏navigationBar，默认为NO。业务某个ViewController需要隐藏NavigationBar可以重载此方法并返回YES.
 */
- (BOOL)autohideNavigationBar;

/**
 *  当前VC隐藏导航栏后，如果需要设置一个全透明的导航栏，且当前页面需设置与框架逻辑一致的返回文案，请重载此方法，并返回一个APCustomNavigationView的实例
 */
- (UIView *)customNavigationBar;

/**
 *  如果某个viewcontroller希望自己的titlebar是不透明，并且指定一个颜色，可以重写这个方法，并返回希望的颜色。
 *  仅限于被Push的VC，tabbar里的VC还是不允许修改navigationBar的半透明属性
 */
- (UIColor *)opaqueNavigationBarColor;

/**
 *  如果某个viewcontroller希望修改状态栏的样式，请重写此方法，并返回希望的style
 */
- (UIStatusBarStyle)customStatusBarStytle;

/**
 *  如果某个viewcontroller希望修改导航栏标题的颜色，请重写此方法，并返回希望的颜色
 */
- (UIColor *)customNavigationBarTitleColor;

/**
 *  如果某个viewcontroller希望修改导航栏返回按钮的文本颜色，请重写此方法，并返回希望的颜色
 */
- (UIColor *)customNavigationBarBackButtonTitleColor;

/**
 *  如果某个viewcontroller希望修改导航栏返回按钮的箭头图片，请重写此方法，并返回希望设置的图片
 */
- (UIImage *)customNavigationBarBackButtonImage;

/**
 *  如果某个viewcontroller希望修改导航栏loading view的颜色，请重写此方法，并返回希望的颜色
 *  第一个颜色：圆环的颜色
 *  第二个颜色：旋转进度条的颜色
 *  如果使用APCommonUI中的APActivityIndicatorView，支持这两个颜色的设置。
 *  如果使用系统的UIActivityIndicatorView或其他自定义的菊花控件，框架只会向其发送setColor:消息，并传递数组中的第一个颜色。
 */
- (NSArray *)customNavigationBarLoadingViewColors;

@end
