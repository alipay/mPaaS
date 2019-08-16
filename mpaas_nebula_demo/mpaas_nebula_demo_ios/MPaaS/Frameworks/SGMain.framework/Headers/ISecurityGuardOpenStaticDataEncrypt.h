//
//  ISecurityGuardOpenStaticDataEncrypt.h
//  SecurityGuardMain
//
//  Created by lifengzhong on 15/11/10.
//  Copyright © 2015年 Li Fengzhong. All rights reserved.
//

#ifndef ISecurityGuardOpenStaticDataEncrypt_h
#define ISecurityGuardOpenStaticDataEncrypt_h

#if TARGET_OS_WATCH
#import <SecurityGuardSDKWatch/Open/OpenStaticDataEncrypt/IOpenStaticDataEncryptComponent.h>
#import <SecurityGuardSDKWatch/Open/OpenStaticDataEncrypt/OpenStaticDataEncryptDefine.h>
#import <SecurityGuardSDKWatch/Open/IOpenSecurityGuardPlugin.h>
#else
#import <SecurityGuardSDK/Open/OpenStaticDataEncrypt/IOpenStaticDataEncryptComponent.h>
#import <SecurityGuardSDK/Open/OpenStaticDataEncrypt/OpenStaticDataEncryptDefine.h>
#import <SecurityGuardSDK/Open/IOpenSecurityGuardPlugin.h>
#endif

@protocol ISecurityGuardOpenStaticDataEncrypt <NSObject, IOpenStaticDataEncryptComponent, IOpenSecurityGuardPluginInterface>

@end


#endif /* ISecurityGuardOpenStaticDataEncrypt_h */
