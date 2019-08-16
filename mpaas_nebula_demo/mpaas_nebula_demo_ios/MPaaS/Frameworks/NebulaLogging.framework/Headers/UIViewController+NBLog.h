//
//  UIViewController+NBLog.h
//  NebulaLogging
//
//  Created by Glance on 2017/8/5.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>
@class NBLogPagePerformance;
@interface UIViewController (NBLog)

- (NBLogPagePerformance *)currentPagePerformance;

- (void)enhanceRpcSpm:(NSString *)spmId;


@end
