//
//  MPaaS+ImportAPShareKit.h
//  APMPaaS
//
//  Created by shenmo on 8/29/16.
//  Copyright © 2016 Alipay. All rights reserved.
//

#import "APShareKit+MPaaS.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
    
    id<APSKClientClass> getAPSKClient();
    
#ifdef __cplusplus
}
#endif // __cplusplus

// Backward capability macros

#define APSKClient              getAPSKClient()