//
//  APConfigLongLinkHandler.h
//  APConfig
//
//  Created by majie on 15/11/27.
//  Copyright © 2015年 WenBi. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface APConfigLongLinkHandler : NSObject

+ (void)registerMessage:(NSString *)message;
+ (void)checkStartListenMessage;

@end
