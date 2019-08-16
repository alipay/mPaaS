//
//  APLRUDiskCache.h
//  MobileFoundation
//
//  Created by shenmo on 2/2/15.
//  Copyright (c) 2015 Alipay. All rights reserved.
//

#import "APCacheProtocol.h"

@interface APLRUDiskCache : NSObject <APCacheProtocol>

@property (nonatomic, strong, readonly) NSString* name;
@property (nonatomic, assign, readonly) BOOL crypted;
@property (nonatomic, assign, readonly) BOOL userDependent;

/**
 *  创建一个持久化的LRU缓存，存入的对象需要支持NSCoding协议
 *
 *  @param name                 缓存的名字，用做数据库的表名。如果有前缀"LIB_CACHES."，会放到Library/Cache目录下面，如果"TMP."会放到tmp目录下，否则默认为Documents。
 *  @param capacity             容量，实际容量会比这个大一些，解决缓存满时添加数据的性能问题
 *  @param userDependent        是否与用户相关，如果与用户相关，当APDataCenter.currentUserId为空时缓存无法操作；
        当切换用户后，缓存会自动指向当前用户的表，业务无须关心这个事件。
 *  @param crypted              数据是否加密
 *
 *  @return 缓存实例，业务需要持有
 */
- (id)initWithName:(NSString*)name capacity:(NSInteger)capacity userDependent:(BOOL)userDependent crypted:(BOOL)crypted;

/**
 *  保存对象
 */
- (void)setObject:(id)object forKey:(NSString*)key;

/**
 *  保存对象并设置过期时间
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

/**
 *  批量添加对象
 */
- (void)addObjects:(NSDictionary*)objects;

/**
 *  按SQL的like语句规则删除满足条件的对象
 */
- (void)removeObjectsWithSqlLike:(NSString*)like;

/**
 *  删除key在keys中的所有对象
 */
- (void)removeObjectsWithKeys:(NSSet*)keys;

@end
