//
//  APMLog.h
//  APMultimedia
//
//  Created by Cloud on 16/3/7.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

// 如果需要使用TAG的，可以在各自的类中定义此TAG，这样便会在所有的log前加上"TAG"这样的前缀
#define APM_LOG_TAG

// 这里再增加一个间接层以用于后面重定义APMLog这个类，可以动态加载
// 比如在动态库中，可以重定义APMLogClass为：
// #define APMLogClass NSClassFromString(@"APMLog")
// 这样动态库中就可以动态的去加载这个类
#define APMLogClass APMLog

#define APM_LOG_WITH_TAG(message, level, ...) [APMLogClass log: message atLevel: level, ## __VA_ARGS__]
#define APM_LOG(message, level, ...) APM_LOG_WITH_TAG(APM_LOG_TAG message, level, ## __VA_ARGS__)

#define APM_DEBUG(message, ...) APM_LOG(message, APMLogLevelDebug, ## __VA_ARGS__)
#define APM_INFO(message, ...) APM_LOG(message, APMLogLevelInfo, ## __VA_ARGS__)
#define APM_WARNING(message, ...) APM_LOG(message, APMLogLevelWarning, ## __VA_ARGS__)
#define APM_ERROR(message, ...) APM_LOG(message, APMLogLevelError, ## __VA_ARGS__)

typedef enum {
    APMLogLevelError = 0,
    APMLogLevelWarning,
    APMLogLevelInfo,
    APMLogLevelDebug
} APMLogLevel;

@interface APMLog : NSObject

+ (void)log:(NSString *)format atLevel:(APMLogLevel)level, ...NS_FORMAT_FUNCTION(1,3);

/**
 *  console打完日志之后接着输出一份，供外部覆盖处理，比如写文件
 *
 *  @param message 处理之后的日志
 *  @param level   日志级别
 */
+ (void)logMessage:(NSString *)message atLevel:(APMLogLevel)level;

@end
