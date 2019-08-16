//
//  MergerExposureLogManage.h
//  SPMTracker
//
//  Created by BoTao on 2017/4/6.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

#ifndef MergerExposureLogManage_h
#define MergerExposureLogManage_h

NS_ASSUME_NONNULL_BEGIN

extern NSString* const kConfigTime;
extern NSString* const kConfigArea;

/////////////////////////////////////////////////////////////////////////////////////
@protocol MergerExposureLogProtocel <NSObject>

//上报曝光埋点
-(void)uploadMergerExposureLogWithSeedId:(NSString *)seedId
                               entityId:(NSString *)entityId
                                bizCode:(NSString *)bizCode
                              extParams:(NSDictionary *)param
                                    view:(nullable NSObject *)view
                                  pageId:(nullable NSString *)pageId
                               logLevel:(NSString *)logLevel;

@end



/////////////////////////////////////////////////////////////////////////////////////
@interface MergerExposureLogManage : NSObject

@property (nonatomic, strong) id<MergerExposureLogProtocel> logProtocol;

/*
 *  延时曝光
 *  解决列表元素曝光需求，每个元素不会重复曝光，储存曝光日志，达到上报条件时，多条曝光日志合并后上报埋点
 *
 *  @param spmId: 埋点SPMID
 *  @param entityId entityId需要从埋点平台找@望乡 申请
 *  @param rid: RPC唯一标示，可以时tracerid、recommondid等
 *  @param pos: cell索引号，类似SPMID的N
 *  @param extParams: 其他扩展参数，既原埋点第四位的扩展参数
 *  @param view: 对应ViewController，view、pageId必须有一个不为空
 *  @param pageId: 对应ViewController的pageId，view、pageId必须有一个不为空
 */
- (void)writeMergerExposureLogWithSeedId:(NSString *)seedId
                                entityId:(NSString *)entityId
                                     rid:(NSString *)rid
                                position:(NSString *)pos
                                 bizCode:(NSString *)bizCode
                               extParams:(NSDictionary *)extParams
                                    view:(nullable NSObject *)view
                                  pageId:(nullable NSString *)pageId
                                logLevel:(NSString *)logLevel ;

/*
 * 立即上报，业务需要在vc的viewWillDisappear中调用，否则曝光埋点可能未上报
 *
 *  @param spmId: 埋点SPMID，取前a、b位，所有匹配spmid都上报
 *  @param view: 对应ViewController，view、pageId必须有一个不为空
 *  @param pageId: 对应ViewController的pageId，view、pageId必须有一个不为空
 */
- (void)commiteMergerExposureLogWithSpmId:(nullable NSString *)spmId
                                     view:(nullable NSObject *)view
                                   pageId:(nullable NSString *)pageId;

/*
 *  类方法，触发所有MergerExposureLogManage实例上报
 *
 *  @param seedId: 埋点SPMID，取前a、b位，所有匹配seedId都上报
 *  @param view: 对应ViewController，view、pageId必须有一个不为空
 *  @param pageId: 对应ViewController的pageId，view、pageId必须有一个不为空
 */
+ (void)commiteAllMergerExposureLogWithSpmId:(nullable NSString *)seedId
                                        view:(nullable NSObject *)view
                                      pageId:(nullable NSString *)pageId;

@end
NS_ASSUME_NONNULL_END

#endif
