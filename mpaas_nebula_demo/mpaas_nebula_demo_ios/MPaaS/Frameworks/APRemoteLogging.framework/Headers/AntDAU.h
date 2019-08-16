//
//  AntDAU.h
//  APRemoteLogging
//
//  Created by 卡迩 on 2018/1/5.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
@class AntBehavior;

extern NSString *const kBizTypeDAU;

@interface AntDAU : NSObject

+ (AntDAU *)shared;

- (void)dauLog:(AntBehavior *)be
       handled:(BOOL *)handled;

@end
