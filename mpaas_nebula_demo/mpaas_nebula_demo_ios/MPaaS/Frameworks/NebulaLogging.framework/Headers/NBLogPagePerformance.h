//
//  NBLogPagePerformance.h
//  H5Service
//
//  Created by chenwenhong on 14-10-17.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <NebulaSDK/NBContentViewPageProfile.h>

#define kReportErrorRequest     @"errorRequest"
#define kReportErrorResponse    @"errorResponse"
#define kReportLongRender       @"longRender"
#define kReportErrorRender      @"errorRender"
#define kReportByUser           @"userReport"
#define kReportByJS             @"jsReport"

@interface NBLogPerformanceTiming : NSObject

@property(nonatomic, assign) NSTimeInterval requestStart;
@property(nonatomic, assign) NSTimeInterval responseEnd;

@end

@interface NBLogPagePerformance : NBContentViewPageProfile

@property(nonatomic, readonly)   NSString *errorType; //异常类型
@property(nonatomic, copy)   NSDictionary *generateFirst; // 页面打开时记录，防止页面结束时无法取到正确数据
@property(nonatomic, readonly)   NBLogPerformanceTiming *performanceTiming;// 未使用
@property(nonatomic, readonly)   BOOL loadWithSPDY; // 是否启用了SPDY
@property(nonatomic, copy)       NSString *fromType; // 页面打开类型　startApp/pushWindow/hrefChange
@property(nonatomic, assign) NSTimeInterval startTime; // 开始请求时间
@property(nonatomic, strong)   NSMutableDictionary *filterJsapiDict;
@property(nonatomic, strong)   NSMutableDictionary *normalJsapiDict;


// 用于记录连续请求的发起 对应 stopLoading字段 SDK内部默认hook资源请求和rpc/openRpc两个jsapi调用
- (void)reportReqStart;
- (void)reportReqEnd;

// 用于记录连续请求及定位的发起 对应 stopLoadingWithoutLocating字段 SDK内部未hook定位过程
- (void)reportLocStart;
- (void)reportLocEnd;

- (void)reportCreateDate:(NSDate *)date; // 上报页面创建时间
- (void)reportRenderTime:(NSDate *)date; // 上报页面开始渲染时间(白屏点)
- (void)reportDidFinishedLoadDate:(NSDate *)date; // 上报页面加载完成时间(同步资源请求完成)

// 由注入JS自动采集
- (void)reportJSMonitor:(NSArray *)monitorData;
- (void)reportJSReport:(NSArray *)monitorData;

// 由SDK内部在页面离开时上报
- (void)reportPerformance;
- (void)reportPageAbnormal;
- (void)reportPageAbnormalWithErrorType:(NSString *)errorType andErrorCode:(NSString *)errorCode;
- (void)reportPageAbnormalWithErrorType:(NSString *)errorType withError:(NSError *)error;


- (void)reportValue:(id)value forKey:(NSString *) key;


@end
