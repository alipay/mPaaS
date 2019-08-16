//
//  MPaaSInterface+MPH5Demo_plugin.m
//  MPH5Demo_plugin
//
//  Created by vivi.yw on 2019/08/06.
//  Copyright © 2019 Alibaba. All rights reserved.
//

#import "MPaaSInterface+MPH5Demo_plugin.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wobjc-protocol-method-implementation"

@implementation MPaaSInterface (MPH5Demo_plugin)

- (BOOL)enableSettingService
{
    return NO;
}

- (NSString *)userId
{
    return @"admin";
}

@end

#pragma clang diagnostic pop
