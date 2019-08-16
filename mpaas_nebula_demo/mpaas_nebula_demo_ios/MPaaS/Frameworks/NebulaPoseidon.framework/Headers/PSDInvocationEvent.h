//
//  PSDInvocationEvent.h
//  Poseidon
//
//  Created by chenwenhong on 14-8-11.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import "PSDEvent.h"
#import "PSDJsApi.h"

@interface PSDInvocationEvent : PSDEvent

@property(nonatomic, readonly, copy) NSString                           *invocationName;
@property(nonatomic, readonly, strong) NSDictionary                     *invocationData; //当前携带的数据对象
@property(nonatomic, strong) NSDictionary                               *invocationResult; // 返回结果
@property(nonatomic, readonly, copy) NSString                           *url;
@property(nonatomic, readonly, strong) PSDJsApi                         *jsApi;
@property(nonatomic, readonly, strong) PSDJsApiResponseCallbackBlock    responseCallback;
@property(nonatomic, copy) NSString                                     *invocationSource;//调用来源
@property(nonatomic, assign) BOOL                                       shouldSkipCallback;//是否跳过执行responseCallback
+ (instancetype)allEvent:(NSString *)invocationName url:(NSString *)url;

// can preventDefault
+ (instancetype)startEvent:(NSString *)invocationName
            invocationData:(NSDictionary *)invocationData
                       url:(NSString *)url;

// can preventDefault and can invoke custom yourself(you should set invocationResult to responseCallback)
+ (instancetype)invokeEvent:(NSString *)invocationName
             invocationData:(NSDictionary *)invocationData
                        url:(NSString *)url
                      jsApi:(PSDJsApi *)jsApi
           responseCallback:(PSDJsApiResponseCallbackBlock)responseCallback;

+ (instancetype)completeEvent:(NSString *)invocationName
             invocationResult:(NSDictionary *)invocationResult
                          url:(NSString *)url  DEPRECATED_ATTRIBUTE; // 废弃方法，请使用下面方法

+ (instancetype)completeEvent:(NSString *)invocationName
               invocationData:(NSDictionary *)invocationData
             invocationResult:(NSDictionary *)invocationResult
                          url:(NSString *)url;

+ (instancetype)errorEvent:(NSString *)invocationName url:(NSString *)url;

+ (instancetype)startEvent:(NSString *)invocationName
                 eventData:(NSDictionary *)invocationData
                       url:(NSString *)url;

+ (instancetype)invokeBeforeEvent:(NSString *)invocationName
             invocationData:(NSDictionary *)invocationData
                        url:(NSString *)url
                      jsApi:(PSDJsApi *)jsApi
                 responseCallback:(PSDJsApiResponseCallbackBlock)responseCallback;

+ (instancetype)invokePermitEvent:(NSString *)invocationName
                   invocationData:(NSDictionary *)invocationData
                              url:(NSString *)url
                            jsApi:(PSDJsApi *)jsApi
                 responseCallback:(PSDJsApiResponseCallbackBlock)responseCallback;
@end
