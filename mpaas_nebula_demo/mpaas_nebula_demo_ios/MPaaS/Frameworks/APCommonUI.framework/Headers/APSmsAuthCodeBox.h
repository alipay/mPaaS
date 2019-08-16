//
//  APSmsAuthCodeBox.h
//  APCommonUI
//
//  Created by yang.zy on 14-1-18.
//  Copyright (c) 2014年 WenBi. All rights reserved.
//

#import "APAuthCodeBox.h"

@interface APSmsAuthCodeBox : APAuthCodeBox


@property (assign, nonatomic) NSTimeInterval interval;
@property (assign, nonatomic) NSTimeInterval startTime;

#pragma mark - APSmsAuthCodeBox实例方法

/**
 *  创建短信验证码输入框
 *  @param originY   组件的y坐标
 *  @param interval  发送短信前的等待时间
 *  @return          短信验证码输入框
 */
- (APSmsAuthCodeBox *)initWithOriginY:(CGFloat)originY
                             Interval:(NSTimeInterval)interval;





@end
