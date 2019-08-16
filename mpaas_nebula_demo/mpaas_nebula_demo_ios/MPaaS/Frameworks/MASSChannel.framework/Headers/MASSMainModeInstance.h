//
//  MASSMainModeInstance.h
//  MASSChannel
//
//  Created by yangxiao on 15/12/3.
//  Copyright © 2015年 ppp. All rights reserved.
//

#import "MASSChannelInstance.h"
#import "MASSDataCallback.h"
#import "MASSErrorInterface.h"
#import "MASSConfigCenter.h"
//#import <AMNet/AMNet.h>
//#import <AMNet/AMNetAvailbleStatistic.h>

#define DATA_UPLOAD_MAX_QUEUE_SIZE 64
#define DATA_DOWNLOAD_MAX_QUEUE_SIZE 128
#define DATA_RECORDING_MAX_QUEUE_SIZE 32
#define DATA_TFS_DOWNLOAD_MAX_QUEUE_SIZE 128
#define MASS_TASK_INQUEUE_EXPIRED_TIME 240
#define MASS_MARK_MAX_QUEUE_SIZE 32
#define MASS_OFFLINE_MAX_QUEUE_SIZE 32
#define MASS_QOS_LIMIT_REASON_STR @"QosLimit"
#define MASS_RETRY_MAX_ERROR @"retryMaxTimes"
#define RETRY_MAX_TIMES 3
/**
 *  大数据通道的实例，这是个单例，对外提供上传下载服务
 */
@interface MASSMainModeInstance : MASSChannelInstance

@property (atomic) BOOL                      started;                //线程是否已经启动了

@property (atomic) BOOL                      shouldStop;             //外部控制整个模块的开关

@property (nonatomic,strong) NSString*          token;                  //整个django对接时需要的token

@property (nonatomic) int64_t                   tokenExpireTime;        //这个token什么时候过期

@property (nonatomic) NSMutableArray*           uploadQueue;            //上传的任务队列

@property (nonatomic) NSMutableArray*           downloadQueue;          //下载的任务队列

@property (nonatomic) NSMutableArray*           quickUploadJudeQueue;   //秒传请求的判断逻辑，所有上传请求都需要先入这个队列

@property (nonatomic) NSMutableArray*           recordingUploadQueue;   //边录边传任务队列

@property (nonatomic) NSMutableArray*           tfsDownloadQueue;       //tfs文件下载的任务队列

@property (nonatomic) NSMutableArray*           tfsLowPriorityQueue;    //tfs文件下载的低优先级队列

@property (nonatomic) NSMutableArray*           markDownloadQueue;      //水印下载的队列

@property (nonatomic) NSMutableArray*           offlineUploadQueue;     //离线上传的队列

@property (nonatomic) NSMutableDictionary*      businessToCallback;     //string的key，上层调用模块的value

@property (nonatomic) NSString*                 uid;                    //uid

@property (nonatomic) NSString*                 utdid;                  //utdid

@property (nonatomic) NSString*                 uuid;                   //uuid

@property (nonatomic) NSString*                 uidAuthority;           //自定义权限码

@property (nonatomic) NSMutableArray*           infoProviders;          //获取框架的信息时使用

@property (nonatomic) id<MAStorageDelegate>     storageInterface;       //文件存储读取接口

@property (nonatomic) id<NetAccessInfo>         netAccessInfoProvider;  //网络信息查询

@property (nonatomic) id<AMLogDelegate>         logWriter;              //打日志

@property (nonatomic) NSMutableArray*           errorListenners;        //打出错日志的地方

@property (nonatomic) BOOL                         isUsingMMDP;
@property (nonatomic) BOOL                         isUsingMMUP;

//@property (nonatomic) AMNetAvailbleStatistic*       djgAvailbleStatistic;   //统计djg可用性
//@property (nonatomic) AMNetAvailbleStatistic*       tfsAvailbleStatistic;   //一般下载可用性

/**
 *  缺省的洞，以文件的md5为key。每个value又是一个dictionary，
 *  @“createTime”对应的是文件上传时间，
 *  @“holes”对应的是一个array，array中每项类似于@“100-500”，表示服务端确实的数据区间
 *  @“percent”对应的是之前已经完成的百分比
 */
@property (nonatomic) NSMutableDictionary*      uploadFileWholes;       //上传文件，服务端缺省的洞

/**
 *  下载未完成的部分文件临时存储路径，key为“fileId_zoom”，每个value又是一个dictionary
    @“lastSaveTime”对应的是临时文件创建的时间，
    @“path”对应的是临时文件存储的绝对路径
    @“percent”对应的是之前完成的百分比
 */
@property (nonatomic) NSMutableDictionary*      downloadFilePaths;      //下载未完成的临时文件路径

@property (atomic) BOOL                         sentryGuard;

@property (atomic) NSInteger                    loopCounter;

/**
 *  单例
 *
 *  @return
 */
+(instancetype)shareInstance;

/**
 *
 *
 *  @param onOrOff
 */
+(void)ThreadStartSyncLockOnOrOff:(BOOL)onOrOff;
/**
 *  开启网络线程
 */
-(void)start;
/**
 *  获取traceId;
 *
 *  @return traceid
 */
-(NSString*)getTraceId;

/**
 *  主要是秒传请求的平行调用回包
 *
 *  @param rsp 响应数据
 */
-(void)MASSRpcResponse:(NSData*)rsp;

/**
 *  返回时的各个模块的实例注册
 *
 *  @param name 模块名，找返回时需要
 *  @param ins  模块实例，需要实现回调接口
 */
-(void)addTaskModel:(NSString*)name instance:(id<MASSCallback>)ins;

#pragma mark - out interfaces
/**
 *  上传任务交给MASS，上传前须先注册自己的模块
 *
 *  @param modelName   addTaskModel方法注册的模块名
 *  @param data        需要上传的文件
 *  @param filename    需要上传的文件名
 *  @param quickUpload 是否需要判断秒传
 */
-(void)sendUploadTaskToMASS:(NSString*)modelName
                    content:(NSData*)data
                   fileName:(NSString*)filename
               needJudgeQic:(BOOL)quickUpload
                 needCrypto:(BOOL)crp
                    bizType:(NSString*)biz
                  routerDir:(MMTCRouterDirect)router
               extralParams:(NSDictionary<NSString*,NSString*>*)extParam
              extralHeaders:(NSDictionary<NSString*,NSString*>*)extHeaders
                    taskKey:(NSString*)tk;

/**
 *  调用方发现文件上传超时了，通知MASS处理超时
 *  @param fileName
 *  @param modelName
 */
-(void)fileUploadTimeout:(NSString*)fileName taskKey:(NSString*)tk;

/**
 *  文件上传取消处理
 *
 *  @param fileName 文件名
 */
-(void)fileUploadCancel:(NSString*)fileName taskKey:(NSString*)tk;

/**
 *  下载任务交给MASS，下载前需要注册自己的模块
 *
 *  @param modelName addTaskModel方法注册的模块名
 *  @param fname     需要下载的文件
 *  @param fid       需要下载的文件id
 *  @param ispic     下载的是不是图片
 *  @param zoom      需要下载的图片格式
    @param resForm   下载结果返回的形式，0：data格式返回，1：文件路径返回，2：data格式和文件路径都返回
 */
-(void)sendDownloadTaskToMASS:(NSString*)modelName
                     fileName:(NSString*)fname
                       fileID:(NSString*)fid
                     filePath:(NSString*)path
                   resultForm:(NSInteger)resForm
                        isPic:(BOOL)ispic
                         zoom:(NSString*)zoom
                   needCrypto:(BOOL)crp
                  needGradual:(BOOL)gradual
                      bizType:(NSString*)biz
           massExtraUrlParams:(NSDictionary*)extraParams
                      taskKey:(NSString*)tk;

/**
 *  下载任务超时
 *
 *  @param fileName 文件名
 *  @param fid      文件id
 */
-(void)fileDownloadTimeoutName:(NSString*)fileName
                        fileId:(NSString*)fid
                       taskKey:(NSString*)tk;

/**
 *  下载任务取消
 *
 *  @param fileName 文件名
 *  @param fid      文件id
 */
-(void)fileDownloadCancelName:(NSString*)fileName
                       fileId:(NSString*)fid
                      taskKey:(NSString*)tk;

/**
 *  启动边录边传
 *
 *  @param modelName 请求模块的名
 *  @param fname     文件名
 *  @param tk        任务编号
 *  @param fp        第一个数据块
 */
-(void)sendRecordingUploadTaskToMASS:(NSString*)modelName
                            fileName:(NSString*)fname
                              taskId:(NSString*)tk
                           firstPart:(NSData*)fp
                          needCrypto:(BOOL)crp;

/**
 *  边录边传的数据发送
 *
 *  @param tk   任务号
 *  @param data 数据
 *  @param hn   是否是最后一部分数据了
 */
-(void)sendRecordingDataTaskId:(NSString*)tk
                          data:(NSData*)data
                       hasNext:(BOOL)hn;

/**
 *  取消边录边传任务
 *
 *  @param tk 任务编号
 */
-(void)cancelRecordingTask:(NSString*)tk;

/**
 *  边录边传任务超时
 *
 *  @param tk 任务编号
 */
-(void)recordingTaskTimeout:(NSString*)tk;

/**
 *  开启tfs文件下载任务
 *
 *  @param modelName 请求模块名
 *  @param fid       文件编号
 *  @param resform   要求返回类型，0表示NSData，1表示文件
 *  @param path      要求文件返回时候，文件绝对路径
 *  @param tk        任务编号
 */
-(void)sendTfsDownloadTaskToMassFrom:(NSString*)modelName
                                 Url:(NSString*)url
                          resultForm:(NSInteger)resform
                            filePath:(NSString*)path
                             bizType:(NSString*)biz
                             taskKey:(NSString*)tk
                       extralHeaders:(NSDictionary*)ehead
                         needGradual:(BOOL)gradual
                              isPost:(BOOL)post
                            postBody:(NSData*)body
                    needContinueDown:(BOOL)continus
                              hostIp:(NSString*)ip
                           dnsCostMS:(double)dnsCost
                            isSysDns:(BOOL)isSysDns
                        dnsFromCache:(BOOL)cacheDns;

/**
 *  取消tfs文件下载任务
 *
 *  @param tk 任务编号
 */
-(void)cancelTfsDownloadTask:(NSString*)tk;

/**
 *  tfs文件下载超时
 *
 *  @param tk 任务编号
 */
-(void)tfsDownloadTimeout:(NSString*)tk;

//--------------------------------------------内部方法---------------------------------------------
#pragma mark - inner callbacks
/**
 *  秒传结果处理
 *
 *  @param fname      秒传的文件
 *  @param model      请求模块
 *  @param isSucc     是否秒传成功
 *  @param fid        成功秒传分配的文件id
 *  @param zooms      图片文件才有的文件规格列表
 *  @param jsonResult 文件在django中的所有信息的json表示
 */
-(void)quickUploadFile:(NSString*)fname
                taskId:(NSString*)tk
             fromModel:(NSString*)model
               success:(BOOL)isSucc
                fileId:(NSString*)fid
                 zooms:(NSString*)zooms
          discriptions:(NSDictionary*)jsonResult;

/**
 *  上传成功调用
 *
 *  @param fname      文件名
 *  @param fid        文件id
 *  @param zooms      图片文件的规格
 *  @param jsonResult 所有返回的json内容
 */
-(void)uploadFileSucc:(NSString*)fname
               taskId:(NSString*)tk
               fileId:(NSString*)fid
                zooms:(NSString*)zooms
         discriptions:(NSDictionary*)jsonResult;

/**
 *  上传完成度回调
 *
 *  @param fname     文件名
 *  @param piceStart 回调的分片
 *  @param cpos      该分片已经确认完成的位置
 */
-(void)uploadFilePieceProgress:(NSString*)fname taskId:(NSString*)tk;

//上传失败回调
-(void)uploadFileFailIsQuick:(BOOL)quick reason:(NSString*)rs taskId:(NSString*)tk;

/**
 *  token的跟新
 *
 *  @param token   token串
 *  @param svrTime 服务端当前时间
 *  @param expTime token的服务端过期时间
 */
-(void)tokenRefresh:(NSString*)token
          serverNow:(int64_t)svrTime
         expireTime:(int64_t)expTime;

/**
 *  在遇到token过期的时候，需要正在执行的任务去触发下更新下token
 */
-(void)tokenExpireToReget;

/**
 *  下载文件成功
 *
 *  @param fname   文件名
 *  @param fid     文件id
 *  @param content 文件内容
 */
-(void)downloadFileSuccFile:(NSString*)fname
                     taskId:(NSString*)tk
                     fileId:(NSString*)fid
                    content:(NSData*)content;

/**
 *  文件下载进度
 *
 *  @param fname 文件名
 *  @param fid   文件id
 */
-(void)downloadFileProgressFile:(NSString*)fname
                         taskId:(NSString*)tk
                         fileId:(NSString*)fid;

/**
 *  文件下载失败，主要是文件类型存储失败
 *
 */
-(void)downloadFileFailTaskID:(NSString*)tk;

/**
 *  边录边传成功时回调
 *
 *  @param tk   任务编号
 *  @param fid  文件id，上传成功时有
 *  @param json 上传成功时服务端返回的信息
 */
-(void)recordingUploadSuccTaskId:(NSString*)tk
                          fileId:(NSString*)fid
                      resultJson:(NSDictionary*)json;

/**
 *  边录边传失败时回调
 *
 *  @param tk   任务编号
 */
-(void)recordingUploadFailTaskId:(NSString*)tk error:(NSError*)err;

/**
 *  tfs文件下载任务完成
 *
 *  @param tk      任务id
 *  @param content 文件数据，当要求返回Data时候返回数据内容
 */
-(void)tfsDownloadSuccTaskId:(NSString*)tk;

/**
 *  tfs文件下载进度条
 *
 *  @param tk 任务id
 */
-(void)tfsDownloadNewProgressTaskId:(NSString*)tk;

/**
 *  收到头了要给个回调
 */
-(void)tfsDownloadHttpHeadRcved:(NSString*)tk;

/**
 *  把当前上传的缺失洞信息存文件
 */
-(void)flushUploadHolesToStorage;

/**
 *  存文件
 */
-(void)flushDownloadTmpPathsToStorage;

/*
 * token快过期了才去主动刷新
 */
-(BOOL)tokenNearExpire;

/*
 * token 已经过期了
 */
-(BOOL)tokenIsInvalid;

/*
 * 发现token出问题了，就要去主动更新token
 */
-(void)startFreshToken;

/**
 *  打日志用
 *
 *  @return
 */
-(NSString*)toString;

/*
 *  是否是后台状态
 *
 *
 */
-(BOOL)fetchFilter;

-(NSError*)getFidDownloadLastError:(NSString*)taskid;

-(NSError*)getUrlDownloadLastError:(NSString*)taskid;

-(NSDictionary*)getFidDownloadStatisInfo:(NSString*)taskid nbnet:(BOOL)nb;

-(NSDictionary*)getFidUploadStatisInfo:(NSString*)taskid;

-(NSDictionary*)getStatisInfoOfUrlRequest:(NSString*)taskid;

@end
