//
//  ISecurityGuardOpenSecureSignature.h
//  SecurityGuardMain
//
//  Created by lifengzhong on 15/11/10.
//  Copyright © 2015年 Li Fengzhong. All rights reserved.
//

#ifndef ISecurityGuardOpenSecureSignature_h
#define ISecurityGuardOpenSecureSignature_h

#if TARGET_OS_WATCH
#import <SecurityGuardSDKWatch/Open/OpenSecureSignature/IOpenSecureSignatureComponent.h>
#import <SecurityGuardSDKWatch/Open/OpenSecureSignature/OpenSecureSignatureDefine.h>
#import <SecurityGuardSDKWatch/Open/IOpenSecurityGuardPlugin.h>
#import <SecurityGuardSDKWatch/Open/OpenSecurityGuardParamContext.h>
#else
#import <SecurityGuardSDK/Open/OpenSecureSignature/IOpenSecureSignatureComponent.h>
#import <SecurityGuardSDK/Open/OpenSecureSignature/OpenSecureSignatureDefine.h>
#import <SecurityGuardSDK/Open/IOpenSecurityGuardPlugin.h>
#import <SecurityGuardSDK/Open/OpenSecurityGuardParamContext.h>
#endif

@protocol ISecurityGuardOpenSecureSignature <NSObject>

@end

#endif /* ISecurityGuardOpenSecureSignature_h */
