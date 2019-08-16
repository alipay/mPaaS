//
//  ISecurityGuardOpenAtlasEncrypt.h
//  SecurityGuardWhiteBox
//
//  Created by lifengzhong on 15/11/9.
//  Copyright © 2015年 Li Fengzhong. All rights reserved.
//

#ifndef ISecurityGuardOpenAtlasEncrypt_h
#define ISecurityGuardOpenAtlasEncrypt_h

#if TARGET_OS_WATCH
#import <SecurityGuardSDKWatch/Open/OpenAtlasEncrypt/IOpenAtlasEncryptComponent.h>
#import <SecurityGuardSDKWatch/Open/IOpenSecurityGuardPlugin.h>
#else
#import <SecurityGuardSDK/Open/OpenAtlasEncrypt/IOpenAtlasEncryptComponent.h>
#import <SecurityGuardSDK/Open/IOpenSecurityGuardPlugin.h>
#endif

@protocol ISecurityGuardOpenAtlasEncrypt <NSObject, IOpenAtlasEncryptComponent, IOpenSecurityGuardPluginInterface>

@end


#endif /* ISecurityGuardOpenAtlasEncrypt_h */
