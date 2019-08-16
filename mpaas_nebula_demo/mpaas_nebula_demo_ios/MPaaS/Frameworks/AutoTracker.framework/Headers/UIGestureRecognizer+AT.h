//
//  UIGestureRecognizer+Log.h
//  APMonitor
//
//  Created by tashigaofei on 14-8-28.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIGestureRecognizer (AT)

/**
 业务指定的UIGestureRecognizer对应的Action的名称
 落入自动化埋点模型中字段33,业务未赋值时会使用 \c senderAction替代。
 */
@property (nonatomic, strong) NSString *actionName;

#pragma mark - Private
/**
 SDK内部维护的UIGestureRecognizer对应的Action的方法名
 */
@property (nonatomic, strong) NSString *senderAction;

@end

@interface UIGestureRecognizer (Deprecated)

@property (nonatomic, strong) NSString *logEntityId __deprecated_msg("已废弃,仅为兼容保留");
@property (nonatomic, strong) NSString *logSpmId __deprecated_msg("已废弃,仅为兼容保留");;

@end
