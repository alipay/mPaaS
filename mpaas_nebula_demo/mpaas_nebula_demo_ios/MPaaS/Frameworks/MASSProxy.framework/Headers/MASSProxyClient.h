//
//  MASSProxyClient.h
//  MASSProxy
//
//  Created by cuinacai on 16/2/24.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "MASSDownMethod.h"
#import "MASSUpMethod.h"
#import "MASSMethod.h"
#import "MASSUploadRespone.h"
#import "MASSProxyDefine.h"


typedef void (^MASSProcessiveBlock)(MASSMethod *method,double percent,long long partialBytes,long long totalBytes,NSData* partFile);
typedef void (^MASSDownloadCompletion)(MASSMethod *method,NSData *content,NSError *error);
typedef void (^MASSUploadCompletion)(MASSMethod *method,MASSUploadRespone *resp,NSError *error);
typedef void (^MASSTfsHeadReceived)(MASSMethod* method,NSData* head);
typedef void (^MASSGeneralUploadCompletion)(MASSMethod* method,NSData *rspBody,NSError* error);
typedef void (^MASSGeneralUploadHeadRcv)(MASSMethod* method,NSData* head);;
@interface MASSProxyClient : NSObject
@property (atomic,strong) NSLock* cookieLock;           //cookie集中在这个对象中管理
/**
 *	@brief	单例
 */
+ (instancetype)shareInstance;
/**
 *	@brief	mass是否开
 */
+ (BOOL)clientSwitch;
/**
 *	@brief	下载数据接口
 *	@param 	method 下载方法,包含相应参数
 *  @param 	timeoutInterval 超时
 *	@return id,method里面的fileId+zoom的组合,可用于cancel
 */
- (NSString *)downloadFile:(MASSDownMethod *)method
           timeoutInterval:(NSTimeInterval)timeoutInterval
                  progress:(MASSProcessiveBlock)progress
                completion:(MASSDownloadCompletion)complete;

/**
 *	@brief	上传数据到阿里云
 *	@param 	method 下载方法,包含相应参数
 *  @param 	timeoutInterval 超时
 *	@return id,可用于cancel
 */
- (NSString *)uploadData:(MASSUpMethod *)method
         timeoutInterval:(NSTimeInterval)timeoutInterval
                progress:(MASSProcessiveBlock)progress
              completion:(MASSUploadCompletion)complete;

/**
 *
 * 上传数据到通用外部地址
 *
 *
 */
-(NSString *)uploadGeneral:(MASSUpMethod*)method
           timeoutInterval:(NSTimeInterval)timeoutInterval
                completion:(MASSGeneralUploadCompletion)complete
                   headRcv:(MASSGeneralUploadHeadRcv)headRcv;

/**
 *	@brief	cancel接口
 *  @param 	key
 */
-(void)cancel:(NSString *)key;

/**
 *	@brief	边录边传,如果是第一次上传需要给出complete的block,
 *	@param 	data 上传的数据
 *  @param 	timeoutInterval 超时(hn=NO时候必填)
 *	@param  tkId任务id,tkId=nil表示开始边录边传新的任务
 *	@param  hn如果是没有数据传或者最后一块数据就hn=NO,表示边录边传结束,等待回调
 *	@return tkId,可用于边录边传的任务id或者cancel的id
 */
- (NSString *)uploadData:(NSData *)data
         timeoutInterval:(NSTimeInterval)timeoutInterval
                  taskId:(NSString*)tkId
              needCrypto:(BOOL)needCrypto
                 hasNext:(BOOL)hn
              completion:(MASSUploadCompletion)complete NS_DEPRECATED_IOS(5_0,6_0);

/**
 *  @brief 边录边传的启动方法
 *  @param timeoutInterval 超时，必须大于0
 *  @param needCrypto 是否要求使用https上传
 *  @param complete 必须有，且必须要有出错处理
 *  @return 返回任务唯一id,如果返回nil，表示传入参数有异常
 */
-(NSString*)startContinuingUploadWithFirstData:(NSData*)firstPart
                                       timeOut:(NSTimeInterval)timeoutInterval
                                    needCrypto:(BOOL)needCrypto
                                    completion:(MASSUploadCompletion)complete;

/**
 *  @brief 边录边传后续数据上传
 *  @param continusData后续边录边传数据
 *  @param taskid任务的标识，start接口返回，不能传nil
 *  @return 如果异常时候返回NO
 */
-(BOOL)continueUploadWithData:(NSData*)continusData taskid:(NSString*)taskid;

/**
 *  @brief 边录边传结束动作
 *  @param taskid任务标识，不能传nil
 *  @return 异常情况返回NO
 */
-(BOOL)endContinueUploadOfTaskid:(NSString*)taskid;

/**
 *	@brief	TFS下载数据接口,根据URL下载
 *	@param 	method 下载方法,包含相应参数
 *  @param 	timeoutInterval 超时
 *	@return id,method里面的fileId+zoom的组合,可用于cancel
 */
- (NSString *)downloadTFS:(MASSTFSDownMethod *)method
          timeoutInterval:(NSTimeInterval)timeoutInterval
                 progress:(MASSProcessiveBlock)progress
               completion:(MASSDownloadCompletion)complete;

/**
 *  tfs下载接口，增加了头的返回
 *
 *
 *
 */
- (NSString*)downloadTFS:(MASSTFSDownMethod*)method
         timeoutInterval:(NSTimeInterval)timeoutInterval
                progress:(MASSProcessiveBlock)progress
              completion:(MASSDownloadCompletion)complete
             headReceive:(MASSTfsHeadReceived)headrcved;

/**
 *	@brief	水印接口
 *	@param 	method 下载方法,包含相应参数
 *  @param 	timeoutInterval 超时
 *	@return id可用于cancel
 */
- (NSString *)downloadMark:(MASSMarkDownMethod *)method
          timeoutInterval:(NSTimeInterval)timeoutInterval
                 progress:(MASSProcessiveBlock)progress
               completion:(MASSDownloadCompletion)complete;

-(NSString*)getDjangoUrlWithFileId:(NSString*)fileId isImage:(BOOL)isImg imageZoom:(NSString*)zoom isHttps:(BOOL)ishttps;
-(NSString*)getDjangoUrlWithFileId:(NSString *)fileId isImage:(BOOL)isImg imageZoom:(NSString *)zoom isHttps:(BOOL)ishttps isPublic:(BOOL)isPublic;

-(NSString*)getDjangoToken;

// 新增的设置fileid型上传下载时候，每个请求都要加的http头和参数
-(void)setGloableExtralHeaders:(NSDictionary<NSString*,NSString*>*)headers extralURLParams:(NSDictionary<NSString*,NSString*>*)urlParams extralMMDPParams:(NSDictionary<NSString*,NSString*>*) mmdpParams;

//新增上传网络接口

/**
 *  静态方法
 *
 *  @return
 */
+(BOOL)defaultNetInterfaceIPv6Only;

/**
 *  静态方法
 *
 *  @param v4
 *
 *  @return
 */
+(NSString*)getIPv6StrFromv4:(NSString*)v4;
/**
 *  是否需要过滤掉fetch导致的失败
 *
 *  @return
 */
+(BOOL)isFetchFilter;


/**
 流量统计的接口，所有任务不管成功失败，都会有一次调用

 @param interface 接口名，分为：fileid_upload、fileid_download、url_request
 @param url fileid或者请求的url
 @param up 本次任务的上行流量
 @param down 本次任务的下行流量
 @param tcpCount tcp建连次数
 @param sslCount ssl握手次数
 @param biz 业务名，通过这个知道是什么业务调用的这个任务
 @param type 网络类型，对应到内部的一个enum，0：无网络、1：2g、2：3g、3：4g、4：wifi
 */
-(void)taskFlowStatistic:(NSString*)interface url:(NSString*)url upSize:(NSInteger)up downSize:(NSInteger)down tcpConnectCount:(NSInteger)tcpCount sslCount:(NSInteger)sslCount bizName:(NSString*)biz netType:(NSInteger)type succ:(BOOL)succ;
@end
