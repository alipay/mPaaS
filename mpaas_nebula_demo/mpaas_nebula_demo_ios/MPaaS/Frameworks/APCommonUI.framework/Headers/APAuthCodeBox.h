//
//  APAuthCodeBox.h
//  APCommonUI
//
//  Created by yang.zy on 14-1-17.
//  Copyright (c) 2014年 WenBi. All rights reserved.
//

#import <UIKit/UIKit.h>
@class APInputBox;
@class APTextField;
@class APButton;
@class APAuthCodeBox;

@protocol AuthCodeDelegate <NSObject>

- (void) onAuthTimerout:(APAuthCodeBox *)authBox;

@end

/**
 *  验证码控件
 */
@interface APAuthCodeBox : UIView


#pragma mark - APAuthCodeBox属性


@property (strong, nonatomic) APInputBox        *inputBox;
@property (strong, nonatomic) UIButton          *button;
@property (assign, nonatomic) BOOL              waiting;
@property(nonatomic, weak)id<AuthCodeDelegate>  delegate;



#pragma mark - APAuthCodeBox实例方法

/**
 *  开始等待
 *  应用场景1：   对于图片验证码，开始转菊花
 *  应用场景2：   对于短信验证码，按钮变为不可用，开始倒计时
 */
- (void)startWaiting;

/**
 *  停止等待
 *  应用场景1：   对于图片验证码，停止转菊花
 *  应用场景2：   对于短信验证码，按钮恢复可用，按钮文字变为”重新发送“；倒计时结束以后stopWaiting后被自动调用
 */
- (void)stopWaiting;



#pragma mark - APAuthCodeBox静态方法

/**
 *  控件高度
 *  @return     返回固定高度：49.0
 */
+ (float)heightOfControl;



@end
