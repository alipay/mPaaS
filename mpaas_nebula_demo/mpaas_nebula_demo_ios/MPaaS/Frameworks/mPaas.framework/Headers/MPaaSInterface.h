//
//  MPaaSInterface.h
//  mPaas
//
//  Created by shenmo on 6/3/16.
//  Copyright © 2016 Alibaba. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MPaaSInterface : NSObject

+ (instancetype)sharedInstance;

#pragma mark - 配置方法，通过Category覆盖以下方法实现应用的自定义配置

/**
 *  是否允许使用MPaaS默认带的设置服务，这个设置服务比较轻量，只支持设置RPC、日志的网关地址与应用ID。
 *  如果使用设置服务，需要将配置写在GatewayConfig.plist文件中。
 *  默认返回NO。
 *
 *  <!!!> 对RPC与日志模块来说，如果接入应用覆盖了DTRpcInterface与APLogAdditions的相关方法，那么SettingService的设置会失效。
 *
 *  接入方可以自己定义Settings.bundle来修改配置，不过选择的环境名称写入到NSUserDefaults后key必须为“kMPSelectedEnvironment”。
 *  如果使用了设置服务，初始化时读取不到kMPSelectedEnvironment的值，会默认去GatewayConfig.plist文件中读取key为“Release”的配置字典。
 *  默认的GatewayConfig.plist结构为：
 *  Root
 *   |- Debug                           (子项与Release相同)
 *   |- Sit                     (子项与Release相同)
 *   |- Release
 *        |- MPaaSLogGateway            日志服务器地址（类似“http://10.218.157.65”）
 *        |- MPaaSLogProductId          日志应用Id，通常为带平台的APPKEY加workspaceId（类似“APPKEY_IOS-0000017768”），对内部应用类似为“IPHONE_1ND”这种。
 *        |- MPaaSRpcGateway            RPC网关地址（类似“http://42.120.224.143/mgw.htm”），开发阶段可以使用http，线上应该使用https。
 *        |- MPaaSRpcProductId          RPC应用Id，对内部应用来说一般同mPaasLogProductId。
 */
- (BOOL)enableSettingService;

/**
 *  升级组件、Hotpatch等拉取Rpc，或埋点日志上报时的userId。接入应用有自己的账户系统，需要实现这个方法，返回相应的userId值。如果是未登录态，可以返回nil。
 *  默认返回 nil
 *  @return 当前的userId
 */
- (NSString*)userId;

/**
 *  当前应用的schema，类似"alipay:"等。接入应用有自己的schema，需要实现这个方法，返回相应的schema值
 *  默认返回 nil
 *  @return 当前应用的schema
 */
- (NSString *)appSchema;


/**
 *  是否启用 Thread Task Monitor
 *  如果启用则会记录 Thread 调用信息
 *  默认返回NO。
 */
- (BOOL)enableThreadTaskMonitor;

@end
