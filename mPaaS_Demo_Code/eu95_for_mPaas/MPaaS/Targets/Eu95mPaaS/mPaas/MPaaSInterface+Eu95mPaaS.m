//
//  MPaaSInterface+Eu95mPaaS.m
//  Eu95mPaaS
//
//  Created by fengguanhua on 2024/04/17. All rights reserved.
//

#import "MPaaSInterface+Eu95mPaaS.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wobjc-protocol-method-implementation"

@implementation MPaaSInterface (Eu95mPaaS)

- (BOOL)enableSettingService
{
    return NO;
}

- (NSString *)userId
{
    return @"Eu95mPaaS";
}

@end

#pragma clang diagnostic pop



@implementation MPSignatureInterface (Eu95mPaaS)

-(MPSecurityComponentType)securityComponentType{
    return MPSecurityComponentTypeBS;
}


@end
