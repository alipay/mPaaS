//
//  ALPAlertView.h
//  CommonUI
//
//  Created by tgf on 13-4-23.
//  Copyright (c) 2013年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "APAlertViewBase.h"

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
