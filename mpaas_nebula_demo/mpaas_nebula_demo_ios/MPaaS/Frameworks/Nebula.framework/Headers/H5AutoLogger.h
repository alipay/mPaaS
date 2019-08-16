//
//  H5AutoLogger.h
//  H5Service
//
//  Created by 八爪 on 15/3/12.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "H5AutoLogConfigs.h"

/*
 * 添加埋点设置已移至文件AutoLogConfigs.h
 * 请勿修改本类文件
 */

extern NSString * const kH5Url       ; //当前页面URL
extern NSString * const kH5Title     ; //当前页面标题
extern NSString * const kH5AppId     ; //当前应用ID
extern NSString * const kH5PublicId  ; //当前服务窗ID
extern NSString * const kH5Version   ; //当前应用版本
extern NSString * const kH5BizScenario    ; //当前窗口创建场景
extern NSString * const kH5CustomParams   ; //当前窗口创建时的自定义参数

// ------ 以上入参覆盖 自动通用字段， 落于扩展参数4
extern NSString * const kH5LogStr    ; //当前埋点的特定信息
// ------ 埋点信息落于扩展参数3

extern NSString * const kH5Lid       ; //用于动态控制上传配置 非必需
extern NSString * const kH5SeedId    ; //埋点名称
extern NSString * const kH5RealTime  ; //用于指明该埋点是否单条即上传
extern NSString * const kH5LogHeader ; //用于指明该埋点的日志头
extern NSString * const kH5UseNSLog  ; //用于指明该埋点需控制台输出，默认为YES

// ------ 请勿直接使用字符串值作为日志入参

#pragma mark 自动埋点入参支持键名

@interface H5AutoLogger : NSObject

/**
 兼容NebulaSDK的埋点接口，NebulaSDK不支持传入整型lid
 自动埋点方法以lid为序号，区分上传配置

 @param seedStr 埋点名
 @return 上传配置序号
 */
+ (NSInteger)findSeedNumberWithSeedStr:(NSString *)seedStr;

/**
 自动埋点调用接口

 @param options 支持键值参考前文常量
 */
//+ (void)logWithOptions:(NSDictionary *)options;

+ (void)logWithOptions:(NSDictionary *)options inSession:(PSDSession *)session;

+ (void)logWithOptions:(NSDictionary *)options inPage:(PSDPage *)psdPage;



@end
