//
//  PSDConfiguration.h
//  NebulaPoseidon
//
//  Created by chenwenhong on 15/10/12.
//  Copyright © 2015年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol PSDLoggerProtocol;
@class WKWebViewConfiguration;

@interface PSDConfiguration : NSObject

@property(nonatomic, readonly, copy) NSString      *sdkVersion;
@property(nonatomic, copy) NSString      *pluginsBundleName;
@property(nonatomic, copy) NSString      *extraPluginsFilePath;
@property(nonatomic, weak) id<PSDLoggerProtocol> logger;
@property(nonatomic, strong) WKWebViewConfiguration *wkConfiguration;
@property(nonatomic, assign) BOOL        shouldUseJSCInjectJS;
@property(nonatomic, assign) BOOL        shouldSyncWKCookie;
//@property(nonatomic, assign) BOOL        enableJsApiReapair;
//@property(nonatomic, assign) BOOL        enableCheckReadPlist;
@property(nonatomic, assign) BOOL        shouldUseNewMethodSyncWKCookie;
@property(nonatomic, assign) NSUInteger  maxRouterUrlLogLength;
@property(nonatomic, assign) BOOL        shouldCallJSAPIWithToken;
@property(nonatomic, assign) BOOL        shouldCallJSAPIWithService;
@property(nonatomic, copy) NSString      *rewriteBridgeContent;
@property(nonatomic, strong) NSArray     *jsapiBlackList; //register jsapi black list
@property(nonatomic, strong) NSArray     *pluginsBlackList; //register plugins black list
@property(nonatomic, assign) BOOL        shouldUseUrlSchemeHandler; //iOS11 scheme handler

@property(nonatomic, assign) BOOL        shouldFixUIWebViewBridge; //iOS iframe bridge problem
@property (nonatomic, weak) NSThread   *customURLProtocolThread;  //CustomURLProtocol线程

@property(nonatomic, assign) BOOL        shouldCancelInjectJS;
@property(nonatomic, assign) BOOL        shouldThrowJSExcuteException;
@property(nonatomic, assign) BOOL        shouldPSDViewDeallocUseMainThread;
@property(nonatomic, assign) BOOL        forceKernelSubObjectMainThreadDealloc;
@property(nonatomic, strong) NSArray<NSString *> *subObjectMainThreadDeallocKernelNames;
@property(nonatomic, assign) BOOL        shouldRedirectHSTS;
@property (nonatomic, assign) BOOL       shouldFixCFNetorkCrash;
@property (nonatomic, assign) BOOL       shouldLogInURLProtocol;


+ (instancetype)defaultConfiguration;

//禁止创建实例
+ (instancetype)alloc UNAVAILABLE_ATTRIBUTE;

- (instancetype)init UNAVAILABLE_ATTRIBUTE;

- (id)copy UNAVAILABLE_ATTRIBUTE;

+ (instancetype)allocWithZone:(struct _NSZone *)zone UNAVAILABLE_ATTRIBUTE;

+ (instancetype)new UNAVAILABLE_ATTRIBUTE;

@end

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
    
    PSDConfiguration * PSDConfigurationGet();
    
#ifdef __cplusplus
}
#endif // __cplusplus
