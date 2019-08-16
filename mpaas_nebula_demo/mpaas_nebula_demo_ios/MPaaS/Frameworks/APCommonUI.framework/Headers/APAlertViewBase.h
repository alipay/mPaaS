//
//  APAlertView.h
//  MobileFoundation
//
//  Created by 朱建 on 13-4-9.
//  Copyright (c) 2013年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>
/*!
 @class         APAlertView
 @abstract      可管理的 UIAlertView 类
 @discussion    使用 UIAlertView 时需要使用该类
 */
@interface APAlertViewBase : UIAlertView

/**
 *以下属性和方法私有,使用者不要调用
 */
@property(nonatomic,weak)id<UIAlertViewDelegate>dtDelegate;
- (void)showAlert;
+(void)setBackgroundMode:(BOOL)isBackMode;
+(void)removeAllAlerviews;

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
