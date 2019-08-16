//
//  NSURL+URLWithFixedString.h
//  MobileFoundation
//
//  Created by 定风波 on 7/17/15.
//  Copyright (c) 2015 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSURL (URLWithFixedString)

/**
 *  对URLWithString这个方法做了一些扩展，去除多余的#，编码非法的%，编码不可接受字符 （http://www.ietf.org/rfc/rfc3986.txt）
 */
+ (instancetype)URLWithFixedString:(NSString *)URLString;

@end
