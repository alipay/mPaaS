//
//  APVoiceRequest.h
//  APMultimedia
//
//  Created by Monster on 2016/11/3.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "APBaseDownloadRequest.h"

@class APVoiceDownloadResponse;
/**
 *  视频下载完成回调
 *
 *  @param response APVoiceDownloadResponse
 */
typedef void (^APVoiceDownloadRequestComplete)(APVoiceDownloadResponse *response);


@interface APVoiceRequest : APBaseDownloadRequest

/**
 *  下载文件的md5值， 如果不为空，则会进行校验。校验失败，error返回错误信息。
 */
@property (nonatomic, copy) NSString *md5;

/**
 *  下载进度回调
 */
@property (nonatomic, copy) APMMProcessiveWithIdBlock processBlock;

/**
 *  文件下载结束的回调
 */
@property (nonatomic, copy) APVoiceDownloadRequestComplete downloadReuestCompletion;

@end

@interface APVoiceDownloadResponse : NSObject

@property (nonatomic, copy) NSString *identifier;
@property (nonatomic, strong) NSError *error;

+ (instancetype)responseWithIdentifier:(NSString*)identifier error:(NSError *)error;
@end
