//
//  APLogAddions.h
//  APRemoteLogging
//
//  Created by tashigaofei on 15/10/13.
//  Copyright © 2015年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AntLogInterface.h"

@interface APLogAdditions : NSObject<AntLogInterceptor>

/**
 *  UUID、UTDID、clientID、deviceModel，language，接入方无须重写，由mPaaS自动获取。
 */
@property (nonatomic, strong, readonly) NSString *UUID __deprecated_msg("业务方需要自定义UUID时,请覆盖实现getBrandNewUUID方法."); // 默认实现为调用系统方法获取UUID
@property (nonatomic, strong, readonly) NSString *UTDID;    // 默认实现为从APMobileIdentifier获取，如果没有APMobileIdentifier，会反射式调用UTDID库的[UTDevice utdid]方法
@property (nonatomic, strong, readonly) NSString *clientID; // 默认实现为从APMobileIdentifier获取，如果没有APMobileIdentifier，会返回@""
@property (nonatomic, strong) NSString *deviceModel;        // 默认实现为从APMobileIdentifier获取，如果没有APMobileIdentifier，会调用系统方法获取设备型号
@property (nonatomic, strong) NSString *language;           // 默认实现为读取NSUserDefaults中kAPLanguageSettingKey。如果使用钱包或mPaaS多语言模块，该方法不需要重写

/**
 *  userID为可选参数，当前登录的用户，接入方在Category中覆盖实现。
 */
@property (nonatomic, strong) NSString *userID;

/**
 *  log日志服务器地址，默认返回@""，需要接入方在Category中覆盖。格式为http://mdap.alipaylog.com/loggw/log.do
 */
@property (nonatomic, strong) NSString *logServerURL;

/**
 *  log日志服务器配置地址，默认返回@""，需要接入方在Category中覆盖。格式为http://mdap.alipaylog.com/loggw/config.do
 *  一般只需要重写logServerURL即可，configServerURL系统会自动根据logServerURL进行修改。
 */
@property (nonatomic, strong) NSString *configServerURL;

/**
 *  log日志服务器配置获取间隔，需要接入方在Category中覆盖，默认为600s
 */
@property (nonatomic, assign) CFAbsoluteTime configGetInterval;

/**
 *  客户端日志产品ID，默认返回[[NSBundle mainBundle] objectForInfoDictionaryKey:@"Product ID"]，如果不同需要接入方在Category中覆盖。
 */
@property (nonatomic, strong) NSString *platformID;

/**
 *  客户端版本号，默认返回[[NSBundle mainBundle] objectForInfoDictionaryKey:@"Product Version"]，如果不同需要接入方在Category中覆盖。
 */
@property (nonatomic, strong) NSString *clientVersion;

/**
 *  本地日志文件大小上限,达到上限时删除历史文件的四分之一. 默认返回 1024*1024*30L (30MB), 如果不同需要接入方在Category中覆盖。
 */
@property (nonatomic, assign) NSInteger maximumSizeOfLog;

/**
 *  本地日志文件个数上限,达到上限时删除历史文件的四分之一. 默认返回256, 如果不同需要接入方在Category中覆盖。
 */
@property (nonatomic, assign) NSInteger maximumNumberOfLogFiles;

/**
 单行日志长度上限,超过上限的日志被丢弃. 默认16K.
 */
@property (nonatomic, assign) NSInteger maximumLengthOfLine;

+ (instancetype)sharedInstance;

/**
 *  默认实现为返回 @[]
 *  @return @[@(APLogTypeXXX), @(APLogTypeYYY)]数组。数组元素为NSNumber类型
 */
- (NSArray*)defaultUploadLogTypes __deprecated_msg("All logs will write & upload without server config now. The return value of this method is ignored.");

/**
 *  输出诊断日志到本地日志文件，方便定位问题。
 *  该方法默认实现为空，由外部覆盖实现为指定日志方法。
 */
- (void)logToFile:(NSString*)logStr;

/**
 生成一个新的UUID.
 每次后台回前台会检查当前UUID的时间戳是否超过了30分钟,若超过了,该方法会被调用.
 默认的实现为调用系统方法生成一个新的UUID: [NSUUID UUID].UUIDString
 
 @return 新的UUID字符串.
 */
- (NSString *)getBrandNewUUID;

/**
 * 是否存在Interceptor实现. 默认返回NO.
 * 接入方需要介入写入/上报时在Category中覆盖该方法返回YES，并覆盖 beforeWrite: 和 beforeUpload: 方法.
 * @return 默认返回NO
 */
- (BOOL)hasInterceptor;

/**
 * 默认实现为空. 接入方需要介入写入时在Category中覆盖该方法.
 */
- (void)beforeWrite:(AntLogWriteOperation *)operations;

/**
 * 默认实现为空. 接入方需要介入上报时在Category中覆盖该方法.
 */
- (void)beforeUpload:(AntLogUploadOperation *)operation;

/**
 IDFA值，可选，默认实现返回nil，接入方可在Category里覆盖实现.
 */
- (NSString *)idfa;

@end
