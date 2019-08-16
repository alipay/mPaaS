//
//  UIImage+AUIconFont.h
//  AntUI
//
//  Created by niki on 2019/3/11.
//  Copyright © 2019年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIImage (AUIconFont)

/**
 注册iconfont（只需要调用一次）
 
 @param fontName iconfont字体名称
 @param fontPath iconfont路径（支持绝对和相对路径等，如@"APCommonUI.bundle/iconfont/auiconfont"）
 */
+ (void)registerIconFont_au:(NSString *)fontName fontPath:(NSString *)fontPath;


+ (void)registerIconFont:(NSString *)fontName fontPath:(NSString *)fontPath __attribute__((unavailable("使用registerIconFont_au:fontPath:")));;

/**
 获取一个正方形矢量图（长和宽相等）
 
 @param name  名称
 @param width 大小
 @param color 图像颜色，传nil，默认为蚂蚁蓝
 
 @return 正方形矢量图
 */
+ (UIImage *)iconWithName_au:(NSString *)name
                    width:(CGFloat)width
                    color:(UIColor *)color;

+ (UIImage *)iconWithName:(NSString *)name
                    width:(CGFloat)width
                    color:(UIColor *)color __attribute__((unavailable("使用iconWithName_au:width:color:")));


/**
 获取一个正方形矢量图（长和宽相等）
 
 @param name        名称
 @param fontName    矢量字体名称
 @param width       大小
 @param color       图像颜色，传nil，默认为蚂蚁蓝
 
 @return 正方形矢量图
 */
+ (UIImage *)iconWithName_au:(NSString *)name
                 fontName:(NSString *)fontName
                    width:(CGFloat)width
                    color:(UIColor *)color;

+ (UIImage *)iconWithName:(NSString *)name
                 fontName:(NSString *)fontName
                    width:(CGFloat)width
                    color:(UIColor *)color __attribute__((unavailable("使用iconWithName_au:fontName:width:color:")));

/**
 获取一个正方形矢量图（长和宽相等）
 
 @param name        名称
 @param fontName    矢量字体名称
 @param width       大小
 @param color       图像颜色，传nil，默认为蚂蚁蓝
 @param alpha       图像透明度，0 ~ 1
 
 @return 正方形矢量图
 */
+ (UIImage *)iconWithName_au:(NSString *)name
                 fontName:(NSString *)fontName
                    width:(CGFloat)width
                    color:(UIColor *)color
                    alpha:(CGFloat)alpha;

+ (UIImage *)iconWithName:(NSString *)name
                 fontName:(NSString *)fontName
                    width:(CGFloat)width
                    color:(UIColor *)color
                    alpha:(CGFloat)alpha __attribute__((unavailable("使用iconWithName_au:fontName:width:color:alpha:")));


/**
 取消iconfont注册
 如果是已经在info.plist里面配置，则此方法不生效
 
 @param fontName 字体名称
 @param fontPath iconfont路径（支持绝对和相对路径等，如@"APCommonUI.bundle/iconfont/auiconfont"）
 */
+ (void)unregisterIconFont_au:(NSString *)fontName fontPath:(NSString *)fontPath;

+ (void)unregisterIconFont:(NSString *)fontName fontPath:(NSString *)fontPath __attribute__((unavailable("使用unregisterIconFont_au:fontPath:")));


/**
 iconfont是否包含该图标
 
 @param name 图标名称
 @param fontName 字体名称
 @return YES，包含；NO，不包含
 */
+ (BOOL)isIconExists_au:(NSString *)name inFont:(NSString *)fontName;

+ (BOOL)isIconExists:(NSString *)name inFont:(NSString *)fontName __attribute__((unavailable("使用isIconExists_au:inFont:")));


/**
 iconfont://antui?id=iconfont_more_ios&size=20&color=%23ffffffff
 如果不是一个合法的iconfontURL，则返回nil，否则返回UIImage对象
 包含四个参数：font(可省略)、color、id、size
 
 @return iconfont
 */
+ (UIImage *)iconFromURLString_au:(NSString *)urlString;

+ (UIImage *)iconFromURLString:(NSString *)urlString __attribute__((unavailable("使用iconFromURLString_au:")));


@end

NS_ASSUME_NONNULL_END
