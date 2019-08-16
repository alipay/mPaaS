//
//  MPLiteSettingService.h
//  APMPaaS
//
//  Created by shenmo on 6/3/16.
//  Copyright © 2016 Alipay. All rights reserved.
//

@protocol MPLiteSettingServiceClass <NSObject>

+ (NSString*)getRPCGateway;
+ (NSString*)getRPCProductId;

+ (NSString*)getRemoteLogGateway;
+ (NSString*)getRemoteLogProductId;

+ (NSString*)getSyncGateway;
+ (NSString*)getSyncPort;
+ (NSString*)getMpaasGateway;
+ (NSString*)getAppId;
+ (NSString*)getWorkspaceId;
+ (NSString*)getAppkey;
+ (NSString *)getProductId;

@end
