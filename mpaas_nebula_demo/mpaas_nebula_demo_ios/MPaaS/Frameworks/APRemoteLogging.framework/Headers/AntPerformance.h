//
//  AntPerformance.h
//  APRemoteLogging
//
//  Created by 卡迩 on 2017/9/29.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AntLogLevel.h"
#import "ATEvent.h"

/**
 * 性能埋点模型
 */
@interface AntPerformance : ATEvent

@property (nonatomic, copy) NSString *bizType;      /**< 字段12,业务类型,可用于控制日志分文件存储以及上报*/
@property (nonatomic, copy) NSString *renderBiz;    /**< 字段12,最终落在日志中的业务类型,该值为空时取bizType字段*/
@property (nonatomic, copy) NSString *subType;      /**< 字段13,子类别*/
@property (nonatomic, copy) NSString *extParam1;    /**< 字段14,扩展字段1*/
@property (nonatomic, copy) NSString *extParam2;    /**< 字段15,扩展字段2*/
@property (nonatomic, copy) NSString *extParam3;    /**< 字段16,扩展字段3*/
@property (nonatomic, copy) NSDictionary *extParam4;/**< 字段17,扩展字段4,将key-value对转换成‘key=value^key1=value1’的形式落入日志.*/
@property (nonatomic, copy) NSString *pageId;       /**< 字段32,页面Id,格式为"spmId__utdid__timestampIn64_"*/

@property (nonatomic, copy) NSString *appId;        /**< 字段34,子应用ID*/

@property (nonatomic, assign) AntLogLevel logLevel;   /**< 字段37,日志等级,可用于控制日志上报*/

@end

@interface AntPerformance ()

@property (nonatomic, strong) NSString *header;       /**< 字段1,日志头*/
@property (nonatomic, strong) NSDate   *timestamp;    /**< 字段2,客户端日志时间*/
@property (nonatomic, strong) NSString *platformId;   /**< 字段3,客户端日志时间*/
@property (nonatomic, strong) NSString *clientVersion;/**< 字段4,客户端版本*/
@property (nonatomic, strong) NSString *logVersion;   /**< 字段5,客户端日志模型版本号*/
@property (nonatomic, strong) NSString *clientId;     /**< 字段6,[imei]|[imsi] 客户端ID*/
@property (nonatomic, strong) NSString *sessionId;    /**< 字段7,客户端会话ID*/
@property (nonatomic, strong) NSString *userId;       /**< 字段8,用户ID*/
@property (nonatomic, strong) NSString *trackId;      /**< 字段9,当前ACTIONID*/
@property (nonatomic, strong) NSString *trackToken;   /**< 字段10,当前ACTION_TOKEN*/
@property (nonatomic, assign) unsigned long long sampleRate;   /**< 字段11,当前抽样率0~1000,代表0.1%～100%*/
@property (nonatomic, strong) NSString *systemName;   /**< 字段18,系统名, e.g. "iOS" */
@property (nonatomic, strong) NSString *systemVersion;/**< 字段19,操作系统版本号*/
@property (nonatomic, strong) NSString *networkType;  /**< 字段20,网络类型*/
@property (nonatomic, strong) NSString *deviceModel;  /**< 字段21,手机型号*/
@property (nonatomic, strong) NSString *innerVersion; /**< 字段22,内部版本号*/
@property (nonatomic, strong) NSString *distributionChannel; /**< 字段23,App发布渠道*/
@property (nonatomic, strong) NSString *utdid;        /**< 字段24,utdid设备ID*/
@property (nonatomic, strong) NSString *language;     /**< 字段25,App语言*/
@property (nonatomic, strong) NSString *cpuCoreNum;   /**< 字段26,Android独有,cpu核数*/
@property (nonatomic, strong) NSString *cpuMaxFreq;   /**< 字段27.Android独有,CPU MaxFreq，单位MHz*/
@property (nonatomic, strong) NSString *totalMem;     /**< 字段28.Android独有,TotalMem,单位MB*/
@property (nonatomic, strong) NSString *hpVersion;    /**< 字段29,hotpatch版本号*/
@property (nonatomic, strong) NSString *apk;          /**< 字段30.Android独有,apk唯一ID*/
@property (nonatomic, strong) NSString *foundationExtended; /**< 字段31.全局扩展字段*/

@property (nonatomic, strong) NSString *resolution;   /**< 字段33,分辨率*/

@property (nonatomic, strong) NSString *processName;  /**< 字段35,Android独有,进程名*/
@property (nonatomic, strong) NSString *logSequenceId;/**< 字段36,日志序列号*/

@property (nonatomic, strong) NSString *logIDFA;      /**< 字段38,IDFA值*/

@end

@interface AntPerformance (Compatibility)

+ (AntPerformance *)performanceWithBizType:(NSString *)bizType
                                   subType:(NSString *) subType
                               extraParams:(NSArray *) extraParams
                           actionControlID:(NSString *) controlID
                               actionToken:(NSString *) actionToken
                       formatterDictionary:(NSDictionary *)formatterDictionary
                              perUploadNum:(NSUInteger) num;

@end

