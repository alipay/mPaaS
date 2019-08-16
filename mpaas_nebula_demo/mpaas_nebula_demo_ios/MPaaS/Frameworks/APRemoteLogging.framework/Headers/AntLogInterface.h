//
//  AntLogInterface.h
//  APRemoteLogging
//
//  Created by 卡迩 on 2017/2/10.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#ifndef AntLogInterface_h
#define AntLogInterface_h
#import "AntLogInterceptor.h"

@protocol AutoTrackInfo;
@protocol AutoTrackerObserver;
@protocol ABTestInfoProvider;

////////////////////////////////////////////////////////////////////////////////

#pragma mark -
#pragma mark 埋点外部接口

@protocol AntLogInterface <NSObject>

@required
/**
 触发特定业务类型的日志立即上报

 @param bizType 待上报日志的业务类型
 */
- (void)triggerUploadForBizType:(NSString *)bizType;

/**
 触发特定业务类型的日志立即上报到指定的服务器地址.
 
 @param bizType 待上报日志的业务类型
 @param url 服务器地址的字符串形式. 传\c nil 时默认上报到mdap.
 @note url指定的服务端必须实现与mdap(Owner @望乡 @尚清)同样的日志上报接口.
 */
- (void)triggerUploadForBizType:(NSString *)bizType
                            url:(NSString *)url;

/**
 触发特定业务类型的日志立即上报到指定的服务器地址.
 
 @param bizType 待上报日志的业务类型
 @param event 触发上报的事件
 @param url 服务器地址的字符串形式. 传\c nil 时默认上报到mdap.
 @note url指定的服务端必须实现与mdap(Owner @望乡 @尚清)同样的日志上报接口.
 */
- (void)triggerUploadForBizType:(NSString *)bizType
                          event:(NSString *)event
                            url:(NSString *)url;

/**
 触发所有日志立即上报到指定服务器地址

 @param event 触发上报的事件,用于埋点上报监控
 @param url 服务器地址,传\c nil 时默认上报到mdap.
 */
- (void)triggerUploadAllForEvent:(NSString *)event
                             url:(NSString *)url;

/**
 注入自动化埋点的监听者
 @see \c AutoTrackerObserver
 
 @param observer 自动化埋点监听者对象. 埋点SDK内部只会弱引用该对象.
 */
- (void)setAutoTrackerObserver:(id<AutoTrackerObserver>)observer;

/**
 获取自动化埋点监听者对象(若有)
 */
- (id<AutoTrackerObserver>)getAutoTrackerObserver;

/**
 注入ABTest信息提供者
 @see \c ABTestInfoProvider
 
 @param provider ABTest信息提供者对象. 埋点SDK内部只会弱引用该对象.
 */
- (void)setABTestInfoProvider:(id<ABTestInfoProvider>)provider;

/**
 获取ABTest信息提供者对象(若有)
 */
- (id<ABTestInfoProvider>)getABTestInfoProvider;

/**
 注入埋点拦截器,用于拦截埋点写入和上报行为.

 @param interceptor 埋点拦截器. 埋点SDK内部会强引用该对象. @see AntLogInterceptor
 */
- (void)setInterceptor:(id<AntLogInterceptor>)interceptor;


- (id<AntLogInterceptor>)interceptor;

@end

#ifdef __cplusplus
extern "C" {
#endif
    
    /**
     获取埋点外部接口实例对象
     
     @return 埋点外部接口实例
     */
    id<AntLogInterface> AntLogInterfaceGet();
    
#ifdef __cplusplus
}
#endif

////////////////////////////////////////////////////////////////////////////////

#pragma mark - 
#pragma mark 自动化埋点回调

/**
 自动化埋点回调中附加的事件信息.
 */
@protocol AutoTrackInfo <NSObject>

/**
 获取自动化埋点事件产生的控件XPath.
 */
- (NSString *)xpath;

/**
 获取自动化埋点事件产生时的时间.
 */
- (NSDate *)timestamp;

@end


/**
 自动化埋点回调接口
 */
@protocol AutoTrackerObserver <NSObject>

@optional
/**
 自动化点击事件的回调接口

 @param info 点击事件的信息. @see \c AutoTrackInfo
 */
- (void)onAutoClick:(id<AutoTrackInfo>)info;

/**
 自动化页面打开事件的回调接口
 @note 页面事件是在页面关闭时落埋点,该回调是在页面关闭时回调.

 @param info 页面打开事件的信息. @see \c AutoTrackInfo
 */
- (void)onAutoOpenPage:(id<AutoTrackInfo>)info;

@end

////////////////////////////////////////////////////////////////////////////////

#pragma mark -
#pragma mark ABTest

/**
 ABTest实验信息提供者接口
 */
@protocol ABTestInfoProvider <NSObject>

@required
/**
 通过Spm Id 查询ABTest实验信息.

 @param spmId 待查询的SpmId
 @return 该 \c spmId 命中的实验列表组成的字符串. 若 \c spmId 未命中任何实验,则返回 \c nil.
 */
- (NSString *)abTestInfoForSpmId:(NSString *)spmId;

/**
 通过Spm Id 查询ABTest附加信息

 @param spmId 待查询的SpmId
 @return 该 \c spmId 命中的附加信息组成的map. 若 \c spmId 未命中任何附加信息,则返回 \c nil.
 */
- (NSDictionary *)abTestExtInfoForSpmId:(NSString *)spmId;

@end

#endif /* AntLogInterface_h */
