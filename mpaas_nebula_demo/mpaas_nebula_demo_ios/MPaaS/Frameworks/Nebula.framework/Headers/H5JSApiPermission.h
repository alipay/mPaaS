//
//  H5JSApiPermission.h
//  NebulaBiz
//
//  Created by 八爪 on 16/5/30.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString * const kJSAPI_META_INFORMATION;   //当前JSAPI元信息
extern NSString * const kJSAPI_META_SECURITYLEVEL; //当前JSAPI安全级别
extern NSString * const kJSAPI_META_USEWHITELIST;  //当前JSAPI是否忽略安全级别，直接使用白名单
extern NSString * const kJSAPI_META_JSAPINAME;     //当前JSAPI调用名

@interface H5JSApiPermission : NSObject

+ (instancetype)sharedInstance;
- (BOOL)checkJsApiPermissionByName:(NSString *)jsapiName appId:(NSString *)appId appKey:(NSString *)appKey currentUrl:(NSString *)currentUrl;
- (BOOL)checkUrl:(NSURL *)url matchSecurityLevel:(NSString *)securityLevel;
- (BOOL)checkSpecialPermissionWithJsapiName:(NSString *)jsApiName
                                       data:(NSDictionary *)data
                                        url:(NSString *)url;
- (void)checkJsApiPermissionByName:(NSString *)jsapiName appId:(__unused NSString *)appId appKey:(__unused NSString *)appKey currentUrl:(NSString *)currentUrl complete:(void (^)(BOOL hasPermision, NSString *securityLevel, BOOL useWhiteList))completeBlock;


/**
 确定一个jspai是否是level_none的权限等级

 @param jsapiName jsapi名称
 @return 是否是level_none的权限，这种需要直接放过的
 */
- (BOOL)isJsApiNameNotLevelNone:(NSString *)jsapiName;

@end
