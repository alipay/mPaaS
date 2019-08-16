//
//  ISecurityGuardOpenOpenSDK.h
//  SecurityGuardTAE
//
//  Created by lifengzhong on 15/11/9.
//  Copyright © 2015年 Li Fengzhong. All rights reserved.
//

#ifndef ISecurityGuardOpenOpenSDK_h
#define ISecurityGuardOpenOpenSDK_h

#if TARGET_OS_WATCH
#import <SecurityGuardSDKWatch/Open/IOpenSecurityGuardPlugin.h>
#import <SecurityGuardSDKWatch/Open/OpenOpenSDK/IOpenOpenSDKComponent.h>
#else
#import <SecurityGuardSDK/Open/IOpenSecurityGuardPlugin.h>
#import <SecurityGuardSDK/Open/OpenOpenSDK/IOpenOpenSDKComponent.h>
#endif

@protocol ISecurityGuardOpenOpenSDK <NSObject, IOpenOpenSDKComponent, IOpenSecurityGuardPluginInterface>

@end

#endif /* ISecurityGuardOpenOpenSDK_h */
