//
//  MPSyncInterface.h
//  MPMssAdapter
//
//  Created by yemingyu on 2019/2/15.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, MPSyncNetConnectType)
{
    MPSyncNetConnectTypeNotAvailable = 0, //当前网络不可用
    MPSyncNetConnectTypeConnecting,       //连接中
    MPSyncNetConnectTypeConnected,        //连接上
    MPSyncNetConnectTypeConnectFailed     //连接失败
};

NS_ASSUME_NONNULL_BEGIN

@interface MPSyncInterface : NSObject

/**
 初始化 Sync 服务，使用 Sync 服务前必须调用
 */
+ (void)initSync;

/**
 获取 Sync 网络连接状态

 @return MPSyncNetConnectType
 */
+ (MPSyncNetConnectType)connectStatus;

/**
 注册对业务名称为 bizName 的通知监听，内部调用了
[[NSNotificationCenter defaultCenter] addObserver:observer selector:selector name:bizName object:nil]; 进行通知监听
 
 @param bizName 业务名称
 @param observer 通知的监听者，通常为调用类中的 self
 @param selector 监听者类中的处理函数
 @return 调用成功或者失败YES/NO
 */
+ (BOOL)registerSyncBizWithName:(NSString *)bizName syncObserver:(id)observer selector:(SEL)selector;

/**
 取消对业务名称为 bizName 的通知监听，内部调用了
 [[NSNotificationCenter defaultCenter] removeObserver:observer name:bizName object:nil]; 进行通知监听解除
 调用该接口后不会再分发 Sync 消息，消息会积压在 SyncSDK 的数据库
 
 @param bizName 业务名称
 @param observer 已注册的通知的监听者，通常为调用类中的 self
 @return 调用成功或者失败YES/NO
 */
+ (BOOL)unRegisterSyncBizWithName:(NSString *)bizName syncObserver:(id)observer;

/**
 取消 Sync 的通知监听，通常在监听类的 dealloc 函数中调用，内部调用了
 [[NSNotificationCenter defaultCenter] removeObserver:observer]; 进行监听者移除

 @param observer 已注册的通知的监听者，通常为调用类中的 self
 */
+ (void)removeSyncNotificationObserver:(id)observer;

/**
 消息处理完成通知回调
 回调 SyncSDK，表示业务数据已经处理
 在 registerSyncBizWithName 接口注册的通知处理函数中，数据处理完后调用

 @param userInfo 返回处理消息信息(notify.userInfo)
 */
+ (void)responseMessageNotify:(NSDictionary *)userInfo;


/**
 用户登录初始化业长连接数据，两个参数都不为空才生效；
 如果 session 过期，或者是客户端在用户登录过一次之后具备了自
 动免登的功能，那么每次免登成功时也必须要调用本方法

 采用的 userId 为 MPaaSInterface 的 - (NSString*)userId 函数
 
 注意：当 userId 发生变化时，先调用 unBindUser 解绑，然后调用 bindUserWithSessionId: 重新建连
 
 @param sessionId 用于校验 session 合法性，需要服务端配合。如果设为 nil，则默认为 @"SESSION_DEMO"
 */
+ (void)bindUserWithSessionId:(NSString *)sessionId;

/**
 解绑当前连接用户

 */
+ (void)unBindUser;


/**
 获取设备 Id，根据设备维度推 Sync 数据时采用此 Id

 @return 设备 Id
 */
+ (NSString *)getSyncDeviceId;

/**
 获取组件当前环境信息
 
 @return 字典类型，包括组件信息
 */
+ (NSDictionary *)getComponentEnv;

@end

NS_ASSUME_NONNULL_END
