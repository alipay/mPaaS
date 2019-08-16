//
//  MPaaS+ImportAUBarButtonItem.h
//  APMPaaS
//
//  Created by yangwei on 2017/5/31.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "AUBarButtonItem+MPaaS.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
    
    id<AUBarButtonItemClass> getAUBarButtonItem();
    
#ifdef __cplusplus
}
#endif // __cplusplus

// Backward capability macros

#define AUBarButtonItem           getAUBarButtonItem()
