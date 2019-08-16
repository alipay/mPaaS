//
//  DTAutoTestDelegate.h
//  MobileFramework
//
//  Created by yixuan on 13-7-16.
//  Copyright (c) 2013年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol DTAutoTestDelegate <NSObject>

@required

// 创建自动化测试代理
- (id)initWithAutoTarget:(id)obj;

// 视图加载完成
- (void)viewDidLoad;

// 视图将要出现
- (void)viewWillAppear:(BOOL)animated;

// 视图已经出现
- (void)viewDidAppear:(BOOL)animated;

// 视图将要消失
- (void)viewWillDisappear:(BOOL)animated;

// 视图已经消息
- (void)viewDidDisappear:(BOOL)animated;

// 释放
- (void)dealloc;

@end
