//
//  NBViewControllerLifecycleDispatcher.h
//  NBService
//
//  Created by chenwenhong on 15/8/21.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NBOptions.h"
#import "NBNavigationTitleViewProtocol.h"

@class NBViewControllerStatus;

typedef void(^NBDelayCallback)();


@interface NBViewControllerProxy : NSObject <PSDViewControllerProtocol, PSDExpandoProtocol>

// 通用属性
@property(nonatomic, readonly, strong) id<NBNavigationTitleViewProtocol>  navigationTitleView;
@property(nonatomic, readonly, strong) id<NBOptionsProtocol>              options;
@property(nonatomic, readonly, copy) NSString                             *channelId;
@property(nonatomic, readonly, copy) NSString                             *customUserAgent;
@property(nonatomic, readonly, strong) NBViewControllerStatus             *myFlags;

- (instancetype)initWithTarget:(UIViewController *)target;

- (void)back;

- (void)clearAndBack;

- (void)close;

- (void)popToViewController:(UIViewController *)vc animated:(BOOL)animated;

- (void)popToWindowOfIndex:(NSInteger)indexPopTo;

- (void)popViewControllerAnimated:(BOOL)animated;

- (void)pushViewController:(UIViewController *)viewController animated:(BOOL)animated;

- (void)addDelayCallback:(NBDelayCallback)callback;

- (void)showCloseItemIfNeeded;

- (void)doShowCloseItemIfNeeded:(BOOL)needed;

/**
 *  重新设置整个options,业务谨慎使用
 *
 *  @date 2017-06-07
 *
 */
- (void)resetOptions:(id<NBOptionsProtocol>)options;

/**
 设置MainTitle的事件

 @param mainTitle 
 @param subtitle 
 */
- (void)sendSetMainTitleEvent:(NSString *)mainTitle subtitle:(NSString *)subtitle;

/**
 重置返回状态
 
 */
- (void)resetBackStatus;

@end
