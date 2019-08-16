#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_NetError_AUEmptyPageLoadingView//程序自动生成
//
//  UIViewController+AUFullScreenLoading.h
//  AntUI
//
//  Created by 沫竹 on 2017/11/30.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface AUEmptyPageLoadingView : UIView


/**
 显示全屏加载视图

 @param view 视图
 @param animated 动画
 */
+ (void)showInView:(UIView *)view animated:(BOOL)animated;


/**
 隐藏全屏加载视图

 @param view 视图
 @param animated 动画
 */
+ (void)hideInView:(UIView *)view animated:(BOOL)animated;


/**
 设置文案

 @param text 文案
 @param ellipsis 是否带省略号
 */
- (void)setText:(NSString *)text ellipsis:(BOOL)ellipsis;

@end


#endif//程序自动生成
