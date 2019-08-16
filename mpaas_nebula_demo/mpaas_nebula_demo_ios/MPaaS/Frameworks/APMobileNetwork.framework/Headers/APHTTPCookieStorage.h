//
//  APHTTPCookieStorage.h
//  APMobileNetwork
//
//  Created by WenBi on 13-9-13.
//  Copyright (c) 2013年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@class APHTTPCookie;

@interface APHTTPCookieStorage : NSObject
/**
 *  获得单例
 */
+ (APHTTPCookieStorage *)sharedHTTPCookieStorage;
/**
 *  删除cookie
 *
 *  @param aCookie 要删除的cookie
 */
- (void)deleteCookie:(APHTTPCookie *)aCookie;
/**
 *  删除所有cookie
 */
- (void)deleteAllCookies;
/**
 *  添加cookie
 *
 *  @param aCookie 要添加的cookie
 */
- (void)setCookie:(APHTTPCookie *)aCookie;
/**
 *  添加多个cookie
 *
 *  @param cookies 要添加的数组类型的cookie
 */
- (void)setCookies:(NSArray *)cookies forURL:(NSURL *)theURL mainDocumentURL:(NSURL *)mainDocumentURL;
/**
 *  获取所有cookie
 */
- (NSArray *)cookies;
/**
 *  根据url所有cookie
 */
- (NSArray *)cookiesForURL:(NSURL *)aURL;
/**
 *  加锁
 */
- (void)lock;
/**
 *  解锁
 */
- (void)unlock;

//added by shaobin 2014.10.21
- (NSMutableString *)httpCookieHeaderStrForUrl:(NSURL *)url operationType:(NSString*)operationType;
/**
 *  根据operationType添加cookies
 *
 *  @param cookies       要添加的cookie
 *  @param operationType
 */
- (void)setCookies:(NSArray*)cookies forOperationType:(NSString*)operationType;

//删除重用cookie,仅供登录模块使用
+(void)removeReuseCookie;
@end
