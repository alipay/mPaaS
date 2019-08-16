//
//  APCacheProtocol.h
//  MobileFoundation
//
//  Created by shenmo on 2/5/15.
//  Copyright (c) 2015 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol APCacheProtocol <NSObject>

@required

/**
 *  最多容纳多少条记录
 */
@property (nonatomic, assign, readonly) NSInteger capacity;

/**
 *  将对象存入缓存，如果object为nil，会删除对象。对象默认为永不过期。
 */
- (void)setObject:(id)object forKey:(NSString*)key;

/**
 *  缓存一个对象，并指定过期的时间戳
 *
 *  @param object 对象，如果为nil会删除指定key的对象
 *  @param key    key
 *  @param expire 过期时间戳，指定一个相对于1970的绝对时间戳。可以使用[date timeIntervalSince1970]。
 */
- (void)setObject:(id)object forKey:(NSString*)key expire:(NSTimeInterval)expire;

/**
 *  取对象
 */
- (id)objectForKey:(NSString*)key;

/**
 *  删除对象
 */
- (void)removeObjectForKey:(NSString*)key;

/**
 *  删除所有对象
 */
- (void)removeAllObjects;

@optional

/**
 *  批量添加数据，无法单独设置每个对象的expire时间，默认都是永不过期的对象。
 */
- (void)addObjects:(NSDictionary*)objects;

/**
 *  批量删除数据
 *
 *  @param regex 正则表达式
 */
- (void)removeObjectsWithRegex:(NSString*)regex;

/**
 *  批量删除数据
 *
 *  @param like sql的like语句
 */
- (void)removeObjectsWithSqlLike:(NSString*)like;

/**
 *  批量删除数据
 *
 *  @param prefix key的前缀
 */
- (void)removeObjectsWithPrefix:(NSString*)prefix;

/**
 *  批量删除数据
 *
 *  @param prefix key的后缀
 */
- (void)removeObjectsWithSuffix:(NSString*)suffix;

/**
 *  批量删除数据，删除keys里所有包含的数据
 */
- (void)removeObjectsWithKeys:(NSSet*)keys;

@end
