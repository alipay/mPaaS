//
//  APSecurityUtilImpl.h
//  APSecurityUtility
//
//  Created by NianXi on 14-9-24.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <dlfcn.h>
#import <mach-o/dyld.h>

typedef struct {
    BOOL (*isDebugging)(const char **args);
    BOOL (*isExternalCall)(void *ret_addr);
    BOOL (*isSwizzlingClassMethod)(NSString *className, SEL sel);
    BOOL (*isSwizzlingInstanceMethod)(NSString *className, SEL sel);
    BOOL (*isJailbroken)(const char **args);
    BOOL (*hasPIE)(const char **args);
    BOOL (*isEncrypted)(const char **args);
    BOOL (*isRiskyEnv)(const char **args); //包含越狱和非越狱环境的PIE和二进制加密标志检测逻辑
    BOOL (*isSwizzlingUIKitInstanceMethod)(NSString *className, SEL sel);
    NSString * (*getTextSectionDigest)();
    BOOL (*isLinkerFlagExisted)(const char **args);
    BOOL (*isInternalNotification)(NSString *name);
    BOOL (*isSwizzlingLocalAuthInstanceMethod)(NSString *className, SEL sel);
    NSDictionary * (*getInjectInfo)();
    NSDictionary * (*baseInfo)();
}security_struct;

#define APSecurityUtilImpl [_APSecurityUtilImpl shared]

@interface _APSecurityUtilImpl : NSProxy

+ (security_struct *)shared;

@end
