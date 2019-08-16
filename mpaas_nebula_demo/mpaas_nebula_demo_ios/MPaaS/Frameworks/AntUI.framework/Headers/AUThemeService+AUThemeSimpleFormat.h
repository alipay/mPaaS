//
//  AUThemeService+AUThemeSimpleFormat.h
//  AntUI
//
//  Created by 莜阳 on 2017/11/27.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "AUThemeService.h"

// 更简洁的数据格式

@interface AUThemeService (AUThemeSimpleFormat)
// 获取色值
+ (UIColor *)AUColorForKey:(NSString *)key inBundle:(NSString *)bundle defaultValue:(UIColor *)defaultValue;

// 获取字体
+ (UIFont *)AUFontForKey:(NSString *)key inBundle:(NSString *)bundle defaultValue:(UIFont *)defaultValue;

// 获取数值
+ (CGFloat)AUFloatForKey:(NSString *)key inBundle:(NSString *)bundle defaultValue:(CGFloat)defaultValue;

// 获取Size
+ (CGSize)AUSizeForKey:(NSString *)key inBundle:(NSString *)bundle defaultValue:(CGSize)defaultValue;

// 获取image对象
+ (NSString *)AUImagePathForKey:(NSString *)key inBundle:(NSString *)bundle defaultValue:(NSString *)defaultValue;

//
+ (UIColor *)AUColorWithStringValue:(NSString *)value;

//
+ (UIFont *)AUFontWithStringValue:(NSString *)value;

//
+ (CGFloat)AUFloatWithStringValue:(NSString *)value;

//
+ (CGSize)AUSizeWithStringValue:(NSString *)value;

//
+ (NSString *)AUImagePathWithStringValue:(NSString *)value;

@end

