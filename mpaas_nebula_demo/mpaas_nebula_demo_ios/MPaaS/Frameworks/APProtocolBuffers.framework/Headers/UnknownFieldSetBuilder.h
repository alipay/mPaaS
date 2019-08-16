// Protocol Buffers for Objective C
//
// Copyright 2010 Booyah Inc.
// Copyright 2008 Cyrus Najmabadi
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

#import "MessageBuilder.h"

@class PBField;
@class PBMutableField;

@interface PBUnknownFieldSetBuilder : NSObject <PBMessageBuilder> {
@private
  NSMutableDictionary* fields;

  // Optimization:  We keep around a builder for the last field that was
  //   modified so that we can efficiently add to it multiple times in a
  //   row (important when parsing an unknown repeated field).
  SInt32 lastFieldNumber;

  PBMutableField* lastField;
}

//+ (PBUnknownFieldSetBuilder*) createBuilder:(PBUnknownFieldSet*) unknownFields;

- (PBUnknownFieldSet*) build;
/**
 *	@brief	合并Unknown类型
 *
 *	@param 	PBUnknownFieldSet
 *
 *	@return instance
 */
- (PBUnknownFieldSetBuilder*) mergeUnknownFields:(PBUnknownFieldSet*) other;
/**
 *	@brief	合并Unknown类型
 *
 *	@param 	PBCodedInputStream
 *
 *	@return instance
 */
- (PBUnknownFieldSetBuilder*) mergeFromCodedInputStream:(PBCodedInputStream*) input;
/**
 *	@brief	合并Unknown类型
 *
 *	@param 	NSData
 *
 *	@return instance
 */
- (PBUnknownFieldSetBuilder*) mergeFromData:(NSData*) data;
/**
 *	@brief	合并Unknown类型
 *
 *	@param 	NSInputStream
 *
 *	@return instance
 */
- (PBUnknownFieldSetBuilder*) mergeFromInputStream:(NSInputStream*) input;
/**
 *	@brief	合并可变整数
 *
 *	@param 	number
 *	@param 	value
 *
 *	@return instance
 */
- (PBUnknownFieldSetBuilder*) mergeVarintField:(SInt32) number value:(SInt32) value;
/**
 *	@brief	同构PB的tag合并input类型
 *
 *	@param 	tag
 *	@param 	input
 *
 *	@return instance
 */
- (BOOL) mergeFieldFrom:(SInt32) tag input:(PBCodedInputStream*) input;
/**
 *	@brief	添加field
 *
 *	@param 	field
 *	@param 	number
 *
 *	@return instance
 */
- (PBUnknownFieldSetBuilder*) addField:(PBField*) field forNumber:(SInt32) number;
/**
 *	@brief	clear
 *
 *	@return instance
 */
- (PBUnknownFieldSetBuilder*) clear;
/**
 *	@brief	合并field
 *
 *	@param 	field
 *	@param 	number
 *
 *	@return instance
 */
- (PBUnknownFieldSetBuilder*) mergeField:(PBField*) field forNumber:(SInt32) number;

@end
