//
//  MPaaS+ImportDynamicRelease.h
//  APMPaaS
//
//  Created by shenmo on 8/29/16.
//  Copyright © 2016 Alipay. All rights reserved.
//

#import "DynamicRelease+MPaaS.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
    
    id<DynamicReleaseClass> getDynamicRelease();
    
#ifdef __cplusplus
}
#endif // __cplusplus

// Backward capability macros

#define DynamicRelease          getDynamicRelease()