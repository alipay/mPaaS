//
//  IOpenSecurityGuardPlugin.h
//  SecurityGuardSDK
//
//  Created by lifengzhong on 15/11/6.
//  Copyright © 2015年 Li Fengzhong. All rights reserved.
//

#ifndef IOpenSecurityGuardPlugin_h
#define IOpenSecurityGuardPlugin_h

#define PLUGIN_META_INFO_NAME                    @"name"
#define PLUGIN_META_INFO_VERSON                  @"version"
#define PLUGIN_META_INFO_PLATFORM                @"platform"
#define PLUGIN_META_INFO_DEPENDENCY              @"dependency"
#define PLUGIN_META_INFO_DEPENDENCY_NAME         @"dependency_name"
#define PLUGIN_META_INFO_DEPENDENCY_MIN_VERSION  @"dependency_min_version"
#define PLUGIN_META_INFO_DEPENDENCY_OPTIONAL     @"dependency_optional"
#define PLUGIN_META_INFO_RESOURCE                @"resource"
#define PLUGIN_META_INFO_RESOURCE_NAME           @"resource_name"
#define PLUGIN_META_INFO_RESOURCE_MIN_VERSION    @"resource_min_version"


#define PLUGIN_META_INFO_PLATFORM_UNI            @0
#define PLUGIN_META_INFO_PLATFORM_EXT            @1
#define PLUGIN_META_INFO_PLATFORM_INT            @2
#define PLUGIN_META_INFO_DEPENDENCY_OPTIONAL_YES @1
#define PLUGIN_META_INFO_DEPENDENCY_OPTIONAL_NO  @0

@protocol IOpenSecurityGuardPlugin <NSObject>

+ (NSDictionary*) getMetaInfo;

+ (void*) initializePlugin: (void *)pParam;

+ (void*) nativeEntry;

@end

@protocol IOpenSecurityGuardPluginInterface <NSObject>

- (Class<IOpenSecurityGuardPlugin>) getMetaClass;

@end

#endif /* IOpenSecurityGuardPlugin_h */
