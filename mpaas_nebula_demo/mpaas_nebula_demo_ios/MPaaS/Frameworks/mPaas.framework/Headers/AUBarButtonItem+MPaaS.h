//
//  AUBarButtonItem+MPaaS.h
//  APMPaaS
//
//  Created by yangwei on 2017/5/31.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@protocol AUBarButtonItemClass <NSObject>

@property(nonatomic, strong) NSString *backButtonTitle; // 返回按钮title
@property(nonatomic, strong) UIImage *backButtonImage;  // 返回按钮图片
@property(nonatomic, strong) UIColor *titleColor;       // 返回按钮文本颜色
@property(nonatomic, assign) BOOL hideBackButtonImage;    //隐藏返回按钮图片，提供给框架使用

/**
 *  创建默认的返回按钮样式
 *
 *  @param title   显示文本
 *  @param target  点击接受者
 *  @param action  点击处理方法
 *
 *  @return AUBarButtonItem
 */
+ (id<AUBarButtonItemClass>)backBarButtonItemWithTitle:(NSString *)title target:(id)target action:(SEL)action;

@end
