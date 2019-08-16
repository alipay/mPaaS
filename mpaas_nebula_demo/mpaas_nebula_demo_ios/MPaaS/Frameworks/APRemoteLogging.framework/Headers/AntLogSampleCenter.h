//
//  APLogSampleControl.h
//  APBusinessCommon
//
//  Created by 卡迩 on 2017/5/19.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AntLogLevel.h"
#import "ISampleControl.h"
@class DelayControl;
NS_ASSUME_NONNULL_BEGIN
extern NSString *const kAntLogSampleRateKey;
extern NSString *const kAntLogLevelRate1Key;
extern NSString *const kAntLogLevelRate2Key;
extern NSString *const kAntLogLevelRate3Key;
extern NSString *const kMaxSampleRateString;
/**
 日志抽样策略控制中心.
 */
@interface AntLogSampleCenter : NSObject

/**
 获取日志抽样策略控制单例.
 
 @return 日志抽样策略控制单例
 */
+ (AntLogSampleCenter *)defaultCenter;

/**
 输入抽样比例，当前设备、当天、某个抽样比例下是否命中抽样群体.
 
 @param rate 抽样比例，正整数，范围为0～1000，即抽样精度为千分之一.
 @return 命中抽样群体时返回 \c YES, 否则返回 \c NO.
 */
- (BOOL)shouldSampleForRate:(unsigned long long)rate;

/**
 输入抽样比例，查询该比例下当前的抽样控制信息.
 
 @param rate 抽样比例，正整数，范围为0～1000，即抽样精度为千分之一.
 @return 指定抽样比例下的抽样控制信息对象.
 */
- (nullable ISampleControl *)controlForSampleRate:(unsigned long long)rate;

/**
 输入抽样控制参数，查询该参数下的抽样控制信息

 @param params 抽样控制参数，至少包含整体抽样率、level1抽样率、level2抽样率、level3抽样率中一个
 @return 指定抽样控制参数下的抽样控制信息对象. 当控制参数不符合要求时返回 \c nil.
 */
- (nullable ISampleControl *)controlForParams:(NSDictionary *)params;


/**
 输入削峰比例，查询改比例下当前的削峰命中情况

 @param params rate 削峰比例，正整数，范围为0～1000，即削峰精度为千分之一.
 @return 指定削峰比例下的削峰控制信息对象.
 */
-(nullable DelayControl *)controlForDelayRate:(NSDictionary *)params;

@end

////////////////////////////////////////////////////////////////////////////////

NS_ASSUME_NONNULL_END
