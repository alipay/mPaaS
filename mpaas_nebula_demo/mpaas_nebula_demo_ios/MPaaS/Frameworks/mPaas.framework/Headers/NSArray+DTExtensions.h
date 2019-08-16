//
//  NSArray+DTExtensions.h
//  APContact
//
//  Created by 逆仞 on 14-3-18.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>


typedef id (^NSArrayObjectValidator)(id object);


/**
 * DTExtensions for reading value at index
 */
@interface NSArray (DTExtensions)

@property(nonatomic, readonly, assign) NSUInteger count;
//@property(nonatomic, readonly, retain) id firstObject;
//@property(nonatomic, readonly, retain) id lastObject;

- (id)objectOrNilAtIndex:(NSUInteger)index;
- (BOOL)containsIndex:(NSUInteger)index;

@end


/**
 * DTExtensions for writing value at index
 */
@interface NSMutableArray (DTExtensions)

- (void)addObjectOrNil:(id)anObject;
- (BOOL)insertObjectOrNil:(id)anObject atIndex:(NSUInteger)index;
- (BOOL)replaceObjectAtIndex:(NSUInteger)index withObjectOrNil:(id)anObject;

@end


// NOTE: add or not?

/* C
- (float)floatAtIndex:(NSUInteger)index;
- (float)floatAtIndex:(NSUInteger)index defaultValue:(float)defaultValue;
- (double)doubleAtIndex:(NSUInteger)index;
- (double)doubleAtIndex:(NSUInteger)index defaultValue:(double)defaultValue; */
/* C More
- (long long)longLongAtIndex:(NSUInteger)index;
- (unsigned long long)unsignedLongLongAtIndex:(NSUInteger)index; */

/* OC
- (BOOL)boolAtIndex:(NSUInteger)index;
- (BOOL)boolAtIndex:(NSUInteger)index defaultValue:(BOOL)defaultValue;
- (NSInteger)integerAtIndex:(NSUInteger)index;
- (NSInteger)integerOrNotFoundAtIndex:(NSUInteger)index;
- (NSInteger)integerAtIndex:(NSUInteger)index defaultValue:(NSInteger)defaultValue; */

/* OC More
- (NSUInteger)unsignedIntegerAtIndex:(NSUInteger)index;
- (NSUInteger)unsignedIntegerOrNotFoundAtIndex:(NSUInteger)index;
- (NSUInteger)unsignedIntegerAtIndex:(NSUInteger)index defaultValue:(NSUInteger)defaultValue; */

/* OC Object
- (NSNumber *)numberAtIndex:(NSUInteger)index;
- (NSNumber *)numberAtIndex:(NSUInteger)index defaultValue:(NSNumber *)defaultValue;
- (NSString *)stringAtIndex:(NSUInteger)index;
- (NSString *)stringOrEmptyStringAtIndex:(NSUInteger)index;
- (NSString *)stringAtIndex:(NSUInteger)index defaultValue:(NSString *)defaultValue;
- (NSArray *)arrayAtIndex:(NSUInteger)index;
- (NSArray *)arrayAtIndex:(NSUInteger)index defaultValue:(NSArray *)defaultValue;
- (NSDictionary *)dictionaryAtIndex:(NSUInteger)index;
- (NSDictionary *)dictionaryAtIndex:(NSUInteger)index defaultValue:(NSDictionary *)defaultValue;
- (NSData *)dataAtIndex:(NSUInteger)index;
- (NSData *)dataAtIndex:(NSUInteger)index defaultValue:(NSData *)defaultValue;
- (NSDate *)dateAtIndex:(NSUInteger)index;
- (NSDate *)dateAtIndex:(NSUInteger)index defaultValue:(NSDate *)defaultValue;
- (NSURL *)URLAtIndex:(NSUInteger)index;
- (NSURL *)URLAtIndex:(NSUInteger)index defaultValue:(NSURL *)defaultValue; */

/* OC Object More
- (id)objectAtIndex:(NSUInteger)index class:(Class)class;
- (id)objectAtIndex:(NSUInteger)index class:(Class)class defaultValue:(id)defaultValue;
- (id)objectAtIndex:(NSUInteger)index protocol:(Protocol *)protocol;
- (id)objectAtIndex:(NSUInteger)index protocol:(Protocol *)protocol defaultValue:(id)defaultValue;
- (id)objectAtIndex:(NSUInteger)index class:(Class)class protocol:(Protocol *)protocol;
- (id)objectAtIndex:(NSUInteger)index class:(Class)class protocol:(Protocol *)protocol defaultValue:(id)defaultValue;
- (id)objectAtIndex:(NSUInteger)index callback:(NSArrayObjectValidator)callback; */

