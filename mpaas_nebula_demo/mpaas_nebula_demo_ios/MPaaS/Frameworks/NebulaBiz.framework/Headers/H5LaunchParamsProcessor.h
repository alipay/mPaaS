//
//  H5LaunchParamsProcessor.h
//  H5Service
//
//  Created by chenwenhong on 14-11-13.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface H5LaunchParamsProcessor : NSObject

/**
 部分参数根据权限做修正，
 检查 allowsBounceVertical明确传入NO，不能露出domain块
      pullRefresh传入YES，盖住domain
      showDomain明确传入NO，隐藏domain
      等三种情况，没有默认值
     
     showOptionMenu 未传时处理默认值

 @param mutableParams 原始参数 & 修正参数
 @param appId 当前appId，作为权限检查依据。如mutableParams已传入appId，以mutableParams中的appId为准
 @param urlStr 当前url
 */
+ (void)checkAndProcessLaunchParams:(NSMutableDictionary *)mutableParams
                              appId:(NSString *)appId
                          urlString:(NSString *)urlStr;

// 只处理跟domain相关的三个参数，没有默认值
+ (void)checkAndProcessDomainInvolved:(NSMutableDictionary *)mutableParams
                                appId:(NSString *)appId
                            urlString:(NSString *)urlStr;

/**
 当APP启动的时候需要使用该方法，以合并应用配置中的启动参数

 @param launchOptions 原始入参
 @param appId 应用ID
 @param sourceId 上个应用ID或外部跳入
 @return 合并应用中心的启动参数
 */
+ (NSDictionary *)getFinallaunchOptions:(NSDictionary *)launchOptions
                            appId:(NSString *)appId
                         sourceId:(NSString *)sourceId;

@end
