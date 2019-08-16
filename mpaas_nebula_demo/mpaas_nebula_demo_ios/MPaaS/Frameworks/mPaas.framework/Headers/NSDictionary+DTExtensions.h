//
//  NSDictionary+DTExtensions.h
//  APContact
//
//  Created by 逆仞 on 14-3-18.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>


typedef id (^NSDictionaryObjectValidator)(id object);


/**
 * DTExtensions for reading value for key
 * @see NSUserDefaults
 */
@interface NSDictionary (DTExtensions)

/* C */
- (float)floatForKey:(id)aKey;
- (float)floatForKey:(id)aKey defaultValue:(float)defaultValue;
- (double)doubleForKey:(id)aKey;
- (double)doubleForKey:(id)aKey defaultValue:(double)defaultValue;
/* C More */
- (long long)longLongForKey:(id)aKey;
- (unsigned long long)unsignedLongLongForKey:(id)aKey;

/* OC */
- (BOOL)boolForKey:(id)aKey;
- (BOOL)boolForKey:(id)aKey defaultValue:(BOOL)defaultValue;
- (NSInteger)integerForKey:(id)aKey;
- (NSInteger)integerOrNotFoundForKey:(id)aKey;
- (NSInteger)integerForKey:(id)aKey defaultValue:(NSInteger)defaultValue;

/* OC More */
- (NSUInteger)unsignedIntegerForKey:(id)aKey;
- (NSUInteger)unsignedIntegerOrNotFoundForKey:(id)aKey;
- (NSUInteger)unsignedIntegerForKey:(id)aKey defaultValue:(NSUInteger)defaultValue;

/* OC Object */
- (NSNumber *)numberForKey:(id)aKey;
- (NSNumber *)numberForKey:(id)aKey defaultValue:(NSNumber *)defaultValue;
- (NSString *)stringForKey:(id)aKey;
- (NSString *)stringOrEmptyStringForKey:(id)akey;
- (NSString *)stringForKey:(id)akey defaultValue:(NSString *)defaultValue;
- (NSArray *)arrayForKey:(id)aKey;
- (NSArray *)arrayForKey:(id)aKey defaultValue:(NSArray *)defaultValue;
- (NSDictionary *)dictionaryForKey:(id)aKey;
- (NSDictionary *)dictionaryForKey:(id)aKey defaultValue:(NSDictionary *)defaultValue;
- (NSData *)dataForKey:(id)aKey;
- (NSData *)dataForKey:(id)aKey defaultValue:(NSData *)defaultValue;
- (NSDate *)dateForKey:(id)aKey;
- (NSDate *)dateForKey:(id)aKey defaultValue:(NSDate *)defaultValue;
- (NSURL *)URLForKey:(id)aKey;
- (NSURL *)URLForKey:(id)aKey defaultValue:(NSURL *)defaultValue;

/* OC Object More */
- (id)objectForKey:(id)aKey class:(Class)theClass;
- (id)objectForKey:(id)aKey class:(Class)theClass defaultValue:(id)defaultValue;
- (id)objectForKey:(id)aKey protocol:(Protocol *)protocol;
- (id)objectForKey:(id)aKey protocol:(Protocol *)protocol defaultValue:(id)defaultValue;
- (id)objectForKey:(id)aKey class:(Class)theClass protocol:(Protocol *)protocol;
- (id)objectForKey:(id)aKey class:(Class)theClass protocol:(Protocol *)protocol defaultValue:(id)defaultValue;
- (id)objectForKey:(id)aKey callback:(NSDictionaryObjectValidator)callback;

@end


/**
 * DTExtensions for writing value for key
 */
@interface NSMutableDictionary (DTExtensions)

/* C */
- (void)setFloat:(float)value forKey:(id<NSCopying>)aKey;
- (void)setDouble:(double)value forKey:(id<NSCopying>)aKey;

/* C More */
- (void)setLongLong:(long long)value forKey:(id<NSCopying>)aKey;
- (void)setUnsignedLongLong:(unsigned long long)value forKey:(id<NSCopying>)aKey;

/* OC */
- (void)setBool:(BOOL)value forKey:(id<NSCopying>)aKey;
- (void)setInteger:(NSInteger)value forKey:(id<NSCopying>)aKey;

/* OC More */
- (void)setUnsignedInteger:(NSUInteger)value forKey:(id<NSCopying>)aKey;

/* OC Object */
- (void)setObjectOrNil:(id)anObject forKey:(id<NSCopying>)aKey;

/**
 *  @brief 给可变字典设置对象，如果对象为nil，直接返回不修改原始数据
 *
 *  @param anObject obj
 *  @param aKey     key
 */
- (void)setSafeObject:(id)anObject forKey:(id<NSCopying>)aKey;

@end

