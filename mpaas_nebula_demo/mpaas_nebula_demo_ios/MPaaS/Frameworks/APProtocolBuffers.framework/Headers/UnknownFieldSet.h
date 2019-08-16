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

@class PBCodedOutputStream;
@class PBField;
@class PBUnknownFieldSetBuilder;

@interface PBUnknownFieldSet : NSObject {
@private
  NSDictionary* fields;
}

@property (readonly, strong) NSDictionary* fields;
//defaultInstance
+ (PBUnknownFieldSet*) defaultInstance;
//设置field
+ (PBUnknownFieldSet*) setWithFields:(NSMutableDictionary*) fields;
//设置data
+ (PBUnknownFieldSet*) parseFromData:(NSData*) data;
//builder
+ (PBUnknownFieldSetBuilder*) builder;
//设置UnknownFields with other
+ (PBUnknownFieldSetBuilder*) builderWithUnknownFields:(PBUnknownFieldSet*) other;

//- (void) writeAsMessageSetTo:(PBCodedOutputStream*) output;
- (void) writeToCodedOutputStream:(PBCodedOutputStream*) output;
//该field的data
- (NSData*) data;
//该field的size
- (SInt32) serializedSize;
//- (SInt32) serializedSizeAsMessageSet;

- (BOOL) hasField:(SInt32) number;
//get Field with number
- (PBField*) getField:(SInt32) number;
//添加到des字符串
- (void) writeDescriptionTo:(NSMutableString*) output
                 withIndent:(NSString*) indent;
//字典存储
- (void) storeInDictionary: (NSMutableDictionary *) dic;

@end
