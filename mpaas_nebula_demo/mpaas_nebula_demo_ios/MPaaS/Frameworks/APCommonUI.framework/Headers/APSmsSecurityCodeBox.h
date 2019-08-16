//
//  APSmsSecurityCodeBox.h
//  APCommonUI
//
//  Created by liangbao.llb on 4/30/14.
//  Copyright (c) 2014 Alipay. All rights reserved.
//

#import "APSecurityCodeBox.h"

@interface APSmsSecurityCodeBox : APSecurityCodeBox

@property (nonatomic, assign) NSTimeInterval interval; // 发送短信前的等待时间

/**
 *  创建短信验证码输入框
 *  @param frame    在父类的位置和大小
 *  @param interval 发送短信前的等待时间
 *  @return         短信验证码输入框
 */
- (APSmsSecurityCodeBox *)initWithFrame:(CGRect)frame
                               Interval:(NSTimeInterval)interval;

/**
 *  创建短信验证码输入框
 *  @param originY  组件的y坐标
 *  @param interval 发送短信前的等待时间
 *  @return         短信验证码输入框
 */
- (APSmsSecurityCodeBox *)initWithOriginY:(CGFloat)originY
                                 Interval:(NSTimeInterval)interval;

/**
 *  设置倒计时结束时执行的block
 *  @param block  执行的block
 *  @return       无
 */
- (void)setCountdownDidCompleteBlock:(void (^)(void))block;

@end
