//
//  DTSyncInterface.h
//  APLongLinkService
//
//  Created by cuinacai on 2017/4/20.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface DTSyncInterface : NSObject
+ (instancetype)sharedInstance;
/**
 *  Sync使用的应用Id，默认实现为
 *  [[[NSBundle mainBundle] infoDictionary] objectForKey:@"Product ID"]
 *
 *  @return 应用Id
 */
- (NSString*)productId;
/**
 *  Sync使用的应用版本号，默认实现为
 *  [[[NSBundle mainBundle] infoDictionary] objectForKey:@"Product Version"];;
 *
 *  @return 应用版本号
 */
- (NSString*)productVersion;
/**
 *  Sync使用的应用appId，默认实现为返回nil
 *
 *  @return appId
 */
- (NSString*)appId;
/**
 *  Sync使用的应用platform，默认实现为返回nil
 *
 *  @return platform
 */
- (NSString*)platform;
/**
 *  Sync使用的应用长连接端口，默认实现为返回0
 *
 *  @return syncport
 */
- (NSInteger)syncPort;
/**
 *  Sync使用的应用长连接host，默认实现为返回nil
 *
 *  @return syncserver
 */
- (NSString*)syncServer;
/**
 *  Sync使用的应用workspaceId，默认实现为返回nil
 *
 *  @return workspaceId
 */
- (NSString*)workspaceId;
@end
