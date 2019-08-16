//
//  APMVideoRequest.h
//  APMultimedia
//
//  Created by aspling on 2016/10/3.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "APBaseDownloadRequest.h"
#import "APVideoInfo.h"

@class APVideoDownloadResponse;
/**
 *  压缩完成block
 *
 *  @param  info    压缩后的视频信息
 *  @param  error   异常信息
 */
typedef void (^APVideoCompressHandler)(APVideoInfo *info, NSError *error);
typedef void (^APVideoCompressProgressHandler)(float progress);

typedef void (^APiCloudDownloadProcessivedBlock)(double progress, NSError *error, BOOL *stop, NSDictionary *info);

// 带id的完成回调
typedef void (^APVideoDownloadCompletion)(NSString *identifier,NSString *storePath,NSError *error);

typedef void (^APRequestVideoAVAssetCompleteHandler)(AVAsset *avasset, NSURL *url, NSError *error);
typedef void (^APAssetGenerateImageCompletionHandler)(UIImage *thumbnail, NSError *error, NSTimeInterval requestedTime);

/**
 *  视频下载完成回调
 *
 *  @param response APVideoDownloadResponse
 */
typedef void (^APVideoDownloadRequestComplete)(APVideoDownloadResponse *response);

/**
 *  存储系统照片回调
 *
 *  @param assetURL
 *  @param error
 */
typedef void (^APStoreVideoToPhotoCompleteHandler)(NSURL *assetURL, NSError *error);


@interface APiCloudRequest : NSObject

/**
 * 是否支持从iCloud下载
 */
@property (nonatomic,assign) BOOL enableiCloudDownloading;


/**
 * 从iCloud下载时的进度回调
 */
@property (nonatomic,copy) APiCloudDownloadProcessivedBlock iCloudProgressHandler;

@end


typedef NS_ENUM(NSUInteger, APVideoCompressLevel) {
    APVideoCompressLevelLow,
    APVideoCompressLevelHigh,
    APVideoCompressLevelLowQuality = APVideoCompressLevelLow,  //360P 码率：800kbps
    APVideoCompressLevelHighQuality = APVideoCompressLevelHigh,// 720P 码率：1400kbps
    APVideoCompressLevelMidQuality, // 540P 码率：1100kbps
    APVideoCompressLevelOriginalQuality, //尽量和视频的原始质量保持一致, 除非特殊用途，不建议使用，对于相册视频，会导致码率过高，造成流量过高。
};

@interface APCompressVideoRequest : APiCloudRequest

/**
 * 压缩完成回调
 */
@property (nonatomic,copy) APVideoCompressHandler compressHandler;

/**
 * 压缩完成回调
 */
@property (nonatomic,copy) APVideoCompressProgressHandler progressHandler;

/**
 从指定点开始压缩，默认从起始点开始
 */
@property (nonatomic, assign) NSTimeInterval startPoint;

/**
 压缩到指定点结束，默认是视频总时长
 */
@property (nonatomic, assign) NSTimeInterval endPoint;


/**
 视频的压缩级别
 */
@property (nonatomic, assign) APVideoCompressLevel compressLevel;

@end


/**
 请直接使用APCompressVideoRequest，APiCloudVideoRequest已被废弃，仅为兼容以前的代码
 */
@interface APiCloudVideoRequest : APCompressVideoRequest

@end


@interface APAVAssetForVideoRequest : APiCloudRequest

/**
 * 获取AVAsset回调
 */
@property (nonatomic,copy) APRequestVideoAVAssetCompleteHandler requestVideoAVAssetcompleteHandler;


@end



@interface APVideoRequest : APBaseDownloadRequest
/**
 *  下载文件的md5值， 如果不为空，则会进行校验。校验失败，error返回错误信息。
 */
@property (nonatomic, copy) NSString *imageMd5;

/**
 *  下载文件的md5值， 如果不为空，则会进行校验。校验失败，error返回错误信息。
 */
@property (nonatomic, copy) NSString *videoMd5;

/**
 *  下载进度回调
 */
@property (nonatomic, copy) APMMProcessiveWithIdBlock processBlock;

/**
 *  文件下载结束的回调
 */
@property (nonatomic, copy) APVideoDownloadRequestComplete downloadReuestCompletion;

@end

@interface APVideoDownloadResponse : NSObject

@property (nonatomic, copy) NSString *identifier;
@property (nonatomic, strong) NSError *error;
@property (nonatomic, strong) NSString *storePath;
@property (nonatomic, strong) UIImage *image;

+ (instancetype)responseWithError:(NSError *)error identifier:(NSString*)identifier;
+ (instancetype)responseWithStorePath:(NSString *)storePath identifier:(NSString*)identifier error:(NSError *)error;
+ (instancetype)responseWithImage:(UIImage *)image identifier:(NSString*)identifier error:(NSError *)error;
@end
