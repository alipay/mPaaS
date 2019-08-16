//
//  ISampleControl.h
//  APRemoteLogging
//
//  Created by 卡迩 on 2017/9/28.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AntLogLevel.h"

/**
 抽样控制信息类.
 */
@interface ISampleControl : NSObject

/**
 是否应该采样，即当前设备、当前时刻在指定抽样比例下是否命中采样群体.
 */
@property (nonatomic, assign) BOOL shouldSample;

/**
 整体抽样比例，正整数，范围为0～1000，即抽样精度为千分之一.
 */
@property (nonatomic, assign) unsigned long long rate;

@end


@interface ISampleControl (/*分级别抽样*/)
/**
 level1抽样比例，正整数，范围为0～1000，即抽样精度为千分之一.
 */
@property (nonatomic, assign) unsigned long long level1Rate;

/**
 level2抽样比例，正整数，范围为0～1000，即抽样精度为千分之一.
 */
@property (nonatomic, assign) unsigned long long level2Rate;

/**
 level3抽样比例，正整数，范围为0～1000，即抽样精度为千分之一.
 */
@property (nonatomic, assign) unsigned long long level3Rate;

/**
 level1的日志是否应该采样，即当前设备、当前时刻在指定抽样比例下是否命中采样群体.
 */
@property (nonatomic, assign) BOOL shouldSampleLevel1;

/**
 level2的日志是否应该采样，即当前设备、当前时刻在指定抽样比例下是否命中采样群体.
 */
@property (nonatomic, assign) BOOL shouldSampleLevel2;

/**
 level3的日志是否应该采样，即当前设备、当前时刻在指定抽样比例下是否命中采样群体.
 */
@property (nonatomic, assign) BOOL shouldSampleLevel3;

- (BOOL)shouldSampleForLevel:(AntLogLevel)level;

- (unsigned long long)rateForLevel:(AntLogLevel)level;

@end


@interface DelayControl : NSObject

/**
 是否命中削峰
 */
@property (nonatomic, assign) BOOL shouldDelay;

/**
 削峰比例，正整数，范围为0～1000，即削峰精度为千分之一.
 */
@property (nonatomic, assign) unsigned long long delayRate;

@end
