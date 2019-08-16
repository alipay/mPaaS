//
//  PSDProxyEvent.h
//  Poseidon
//
//  Created by chenwenhong on 14-11-4.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import "PSDEvent.h"

@class PSDResponse;

@interface PSDProxyEvent : PSDEvent

@property(nonatomic, readonly, copy) NSString       *uniqueId;
@property(nonatomic, readonly, copy) NSString       *channelId;
@property(nonatomic, strong) NSURLRequest           *request; // 当前的请求对象
@property(nonatomic, strong) NSURLRequest           *origRequest; // 当前请求为重定向时，指向上个请求
@property(nonatomic, readonly, strong) NSDate       *requestDate; // 请求时间
@property(nonatomic, strong) NSURLResponse          *response; // 响应对象
@property(nonatomic, readonly, strong) NSDate       *responseDate; // 响应时间
@property(nonatomic, strong) NSData                 *receiveData; // 生效：kEvent_Proxy_Request_ReceiveData、kEvent_Proxy_Request_FinishReceiveData、kEvent_Proxy_Request_Finish；当event为kEvent_Proxy_Request_FinishReceiveData时，仅mimeType是：text/html、image/png、image/jpg、application/javascript、application/json、text/css时才有
@property(nonatomic, readonly, strong) NSError      *error;
@property(nonatomic, assign) BOOL                   willRedirectRequest; // 生效：kEvent_Proxy_Request_Start_Handler、kEvent_Proxy_Request_Response_Handler
@property(nonatomic, assign) BOOL                   willHoldReceiveData; // 生效：kEvent_Proxy_Request_ReceiveData
@property(nonatomic, assign) NSUInteger             receiveDataLength; // 生效：kEvent_Proxy_Request_Finish
@property(nonatomic, readonly, strong) PSDResponse  *customResponse;
@property(nonatomic, strong) NSURLSessionTask       *task;
@property(nonatomic, strong) NSURLSessionTaskMetrics *metrics API_AVAILABLE(macosx(10.12), ios(10.0), watchos(3.0), tvos(10.0)); 

//处理request
+ (instancetype)requestHandlerEvent:(NSURLRequest *)request
                        requestDate:(NSDate *)requestDate
                     customResponse:(PSDResponse *)customResponse
                          channelId:(NSString *)channelId;

+ (instancetype)startLoadEvent:(NSURLRequest *)request
                   requestDate:(NSDate *)requestDate
                      uniqueId:(NSString *)uniqueId
                     channelId:(NSString *)channelId;

//将要重定向
+ (instancetype)willRedirectEvent:(NSURLRequest *)request
                      origRequest:(NSURLRequest *)origRequest
                 redirectResponse:(NSURLResponse *)response
                     redirectDate:(NSDate *)redirectDate
                         uniqueId:(NSString *)uniqueId
                        channelId:(NSString *)channelId;

//处理response、重定向
+ (instancetype)responseHandler:(NSURLRequest *)request
                       response:(NSURLResponse *)response
                    requestDate:(NSDate *)requestDate
                   responseDate:(NSDate *)responseDate
                      channelId:(NSString *)channelId;

//处理response
+ (instancetype)receiveResponse:(NSURLResponse *)response
                        request:(NSURLRequest *)request
                    requestDate:(NSDate *)requestDate
                   responseDate:(NSDate *)responseDate
                       uniqueId:(NSString *)uniqueId
                      channelId:(NSString *)channelId;

//处理分段data
+ (instancetype)receiveDataEvent:(NSURLRequest *)request
                        response:(NSURLResponse *)response
                     receiveData:(NSData *)data
                        uniqueId:(NSString *)uniqueId
                       channelId:(NSString *)channelId;

//处理data
+ (instancetype)finishReceiveDataEvent:(NSURLRequest *)request
                              response:(NSURLResponse *)response
                           requestDate:(NSDate *)requestDate
                          responseDate:(NSDate *)responseDate
                           receiveData:(NSData *)data
                                 error:(NSError *)error
                              uniqueId:(NSString *)uniqueId
                             channelId:(NSString *)channelId;

+ (instancetype)finishLoadEvent:(NSURLRequest *)request
                       response:(NSURLResponse *)response
                    requestDate:(NSDate *)requestDate
                   responseDate:(NSDate *)responseDate
                    receiveData:(NSData *)receiveData
              receiveDataLength:(NSUInteger)receiveDataLength
                          error:(NSError *)error
                       uniqueId:(NSString *)uniqueId
                      channelId:(NSString *)channelId;

+ (instancetype)finishCollectingMetricsEvent:(NSURLSessionTaskMetrics *)metrics
                                     request:(NSURLRequest *)request
                                    response:(NSURLResponse *)response
                                        task:(NSURLSessionTask *)task
                                    uniqueId:(NSString *)uniqueId
                                   channelId:(NSString *)channelId API_AVAILABLE(macosx(10.12), ios(10.0), watchos(3.0), tvos(10.0));

+ (instancetype)requestCancelEvent:(NSURLRequest *)request
                             error:(NSError *)error
                       requestDate:(NSDate *)requestDate
                          uniqueId:(NSString *)uniqueId
                         channelId:(NSString *)channelId;

@end
