//
//  H5Logger+private.h
//  NebulaBiz
//
//  Created by Glance on 16/9/22.
//  Copyright © 2016年 Alipay. All rights reserved.
//


// 默认除H5_PAGE_PERFORMANCE|H5_AL_SESSION_FROM_NATIVE|H5_AL_SESSION_MAP_SUCCESS|H5_AL_SESSION_FALLBACK|H5_GETLOCATION_RESULT之外的常规性能日志会切至NebulaTech类型行为日志。可改写

@interface NBLogger : NSObject

// =================================== 指定发生场景 建议使用 提高准确性 ============================== //


/**
 行为埋点 未使用自动开关控制，大促时无差别降级

 @param seedID 埋点名
 @param ucId 用例组标识
 @param params 埋点入参
 @param page 发生页面
 */
+ (void)behaviorLogger:(NSString *)seedID params:(NSArray *)params inPage:(PSDPage *)page;
+ (void)behaviorLogger:(NSString *)seedID ucId:(NSString *)ucId params:(NSArray *)params inPage:(PSDPage *)page;


/**
 性能埋点 未使用自动开关控制，大促时无差别降级

 @param seedID 埋点名
 @param ucId 用例组标识
 @param params 埋点入参
 @param page 发生页面
 */
+ (void)performaceLogger:(NSString *)seedID params:(NSArray *)params inPage:(PSDPage *)page;


/**
 异常埋点 未使用自动开关控制，大促时无差别降级

 @param seedID 埋点名
 @param ucId 用例组标识
 @param params 埋点入参
 @param page 发生页面
 */
+ (void)errorLogger:(NSString *)seedID params:(NSArray *)params inPage:(PSDPage *)page;


/**
 通用埋点 未使用自动开关控制，大促时无差别降级

 @param seedID 埋点名
 @param ucId 埋点入参
 @param params 埋点入参
 @param logHeader 日志头
 @param realTime 是否需要实时上传
 @param page 发生页面
 */
+ (void)monitorLogger:(NSString *)seedID
                 ucId:(NSString *)ucId
               params:(NSArray *)params
            logHeader:(NSString *)logHeader
             realTime:(BOOL)realTime
               inPage:(PSDPage *)page;


// =================================== 业务手动埋点接口 ============================== //

+ (void)behaviorLogger:(NSString *)seedID
                  ucId:(NSString *)ucId
              actionId:(NSString *)actionId
                params:(NSArray *)params
              logLevel:(NSInteger)logLevel
               bizType:(NSString *)bizType
              spmToken:(NSObject *)spmToken
            abTestInfo:(NSString *)abTestInfo
              entityId:(NSString *)entityId
            extLogInfo:(NSDictionary *)extLogInfo
                inPage:(PSDPage *)page;


// =================================== 自动页面信息不准 建议换用以上新接口 ============================== //


/**
 *  读取当前环境参数的快捷方法
 *
 */
+ (void)getAppId:(NSString **)appId publicId:(NSString **)publicId version:(NSString **)version sourceId:(NSString **)sourceId bizScenario:(NSString **)bizScenario;

+ (void)getAppId:(NSString **)appId publicId:(NSString **)publicId openAppId:(NSString **)openAppId shopId:(NSString **)shopId version:(NSString **)version sourceId:(NSString **)sourceId bizScenario:(NSString **)bizScenario customParams:(NSString **)customParams;

/**
 *  行为埋点
 *  @param seedID 埋点名
 *  @param ucId 用例组标识
 *  @params params  埋点的数组,数组中支持4个项，最后一项目需要传入数组
 */
+ (void)behaviorLogger:(NSString *)seedID ucId:(NSString *)ucId params:(NSArray *)params;

/**
 *  性能埋点
 *  @param seedID 埋点名
 *  @param ucId 用例组标识
 *  @params params  埋点的数组,数组中支持4个项，最后一项目需要传入数组
 */
+ (void)performaceLogger:(NSString *)subType params:(NSArray *)params;

/**
 *  常规监控埋点
 *  @param seedID 埋点名
 *  @param ucId 用例组标识
 *  @params params  埋点的数组,数组中支持4个项，最后一项目需要传入数组
 */
+ (void)monitorLogger:(NSString *)seedID ucId:(NSString *)ucId params:(NSArray *)params;

/**
 *  通用性能模型埋点方法
 *  @param seedID 埋点名
 *  @param ucId 用例组标识
 *  @params params  埋点的数组,数组中支持4个项，最后一项目需要传入数组
 *  @params logHeader 传入 "H-MM"时做性能埋点, 传入"H-EM"时做异常埋点用
 *  @params realTime 是否实时上报
 */
+ (void)monitorLogger:(NSString *)seedID ucId:(NSString *)ucId params:(NSArray *)params logHeader:(NSString *)logHeader realTime:(BOOL)realTime;



@end
