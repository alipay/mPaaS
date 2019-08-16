//
//  NPCustomFileManager.h
//  NebulaPlugins
//
//  Created by theone on 16/10/19.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NPCustomFileManager : NSObject
+ (BOOL)clearAppTempFilesWithAppId:(NSString *)appId;
+ (NSString *)getCustomMainFlodPath;
+ (NSString *)getAppSavedFlodNameWithAppId:(NSString *)appId;
+ (NSString *)getAppTempFlodNameWithAppId:(NSString *)appId;
@end
