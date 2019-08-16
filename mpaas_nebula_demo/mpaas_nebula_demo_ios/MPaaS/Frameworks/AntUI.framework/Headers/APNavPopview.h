#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_FloatMenu_AUFloatMenu//程序自动生成
//
//  APNavPopView.h
//  Launcher
//
//  Created by ronghui.zrh on 15/9/9.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//


#import <UIKit/UIKit.h>
#import "AUFloatMenu.h"

/**popview消失的通知*/
//static NSString * const APExtUIPopViewDissmissedNotification = @"APExtUIPopViewDissmissedNotification";
@class APNavItemView;

__deprecated_msg("APNavPopview 即将废弃，请直接使用 AUFloatMenu")
@interface APNavPopview : AUFloatMenu
/**
 *  创建浮动菜单视图
 *
 *  @param position        浮动菜单在屏幕上展示的位置
 *  @param items           展示的内容数组，一般为APNavItemView对象
 *
 *  @return 浮动菜单视图
 */
+(APNavPopview *)showAtPostion:(CGPoint)position items:(NSArray<APNavItemView *> *)items;

/**
 *  创建浮动菜单视图
 *
 *  @param position        浮动菜单在屏幕上展示的位置
 *  @param orignY          浮动菜单在屏幕上y坐标值
 *  @param items           展示的内容数组，一般为APNavItemView对象
 *
 *  @return 浮动菜单视图
 */
+(APNavPopview *)showAtPostion:(CGPoint)position startOrignY:(CGFloat)orignY items:(NSArray<APNavItemView *> *)items;

@end

#endif//程序自动生成
