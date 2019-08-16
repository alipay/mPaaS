//
//  APDAOProtocol.h
//  MobileFoundation
//
//  Created by shenmo on 9/29/14.
//  Copyright (c) 2014 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <sqlite3.h>
#import "APDataCrypt.h"
#import "APDAOResult.h"
#import "APDAOTransaction.h"

/**
 *  使用下面方法在DAO执行时，插入切面，当获取数据库锁时，执行回调。可以在回调中同步执行 Query 方法。
 *       [[[proxy forTable:@"ATable"] onLockAcquired:^ (sqlite3* sqliteHandle, NSString* tableName, NSDictionary* arguments) {
 *          NSLog(@"on lock");
 *       }] insertModels:models];
 *
 *  只有 forTable 方法返回的对象支持该协议。
 */
typedef void (^APDAOAspectOnLockAcquiredHandler)(id proxy, sqlite3* sqliteHandle, NSString* tableName, NSDictionary* arguments);

@protocol APDAOAspectProtocol <NSObject>

- (id)onLockAcquired:(APDAOAspectOnLockAcquiredHandler)callback;

@end

@protocol APDAOProtocol;

typedef NS_ENUM (NSUInteger, APDAOProxyEventType)
{
    APDAOProxyEventShouldUpgrade = 0,   // 即将升级
    APDAOProxyEventUpgradeFailed,       // 表升级失败
    APDAOProxyEventTableCreated,        // 表被创建
    APDAOProxyEventTableDeleted,        // 表被删除
};

typedef void (^APDAOProxyEventHandler)(id<APDAOProtocol> proxy, APDAOProxyEventType eventType, NSDictionary* arguments);

typedef NSDictionary* (^APDAOProxyInsertionCallbackForSearchFields)(NSDictionary* arguments);

/**
 *  这个Protocol定义的方法每个DAO代理对象都支持，使用时使用id<APDAOProtocol>对DAO对象进行转换。
 */
@protocol APDAOProtocol <NSObject>

/**
 *  配置文件里module可以设置表名，如果想实现配置文件作为一个模板，操作不同的表，可以生成DAO对象后修改tableName。
 *  但需要注意多线程并发情况下，设置表名，再进行数据库操作的同步问题。防止出现窜表的情况。
 *  当要操作多个表时，推荐使用下面的“forTable:”方法。
 */
@property (atomic, strong) NSString* tableName;

/**
 *  返回这个proxy操作的表所在数据库文件的路径
 */
@property (atomic, strong, readonly) NSString* databasePath;

/**
 *  获取这个proxy操作的数据库文件的句柄
 */
@property (atomic, assign, readonly) sqlite3* sqliteHandle;

/**
 *  这个proxy的事件回调，业务自行设置。回调线程不确定。
    注意循环引用的问题，业务对象持有proxy，这个handler方法里不要访问业务对象或proxy，proxy可以在回调的第一个参数里拿到。
 */
@property (atomic, copy) APDAOProxyEventHandler proxyEventHandler;

/**
 *  设置加密器，用于加密表里标记为需要加密的列的数据。向表里写数据时，碰到这个列，会调用进行加密。
 *
 *  @param crypt 加密结构体，会被拷贝一份。如果传入的crypt是外部创建的，需要外部进行free。如果是APDefaultEncrypt()，不需要进行释放。
 */
@property (atomic, assign) APDataCrypt* encryptMethod;

/**
 *  设置解密器，用于解密表里标记为需要加密的列的数据。从表里读数据时，碰到这个列，会调用进行解密。
 *
 *  @param crypt 解密结构体，会被拷贝一份。如果传入的crypt是外部创建的，需要外部进行free。如果是APDefaultDecrypt()，不需要进行释放。
 */
@property (atomic, assign) APDataCrypt* decryptMethod;

/**
 *  ORM 生成对象时，是否直接使用ivar操作来生成，速度最快。但是如果自定义了属性的setter方法，并不会调用。
 *  该选项默认为 YES。如果关闭或设置为 NO，会调用相应属性的setter方法赋值。
 */
@property (atomic, assign) BOOL iVarDirectAccess;

/**
 *  这个方法获取一个对象，这个对象可以调用proxy的所有方法，同时指定操作某个表
 *  使用这种方式可以解决切表频繁时的同步问题，无须整体加锁。
 *  比如：
 *      @synchronized(self)
 *      {
 *          [proxy setTableName:@"ATable"];
 *          [proxy insertModels:models];
 *      }
 *  等价于：
 *      [[proxy forTable:@"ATable"] insertModels:models];
 *
 *  @param tableName 表名
 *
 *  @return 对特定表生效的代理对象
 */
- (id)forTable:(NSString*)tableName;

/**
 *  直接执行SQL，支持绑定参数
 *
 *  @param sql       sql
 *  @param arguments 参数数组
 *
 *  @return 是否成功
 */
- (APDAOResult*)executeUpdateWithSQL:(NSString*)sql arguments:(NSArray*)arguments;

/**
 *  直接执行SQL，支持绑定参数。
 *
 *  @param sql       sql
 *  @param arguments 参数数组
 *
 *  @return 列字典组成的数组
 */
- (NSArray*)executeQueryWithSQL:(NSString*)sql arguments:(NSArray*)arguments;

/**
 *  返回sqlite的最后一条rowId
 *
 *  @return sqlite3_last_insert_rowid()
 */
- (sqlite_int64)lastInsertRowId;

/**
 *  返回上一次update、delete、insert操作影响的行数
 *
 *  @return sqlite3_changes()
 */
- (int)lastChangedRowCount;

/**
 *  获取配置文件定义的所有方法列表
 */
- (NSArray*)allMethodsList;

/**
 *  判断某个表是否存在，也可以判断getSchemaOfTable方法是否返回nil。
 */
- (BOOL)tableExistsForName:(NSString*)tableName;

/**
 *  获取当前proxy的tableName表的建表语句。
 */
- (NSString*)getSchema;

/**
 *  与getSchema方法相同，但是可以指定表名。
 */
- (NSString*)getSchemaOfTable:(NSString*)tableName;

/**
 *  删除配置文件里定义的表，可以用于特殊情况下的数据还原。删除表后，DAO对象仍可以正常使用，再次调用其它方法，会重新创建表。
 *  默认删除这个proxy的tableName指定的表。
 */
- (APDAOResult*)deleteTable;

/**
 *  与deleteTable方法相同，但是可以指定表名。
 */
- (APDAOResult*)deleteTableWithName:(NSString*)tableName;

/**
 *  删除符合某个正则规则的所有表，请确保只删除本Proxy操作的表，否则可能发生异常
 *  这个方法等价于 [self deleteTablesWithPredicate:[NSPredicate predicateWithFormat:@"SELF MATCHES %@", pattern] autovacuum:autovacuum progress:progress callback:callback];
 *
 *  @param pattern    正则表达式
 *  @param autovacuum 删除完成是否自动调用vacuum清理数据库空间
 *  @param progress   进度回调，可传nil，回调不保证主线程。为百分之后的结果
 *  @param callback   每个要删除的表删除前会调用callback，返回YES会继续删除，返回NO就不删这个表
 *
 *  @return 操作是否成功
 */
- (APDAOResult*)deleteTablesWithRegex:(NSString*)pattern autovacuum:(BOOL)autovacuum progress:(void (^)(float progress))progress callback:(BOOL (^)(NSString* tableName))callback;

/**
 *  删除符合某个谓词规则的所有表，请确保只删除本Proxy操作的表，否则可能发生异常
 *
 *  @param predicate  谓词规则
 *  @param autovacuum 删除完成是否自动调用vacuum清理数据库空间
 *  @param progress   进度回调，可传nil，回调不保证主线程。为百分之后的结果
 *  @param callback   每个要删除的表删除前会调用callback，返回YES会继续删除，返回NO就不删这个表
 *
 *  @return 操作是否成功
 */
- (APDAOResult*)deleteTablesWithPredicate:(NSPredicate*)predicate autovacuum:(BOOL)autovacuum progress:(void (^)(float progress))progress callback:(BOOL (^)(NSString* tableName))callback;

/**
 *  调用自己的数据库链接执行vacuum操作
 */
- (void)vacuumDatabase;

/**
 *  删除数据库文件，谨慎调用
 */
- (void)removeDatabaseFile;

/**
 *  DAO对象可以自己把操作放在事务里提升速度，实际调用的是该DAO对象操作的数据库文件APSharedPreferences的daoTransaction方法。
 */
- (APDAOResult*)daoTransaction:(APDAOTransaction)transaction;

/**
 *  创建一个数据库副连接，为接下来可能发生的并发select操作加速使用。可以调用多次，创建多个数据库连接待用。
 *  这些创建的链接会自动关闭，业务层无须处理。
 
 *  @param autoclose 在空闲状态多少秒后自动关闭，0表示使用系统值
 */
- (void)prepareParallelConnection:(NSTimeInterval)autoclose;

/**
 *  全局搜索对于插入操作，是采用数据库钩子。插入操作完成后钩子方法将变化的rowid给全局搜索，然后select出来相应的数据。
 *  这种方式比较低效，所以业务方可以让自己的proxy通过这个方法注册回调方法。执行DAO操作时，会把model返回给业务方，由业务方决定哪些字段用来建索引。
 *
 *  @param methodSelector 需要关注的插入操作方法selector
 *  @param callback       回调block
 
 *  多个insert方法可以对应同一个回调block，比如proxy的接口有两个insert的DAO方法：
 *
 *  @protocol APChatMessageProxy <APDAOProtocol>
 *  - (APDAOResult *)insertChatMessage:(APChatMessage *)message;
 *  - (APDAOResult *)insertChatMessages:(NSArray *)messages;
 *  @end
 *
 *  NSArray* (^block)(NSDictionary* arguments) = ^ (NSDictionary* arguments) { return @[];};
 *  [proxy registerSearchFieldsForInsertMethod:@selector(insertChatMessage:) callback:block];
 *  [proxy registerSearchFieldsForInsertMethod:@selector(insertChatMessages:) callback:block];
 */
- (void)registerSearchFieldsForInsertMethod:(SEL)methodSelector callback:(APDAOProxyInsertionCallbackForSearchFields)callback;

@end
