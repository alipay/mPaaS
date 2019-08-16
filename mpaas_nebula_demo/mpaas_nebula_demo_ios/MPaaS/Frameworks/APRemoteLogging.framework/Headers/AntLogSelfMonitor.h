//
//  AntLogSelfMonitor.h
//  APRemoteLogging
//
//  Created by 卡迩 on 2017/8/11.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>


extern NSString *const kLogMonitorBizId;

#ifdef __cplusplus
extern "C" {
#endif
    /**
     * LogMonitor 本地日志
     */
    void AntLogMonitor(NSString *tag, NSString *format, ...);
    
    /**
     * LogMonitor 埋点
     */
    void AntLogRemoteMonitor(NSString *seed,NSArray *params);
#ifdef __cplusplus
}
#endif
