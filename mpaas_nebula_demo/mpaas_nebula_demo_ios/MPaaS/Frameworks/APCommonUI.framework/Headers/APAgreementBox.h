//
//  APAgreementBox.h
//  CommonUI
//
//  Created by tgf on 2013-04.
//  Copyright (c) 2013年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

@class APCheckBox;
@class APLinkButton;

/**
 * 用于显示用户注册协议的组件
 */
@interface APAgreementBox : UIControl

@property(nonatomic, readonly) APCheckBox *checkBox;  //单选框
@property(nonatomic, readonly) APLinkButton *linkButton; //注册信息链接button
@property(nonatomic, assign) BOOL disabled; // 设置APCheckBox是选中不可取消状态，默认是NO

/**
 *  创建注册协议组件
 *
 *  @param frame     组件frame
 *  @param labelText 单选框显示文本
 *  @param linkText  注册信息链接文本
 *
 *  @return 新建并初始化的注册协议组件
 */
- (id)initWithFrame:(CGRect)frame labelText:(NSString *)labelText linkText:(NSString *)linkText;

/**
 *  设置单选框是否隐藏
 *
 *  @param hidden 是否隐藏
 */
- (void)setCheckBoxHidden:(BOOL)hidden;

@end
