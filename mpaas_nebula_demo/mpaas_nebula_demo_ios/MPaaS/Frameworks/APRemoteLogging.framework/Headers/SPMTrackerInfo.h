//
//  SPMTrackerInfo.h
//  APRemoteLogging
//
//  Created by BoTao on 2017/7/5.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

#ifndef SPMTrackerInfo_h
#define SPMTrackerInfo_h

#define TRACKER_HEADER_PAGETS @"pagets"
#define TRACKER_HEADER_SSPM @"srcSpm"
#define TRACKER_HEADER_LSPM @"lastClickSpm"

__deprecated_msg("请使用SPMTracker.framework中的SPMTrackerInfo")
@interface SPMTrackerInfo : NSObject
/**
 * 获取钱包全局最后一次点击的spmid
 *
 */
+ (NSString *)lastClickedSpmId;

/**
 * 更新全局lastClickSpm，H5容器专用，其他业务禁止调用
 *
 *  @param spmId:新的spmId
 */
+ (void)setLastClickSpm:(NSString *)spmId;

/**
 * 更新srcSpm
 *
 *  @param spmId:新的spmId
 *  @param index:page索引
 **/
+ (void)updateSrcSpm:(NSString *)spmId index:(NSObject *)index;

/**
 * 更新lastSpm
 *
 *  @param spmId:新的spmId
 *  @param index:page索引
 **/
+ (void)updateLastSpm:(NSString *)spmId index:(NSObject *)index;

/**
 *  获取TracerInfo
 *
 *  @param index:pageid索引,通常传入当前VC对象即可
 *
 *  @return 包含miniPageId，srcSpm，lastClickSpm的dict
 **/
+ (NSDictionary *)getTracerInfo:(NSObject *)index;

/**
 *  判断index对象是否已调用过pageStart，且未调用过pageEnd
 *
 *  @param index:pageid索引,通常传入当前VC对象即可
 *
 *  @return YES=已调用
 **/
+ (BOOL)isPageStarted:(NSObject *)index;

@end
#endif
