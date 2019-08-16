//
//  NBLogConfiguration.h
//  NebulaLogging
//
//  Created by Glance on 16/11/8.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_OPTIONS(NSUInteger, NBLogServiceOption) {
    NBLogServiceNone        = 0,      // 关闭所有埋点类型
    NBLogServicePerformance = 1 << 0, // 页面性能和页面异常 默认启动
    NBLogServiceRemoteLog   = 1 << 1, // 提供remoteLog jsapi供前端调用 默认启动
    NBLogServiceManualSPM   = 1 << 2, // 手动SPM  pageMonitor/clicked支持 默认启动
    NBLogServiceAutoSPM     = 1 << 3, // 自动SPM auto_openPage/auto_click支持 默认启动
    //NBLogServiceHAR         = 1 << 4, // 已下线。采集HAR页面数据，接入方调用-[PSDPage triggerRecord] 写入本地沙盒tempg下nebula目录，目前在试用中 默认关闭
    NBLogServiceNetWorkStart = 1 << 5, // 采集页面发起，数量较大，谨慎使用。或者监听monitor.log.before事件筛选指定url 默认关闭
    NBLogServicemtBizLog    = 1 << 7,  // 提供mtBizReport jsapi供前端调用 默认启动
    NBLogServiceOtherLog    = 1 << 6,  // 自动产出应用打开，JS异常，资源异常，API异常等自动埋点 默认启动
    NBLogServiceAll         = 0xffffff, // 开启所有埋点类型
};

@interface NBLogConfiguration : NSObject

@property (nonatomic, assign)   BOOL enableConsoleLog; // 控制台输出日志
@property (nonatomic, readonly) NSString *sdkVersion; // SDK版本号
@property (nonatomic, assign)   NBLogServiceOption serviceOption; // 开启的服务项 default NBLogServicePerformance | NBLogServiceRemoteLog | NBLogServiceManualSPM | NBLogServiceAutoSPM | NBLogServiceOtherLog | NBLogServicemtBizLog
@property (nonatomic, assign)   BOOL shouldInjectPerformaceJS; // 开启后，自动注入性能统计使用的JS文件，h5_performance.js default YES
@property (nonatomic, assign)   BOOL shouldInjectReportClickJS; // 开启后，自动注入点击统计使用的JS文件，h5_reportClick.js default YES
@property (nonatomic, assign)   BOOL shouldInjectSPMJS; // 开启后，自动注入性能统计使用的JS文件，h5_performance.js default YES
@property (nonatomic, weak)     id<NBLogConfigServiceDelegate> configServiceDelegate; // 部分埋点阈值的动态支持 default references NBLogConfigServiceDelegate.h

@property (nonatomic, copy)     NSArray<NSString *> *loadResourceApis; // 网络访问相关的JSAPI列表，default ["rpc","openRpc", "httpRequest"], 用于统计异步页面的加载完成时间，对应性能字段中的stoploading指标

@property (nonatomic, assign)   BOOL enableNewJsApiLog; // 钱包10.1.50 大于xxms的jsapi调用记录时间开销
@property (nonatomic, assign)   double jsApilogTimelimit; // 钱包10.1.50 大于xxms的jsapi调用记录时间开销
@property (nonatomic, copy)     NSArray<NSString *> *jsApilogExitWhitelist; //钱包10.1.50 没有callback实现的白名单

// ============================ 自动 容器 埋点 ================== //
@property (nonatomic, strong)   Class logConfigClass; // NBAutoLogger接口的配置类 default null。在接口调用时有传入kH5SeedId对应的值时，非必需设置该属性。使用场景：1.只使用埋点序号做埋点管理时，提供管理类，以供查询埋点序号对应的字符串埋点名。2.埋点事件派发时，事件中含有该埋点序号，可用于开关控制。类编码要求：1.序号使用时请注意不与NBAutoLogConfigs.h中重复 2.实现+ (NSDictionary*)readPreConfigByLid:(NSInteger)lid 方法, 在方法中返回埋点配置，例如
/*
 
 @implementation H5AutoLogConfigs
 NSDictionary * H5AutoLogDefaultConfigs()
 {
 return @{
 @"21001":@{@"seedId": @"H5_AL_INTERCEPT_SCHEME", @"output": @"mdap"},
 };
 }
 static NSDictionary *logConfigList = nil; // 本地预置上传配置
 + (NSDictionary*)readPreConfigByLid:(NSInteger)lid {
 static dispatch_once_t onceToken;
 dispatch_once(&onceToken, ^{
 logConfigList = H5AutoLogDefaultConfigs();
 });
 return [logConfigList objectForKey:[[NSString alloc] initWithFormat:@"%ld",(long)lid]];
 }
 @end
 */

@property (nonatomic, assign) BOOL enableCancelEventLog;

// ============================ 自动 SPM 埋点 ================== //
@property (nonatomic, assign)    BOOL shouldFilterPVWhenSubView; // 开启后，自动spm不计入嵌入页面的pageMonitor   default YES prerequisite: PSDContext.currentViewController实现isSubViewMode方法
@property (nonatomic, strong)    id<NBLogTrackAgentProtocol> trackAgent; //  pageMonitor代理 default NBDefaultLogTrackAgent
@property (nonatomic, strong)    id<NBLogClickAgentProtocol> clickAgent; // autoClick代理 default NBLogClickAgent
@property (nonatomic, strong)    id<NBLogExtraParamProtocol> paramAgent; // 业务数据代理 default nil

//　容器单条日志长度治理
@property(nonatomic, assign)     NSUInteger maxUrlLogLength;
@property(nonatomic, assign)     BOOL enableCleanUrl;

@end

#ifdef __cplusplus
extern "C" {
#endif
    
    NBLogConfiguration * NBLogConfigurationGet();
    void NBLogConsole(NSString *format, ...);

#ifdef __cplusplus
}
#endif




#pragma mark - Unavalilable

@interface NBLogConfiguration (UNAVAILABLE)

/**
 *  不可分配内存空间
 */
+ (instancetype)new UNAVAILABLE_ATTRIBUTE;

/**
 *  不可初始化
 */
- (instancetype)init UNAVAILABLE_ATTRIBUTE;

/**
 *  不可重写
 */
- (id)copy UNAVAILABLE_ATTRIBUTE;

@end





