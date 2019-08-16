//
//  AntLogConfigManager.h
//  APRemoteLogging
//
//  Created by 卡迩 on 2017/12/13.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AntLogLevel.h"
#import "ISampleControl.h"

extern NSUInteger const kDefaultMaxLogCount;

@class ATConfig;

#ifdef SDK_IS4_ALIPAY
@class ATRealtimeLogConfig;
@class ATDelayUploadConfig;

#endif

/**
 * 埋点配置管理器
 */
@interface ATConfigMgr : NSObject

#ifdef SDK_IS4_ALIPAY
@property (nonatomic, strong) ATRealtimeLogConfig *realtimeConfig;
@property (nonatomic, strong) ATDelayUploadConfig *delayUploadConfig;

#endif

- (NSDictionary<NSString *,ATConfig *> *)allBizConfigs;

- (ATConfig *)configForBiz:(NSString *)bizType;

- (void)refreshConfig:(BOOL)force extInfo:(NSDictionary *)info;

- (void)setExtConfigValue:(NSString *)value
                   forKey:(NSString *)key;

-(void)setExtConfigDict:(NSDictionary *)configDict;

- (NSString *)extConfigValueForKey:(NSString *)key;

- (void)recalculateSampleControl;

- (void)notifyDidFinishLaunching:(__unused NSDictionary *)info;

-(BOOL)inDelayTime;

@end

@interface ATConfigMgr ()

@property (atomic, assign) BOOL httpsDisabled;
@property (atomic, assign) BOOL lengthLimitDisabled;
@property (atomic, assign) BOOL delayUpload;/**< 蓄洪功能开关*/
@property (atomic, assign) BOOL fullLink;/**< 全链路监控功能开关*/
@property (atomic, assign) BOOL customLog;/**< 自定义日志功能开关*/
@property (atomic, assign) BOOL verifySwitch;/**< 验证功能开关*/
@property (atomic, assign) BOOL floodRate;/**< 削峰率开关*/
@property (atomic, assign) BOOL periodUpload;/**< 间隔上传开关*/
@property (atomic, assign) NSInteger periodInterval;/**< 轮询间隔*/
@property (atomic, assign) BOOL failDelay;/**< 失败后上传间隔开关*/
@property (atomic, assign) BOOL emptyTask;/**< 空任务修复开关*/
@end

////////////////////////////////////////////////////////////////////////////////

@interface ATConfig : NSObject

@property (nonatomic, assign) NSUInteger maxLogCount;       /**< 条数上报阈值*/
@property (nonatomic, strong) NSArray *sendNetEnvs;         /**< 可上报的网络类型集合*/
@property (nonatomic, strong) NSArray *events;              /**< 可上报的原因集合*/
@property (nonatomic, assign) AntLogLevel level;            /**< 最低可写入的日志等级*/
@property (nonatomic, assign) BOOL write;                   /**< 是否写入*/
@property (nonatomic, assign) BOOL encrypt;                 /**< 是否加密*/
@property (nonatomic, assign) BOOL realtime;                /**< 是否实时通道上报*/
@property (nonatomic, assign) BOOL usemetds;                /**< 是否走metds域名上报*/
@property (nonatomic, assign) NSInteger periodInterval;    /**< 上传时间间隔*/
@property (nonatomic, strong) ISampleControl *sampleControl;/**< 抽样控制策略*/
@property (nonatomic, strong) DelayControl *delayControl;   /**< 削峰控制策略*/

+ (ATConfig *)defaultConfig;

+ (ATConfig *)configWithDictionary:(NSDictionary *)dict;

- (BOOL)netEnvValid;

@end


#ifdef SDK_IS4_ALIPAY
@interface ATRealtimeLogConfig : NSObject

@property (nonatomic, assign) BOOL enabled;
@property (nonatomic, assign) NSTimeInterval timerInterval;

@end

@interface ATDelayUploadConfig : NSObject

@property(nonatomic,strong) NSMutableDictionary* floodTime;/**< 蓄洪开启时间为key 泄洪时间为value 可以配置多个 泄洪时间 单位 100ms*/
@property(nonatomic,assign) uint64_t minDelay;/**< 蓄洪最小持续时间 单位秒*/
@property(nonatomic,assign) uint64_t maxDelay;/**< 蓄洪最大持续时间 单位秒*/
@property(nonatomic,strong) NSString* currDesc;/**< 削峰配置当前描述*/
@property(nonatomic,strong) NSString* lastDesc;/**< 削峰上次配置的描述*/
@end

#endif

