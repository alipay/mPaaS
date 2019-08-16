//
//  MPaaS+MonitorStartUpTime.h
//  APMPaaS
//
//  Created by qiwei on 16/10/12.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#ifndef MPaaS_MonitorStartUpTime_h
#define MPaaS_MonitorStartUpTime_h

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

    /**
     全局变量，程序启动的开始时刻
     使用方法: 声明后使用，但不要修改
     系统时间时刻，随系统时间变化而变化
     实现原理： CFAbsoluteTimeGetCurrent()
     注：不建议使用
     */
    extern CFTimeInterval globalMonitorStartUpTime;

    /**
     全局变量，程序启动的开始时刻
     使用方法: 声明后使用，但不要修改
     相对开机时刻，不随系统时间变化而变化
     实现原理： CACurrentMediaTime()
     注：建议使用
     */
    extern CFTimeInterval globalRelativeStartUpTime;
    
    
    /**
     设置App启动的最早时刻。
     一般在主进程的第一个+load方法中设置。
     如果有自动链接的动态库，则建议放在第一个动态库的第一个+load方法中。
     */
    extern void MPStartupTimeMarkAppStartPoint();
    
    /**
     设置启动过程中的某个时刻，例如 main,didfinishlaunch,dbinit
     内部会减去app启动的最早时刻
     */
    extern void MPStartupTimeMarkAppPhase(const char *phaseName);
    
    /**
     设置启动过程中的某个时刻，例如 main,didfinishlaunch,dbinit
     内部会减去app启动的最早时刻，此方法多了开关控制
     */
    extern void MPStartupTimeWithConfigMarkAppPhase(const char *phaseName);
    
    /**
     设置启动过程中的某段时间的耗时，例如dbcost
     */
    extern void MPStartupTimeSetRangeCost(const char *rangeName,CFTimeInterval cost);
    
    /**
     辅助统计某段时间的耗时
     例如：
         MPStartupRangeCostStart(dbinit);
         //... db init code ...
         MPStartupRangeCostFinish(dbinit);
     */
    #define MPStartupTimeRangeCostStart(name)\
        CFTimeInterval _mpstartuptimeRangeStart##name = CACurrentMediaTime();
    
    #define MPStartupTimeRangeCostFinish(name)\
        CFTimeInterval _mpstartuptimeRangeFinish##name = CACurrentMediaTime();\
        MPStartupTimeSetRangeCost(#name,_mpstartuptimeRangeFinish##name - _mpstartuptimeRangeStart##name);
    
    /**
     Phase 启动的某一时刻（距离app启动的时间）
     Range 启动的某一段代码的耗时
     */
    typedef NS_ENUM(NSUInteger,MPStartupTimeDataType){
        MPStartupTimeData_Phase,
        MPStartupTimeData_Range,
    };
    
    /**
     遍历所有过程
     只能调用一次（后续调用没有数据）
     */
    extern void MPStartupTimeForEachData(void (^callback)(const char *name,CFTimeInterval value,MPStartupTimeDataType type));


#ifdef __cplusplus
}
#endif // __cplusplus

#endif /* MPaaS_MonitorStartUpTime_h */
