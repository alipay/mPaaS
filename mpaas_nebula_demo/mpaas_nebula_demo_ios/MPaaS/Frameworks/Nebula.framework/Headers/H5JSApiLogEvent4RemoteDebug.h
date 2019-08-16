//
//  PSDJSApiRemoteLogEvent.h
//  Nebula
//
//  Created by runfeng.crf on 2018/8/30.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <NebulaPoseidon/NebulaPoseidon.h>

#define kH5Event_JSApi_Log_Error @"jsapi.log.error"
#define kH5Event_JSApi_Log_HttpRequest @"jsapi.log.httpRequest"

@interface H5JSApiLogEvent4RemoteDebug : PSDEvent

@property (nonatomic, strong) NSString *jsApiName;
@property (nonatomic, assign) NSInteger errorCode;
@property (nonatomic, assign) NSInteger subCode;
@property (nonatomic, strong) NSString *message;
@property (nonatomic, strong) NSString *desc;
@property (nonatomic, weak) PSDContext *psdContext;

+ (instancetype)errorEventWithName:(NSString *)jsApiName
                              code:(NSInteger)errorCode
                           subCode:(NSInteger)subCode
                           message:(NSString *)message
                              desc:(NSString *)desc
                           context:(PSDContext *)context;

@end


@interface H5JSApiLogEventHttpRequest : PSDEvent

@property (nonatomic, strong) NSURLRequest *request;
@property (nonatomic, strong) NSHTTPURLResponse *response;
@property (nonatomic, strong) NSData *responseData;
@property (nonatomic, strong) NSError *error;
@property (nonatomic, strong) NSDate *requestTime;

+ (instancetype)eventWithRequest:(NSURLRequest *)request
                        response:(NSHTTPURLResponse *)response
                    responseData:(NSData *)data
                           error:(NSError *)error
                     requestTime:(NSDate *)requestTime;

@end
