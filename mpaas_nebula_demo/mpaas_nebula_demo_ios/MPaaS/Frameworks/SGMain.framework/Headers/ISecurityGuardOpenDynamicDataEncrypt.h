//
//  ISecurityGuardOpenDynamicDataEncrypt.h
//  SecurityGuardMain
//
//  Created by lifengzhong on 15/11/10.
//  Copyright © 2015年 Li Fengzhong. All rights reserved.
//

#ifndef ISecurityGuardOpenDynamicDataEncrypt_h
#define ISecurityGuardOpenDynamicDataEncrypt_h

#if TARGET_OS_WATCH
#import <SecurityGuardSDKWatch/Open/OpenDynamicDataEncrypt/IOpenDynamicDataEncryptComponent.h>
#import <SecurityGuardSDKWatch/Open/IOpenSecurityGuardPlugin.h>
#else
#import <SecurityGuardSDK/Open/OpenDynamicDataEncrypt/IOpenDynamicDataEncryptComponent.h>
#import <SecurityGuardSDK/Open/IOpenSecurityGuardPlugin.h>
#endif

@protocol ISecurityGuardOpenDynamicDataEncrypt <NSObject, IOpenDynamicDataEncryptComponent, IOpenSecurityGuardPluginInterface>

@end


#endif /* ISecurityGuardOpenDynamicDataEncrypt_h */
