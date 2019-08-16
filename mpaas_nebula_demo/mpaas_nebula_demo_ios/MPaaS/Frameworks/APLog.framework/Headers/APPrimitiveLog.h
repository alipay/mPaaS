//
//  APPrimitiveLog.h
//  APMobileFoundation
//
//  Created by taoyuan on 16/6/6.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#ifndef APPrimitiveLog_h
#define APPrimitiveLog_h


#ifdef __cplusplus
extern "C" {
#endif
    
    void APPrimitiveLog(const char *tag, int level, const char *format, ...) __attribute__((deprecated("Use APLogInfo instead")));
    
#ifdef __cplusplus
}
#endif


#endif
