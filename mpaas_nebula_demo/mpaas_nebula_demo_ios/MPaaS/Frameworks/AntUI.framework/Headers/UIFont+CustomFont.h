//
//  UIFont+CustomFont.h
//  AntUI
//
//  Created by zhaolei on 2017/7/7.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>


//获得数字字体名字
NSString * AUNumberFontName();

//获得数字字体路径
NSString * AUNumberFontPath();

@interface UIFont(CustomFont)

+ (void)au_loadFontWithResource:(NSString *) resource;

//only for 鸟巢
+ (UIFont *) fontWithCustomName:(NSString *)customName size:(CGFloat) size;

//业务请调用这个
+ (UIFont *) au_fontWithCustomName:(NSString *) customName
                          size:(CGFloat) size;

@end


@interface UIFont(AntUI)


/**
 获取HelveticaNeue字体

 @param fontSize 字体大小
 @return HelveticaNeue字体
 */
+ (UIFont *)au_getHelveticaNeueFont:(float)fontSize;


/**
 获取STHeitiSC-Light字体

 @param fontSize 字体大小
 @return STHeitiSC-Light字体
 */
+ (UIFont *)au_getHeitiSCFont:(float)fontSize;

@end
