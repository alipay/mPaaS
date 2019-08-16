//
//  DTRpcBaseOperation.h
//  APMobileNetwork
//
//  Created by WenBi on 13-5-21.
//  Copyright (c) 2013年 Alipay. All rights reserved.
//

#import "DTURLRequestOperation.h"

@interface DTRpcBaseOperation : DTURLRequestOperation

@property(nonatomic, strong) NSDictionary *responseJSON;
@property(nonatomic, strong) NSDictionary *resultJSON;
/** 是否走新协议的RPC*/
@property(nonatomic, assign) BOOL isAMRPC;
/** 是否ProtocolBuffers*/
@property(nonatomic, assign) BOOL isProtocolBuffers;
/** 是否NSData类型*/
@property(nonatomic, assign) BOOL isNSData;
@property(nonatomic, assign) BOOL isCDN;//是否走CDN
@property(nonatomic,strong)NSDictionary *addHeaders;
@property(nonatomic,strong)NSString *alertErr;//服务端控制提示弹的方式
-(NSMutableDictionary*)responseToDictionary:(NSHTTPURLResponse*)respo;
/**
 *  从返回的json中获取结果状态
 *
 *  @param responseJSON
 *
 *  @return yes/no
 */
-(BOOL)checkResultStatus:(NSDictionary *)responseJSON;
@end
