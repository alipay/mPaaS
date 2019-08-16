//
//  APDownloadReq.h
//  APMobileNetwork
//
//  Created by Wanlei on 14-10-21.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

#define APDownloadDefaultTimeoutInterval 60

@interface APDownloadRequest : NSObject

@property(nonatomic, strong, readonly)NSURL *downloadURL;
@property(nonatomic, copy, readonly) void (^completionBlock)(NSString *path, NSError *error);
@property(nonatomic, copy, readonly) void (^progressBlock)(float percent, NSUInteger readBytes, NSUInteger totalBytes);
@property(nonatomic, assign) NSTimeInterval timeoutInterval;


/**
 *  初始化一个下载req
 *
 *  @param appKey             标示业务方
 *  @param aURL               需要下载的url
 *  @param completionCallback 下载完成block，在主线程中回调
 *
 *  @return 下载req
 */
-(APDownloadRequest*)initWithAppKey:(NSString *)appKey atURL:(NSURL *)aURL
                 completionCallback:(void (^)(NSString *path, NSError *error))completionCallback;


/**
 *  设置进度，可不设
 *
 *  @param aURL  需要下载的URL
 *  @param block complete block
 */
- (void)setProgressBlock:(void (^)(float percent, NSUInteger readBytes, NSUInteger totalBytes))block;


@end

@interface NSMutableURLRequest(DownloadRequest)
/**
 *  download是否走spdy的开关
 *
 */
-(void)setShouldStartResourcesSPDYProxy:(BOOL)val;
/**
 *  download是否走asi的开关
 *
 */
-(void)setShouldStartResourcesASIProxy:(BOOL)val;

@end

