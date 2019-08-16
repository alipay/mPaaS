//
//  APButton.h
//  APCommonUI
//
//  Created by WenBi on 14-1-14.
//  Copyright (c) 2014年 WenBi. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, APButtonType) {
    APButtonTypeCustom,      //自定义按钮
    APButtonTypeDefault,     //主按钮
    APButtonTypeSecondary,   //次按钮
    APButtonTypeCaution,     //警示按钮
    APButtonTypeAdd,         //信用卡添加按钮
    APButtonTypeSocial,      //社交按钮
    APButtonTypeAssist,      //辅助按钮
};

/**
 *  按钮。
 *  
 *  目前默认实现了以下三种样式的按钮：
 *  
 *      - 主按钮
 *      - 次按钮
 *      - 一种警示按钮，通常按钮背景会显示为较醒目的红色。
 *      - 自定义按钮，不会应用任何样式，也不会初始化frame。
 *
 *  如果使用带frame的init方法初始化按钮，按钮会使用指定的frame，否则会使用默认的frame。
 *
 */
@interface APButton : UIButton

/**
 *  扩展的按钮类型。
 */
@property(nonatomic, assign, readonly) APButtonType extendedButtonType;

/**
 *  一个方法的辅助方法，用于创建并初始化一个按钮的对象。
 *
 *  @param buttonType 按钮类型，必须是定义在<code>APButtonType</code>中的其中一个值。
 *  @param title      铵钮标题
 *  @param target     响应按钮点击事件的对象
 *  @param action     响应按钮点击事件的函数
 *
 *  @return 新创建并经过初始化的按钮对象。
 *  
 *  使用这个方法创建的按钮对象，其默认的frame为<code>CGRectMake(10.0, 0, APCommonUIGetScreenWidth()-20, 42.0)</code>，
 *  对于指定的target和action所对应事件为<code>UIControlEventTouchUpInside</code>。
 */
+ (APButton *)buttonWithType:(APButtonType)buttonType title:(NSString *)title target:(id)target action:(SEL)action;

/**
 *  Initializes and returns the newly created button with specified button type.
 *
 *  @param buttonType The type of the button to be initialized.
 *
 *  @return An initialized button with specified button type.
 */
- (id)initWithButtonType:(APButtonType)buttonType;

#pragma 加载菊花
/**
 *  点击button时，显示加载小菊花
 *  1、APButtonTypeCustom 和 APButtonTypeAdd两种类型不支持添菊花
 *  2、加载过程中，除导航栏可操作外，当前页面不允许其他操作,如有其他操作，请先调用stopLoading停止加载
 *
 *  @param loadingTitle 菊花显示时的文案，若不设置此文案，菊花居中显示
 *  @param currentVC    当前VC
 */
- (void)startLoadingWithTitle:(NSString *)loadingTitle currentViewController:(UIViewController *)currentVC;


/**
 * 停止显示小菊花，恢复button原本文案
 */
- (void)stopLoading;

@end
