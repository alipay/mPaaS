//
//  SGMain.h
//  SecurityGuardMain
//
//  Created by lifengzhong on 2016/12/29.
//  Copyright © 2016年 Li Fengzhong. All rights reserved.
//

#ifndef SGMain_h
#define SGMain_h

#import <Foundation/Foundation.h>

 

#ifdef _SG_INTERNAL_VERSION_

#import "ISecurityGuardSafeToken.h"
#import "ISecurityGuardInitialize.h"
#import "ISecurityGuardDataCollection.h"
#import "ISecurityGuardStaticDataStore.h"
#import "ISecurityGuardStaticDataEncrypt.h"
#import "ISecurityGuardDynamicDataEncrypt.h"
#import "ISecurityGuardDynamicDataStore.h"
#import "ISecurityGuardSecureSignature.h"
#import "ISecurityGuardAtlasEncrypt.h"

#endif

#import "ISecurityGuardOpenSafeToken.h"
#import "ISecurityGuardOpenInitialize.h"
#import "ISecurityGuardOpenDataCollection.h"
#import "ISecurityGuardOpenStaticDataStore.h"
#import "ISecurityGuardOpenStaticDataEncrypt.h"
#import "ISecurityGuardOpenDynamicDataEncrypt.h"
#import "ISecurityGuardOpenDynamicDataStore.h"
#import "ISecurityGuardOpenSecureSignature.h"
#import "ISecurityGuardOpenAtlasEncrypt.h"
#import "ISecurityGuardOpenUMID.h"
#import "ISecurityGuardOpenStaticKeyEncrypt.h"
#import "ISecurityGuardOpenOpenSDK.h"
#import "ISecurityGuardOpenLiteVMService.h"



#endif /* SGMain_h */
