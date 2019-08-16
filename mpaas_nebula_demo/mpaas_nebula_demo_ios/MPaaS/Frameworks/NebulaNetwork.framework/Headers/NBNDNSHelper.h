//
//  NBNDNSHelper.h
//  NebulaNetwork
//
//  Created by runfeng.crf on 2019/2/26.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

//复制于NebulaBiz/H5DNSHelper
@interface NBNDNSHelper : NSObject

+ (void)getIPAddressWithHost:(NSString *)host complete:(void (^)(NSString *ipAddress))complete;

/**
 *  获取IP地址中的最后一个地址
 *
 *  @param addresses
 *
 *  @return
 */
+ (NSString*)getAddressFromArray:(CFArrayRef)addresses;

@end
