//
//  NBDebugAppDefine.h
//  NebulaDebug
//
//  Created by 扶瑶 on 2017/6/29.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#pragma mark - params

extern NSString *const NBDEBUG_APP_NBSOURCE;
extern NSString *const NBDEBUG_APP_NBSOURCE_DEBUG;

extern NSString *const NBDEBUG_APP_NBSTRICTVERSION;
extern NSString *const NBDEBUG_APP_NBSCENE;
extern NSString *const NBDEBUG_APP_ID;
extern NSString *const NBDEBUG_APP_NBPREFER;
extern NSString *const NBDEBUG_APP_NBTOKEN;

extern NSString *const NBDebugAddDebugItemNotification;
extern NSString *const NBDebugVerifyResultNotification;
extern NSString *const NBDebugStatusUpdateNotification;

#pragma mark - App Manager

extern NSString *const NBDebugKeyVersion;
extern NSString *const NBDebugKeyScene;
extern NSString *const NBDebugKeyAppId;
extern NSString *const NBDebugKeyDebugItem;
extern NSString *const NBDebugKeyVerifyResult;
extern NSString *const NBDebugKeyParams;

@interface NADOptions : NSObject
@property (strong, nonatomic) NSString *appId;
@property (strong, nonatomic) NSString *scene;
@property (strong, nonatomic) NSString *version;
@property (strong, nonatomic) NSString *nbtoken;
@property (assign, nonatomic) BOOL isDebugSource;
@property (assign, nonatomic) BOOL isPrefer;
@property (assign, nonatomic) BOOL hasVerified;

+ (NADOptions *)optinsWithParams:(NSDictionary *)params;

@end
