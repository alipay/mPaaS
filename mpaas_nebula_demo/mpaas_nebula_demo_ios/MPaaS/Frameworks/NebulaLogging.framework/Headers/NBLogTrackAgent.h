//
//  NBLogTrackAgent.h
//  NebulaLogging
//
//  Created by Glance on 16/11/4.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NBLogTrackAgent : NSObject<NBLogTrackAgentProtocol>

@end


/**
 为简化继承的复写成本，提供便捷方法
 */
@interface NBLogTrackAgent (convenience)

/**
 一个页面内存生命周期中，多次PV的刷新起始点（第一次起始由H5页面调用reportData触发）
 
 @param psdContext   Nebula框架中定义的上下文，可取到View/VC/Session等对象
 @param trackContext APReoteLogging组件上定义的上下文，可取到spmId，bizType等
 */
- (void)context:(PSDContext *)psdContext resumeStart:(APLogTrackContext *)trackContext;

/**
 PV的结束点，必须对应一次reportData或resumStart
 
 @param psdContext   Nebula框架中定义的上下文，可取到View/VC/Session等对象
 @param trackContext APReoteLogging组件上定义的上下文，可取到spmId，bizType等
 */
- (void)context:(PSDContext *)psdContext pageEnd:(APLogTrackContext *)trackContext;

@end

/*==================================Example======================================================================================================================*/

/* 继承复写示例 - 需求：页面销毁时才做PV统计
 * 默认实现为页面出现在用户视野一次即一次PV

@interface CustomTrackAgent : NBLogTrackAgent
@end

@implementation CustomTrackAgent

#pragma mark - NBLogTrackAgentProtocol
- (APLogTrackContext *)context:(PSDContext *)psdContext didReportData:(NSDictionary *)data
{
    // 该时机为通用pageMonitor开始时机，建议调用super实现
    return [super context:psdContext didReportData:data];
}


- (void)context:(PSDContext *)psdContext didDestroy:(APLogTrackContext *)trackContext
{
    // 对应reportData一次start, 此时为end, 完成成一个PV周期
    [super context:psdContext pageEnd:trackContext];
}
@end

*/
