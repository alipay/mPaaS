//
//  AntBehavior.h
//  APRemoteLogging
//
//  Created by 卡迩 on 2017/9/27.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ATEvent.h"
/**
 * 行为埋点模型
 */
@interface AntBehavior : ATEvent

@property (nonatomic, copy) NSString *actionId;     /**< 字段9,行为ID*/
@property (nonatomic, copy) NSString *ABTestInfo;   /**< 字段10,ABTest信息*/
@property (nonatomic, copy) NSString *refer;        /**< 字段11,refer信息(上一个页面的spm+pageId)*/
@property (nonatomic, copy) NSString *appId;        /**< 字段12,子应用ID*/
@property (nonatomic, copy) NSString *xpath;        /**< 字段14,控件或页面XPath*/
@property (nonatomic, copy) NSString *entityId;     /**< 字段15,数据回流ID(scm)*/
@property (nonatomic, copy) NSString *spm/*seed*/;  /**< 字段16,spm,原seed字段*/
@property (nonatomic, assign) AntLogLevel logLevel;   /**< 字段17,日志等级,可用于控制日志上报*/
@property (nonatomic, copy) NSString *bizType;      /**< 字段18,业务类型,可用于控制日志分文件存储以及上报*/
@property (nonatomic, copy) NSString *renderBiz;    /**< 字段18,最终落在日志中的业务类型,该值为空时取bizType字段*/
@property (nonatomic, copy) NSString *extParam1;    /**< 字段20,扩展字段1*/
@property (nonatomic, copy) NSString *extParam2;    /**< 字段21,扩展字段2*/
@property (nonatomic, copy) NSString *extParam3;    /**< 字段22,扩展字段3*/
@property (nonatomic, copy) NSDictionary *extParam4;/**< 字段23,扩展字段4,转换成‘key=value^key1=value1’的形式落入日志.*/
@property (nonatomic, copy) NSString *ucId;         /**< 字段27,用例编号*/

@end

////////////////////////////////////////////////////////////////////////////////

@interface AntBehavior (/**Private*/)
@property (nonatomic, strong) NSString *header;       /**< 字段1,日志头,默认D-VM*/
@property (nonatomic, strong) NSDate   *timestamp;    /**< 字段2,客户端日志时间*/
@property (nonatomic, strong) NSString *platformId;   /**< 字段3,客户端ProductID. 如 IPHONE_1ND*/
@property (nonatomic, strong) NSString *clientVersion;/**< 字段4,客户端版本*/
@property (nonatomic, strong) NSString *logVersion;   /**< 字段5,客户端日志模型版本号*/
@property (nonatomic, strong) NSString *clientId;     /**< 字段6,[imei]|[imsi] 客户端ID*/
@property (nonatomic, strong) NSString *sessionId;    /**< 字段7,客户端会话ID*/
@property (nonatomic, strong) NSString *userId;       /**< 字段8,用户ID*/

@property (nonatomic, strong) NSString *pageStartTime;/**< 字段13,页面打开时间戳,单位ms,64进制*/
@property (nonatomic, strong) NSString *logType;      /**< 字段19,日志类型,固定为'c'*/
@property (nonatomic, strong) NSString *sourceId;     /**< 字段24,营销来源.*/
@property (nonatomic, strong) NSString *pageStayTime; /**< 字段25,页面停留时长*/
@property (nonatomic, strong) NSString *utdid;        /**< 字段26,utdid设备ID*/

@property (nonatomic, copy  ) NSString *pageId;       /**< 字段28,页面Id,格式为"spmId__utdid__timestampIn64_"*/
@property (nonatomic, copy  ) NSString *lastViewId;   /**< 字段29,上一个ViewId*/
@property (nonatomic, copy  ) NSString *viewId;       /**< 字段30,当前ViewId*/
@property (nonatomic, copy  ) NSString *trackId;      /**< 字段31,当前ACTIONID*/
@property (nonatomic, copy  ) NSString *trackToken;   /**< 字段32,当前ACTION_TOKEN*/
@property (nonatomic, assign) unsigned long long sampleRate;   /**< 字段33,当前抽样率0~1000,代表0.1%～100%*/
@property (nonatomic, strong) NSString *deviceModel;  /**< 字段34,手机型号*/
@property (nonatomic, strong) NSString *systemVersion;/**< 字段35,操作系统版本号*/
@property (nonatomic, strong) NSString *networkType;  /**< 字段36,网络类型*/
@property (nonatomic, strong) NSString *innerVersion; /**< 字段37,内部版本号*/
@property (nonatomic, strong) NSString *distributionChannel; /**< 字段38,App发布渠道*/
@property (nonatomic, strong) NSString *language;     /**< 字段39,App语言*/
@property (nonatomic, strong) NSString *hpVersion;    /**< 字段40,hotpatch版本号*/
@property (nonatomic, strong) NSString *cpuCoreNum;   /**< 字段41,Android独有,cpu核数*/
@property (nonatomic, strong) NSString *cpuMaxFreq;   /**< 字段42.Android独有,CPU MaxFreq，单位MHz*/
@property (nonatomic, strong) NSString *totalMem;     /**< 字段43.Android独有,TotalMem,单位MB*/
@property (nonatomic, strong) NSString *foundationExtended; /**< 字段44.全局扩展字段*/
@property (nonatomic, strong) NSString *spmStatus;    /**< 字段45,spm状态,标识pageStart,pageEnd是否有效*/
@property (nonatomic, strong) NSString *resolution;   /**< 字段46,分辨率*/
@property (nonatomic, strong) NSString *processName;  /**< 字段47,Android独有,进程名*/
@property (nonatomic, strong) NSString *logSequenceId;/**< 字段48,日志序列号*/
@property (nonatomic, strong) NSString *logIDFA;      /**< 字段49,IDFA值*/

@end

////////////////////////////////////////////////////////////////////////////////

@interface AntBehavior (Compatibility)
/**
 * 生成一个AntBehavior对象，兼容老的埋点接口参数
 */
+ (AntBehavior *)behaviorWithActionId:(NSString *)actionId
                            extParams:(NSArray *)extParams
                                appId:(NSString *)appId
                                 seed:(NSString *)seed
                                 ucId:(NSString *)ucId
                              bizType:(NSString *)bizType
                              extInfo:(NSDictionary *)extInfo;

#ifdef SDK_IS4_ALIPAY
/**
 * 生成一个AntBehavior对象，兼容老的埋点接口参数
 */
+ (AntBehavior *)behaviorWithLogDictionary:(NSDictionary *)dict;
#endif

@end

