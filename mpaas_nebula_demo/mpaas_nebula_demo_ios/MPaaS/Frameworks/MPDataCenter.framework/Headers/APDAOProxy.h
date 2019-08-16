//
//  APDAOProxy.h
//  MobileFoundation
//
//  Created by shenmo on 14-9-21.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <sqlite3.h>
#import "APDAOVersionManager.h"
#import "APDAOHistoryManager.h"
#import "APDAOTransaction.h"

@class APDAOConfig;
@class APDatabaseConnection;

@protocol APDAOProxyDelegate <NSObject>

/**
 *  连接是否良好
 */
- (BOOL)goodConnection;

/**
 *  锁主连接
 */
- (void)databaseConnectionLock:(NSString*)tag;

/**
 *  解锁主连接
 */
- (void)databaseConnectionUnlock;

/**
 *  主连接是否锁定
 */
- (BOOL)databaseLocked;

/**
 *  删除数据库文件
 */
- (void)removeDatabaseFile;

/**
 *  执行vacuum
 */
- (void)vacuumDatabase;

/**
 *  当出现SQLITE_FULL错误时，是否重试
 */
- (BOOL)shouldRetryOnSQLiteFull;

/**
 *  将temp_store改成1
 */
- (void)setTempStoreToFile;

/**
 *  取主连接
 */
- (APDatabaseConnection*)databaseConnection;

/**
 *  取一个并发连接
 */
- (APDatabaseConnection*)parallelDatabaseConnection;

/**
 *  释放并发连接
 */
- (void)releaseParallelDatabaseConnection:(APDatabaseConnection*)connection;

/**
 *  预先创建一个并发连接
 *
 *  @param autoclose 多少秒不用自动关闭
 */
- (void)prepareParallelConnection:(NSTimeInterval)autoclose;

/**
 *  取这个Proxy使用的版本管理器对象
 */
- (id<APDAOVersionManager>)versionManager;

/**
 *  取这个Proxy使用的历史管理器对象
 */
- (id<APDAOHistoryManager>)historyManager;

/**
 *  进行事务
 */
- (APDAOResult*)daoTransaction:(APDAOTransaction)transaction;

/**
 *  报告一个插入操作
 *
 *  @param fields    列信息
 *  @param rowId     插入完成后位于数据库的rowId
 *  @param tableName 操作的表
 */
- (void)reportInsertion:(NSDictionary*)fields rowId:(sqlite_int64)rowId tableName:(NSString*)tableName;

/**
 *  处理严重的SQLite错误，包括修复数据库，重置数据库
 *
 *  @param errorCode    错误码
 *  @param errorString  错误信息
 */
- (void)handleFatalError:(int)errorCode errorString:(NSString*)errorString;

/**
 *  在APSharedPreferences打开数据库时，会回调业务钩子。写操作需要在钩子完全完成时再继续操作。
 */
- (void)waitUntilDatabaseOpenEventDone;

@optional

/**
 *  注册自己
 */
- (void)registerProxy;

/**
 *  反注册自己
 */
- (void)unregisterProxy;

@end

@interface APDAOProxy : NSObject

@property (nonatomic, strong, readonly) APDAOConfig* config;
@property (nonatomic, weak) id<APDAOProxyDelegate> delegate;
@property (nonatomic, assign) BOOL isVersionManager;
@property (nonatomic, assign) BOOL isHistoryManager;

/**
 *  为protocol生成APDAOProxy的子类
 */
+ (Class)proxyClassForProtocol:(Protocol*)protocol;

/**
 *  快速从Config和protocol生成APDAOProxy的子类实例。
 */
+ (APDAOProxy*)proxyWithConfig:(APDAOConfig*)config protocol:(Protocol*)protocol;

/**
 *  快速从配置文件内容创建APDAOProxy的子类实例
 */
+ (APDAOProxy*)proxyWithXMLContent:(NSString*)content protocol:(Protocol*)protocol;

/**
 *  默认且唯一的初始化方法
 */
- (id)initWithConfig:(APDAOConfig*)config;

@end
