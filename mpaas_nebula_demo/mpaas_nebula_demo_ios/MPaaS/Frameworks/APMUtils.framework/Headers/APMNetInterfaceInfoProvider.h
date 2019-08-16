//
//  NetInterfaceInfoProvider.h
//  NetInterface
//
//  Created by yangxiao on 16/5/31.
//  Copyright © 2016年 ppp. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <netinet/in.h>

// 使用该库前先把这个通知搞统一，这个通知就是网络切换的通知，改成自己平台对应的key就行了
#define APM_NET_ACCESS_CHANGE_NOTICE_KEY @"APMNetReachabilityDidChangeNotification"

/**
 *  IPv6网络判断类,提供了
 */
@interface APMNetInterfaceInfoProvider : NSObject

/**
 *  单例
 *
 *  @return
 */
+ (APMNetInterfaceInfoProvider*)shareInstance;

/**
 *  调此方法判断该手机此时使用的默认网卡是否为IPV6的
 *
 *  @return
 */
- (BOOL)defaultNetInterfaceV6Only;

/**
 *  将点分式ipv4地址转换为冒号分隔的ipv6地址
 *
 *  @param ipv4 点分ipv4地址
 *
 *  @return ipv6地址，可能为nil，不带中括号
 */
- (NSString*)translateIpV6FromV4:(NSString*)ipv4;

/**
 *  给BSDSocket使用的方法，获取需要bind的本地地址，因为对于bsdsocket，要使用ipv6地址，必须客户端bind本地的ipv6地址
 *  调用了defaultNetInterfaceV6Only方法返回的是YES时，bsdsocket建连就需要调用这个方法，取得本地ipv6地址，然后bind这个地址，才能connect成功
 *
 *  @return ipv6的bsd address
 */
- (struct sockaddr_in6*)getDefaultNetInterfaceV6OnlyAddress;

@end
