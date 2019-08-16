//
//  DynamicReleaseDefines.h
//  DynamicRelease
//
//  Created by ronghui.zrh on 16/3/5.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#ifndef DynamicReleaseDefines_h
#define DynamicReleaseDefines_h

#define kDynamicReleaseDomain @"com.alipay.dynamicrelease"

#define kDynamicReleaseError 299   //统一的错误

#define kDynamicReleaseRPCErrorCode  300 //服务端返回not success
#define kDynamicReleaseExceptionErrorCode  304   //异常
#define kDynamicReleaseContentNilErrorCode 305 //数据为nil
#define kDynamicReleaseContentMd5ErrorCode 306 //数据md5 error
#define kDynamicReleaseSaveFileErrorCode 307 // 保存资源文件错误                // 9.9.1开始只用于鸟巢
#define kDynamicReleaseSaveMetaInfoFileErrorCode 308 //保存metaInfo文件错误    // 9.9.1开始只用于鸟巢
#define kDynamicReleaseRemoveFileErrorCode 309 //remove资源文件和metainfo文件失败
#define kDynamicReleaseResourceTypeErrorCode 310 //资源类型错误

// 9.9.1新增

// 执行脚本阶段错误
#define kDynamicReleaseReadSigErrorCode 400 // 读取sig文件错误
#define kDynamicReleaseMD5MissingErrorCode 401 // 读取sig文件后检验md5，但在metainfo里没有md5
#define kDynamicReleaseVerifyMD5ErrorCode 402 // 读取sig文件后校验md5错误
#define kDynamicReleaseReadZipErrorCode 403 // 读取zip文件错误
#define kDynamicReleaseVerifySignErrorCode 404 // hotpatch签名验证错误
#define kDynamicReleaseHotpatchMissingErrorCode 405 // 执行hotpatch找不到资源文件

#define kDynamicReleaseJSRunErrorCodeBase 1000 // JSPatch那边的运行结果加上1000

// 处理脚本阶段错误
#define kDynamicReleaseSGInitializeErrorCode 500 // 无线保镖初始化失败
#define kDynamicReleaseSGEncryptErrorCode 501 // 无线保镖加密失败
#define kDynamicReleasePListSerializationErrorCode 502 // 将对象序列化失败
#define kDynamicReleaseProcessExceptionErrorCode 503 // 脚本处理阶段异常的错误
#define kDynamicReleaseWriteToDiskErrorCode 504 // 写文件阶段错误
#define kDynamicReleaseProcessUnknownErrorCode 505

static NSString * const DR_HOTPATCH = @"BANDAGE";
static NSString * const DR_BIRDNEST = @"BIRDNEST";
static NSString * const DR_NEBULA = @"NEBULA";

static NSString * const DR_DYNAMICRELEASE = @"DynamicRelease";
static NSString * const DR_KEYBIZ = @"KeyBiz";
static NSString * const DR_VERSION = @"version";
static NSString * const DR_RESOURCEID = @"resId";
static NSString * const DR_METHOD_COUNT = @"methodCount";
static NSString * const DR_ERRORCODE = @"errorCode";
static NSString * const DR_ERRORDESC = @"errorDesc";
static NSString * const DR_FIRSTRUN = @"firstRun";
static NSString * const DR_BN_RES = @"resDesc";

static NSString * const DR_RPC = @"RPC";
static NSString * const DR_DOWNLOAD = @"Download";
static NSString * const DR_PROCESS = @"Process";
static NSString * const DR_EXECUTE = @"Execute";
static NSString * const DR_ROLLBACK = @"Rollback";
static NSString * const DR_NOTIFY = @"Notify";

static NSString * const DR_START = @"Start";
static NSString * const DR_FAIL = @"Fail";
static NSString * const DR_SUCCESS = @"Success";
static NSString * const DR_EXCEPTION = @"Exception";

#define DR_SAFE_STRING(s) ((s==nil)?@"":s)

#endif /* DynamicReleaseDefines_h */
