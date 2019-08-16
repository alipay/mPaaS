//
//  APFileManager.h
//  APMultimedia
//
//  Created by Monster on 15/4/11.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "APMMConst.h"
#import "APBaseUploadRequest.h"
#import "APBaseDownloadRequest.h"

@class APFileDownloadResponse;

@interface APFileUploadResponse : NSObject

@property (nonatomic, copy) NSString *cloudId;

@property (nonatomic, strong) NSError *error;

/**
 服务器端返回的一些额外信息，在上传的extraHeaders和extraParams为不为空的情况下，extraInfo可能返回一些有效信息。
 */
@property (nonatomic, copy) NSDictionary *extraInfo;

- (instancetype)initWithError:(NSError *)error;

- (instancetype)initWithCloudId:(NSString *)cloudId;

- (instancetype)initWithCloudId:(NSString *)cloudId error:(NSError *)error extraInfo:(NSDictionary *)extraInfo;


@end

typedef void (^APFileUploadCompletion)(NSString *cloudId, NSError *error);
typedef void (^APFileDownloadCompletion)(NSData *data, NSError *error);
typedef void (^APFileDownloadPathCompletion)(NSString *storePath, NSError *error);
typedef void (^APFileDownloadRequestComplete)(APFileDownloadResponse *response);
typedef void (^APFileUploadResponseCompletion)(APFileUploadResponse *response);



@interface APFileUploadRequest : APBaseUploadRequest

/**
 上传时额外的http头部参数，需要业务方和服务器端协商
 */
@property (nonatomic, copy) NSDictionary<NSString *,NSString *> *extraHeaders;

/**
 需要业务方和服务器端协商, 额外的上传参数，非头部
 */
@property (nonatomic, copy) NSDictionary<NSString *,NSString *> *extraParams;

/**
 当APFileUploadResponseCompletion设置的情况下，APFileUploadCompletion不会回调，建议使用APFileUploadResponseCompletion，方便扩展
 */
@property (nonatomic, copy) APFileUploadCompletion complete;

/**
 当APFileUploadResponseCompletion设置的情况下，APFileUploadCompletion不会回调，建议使用APFileUploadResponseCompletion，方便扩展
 */
@property (nonatomic, copy) APFileUploadResponseCompletion responseComplete;

@end



@interface APFileDownloadRequest : APBaseDownloadRequest

/**
 *  下载文件的md5值， 如果不为空，则会进行校验。校验失败，error返回错误信息。
 */
@property (nonatomic, copy) NSString *md5;

/**
 * 文件下载到指定的路径，指定storePath后，下载后数据不存缓存，下载后的文件业务方自己管理。如果不指定storePath，则认为是按照二进制流下载。会直接影响到下载完成回调中返回值
 */
@property (nonatomic, copy) NSString *storePath;

/**
 *  下载的是否是zip压缩文件，如果是zip文件，将会解压缩， 只有指定了storePath这个参数才有效。
 */
@property (nonatomic, assign,getter = isZip) BOOL Zip;

/**
 *  下载进度回调
 */
@property (nonatomic, copy) APMMProcessiveBlock processBlock;

/**
 *  文件下载结束的回调
 */
@property (nonatomic, copy) APFileDownloadRequestComplete downloadReuestCompletion;

/**
 *  是否使用文件加密 若isZip为YES,则不解压
 */
@property (nonatomic, assign) BOOL useCrypt;


@end



typedef NS_ENUM(NSUInteger, APResponseSourceType) {
    APResponseSourceTypeUnkown,//默认状态 未知
    APResponseSourceTypeMemory,//来自内存缓存
    APResponseSourceTypeDisk, //来自磁盘缓存
    APResponseSourceTypeNetwork,//来自网络
};

/**
 * 下载指定存储路径storePath有值，否则data将返回值
 */
@interface APFileDownloadResponse : NSObject

@property (nonatomic, copy) NSString *cloudId;
@property (nonatomic, strong) NSData *data;
/**
 文件下载后的存储目录，storepath对于对于zip文件，filePath为文件的为解压后的文件目录；对于非zip文件，对于cloudid或者url，为业务方传入的storePath，需要自己拼凑最终的路径，建议使用filePath，filePath指向最终文件路径
 */
@property (nonatomic, copy) NSString *storePath;
@property (nonatomic, strong) NSError *error;

/**
 对于非zip文件，filePath为文件下载后的文件路径；对于zip文件，filePath为文件的为解压后的文件目录
 */
@property (nonatomic, copy) NSString *filePath;

/**
 获取数据的来源，只有当有数据返回的时候，才有意义，当response中有error的时候，sourceType不确定
 */
@property (nonatomic, assign) APResponseSourceType sourceType;

- (instancetype)initWithError:(NSError *)error;
- (instancetype)initWithData:(NSData *)data;
- (instancetype)initWithStorePath:(NSString *)storePath;
- (instancetype)initWithStorePath:(NSString *)storePath filePath:(NSString *)filePath;
- (instancetype)initWithData:(NSData *)data storePath:(NSString *)storePath cloudId:(NSString *)cloudId error:(NSError *)error;

@end

@interface APFileManager : NSObject

+ (instancetype)manager;

#pragma mark 上传
/**
 *  上传文件
 *
 *  @param path     文件全路径
 *  @param business 业务存储标识
 *  @param progress 进度
 *  @param complete 完成状态
 *
 *  @return 返回localId,用于上传失败时重传
 */

- (NSString *)uploadWithFilePath:(NSString *)path
                        business:(NSString *)business
                        progress:(APMMProcessiveBlock)progress
                      completion:(APFileUploadCompletion)complete;

- (NSString *)uploadWithFilePath:(NSString *)path request:(APFileUploadRequest *)uploadRequest;


/**
 *  上传文件
 *
 *  @param data     文件字节流数据
 *  @param business 业务存储标识
 *  @param progress 进度
 *  @param complete 完成状态
 *
 *  @return 返回localId,用于上传失败时重传
 */
- (NSString *)uploadWithFileData:(NSData *)data
                        business:(NSString *)business
                        progress:(APMMProcessiveBlock)progress
                      completion:(APFileUploadCompletion)complete;

- (NSString *)uploadWithFileData:(NSData *)data request:(APFileUploadRequest *)uploadRequest;


/**
 * 离线上传文件
 * @param url 离线上传文件的url
 *
 */
- (void)uploadOfflineWithUrl:(NSString *)url
                  completion:(APFileUploadCompletion)complete;

#pragma mark 下载

/**
 *  下载文件，用于小文件接口
 *
 *  @param cloudId  cloudId
 *  @param business 业务存储标识
 *  @param progress 进度
 *  @param complete 完成状态
 */
- (NSString *)downLoadFileWithCloudId:(NSString *)cloudId
                             business:(NSString *)business
                             progress:(APMMProcessiveBlock)progress
                           completion:(APFileDownloadCompletion)complete DEPRECATED_MSG_ATTRIBUTE("Replaced by 'downloadFileWithCloudId: downloadRequest:'");

/**
 *  下载文件,对于非zip文件 如果指定storepath目录，在store P啊替换下 已经存在同名的文件 则直接返回，不会触发网络请求
 *  指定下载文件路径
 *
 *  @param cloudId  cloudId
 *  @param path 指定文件的存储路径
 *  @param isZip 如果是zip文件将会解压缩
 *  @param progress 进度
 *  @param complete 完成状态
 */
- (NSString *)downLoadFileToPathWithCloudId:(NSString *)cloudId
                                  storePath:(NSString *)storePath
                                      isZip:(BOOL)isZip
                                   progress:(APMMProcessiveBlock)progress
                                 completion:(APFileDownloadPathCompletion)complete DEPRECATED_MSG_ATTRIBUTE("Replaced by 'downloadFileWithCloudId: downloadRequest:'");

/**
 *  下载文件，对于非zip文件， 如果指定storepath目录，已经存在同名的文件 则直接返回，不会触发网络请求。
 *
 *  @param cloudId         cloudId
 *  @param downloadRequest 下载请求的相关配置
 *
 *  @return cloudId
 */
- (NSString *)downloadFileWithCloudId:(NSString *)cloudId downloadRequest:(APFileDownloadRequest*)downloadRequest;


- (BOOL)isFileCacheExistFor:(NSString*)identifier request:(APFileDownloadRequest*)request;

/**
 * 取消上传或下载任务
 */
- (BOOL)cancelTaskWithLocalId:(NSString*)localId;


/**
 根据cloudId+storePath Request生成最终文件路径，对于没有制定store Path的request直接返回nil，对于zip资源，直接返回解压的上层目录

 @param cloudId cloudId description
 @param request 设置了storePath的APFileDownloadRequest
 @return 根据cloudId+storePath Request生成最终文件路径
 */
- (NSString *)destinationPathWithCloudId:(NSString *)cloudId storePathRequest:(APFileDownloadRequest *)request;

/**
 根据cloud id/local id或者url拿到文件的缓存地址，支持文件和视频id

 @param identifier cloud id/local id或者url
 @return 如果本地缓存存在则返回l存储路径，否则则返回nil;
 */
- (NSString *)cachePathWithIdentifier:(NSString*)identifier;

/**
 根据cloud id生成文件下载的url

 @param cloudId cloud id
 @return 根据cloud id生成文件下载的url
 */
- (NSString *)buildFileDownloadUrlWithCloudId:(NSString *)cloudId;

#pragma mark - 加密



/**
 *  解密数据
 *
 *  @param inputData 源数据
 *
 *  @return 解密后数据
 */
- (NSData*)decryptData:(NSData*)inputData;

/**
 *  解密文件
 *
 *  @param   inputPath源文件
 *  @param   outputPath解密后目标文件（需与源文件路径不同）
 *  @param   APFileDownloadPathCompletion
 *  @param   isZip 是否压缩包
 *  @Discuss 如果为压缩包需指定isZip,则在解密后解压到目标文件
 */
- (void)decryptDataInputFile:(NSString*)inputFile outputFile:(NSString*)outputFile clouldId:(NSString*)cloudId isZip:(BOOL)isZip completion:(APFileDownloadPathCompletion)completion;

@end
