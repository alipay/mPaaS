//
//  MPaaS+ImportAPThemeManager.h
//  APMPaaS
//
//  Created by shenmo on 8/29/16.
//  Copyright © 2016 Alipay. All rights reserved.
//

#import "APThemeManager+MPaaS.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
    
    id<APThemeManagerClass> getAPThemeManager();
    
#ifdef __cplusplus
}
#endif // __cplusplus

// Backward capability macros

#define APThemeManager          getAPThemeManager()
