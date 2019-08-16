//
//  SPMTrackerLog.h
//  SPMTracker
//
//  Created by BoTao on 2017/2/3.
//  Copyright © 2017年 Alipay. All rights reserved.
//
#import <Foundation/Foundation.h>

#ifndef SPMTrackerLog_h
#define SPMTrackerLog_h

#define kSPMActionOpenPage @"openPage"
#define kSPMActionClicked @"clicked"
#define kSPMActionSlided @"slided"
#define kSPMActionExposure @"exposure"

#define kSPMMonitorChInfoKey @"chInfo"
#define kSPMPageIDKey @"pagets"
#define kSPMPageBackKey @"pageBack"

NS_ASSUME_NONNULL_BEGIN

__deprecated_msg("请使用SPMTracker.framework中的SPMTrackerLog")
@interface SPMTrackerLog : NSObject

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// 行为埋点
/**
 *  点击-行为埋点使用
 *
 *  @param spmId SPM埋点ID
 *  @param entityId 对应scmId、rpcId
 *  @param bizCode 业务bizType，埋点平台申请
 *  @param param4 扩展参数，业务自己根据需要填充。字典会被转换成key-value的字符串计入日志
 *  @param view 埋点对应view，传vc对象最好，其次view对象，不能为空
 *  @param loggerLevel 日志等级(LoggerLevelLow/LoggerLevelMedium/LoggerLevelHigh)，默认为LoggerLevelMedium
 */
+ (void)clickedLogWithSpmId:(NSString *)spmId entityId:(NSString *)entityId bizCode:(NSString *)bizCode extParams4:(nullable NSDictionary *)param4 view:(NSObject *)view logLevel:(NSString *)logLevel ;

// 可以明确传递pageId时调用次方法，否则调用楼上的方法
+ (void)clickedLogWithSpmId:(NSString *)spmId entityId:(NSString *)entityId bizCode:(NSString *)bizCode extParams4:(nullable NSDictionary *)param4 pageId:(NSString *)pageId logLevel:(NSString *)logLevel ;

+ (void)clickedLogWithSpmId:(NSString *)spmId bizCode:(NSString *)bizCode extParams4:(nullable NSDictionary *)param4 view:(NSObject *)view logLevel:(NSString *)logLevel ;

+ (void)clickedLogWithSpmId:(NSString *)spmId bizCode:(NSString *)bizCode extParams4:(nullable NSDictionary *)param4 view:(NSObject *)view ;

/**
 *  翻页-行为埋点使用
 *
 *  @param spmId SPM埋点ID
 *  @param entityId 对应scmId、rpcId
 *  @param bizCode 业务bizType，埋点平台申请
 *  @param param4 扩展参数，业务自己根据需要填充。字典会被转换成key-value的字符串计入日志
 *  @param view 埋点对应view，传vc对象最好，其次view对象，不能为空
 *  @param loggerLevel 日志等级(LoggerLevelLow/LoggerLevelMedium/LoggerLevelHigh)，默认为LoggerLevelMedium
 */
+ (void)slideLogWithSpmId:(NSString *)spmId entityId:(NSString *)entityId bizCode:(NSString *)bizCode extParams4:(nullable NSDictionary *)param4 view:(NSObject *)view logLevel:(NSString *)logLevel ;

+ (void)slideLogWithSpmId:(NSString *)spmId bizCode:(NSString *)bizCode extParams4:(nullable NSDictionary *)param4 view:(NSObject *)view logLevel:(NSString *)logLevel ;

+ (void)slideLogWithSpmId:(NSString *)spmId bizCode:(NSString *)bizCode extParams4:(nullable NSDictionary *)param4 view:(NSObject *)view ;

/**
 *  曝光-行为埋点使用
 *
 *  @param spmId SPM埋点ID
 *  @param entityId 对应scmId、rpcId
 *  @param bizCode 业务bizType，埋点平台申请
 *  @param param4 扩展参数，业务自己根据需要填充。字典会被转换成key-value的字符串计入日志
 *  @param view 埋点对应view，传vc对象最好，其次view对象，不能为空
 *  @param loggerLevel 日志等级(LoggerLevelLow/LoggerLevelMedium/LoggerLevelHigh)，默认为LoggerLevelMedium
 */
+ (void)exposureLogWithSpmId:(NSString *)spmId entityId:(NSString *)entityId bizCode:(NSString *)bizCode extParams4:(nullable NSDictionary *)param4 view:(NSObject *)view logLevel:(NSString *)logLevel ;

// 可以明确传递pageId时调用次方法，否则调用楼上的方法
+ (void)exposureLogWithSpmId:(NSString *)spmId entityId:(NSString *)entityId bizCode:(NSString *)bizCode extParams4:(nullable NSDictionary *)param4 pageId:(NSString *)pageId logLevel:(NSString *)logLevel ;

+ (void)exposureLogWithSpmId:(NSString *)spmId bizCode:(NSString *)bizCode extParams4:(nullable NSDictionary *)param4 view:(NSObject *)view logLevel:(NSString *)logLevel ;

+ (void)exposureLogWithSpmId:(NSString *)spmId bizCode:(NSString *)bizCode extParams4:(nullable NSDictionary *)param4 view:(NSObject *)view ;

/*
 *  合并曝光
 *  推荐使用，解决列表元素曝光需求，每个元素不会重复曝光，储存曝光日志，达到上报条件时，多条曝光日志合并后上报埋点
 *  合并曝光文档：https://lark.alipay.com/data/help/willav
 *
 *  @param spmId: 埋点SPMID，不可为空
 *  @param entityId 对应scmId、rpcId
 *  @param bizCode 业务bizType，埋点平台申请
 *  @param rid: RPC唯一标示，可以时tracerid、recommondid等
 *  @param pos: cell索引号，类似SPMID的N
 *  @param extParams: 扩展参数，业务自己根据需要填充。字典会被转换成key-value的字符串计入日志
 *  @param view: 埋点对应view，传vc对象最好，其次view对象，不能为空
 *  @param loggerLevel 日志等级(LoggerLevelLow/LoggerLevelMedium/LoggerLevelHigh)，默认为LoggerLevelMedium
 */
+ (void)mergerExposureLogWithSpmId:(NSString *)spmId entityId:(NSString *)entityId rid:(NSString *)rid position:(NSString *)pos bizCode:(NSString *)bizCode extParams:(NSDictionary *)extParams view:(NSObject *)view logLevel:(NSString *)logLevel;

// 可以明确传递pageId时调用次方法，否则调用楼上的方法
+ (void)mergerExposureLogWithSpmId:(NSString *)spmId entityId:(NSString *)entityId rid:(NSString *)rid position:(NSString *)pos bizCode:(NSString *)bizCode extParams:(NSDictionary *)extParams pageId:(NSString *)pageId logLevel:(NSString *)logLevel;

+ (void)mergerExposureLogWithSpmId:(NSString *)spmId rid:(NSString *)rid position:(NSString *)pos bizCode:(NSString *)bizCode extParams:(NSDictionary *)extParams view:(NSObject *)view logLevel:(NSString *)logLevel;

+ (void)mergerExposureLogWithSpmId:(NSString *)spmId rid:(NSString *)rid position:(NSString *)pos bizCode:(NSString *)bizCode extParams:(NSDictionary *)extParams view:(NSObject *)view;

/*
 *  上报合并曝光日志，上报成功后会清除已上报日志
 *  pageMonitor的onViewWillDisappear中会调用，如果业务需要手工触发上报合并曝光日志，调用此方法
 *
 *  @param spmId: 埋点SPMID，所有向后匹配的spmid都上报，例如a13.b42，则a13.b42.c11、a13.b42.c51.d222等合并曝光日志都上报并清除记录
 *  @param view: 埋点对应view，传vc对象最好，其次view对象，不能为空
 */
+ (void)commiteMergerExposureLogWithSpmId:(NSString *)spmId view:(NSObject *)view;

/**
 *  @param actionId  action ID 必填，标识一个埋点的类别，可用actionID定义在APMonitorPointDataDefines.h
 文件中
 *  @param extParams 扩展参数，业务自己根据需要填充。数组元素最多4个，第四个元素可以是字典，字典内容可自定义，字典会被转换成key-value的字符串计入日志
 *  @param spmId      埋点ID（后端定义的，找@望乡生成）
 *  @param entityId 对应scmId、rpcId
 *  @param bizCode 业务bizType，埋点平台申请
 *  @param view 埋点对应view，传vc对象最好，其次view对象，不能为空
 *  @param loggerLevel 日志等级(LoggerLevelLow/LoggerLevelMedium/LoggerLevelHigh)，默认为LoggerLevelMedium
 */
+ (void)writeLogWithActionId:(NSString *)actionId extParams:(NSArray *)extParams spmId:(NSString *)spmId entityId:(NSString *)entityId bizCode:(NSString *)bizCode view:(NSObject *)view logLevel:(NSString *)logLevel;

+ (void)writeLogWithActionId:(NSString *)actionId extParams:(NSArray *)extParams spmId:(NSString *)spmId bizCode:(NSString *)bizCode view:(nonnull NSObject *)view logLevel:(NSString *)logLevel;





///////////////////////////////////////////////////////////////////////////////////////////////////////////
// pageMonitor
/**
 *  pageMonitor，记录chinfo信息，一般在scheme跳转的方法中最后调用该方法，logPageEndWithSpmId时使用chinfo信息，用完删除对应记录
 *
 *  @param options scheme参数
 *  @param viewController当前vc，作为记录信息的key
 *
 *  @return 参数包含chinfo时，返回YES，否则NO
 */
+ (BOOL)spliteSchemaOptions:(NSDictionary *)options viewController:(NSObject *)viewController;

/**
 *  pageMonitor，更新chinfo信息
 *
 *  @param info chInfo值
 *  @param viewController当前vc，作为记录信息的key
 *
 */
+ (void)updateChInfo:(NSString *)info viewController:(NSObject *)viewController;

/**
 *  pageMonitor，根据vc获取chInfo
 */
+ (NSString *)chInfoForViewController:(NSObject *)vc;

/**
 *  pageMonitor，页面打开
 *
 *  @param spmId 代表当前页面的spm
 *  @param view 埋点对应view，传vc对象最好，其次view对象，不能为空
 *
 */
+ (void)onViewDidAppear:(NSString *)spmId view:(nonnull NSObject *)view;

/**
 *  pageMonitor，页面结束
 *  @param spmId 代表当前页面的spm
 *  @param view 埋点对应view，传vc对象最好，其次view对象，不能为空
 *  @param bizCode 业务bizCode
 *  @param param 手动埋点扩展参数4，底层保留key不要使用：chInfo
 */
+ (void)onViewWillDisappear:(NSString *)spmId view:(nonnull NSObject *)view bizCode:(NSString *)bizCode param:(NSDictionary *)param;

/**
 *  清空pageid对应的所有埋点缓存数据，非必需调用
 *  @param view 埋点对应view，传vc对象最好，其次view对象，不能为空
 */

+ (void)onDealloc:(nonnull NSObject *)view;

/**
 * 对应onViewDidAppear:view:，H5专用
 */
+ (void)logPageStartWithSpmId:(NSString *)spmId index:(NSObject *)index;

/**
 * 对应onViewWillDisappear:view:bizCode:param:，H5专用
 */
+ (void)logPageEndWithSpmId:(NSString *)spmId
                      index:(NSObject *)index
                    bizType:(nullable NSString *)bizType
                      param:(nullable NSDictionary *)param;



///////////////////////////////////////////////////////////////////////////////////////////////////////////
// pagets
/**
 *  RPC透传pageId，根据view获得pageId
 *
 *  @param view 埋点对应view，传vc对象最好，其次view对象，不能为空
 *
 *  @return 以pageId为value的字典
 **/
+ (NSDictionary* )headerParamsForPagets:(NSObject *)view;

/**
 *  根据view获得miniPageId
 *
 *  @param view 埋点对应view，传vc对象最好，其次view对象，不能为空
 *
 *  @return miniPageId值
 **/
+ (NSString *)getMiniPageId:(NSObject *)view;

/**
 *  根据view获得pageId
 *
 *  @param view 埋点对应view，传vc对象最好，其次view对象，不能为空
 *
 *  @return pageId值
 **/
+ (NSString *)getPageId:(NSObject *)view;

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// pageback
/**
 *  设备页面回退标志黑名单
 *
 *  @param pageBackDicBlack 不会被标记为退回的页面们的spmid，比如：钱包首页4大金刚之一口碑首页a13.b42
 **/
+(void)updatePageBackDicBlack:(NSArray<NSString *> *)pageBackDicBlack;

@end

NS_ASSUME_NONNULL_END

#endif
