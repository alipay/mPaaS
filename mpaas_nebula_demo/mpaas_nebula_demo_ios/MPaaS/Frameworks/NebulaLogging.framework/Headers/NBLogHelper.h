//
//  H5LogHelper.h
//  H5Service
//
//  Created by bingye.yu on 12/15/15.
//  Copyright (c) 2015 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
@class APLogTrackContext;

@interface NBLogHelper : NSObject

@property(nonatomic, copy) NSString *url;
@property(nonatomic, copy) NSString *referer;
@property(nonatomic, readonly) unsigned long long lastH5Tap;
@property(nonatomic, assign) NSTimeInterval lastDidBecomeActive;

- (void)pushGeneralFields:(NSDictionary *)generalFields;
- (void)popGeneralFields;
- (void)popGeneralFieldsWithH5Token:(NSString *)pageUUID;
- (NSDictionary *)currentGeneralFields;

+ (NBLogHelper *)sharedInstance;

+ (void)setLastH5Tap:(unsigned long long)lastH5Tap;

- (NSString *)generateUUID;
- (NSString *)generateUUID:(PSDKernel *)target;

+ (NSString *)getTimeNow;
// HAR下线　+ (NSString *)getLogTimeStr:(NSDate *)date forHAR:(BOOL)forHAR;

+ (NSString *)extractSimpleUrl:(NSString *)simpleUrl;

- (void)clearAll;

+ (NSString *)safeSplitFromStr:(NSString *)origStr;

double NBLogGetUsedMemory();
BOOL NBLogRegexTest(NSString *str, NSArray *patterns);
id safe_getAssociatedObject(id object, const void * key);


#pragma mark - 通用字段
/***************************************************************************
 * 通用字段：appId（产品ID）,publicId（服务窗ID）, openAppId（开放平台ID）,shopId(商铺ID), version（产品版本号）, url、referer（上一个页面的URL）, token（native控件的唯一标识）,viewId（当前native控件ID）,refviewId（上一个native控件ID）,h5Token（每一次页面访问的唯一标识）,h5SessionToken（每一次H5会话的唯一标识）, appmode(op或nb，标识应用中心或nebula平台),psd（online或local，标识在线页面或离线页面）, bizScenario（业务场景来源）,sourceId（上一个产品ID）,customParams(自定义启动参数，通常用于埋点),  log_release_type(发布类型), isTinyApp(是否为小程序)。19项
 *
 */


/**
 扩展参数预处理

 @param params 原始扩展参数
 @return count为1～4的扩展参数
 */
+ (NSArray *)formateArray:(NSArray *)params;

/**
 拼接入参，加入通用容器埋点字段；当参数冲突时，优先使用入参params中的参数

 @param params 原始参数
 @param ucId 用例ID
 @param actionId 行为ID
 @param seedId 埋点名
 @return count<=4的非nil数组
 */
+ (NSArray * _Nonnull)resultParamsWithParams:(NSArray *)params
                                        ucId:(NSString *)ucId
                                    actionId:(NSString *)actionId
                                      seedId:(NSString *)seedId;

+ (NSArray *)resultParamsWithParams:(NSArray *)params ucId:(NSString *)ucId actionId:(NSString *)actionId seedId:(NSString *)seedId inSession:(PSDSession * _Nullable)session;

+ (NSArray *)resultParamsWithParams:(NSArray *)params ucId:(NSString *)ucId actionId:(NSString *)actionId seedId:(NSString *)seedId inPage:(PSDPage * _Nonnull)psdPage;
/**
 基于事件的埋点时，自行获取通用字段，尽量不依赖H5LogHeler单例

 @param page 当前页面 session 当前应用 useGenerateFirst 页面退出时获取不可靠，使用缓存项
 @return 可靠的通用字段字典
 */
+ (NSDictionary *)generalFields;
+ (NSDictionary *)generalFieldsFromPage:(PSDPage *)page;
+ (NSDictionary *)generalFieldsFromPage:(PSDPage *)page useGenerateFirst:(BOOL)useGenerateFirst;
+ (NSDictionary *)generalFieldsFromSession:(PSDSession *)psdSession;

/**
 将字典用'^', '='拼接起来

 @param dict 原始字典
 @return 拼接结果
 */
+ (NSString * _Nonnull)concatedLogFromDictionary:(NSDictionary *)dict;


/**
 统一性能日志入口
 过滤webapp日志分离

 @param tpye 类型
 @param subType 子类型，业务可以自己定义
 @param extraParams 扩展字段，共四个item，第四个item是字典，字典内容可自定义，字典会被转换成key-value的字符串计入日志
 @param formatterDictionary 业务可以根据需求自定义formatter字典值，格式头可以通过此字典参数设置
 @param perUploadNum达到number条日志时，触发一次日志上传，当number＝＝1时，实时上传日志。0表示忽略此参数.
 */
+ (void)doPerformanceLogWithType:(APLogType)type
                         subType:(NSString *)subType
                     extraParams:(NSArray *)extraParams
             formatterDictionary:(NSDictionary *)formatterDictionary
                    perUploadNum:(NSUInteger)number
                          target:(PSDKernel *)target;

+ (void)doBehaviorLogWithActionId:(NSString *)actionId
                        extParams:(nullable NSArray *)extParams
                            appId:(nullable NSString *)appId
                             seed:(NSString *)seed
                             ucId:(nullable NSString *)ucId
                          bizType:(nullable NSString *)bizType
              formatterDictionary:(nullable NSDictionary *)formatterDictionary
                           target:(PSDKernel *)target;

+ (void)doPerformanceLogWithType:(APLogType)type
                         subType:(NSString *)subType
                             lid:(NSString *)lid
                     extraParams:(NSArray *)extraParams
             formatterDictionary:(NSDictionary *)formatterDictionary
                    perUploadNum:(NSUInteger)number
                          target:(PSDKernel *)target;


+ (void)enqueueTaskSync:(void(^)())block;
+ (void)enqueueTaskAsync:(void(^)())block;
+ (void)forceEnqueueTaskAsync:(void(^)())block;

#pragma mark - 自动spm日志自动参数

+ (NSDictionary *)extraParamForPSDContext:(__unused PSDContext *)psdContext trackContext:(__unused APLogTrackContext *)trackContext;

@end
