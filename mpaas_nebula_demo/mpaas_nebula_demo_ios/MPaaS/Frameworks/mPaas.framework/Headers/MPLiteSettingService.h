//
//  MPLiteSettingService.h
//  mPaas
//
//  Created by shenmo on 6/3/16.
//  Copyright © 2016 Alibaba. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MPLiteSettingService : NSObject

/**
 *  获取应用的rpc业务网关地址，与meta.config文件中 rpcGW 字段一致
 */
+ (NSString*)getRPCGateway;

/**
 *  获取应用的日志网关地址，与meta.config文件中 logGW 字段一致
 */
+ (NSString*)getRemoteLogGateway;

/**
 *  获取应用的sync网关地址，与meta.config文件中 syncserver 字段一致
 */
+ (NSString*)getSyncGateway;

/**
 *  获取应用的sync网关地址端口号，与meta.config文件中 syncport 字段一致
 */
+ (NSString*)getSyncPort;

/**
 *  获取应用的组件网关地址，与meta.config文件中 mpaasapi 字段一致
 */
+ (NSString*)getMpaasGateway;

/**
 *  获取应用的appId，与meta.config文件中 appId 字段一致
 */
+ (NSString*)getAppId;

/**
 *  获取应用的workspaceId，与meta.config文件中 workspaceId 字段一致
 */
+ (NSString*)getWorkspaceId;

/**
 *  获取应用的appKey，由appId 与平台拼接组成，如 320C94C171133_IOS
 */
+ (NSString*)getAppkey;

/**
 *  获取应用的productId，由appId 、平台、workspaceId拼接组成，如 320C94C171133_IOS-test
 */
+ (NSString *)getProductId;

/**
 *  获取平台类型，默认为iOS
 */
+ (NSString *)getPlatform;
@end
