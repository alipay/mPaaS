//
//  APMDiskCache.h
//  APMultimedia
//
//  Created by Cloud on 16/5/20.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "APMCacheItem.h"

NS_ASSUME_NONNULL_BEGIN

/**
   APMDiskCache is a thread-safe cache that stores key-value pairs backed by SQLite
   and file system (similar to NSURLCache's disk cache).

   APMDiskCache has these features:

 * It use LRU (least-recently-used) to remove objects.
 * It can be controlled by cost, count, and age.
 * It can be configured to automatically evict objects when there's no free disk space.
 * It can automatically decide the storage type (sqlite/file) for each object to get
   better performance.

   You may compile the latest version of sqlite and ignore the libsqlite3.dylib in
   iOS system to get 2x~4x speed up.
 */
@interface APMDiskCache : NSObject

#pragma mark - Attribute
///=============================================================================
/// @name Attribute
///=============================================================================

/** The name of the cache. Default is nil. */
@property (nonatomic, nullable, copy) NSString *name;

/** The path of the cache (read-only). */
@property (nonatomic, readonly) NSString *path;

/**
   If the object's data size (in bytes) is larger than this value, then object will
   be stored as a file, otherwise the object will be stored in sqlite.

   0 means all objects will be stored as separated files, NSUIntegerMax means all
   objects will be stored in sqlite.

   The default value is 20480 (20KB).
 */
@property (nonatomic, readonly) NSUInteger inlineThreshold;

/**
   If this block is not nil, then the block will be used to archive object instead
   of NSKeyedArchiver. You can use this block to support the objects which do not
   conform to the `NSCoding` protocol.

   The default value is nil.
 */
@property (nonatomic, nullable, copy) NSData *(^customArchiveBlock)(id object);

/**
   If this block is not nil, then the block will be used to unarchive object instead
   of NSKeyedUnarchiver. You can use this block to support the objects which do not
   conform to the `NSCoding` protocol.

   The default value is nil.
 */
@property (nonatomic, nullable, copy) id (^customUnarchiveBlock)(NSString *key, NSData *data);

#pragma mark - Limit
///=============================================================================
/// @name Limit
///=============================================================================

/**
   The maximum number of objects the cache should hold.

   @discussion The default value is NSUIntegerMax, which means no limit.
   This is not a strict limit — if the cache goes over the limit, some objects in the
   cache could be evicted later in background queue.
 */
@property (nonatomic, assign) NSUInteger countLimit;

/**
   The maximum total cost that the cache can hold before it starts evicting objects.

   @discussion The default value is NSUIntegerMax, which means no limit.
   This is not a strict limit — if the cache goes over the limit, some objects in the
   cache could be evicted later in background queue.
 */
@property (nonatomic, assign) int64_t costLimit;


@property (nonatomic, assign) int64_t protectedBusinessCostLimit;


/**
   The maximum expiry time of objects in cache.

   @discussion The default value is DBL_MAX, which means no limit.
   This is not a strict limit — if an object goes over the limit, the objects could
   be evicted later in background queue.
 */
@property (nonatomic, assign) NSTimeInterval ageLimit;

/**
   The minimum free disk space (in bytes) which the cache should kept.

   @discussion The default value is 0, which means no limit.
   If the free disk space is lower than this value, the cache will remove objects
   to free some disk space. This is not a strict limit—if the free disk space goes
   over the limit, the objects could be evicted later in background queue.
 */
@property (nonatomic, assign) NSUInteger freeDiskSpaceLimit;

/**
   The auto trim check time interval in seconds. Default is 60 (1 minute).

   @discussion The cache holds an internal timer to check whether the cache reaches
   its limits, and if the limit is reached, it begins to evict objects.
 */
@property (nonatomic, assign) NSTimeInterval autoTrimInterval;

/**
   Set `YES` to enable error logs for debug.
 */
@property (nonatomic, assign) BOOL errorLogsEnabled;

/**
 *  trim都不会删除这个白名单中的业务
 */
@property (nonatomic, copy) NSArray <NSString *>*protectedBusinesses;
@property (nonatomic, assign) NSUInteger protectedTags;

#pragma mark - Initializer
///=============================================================================
/// @name Initializer
///=============================================================================
- (instancetype)init UNAVAILABLE_ATTRIBUTE;
+ (instancetype)new UNAVAILABLE_ATTRIBUTE;

/**
   Create a new cache based on the specified path.

   @param path Full path of a directory in which the cache will write data.
   Once initialized you should not read and write to this directory.

   @return A new cache object, or nil if an error occurs.

   @warning If the cache instance for the specified path already exists in memory,
   this method will return it directly, instead of creating a new instance.
 */
- (nullable instancetype)initWithPath:(NSString *)path;

/**
   The designated initializer.

   @param path       Full path of a directory in which the cache will write data.
   Once initialized you should not read and write to this directory.

   @param threshold  The data store inline threshold in bytes. If the object's data
   size (in bytes) is larger than this value, then object will be stored as a
   file, otherwise the object will be stored in sqlite. 0 means all objects will
   be stored as separated files, NSUIntegerMax means all objects will be stored
   in sqlite. If you don't know your object's size, 20480 is a good choice.
   After first initialized you should not change this value of the specified path.

   @return A new cache object, or nil if an error occurs.

   @warning If the cache instance for the specified path already exists in memory,
   this method will return it directly, instead of creating a new instance.
 */
- (nullable instancetype)initWithPath:(NSString *)path
                      inlineThreshold:(NSUInteger)threshold NS_DESIGNATED_INITIALIZER;

#pragma mark - Access Methods
///=============================================================================
/// @name Access Methods
///=============================================================================

/**
 *  为缓存类型准备存储空间
 *
 *  @param type 缓存类型
 */
- (void)registerType:(int)type;


/**
 *  对已注册类型批量创建文件夹
 */
- (void)lazyRegister;

/**
 *  设置对应类型的文件名生成方法
 *
 *  @param customFilenameBlock 文件名生成block，返回值将用作新的文件名。block中key为请求的key，filename为默认生成的文件名
 *  @param type                缓存类型
 */
- (void)setCustomFilenameBlock:(NSString *(^)(NSString *key, NSString *filename))customFilenameBlock forType:(int)type;

/**
   Returns a boolean value that indicates whether a given key is in cache.
   This method may blocks the calling thread until file read finished.

   @param key A string identifying the value. If nil, just return NO.
   @return Whether the key is in cache.
 */
- (BOOL)containsObjectForKey:(NSString *)key;

#ifdef APM_USE_ASYNC
/**
   Returns a boolean value with the block that indicates whether a given key is in cache.
   This method returns immediately and invoke the passed block in background queue
   when the operation finished.

   @param key   A string identifying the value. If nil, just return NO.
   @param block A block which will be invoked in background queue when finished.
 */
- (void)containsObjectForKey:(NSString *)key withBlock:(void (^)(NSString *key, BOOL contains))block;
#endif

/**
   Returns the value associated with a given key.
   This method may blocks the calling thread until file read finished.

   @param key A string identifying the value. If nil, just return nil.
   @return The value associated with key, or nil if no value is associated with key.
 */
- (nullable id<NSCoding>)objectForKey:(NSString *)key;

/**
 *  查询缓存，存在一个key对应多个对象的情况，这里使用selectionBlock来选择哪一条记录满足条件
 *
 *  @param key            缓存对象的key
 *  @param selectionBlock 从多个对象中选择需要缓存的blocki
 *
 *  @return key所对应的缓存对象
 */
- (nullable id<NSCoding>)objectForKey:(NSString *)key selectionBlock:(APMCacheItem *(^)(NSArray <APMCacheItem *> * _Nullable infos))selectionBlock;

#ifdef APM_USE_ASYNC
/**
   Returns the value associated with a given key.
   This method returns immediately and invoke the passed block in background queue
   when the operation finished.

   @param key A string identifying the value. If nil, just return nil.
   @param block A block which will be invoked in background queue when finished.
 */
- (void)objectForKey:(NSString *)key withBlock:(void (^)(NSString *key, id<NSCoding> _Nullable object))block;
#endif

/**
 *  获取对应key的缓存对象的扩展信息
 *
 *  @param key 缓存对象的key
 *
 *  @return 扩展信息，存储时指定
 */
- (nullable NSString *)extendedInfoForKey:(NSString *)key;

/**
 *  查询对应key的别名
 *
 *  @param key 缓存对象的key
 *
 *  @return key的别名
 */
- (nullable NSString *)aliasKeyForKey:(NSString *)key;

/**
 *  查询对应tag和时间范围内的缓存对象，条件为：包含tag以及比给定时间晚
 *
 *  @param tag  限定的tag查询条件
 *  @param time 限定的时间查询条件
 *
 *  @return 满足给定条件的缓存对象
 */
- (nullable NSArray <APMCacheItem *>*)itemsWithTag:(NSUInteger)tag laterThanTime:(int)time;

/**
 *  查询对应key的缓存信息，不包含数据本身
 *
 *  @param key 对应缓存对象的key
 *
 *  @return 缓存对象的基本信息，不包含数据
 */
- (nullable APMCacheItem *)itemForKey:(NSString *)key;

/**
   Sets the value of the specified key in the cache.
   This method may blocks the calling thread until file write finished.

   @param object The object to be stored in the cache. If nil, it calls `removeObjectForKey:`.
   @param key    The key with which to associate the value. If nil, this method has no effect.
 */
- (void)setObject:(nullable id<NSCoding>)object forKey:(NSString *)key;

/**
   Sets the value of the specified key in the cache.
   This method returns immediately and invoke the passed block in background queue
   when the operation finished.

   @param object The object to be stored in the cache. If nil, it calls `removeObjectForKey:`.
   @param block  A block which will be invoked in background queue when finished.
 */
#ifdef APM_USE_ASYNC
- (void)setObject:(nullable id<NSCoding>)object forKey:(NSString *)key withBlock:(void (^)(void))block;
- (void)setObject:(nullable id<NSCoding>)object forKey:(NSString *)key type:(NSUInteger)type business:(nullable NSString *)business tag:(NSUInteger)tag withBlock:(void (^)(void))block;
- (void)setObject:(nullable id<NSCoding>)object forKey:(NSString *)key uuid:(NSString *)uuid type:(NSUInteger)type business:(nullable NSString *)business tag:(NSUInteger)tag withBlock:(void (^)(void))block;
#endif

- (BOOL)setObject:(nullable id<NSCoding>)object forKey:(NSString *)key type:(NSUInteger)type business:(nullable NSString *)business tag:(NSUInteger)tag;
- (BOOL)setObject:(nullable id<NSCoding>)object forKey:(NSString *)key uuid:(NSString *)uuid type:(NSUInteger)type business:(nullable NSString *)business tag:(NSUInteger)tag;
- (BOOL)setObject:(nullable id<NSCoding>)object forKey:(NSString *)key uuid:(NSString *)uuid type:(NSUInteger)type business:(nullable NSString *)business tag:(NSUInteger)tag expirationTime:(int)expirationTime;

- (BOOL)setObjectWithPath:(NSString *)path forKey:(NSString *)key uuid:(NSString *)uuid type:(NSUInteger)type business:(NSString *)business tag:(NSUInteger)tag info:(nullable NSString *)info;
- (BOOL)setObjectWithPath:(NSString *)path forKey:(NSString *)key uuid:(NSString *)uuid type:(NSUInteger)type business:(NSString *)business tag:(NSUInteger)tag info:(nullable NSString *)info expirationTime:(int)expirationTime;

/**
 *  更新对象的别名
 *
 *  @param aliasKey 需要设置的key对应的别名
 *  @param key      对应缓存对象的key
 */
- (void)updateAliasKey:(nullable NSString *)aliasKey forKey:(NSString *)key;

/**
 *  更新对象的业务标识
 *
 *  @param business 需要设置的业务标识
 *  @param key      对应的key
 */
- (void)updateBusiness:(nullable NSString *)business forKey:(NSString *)key;

/**
 *  更新对象的别名和业务标识
 *
 *  @param aliasKey 缓存对象的别名
 *  @param business 业务标识
 *  @param key      缓存对象的key
 */
- (void)updateAliasKey:(nullable NSString *)aliasKey business:(nullable NSString *)business forKey:(NSString *)key;

/**
 *  更新对象的扩展信息
 *
 *  @param info 扩展信息
 *  @param key  缓存对象的key
 */
- (void)updateInfo:(NSString *)info forKey:(NSString *)key;

/**
 *  更新对象的标签
 *
 *  @param tag         标签
 *  @param key         缓存对象的key
 *  @param addOrRemove 增加还是删除指定的tag标识
 */
- (void)updateTag:(NSUInteger)tag forKey:(NSString *)key addOrRemove:(BOOL)addOrRemove;

/**
 *  根据缓存路径更新缓存的访问时间
 *
 *  @param path 缓存的路径
 */
- (void)updateAccessTimeWithPath:(NSString *)path;

/**
   Removes the value of the specified key in the cache.
   This method may blocks the calling thread until file delete finished.

   @param key The key identifying the value to be removed. If nil, this method has no effect.
 */
- (void)removeObjectForKey:(NSString *)key;

#ifdef APM_USE_ASYNC
/**
   Removes the value of the specified key in the cache.
   This method returns immediately and invoke the passed block in background queue
   when the operation finished.

   @param key The key identifying the value to be removed. If nil, this method has no effect.
   @param block  A block which will be invoked in background queue when finished.
 */
- (void)removeObjectForKey:(NSString *)key withBlock:(void (^)(NSString *key))block;
#endif

/**
   Empties the cache.
   This method may blocks the calling thread until file delete finished.
 */
- (void)removeAllObjects;

#ifdef APM_USE_ASYNC
/**
   Empties the cache.
   This method returns immediately and invoke the passed block in background queue
   when the operation finished.

   @param block  A block which will be invoked in background queue when finished.
 */
- (void)removeAllObjectsWithBlock:(void (^)(void))block;

/**
   Empties the cache with block.
   This method returns immediately and executes the clear operation with block in background.

   @warning You should not send message to this instance in these blocks.
   @param progress This block will be invoked during removing, pass nil to ignore.
   @param end      This block will be invoked at the end, pass nil to ignore.
 */
- (void)removeAllObjectsWithProgressBlock:(nullable void (^)(int removedCount, int totalCount))progress
                                 endBlock:(nullable void (^)(BOOL error))end;
#endif

/**
   Returns the number of objects in this cache.
   This method may blocks the calling thread until file read finished.

   @return The total objects count.
 */
- (NSInteger)totalCount;

#ifdef APM_USE_ASYNC
/**
   Get the number of objects in this cache.
   This method returns immediately and invoke the passed block in background queue
   when the operation finished.

   @param block  A block which will be invoked in background queue when finished.
 */
- (void)totalCountWithBlock:(void (^)(NSInteger totalCount))block;
#endif

/**
   Returns the total cost (in bytes) of objects in this cache.
   This method may blocks the calling thread until file read finished.

   @return The total objects cost in bytes.
 */
- (int64_t)totalCost;

/**
 *  查询指定类型的缓存对象大小(字节为单位)
 *
 *  @param type 缓存类型
 *
 *  @return 满足条件的缓存总大小(字节为单位)
 */
- (int64_t)totalCostWithType:(NSUInteger)type;

/**
 *  查询在指定时间之前访问过的缓存对象大小总合(字节为单位)
 *
 *  @param time 时间点
 *
 *  @return 满足条件的缓存总大小(字节为单位)
 */
- (int64_t)totalCostEarlierThanTime:(int)time;

/**
 *  根据业务标识和缓存标签统计缓存的大小
 *
 *  @return 以业务识别和缓存标签分类的缓存统计大小
 */
- (nullable NSArray<NSDictionary *> *)costGroupByBusinessAndTag;

#ifdef APM_USE_ASYNC
/**
   Get the total cost (in bytes) of objects in this cache.
   This method returns immediately and invoke the passed block in background queue
   when the operation finished.

   @param block  A block which will be invoked in background queue when finished.
 */
- (void)totalCostWithBlock:(void (^)(int64_t totalCost))block;
#endif

#pragma mark - Path

/**
 *  指定缓存类型的根目录
 *
 *  @param type 缓存类型
 *
 *  @return 指定缓存类型的根目录
 */
- (NSString *)rootPathForType:(NSUInteger)type;

/**
 *  查询缓存存储在磁盘上的路径
 *
 *  @param key 缓存对应的key
 *
 *  @return 缓存路径
 */
- (nullable NSString *)objectPathForKey:(NSString *)key;

/**
 *  生成缓存应该存储的路径
 *
 *  @param key  缓存对应的key
 *  @param type 缓存类型
 *
 *  @return 对应缓存类型与key的存储路径
 */
- (NSString *)generatePathForKey:(NSString *)key type:(NSUInteger)type;

#pragma mark - Trim
///=============================================================================
/// @name Trim
///=============================================================================

/**
   Removes objects from the cache use LRU, until the `totalCount` is below the specified value.
   This method may blocks the calling thread until operation finished.

   @param count  The total count allowed to remain after the cache has been trimmed.
 */
- (void)trimToCount:(NSUInteger)count;

#ifdef APM_USE_ASYNC
/**
   Removes objects from the cache use LRU, until the `totalCount` is below the specified value.
   This method returns immediately and invoke the passed block in background queue
   when the operation finished.

   @param count  The total count allowed to remain after the cache has been trimmed.
   @param block  A block which will be invoked in background queue when finished.
 */
- (void)trimToCount:(NSUInteger)count withBlock:(void (^)(void))block;
#endif

/**
   Removes objects from the cache use LRU, until the `totalCost` is below the specified value.
   This method may blocks the calling thread until operation finished.

   @param cost The total cost allowed to remain after the cache has been trimmed.
 */
- (void)trimToCost:(int64_t)cost;

#ifdef APM_USE_ASYNC
/**
   Removes objects from the cache use LRU, until the `totalCost` is below the specified value.
   This method returns immediately and invoke the passed block in background queue
   when the operation finished.

   @param cost The total cost allowed to remain after the cache has been trimmed.
   @param block  A block which will be invoked in background queue when finished.
 */
- (void)trimToCost:(int64_t)cost withBlock:(void (^)(void))block;
#endif

/**
   Removes objects from the cache use LRU, until all expiry objects removed by the specified value.
   This method may blocks the calling thread until operation finished.

   @param age  The maximum age of the object.
 */
- (void)trimToAge:(NSTimeInterval)age;

#ifdef APM_USE_ASYNC
/**
   Removes objects from the cache use LRU, until all expiry objects removed by the specified value.
   This method returns immediately and invoke the passed block in background queue
   when the operation finished.

   @param age  The maximum age of the object.
   @param block  A block which will be invoked in background queue when finished.
 */
- (void)trimToAge:(NSTimeInterval)age withBlock:(void (^)(void))block;
#endif

/**
 *  清理指定业务标识的缓存，所有生存时间超过指定时间的都清除
 *
 *  @param age      指定的生存时间点，超过此时间的缓存将被清除
 *  @param business 业务标识
 */
- (void)trimToAge:(NSTimeInterval)age forBusiness:(NSString *)business;

/**
 *  清理指定业务标识的缓存，所有生存时间超过指定时间的都清除，除了指定的标签
 *
 *  @param age       指定的生存时间点，超过此时间的缓存将被清除
 *  @param business  业务标识
 *  @param exceptTag 缓存的标签，满足此标签的缓存不清除
 */
- (void)trimToAge:(NSTimeInterval)age forBusiness:(NSString *)business exceptTag:(NSUInteger)tag;

#pragma mark - Extended Data
///=============================================================================
/// @name Extended Data
///=============================================================================

/**
   Get extended info from an object.

   @discussion See 'setInfo:toObject:' for more information.

   @param object An object.
   @return The extended info.
 */
+ (nullable NSString *)getExtendedInfoFromObject:(id)object;

/**
   Set extended info to an object.

   @discussion You can set any extended data to an object before you save the object
   to disk cache. The extended data will also be saved with this object. You can get
   the extended data later with "getExtendedDataFromObject:".

   @param info         The extended info (pass nil to remove).
   @param object       The object.
 */
+ (void)setExtendedInfo:(nullable NSString *)info toObject:(id)object;

@end

NS_ASSUME_NONNULL_END
