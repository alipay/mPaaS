//
//  NAMErrorCode.h
//  NebulaAppManager
//
//  Created by 扶瑶 on 16/3/4.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#ifndef NAMErrorCode_h
#define NAMErrorCode_h

// 错误域
extern NSString *const NAM_ERROR_DOMAIN;
extern NSString *const NAM_ERROR_OPTIONS;

/**
    NAMErrorUnknown =           10000,
    NAMErrorCanNotOpenApp =     10001,
    NAMErrorUnzipFailed =       10003,
    NAMErrorRPCException =      10004,
    NAMErrorRPCCalling =        10005,
    NAMErrorRPCNoExpired =      10006,
    NAMErrorVerifyFailed =      10007,
    NAMErrorPatchFailed =       10008,
    NAMErrorAppCacheNotExist =  10009,
    NAMErrorDownloadFailed =    10010
 */
typedef NS_ENUM(NSUInteger, NAMErrorCode) {
    
    NAMErrorUnknown = 10000,    //  未知错误
    NAMErrorCanNotOpenApp,      //  无法打开包, appId异常
    NAMErrorUnzipFailed,        //  解压包失败
    NAMErrorRPCException,       //  rpc异常, 无应用
    NAMErrorRPCCalling,         //  上一个请求尚未结束
    NAMErrorRPCNoExpired,       //  请求的app未过期
    NAMErrorVerifyFailed,       //  验签失败
    NAMErrorPatchFailed,        //  增量更新失败
    NAMErrorAppCacheNotExist,   //  应用本地缓存不存在 (e.g. 请求失败,本地无应用缓存)
    NAMErrorDownloadFailed,     //  下载失败
    NAMErrorPrepareTimeOut,     //  准备超时
    NAMErrorOpenAppBreak,       //  启动应用打断
    NAMErrorSDKVersionError     //  支持最低AppxSDK版本过低
};

#endif /* NAMErrorCode_h */
