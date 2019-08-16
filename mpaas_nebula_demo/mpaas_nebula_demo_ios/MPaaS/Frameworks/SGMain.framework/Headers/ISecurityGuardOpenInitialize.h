//
//  ISecurityGuardOpenInitialize.h
//  SecurityGuardMain
//
//  Created by lifengzhong on 15/11/12.
//  Copyright © 2015年 Li Fengzhong. All rights reserved.
//

#ifndef ISecurityGuardOpenInitialize_h
#define ISecurityGuardOpenInitialize_h

#if TARGET_OS_WATCH
#import <SecurityGuardSDKWatch/Open/OpenInitialize/IOpenInitializeComponent.h>
#import <SecurityGuardSDKWatch/Open/IOpenSecurityGuardPlugin.h>
#else
#import <SecurityGuardSDK/Open/OpenInitialize/IOpenInitializeComponent.h>
#import <SecurityGuardSDK/Open/IOpenSecurityGuardPlugin.h>
#endif

@protocol ISecurityGuardOpenInitialize <NSObject, IOpenInitializeComponent, IOpenSecurityGuardPluginInterface>

@end


#endif /* ISecurityGuardOpenInitialize_h */
