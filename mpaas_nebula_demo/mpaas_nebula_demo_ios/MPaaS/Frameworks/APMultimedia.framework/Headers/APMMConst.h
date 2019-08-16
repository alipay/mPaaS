//
//  APMMConst.h
//  APMultimedia
//
//  Created by fuxin on 15/3/31.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//
#import <APMTaskManager/APMTask.h>
#ifndef APMultimedia_APMMConst_h
#define APMultimedia_APMMConst_h

#define UnavailableCheck_Enabel  (YES)

//进度回调
typedef void (^APMMProcessiveBlock)(double percentage,
                                    long long partialBytes,
                                    long long totalBytes);

//按照index区分的批量动作进度
typedef void (^APMMBatchProcessiveBlock)(NSUInteger index,
                                         double percentage,
                                         long long partialBytes,
                                         long long totalBytes);

// 带id的进度回调
typedef void (^APMMProcessiveWithIdBlock)(NSString *identifier,double percentage,long long partialBytes,long long totalBytes);
/**
 * 多媒体任务优先级
 */
typedef NS_ENUM (NSUInteger,APMultimediaTaskPriority){
    //低优先级
    APMultimediaTaskPriorityLow = APMTaskPriorityLow,
    //默认优先级
    APMultimediaTaskPriorityDefault = APMTaskPriorityDefault
};
/**
 * 多媒体任务执行顺序
 */
typedef NS_ENUM (NSUInteger,APMultimediaTaskExecuteSequence){
    //先进先出
    APMultimediaTaskExecuteSequenceFIFO = APMTaskExecuteSequenceFIFO,
    //后进先出
    APMultimediaTaskExecuteSequenceLIFO = APMTaskExecutequenceLIFO,
    //自动，由多媒体组件进行控制，默认是该值
    APMultimediaTaskExecuteSequenceAuto = 1000
};

//错误类型
#define   APMultimedia_Error_FileNotExist               (8501)        //文件不存在
#define   APMultimedia_Error_RecordMaxMixError          (8502)        //录音最大最小时长错误
#define   APMultimedia_Error_CloudIdIsEmpty             (8503)        //cloudId为空
#define   APMultimedia_Error_AlAssetIsEmpty             (8504)
#define   APMultimedia_Error_ArrayIsEmpty               (8505)        //array参数为空
#define   APMultimedia_Error_LocalIdFileNotFile         (8506)        //根据localId未获取到缓存文件
#define   APMultimedia_Error_ParameterIsError           (8507)        //参数有误
#define   APMultimedia_Error_UnAceptArray               (8508)
#define   APMultimedia_Error_DownLoadFileEmpty          (8509)        //下载文件内容为空
#define   APMultimedia_Error_UnZipFail                  (8601)        //解压失败
#define   APMultimedia_Error_DataIsNull                 (8602)        //data为空
#define   APMultimedia_Error_Cancel                     (8603)        //任务取消
#define   APMultimedia_Error_VerifyError                (8604)        //文件校验失败
#define   APMultimedia_Error_CompressError              (8605)        //视频压缩失败
#define   APMultimedia_Error_BatchUploadError           (8606)        //批量上传时失败
#define   APMultimedia_Error_StatusError                (8607)        //视频状态有误
#define   APMultimedia_Error_ImageTooLarge              (8608)        //图片文件超大
#define   APMultimedia_Error_PortalNotCertifcated       (8609)        //wifi未认证，不能真正上网
#define   APMultimedia_Error_ResponseFromMassIsEmpty    (8610)        //网络组件返回的response为空
#define   APMultimedia_Error_iOSVersionLessThan_iOS8    (8611)        //iOS版本低于8.0，不支持PHAsset方式访问Photo
#define   APMultimedia_Error_DownloadFromiCloudFailed   (8612)        //从iCloud下载失败
#define   APMultimedia_Error_GetLowQualityImageFailed   (8613)        //获取低清图失败
#define   APMultimedia_Error_DownloadFromiCloudTimeout  (8614)        //从iCloud下载超时
#define   APMultimedia_Error_FileStreamOpenFailed       (8615)        //文件流打开失败
#define   APMultimedia_Error_HasNoSpaceAvailable        (8616)        //文件流无可空间
#define   APMultimedia_Error_Unknown                    (8999)        //未知错误
#define   APMultimedia_Error_FlowLimit                  (2000)        //双十一十二限流
#define   APMultimedia_Error_NotSupportRangeAccess      (8617)        // 媒体资源不支持边下边播
#define   APMultimedia_Error_NetWorkError               (8618)        // 网络错误
#define   APMultimedia_Error_UnreachableNetWorkError               (8619)        // 无网络错误


#define   APMultimedia_Error_CanntGetiCloudProgress     (-1)          // 无法获取iCloud的同步进度


#define   kDjangoErrorDomain                            @"com.taobao.t.django"
#define   kDjangoErrorBreakPoint                        @"DjangoErrorBreakPoint"
#define   kMultiMediaAppName                            @"APMultiMedia"
#define   kCloudIdLength                                (32)
#define   kCacheDefaultBusiness                         @"Common"     //通用存储业务名
#define   kCacheDefaultBizType                          @"mm_other"   //默认的biztype

#define   kCacheErrorRecordAge                          (60 * 60 * 24 * 14)  //上传失败不删除的时间，单位:s

#endif
