//
//  TYPowerDetailInfo.h
//  TianYan
//
//  Created by NianXi on 16/2/25.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TYPowerDetailInfo : NSObject
+ (void)doTYLoadWork;

@property (nonatomic, assign, readonly) NSUInteger locationCount;
@property (nonatomic, strong, readonly) NSDictionary *threadsCostDic;
@property (nonatomic, strong, readonly) NSNumber *processTime;
@property (nonatomic, assign, readonly) NSUInteger fetchCount;
@property (nonatomic, assign, readonly) NSUInteger healthCount;
@property (nonatomic, assign, readonly) NSUInteger hotspotCount;
@end
