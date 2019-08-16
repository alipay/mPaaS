//
//  MPCryptKit.h
//  MPCryptKit
//
//  Created by shenmo on 12/28/14.
//  Copyright (c) 2014 shenmo. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "APSSKeychain.h"
#import "APBase64.h"
#import "APMD5.h"

#pragma mark NSData+AESCrypt.h

@interface NSData (AESCrypt)

- (NSData *)apAES256EncryptWithKey:(NSString *)key;
- (NSData *)apAES256DecryptWithKey:(NSString *)key;

@end

#pragma mark NSData+Base64.h

@interface NSData (Base64)

+ (NSData *)dataWithBase64EncodedString:(NSString *)string;
- (NSString *)base64EncodedStringWithWrapWidth:(NSUInteger)wrapWidth;
- (NSString *)base64EncodedString;
- (NSString *)dt_base64EncodedString;

@end

@interface NSString (Base64)

+ (NSString *)stringWithBase64EncodedString:(NSString *)string;
- (NSString *)base64EncodedStringWithWrapWidth:(NSUInteger)wrapWidth;
- (NSString *)base64EncodedString;
- (NSString *)base64DecodedString;
- (NSData *)base64DecodedData;

@end

#pragma mark NSData+DTMD5.h

@interface NSData (DTMD5)

- (NSString *)MD5String;

@end

#pragma mark NSString+DTMD5.h

@interface NSString (DTMD5)

- (NSString *)MD5String;

@end

#pragma mark NSString+DTAES.h

@interface NSString (DTAES)

/*!
 @function      stringWithAESEncrypt
 @abstract      AES加密字符串数据
 @param         sKey        密钥字符串
 @param         ivParameter IV参数
 @param         charSetOfSrc 明文字符串的字符编码
 @param         charSetOfKey 密钥字符串的字符编码
 @return        加密结果的Base64字符串
 */
- (NSString *)stringWithAESEncrypt:(NSString *)sKey
                       ivParameter:(NSString *)ivParameter
                      charSetOfSrc:(NSStringEncoding)charSetOfSrc
                      charSetOfKey:(NSStringEncoding)charSetOfKey;


/*!
 @function      stringWithAESDecrypt
 @abstract      AES解密字符串数据
 @param         sKey        密钥字符串
 @param         ivParameter IV参数
 @param         charSetOfSrc 明文字符串的字符编码
 @param         charSetOfKey 密钥字符串的字符编码
 @return        明文字符串
 */
- (NSString *)stringWithAESDecrypt:(NSString *)sKey
                       ivParameter:(NSString *)ivParameter
                      charSetOfSrc:(NSStringEncoding)charSetOfSrc
                      charSetOfKey:(NSStringEncoding)charSetOfKey;

/*!
 @function      stringWithAESEncryptDefault
 @abstract      AES加密字符串数据，，使用缺省的密钥和iv
 @return        加密结果的Base64字符串
 */
- (NSString *)stringWithAESEncryptDefault;

/*!
 @function      dataWithAESEncryptDefault
 @abstract      AES加密字符串数据，，使用缺省的密钥和iv
 @return        NSData加密结果
 */
- (NSData *)dataWithAESEncryptDefault;

/*!
 @function      stringWithAESEncryptDefault
 @abstract      AES解密字符串数据，使用缺省的密钥和iv
 @return        明文字符串
 */
- (NSString *)stringWithAESDecryptDefault;

@end
