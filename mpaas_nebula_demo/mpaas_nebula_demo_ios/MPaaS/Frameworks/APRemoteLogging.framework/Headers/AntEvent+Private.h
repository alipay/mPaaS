//
//  AntEvent+Private.h
//  APRemoteLogging
//
//  Created by LiMengtian on 2018/10/29.
//  Copyright © 2018 Alipay. All rights reserved.
//

//业务方禁止引入该头文件！！！
//业务方禁止引入该头文件！！！
//业务方禁止引入该头文件！！！

#ifndef AntEvent_Private_h
#define AntEvent_Private_h

#import "AntEvent.h"

//https://yuque.antfin-inc.com/dc/guide/shokgx

@interface AntEvent ()

@property (nonatomic, copy) NSString *header;       /**< 字段1,日志头,默认D-VM*/
@property (nonatomic, copy) NSDate   *timestamp;    /**< 字段2,客户端日志时间*/
@property (nonatomic, copy) NSString *platformId;   /**< 字段3,客户端ProductID. 如 IPHONE_1ND*/
@property (nonatomic, copy) NSString *clientVersion;/**< 字段4,客户端版本*/
@property (nonatomic, copy) NSString *logVersion;   /**< 字段5,客户端日志模型版本号*/
@property (nonatomic, copy) NSString *clientId;     /**< 字段6,[imei]|[imsi] 客户端ID*/
@property (nonatomic, copy) NSString *sessionId;    /**< 字段7,客户端会话ID*/
@property (nonatomic, copy) NSString *userId;       /**< 字段8,用户ID*/
@property (nonatomic, assign) unsigned long long sampleRate;   /**< 字段9,当前抽样率0~1000,代表0.1%～100%*/
//@property (nonatomic, copy) NSString *eventId;      /**< 字段10，事件ID 必填 */
//@property (nonatomic, copy)   NSString *bizType;    /**< 字段11,业务类型,可用于控制日志分文件存储以及上报 必填*/
@property (nonatomic, copy) NSString *renderBiz;    /**< 字段11,最终落在日志中的业务类型,该值为空时取bizType字段*/
//@property (nonatomic, assign) AntLogLevel logLevel; /**< 字段12,日志等级,可用于控制日志上报*/
@property (nonatomic, copy) NSString *pageId;     /**< 字段13,页面Id,格式为"spmId__utdid__timestampIn64_"*/
@property (nonatomic, copy) NSString *ABTestInfo; /**< 字段14,ABTest信息*/
@property (nonatomic, copy) NSString *ucId;       /**< 字段15,用例编号*/
@property (nonatomic, copy) NSString *hpVersion; /**< 字段16,hotpatch版本号*/
@property (nonatomic, copy) NSString *systemName;   /**< 字段17,系统名, e.g. "iOS" */
@property (nonatomic, copy) NSString *systemVersion;/**< 字段18,操作系统版本号*/
@property (nonatomic, copy) NSString *networkType;  /**< 字段19,网络类型*/
@property (nonatomic, copy) NSString *deviceModel;  /**< 字段20,手机型号*/
@property (nonatomic, copy) NSString *innerVersion; /**< 字段21,内部版本号*/
@property (nonatomic, copy) NSString *distributionChannel; /**< 字段22,App发布渠道*/
@property (nonatomic, copy) NSString *utdid;        /**< 字段23,utdid设备ID*/
@property (nonatomic, copy) NSString *language;     /**< 字段24,App语言*/
@property (nonatomic, copy) NSString *manufacturer; /**< 字段25，制造商*/
@property (nonatomic, copy) NSString *resolution;   /**< 字段26,分辨率*/
@property (nonatomic, copy) NSString *appId;        /**< 字段27,子应用ID*/
@property (nonatomic, copy) NSString *processName;  /**< 字段28,Android独有,进程名*/
@property (nonatomic, copy) NSDictionary *deviceInfo; /**< 字段29，手机属性*/
@property (nonatomic, copy) NSString *clientReservedParams;  /**< 字段30， 客户端预留*/
@property (nonatomic, copy) NSString *userReservedParams;  /**< 字段31， 用户预留*/
@property (nonatomic, copy) NSString *logSequenceId;/**< 字段32,日志序列号*/
@property (nonatomic, copy) NSString *foundationExtended; /**< 字段33.全局扩展字段*/
@property (nonatomic, copy) NSString *extParam1;    /**< 字段34,扩展字段1*/
@property (nonatomic, copy) NSString *extParam2;    /**< 字段35,扩展字段2*/
@property (nonatomic, copy) NSString *extParam3;    /**< 字段36,扩展字段3*/
//@property (nonatomic, copy) NSDictionary *extParam4;/**< 字段37,扩展字段4,将key-value对转换成‘key=value^key1=value1’的形式落入日志.*/
@property (nonatomic, copy) NSString *reservedParams1; /**< 字段38,保留字段1*/
@property (nonatomic, copy) NSString *reservedParams2; /**< 字段39,保留字段2*/

@end

#endif /* AntEvent_Private_h */
