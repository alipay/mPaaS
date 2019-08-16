//
//  APMCache.h
//  APMultimedia
//
//  Created by Cloud on 16/5/20.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "APMMemoryCache.h"
#import "APMDiskCache.h"

NS_ASSUME_NONNULL_BEGIN

/**
   `APMCache` is a thread safe key-value cache.

   It use `APMMemoryCache` to store objects in a small and fast memory cache,
   and use `APMDiskCache` to persisting objects to a large and slow disk cache.
   See `APMMemoryCache` and `APMDiskCache` for more information.
 */
@interface APMCache : NSObject

/** The name of the cache, readonly. */
@property (copy, readonly) NSString *name;

/** The underlying memory cache. see `APMMemoryCache` for more information.*/
@property (strong, readonly) APMMemoryCache *memoryCache;

/** The underlying disk cache. see `APMDiskCache` for more information.*/
@property (strong, readonly) APMDiskCache *diskCache;

/**
 *  Create a default cache instance.i
 *
 *  @return A new cache object, or nil if an error occuors.
 */
+ (nullable instancetype)defaultCache;

/**
   Create a new instance with the specified name.
   Multiple instances with the same name will make the cache unstable.

   @param name  The name of the cache. It will create a dictionary with the name in
   the app's caches dictionary for disk cache. Once initialized you should not
   read and write to this directory.
   @result A new cache object, or nil if an error occurs.
 */
- (nullable instancetype)initWithName:(NSString *)name;

/**
   Create a new instance with the specified name.
   Multiple instances with the same name will make the cache unstable.

   @param name  The name of the cache. It will create a dictionary with the name in
   the app's caches dictionary for disk cache. Once initialized you should not
   read and write to this directory.

   @param threshold  The data store inline threshold in bytes. If the object's data
   size (in bytes) is larger than this value, then object will be stored as a
   file, otherwise the object will be stored in sqlite. 0 means all objects will
   be stored as separated files, NSUIntegerMax means all objects will be stored
   in sqlite. If you don't know your object's size, 20480 is a good choice.
   After first initialized you should not change this value of the specified path.

   @result A new cache object, or nil if an error occurs.
 */
- (nullable instancetype)initWithName:(NSString *)name
                      inlineThreshold:(NSUInteger)threshold;

/**
   Create a new instance with the specified path.
   Multiple instances with the same name will make the cache unstable.

   @param path  Full path of a directory in which the cache will write data.
   Once initialized you should not read and write to this directory.
   @result A new cache object, or nil if an error occurs.
 */
- (nullable instancetype)initWithPath:(NSString *)path;

/**
   Convenience Initializers
   Create a new instance with the specified name.
   Multiple instances with the same name will make the cache unstable.

   @param name  The name of the cache. It will create a dictionary with the name in
   the app's caches dictionary for disk cache. Once initialized you should not
   read and write to this directory.
   @result A new cache object, or nil if an error occurs.
 */
+ (nullable instancetype)cacheWithName:(NSString *)name;

/**
   Convenience Initializers
   Create a new instance with the specified path.
   Multiple instances with the same name will make the cache unstable.

   @param path  Full path of a directory in which the cache will write data.
   Once initialized you should not read and write to this directory.
   @result A new cache object, or nil if an error occurs.
 */
+ (nullable instancetype)cacheWithPath:(NSString *)path;

- (instancetype)init UNAVAILABLE_ATTRIBUTE;
+ (instancetype)new UNAVAILABLE_ATTRIBUTE;

#pragma mark - Access Methods
///=============================================================================
/// @name Access Methods
///=============================================================================

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
- (void)containsObjectForKey:(NSString *)key withBlock:(nullable void (^)(NSString *key, BOOL contains))block;
#endif

/**
   Returns the value associated with a given key.
   This method may blocks the calling thread until file read finished.

   @param key A string identifying the value. If nil, just return nil.
   @return The value associated with key, or nil if no value is associated with key.
 */
- (nullable id<NSCoding>)objectForKey:(NSString *)key;

#ifdef APM_USE_ASYNC
/**
   Returns the value associated with a given key.
   This method returns immediately and invoke the passed block in background queue
   when the operation finished.

   @param key A string identifying the value. If nil, just return nil.
   @param block A block which will be invoked in background queue when finished.
 */
- (void)objectForKey:(NSString *)key withBlock:(nullable void (^)(NSString *key, id<NSCoding> object))block;
#endif

/**
   Sets the value of the specified key in the cache.
   This method may blocks the calling thread until file write finished.

   @param object The object to be stored in the cache. If nil, it calls `removeObjectForKey:`.
   @param key    The key with which to associate the value. If nil, this method has no effect.
 */
- (void)setObject:(nullable id<NSCoding>)object forKey:(NSString *)key;

#ifdef APM_USE_ASYNC
/**
   Sets the value of the specified key in the cache.
   This method returns immediately and invoke the passed block in background queue
   when the operation finished.

   @param object The object to be stored in the cache. If nil, it calls `removeObjectForKey:`.
   @param block  A block which will be invoked in background queue when finished.
 */
- (void)setObject:(nullable id<NSCoding>)object forKey:(NSString *)key withBlock:(nullable void (^)(void))block;
#endif

- (BOOL)setObject:(nullable id<NSCoding>)object forKey:(NSString *)key type:(NSUInteger)type business:(nullable NSString *)business tag:(NSUInteger)tag;
#ifdef APM_USE_ASYNC
- (void)setObject:(nullable id<NSCoding>)object forKey:(NSString *)key type:(NSUInteger)type business:(nullable NSString *)business tag:(NSUInteger)tag withBlock:(void (^)(void))block;
#endif

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
- (void)removeObjectForKey:(NSString *)key withBlock:(nullable void (^)(NSString *key))block;
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

@end

NS_ASSUME_NONNULL_END
