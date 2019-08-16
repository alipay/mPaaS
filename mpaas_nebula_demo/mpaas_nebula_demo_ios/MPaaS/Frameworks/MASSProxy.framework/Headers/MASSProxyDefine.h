//
//  MASSProxyDefine.h
//  MASSProxy
//
//  Created by cuinacai on 16/3/9.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#define MASSCookie @"Cookie"
#define MASSSetCookie @"Set-Cookie"


typedef NS_ENUM(NSInteger, MASSDownReturnType)
{
    MASSDownReturnData = 0,//下载返回data
    MASSDownReturnFilePath,  //下载返回文件路径
    MASSDownReturnDataAndFilePath //下载返回data和文件路径
};

typedef NS_ENUM(NSInteger, MASSErrorCode)
{
    MASSErrorCodeTimeout = -10001,//超时
    MASSErrorCodeDowngrade = -10002,  //降级
    MASSErrorCodeCancel = -10003,  //取消
    MASSErrorCodeFail = -10004, //失败,网络或逻辑原因
    MASSErrorCodeQueueTimeout = -10005,     //队列等待超时
    MASSErrorCodeQPSLimitsExceeds = -10006, //服务端限流
    MASSErrorCodeRecordingTaskMissing = -10007, //录音请求时任务已经不存在了
    MASSErrorCodeTimeoutTooLittle = -10008,
    MASSErrorCodeBackGroundDownload = -10009,
    MASSErrorCodeDownloadHostIllegal = -10010,
};
