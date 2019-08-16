//
//  UIImage+Color.h
//  MobileFoundation
//
//  Created by shenmo on 11/13/14.
//  Copyright (c) 2014 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface UIImage (Color)

/**
 *  生成1*1像素的纯色图片
 */
+ (UIImage *)imageWithColor1x1:(UIColor *)color;

/**
 *  生成指定尺寸的纯色图片
 */
+ (UIImage *)imageWithColor:(UIColor *)color size:(CGSize)size;

/**
 *  设置图片透明度
 */
+ (UIImage *)imageByApplyingAlpha:(CGFloat)alpha image:(UIImage*)image;

@end
