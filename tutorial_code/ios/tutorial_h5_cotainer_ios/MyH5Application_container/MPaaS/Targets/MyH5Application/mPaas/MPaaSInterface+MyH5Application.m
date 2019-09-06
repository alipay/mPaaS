//
//  MPaaSInterface+MyH5Application.m
//  MyH5Application
//
//  Created by Evan on 2019/08/22.
//  Copyright © 2019 Alibaba. All rights reserved.
//

#import "MPaaSInterface+MyH5Application.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wobjc-protocol-method-implementation"

@implementation MPaaSInterface (MyH5Application)

- (BOOL)enableSettingService
{
    return NO;
}

- (NSString *)userId
{
    return nil;
}

@end

#pragma clang diagnostic pop
