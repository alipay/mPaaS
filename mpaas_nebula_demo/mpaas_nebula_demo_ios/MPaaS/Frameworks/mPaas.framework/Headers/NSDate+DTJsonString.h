//
//  NSDate+DTJsonString.h
//  MobileFoundation
//
//  Created by WenBi on 13-4-12.
//  Copyright (c) 2013年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * \code NSDate 类的扩展，用于在 JSON 对象序列化中将 \code NSDate 生成相应的字符串，
 * 或者反序列化中将 JSON 串中的 long 型（64位）表示的毫秒数转换为 \code NSDate 对象。
 */
@interface NSDate (DTJsonString)

/**
 * 根据指定的字符串，创建相应的 \code NSDate 对象。
 *
 * @param string 字符串形式的64位整数，这个整数表示从1970年开始至指定的日期经过了多少毫秒。
 *
 * @return 如果转换成功，返回 \code NSDate 对象，否则返回 nil。
 */
+ (NSDate *)dateFromJSONString:(NSString *)string;

/**
 * 把一个由 \code NSDate 表示的日期和时间，转换为64位整数的毫秒数。
 *
 * @return 一个数符串，该字符串中是一个64位的整型数值。
 */
- (NSString *)toJSONString;

@end
