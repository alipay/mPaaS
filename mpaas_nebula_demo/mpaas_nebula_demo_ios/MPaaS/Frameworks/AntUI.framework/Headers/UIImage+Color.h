//
//  UIImage+Color.h
//  MobileFoundation
//
//  Created by shenmo on 11/13/14.
//  Copyright (c) 2014 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface UIImage (Color)

/**
 *  生成1*1像素的纯色图片
 */
+ (UIImage *)imageWithColor1x1_au:(UIColor *)color;
+ (UIImage *)imageWithColor1x1:(UIColor *)color __attribute__((unavailable("使用imageWithColor1x1_au")));

/**
 *  生成指定尺寸的纯色图片
 */
+ (UIImage *)imageWithColor_au:(UIColor *)color size:(CGSize)size;

+ (UIImage *)imageWithColor:(UIColor *)color size:(CGSize)size __attribute__((unavailable("使用imageWithColor_au:size:")));

/**
 *  设置图片透明度
 */
+ (UIImage *)imageByApplyingAlpha_au:(CGFloat)alpha image:(UIImage*)image;

+ (UIImage *)imageByApplyingAlpha:(CGFloat)alpha image:(UIImage*)image __attribute__((unavailable("使用imageByApplyingAlpha_au:image:")));

@end
