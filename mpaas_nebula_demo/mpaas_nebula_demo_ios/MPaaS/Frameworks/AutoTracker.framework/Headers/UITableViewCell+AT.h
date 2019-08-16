//
//  UITableViewCell+AddAPMonitor.h
//  APRemoteLogging
//
//  Created by zhiyuan.yzy on 14-2-13.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UITableViewCell (AT)

/**
 业务指定的UITableViewCell选中时对应的Action的名称
 落入自动化埋点模型中字段33,业务未赋值时会使用 \c @"CellAction"替代。
 */
@property (nonatomic, strong) NSString *actionName;

@end
