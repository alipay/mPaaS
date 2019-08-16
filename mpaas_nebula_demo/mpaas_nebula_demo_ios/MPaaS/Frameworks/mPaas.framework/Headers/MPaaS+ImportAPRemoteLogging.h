//
//  MPaaS+ImportAPRemoteLogging.h
//  APMPaaS
//
//  Created by shenmo on 8/29/16.
//  Copyright © 2016 Alipay. All rights reserved.
//

#import "APRemoteLogging+MPaaS.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
    
    id<APRemoteLoggerClass> getAPRemoteLogger();
    
#ifdef __cplusplus
}
#endif // __cplusplus

// Backward capability macros

#define APRemoteLogger          getAPRemoteLogger()