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

#import "WireFormat.h"

@class PBCodedInputStream;
@class PBCodedOutputStream;
//@class PBExtendableMessageBuilder;
@class PBExtensionRegistry;
@class PBUnknownFieldSetBuilder;

@protocol PBExtensionField
/**
 *	@brief	fieldNumber
 *
 *	@return int32
 */
- (SInt32) fieldNumber;
/**
 *	@brief	wireType
 *
 *	@return PBWireFormat
 */
- (PBWireFormat) wireType;
/**
 *	@brief	isRepeated
 *
 *	@return YES/NO
 */
- (BOOL) isRepeated;
/**
 *	@brief	extendedClass
 *
 *	@return CLass
 */
- (Class) extendedClass;
/**
 *	@brief	默认值
 *
 *	@return instance
 */
- (instancetype) defaultValue;

//- (void) mergeFromCodedInputStream:(PBCodedInputStream*) input
//                     unknownFields:(PBUnknownFieldSetBuilder*) unknownFields
//                 extensionRegistry:(PBExtensionRegistry*) extensionRegistry
//                           builder:(PBExtendableMessageBuilder*) builder
//                               tag:(SInt32) tag;
- (void) writeValue:(id) value includingTagToCodedOutputStream:(PBCodedOutputStream*) output;
/**
 *	@brief	计算长度
 *
 *	@return size
 */
- (SInt32) computeSerializedSizeIncludingTag:(id) value;
/**
 *	@brief 打印描述
 *
 *	@return
 */
- (void) writeDescriptionOf:(id) value
                         to:(NSMutableString*) output
                 withIndent:(NSString*) indent;
/**
 *	@brief	添加到dic
 *
 *	@return 
 */
- (void) addDictionaryEntriesOf:(id) value
                             to:(NSMutableDictionary*) dictionary;
@end
