//
//  APLogSpmUtils.h
//  APRemoteLogging
//
//  Created by majie on 16/8/3.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString *const kPageIdSuffix;

@interface APLogSpmUtils : NSObject

+ (NSString *)pageIdWithSeparator:(NSString *)separator forSpmid:(NSString *)spmid;
+ (NSString*)c10to64:(UInt64)i;

@end
