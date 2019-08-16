//
//  APPBGeneratedMessage.h
//  APProtocolBuffers
//
//  Created by JinWenXiang on 15/6/17.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GeneratedMessage.h"

@interface APPBGeneratedMessage : PBGeneratedMessage {
}

/* @protected */
- (BOOL) parseUnknownField:(PBCodedInputStream*) input
             unknownFields:(PBUnknownFieldSetBuilder*) unknownFields
         extensionRegistry:(PBExtensionRegistry*) extensionRegistry
                       tag:(SInt32) tag;

/**
 * Parse {@code data} as a message of this type and merge it with the
 * message being built.  This is just a small wrapper around
 * {@link #mergeFrom(CodedInputStream)}.
 */
- (void) mergeFromData:(NSData*) data;
//merge from CodedInputStream
- (void) mergeFromCodedInputStream:(PBCodedInputStream*) input;

/**
 * Like {@link Builder#mergeFrom(CodedInputStream)}, but also
 * parses extensions.  The extensions that you want to be able to parse
 * must be registered in {@code extensionRegistry}.  Extensions not in
 * the registry will be treated as unknown fields.
 */
- (void) mergeFromCodedInputStream:(PBCodedInputStream*) input extensionRegistry:(PBExtensionRegistry*) extensionRegistry;

//unknown fields
- (PBUnknownFieldSet*) unknownFields;
//set unknown fields
- (void) setUnknownFields:(PBUnknownFieldSet*) unknownFields;
/**
 * Http原始的如果response
 */
@property(nonatomic, strong) NSURLResponse *response;
/**
 * 如果response是NSHTTPURLResponse返回response的allHeaderFields
 */
-(NSDictionary *)allResponseHeaderFields;
@end
