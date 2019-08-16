//
//  APRemoteLogger.h
//  APRemoteLogging
//
//  Created by tashigaofei on 14-6-23.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <mach/mach.h>
#import "APMonitorPointDataDefines.h"

#ifdef SDK_IS4_ALIPAY
#import "APLogAddions.h"
#endif

NS_ASSUME_NONNULL_BEGIN
/**
 手动埋点Logger. 包含行为埋点和性能埋点.
 文档: https://lark.alipay.com/wfc/doc/manual-log-ios
 */
@interface APRemoteLogger : NSObject

#pragma mark -
#pragma mark Behavior 行为埋点接口

/**
 *  行为埋点接口。客户端版本、用户ID、设备ID、操作系统版本、网络类型、设备类型、软件版本会自动填充，不需要业务埋点。
 *  对于不需要自定义bizType的业务，推荐使用该接口。
 *
 *  @param actionId  action ID 必填，标识一个埋点的类别，可用actionID定义在APMonitorPointDataDefines.h
 文件中
 *  @param extParams 可选，扩展参数，业务自己根据需要填充。数组元素最多4个，第四个元素可以是字典，
 字典内容可自定义，字典会被转换成key-value的字符串计入日志
 *  @param appId     可选，子应用ID
 *  @param seed      可选，埋点ID，现已更名为spm，若有则务必填写。
 *  @param ucId      可选，用例编号
 */
+(void)writeLogWithActionId:(NSString *)actionId
                  extParams:(nullable NSArray *)extParams
                      appId:(nullable NSString *)appId
                       seed:(NSString *)seed
                       ucId:(nullable NSString *)ucId;

/**
 *  行为埋点接口。客户端版本、用户ID、设备ID、操作系统版本、网络类型、设备类型、软件版本会自动填充，不需要业务埋点。
 *
 *  @param actionId  action ID 必填，标识一个埋点的类别，可用actionID定义在APMonitorPointDataDefines.h
 文件中
 *  @param extParams 可选，扩展参数，业务自己根据需要填充。数组元素最多4个，第四个元素可以是字典，
 字典内容可自定义，字典会被转换成key-value的字符串计入日志
 *  @param appId     可选，子应用ID
 *  @param seed      可选，埋点ID，现已更名为spm，若有则务必填写。
 *  @param ucId      可选，用例编号
 *  @param bizType   可选，业务类型. 默认值为behavior,若传入非空的自定义的bizType，请务必保证已经跟mdap服务端申请了该bizType,否则服务端会丢弃该日志
 *  对于不需要自定义formatter的业务，推荐使用该接口。
 */
+(void)writeLogWithActionId:(NSString *)actionId
                  extParams:(nullable NSArray *)extParams
                      appId:(nullable NSString *)appId
                       seed:(NSString *)seed
                       ucId:(nullable NSString *)ucId
                    bizType:(nullable NSString *)bizType;

/**
 *  行为埋点接口。客户端版本、用户ID、设备ID、操作系统版本、网络类型、设备类型、软件版本会自动填充，不需要业务埋点。
 *
 *  @param actionId  action ID 必填，标识一个埋点的类别，可用actionID定义在APMonitorPointDataDefines.h
 文件中
 *  @param extParams 可选，扩展参数，业务自己根据需要填充。数组元素最多4个，第四个元素可以是字典，
 字典内容可自定义，字典会被转换成key-value的字符串计入日志
 *  @param appId     可选，子应用ID
 *  @param seed      可选，埋点ID，现已更名为spm，若有则务必填写。
 *  @param ucId      可选，用例编号
 *  @param bizType   可选，业务类型. 默认值为behavior,若传入非空的自定义的bizType，请务必保证已经跟mdap服务端申请了该bizType,否则服务端会丢弃该日志
 *  @param formatterDictionary  可选，业务可以根据需求自定义formatter字典值，内容ID(entityId/SCM)、日志头(header)、页面Id(pageId)、日志级别(logLevel)、ABTest实验信息(abTestInfo)可通过该字段自定义。
 */
+ (void)writeLogWithActionId:(NSString *)actionId
                   extParams:(nullable NSArray *)extParams
                       appId:(nullable NSString *)appId
                        seed:(NSString *)seed
                        ucId:(nullable NSString *)ucId
                     bizType:(nullable NSString *)bizType
         formatterDictionary:(nullable NSDictionary *)formatterDictionary;

#pragma mark -
#pragma mark PageMonitor
/**
 *  PageMonitor 页面打开
 *  @param spmId 代表当前页面的spm
 *  @param index  pageid索引,通常传入当前VC对象即可,同一个页面的pageStart和pageEnd需要传入同一个对象.
 *  @return void
 *
 */
+ (void)logPageStartWithSpmId:(NSString *)spmId
                        index:(NSObject *)index;

/**
 *  PageMonitor 页面结束，会生成pageMonitor埋点
 *  @param spmId 代表当前页面的spm
 *  @param index  pageid索引,通常传入当前VC对象即可,同一个页面的pageStart和pageEnd需要传入同一个对象.
 *  @param param 手动埋点扩展参数4
 *  @return void
 */
+ (void)logPageEndWithSpmId:(NSString *)spmId
                      index:(NSObject *)index
                    bizType:(nullable NSString *)bizType
                      param:(nullable NSDictionary *)param;

#pragma mark -
#pragma mark Performance 性能埋点接口

#ifdef SDK_IS4_ALIPAY
/**
 *  性能埋点接口，客户端版本、用户ID、设备ID、操作系统版本、网络类型、设备类型、软件版本会自动填充，不需要业务埋点。
 *
 *  @param tpye 类型
 *  @param subType 子类型，业务可以自己定义
 *  @param extraParams 扩展字段，共四个item，第四个item是字典，字典内容可自定义，字典会被转换成key-value的字符串计入日志
 */
+ (void)writePerformanceLogWithType:(APLogType)type
                            subType:(nullable NSString *)subType
                        extraParams:(nullable NSArray *)extraParams;

/**
 *  埋点接口，客户端版本、用户ID、设备ID、操作系统版本、网络类型、设备类型、软件版本会自动填充，不需要业务埋点。
 *
 *  @param tpye 类型,每种类型对应一个日志文件
 *  @param subType 子类型，业务可以自己定义，用于过滤筛选用
 ＊ @param extraParams 扩展字段，共四个item，第四个item是字典，字典内容可自定义， 字典会被转换成key-value的字符串计入日志
 *  @param perUploadNum 达到num条日志时，触发一次日志上传，当num＝＝1时，实时上传日志。0表示忽略此参数.
 */
+ (void)writeWithType:(APLogType)type
              subType:(nullable NSString *) subType
           paramArray:(nullable NSArray *) extraParams
         perUploadNum:(NSUInteger) num;

/**
 *  性能埋点接口，客户端版本、用户ID、设备ID、操作系统版本、网络类型、设备类型、软件版本会自动填充，不需要业务埋点。
 *
 *  @param tpye 类型
 *  @param subType 子类型，业务可以自己定义
 *  @param extraParams 扩展字段，共四个item，第四个item是字典，字典内容可自定义，字典会被转换成key-value的字符串计入日志
 *  @param formatterDictionary 业务可以根据需求自定义formatter字典值，格式头可以通过此字典参数设置
 *  @param perUploadNum达到number条日志时，触发一次日志上传，当number＝＝1时，实时上传日志。0表示忽略此参数.
 */
+ (void)writePerformanceLogWithType:(APLogType)type
                            subType:(nullable NSString *)subType
                        extraParams:(nullable NSArray *)extraParams
                formatterDictionary:(nullable NSDictionary *)formatterDictionary
                       perUploadNum:(NSUInteger)number;

/**
 *  性能埋点接口(支持自定义bizType，10.0.12新增)
 *  客户端版本、用户ID、设备ID、操作系统版本、网络类型、设备类型、软件版本会自动填充，不需要业务埋点。
 *  @param bizType   埋点的业务类型，用于日志文件拆分、限流;
 *  @param subType   埋点子类型，业务可以自己定义
 *  @param extraParams 扩展字段，共四个item，第四个item是字典，字典内容可自定义，字典会被转换成key-value的字符串计入日志
 *  @param formatterDictionary 业务可以根据需求自定义formatter字典值，日志头、日志级别可以通过此字典参数设置
 *  @param perUploadNum达到number条日志时，触发一次日志上传，当number＝＝1时，实时上传日志。0表示忽略此参数.
 */
+ (void)writePerformanceLogWithBizType:(nullable NSString *)bizType
                               subType:(nullable NSString *)subType
                           extraParams:(nullable NSArray *)extraParams
                   formatterDictionary:(nullable NSDictionary *)dictionary
                          perUploadNum:(NSUInteger)number;
#endif

@end
NS_ASSUME_NONNULL_END
