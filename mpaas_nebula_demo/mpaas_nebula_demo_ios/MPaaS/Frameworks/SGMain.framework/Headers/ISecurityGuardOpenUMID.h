//
//  ISecurityGuardOpenUMID.h
//  SecurityGuardMain
//
//  Created by lifengzhong on 15/11/10.
//  Copyright © 2015年 Li Fengzhong. All rights reserved.
//

#ifndef ISecurityGuardOpenUMID_h
#define ISecurityGuardOpenUMID_h

#if TARGET_OS_WATCH
#import <SecurityGuardSDKWatch/Open/OpenUMID/IOpenUMIDComponent.h>
#import <SecurityGuardSDKWatch/Open/IOpenSecurityGuardPlugin.h>
#else
#import <SecurityGuardSDK/Open/OpenUMID/IOpenUMIDComponent.h>
#import <SecurityGuardSDK/Open/IOpenSecurityGuardPlugin.h>
#endif

@protocol ISecurityGuardOpenUMID <NSObject, IOpenUMIDComponent, IOpenSecurityGuardPluginInterface>


@end


#endif /* ISecurityGuardOpenUMID_h */
