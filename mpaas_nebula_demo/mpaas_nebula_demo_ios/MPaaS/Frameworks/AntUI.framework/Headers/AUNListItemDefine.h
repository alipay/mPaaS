#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_Tableview//程序自动生成
//
//  AUNListItemDefine.h
//  AntUI
//
//  Created by maizhelun on 2017/3/6.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#ifndef AUNListItemDefine_h
#define AUNListItemDefine_h

#define AUNClass_h(clazz,inheritClazz) \
@interface clazz : inheritClazz \
@end


#define AUNClass_m(clazz) \
@implementation clazz \
- (void)setHidden:(BOOL)hidden \
{ \
[super setHidden:hidden]; \
[self.superview layoutAgain]; \
} \
- (void)setSize:(CGSize)size\
{\
[super setSize:size];\
[self setAU_size:size];\
    [self layoutAgain];\
}\
@end

#define AUNLabel_m(clazz) \
@implementation clazz \
- (void)setHidden:(BOOL)hidden \
{ \
    [super setHidden:hidden]; \
    [self.superview layoutAgain]; \
} \
- (void)setText:(NSString *)text \
{ \
    [super setText:text]; \
    [self.superview layoutAgain]; \
} \
- (void)setSize:(CGSize)size\
{\
[super setSize:size];\
[self setAU_size:size];\
[self layoutAgain];\
}\
@end

#endif /* AUNListItemDefine_h */


// 单行 AUSwitchListItem AUSingleTitleListItem 左图默认 size 以及与title的左间距
#define SINGLE_LEFT_IMAGE_SIZE                              AUI_THEMES_SIZE(@"LIST_SINGLE_LINE_RIGHT_ASSIST_IMAGE_SIZE", @"ICON_SIZE(30, 30)").width //左边图标默认正方形，大小为30
#define SINGLE_LEFT_IMAGE_SPACE                             AUI_THEMES_FLOAT(@"LIST_LEFT_RIGHT_MARGIN", @"NUMBER(16)") //16 //左图-主标题 间距

#endif//程序自动生成
