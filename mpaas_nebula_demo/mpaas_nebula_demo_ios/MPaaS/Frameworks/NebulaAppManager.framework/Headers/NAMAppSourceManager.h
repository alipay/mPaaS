//
//  NAMAppSourceManager.h
//  NebulaAppManager
//
//  Created by runfeng.crf on 2018/10/17.
//  Copyright © 2018 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, NAMAppInfoSource) {
    NAMAppInfoSourceUnknown = 0,          //
    NAMAppInfoSourceSync,                 //sync
    NAMAppInfoSourceEnterAppAsync,        //进入应用，异步
    NAMAppInfoSourceEnterAppSyncTry,      //进入应用，尝试同步
    NAMAppInfoSourceEnterAppSyncForce,    //进入应用，强制同步
    NAMAppInfoSourceLogin,                //账密登录、切换账号、覆盖安装
    NAMAppInfoSourceStableRpc,            //智能分数强大rpc策略
    NAMAppInfoSourceRpcAsync,             //全网rpc异步更新
    NAMAppInfoSourceRpcSync               //全网rpc同步更新（止血）
};

typedef NS_ENUM(NSUInteger, NAMAppPackageSource) {
    NAMAppPackageSourceUnknown = 0,
    NAMAppPackageSourceSync,              //sync
    NAMAppPackageSourceEnterAppAsync,     //进入应用，异步
    NAMAppPackageSourceEnterAppSyncTry,   //进入应用，同步
    NAMAppPackageSourceEnterAppSyncForce, //进入应用，同步
    NAMAppPackageSourceLogin,             //账密登录、切换账号、覆盖安装
    NAMAppPackageSourceAutoLogin,         //免登
    NAMAppPackageSourceWifiPreDown,       //智能分数wifi预下载策略
    NAMAppPackageSourceRpcSync,           //全网rpc同步更新（止血）
};

@interface NAMAppSourceManager : NSObject

- (void)setAppInfoSource:(NSString *)appId version:(NSString *)version source:(NAMAppInfoSource)source;
- (void)setAppsInfoSource:(NSDictionary *)apps source:(NAMAppInfoSource)source;
- (void)setAppPackageSource:(NSString *)appId version:(NSString *)version source:(NAMAppPackageSource)source;
- (void)setAppsPackageSource:(NSDictionary *)apps source:(NAMAppPackageSource)source;

- (NAMAppInfoSource)appInfoSource:(NSString *)appId version:(NSString *)version;
- (NAMAppPackageSource)appPackageSource:(NSString *)appId version:(NSString *)version;

@end


