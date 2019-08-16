//
//  NBLogConfigServiceDelegate.h
//  NebulaLogging
//
//  Created by Glance on 2017/8/5.
//  Copyright © 2017年 Alipay. All rights reserved.
//

@protocol NBLogConfigServiceDelegate
@optional
@property(nonatomic, readonly) BOOL useAsyncLogThread; // 是否使用异步线程执行埋点事件分发和埋落操作 default NO
@property(nonatomic, readonly) BOOL isCurrentWifi;     // 接入方实现是否wifi的判断 default NO
@property(nonatomic, readonly) BOOL logNebulaTechEnable; // 历史原因导致webapp类型日志量过大，需切出至NebulaTech default YES
@property(nonatomic, readonly) NSArray *logWebAppWhitelist; // webapp切至NebulaTech时，需保留的埋点名 default 正则数组@[@"H5_PAGE_PERFORMANCE|H5_AL_SESSION_FROM_NATIVE|H5_AL_SESSION_MAP_SUCCESS|H5_AL_SESSION_FALLBACK|H5_GETLOCATION_RESULT"];
@property(nonatomic, readonly) int reportAbnormalResourceSize; //网络资源toobig异常的阈值 default 1024(kB)
@property(nonatomic, readonly) int reportAbnormalResourceSizeWarn; //网络资源toobig异常的阈值 default 300(kB)
@property(nonatomic, readonly) int reportAbnormalPageRenderLimitSec; //页面longRender的非wifi渲染延迟的阈值 default 60s
@property(nonatomic, readonly) int reportAbnormalPageRenderWifiLimitSec; //页面longRender的wifi渲染延迟的阈值 default 20s
@property(nonatomic, readonly) NSArray *jsapiResultErrorLogBlackList; // 某些JsApi可能带有敏感信息，支持白名单参数过滤 default nil
@property(nonatomic, readonly) NSDictionary *logNewBlankScreenConfig; // 新的白屏埋点的开关及阈值控制 default @{@"enable":@"NO",@"wifiLimit":@10,@"elseNetWork":@30,@"testFilter":@6}
//@property(nonatomic, readonly) BOOL  shouldEnableHAR; // 已下线。是否开启HAR采集，前提是serviceOptions中有开启
@property(nonatomic, readonly) NSString *jsUrl4SPMLog; // 用于spm埋点的jsSDK资源链接，前提是shouldInjectSPMJS开启
@property(nonatomic, readonly) float stopLoadingWaitingTime; // 异步渲染页面的等待时间 default 1s
@property(nonatomic, readonly) NSArray *performceApiLogBlackList; // 单条性能日志中，逐一记录JSAPI信息会导致日志过长，对于黑名单中的jsapi，记录到扩展字段4中的filterJsapiLogs中
@property(nonatomic, readonly) BOOL shouldCollectUnfinishedUrl; // 页面离开时记录未加载完成的url　10.1.32
@property(nonatomic, readonly) NSString *logGroup; // 记录当前用户所在的灰度分桶　10.1.35

@end
