//
//  ISecurityGuardOpenStaticKeyEncrypt.h
//  SecurityGuardTAE
//
//  Created by lifengzhong on 15/11/9.
//  Copyright © 2015年 Li Fengzhong. All rights reserved.
//

#ifndef ISecurityGuardOpenStaticKeyEncrypt_h
#define ISecurityGuardOpenStaticKeyEncrypt_h

#if TARGET_OS_WATCH
#import <SecurityGuardSDKWatch/Open/IOpenSecurityGuardPlugin.h>
#import <SecurityGuardSDKWatch/Open/OpenStaticKeyEncrypt/IOpenStaticKeyEncryptComponent.h>
#import <SecurityGuardSDKWatch/Open/OpenStaticKeyEncrypt/OpenStaticKeyEncryptDefine.h>
#else
#import <SecurityGuardSDK/Open/IOpenSecurityGuardPlugin.h>
#import <SecurityGuardSDK/Open/OpenStaticKeyEncrypt/IOpenStaticKeyEncryptComponent.h>
#import <SecurityGuardSDK/Open/OpenStaticKeyEncrypt/OpenStaticKeyEncryptDefine.h>
#endif

@protocol ISecurityGuardOpenStaticKeyEncrypt <NSObject, IOpenStaticKeyEncryptComponent, IOpenSecurityGuardPluginInterface>

@end


#endif /* ISecurityGuardOpenStaticKeyEncrypt_h */
