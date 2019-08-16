//
//  APThreadTaskMonitor.h
//  APMobileFoundation
//
//  Created by llb on 2018/6/26.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum APThreadTaskMonitorUptimeType{
    APThreadTaskMonitorUptimeTypeEE = 1,  // 早于分析开始&早于分析结束  E:early L:later
    APThreadTaskMonitorUptimeTypeEL,      // 早于分析开始&晚于分析结束
    APThreadTaskMonitorUptimeTypeLE,      // 晚于分析开始&早于分析结束
    APThreadTaskMonitorUptimeTypeLL,      // 晚于分析开始&晚于分析结束
} APThreadTaskMonitorUptimeType;


@interface APThreadMonitorDetailInfo : NSObject

@property (nonatomic, strong) NSString* name;     //线程名，如果不存在则使用queue的名字
@property (nonatomic, assign) int tid;            //线程id
@property (nonatomic, assign) long state;         //线程状态，参见宏定义 运行中:TH_STATE_RUNNING 1
@property (nonatomic, assign) long uptime;        //记录线程信息时间
@property (nonatomic, assign) long userUseTime;   //user运行时长(毫秒)
@property (nonatomic, assign) long sysUseTime;    //sys运行时长(毫秒)
@property (nonatomic, assign) long sleepTime;     //休眠时间
@property (nonatomic, assign) int priority;       //线程优先级
@property (nonatomic, assign) int nice;           //线程实际优先级
@property (nonatomic, assign) int cpu_usage;      //cpu使用量

@end

@interface APThreadTaskInfo : NSObject

@property (nonatomic, strong) NSString   *taskId;
@property (nonatomic, assign) NSUInteger biz;
@property (nonatomic, strong) NSString   *tag;
@property (nonatomic, assign) int tid;
@property (nonatomic, assign) long startTime;
@property (nonatomic, assign) long endTime;
@property (nonatomic, assign) long startAnalysisTime;
@property (nonatomic, assign) long endAnalysisTime;
@property (nonatomic, assign) APThreadTaskMonitorUptimeType uptimeType;
@property (nonatomic, strong) APThreadMonitorDetailInfo* startDetail;
@property (nonatomic, strong) APThreadMonitorDetailInfo* endDetail;

@end


@interface APThreadTaskMonitor : NSObject

+ (dispatch_block_t)addThreadTask:(NSUInteger)biz tag:(const char *)tag block:(dispatch_block_t)block;
+ (void)startMonitorTasksInfo;
+ (void)endMonitorTasksInfo;
+ (NSString *)threadTasksDetail;

@end
