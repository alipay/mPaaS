//
//  APBusinessPreferences.h
//  MobileFoundation
//
//  Created by shenmo on 14-9-23.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <sqlite3.h>
#import "APDataCrypt.h"
#import "APDAOResult.h"
#import "APDAOTransaction.h"
#import "APSharedPreferences.h"

@class APSharedPreferences;

@interface APBusinessPreferences : NSObject

@property (nonatomic, strong, readonly) NSString* business;
@property (nonatomic, strong, readonly) APSharedPreferences* targetPreferences;
@property (nonatomic, assign, readonly) sqlite3* sqliteHandle;

/**
 *  外部不要调用，不要主动创建APBusinessPreferences对象
 */
- (id)initWithBusiness:(NSString*)business userDependent:(BOOL)userDependent;

/**
 *  外部不要调用，不要主动创建APBusinessPreferences对象
 */
- (id)initWithCustomPath:(NSString*)path identifier:(NSString*)identifier;

#pragma mark KV Storage

/**
 *  删除存储项
 */
- (void)removeItemForKey:(NSString*)key;

/**
 *  按SQLite的like规则删除存储项
 */
- (void)removeItemsLike:(NSString*)pattern;

/**
 *  判断某个key是否存在
 */
- (BOOL)itemExistsForKey:(NSString*)key;

/**
 *  所有keys
 */
- (NSArray*)allKeys;

/**
 *  整数
 */
- (NSInteger)integerForKey:(NSString*)key;
- (NSInteger)integerForKey:(NSString*)key defaultValue:(NSInteger)defaultValue; // 当数据不存在时默认值
- (BOOL)setInteger:(NSInteger)value forKey:(NSString*)key;

/**
 *  long long
 */
- (long long)longLongForKey:(NSString*)key;
- (long long)longLongForKey:(NSString*)key defaultValue:(long long)defaultValue; // 当数据不存在时默认值
- (BOOL)setLongLong:(long long)value forKey:(NSString*)key;

/**
 *  BOOL
 */
- (BOOL)boolForKey:(NSString*)key;
- (BOOL)boolForKey:(NSString*)key defaultValue:(BOOL)defaultValue; // 当数据不存在时默认值
- (BOOL)setBool:(BOOL)value forKey:(NSString*)key;

/**
 *  double
 */
- (double)doubleForKey:(NSString*)key;
- (double)doubleForKey:(NSString*)key defaultValue:(double)defaultValue; // 当数据不存在时默认值
- (BOOL)setDouble:(double)value forKey:(NSString*)key;

/**
 *  NSString*，也可使用下面的setObject方法保存，推荐使用string方法
 */
- (NSString*)stringForKey:(NSString*)key;
- (NSString*)stringForKey:(NSString*)key extension:(APDataCrypt*)extension;
- (BOOL)setString:(NSString*)string forKey:(NSString*)key;
- (BOOL)setString:(NSString*)string forKey:(NSString*)key extension:(APDataCrypt*)extension;

/**
 *  setObject是对PList对象，archiveObject是对支持NSCoding的对象，saveJsonObject对任意对象。
 *  取对象的方法都是objectForKey:
 */
- (id)objectForKey:(NSString*)key;
- (id)objectForKey:(NSString*)key extension:(APDataCrypt*)extension;
- (BOOL)setObject:(id)object forKey:(NSString*)key;
- (BOOL)setObject:(id)object forKey:(NSString*)key extension:(APDataCrypt*)extension;
- (BOOL)setObject:(id)object forKey:(NSString*)key extension:(APDataCrypt*)extension options:(APDataOptions)options;
- (BOOL)archiveObject:(id)object forKey:(NSString*)key;
- (BOOL)archiveObject:(id)object forKey:(NSString*)key extension:(APDataCrypt*)extension;
- (BOOL)archiveObject:(id)object forKey:(NSString*)key extension:(APDataCrypt*)extension options:(APDataOptions)options;
- (BOOL)saveJsonObject:(id)object forKey:(NSString*)key;
- (BOOL)saveJsonObject:(id)object forKey:(NSString*)key extension:(APDataCrypt*)extension;
- (BOOL)saveJsonObject:(id)object forKey:(NSString*)key extension:(APDataCrypt*)extension options:(APDataOptions)options;

#pragma mark DAO Access

/**
 *  DAO事务操作
 */
- (APDAOResult*)daoTransaction:(APDAOTransaction)transaction;

@end
