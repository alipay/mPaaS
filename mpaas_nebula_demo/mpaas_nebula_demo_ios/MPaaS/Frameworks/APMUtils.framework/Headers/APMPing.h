//
//  ApmPing.h
//  Camera
//
//  Created by aspling on 16/5/19.
//  Copyright © 2016年 aspling. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface APMPing : NSObject
/**
 *  init函数
 *
 *  @param host ping的域名
 *
 *  @return
 */
- (instancetype)initWithHost:(NSString*)host;
/**
 *  开始ping,可指定ping次数
 *
 *  @param count ping次数，等于0则一直ping
 */
- (void)startPingWithCount:(NSUInteger)count;
/**
 *  结束ping
 */
- (void)stopPing;
@end
