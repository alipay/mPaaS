//
//  aplog_io.h
//  APLog
//
//  Created by myy on 17/1/17.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#ifndef aplog_io_h
#define aplog_io_h


#include <stdio.h>
#include <stdlib.h>


#ifdef __cplusplus
extern "C" {
#endif
    
    
    typedef struct _APLogIO
    {
        int  isMmap;
        int  (*fileOpen )(void* thiz, const char* szLogName, const char* szMmapName, int isFg, int mode);
        int  (*fileWrite)(void* thiz, const void* buf, size_t len);
        int  (*fileFlush)(void* thiz);
        void (*fileClose)(void* thiz);
        void (*fileHandleFgBgState)(void* thiz, int isFg);
    }APLogIO;
    
    
    APLogIO* APLogIOCreate(int isMmap);
    void APLogIOFree(APLogIO* thiz);
    
    
#ifdef __cplusplus
}
#endif

#endif


