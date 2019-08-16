//
//  TYWholeFPSMonitor.h
//  TianYan
//
//  Created by yeyu on 16/7/7.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface TYWholeFPSMonitor : NSObject

//  外部传进标志是不是vc正在创建
@property (nonatomic, assign) BOOL isViewControllerCreating;

+ (instancetype)sharedInstance;

//  整体监控接口
- (void)startWholeFpsAndLagMonitor;

//  监控阶段数据(同时只允许存在一个监控)
- (void)startPhaseFpsAndLagMonitor;
- (unsigned int)endPhaseFpsAndLagMontior;

@end



