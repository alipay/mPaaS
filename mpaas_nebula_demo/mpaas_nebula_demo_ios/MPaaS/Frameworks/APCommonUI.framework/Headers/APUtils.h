//
//  APUtils.h
//  APCommonUI
//
//  Created by WenBi on 14-1-16.
//  Copyright (c) 2014年 WenBi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AntUI/AntUI.h>

#define APCommonUILoadImage(imageName) \
    AUBundleImage(imageName)

//不要调用！
#define APCommonUIResourcePath(resName, resType) \
    [[NSBundle mainBundle] pathForResource:[NSString stringWithFormat:@"APCommonUI.bundle/%@", resName] ofType:resType]

#define APCommonUIGetSystemVersion() \
    ([[[UIDevice currentDevice] systemVersion] floatValue])

#define APCommonUIIsIphone6Plus \
    (CGSizeEqualToSize([UIScreen mainScreen].bounds.size, CGSizeMake(414, 736)))

#define APCommonUIIsLowerIphone6 \
    [UIScreen mainScreen].bounds.size.width == 320

//@interface UIColor (APCommonUIExtensions)
//
///**
// * 用一个24位的整数生成UIColor
// * 这个方法实现如下，只会返回不透明的颜色
//   return [UIColor colorWithRed:((rgb & 0xFF0000) >> 16) / 255.0f
//      green:((rgb & 0xFF00) >> 8) / 255.0f
//      blue:((rgb & 0xFF)) / 255.0f
//      alpha:1.0f];
// * @param rgb 形如0xRRGGBB
// */
//+ (UIColor *)colorWithRGB:(int)rgb;
//
//// 这个方法可以指定透明度，alpha取值是[0, 1.0]
//+ (UIColor *)colorWithRGB:(int)rgb alpha:(CGFloat)alpha;
//
//@end

/**
 *  获取view距离屏幕上方的距离
 *
 */
__deprecated_msg("该方法已废弃，请直接用AUCommonUIGetContentInsetTop()")
CGFloat APCommonUIGetContentInsetTop();

/**
 *  无论竖屏还是横屏，都返回竖屏时屏幕的宽度
 */
__deprecated_msg("该方法已废弃，请直接用AUCommonUIGetScreenWidthForPortrait()")
CGFloat APCommonUIGetScreenWidthForPortrait();

/**
 * 获取屏幕宽度，竖屏时返回竖屏的宽度，横屏时返回横屏的宽度
 */
__deprecated_msg("该方法已废弃，请直接用AUCommonUIGetScreenWidth()")
CGFloat APCommonUIGetScreenWidth();

/**
 * 获取屏幕高度
 */
__deprecated_msg("该方法已废弃，请直接用AUCommonUIGetScreenHeight()")
CGFloat APCommonUIGetScreenHeight();


/**
 *  获取导航栏上icon的间距
 */
__deprecated_msg("该方法已废弃，请直接用AUCommonUIGetMarginBetweenNavigationItemIcon()")
CGFloat APCommonUIGetMarginBetweenNavigationItemIcon();


