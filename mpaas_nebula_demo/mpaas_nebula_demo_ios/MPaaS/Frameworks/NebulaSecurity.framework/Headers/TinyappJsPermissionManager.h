//
//  H5AppJsPermissionManager.h
//  NebulaBiz
//
//  Created by theone on 16/12/12.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TinyappJsPermissionManager : NSObject
- (instancetype)initWithConfig:(NSDictionary *)config;
- (instancetype)initWithConfig:(NSDictionary *)config appId:(NSString *)appId;
- (instancetype)initWithConfig:(NSDictionary *)config appId:(NSString *)appId session:(PSDSession *)session;
- (BOOL)hasPermissionWithjsapiName:(NSString *)jsapiName
                              data:(NSDictionary *)data
                               url:(NSString *)url;
- (BOOL)hasPermissionWithEventName:(NSString *)eventName
                              data:(NSDictionary *)data
                               url:(NSString *)url;
- (BOOL)hasPermissionWithUrl:(NSString *)url;
- (BOOL)hasPermissionWithUrl:(NSString *)url appId:(NSString *)appId;
- (BOOL)hasPermissionWithWebviewUrl:(NSString *)urlStr;
- (BOOL)haspermissionWithWebviewWithJsapi:(NSString *)jsapiName appId:(NSString *)appId;
- (BOOL)hasPermissionWithResponse:(NSHTTPURLResponse *)response;

/**
 是否HttpRequest请求需要走SPDY，不要改动此方法名，外部会动态调用
 
 @return 是否需要判断
 */
- (BOOL)shouldGoWithSPDY;

/**
 是否需要做权限判断，不要改动此方法名，外部会动态调用

 @return 是否需要判断
 */
- (BOOL)shouldDoPermissonJudge;

/**
 通过扩展名称来判断是否需要走SPDY，不要改动此方法名，外部会动态调用

 @return 是否可以走
 */
- (BOOL)shouldGOSPDYWithRequestExtention:(NSString *)extention;

/**
 网络请求是否强制https/wss
 */
- (BOOL)shouldForceSSL;

/**
 获取组件权限配置

 @return 组件权限配置
 */
- (NSDictionary*)componentPermissionConfig;
@end
