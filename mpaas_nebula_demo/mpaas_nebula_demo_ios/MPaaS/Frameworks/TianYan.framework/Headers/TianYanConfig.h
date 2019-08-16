//
//  TianYanConfig.h
//  TianYan
//
//  Created by myy on 16/4/18.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#define kFPSFirstLevelLagInterval   (0.1f)
#define kFPSSecondLevelLagInterval  (0.2f)
#define kFPSThirdLevelLagInterval   (0.5f)
#define kFPSFouthLevelLagInterval   (1.0f)

//#define kFPSLowLagInterval 0.2f
//#define kFPSMidLagInterval 0.5f
//#define kFPSHigLagInterval 1.f

#define kFPSFirstLevelLagWeight     (0.3f)
#define kFPSSecondLevelLagWeight    (1.f)
#define kFPSThirdLevelLagWeight     (1.5f)
#define kFPSFouthLevelLagWeight     (2.25f)


//#define kFPSLowLagWeight 1.f
//#define kFPSMidLagWeight 1.5f
//#define kFPSHigLagWeight 2.25f



/**
 *  天眼SDK配置参数的结构。
 */
@interface TianYanConfig : NSObject

/** 通用参数。客户端App的版本号。SDK用来区分App是否有版本变化。必须设置。 */
@property (nonatomic, strong) NSString* ClientVersion;

/** 通用参数。通用监控周期。SDK用来做电量消耗等的周期性指标计算。单位：秒。默认1800秒。可以不设置。 */
@property (nonatomic, assign) double MonitorPeriod;

/** 电量参数。是否开启CPU周期性检测。默认为YES。可以不设置 */
@property (nonatomic, assign) BOOL IsCPUCheck;

/** 内存参数。是否开启ViewController的内存泄漏检测。建议测试版本为YES。默认为NO。可以不设置 */
@property (nonatomic, assign) BOOL IsMemLeakCheckVCs;

/** 内存参数。如果开启了ViewController的内存泄漏检测，这里设置需要过滤掉的ViewController前缀。默认为空。可以不设置 */
@property (nonatomic, strong) NSArray* MemLeakCheckFilterVCs;

/** 存储参数。检查存储空间的周期性间隔值，到后台时判断检测。单位：秒。默认1800秒。可以不设置 */
@property (nonatomic, assign) int StorageCheckInterval;

/** 存储参数。检查存储空间时，配置的多媒体文件路径。可以不设置 */
@property (nonatomic, strong) NSArray* StorageCheckMultiMediaPaths;

/** 性能参数。是否开启性能周期性检测。默认为YES。可以不设置 */
@property (nonatomic, assign) BOOL IsPerformanceCheck;

/** 性能参数。传入当前productionVersion，作为使用卡顿捕获策略还是流畅度监控策略的依据，如果不传，则不监控*/
@property (nonatomic, strong) NSString *productionVersion;

/** 性能参数。传入当前UTDID，作为使用卡顿捕获策略还是流畅度监控策略的依据，如果不传，则不监控*/
//@property (nonatomic, strong) NSString *UTDID;

/** 性能参数。传入当前userId，作为使用卡顿捕获策略还是流畅度监控策略的依据，如果不传或者未登陆，则为流畅度监控策略*/
@property (nonatomic, strong) NSString *currentUserId;

/** 性能参数。传入当前UTDID，作为使用12306卡顿捕获策略还是流畅度监控策略的依据，如果不传或者未登陆，则为流畅度监控策略*/
@property (nonatomic, strong) NSString *UTDID;

// 性能参数。传入设定的筛选值，0-100，和上边的参数搭配使用，如果UTDID hash之后%100在productionVersion hash之后%100~传入的筛选值productionVersion hash之后%100 + lagMonitorTenPercent-1之间，则使用卡顿捕获策略，剩下的从再相应便宜fpsMonitorTenPercent使用流畅度监控策略，如果到100了，则转到0，不能有重叠部分，即两个值相加不能超过100
/** 性能参数，卡顿监控占比，以1%为单位，如果设为30，即30%*/
/* 该参数设置无用，目前策略是全量开启*/
@property (nonatomic, assign) NSUInteger lagMonitorTenPercent;

/** 性能参数，流畅度监控占比，以1%为单位，如果设为30，即30%*/
@property (nonatomic, assign) NSUInteger fpsMonitorTenPercent;

@end



