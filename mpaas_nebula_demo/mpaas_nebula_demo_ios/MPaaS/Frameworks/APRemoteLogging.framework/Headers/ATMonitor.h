//
//  ATMonitor.h
//  APRemoteLogging
//
//  Created by 卡迩 on 2018/7/4.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import "ATEvent.h"

/**
 * 性能管理日志模型
 */
@interface ATMonitor : ATEvent

@property (nonatomic, strong) NSString *header;       /**< 字段1,日志头,默认D-VM*/
@property (nonatomic, strong) NSDate   *timestamp;    /**< 字段2,客户端日志时间*/
@property (nonatomic, strong) NSString *platformId;   /**< 字段3,客户端ProductID. 如 IPHONE_1ND*/
@property (nonatomic, strong) NSString *clientVersion;/**< 字段4,客户端版本*/
@property (nonatomic, strong) NSString *logVersion;   /**< 字段5,客户端日志模型版本号*/
@property (nonatomic, strong) NSString *clientId;     /**< 字段6,[imei]|[imsi] 客户端ID*/
@property (nonatomic, strong) NSString *userId;       /**< 字段7,用户ID*/
@property (nonatomic, strong) NSString *networkType;  /**< 字段8,网络类型*/
@property (nonatomic, strong) NSString *deviceModel;  /**< 字段9,手机型号*/
@property (nonatomic, strong) NSString *systemVersion;/**< 字段10,操作系统版本号*/
@property (nonatomic, strong) NSString *innerVersion; /**< 字段11,内部版本号*/
@property (nonatomic, strong) NSString *channelId;    /**< 字段12,渠道ID*/
@property (nonatomic, strong) NSString *packageType;  /**< 字段13,包类型*/
@property (nonatomic, strong) NSString *appId;        /**< 字段14,子应用ID*/
@property (nonatomic, strong) NSString *monitorType;  /**< 字段15,subType*/
@property (nonatomic, strong) NSString *subType;      /**< 字段16,subType*/
@property (nonatomic, strong) NSDictionary *attachment; /**< 字段17,attachment*/
@property (nonatomic, strong) NSString *language;     /**< 字段18,App语言*/
@property (nonatomic, strong) NSString *hpVersion;    /**< 字段19,hotpatch版本号*/
@property (nonatomic, strong) NSString *cpuCoreNum;   /**< 字段20,Android独有,cpu核数*/
@property (nonatomic, strong) NSString *cpuMaxFreq;   /**< 字段21.Android独有,CPU MaxFreq，单位MHz*/
@property (nonatomic, strong) NSString *totalMem;     /**< 字段22.Android独有,TotalMem,单位MB*/
@property (nonatomic, strong) NSString *extParam1;    /**< 字段23.扩展字段1,服务端填充IP*/
@property (nonatomic, strong) NSString *apk;          /**< 字段24.Android独有,apk唯一ID*/
@property (nonatomic, strong) NSString *processName;  /**< 字段25,Android独有,进程名*/
@property (nonatomic, strong) NSString *utdid;        /**< 字段26,utdid设备ID*/
@property (nonatomic, strong) NSString *foundationExtended; /**< 字段27.全局扩展字段*/
@property (nonatomic, strong) NSString *logSequenceId;/**< 字段28,日志序列号*/
@property (nonatomic, strong) NSString *logIDFA;      /**< 字段29,IDFA值*/

@end
