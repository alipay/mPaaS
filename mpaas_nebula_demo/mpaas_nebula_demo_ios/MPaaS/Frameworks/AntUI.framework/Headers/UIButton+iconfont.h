#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_IconFont_AUIconView//程序自动生成
//
//  UIButton+iconfont.h
//  AntUI
//
//  Created by 沫竹 on 2017/11/29.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIButton (iconfont)


/**
 button设置iconfont
 注意：setIconfont和setTitle、setImage互斥

 @param name iconfont名字
 @param color iconfont颜色
 @param width iconfont大小
 @param state button状态
 */
- (void)setIconfont:(nullable NSString *)name
              color:(UIColor *)color
              width:(CGFloat)width
           forState:(UIControlState)state;

@end

#endif//程序自动生成
