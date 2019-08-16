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

#import "Field.h"

@class PBUnknownFieldSet;

@interface PBMutableField : PBField
/**
 *	@brief	空参数实例化
 *
 *	@param
 *
 *	@return 实例
 */
+ (PBMutableField *)field;
/**
 *	@brief	PBField实例化
 *
 *	@param 	other
 *
 *	@return 实例
 */
- (PBMutableField *)mergeFromField:(PBField *)other;
/**
 *	@brief	释放成员变量
 *
 *	@param
 *
 *	@return 实例
 */
- (PBMutableField *)clear;
/**
 *	@brief	添加可变64位整数
 *
 *	@param 	value
 *
 *	@return 实例
 */
- (PBMutableField *)addVarint:(SInt64)value;
/**
 *	@brief	添加可变32位整数
 *
 *	@param 	value
 *
 *	@return 实例
 */
- (PBMutableField *)addFixed32:(SInt32)value;
/**
 *	@brief	添加不可变64位整数
 *
 *	@param 	value
 *
 *	@return 实例
 */
- (PBMutableField *)addFixed64:(SInt64)value;
/**
 *	@brief	add NSData
 *
 *	@param 	value
 *
 *	@return 实例
 */
- (PBMutableField *)addLengthDelimited:(NSData *)value;
/**
 *	@brief	添加未知set
 *
 *	@param 	value
 *
 *	@return 实例
 */
- (PBMutableField *)addGroup:(PBUnknownFieldSet *)value;

@end