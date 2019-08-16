//
//  H5PingHelper.h
//  H5Service
//
//  Created by theone on 14-6-16.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SimplePing.h"

@interface H5PingResult : NSObject
@property(nonatomic, assign) float consumedTimeMs;
@property(nonatomic, assign) float loss;
@property(nonatomic, strong) NSMutableArray *timePerRound;
@property(nonatomic, strong) NSString *networkType;
@property(nonatomic, assign) long long timeStamp;
- (NSDictionary *)pingResult;
@end

@interface H5PingHelper : NSObject<SimplePingDelegate>
@property(nonatomic, copy) void (^callback)(H5PingResult *);
+ (void)pingWithHost:(NSString *)host
               times:(int)times
           useCashed:(BOOL)useCashed
            callback:(void (^)(H5PingResult *))callback;
@end

