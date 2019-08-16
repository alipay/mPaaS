//
//  APSharedPreferences.h
//  AliPay
//
//  Created by shenmo on 14-9-19.
//  Copyright (c) 2014年 shenmo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <sqlite3.h>
#import "APDataCrypt.h"
#import "APDAOResult.h"
#import "APDAOTransaction.h"

// 对应基础表的options字段
typedef NS_OPTIONS (unsigned int, APDataOptions)
{
    // 这两个选项不要在接口中使用，是标识数据的加密属性的，请使用extension来传递加密方法
    APDataOptionDefaultEncrypted    = 1 << 0,       // 这个选项不要传，传了也没效果，统一存储会使用接口里的extension来做加密的判断，而不是options
    APDataOptionCustomEncrypted     = 1 << 1,       // 这个选项不要传，传了也没效果，统一存储会使用接口里的extension来做加密的判断，而不是options
    
    // 标识该数据在清理缓存时可被清除，这里用unsinged int强转1，为因为某些编译选项下，右边的1<<31不能按照unsigned int 来计算，导致赋值失败
    APDataOptionPurgeable           = (unsigned int)1 << 31,
};

/**
 *  数据库连接的事件
 */
typedef NS_ENUM(NSUInteger, APSqliteConnectionEvent)
{
    APSqliteConnectionEventOpen = 0,
    APSqliteConnectionEventWillClose,
    APSqliteConnectionEventDidClose,
    APSqliteConnectionEventDidRenew,    // 用户并没有切换，但是因为登出、登入导致数据库连接需要重新通知一下业务方。如果数据库已经关闭，不会发这个事件。
};

@class APSharedPreferences;

/**
 *  数据库连接监听回调的函数指针定义
 *  sqliteHandle，当事件为APSqliteConnectionEventClose时，这个sqliteHandle为已经关闭的连接的指针，！！！已经关闭，切勿使用 ！！！
 *  @return 返回值是这个APSharedPreferences是否要继续汇报自己的事件
 */
typedef BOOL (*APSqliteConnectionEventListener)(APSharedPreferences* databaseOwner, APSqliteConnectionEvent event, NSString* databasePath, sqlite3* sqliteHandle);

/**
 *  数据库数据变化的钩子，用于使用Objective-C对象作为参数调用DAO，修改数据库时。只支持Insert。
 *  fields为NSDictionary，存储原始字符串，无加密。
 */
typedef void (*APSqliteInsertionListener)(NSString* databasePath, NSString* tableName, sqlite_int64 rowId, NSDictionary* fields);

/**
 *  统一存储默认的文件夹名："Preferences"，在Documents目录下
 */
extern NSString* const kAPDataCenterDefaultDirectoryName;

@interface APSharedPreferences : NSObject

/**
 *  数据库文件的路径
 */
@property (atomic, strong, readonly) NSString* path;

/**
 *  sqlite3的句柄
 */
@property (atomic, assign, readonly) sqlite3* sqliteHandle;

/**
 *  设置数据库连接监听回调函数
 */
+ (void)setSqliteConnectionEventListener:(APSqliteConnectionEventListener)listener;

/**
 *  设置监听数据库行变更的钩子方法
 */
+ (void)setSqliteInsertionListener:(APSqliteInsertionListener)listener;

/**
 *  从一个路径创建，如果文件不存在，会在此路径自动生成数据库文件，并建表存储key-value数据。
 */
- (id)initWithPath:(NSString*)path;
- (id)initWithPath:(NSString*)path customIdentifier:(NSString*)identifier;

#pragma mark KV Storage

/**
 *  清空所有Key-Value数据
 */
- (void)reset;

/**
 *  删除数据库文件，谨慎调用
 */
- (void)removeDatabaseFile;

/**
 *  移除某个键值对应的数据
 */
- (void)removeItemForKey:(NSString*)key business:(NSString*)business;

/**
 *  删除符合某种模式的键值对应的数据，pattern使用sql的like语句那种形式就行
 *  比如removeItemsLike:@"int_%" business:@"biz"，会删除所有“int_%_biz”这种类型的数据
 *  removeItemsLike:@"%" business:@"biz"会删除所有biz业务的数据
 */
- (void)removeItemsLike:(NSString*)pattern business:(NSString*)business;

/**
 *  某个键值是否存在
 */
- (BOOL)itemExistsForKey:(NSString*)key business:(NSString*)business;

/**
 *  default表里的所有条目的key
 */
- (NSArray*)allKeys;

/**
 *  default表里某个业务的所有key值
 */
- (NSArray*)allKeysOfBusiness:(NSString*)business;

/**
 *  大致计算一个business的所有数据的大小，返回字节数。
 *  避免在主线程调用该方法。
 */
- (unsigned long long)approximateSizeOfBusiness:(NSString*)business;

/**
 *  删除所有可被清空的数据
 */
- (void)removePurgeableItems;

/**
 *  integer、long long、bool、double
 */
- (NSInteger)integerForKey:(NSString*)key business:(NSString*)business;
- (NSInteger)integerForKey:(NSString*)key business:(NSString*)business defaultValue:(NSInteger)defaultValue; // 当数据不存在时默认值
- (BOOL)setInteger:(NSInteger)value forKey:(NSString*)key business:(NSString*)business;

- (long long)longLongForKey:(NSString*)key business:(NSString*)business;
- (long long)longLongForKey:(NSString*)key business:(NSString*)business defaultValue:(long long)defaultValue; // 当数据不存在时默认值
- (BOOL)setLongLong:(long long)value forKey:(NSString*)key business:(NSString*)business;

- (BOOL)boolForKey:(NSString*)key business:(NSString*)business;
- (BOOL)boolForKey:(NSString*)key business:(NSString*)business defaultValue:(BOOL)defaultValue; // 当数据不存在时默认值
- (BOOL)setBool:(BOOL)value forKey:(NSString*)key business:(NSString*)business;

- (double)doubleForKey:(NSString*)key business:(NSString*)business;
- (double)doubleForKey:(NSString*)key business:(NSString*)business defaultValue:(double)defaultValue; // 当数据不存在时默认值
- (BOOL)setDouble:(double)value forKey:(NSString*)key business:(NSString*)business;

/**
 *  存取字符串，支持加密，关于加密参考APDataCrypt.h
 *  如果数据之前是使用默认方法加密的，也就是使用APDefaultEncrypt()加密，那么取数据时不需要传extension了，留NULL即可。
 */
- (NSString*)stringForKey:(NSString*)key business:(NSString*)business;
- (NSString*)stringForKey:(NSString*)key business:(NSString*)business extension:(APDataCrypt*)extension;
- (BOOL)setString:(NSString*)string forKey:(NSString*)key business:(NSString*)business;
- (BOOL)setString:(NSString*)string forKey:(NSString*)key business:(NSString*)business extension:(APDataCrypt*)extension;

/**
 *  取对象，业务层不需要关心归档方式，统一使用该接口取对象。
 *
 *  @return 如果是Property List的归档方式，返回的对象和容器的子对象都是mutable的
 */
- (id)objectForKey:(NSString*)key business:(NSString*)business;
- (id)objectForKey:(NSString*)key business:(NSString*)business extension:(APDataCrypt*)extension;
- (id)objectForKey:(NSString*)key business:(NSString*)business expectedClass:(Class)expectedClass error:(NSError**)error;

/**
 *  以PropertyList归档方式存对象，PList对象定义如下：
 *  NSNumber、NSString、NSData、NSDate、NSArray、NSDictionary，NSArray和NSDictionary里的子对象也只能是Property List对象。Mutable的对象也可以
 */
- (BOOL)setObject:(id)object forKey:(NSString*)key business:(NSString*)business;
- (BOOL)setObject:(id)object forKey:(NSString*)key business:(NSString*)business extension:(APDataCrypt*)extension;
- (BOOL)setObject:(id)object forKey:(NSString*)key business:(NSString*)business extension:(APDataCrypt*)extension options:(APDataOptions)options;

/**
 *  使用Archive的方式存储对象，只要对象支持NSCoding，都可以归档。
 *  Property List对象也可以使用archive方式归档，但速度要慢很多，建议当对象肯定为Property List时，使用setObject方法。
 */
- (BOOL)archiveObject:(id)object forKey:(NSString*)key business:(NSString*)business;
- (BOOL)archiveObject:(id)object forKey:(NSString*)key business:(NSString*)business extension:(APDataCrypt*)extension;
- (BOOL)archiveObject:(id)object forKey:(NSString*)key business:(NSString*)business extension:(APDataCrypt*)extension options:(APDataOptions)options;

/**
 *  使用Json decode/encode来归档对象，这种对象不需要为PList对象，也不需要自己实现NSCoding协议。
 *  取数据仍然使用objectForKey。
 */
- (BOOL)saveJsonObject:(id)object forKey:(NSString*)key business:(NSString*)business;
- (BOOL)saveJsonObject:(id)object forKey:(NSString*)key business:(NSString*)business extension:(APDataCrypt*)extension;
- (BOOL)saveJsonObject:(id)object forKey:(NSString*)key business:(NSString*)business extension:(APDataCrypt*)extension options:(APDataOptions)options;

#pragma mark DAO Access

/**
 *  每个APSharedPreferences对象对应磁盘上的一个数据库文件，它也可能是DAO操作的目的文件（假如有DAO对象指向它）。
 *  如果一系列DAO调用可以优化为同一个事务，那么在操作前调用daoTransaction:APDAOTransactionBegin，结束时使用daoTransaction:APDAOTransactionCommit会大大提升速度。
 *
 *  @param transaction transaction操作类别
 *
 *  @return 操作是否成功
 */
- (APDAOResult*)daoTransaction:(APDAOTransaction)transaction;


#pragma mark - lock

/**
 *  对默认数据库连接加锁
 *  @param tag 加锁的原因
 */
- (void)databaseConnectionLock:(NSString*)tag;

/**
 *  对默认数据库连接解锁
 */
- (void)databaseConnectionUnlock;



@end
