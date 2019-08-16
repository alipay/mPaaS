//
//  H5TransitionsHandler.h
//  NebulaBiz
//
//  Created by Glance on 2018/7/5.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PSDSession+coupleProcess.h"

typedef NS_ENUM(NSInteger, H5OPENURLFROMTYPE) {
    H5OPENURLFROMTYPEUnKnown,
    H5OPENURLFROMTYPEDownLoad
};

@interface H5TransitionsHandler : NSObject

+ (BOOL)shouldOpenURL:(NSString *)url appId:(NSString *)appId from:(H5OPENURLFROMTYPE)fromType;
+ (BOOL)unifyOpenURL:(NSURL *)url sceneParams:(NSDictionary *)sceneParams fromWebView:(PSDContentView *)contentView;

+ (BOOL)unifyStartApplication:(NSString *)name params:(NSDictionary *)params animated:(BOOL)animated sceneParams:(NSDictionary *)sceneParams;
+ (BOOL)unifyStartApplication:(NSString *)name params:(NSDictionary *)params launchMode:(DTMicroApplicationLaunchMode)launchMode sceneParams:(NSDictionary *)sceneParams;
+ (BOOL)unifyStartApplication:(NSString *)name
                  params:(NSDictionary *)params
             appClearTop:(BOOL)appClearTop
              launchMode:(DTMicroApplicationLaunchMode)launchMode
                sourceId:(NSString *)sourceId
                  sceneParams:(NSDictionary *)sceneParams;

+ (BOOL)unifyStartApplication:(NSString *)name
                       params:(NSDictionary *)params
                  appClearTop:(BOOL)appClearTop
                   launchMode:(DTMicroApplicationLaunchMode)launchMode
                     sourceId:(NSString *)sourceId
                  sceneParams:(NSDictionary *)sceneParams
                  fromSession:(PSDSession *)fromSession
                    readyTask:(PSDSessionAccessoryReadyTask)saveTask
                     saveTask:(PSDSessionAccessorySaveTask)saveTask
                  destroyTask:(PSDSessionAccessoryDestroyTask)destroyTask;

@end
