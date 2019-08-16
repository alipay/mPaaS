// Protocol Buffers for Objective C
//
// Copyright 2010 Booyah Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// Author: Jon Parise <jon@booyah.com>

#import <Foundation/Foundation.h>

extern NSString * const PBArrayTypeMismatchException;
extern NSString * const PBArrayNumberExpectedException;
extern NSString * const PBArrayAllocationFailureException;

typedef enum _PBArrayValueType
{
	PBArrayValueTypeBool,
	PBArrayValueTypeInt32,
	PBArrayValueTypeUInt32,
	PBArrayValueTypeInt64,
	PBArrayValueTypeUInt64,
	PBArrayValueTypeFloat,
	PBArrayValueTypeDouble,
} PBArrayValueType;

// PBArray is an immutable array class that's optimized for storing primitive
// values.  All values stored in an PBArray instance must have the same type
// (PBArrayValueType).  Object values (PBArrayValueTypeObject) are retained.
@interface PBArray : NSObject <NSCopying>
{
@protected
	PBArrayValueType	_valueType;
	NSUInteger			_capacity;
	NSUInteger			_count;
	void *				_data;

}
//Count
- (NSUInteger)count;
//bool At Index
- (BOOL)boolAtIndex:(NSUInteger)index;
//int32 At Index
- (SInt32)int32AtIndex:(NSUInteger)index;
//enum At Index
- (SInt32)enumAtIndex:(NSUInteger)index;
//uint32 At Index
- (UInt32)uint32AtIndex:(NSUInteger)index;
//int64 At Index
- (SInt64)int64AtIndex:(NSUInteger)index;
//uint64 At Index
- (UInt64)uint64AtIndex:(NSUInteger)index;
//float At Index
- (Float32)floatAtIndex:(NSUInteger)index;
//double At Index
- (Float64)doubleAtIndex:(NSUInteger)index;
//Equal To Array
- (BOOL)isEqualToArray:(PBArray *)array;
//enumerate
- (void)enumerateObjectsUsingBlock:(void (^)(id obj, NSUInteger idx, BOOL *stop))block;
//index Of Object
- (NSUInteger)indexOfObjectPassingTest:(BOOL (^)(id obj, NSUInteger idx, BOOL *stop))predicate;

//This Methods automaticaly pack/unpack in NSNumber primitive values
- (id)firstObject;
//last Object
- (id)lastObject;
//object At Indexed
- (id)objectAtIndexedSubscript:(NSUInteger)idx;

@property (nonatomic,assign,readonly) PBArrayValueType valueType;
@property (nonatomic,assign,readonly) const void * data;
@property (nonatomic,assign,readonly,getter=count) NSUInteger count;

@end

@interface PBArray (PBArrayExtended)

//- (instancetype)arrayByAppendingArray:(PBArray *)array;
- (PBArray *)filteredArrayUsingPredicate:(NSPredicate *)predicate;
@end

@interface PBArray (PBArrayCreation)
//init With PBArrayValueType
+ (instancetype)arrayWithValueType:(PBArrayValueType)valueType;
//+ (instancetype)arrayWithValues:(const void *)values count:(NSUInteger)count valueType:(PBArrayValueType)valueType;
+ (instancetype)arrayWithArray:(NSArray *)array valueType:(PBArrayValueType)valueType;
//init With PBArrayValueType
- (instancetype)initWithValueType:(PBArrayValueType)valueType;
//init With (values,count,valueType)
- (instancetype)initWithValues:(const void *)values count:(NSUInteger)count valueType:(PBArrayValueType)valueType;
//init With Array
- (instancetype)initWithArray:(NSArray *)array valueType:(PBArrayValueType)valueType;

@end

// PBAppendableArray extends PBArray with the ability to append new values to
// the end of the array.
@interface PBAppendableArray : PBArray
//add BOOL
- (void)addBool:(BOOL)value;
//add Int32
- (void)addInt32:(SInt32)value;
//add Uint32
- (void)addUint32:(UInt32)value;
//add Int64
- (void)addInt64:(SInt64)value;
//add Uint64
- (void)addUint64:(UInt64)value;
//add Float
- (void)addFloat:(Float32)value;
//add Double
- (void)addDouble:(Float64)value;
//add Enum
- (void)addEnum:(SInt32)value;

//append Array
- (void)appendArray:(PBArray *)array;
//append Values
- (void)appendValues:(const void *)values count:(UInt32)count;

@end
