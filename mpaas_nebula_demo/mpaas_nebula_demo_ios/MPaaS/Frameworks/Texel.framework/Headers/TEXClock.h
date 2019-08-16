//
//  TEXClock.h
//  Texel
//
//  Created by Cloud on 2017/6/10.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreMedia/CoreMedia.h>

@interface TEXClock : NSObject

+ (instancetype)sharedInstance;

- (CMTime)currentTimestamp;
- (CMTime)timestampFromHostTime:(uint64_t)hostTime;

@end
