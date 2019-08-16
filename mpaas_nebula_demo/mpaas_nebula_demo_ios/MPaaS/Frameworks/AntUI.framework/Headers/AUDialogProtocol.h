#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_alert//程序自动生成
//
//  AUDialogProtocol.h
//  AntUI
//
//  Created by QiXin on 2016/9/27.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@class AUDialogBaseView;
@protocol AUDialogDelegate <UIAlertViewDelegate>

@optional
/**
 将要展示回调
 
 @param dialogView 将要展示的 dialog 视图
 */
- (void)willPresentDialogView:(AUDialogBaseView *)dialogView;

/**
 是否可以隐藏 dialog 视图

 @param dialogView 指定的 dialog 视图
 @return 是否可以隐藏,如果返回 YES 则走隐藏流程。不实现则默认返回 YES。
 */
- (BOOL)shouldDismissDialogView:(AUDialogBaseView *)dialogView;

/**
 点击按钮回调

 @param dialogView 点击的 dialog 视图
 @param buttonIndex 点击的按钮索引
 */
- (void)dialogView:(AUDialogBaseView *)dialogView clickedButtonAtIndex:(NSInteger)buttonIndex;

/**
 即将消失回调

 @param dialogView dialog 视图
 @param buttonIndex 点击的按钮索引
 */
- (void)dialogView:(AUDialogBaseView *)dialogView willDismissWithButtonIndex:(NSInteger)buttonIndex;

/**
 已经消失回调

 @param dialogView dialog 视图
 @param buttonIndex 点击的按钮索引
 */
- (void)dialogView:(AUDialogBaseView *)dialogView didDismissWithButtonIndex:(NSInteger)buttonIndex;

@end

#endif//程序自动生成
