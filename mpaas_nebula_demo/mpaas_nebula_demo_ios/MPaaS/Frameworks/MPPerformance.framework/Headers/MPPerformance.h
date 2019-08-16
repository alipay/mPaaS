//
//  MPPerformanceInterface.h
//  MPPerformance
//
//  Created by yemingyu on 12/7/16.
//  Copyright © 2016 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MPPerformance : NSObject

//启动性能监控
+ (void)startPerformanceMonitor;

// 设置电量消耗的统计时间，默认为1800秒，也就是应用累计使用一个小时，将电量使用情况上报一次。最小设置值为300秒, 设置为0或不设置都是默认1800秒
+ (void)setBatteryMonitorPeriod:(NSTimeInterval)seconds;

@end
