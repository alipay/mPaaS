//
//  APDataCenterInterface.h
//  MPDataCenter
//
//  Created by shenmo on 5/4/16.
//  Copyright © 2016 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface APDataCenterInterface : NSObject

/**
 *  单例对象
 */
+ (instancetype)sharedInstance;

#pragma mark - 默认加解密密钥，32字节的数组

// 下面两个方法任选其一实现
//      第一个方法由应用提供完整的32字节密钥
//      第二个方法由应用提供一个AppId，由统一存储计算出32字节的密钥。

/**
 *  为了安全性，不使用Objective-C方法的返回值来设置加密Key。
 *  接入应用使用Category覆盖此方法后，在实现中再回调setter方法，将加密key返回。
 *  如果覆盖了此方法，返回YES。
 */
- (BOOL)setDefaultCryptKey:(void (*)(NSData* key))setter;

#pragma mark - 日志方法

/**
 *  写本地文件日志
 *  默认实现为调用APLogInfo接口写日志，Tag为"APDataCenter"
 */
- (void)writeLocalFileLog:(NSString*)line;

/**
 *  写远程日志，用于记录异常与错误
 *  默认实现为：
     [APRemoteLogger writeLogWithActionId:KActionID_Event
                                extParams:@[[NSString stringWithFormat:@"[APDataCenter] %@", line]]
                                    appId:@"data_center"
                                     seed:@"data_center_log"
                                     ucId:@""];
 */
- (void)writeRemoteLog:(NSString*)line;

/**
 *  写性能日志，用于记录性能监控数据
 *  默认实现为：
    [APRemoteLogger writePerformanceLogWithType:APLogTypeKeyBizTrace subType:@"KeyBiz" extraParams:parameters];
 */
- (void)writePerformanceLog:(NSArray*)parameters;

# pragma mark - 监控使用的方法

/**
 *  应用启动完成会抛的通知，用于统一存储性能数据捕获。判断哪些调用是发生在启动过程中的。
 *  默认返回nil。
 */
- (NSString*)launchingFinishNotificationName;

@end
