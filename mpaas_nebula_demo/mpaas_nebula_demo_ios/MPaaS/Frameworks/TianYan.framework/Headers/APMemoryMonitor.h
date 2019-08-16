//
//  APMemoryMonitor.h
//  APOOMDetector
//
//  Created by Chenfeng on 18/11/29.
//  Copyright © 2019年 alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface APMemoryMonitor : NSObject

+ (instancetype)sharedInstance;

/*
NSDictionary *memoryInfo = @{
 
    //数值参考
    内存极限值：
        - 是苹果推荐的内存度量及优化的指标。而Memory Footprint的值达到Limit line时，就会触发内存警告，并进一步导致OOM
        - 参考值
            device:   (Footprint /Total/Percentage of total)
            iPhone4:  325MB    /512MB/63%
            iPhone4s: 286MB    /512MB/56%
            iPhone5:  645MB    /1024MB/62%
            iPhone5s: 646MB    /1024MB/63%
            iPhone6:  645MB    /1024MB/62%
            iPhone6+: 645MB    /1024MB/62%
            iPhone6s: 1396MB   /2048MB/68%
            iPhone6s+: 1392MB  /2048MB/68%
            iPhoneSE: 1395MB   /2048MB/69%
            iPhone7:  1395MB   /2048MB/68%
            iPhone7+: 2040MB   /3072MB/66%
            iPhone8:  1395MB   /2048MB/68%
            iPhone8+: 2040MB   /3072MB/66%

            iPhoneX:  1392MB      /2785/50%
            iPhoneXR: 1392MB      /2785/50%

            iPhoneXs:     2039MB     /3713/55%
            iPhoneXs-MAX: 2039MB     /3713/55%

 
    内存安全值：
        - 参考值：
            iPhone8P及以下： 内存总量 * 50%
            iPhoneX及以上：  内存总量 * 35%
 
    //当前进程占用的内存：和XCodeDebug面板上的内存数值一致，最主要的参考指标
    @"physFootprint":xxx,
 
    //当前设备空闲内存和总内存占比:数字越小代表当前设备可用内存越小
    @"systemMemoryLevel":xxx
 
    //从系统接口获取的设备空闲内存，结合上述分析其实比真实可用的偏小一些
    @"freeMemory":xxx,
 
    //当前进程占用的物理内存：高于XCodeDebug面板上的内存数值
        - resident memory= dirty memory+clean memory that loaded in physical memory
    @"residentMemory":xxx,
 
    //当前进程占用的虚拟内存
        - virtual memory = clean memory + dirty memory.
    @"virtualMemory":xxx,

    //当前进程，如钱包App本身占用的内存大小
    @"currentProcessMemory": xxx

};

 */
- (NSDictionary*)latestMemoryEvaluation;


//最近25次start/exit app 产生的内存变化日志
+ (NSString*)memoryTrackerLog;
@end
