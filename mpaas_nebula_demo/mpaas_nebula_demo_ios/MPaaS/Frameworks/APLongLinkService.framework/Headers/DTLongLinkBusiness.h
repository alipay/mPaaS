//
//  DTLongLinkBusiness.h
//  APLongLinkService
//
//  Created by alipay\kuohai on 14-9-8.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>


typedef NS_ENUM(NSInteger,NetConnectType)
{
    NetConnectTypeNotAvailable = 0, //当前网络不可用
    NetConnectTypeConnecting,       //连接中
    NetConnectTypeConnected,        //连接上
    NetConnectTypeConnectFailed     //连接失败
};

//监听通知
extern NSString * const APConnectionStatusNotification;
//Notification status info key
extern NSString * const APConnectionStatusKey;

@interface DTLongLinkBusiness : NSObject
/**
 *	@brief	app启动时候初始化同步服务
 *	@return void
 */
+(void)syncInit;
/**
 *	网络连接状态
 */
+(NetConnectType)connectStatus;
/**
 *  通知SyncSDK已经注册通知监听,可以接收Sync消息
 *  如果不调用该接口则不分发Sync消息,消息会积压在SyncSDK的数据库
 *  @param 	biz 	业务名称
 *  @return 调用成功或者失败YES/NO
 */
+(BOOL)hasRegisterNotificationWithBiz:(NSString*)biz;
/**
 *  通知SyncSDK已经取消通知监听,不再接收Sync消息
 *  调用该接口后不会再分发Sync消息,消息会积压在SyncSDK的数据库
 *  @param 	biz 	业务名称
 *  @return 调用成功或者失败YES/NO
 */
+(BOOL)unRegisterNotificationWithBiz:(NSString*)biz;
/**
 *	@brief	消息处理完成通知回调
 *
 *	@param 	dic 返回处理消息信息(notify.userInfo)
 *
 *	@return
 */
+ (void)responseMessageNotify:(NSDictionary *)userInfo;

/**
 *	@brief	用户登录初始化业长连接数据，两个参数都不为空才生效；
 *  如果 session 过期，或者是客户端在用户登录过一次之后具备了自
 *  动免登的功能，那么每次免登成功时也必须要调用本方法
 *
 *	@param 	userId 	    用户id
 *	@param 	sessionId   用于校验session合法性
 *
 *	@return
 */
+ (void)sendBindUser:(NSString *)userId sessionId:(NSString *)sessionId;

/**
 *	@brief	解绑当前连接用户
 *
 *	@return
 */
+ (void)sendUnBindUser;
@end
