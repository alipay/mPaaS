//
//  APVideoManager.h
//  APMultimedia
//
//  Created by Cloud on 15/5/22.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AssetsLibrary/AssetsLibrary.h>
#import "APFileManager.h"
#import "APImageManager.h"
#import "APMMConst.h"
#import "APVideoInfo.h"
#import "APVideoRequest.h"


typedef enum : NSUInteger {
    APCameraPermissionGranted,           // 已授权
    APCameraPermissionNoVideo,           // 摄像头无权限
    APCameraPermissionNoAudio,           // 麦克风无权限
} APCameraPermissionType;


#pragma mark - 由于历史原因，当前APVideoManager涉及identifier的接口只支持视频id和首帧图id组合的形式。

@interface APVideoManager : NSObject

/**
 *  共享实例
 */
+ (instancetype)shareManager;

#pragma mark - 摄像头和麦克风权限获取接口

+ (void)requestCameraPermission:(void (^)(APCameraPermissionType granted))block;

#pragma mark - 压缩

/**
 *  压缩视频
 *  如果最终不需要发送此视频，需要调用清除缓存接口
 *
 *  @param  path      视频文件全路径
 *  @param  complete  视频压缩完成的block
 */
- (void)compressVideoWithPath:(NSString *)path
                   completion:(APVideoCompressHandler)complete;

/**
 *  压缩视频
 *  如果最终不需要发送此视频，需要调用清除缓存接口
 *
 *  @param  asset     视频asset,支持ALAsset和PHAsset，PHAsset暂不支持从iCloud下载，与调用方约定，传过来的都是本地资源
 *  @param  complete  视频压缩完成的block
 */
- (void)compressVideoWithAsset:(id)asset
                    completion:(APVideoCompressHandler)complete;

/**
 *  压缩视频，支持PHAsset从iCloud下载
 *  如果最终不需要发送此视频，需要调用清除缓存接口
 */
- (void)compressVideoWithAsset:(id)asset
                       request:(APCompressVideoRequest*)request;

/**
 *  计算完整的视频压缩后二进制大小的预估值 单位为M，不支持在icloud上未下载到本地的视频，在iphone6上耗时在20-100ms之间 不建议在主线程调用

 *  @param asset ALAsset或者PHAsset和AVAsset
 *  @return 压缩后的视频预估二进制大小 单位为M
 */
- (CGFloat)estimatedCompressedDataSizeOfAsset:(id)asset compressLevel:(APVideoCompressLevel)compressLevel;

#pragma mark - 获取缩略图

/**
 *  同步获取本地缓存中的视频缩略图
 *
 *  @param  identifier  视频id
 *
 *  @return 缩略图，如果为nil，则表示本地未查到
 */
- (UIImage *)getThumbnailWithIdentifierFromCache:(NSString *)identifier;

/**
 *  获取视频缩略图
 *  如果传的是localId，会直接从缓存中查询，并在当前线程中调用complete
 *
 *  @param  identifier  视频id
 *  @param  business    业务存储标识
 *  @param  progress    下载进度百分比回调
 *  @param  complete    完成回调
 *
 *  @return 用于取消任务的taskId
 */
- (NSString *)getThumbnailWithIdentifier:(NSString *)identifier
                                business:(NSString *)business
                                progress:(APMMProcessiveWithIdBlock)progress
                              completion:(APImageDownloadWithIdCompletion)complete;

/**
 *  获取视频缩略图的id，该id可以使用APImageManager相关的接口
 *
 *  @param  identifier  视频id
 *
 *  @return 可用于APImageManager的id
 */
- (NSString *)getThumbnailIdFromIdentifier:(NSString *)identifier;

/**
 *  获取视频缩略图
 *
 *  @param identifier 视频id+缩略图id
 *  @param request    APVideoRequest对象入参
 *
 *  @return 用于取消任务的taskId
 */
- (NSString *)getVideoThumbnail:(NSString*)identifier
                        request:(APVideoRequest*)request;

#pragma mark - 获取视频

/**
 *  获取视频
 *
 *  @param  identifier  视频id
 *  @param  business    业务存储标识
 *  @param  progress    下载进度百分比回调
 *  @param  complete    完成回调
 *
 *  @return 用于取消任务的taskId
 */

- (NSString *)getVideoWithIdentifier:(NSString *)identifier
                            business:(NSString *)business
                            progress:(APMMProcessiveWithIdBlock)progress
                          completion:(APVideoDownloadCompletion)complete;

/**
 *  获取视频
 *
 *  @param identifier 视频id+缩略图id
 *  @param request    APVideoRequest对象入参
 *
 *  @return 用于取消任务的taskId
 */
- (NSString *)getVideo:(NSString*)identifier
               request:(APVideoRequest*)request;

#pragma mark - 视频上传

/**
 *  视频上传
 *
 *  @param  localId   视频localId
 *  @param  business  业务存储标识
 *  @param  progress  上传进度百分比回调
 *  @param  complete  上传完成回调
 *
 *  @return 用于取消任务的taskId
 */
- (NSString *)uploadWithLocalId:(NSString *)localId
                       business:(NSString *)business
                       progress:(APMMProcessiveWithIdBlock)progress
                     completion:(APFileUploadCompletion)complete;

- (NSString *)uploadWithLocalId:(NSString *)localId
                  request:(APFileUploadRequest *)uploadRequest;

#pragma mark - 取消任务
/**
 *  取消上传/下载任务
 *
 *  @return 返回成功与否
 */
- (BOOL)cancelTaskWithIdentifier:(NSString *)identifier;

/**
 *  取消上传/下载任务
 *
 *  @return 返回成功与否
 */
- (BOOL)cancelTaskWithTaskId:(NSString *)taskId;

#pragma mark - 删除视频及缩略图缓存

/**
 *  删除视频及缩略图缓存
 *  如果是本地录制的小视频，也会从14天小视频列表中删除
 */
- (void)clearCacheForIdentifier:(NSString *)identifier;

/**
 直接缓存视频到cache中并返回相关信息。该接口不做任何压缩处理，适用于已经做过处理的视频，比如多媒体录制接口录制的视频，已经压缩过的视频。

 @param path 视频路径
 @param complete 处理完成回调
 */
- (void)cacheVideoWithPath:(NSString *)path
                completion:(APVideoCompressHandler)complete;

@end

#pragma mark - 状态管理

// 视频状态
typedef enum : NSUInteger {
    APVideoNotExist,                            // 视频不存在
    APVideoExist,                               // 视频存在
    APVideoUploading,                           // 视频正在上传中
    APVideoDownloading,                         // 视频正在下载中
    APVideoUnknownStatus                        // 视频状态未知
} APVideoStatus;

@interface APVideoManager (APVideoStatusExtension)

/**
 *  视频状态查询
 *  在主线程调用，否则行为未知
 *
 *  @param  identifier 视频的id，localId或者cloudId
 *
 *  @return 返回状态
 */
- (APVideoStatus)getStatusOfIdentifier:(NSString *)identifier;

/**
 *  视频进度查询
 *  在状态为下载或者上传时调用此接口，否则返回0
 *  在主线程调用，否则行为未知
 *
 *  @param  identifier 视频的id，localId或者cloudId
 *
 *  @return 如果正在下载或上传，返回当前的进度。否则返回0
 */
- (double)getProgressOfIdentifier:(NSString *)identifier;

@end

#pragma mark - 小视频管理

@interface APVideoManager (APShortVideoManager)

/**
 *  添加小视频
 *
 *  @param  localId     小视频的localId
 */
- (void)addShortVideoWithLocalId:(NSString *)localId;

/**
 *  删除小视频
 *
 *  @param  localId     小视频的localId
 */
- (void)delShortVideoWithLocalId:(NSString *)localId;

/**
 *  返回14天内的小视频列表
 *
 *  @return  小视频localId的列表
 */
- (NSArray <NSString *>*)getShortVideoList;

@end

#pragma mark - 视频id管理

@interface APVideoManager (APVideoIndentifierManager)

/**
 *  判断当前identifier是否是localId
 *
 *  @param  identifier  请求的视频identifier，如果参数无效，返回结果未知
 *
 *  @return 当前identifier是否是localId
 */
- (BOOL)isIdentifierLocal:(NSString *)identifier;

/**
 *  根据视频的identitifer获取视频本地的路径
 *
 *  @param identifier 视频的identifier
 *
 *  @return 视频在本地的路径，如果本地没有该视频的话，则返回nil
 */
- (NSString *)getVideoPathWithIdentifier:(NSString *)identifier;

/**
 根据视频的identitifer获取视频的id

 @param identifier 视频的identifier
 @return 如果是有效的identifier，则返回视频id，否则返回nil
 */
- (NSString *)getVideoIdWithIdentifier:(NSString *)identifier;

#pragma mark - 存储系统相册

/**
 *  根据identifier从缓存中获取video，然后存到系统相册。
 *
 *  @param identifier cloudId or local Id
 *  @param complete   存储完成回调，不保证在主线程执行。
 */
- (void)storeVideoIntoPhotoAlbumWithIdentifier:(NSString *)identifier complete:(APStoreVideoToPhotoCompleteHandler)complete;

@end


@interface APVideoManager (AVAsset)

/**
 根据ALAsset或者PHAsset对象生成video AVAsset对象

 @param asset ALAsset或者PHAsset对象
 @param request APiCloudAVAssetForVideoRequest 请求
 */
- (void)requestAVAssetForVideoWithAsset:(id)asset request:(APAVAssetForVideoRequest *)request;



/**
 根据AVAsset在指定时间点生成素略图

 @param asset  asset AVAsset对象
 @param time 指定时间 单位秒
 @param size 缩略图尺寸，缩略图都是等比图 生成缩略图尺寸小于等于这个尺寸，单位为点
 @param handler 生成单张缩略图的回调
 */
- (void)generateThumbnailFromAVAsset:(AVAsset *)asset
                              atTime:(NSTimeInterval)time
                                size:(CGSize)size
                     completeHandler:(APAssetGenerateImageCompletionHandler)handler;
@end

