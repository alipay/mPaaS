//
//  NSString+DTRegularExpressionValidator.h
//  MobileFoundation
//
//  Created by 朱建 on 13-4-15.
//  Copyright (c) 2013年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

/*!
 @abstract  对NSString增加对常用正则表达式验证的Categary
 */
@interface NSString (DTRegularExpressionValidator)

/*!
 @abstract  验证正则表达式是否满足
 @param     pattern
 正则表达式
 @return    是否满足
 */
- (BOOL)validateRegularExpression:(NSString *)pattern;

/*!
 @abstract      是否是有效的手机号码
 @return        是否是有效的手机号码
 */
- (BOOL)isValidMobilePhoneNumber;

/*!
 @abstract      是否是有效的固话号码
 @discussion    需要区号前缀，如 0571-12345678 或 057112345678 或 021-12345678 或 02112345678
 @return        是否是有效的固话号码
 */
- (BOOL)isValidTelephoneNumber;

/*!
 @abstract  是否是有效的邮箱地址
 @return    是否是有效的邮箱地址
 */
- (BOOL)isValidEmail;

/*!
 @abstract  是否是有效的邮政编码
 @return    是否是有效的邮政编码
 */
- (BOOL)isValidZipCode;

/*!
 @abstract      是否是有效的身份证号码
 @discussion    仅判断位数，未判断生日和末位校验
 @return        是否是有效的身份证号码
 */
- (BOOL)isValidIDCardNumber;

/*!
 @abstract      是否是有效的正整数
 @discussion    不能有+号前缀
 @return        是否是有效的正整数
 */
- (BOOL)isValidPositiveInteger;

/*!
 @abstract  是否是有效的负整数
 @return    是否是有效的负整数
 */
- (BOOL)isValidNegativeInteger;

/*!
 @abstract      是否是有效的金额
 @discussion    不能有+-号前缀，最多两位小数
 @return        是否是有效的金额
 */
- (BOOL)isValidAmount;

/*!
 @abstract      是否全部是数字字符
 @return        是否全部是数字字符
 */
- (BOOL)isAllDigitNumber;

@end
