//
//  ALPNetErrorView.h
//  CommonUI
//
//  Created by zhiyuan.yzy on 13-6-16.
//  Copyright (c) 2013年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface APNetErrorView : UIView

/**
 *  网络异常老控件样式，建议使用新控件 `APExceptionView`
 */
+ (id)showInParentView:(UIView *)parent withTarget:(id)target action:(SEL)action;

/**
 *  隐藏APNetErrorView
 */
- (void)dismiss;

- (void)setTarget:(id)target action:(SEL)action;

@end
