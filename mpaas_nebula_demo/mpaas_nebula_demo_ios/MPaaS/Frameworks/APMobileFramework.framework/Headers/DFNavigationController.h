//
//  DFNavigationController.h
//  MobileRuntime
//
//  Created by WenBi on 13-4-8.
//  Copyright (c) 2013年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface DFNavigationController : DTNavigationController

/**
 *  注意：框架把这个方法重写了，回到当前App的rootViewController，而不是回到首页。
 */
- (NSArray *)popToRootViewControllerAnimated:(BOOL)animated;

@end

