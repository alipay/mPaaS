//
//  MPaaS+ImportAPMobileIdentifier.h
//  APMPaaS
//
//  Created by shenmo on 8/29/16.
//  Copyright © 2016 Alipay. All rights reserved.
//

#import "APMobileIdentifier+MPaaS.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
    
    id<APMobileIdentifierClass> getAPMobileIdentifier();
    
#ifdef __cplusplus
}
#endif // __cplusplus

// Backward capability macros

#define APMobileIdentifier      getAPMobileIdentifier()