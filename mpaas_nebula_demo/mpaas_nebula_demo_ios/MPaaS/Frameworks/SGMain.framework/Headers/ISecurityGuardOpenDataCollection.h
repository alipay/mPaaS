//
//  ISecurityGuardOpenDataCollection.h
//  SecurityGuardMain
//
//  Created by lifengzhong on 15/11/10.
//  Copyright © 2015年 Li Fengzhong. All rights reserved.
//

#ifndef ISecurityGuardOpenDataCollection_h
#define ISecurityGuardOpenDataCollection_h

#if TARGET_OS_WATCH
#import <SecurityGuardSDKWatch/Open/OpenDataCollection/IOpenDataCollectionComponent.h>
#import <SecurityGuardSDKWatch/Open/IOpenSecurityGuardPlugin.h>
#else
#import <SecurityGuardSDK/Open/OpenDataCollection/IOpenDataCollectionComponent.h>
#import <SecurityGuardSDK/Open/IOpenSecurityGuardPlugin.h>
#endif

@protocol ISecurityGuardOpenDataCollection <NSObject, IOpenDataCollectionComponent, IOpenSecurityGuardPluginInterface>

@end


#endif /* ISecurityGuardOpenDataCollection_h */
