//
//  DFClientDelegate.h
//  Alipay Mobile Runtime Framework
//
//  Created by WenBi on 13-3-30.
//  Copyright (c) 2013年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

@class DFContext;

/**
 * <code>DFClientDelegate</code> 用于处理框架应用程序的生命周期及运行时的处理（如内存警告等）。
 */
@interface DFClientDelegate : UIResponder <UIApplicationDelegate>

/**
 * 获取应用程序对象的唯一的委托对象。
 */
+ (DFClientDelegate *)sharedDelegate;

/**
 * 获取或设置框架上下文对象。
 */
@property(nonatomic, strong) DFContext *context;

/**
 * 应用主窗口
 */
@property(nonatomic, strong) UIWindow *window;

/**
 * 启动钱包
 */
- (BOOL)bootUp;

@end
