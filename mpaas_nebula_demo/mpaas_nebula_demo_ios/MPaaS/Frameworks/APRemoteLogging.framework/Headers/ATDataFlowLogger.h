//
//  ATDataFlowLogger.h
//  APRemoteLogging
//
//  Created by 卡迩 on 2018/7/2.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import "ATLogger.h"
#import "ATDataFlow.h"

/**
 * 流量监控埋点Logger
 */
@interface ATDataFlowLogger : ATLogger

/**
 * 流量监控
 * @param dataFlow 流量监控参数对象 @see \c ATDataFlow
 */
- (void)recordDataFlow:(ATDataFlow *)dataFlow;

@end

#ifdef __cplusplus
extern "C" {
#endif
    
    /**
     * 获取流量监控Logger实例
     */
    ATDataFlowLogger * ATDataFlowLoggerGet();
    
#ifdef __cplusplus
}
#endif
