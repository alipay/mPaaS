//
//  UIControl+AddAPMonitor.h
//  APRemoteLogging
//
//  Created by zhiyuan.yzy on 14-2-12.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIControl (AT)

/**
 业务指定的UIControl对应的Action的名称
 落入自动化埋点模型中字段33,业务未赋值时会使用 \c senderAction替代。
 */
@property (nonatomic, strong) NSString *actionName;

#pragma mark - Private
/**
 SDK内部维护的UIControl对应的Action的方法名
 */
@property (nonatomic, strong) NSString *senderAction;

/**
 监控模块(APMonitor)监控点击Laucnher上Tab切换按钮时使用的ID,普通业务方不需要关心.
 */
@property (nonatomic, strong) NSString *tabButtonId;

@end
