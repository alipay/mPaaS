//
//  APLLHTTPDNS.h
//  APLongLinkService
//
//  Created by cuinacai on 15/1/26.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol LLHTTPDNSOrigin<NSObject>
@property (nonatomic, strong) NSString *ip;
@property (nonatomic) in_port_t port;
@property (nonatomic) BOOL  isSPDY;
@end

@protocol LLHTTPDNSInterface <NSObject>
/*
 *当有错误发生时，需要把发生错误的域名告诉，否则没法在SPDY与HTTP协议中切换
 */
-(void)setError:(NSString*)host;

/*
 *获取Origin
 *Origin:
 *ip
 *port
 *isSPDY
 */
-(id<LLHTTPDNSOrigin>)getOriginByHost:(NSString*)host;
/*
 * ipv4转ipv6
 *
 */
-(NSString*)getIpV6OxcStringFromPointSepIpV4:(NSString*)v4;
/*
 * 判断是不是ipv6only环境
 *
 */
-(BOOL)netCardIpV6Only;
@end



@interface APLLHTTPDNS : NSObject<LLHTTPDNSInterface>
//单例
+(instancetype)sharedInstance;
/**
 *  httpDNS实现
 */
+(void)setLLHTTPDNS:(id<LLHTTPDNSInterface>)llHTTPDNS;
/**
 *  httpDNS开关, 默认关闭
 */
@property(nonatomic)BOOL httpDNSOpen;
@end

