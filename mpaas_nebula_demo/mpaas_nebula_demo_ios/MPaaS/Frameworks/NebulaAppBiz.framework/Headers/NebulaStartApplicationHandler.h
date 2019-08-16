//
//  NebulaStartApplicationHandler.h
//  NebulaAppBiz
//
//  Created by 扶瑶 on 16/11/29.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface NebulaStartApplicationHandler : NSObject <DTStartApplicationHandler, NebulaStartHandlerProtocol>

+ (BOOL)isNebulaHanlerProcessed:(DTMicroApplication *)application params:(NSDictionary *)params;
+ (NSMutableDictionary *)updateHandlerAsProcessed:(DTMicroApplication *)application params:(NSDictionary *)params;

@end
