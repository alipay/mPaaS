//
//  APHTTPCookie.h
//  APMobileNetwork
//
//  Created by WenBi on 13-9-13.
//  Copyright (c) 2013年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface APHTTPCookie : NSObject
/**
 *  从headerFields中获得cookies
 *
 *  @param headerFields
 *  @param aURL
 *
 *  @return cookies
 */
+ (NSArray *)cookiesWithResponseHeaderFields:(NSDictionary *)headerFields forURL:(NSURL *)aURL;
/**
 *  根据properties获取实例
 *
 *  @param properties 属性字典
 *
 *  @return 实例
 */
- (id)initWithProperties:(NSDictionary *)properties;
/**
 *  从属性中获取Domain
 *
 *  @return Domain
 */
- (NSString *)domain;
/**
 *  从属性中获取过期时间
 *
 *  @return date
 */
- (NSDate *)expiresDate;
/**
 *  从属性中获取name
 *
 *  @return name
 */
- (NSString *)name;
/**
 *  从属性中获取path
 *
 *  @return path
 */
- (NSString *)path;
/**
 *  获得属性数组
 *
 *  @return 属性数组
 */
- (NSDictionary *)properties;
/**
 *  从属性中获取name、value
 *
 *  @return name=value字符串
 */
- (NSString *)requestHeaderField;

@end
