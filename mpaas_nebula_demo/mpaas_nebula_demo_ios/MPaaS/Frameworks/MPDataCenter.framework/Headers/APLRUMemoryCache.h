//
//  APLRUMemoryCache.h
//  MobileFoundation
//
//  Created by shenmo on 2/2/15.
//  Copyright (c) 2015 Alipay. All rights reserved.
//

#import "APCacheProtocol.h"

@interface APLRUMemoryCache : NSObject <APCacheProtocol>

/**
 *  是否自动处理系统内存警告，如果为 YES，会在收到警告后将缓存清空
 */
@property (nonatomic, assign) BOOL handleMemoryWarning; // default NO

/**
 *  初始化并设置容量
 */
- (id)initWithCapacity:(NSInteger)capacity;

/**
 *  保存对象
 */
- (void)setObject:(id)object forKey:(NSString*)key;

/**
 *  保存对象并设置多少秒后过期
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
 *  删除所有key满足regex正则表达式的对象
 */
- (void)removeObjectsWithRegex:(NSString*)regex;

/**
 *  删除所有key带prefix前缀的对象
 */
- (void)removeObjectsWithPrefix:(NSString*)prefix;

/**
 *  删除所有key带suffix后缀的对象
 */
- (void)removeObjectsWithSuffix:(NSString*)suffix;

/**
 *  删除key在keys中的所有对象
 */
- (void)removeObjectsWithKeys:(NSSet*)keys;

/**
 *  将缓存对象读取到一个数组里，但不做LRU缓存策略处理。fromHead为YES时，从头开始遍历，否则对尾开始遍历。
 */
- (NSArray*)peekObjects:(NSInteger)count fromHead:(BOOL)fromHead;

/**
 *  快速判断某个key的对象是否存在
 */
- (BOOL)objectExistsForKey:(NSString*)key;

/**
 *  更新容量，如果新容量比原先的小，会删除部分缓存
 */
- (void)resetCapacity:(NSInteger)capacity;

/**
 *  判断一个对象是否在缓存的前面（前5位），如果是的话，认为已经位于很靠前的位置。
 */
- (id)findObjectAtTopSequenceForKey:(NSString*)key atTop:(BOOL*)atTop;

@end
