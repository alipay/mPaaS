//
//  APMonitorPointMrg.h
//  AlipayPortal
//
//  Created by  tudou on 11-12-19.
//  Copyright (c) 2011年 aliPay. All rights reserved.
//

#import <Foundation/Foundation.h>

//FIXME:埋点的老接口，不要在这个类里面再添加方法
@interface APMonitorPointManager : NSObject

@property (atomic, strong) NSString *userID;
@property (nonatomic, assign) BOOL hasAuthenticated;

+ (APMonitorPointManager*)sharedInstance;

/**
 *   注意：新的打点不要调用此接口，为保持兼容以前的代码保留
 *              8.3之前的老的页面继续使用此接口，8.3新开的页面使用writeLogWithActionId:..这个接口
 *
 *              新的接口文件是APRemoteLogger.h
 *
 *  @param firstLog 字典初始化参数
 **/
-(void)addLogsAndKeys:(NSString *)firstLog, ... /*__deprecated*/;

/**
 * 设置用户的id跟认证信息
 * @param userId,登录用户的用户id
 */
- (void)setUserId:(NSString *)userId;

/**
 * 设置用户的id跟认证信息
 * @@param authenticated,标志用户是否已经认证
 */
- (void)setAuthenticated:(BOOL)authenticated;


@end
