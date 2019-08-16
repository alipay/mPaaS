//
//  ATDataFlow.h
//  APRemoteLogging
//
//  Created by 卡迩 on 2018/7/2.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import "ATEvent.h"

/**
 * 流量监控日志模型
 */
@interface ATDataFlow : ATEvent

@property (nonatomic, strong) NSString *header;       /**< 字段1,日志头,默认DF*/
@property (nonatomic, strong) NSDate   *timestamp;    /**< 字段2,客户端日志时间*/
@property (nonatomic, strong) NSString *platformId;   /**< 字段3,客户端日志时间*/
@property (nonatomic, strong) NSString *clientVersion;/**< 字段4,客户端版本*/
@property (nonatomic, strong) NSString *userId;       /**< 字段5,用户ID*/
@property (nonatomic, strong) NSString *utdid;        /**< 字段6,utdid设备ID*/
@property (nonatomic, strong) NSString *networkType;  /**< 字段7,网络类型*/
@property (nonatomic, strong) NSString *dataFlowType; /**< 字段8,流量类型*/
@property (nonatomic, strong) NSString *identifier;   /**< 字段9,标识符*/
@property (nonatomic, strong) NSString *size;         /**< 字段10,大小*/
@property (nonatomic, strong) NSString *owner;        /**< 字段11,owner*/
@property (nonatomic, strong) NSDictionary *extInfo;  /**< 字段12,扩展参数*/
@property (nonatomic, strong) NSString *systemVersion;/**< 字段13,操作系统版本号*/
@property (nonatomic, strong) NSString *deviceModel;  /**< 字段14,手机型号*/
@property (nonatomic, strong) NSString *unusedInfo0;  /**< 字段15,空*/
@property (nonatomic, strong) NSString *unusedInfo1;  /**< 字段16,空*/
@property (nonatomic, strong) NSString *unusedInfo2;  /**< 字段17,空*/
@property (nonatomic, strong) NSString *unusedInfo3;  /**< 字段18,空*/
@property (nonatomic, strong) NSString *unusedInfo4;  /**< 字段19,空*/
@property (nonatomic, strong) NSString *logSequenceId;/**< 字段20,日志序列号*/
@property (nonatomic, assign) AntLogLevel logLevel;     /**< 字段21,日志等级,可用于控制日志上报*/
@property (nonatomic, assign) unsigned long long sampleRate;   /**< 字段22,当前抽样率0~1000,代表0.1%～100%*/
@property (nonatomic, strong) NSString *logIDFA;      /**< 字段23,IDFA值*/

@end
