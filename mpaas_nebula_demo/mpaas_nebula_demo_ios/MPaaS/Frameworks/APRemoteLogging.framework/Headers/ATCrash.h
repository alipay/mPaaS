//
//  ATException.h
//  APRemoteLogging
//
//  Created by 卡迩 on 2018/7/3.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import "ATEvent.h"

/**
 * Crash日志模型
 */
@interface ATCrash : ATEvent

@property (nonatomic, strong) NSString *header;       /**< 字段1,日志头,默认e*/
@property (nonatomic, strong) NSDate   *timestamp;    /**< 字段2,客户端日志时间*/
@property (nonatomic, strong) NSString *platformId;   /**< 字段3,客户端ProductID. 如 IPHONE_1ND*/
@property (nonatomic, strong) NSString *clientVersion;/**< 字段4,客户端版本*/
@property (nonatomic, strong) NSString *logVersion;   /**< 字段5,客户端日志模型版本号*/
@property (nonatomic, strong) NSString *clientId;     /**< 字段6,[imei]|[imsi] 客户端ID*/
@property (nonatomic, strong) NSString *sessionId;    /**< 字段7,客户端会话ID*/
@property (nonatomic, strong) NSString *userId;       /**< 字段8,用户ID*/
@property (nonatomic, strong) NSString *actionId;     /**< 字段9,行为ID*/
@property (nonatomic, strong) NSString *appState;     /**< 字段10,app前后台状态*/
@property (nonatomic, strong) NSString *statusMsg;    /**< 字段11,statusMsg ?*/
@property (nonatomic, strong) NSString *appId;        /**< 字段12,子应用ID*/
@property (nonatomic, strong) NSString *subType;      /**< 字段13,subType ?*/
@property (nonatomic, strong) NSString *exceptionType;/**< 字段14,异常类型*/
@property (nonatomic, strong) NSString *appStack;     /**< 字段15,应用堆栈*/
@property (nonatomic, strong) NSString *vcStack;      /**< 字段16,VC堆栈*/
@property (nonatomic, strong) NSString *channelId;    /**< 字段17,渠道ID*/
@property (nonatomic, strong) NSString *packageType;  /**< 字段18,包类型*/
@property (nonatomic, strong) NSString *lastViewId;   /**< 字段19,上一个ViewId*/
@property (nonatomic, strong) NSString *viewId;       /**< 字段20,当前ViewId*/
@property (nonatomic, strong) NSString *pageSerialNo; /**< 字段21,页面流水号*/
@property (nonatomic, strong) NSString *trackId;      /**< 字段22,当前ACTIONID*/
@property (nonatomic, strong) NSString *trackToken;   /**< 字段23,当前ACTION_TOKEN*/
@property (nonatomic, strong) NSString *deviceModel;  /**< 字段24,手机型号*/
@property (nonatomic, strong) NSString *systemVersion;/**< 字段25,操作系统版本号*/
@property (nonatomic, strong) NSString *networkType;  /**< 字段26,网络类型*/
@property (nonatomic, strong) NSString *extension;    /**< 字段27,扩展信息*/
@property (nonatomic, strong) NSString *innerVersion; /**< 字段28,内部版本号*/
@property (nonatomic, strong) NSString *utdid;        /**< 字段29,utdid设备ID*/
@property (nonatomic, strong) NSString *language;     /**< 字段30,App语言*/
@property (nonatomic, strong) NSString *hpVersion;    /**< 字段31,hotpatch版本号*/
@property (nonatomic, strong) NSString *ebcContextInfo;/**< 字段32,虚拟机调用栈*/
@property (nonatomic, strong) NSString *threadName;   /**< 字段33,线程名 ？*/
@property (nonatomic, strong) NSString *javaOrNative; /**< 字段34,javaOrNative ？*/
@property (nonatomic, strong) NSString *apk;          /**< 字段35.Android独有,apk唯一ID*/
@property (nonatomic, strong) NSString *bootReason;   /**< 字段36.bootReason ?*/
@property (nonatomic, strong) NSString *foundationExtended; /**< 字段37.全局扩展字段*/
@property (nonatomic, strong) NSString *logSequenceId;/**< 字段38,日志序列号*/
@property (nonatomic, strong) NSString *logIDFA;      /**< 字段39,IDFA值*/

@end

@interface ATCrash (Compatibility)

+ (ATCrash *)crashWithStateDictionary:(NSDictionary *)dict;

@end
