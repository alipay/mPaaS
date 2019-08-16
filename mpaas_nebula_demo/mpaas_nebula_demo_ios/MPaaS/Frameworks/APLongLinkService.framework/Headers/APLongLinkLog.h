//
//  APLongLinkLog.h
//  APLongLinkService
//
//  Created by cuinacai on 14/11/6.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum {
    SYNC_LINK = 0,
    SYNC_PROTO,
    SYNC_Diagnose //诊断日志
} LonkLinkLogType;

//subType
extern NSString * const APSyncConnSpdy;
extern NSString * const APSyncConnSSL;
extern NSString * const APSyncConnTCP;
extern NSString * const APSyncConnMMTP;
extern NSString * const APSyncLLInitMMTP;
extern NSString * const APSyncLLInit;
extern NSString * const APSyncLLBU;
extern NSString * const APSyncLLUBU;
extern NSString * const APSyncLLH;
extern NSString * const APSyncExpSpdy;
extern NSString * const APSyncExpMMTP;
extern NSString * const APSyncExpLL;
extern NSString * const APSyncSync1001;
extern NSString * const APSyncSync1003;
extern NSString * const APSyncSync1004;
extern NSString * const APSyncSync2001;
extern NSString * const APSyncSync2002;
extern NSString * const APSyncSync2003;
extern NSString * const APSyncSyncExp;
extern NSString * const APSyncSyncDispatch;
extern NSString * const APSyncSyncCallback;
extern NSString * const APSyncAppstat;
extern NSString * const APSyncNetstat;
extern NSString * const APSyncBgtime;

//扩展参数
extern NSString * const APSyncExtraPara1;
extern NSString * const APSyncExtraPara2;
extern NSString * const APSyncExtraPara3;
extern NSString * const data_parse_exception;
extern NSString * const db_exception;

@protocol APLongLinkLogInterface <NSObject>
/**
 *  写日志
 *
 *  @param type     日志类型(文件名字)
 *  @param subType  子类型
 *  @param params   参数
 *  @param formater 格式
 */
-(void)logWithType:(LonkLinkLogType)type subType:(NSString *)subType extraParams:(NSDictionary*)params paramsFormater:(NSArray*)formater;
@optional
/**
 * 功能或关键业务不可用时的埋点上报
 *
 * bizName  业务名字            （字符串，如：MTBIZ_FRAME，MTBIZ_NETWORK，MTBIZ_SYNC，MTBIZ_MEDIA，以及其它业务自己定义）
 * subName  业务不可用功能点名字  （字符串，如：FRAME_CLIENT_STARTUP_DEAD，以及其它业务自己定义）
 * failCode 不可用原因分类码     （整型值，业务自己定义）
 * params   埋点扩展参数        （dict，业务自己定义）
 */
-(void)MTBIZ_Report:(NSString*)bizName subName:(NSString*)subName failCode:(NSInteger)failCode params:(NSDictionary*)params;
/**
 * 针对买名单或者开关控制内的用户埋点上报
 *
 * param1  埋点定义的参数1
 * param2  埋点定义的参数2
 * param3  埋点定义的参数3
 * map     扩展字段k-v
 */
- (void)writeNetworkLogParam1:(NSString*)param1 param2:(NSString *)param2 param3:(NSString *)param3 paramKVMap:(NSDictionary *)map;
/**
 * network监控日志
 *
 * param1  埋点定义的参数1
 * param2  埋点定义的参数2
 * param3  埋点定义的参数3
 * map     扩展字段k-v
 */
- (void)writeMonitorLogParam1:(NSString*)param1 param2:(NSString *)param2 param3:(NSString *)param3 paramKVMap:(NSDictionary *)map;
@end

@interface APLongLinkLog : NSObject
/**
 *  设置写日志的实现者
 *
 *  @param logger 实现APLongLinkLogInterface的对象
 */
+(void)setLogger:(id<APLongLinkLogInterface>)logger;
/**
 *  写日志
 *
 *  @param type     日志类型(文件名字)
 *  @param subType  子类型
 *  @param params   参数
 *  @param formater 格式
 */
+(void)logWithType:(LonkLinkLogType)type subType:(NSString *)subType extraParams:(NSDictionary*)params paramsFormater:(NSArray*)formater;
/**
 * 功能或关键业务不可用时的埋点上报
 *
 * subName  业务不可用功能点名字  （字符串，如：FRAME_CLIENT_STARTUP_DEAD，以及其它业务自己定义）
 * failCode 不可用原因分类码     （整型值，业务自己定义）
 * params   埋点扩展参数        （dict，业务自己定义）
 */
+(void)reportSubName:(NSString*)subName failCode:(NSInteger)failCode params:(NSDictionary*)params;
/**
 * 针对买名单或者开关控制内的用户埋点上报
 *
 * param1  埋点定义的参数1
 * param2  埋点定义的参数2
 * param3  埋点定义的参数3
 * map     扩展字段k-v
 */
+ (void)writeNetworkLogParam1:(NSString*)param1 param2:(NSString *)param2 param3:(NSString *)param3 paramKVMap:(NSDictionary *)map;
/**
 * network监控日志
 *
 * param1  埋点定义的参数1
 * param2  埋点定义的参数2
 * param3  埋点定义的参数3
 * map     扩展字段k-v
 */
+ (void)writeMonitorLogParam1:(NSString*)param1 param2:(NSString *)param2 param3:(NSString *)param3 paramKVMap:(NSDictionary *)map;
@end


