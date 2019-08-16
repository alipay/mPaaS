//
//  ISecurityGuardOpenStaticDataStore.h
//  SecurityGuardMain
//
//  Created by lifengzhong on 15/11/7.
//  Copyright © 2015年 Li Fengzhong. All rights reserved.
//

#ifndef ISecurityGuardOpenStaticDataStore_h
#define ISecurityGuardOpenStaticDataStore_h

#if TARGET_OS_WATCH
#import <SecurityGuardSDKWatch/Open/OpenStaticDataStore/IOpenStaticDataStoreComponent.h>
#import <SecurityGuardSDKWatch/Open/OpenStaticDataStore/OpenStaticDataStoreDefine.h>
#import <SecurityGuardSDKWatch/Open/IOpenSecurityGuardPlugin.h>
#else
#import <SecurityGuardSDK/Open/OpenStaticDataStore/IOpenStaticDataStoreComponent.h>
#import <SecurityGuardSDK/Open/OpenStaticDataStore/OpenStaticDataStoreDefine.h>
#import <SecurityGuardSDK/Open/IOpenSecurityGuardPlugin.h>
#endif

@protocol ISecurityGuardOpenStaticDataStore <NSObject, IOpenStaticDataStoreComponent, IOpenSecurityGuardPluginInterface>
@end


#endif /* ISecurityGuardOpenStaticDataStore_h */
