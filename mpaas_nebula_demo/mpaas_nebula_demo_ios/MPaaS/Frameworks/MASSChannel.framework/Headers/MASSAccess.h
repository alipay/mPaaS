//
//  MASSAccess.h
//  MASSChannel
//
//  Created by yangxiao on 15/12/15.
//  Copyright © 2015年 ppp. All rights reserved.
//
#import <Foundation/Foundation.h>
#import "MASSDataCallback.h"
#import "MASSMainModeInstance.h"
#import "NBNetDownloadCommon.h"
#import "MASSNetworkInterface.h"
#import "MASSCommonDefine.h"

@interface MASSSvrInfo : NSObject

@property (nonatomic)NSString*      host;

@property (nonatomic)NSMutableArray*       iplist;

@property (nonatomic)NSString*      port;

@end


@interface MASSAccess : NSObject

/**
 *  单例
 *
 *  @return 单例
 */
+(instancetype)shareInstance;

/**
 *  将服务端的地址传给通道层,如果线程没有开始，立即开始运行
 *
 *  @param tokenSvr    token的服务器域名和ip列表
 *  @param uploadSvr   上传的服务器域名和ip列表
 *  @param downloadSvr 下载的服务器域名和ip列表
 */
-(void)dispatchTokenSvrInfo:(MASSSvrInfo*)tokenSvr
                 uploadInfo:(MASSSvrInfo*)uploadSvr
               downloadInfo:(MASSSvrInfo*)downloadSvr
         downloadInfoCrypto:(MASSSvrInfo*)downSvrCrypto
              configStorage:(id<MAStorageDelegate>)storage;
/**
 *  上面接口的扩展版，增加了mmdp和mmup的iplist
 *
 *  @param tokenSvr
 *  @param uploadSvr
 *  @param downloadSvr
 *  @param downSvrCrypto
 *  @param mmdpSvr
 *  @param mmupSvr
 *  @param storage
 */
-(void)dispatchTokenSvrInfo:(MASSSvrInfo*)tokenSvr
                 uploadInfo:(MASSSvrInfo*)uploadSvr
               downloadInfo:(MASSSvrInfo*)downloadSvr
         downloadInfoCrypto:(MASSSvrInfo*)downSvrCrypto
                   mmdpInfo:(MASSSvrInfo*)mmdpSvr
                   mmupInfo:(MASSSvrInfo*)mmupSvr
              configStorage:(id<MAStorageDelegate>)storage;

/**
 *  随时要进行服务端ip列表更新
 *
 *  @param tokenSvr         token的服务器域名和ip列表
 *  @param uploadSvr        上传的服务器域名和ip列表
 *  @param downloadSvr      下载的服务器域名和ip列表
 */
-(void)freshTokenSvrInfo:(MASSSvrInfo*)tokenSvr
              uploadInfo:(MASSSvrInfo*)uploadSvr
            downloadInfo:(MASSSvrInfo*)downloadSvr
      downloadInfoCrypto:(MASSSvrInfo*)dsvrCrpt;
/**
 *  上面接口的扩展板
 *
 *  @param tokenSvr
 *  @param uploadSvr
 *  @param downloadSvr
 *  @param dsvrCrpt
 *  @param mmdpSvr
 *  @param mmupSvr
 */
-(void)freshTokenSvrInfo:(MASSSvrInfo*)tokenSvr
              uploadInfo:(MASSSvrInfo*)uploadSvr
            downloadInfo:(MASSSvrInfo*)downloadSvr
      downloadInfoCrypto:(MASSSvrInfo*)dsvrCrpt
                mmdpInfo:(MASSSvrInfo*)mmdpSvr
                mmupInfo:(MASSSvrInfo*)mmupSvr;
/**
 *  注册模块名
 *
 *  @param name 这个模块的名称
 *  @param ins  回调对象
 */
-(void)registDataTaskModel:(NSString*)name instance:(id<MASSCallback>)ins;
/**
 *  开始上传
 *
 *  @param modelName   发起的模块名
 *  @param data        待上传的内容
 *  @param fname       待上传的文件名
 *  @param quickUpload 是否需要判断秒传，比如是刚拍的照，就不需要秒传
 */
-(void)uploadStartFromModel:(NSString*)modelName
                    content:(NSData*)data
                   fileName:(NSString*)fname
             needJudgeQuick:(BOOL)quickUpload
                 needCrypto:(BOOL)cyp
                    bizType:(NSString*)biz
                  routerDir:(MMTCRouterDirect)router
               extralParams:(NSDictionary<NSString*,NSString*>*)extParam
              extralHeaders:(NSDictionary<NSString*,NSString*>*)extHeader
                    taskKey:(NSString*)tk;
/**
 *  上传文件业务超时
 *
 *  @param fname 文件名
 */
-(void)fileUploadTimeout:(NSString*)fname taskKey:(NSString*)tk;
/**
 *  上传业务取消
 *
 *  @param fname 文件名
 */
-(void)fileUploadCancel:(NSString*)fname taskKey:(NSString*)tk;

/**
 *
 *
 *  @param modelName
 *  @param fname
 *  @param fid
 *  @param path
 *  @param resForm
 *  @param ispic
 *  @param zoom
 *  @param stZoom
 *  @param crp
 *  @param tk
 */
-(void)fileDownloadFromModel:(NSString*)modelName
                    fileName:(NSString*)fname
                      fileId:(NSString*)fid
                    filePath:(NSString*)path
                  resultForm:(NSInteger)resForm
                   isPicture:(BOOL)ispic
                        zoom:(NSString*)zoom
                     gradual:(BOOL)gradual
                  needCrypto:(BOOL)crp
                     bizType:(NSString*)biz
                 mmdpBizData:(NSData*)bizData
                   routerDir:(MMTCRouterDirect)router
          massExtraUrlParams:(NSDictionary*)extraParams
             extraMMDPParams:(NSDictionary<NSString*,NSString*>*)extraMMDPParams
                     taskKey:(NSString*)tk;
/**
 *  下载文件超时
 *
 *  @param fname 下载的文件名
 *  @param fid   下载的文件id
 */
-(void)fileDownloadTimeoutName:(NSString*)fname fileId:(NSString*)fid taskKey:(NSString*)tk;

/**
 *  下载文件取消
 *
 *  @param fname 文件名
 *  @param fid   文件id
 */
-(void)fileDownloadCancel:(NSString*)fname fileId:(NSString*)fid taskKey:(NSString*)tk;

/**
 *  边录边传
 *
 *  @param modelName 发起的模块名
 *  @param fname     上传的文件名
 *  @param tk        任务id
 *  @param firstData 第一部分数据，可以为nil
 */
-(void)recordingUploadFromModel:(NSString*)modelName
                       fileName:(NSString*)fname
                         taskId:(NSString*)tk
                  firstDataPart:(NSData*)firstData
                     needCrypto:(BOOL)crp;

/**
 *  边录边传录制
 *
 *  @param data 数据部分
 *  @param tk   任务id
 *  @param hn   是否是最后一片
 */
-(void)recordingUploadAppendData:(NSData*)data
                          taskId:(NSString*)tk
                         hasNext:(BOOL)hn;

/**
 *  边录边传取消
 *
 *  @param tk 任务id
 */
-(void)recordingCancelTask:(NSString*)tk;

/**
 *  边录边传超时
 *
 *  @param tk 任务id
 */
-(void)recordingTimeoutTask:(NSString*)tk;

/**
 *  tfs下载任务
 *
 *  @param modelName 模块名
 *  @param fname     文件名
 *  @param tk        任务id
 *  @param resForm   返回时Data还是文件
 *  @param path      要求返回文件时候的路径
 */
-(void)tfsDownloadFromModel:(NSString*)modelName
                   fileName:(NSString*)fname
                        Url:(NSString*)url
                     taskId:(NSString*)tk
                 resultForm:(NSInteger)resForm
                   filePath:(NSString*)path
                    bizType:(NSString*)bizType
              extralHeaders:(NSDictionary*)ehead
                needGradual:(BOOL)gradual
                     isPost:(BOOL)post
                   postBody:(NSData*)body
           needContinueDown:(BOOL)continus;

/**
 *  tfs下载任务取消
 *
 *  @param tk 任务id
 */
-(void)tfsDownloadCancelTask:(NSString*)tk;

/**
 *  tfs下载任务超时
 *
 *  @param tk 任务id
 */
-(void)tfsDownloadTimeoutTask:(NSString*)tk;

/**
 *  水印下载
 *
 *  @param model
 *  @param fid
 *  @param zoom
 *  @param crpt
 *  @param tk    
 */
-(void)markDownloadFromModel:(NSString*)model
                      fileId:(NSString*)fid
                 mainImgZoom:(NSString*)zoom
                  needCrypto:(BOOL)crpt
                      taskId:(NSString*)tk
                     bizType:(NSString*)bizType
                 mmdpBizData:(NSData*)bizdata
             extralMMDPParam:(NSDictionary<NSString*,NSString*>*)extraParam;

/**
 *  取消水印接口
 *
 *  @param tk
 */
-(void)markTaskCancel:(NSString*)tk;

//与netctl接口///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 *	@brief	info提供者
 *
 *	@param 	infoObject     MAInitInfoInterface实现
 *
 *	@return
 */
-(void)addInfoProvider:(id<MAInitInfoInterface>)infoProvider;

/**
 *	@brief	网络信息提供者
 *
 *	@param 	netInfoProvider     NetAccessInfo实现
 *
 *	@return
 */
-(void)registerNetInfoProvider:(id<NetAccessInfo>)netInfoProvider;

/**
 *	@brief	打日志的提供者
 *
 *	@param 	LogWriter     AMLogDelegate实现
 *
 *	@return
 */
-(void)registerLogWriter:(id<AMLogDelegate>)lw;

/**
 *  出错上报
 *
 *  @param el MAErrorInterface的实现
 */
-(void)registErrorListener:(id<MASSErrorInterface>)el;

/**
 *  所有配置信息的传递接口
 *
 *  @param config config
 */
-(void)setMassChannelConfig:(NSDictionary*)config;

/**
 *  设置新下载/上传通道的开关
 *
 *  @param isMMDP 新下载开关
 *  @param isMMUP 新上传开关
 */
-(void)setMMDPSwitch:(BOOL)isMMDP MMUPSwitch:(BOOL)isMMUP;

/**
 *  设置在mmup上传时候，后端服务器使用django做存储
 *
 *  @param backendDj 后端使用django
 */
-(void)setMMUPBackendDjango:(BOOL)backendDj;

/**
 *  ipv6
 *
 *  @return
 */
-(BOOL)defaultInterfaceIpv6Only;

/**
 *  ipv4转ipv6
 *
 *  @param v4
 *
 *  @return
 */
-(NSString*)translateToIpv6StrFromIpv4:(NSString*)v4;

/**
 *  获取数据通道开关（上行）
 *
 *  @return
 */
-(BOOL)isUseMMUP;

/**
 *  获取数据通道下行
 *
 *  @return 
 */
-(BOOL)isUseMMDP;

/**
 *  django fileId兑换url
 */
+(NSString*)getDjangoUrlWithFileId:(NSString*)fileId isImage:(BOOL)isImg imageZoom:(NSString*)zoom isHttps:(BOOL)ishttps;

/**
 *  django fileId兑换url
 */
+(NSString*)getDjangoUrlWithFileId:(NSString *)fileId isImage:(BOOL)isImg imageZoom:(NSString *)zoom isHttps:(BOOL)ishttps isPublic:(BOOL)isPublic;

/**
 *  获取django的token
 */
+(NSString*)getDjangoToken;


+(NSError*)getLastErrorOfFileIDDownload:(NSString*)taskid;

+(NSError*)getLastErrorOfTfsDownload:(NSString*)taskid;

+(NSDictionary*)getStatisInfoOfFileIdDownload:(NSString*)taskid isNBNet:(BOOL)nb;

+(NSDictionary*)getStatisInfoOfFileIdUpload:(NSString*)taskid;

+(NSDictionary*)getStatisInfoOfUrlRequest:(NSString*)taskid;

@end




