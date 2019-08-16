//
//  DTLongLinkControl.h
//  APLongLinkService
//
//  Created by alipay\kuohai on 14-9-14.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

//降级开关
#define AP_LONGLINK_DOWNGRAGE_CONFIG @"AP_LONGLINK_DOWNGRAGE_CONFIG"
extern NSString * const APLongLinkErrorNotification;
extern NSString * const APLongLinkReLoginNotification;
extern NSString * const KSyncIdleNotification;

@interface DTLongLinkControl : NSObject
/*
 * instance
 */
+ (DTLongLinkControl *)sharedInstance;

/**
 *	@brief	用户登陆初始化业务内长连接数据
 *
 *	@param 	userId 	    用户名
  *	@param 	sessionId   用于校验session合法性
 *
 *	@return
 */
- (void)sendBindUser:(NSString *)userId sessionId:(NSString *)sessionId;

/**
 *	@brief	解绑当前连接用户
 *
 *	@return
 */
- (void)sendUnBindUser;
@end
