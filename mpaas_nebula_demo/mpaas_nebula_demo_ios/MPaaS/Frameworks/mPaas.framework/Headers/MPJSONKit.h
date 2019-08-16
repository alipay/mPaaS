//
//  MPJSONKit.h
//  MPJSONKit
//
//  Created by shenmo on 12/28/14.
//  Copyright (c) 2014 shenmo. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "DTNumber.h"

#pragma mark APJSONExtensions.h

@interface NSObject (APJSONKitExtensions)

/**
 *  将NSObject序列化成字符串。
 *
 *  @return 序列化成字符串.（该方法实际调用APJSONString）
 */
- (NSString *)JSONString;

- (NSString *)APJSONString;

@end

@interface NSString (APJSONKitExtensions)

/**
 *  将字符串反序列化成NSObject对象。
 *
 *  @return 反序列化NSObject对象。（该方法实际调用APJSONValue）
 */
- (id)JSONValue;

- (id)APJSONValue;

@end

@interface NSData (APJSONKitExtensions)

/**
 *  将Data反序列化成NSObject对象。
 *  Data应该应该是utf8编码的json字符串。
 *
 *  @return 反序列化NSObject对象。（该方法实际调用APJSONValue）
 */
- (id)JSONValue;

- (id)APJSONValue;

@end

#pragma mark DTJsonDecoder.h

extern NSString * const NSClassCastExpcetion;

@interface DTJsonDecoder : NSObject

+ (DTJsonDecoder *)decoder;

- (id)decodeWithClass:(Class)cls elementClass:(Class)elementClass fromJSONString:(NSString *)string;
- (id)decodeWithClass:(Class)cls elementClass:(Class)elementClass fromJSONObject:(id)json;
- (id)decodeWithClassName:(NSString *)className elementClass:(Class)elementClass fromJSONObject:(id)json;

@end

#pragma mark DTJsonEncoder.h

@interface DTJsonEncoder : NSObject

/**
 * Creates and return a new <code>DTJsonEncoder</code> object.
 *
 * @return A newly created and initialized object of <code>DTJsonEncoder</code.
 */
+ (DTJsonEncoder *)encoder;

/**
 * Encodes a JSON object into a string with JSON format.
 *
 *
 */
- (NSString *)encodeObject:(id)object;

@end
