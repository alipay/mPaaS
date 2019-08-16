//
//  APBase64.h
//  APUtils
//
//  Created by WenBi on 13-8-30.
//  Copyright (c) 2013年 WenBi. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * 依据 RFC 2405 实现 Base64 的编码和解码。
 * 在任意的字节数组中可能会包含不可见字符，而这些不可见字符不能在文本网络协议中传输。
 * Base64 编码就是将这些不可见的字符序列转换成以ASCII编码的字符串，从而解决不可见字符在文本
 * 网络协议中传输的问题。
 */
@interface APBase64 : NSObject

/**
 * 把一个 NSData 的对象转换成 Base64 编码的字符串。
 *
 * @param data 要编码的 NSData 对象，其中包含任意的字节序列。
 * @return 编码后的字符串。如果参数 <code>data</code> 为 <code>nil</code>，或
 *  <code>data.length</code> 的值为零，则返回 <code>nil</code>。
 */
+ (NSString *)encodeData:(NSData *)data;

/**
 * 把一个字节数组进行 Base64 编码。
 *
 * @param bytes 指向要编码的字节数组的指针
 * @param length 字节数组的长度，如果这个参数为零，则简单的返回 <code>nil</code>
 * @return Base64 编码后的数据字符串。
 */
+ (NSString *)encodeBytes:(const void *)bytes length:(NSUInteger)length;

/**
 * 把一个普通的字符串进行 Base64 编码。
 *
 * @param string 要编译的字符串。
 * @param encoding 把字符串转换成C类型的字符串时所用的编码格式。
 * @return Base64 编码后的字符串。
 *
 * 因为 NSString 对象表示的字符串是 unicode 的字符串，
 * 要对它进行编码需要先转换成C类型的字符串（字节序列），所以使用这个方法要指定要编码的字符串
 * 转换成C类型的字符串时所用的编码格式（在 NSStringEncoding 中定义，通常情况下为：NSUTF8StringEncoding）。
 */
+ (NSString *)encodeString:(NSString *)string encoding:(NSStringEncoding)encoding;

/**
 * 创建并返回一个包含Base64编码后数据的 NSData 对象。
 * 
 * @param data 一个 NSData 对象，其中包含需要编码的字节序列。
 * @return 包含 Base64 编码后数据的 NSData 对象。
 */
+ (NSData *)dataByEncodingData:(NSData *)data;

/**
 * 创建并返回一个包含Base64编码后数据的 NSData 对象。
 *
 * @param bytes 要编码的字节数组。
 * @param length 字节数组的长度。
 * @return 包含 Base64 编码后数据的 NSData 对象。
 */
+ (NSData *)dataByEncodingBytes:(const void *)bytes length:(NSUInteger)length;

/**
 * 创建并返回一个包含Base64编码后数据的 NSData 对象。
 *
 * @param string 需要编码的字符串。
 * @param encoding 需要编码的字符串转换成C风格的字符串时使用的编码格式，
 *  由 NSStringEncoding 定义，通常使用的值为：NSUTF8StringEncoding。
 * @return 包含 Base64 编码后数据的 NSData 对象。
 */
+ (NSData *)dataByEncodingString:(NSString *)string encoding:(NSStringEncoding)encoding;

/**
 * Creates and returns a data object containing the bytes
 * decoded from the specified data object.
 *
 * @param data A data object containing Base64-encoded bytes.
 * @return A data object that containing bytes from Base64 decoding.
 */
+ (NSData *)decodeData:(NSData *)data;

/**
 * Creates and returns a data object containing the bytes
 * decoded from the specified bytes.
 *
 * @param bytes A sequence of Base64-encoded bytes.
 * @param length The number of bytes to be decoded.
 * @return A data object that containing bytes from Base64 decoding.
 */
+ (NSData *)decodeBytes:(const void *)bytes length:(NSUInteger)length;

/**
 * Creates and returns a data object containing the bytes
 * decoded from a given string.
 *
 * @param string A Base64-encoded string to be decoded.
 * @return A data object that containing bytes from Base64 decoding.
 */
+ (NSData *)decodeString:(NSString *)string;

@end
