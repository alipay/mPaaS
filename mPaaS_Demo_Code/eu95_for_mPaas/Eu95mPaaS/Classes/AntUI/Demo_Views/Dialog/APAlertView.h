//
//  ALPAlertView.h
//  CommonUI
//
//  Created by tgf on 13-4-23.
//  Copyright (c) 2013年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "APAlertViewBase.h"

#import <AntUI/AUNoticeDialog.h>

#pragma mark -
// TODO: Do not subclass UIAlertView
#pragma mark -

/**
 * 定制的alert view
 */
@interface APAlertView : APAlertViewBase

/**
 *  显示alert窗口
 *
 *  @return 点击的button下标
 */
- (NSInteger)showModel;

@end


@interface AUAlertViewAdapter : AUNoticeDialog

- (NSInteger)showModel;

/**
 *@brief 初始化方法
 */
- (id)initWithTitle:(NSString *)title message:(NSString *)message;

/**
 @brief 添加Button 和回调
 @param title: 按钮title
 @param callback: 回调的callback
 */
- (NSInteger)addButtonWithTitle:(NSString *)title callback:(void (^)(int index, NSString *title))callback;

/**
 @brief 添加取消Button和回调
 @param title: 按钮title
 @param callback: 回调的callback
 */
- (NSInteger)addCancelButtonWithTitle:(NSString *)title callback:(void (^)(int index, NSString *title))callback;

/**
 @brief 添加Button
 @param title: 按钮title
 */
- (NSInteger)addButtonWithTitle:(NSString *)title;

/**
 @brief 添加取消button
 @param title: 按钮title
 */
- (NSInteger)addCancelButtonWithTitle:(NSString *)title;

@end
