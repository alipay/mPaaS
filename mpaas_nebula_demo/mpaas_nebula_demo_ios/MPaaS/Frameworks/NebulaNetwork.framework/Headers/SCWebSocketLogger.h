//
//  SCWebSocketLogger.h
//  SocketCraft
//
//  Created by yangxiao on 2017/2/27.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

#define LOG_TYPE_CONN @"conn"
#define LOG_TYPE_DISCONN @"disconn"
#define LOG_TYPE_ERROR @"error"

@interface SCWebSocketLogger : NSObject

+(void)logWithContentDic:(NSDictionary*)dic type:(NSString*)type;

+(void)localLogInfo:(NSString*)param;

@end
