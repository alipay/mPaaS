//
//  NPContext.h
//  NebulaAppBiz
//
//  Created by 扶瑶 on 16/2/18.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NebulaAppDefine.h"

@class NADownloadManager;
@class NAZipArchiveManager;
@class NADataStorage;
@class NARequestManager;
@class NAAppInterface;
@class NAConfigManager;
@class NASyncCenter;
@class NACreditCenter;
@class NABloodManager;
@class NADService;
@interface NAContext : NSObject
@property (nonatomic, weak) id<NADebugProtocol> debugManager;

+ (NAContext *)shared;

+ (NADownloadManager *)downloadManager;
+ (NAZipArchiveManager *)zipArchiveManager;
+ (NARequestManager *)requestManager;
+ (NADataStorage *)dataStorage;
+ (NAAppInterface *)appInterface;
+ (NAConfigManager *)configManager;
+ (NASyncCenter *)syncCenter;
+ (id<NADebugProtocol>)debugManager;
+ (NACreditCenter *)creditCenter;
+ (NABloodManager *)bloodManager;
+ (NADService *)debugAppService;

@end
