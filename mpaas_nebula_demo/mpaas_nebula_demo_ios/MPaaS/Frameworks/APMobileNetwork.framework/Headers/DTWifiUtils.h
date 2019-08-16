//
//  DTWifiUtils.h
//  APMobileNetwork
//
//  Created by 孟嵩 on 15/11/2.
//  Copyright © 2015年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface DTWifiUtils : NSObject
/**
 *  获取ssidinfo
 */
+ (NSDictionary *)fetchSSIDInfo;
/**
 *  wifi是否连接
 */
+(BOOL)isWifiConnected;
/**
 *  网络切换时刷新ssidinfo
 */
+(void)refreshSSIDInfo;
@end
