#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_IconFont_AUIconView//程序自动生成
//
//  AUIconLabel.h
//  a16
//
//  Created by majie on 14-12-30.
//  Copyright (c) 2014年 majie. All rights reserved.
//

#import <UIKit/UIKit.h>

//支持多个ttf，因为加载一项ttf需要多个操作，所以如果用户使用
//非默认iconfont，都需要自己手动指定iconfont名字

//添加一项新的ttf流程
//1 打开AUCommonUI.bundle/AU_iconfont_name.plist文件
//2 在key键root下添加一项记录，记录键值是加载font的名字，比如默认项key值就是iconfont
//3 在portal项目下，添加字体资源，比如默认项是iconfont.ttf，iconfontconfig.plist文件
//4 配置记录，添加file/config键，分别是上述两项资源在mainBundle路径

//注意，注册fontname时一定要防止重复注册，查看AU_iconfont_name.plist可以看到所有已经使用的fontname（font family name）
//fontname 和 fontname.ttf 一个是加载font的名字，一个是物理加载字体的名字，在使用时两者未必相同
//修改fontname http://www.atatech.org/articles/28526
//工具下载 http://soft.macx.cn/soft2042.htm

@interface AUIconFont : NSObject

//使用默认ttf(配置文件第一项)
+ (UIFont *)iconFont;
+ (UIFont *)iconFontWithSize:(NSInteger)fontSize;

+ (UIFont *)iconFontWithFontName:(NSString *)fontName;
+ (UIFont *)iconFontWithFontName:(NSString *)fontName size:(NSInteger)fontSize;

@end

@interface UIView (AUIconFont)

//使用默认ttf(配置文件第一项)
+ (UIView *)iconFontViewWithPoint:(CGPoint)point name:(NSString *)name;
+ (UIView *)iconFontViewWithPoint:(CGPoint)point name:(NSString *)name color:(UIColor *)color;

+ (UIView *)iconFontViewWithPoint:(CGPoint)point name:(NSString *)name fontName:(NSString *)fontName;
+ (UIView *)iconFontViewWithPoint:(CGPoint)point name:(NSString *)name fontName:(NSString *)fontName color:(UIColor *)color;

- (BOOL)setIconFontColor:(UIColor *)color;
- (BOOL)setIconFontName:(NSString *)name;

@end

#endif//程序自动生成
