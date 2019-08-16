//
//  TYMemoryMonitor.h
//  TianYan
//
//  Created by taoyuan on 15/8/14.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface TYMemoryMonitor : NSObject
+(instancetype)shareMemMonitor;
- (void)startMonitor;
- (NSDictionary *)caculateHealthRate;
- (NSDictionary *)memoryInfoWithKey:(NSString *)key;

@end
