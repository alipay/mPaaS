//
//  NSString+APMDeviceVersion.h
//  APMUtils
//
//  Created by Cloud on 2017/10/2.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (APMDeviceVersion)

- (NSComparisonResult)apm_compareWithVersion:(NSString *)version;

@end
