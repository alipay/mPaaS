//
//  SCWebSocketConfigMgr.h
//  SocketCraft
//
//  Created by yangxiao on 2017/2/22.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SCWebSocketConfig.h"

@interface SCWebSocketConfigMgr : NSObject

@property (atomic) NSDictionary* configJson;

+(instancetype)shareInstance;

-(void)freshConfig:(NSDictionary*)conf;

-(SCWebSocketConfig*)getConfigForAppID:(NSString*)appid;

@end
