//
//  APDownloadMgr.h
//  APMobileNetwork
//
//  Created by Wanlei on 14-10-21.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "APDownloadRequest.h"

@interface APDownloadManager : NSObject

//是否需要清理过期文件，主要是防止在启动阶段就开始做清理这种事情
@property (atomic) BOOL             fileClearSwitch;


/**
 *  文件下载管理器
 *
 *  文件下载管理器为单例，全局只有一个
 *
 *  @return 唯一的文件下载管理器
 */
+(APDownloadManager*)sharedDownloadMgr;
/**
 *  获取下载线程
 */
- (NSThread *)downloadThread;

/**
 *  启动文件下载
 *
 *  @param appKey App Key，用于标识一个业务。
 *  @param aURL               需要下载的URL
 *  @param completionCallback 下载器在主线程中调用block
 *  @param timeoutInterval 超时时间
 *  @return 返回一个Tag对象，标识一次下载请求
 */
- (id)downloadFileWithAppKey:(NSString *)appKey atURL:(NSURL *)aURL
       completionCallback:(void (^)(NSString *path, NSError *error))completionCallback;

- (id)downloadFileWithAppKey:(NSString *)appKey atURL:(NSURL *)aURL
          completionCallback:(void (^)(NSString *path, NSError *error))completionCallback timeoutInterval:(NSTimeInterval)timeoutInterval;

/**
 *  通过req方式启动文件下载
 *
 *  @param req 需要下载的req参数
 *
 *  @return 返回一个Tag对象，标识一次下载请求
 */
- (id)downloadFileWithReq:(APDownloadRequest*)req;

/**
 *  取消文件下载
 *
 *  @param tag 通过Tag对象取消下载
 *         tag为downloadFileWithAppKey:atURL:completionCallback: 或downloadFileWithReq: 返回
 */
- (void)cancelTaskForTag:(id)tag;

/**
 *  检查aURL对应的文件是否已存在
 *
 *  @param aURL 需要检查对应文件是否存在的URL
 *
 *  @return aURL对应的文件已存在返回YES,否则返回NO
 */
-(BOOL)isFileExistedForURL:(NSURL*)aURL;

/**
 *  清理过期的文件
 */
-(void)clearExpiredFile;

@end




