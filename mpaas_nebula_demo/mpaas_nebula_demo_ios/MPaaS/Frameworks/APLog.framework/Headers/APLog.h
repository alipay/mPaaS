//
//  APLog.h
//  APUtils
//
//  Created by WenBi on 13-4-2.
//  Copyright (c) 2013年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>


typedef enum APLogLevel
{
	/** 特殊的日志级别，用于关闭所有的日志记录。 */
	kAPLogLevelOff = (NSUInteger)-1,
	
	/** 出错级别，用于记录错误事件。 */
	kAPLogLevelError = 40000,
	
	/** 警告级别，记录可能会影响应用程序正常运行的事件。 */
	kAPLogLevelWarn = 30000,
	
	/** 信息级别，用于记录程序中的关键事件。 */
	kAPLogLevelInfo = 20000,
	
	/** 调试级别，用于记录应用程序的调试信息。 */
	kAPLogLevelDebug = 10000,
	
	/** 特殊的最低级别，用于打开所有的日志记录。 */
	kAPLogLevelAll = 0,
	
} APLogLevel;


/**
 * Log a message with kAPLogLevelError level.
 *
 * @param message An NSString object that contains a printf-style string
 *    containing a log message and placeholders for the arguments.
 * @param ... The arguments displayed in the format string.
 */
#define APLogError(tag,fmt, ...) \
APLogToFile(tag, kAPLogLevelError, fmt, ##__VA_ARGS__)

/**
 * Log a message with kAPLogLevelWarn level.
 *
 * @param message An NSString object that contains a printf-style string
 *    containing a log message and placeholders for the arguments.
 * @param ... The arguments displayed in the format string.
 */
#define APLogWarn(tag,fmt, ...) \
APLogToFile(tag, kAPLogLevelWarn, fmt, ##__VA_ARGS__)

/**
 * Log a message with kAPLogLevelInfo level.
 *
 * @param message An NSString object that contains a printf-style string
 *    containing a log message and placeholders for the arguments.
 * @param ... The arguments displayed in the format string.
 */
#define APLogInfo(tag,fmt, ...) \
APLogToFile(tag, kAPLogLevelInfo, fmt, ##__VA_ARGS__)

/**
 * Log a message with kAPLogLevelDebug level.
 *
 * @param message An NSString object that contains a printf-style string
 *    containing a log message and placeholders for the arguments.
 * @param ... The arguments displayed in the format string.
 */
#define APLogDebug(tag,fmt, ...) \
APLogToFile(tag, kAPLogLevelDebug, fmt, ##__VA_ARGS__)


#ifdef __cplusplus
extern "C" {
#endif
    
    /**
     * 内部使用，业务不要用。
     */
    void APLogToFile(NSString *tag, int level, NSString *format, ...) NS_FORMAT_FUNCTION(3,4);
    
    /**
     * 历史遗留，没有实现，业务不要用。
     */
    void APLog(NSString *format, ...) __attribute__((deprecated("Use APLogInfo instead")));

#ifdef __cplusplus
}
#endif


#if DEBUG
#define APLogMonitor(tag,fmt, ...) APLogToFile(tag, kAPLogLevelInfo, fmt, ##__VA_ARGS__)
#else
#define APLogMonitor(tag,fmt, ...)
#endif

