//
//  UIViewController+MobileFramework.h
//  APMobileFramework
//
//  Created by tashigaofei on 14-6-30.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "DTMicroApplication.h"

@interface UIViewController (MobileFramework)

// ViewController所属的App。
@property (nonatomic, weak) DTMicroApplication *microApplication;

// 当前ViewController导航栏的底部横线背景色
@property (nonatomic, strong) UIColor *alipayBottomLineColor;

// 当前ViewController导航栏的背景色
@property (nonatomic, strong) UIColor *alipayNavbarColor;

// 当前ViewController导航栏是否隐藏
@property (nonatomic, assign) BOOL isAlipayNavbarHidden;

@property (nonatomic, assign) BOOL isTransitionFinished;

@property (nonatomic, assign) BOOL isAlipayExiting;

@property (nonatomic, assign) CFTimeInterval pushTs;

@property (nonatomic, assign) BOOL isAppFirstVC;

@end
