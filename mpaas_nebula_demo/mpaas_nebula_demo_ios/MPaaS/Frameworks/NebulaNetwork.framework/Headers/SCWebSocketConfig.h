//
//  SCWebSocketConfig.h
//  SocketCraft
//
//  Created by yangxiao on 2017/2/21.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SCWebSocketConfig : NSObject

@property (nonatomic) NSDictionary*     conf;

-(NSInteger)configDefaultTimeoutMS;

-(NSArray*)configDomainList;

-(NSInteger)configMaxTimeoutMS;

-(NSInteger)configTimeoutMS;

@end
