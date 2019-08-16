//
//  ALPNumPwdInputView.h
//  CommonUI
//
//  Created by shaobin on 11/6/13.
//  Copyright (c) 2013 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

@class APNumPwdInputView, APTextField;

@protocol APNumPwdInputViewDelegate <NSObject>

- (void)onPasswordDidChange:(APNumPwdInputView*)sender;

@end

/**
 * 6位数字密码输入框控件。
 */
@interface APNumPwdInputView : UIView<UITextFieldDelegate>

/** 用户输入的密码 */
@property (nonatomic, strong, readonly) NSString *password;
@property (nonatomic, readonly) UILabel *titleLabel;    // 密码输入的提示文字
@property (nonatomic, readonly) APTextField *textField;
@property (nonatomic, weak) id<APNumPwdInputViewDelegate> delegate;

/**
 * 是否是6位数字密码控件。如果是NO，则显示为普通的密码输入框。
 */
@property (nonatomic, assign, getter = isNumericPassword) BOOL numericPassword;

/**
 * 初始化6位数字密码
 * 
 * quadWidth:单个方格宽度  
 * quadHeight:单个方格高度
 */
- (id)initWithQuadWidth:(CGFloat)quadWidth quadHeight:(CGFloat)quadHeight;

/**
 * 初始化6位数字密码
 *
 * quadWidth:单个方格宽度
 * quadHeight:单个方格高度
 * password:初始密码
 */
- (id)initWithQuadWidth:(CGFloat)quadWidth quadHeight:(CGFloat)quadHeight password:(NSString*)password;

/**
 * 清空密码框，不会触发delegate回调
 */
- (void)reset;

- (BOOL)showKeyBoard;
- (BOOL)hideKeyBoard;

- (void)setBackgroundImage:(UIImage *)image;

@end

