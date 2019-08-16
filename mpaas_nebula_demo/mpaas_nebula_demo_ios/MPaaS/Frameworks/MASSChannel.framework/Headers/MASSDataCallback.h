//
//  MASSDataCallback.h
//  MASSChannel
//
//  Created by yangxiao on 15/12/9.
//  Copyright © 2015年 ppp. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, MMTCRouterDirect) {
    MMTCRouterIgnore,
    MMTCRouterUsingMMTC,
    MMTCRouterUsingDjango,
};

/**
 *  ！！！！！！！！！！！！！！！！！！！！！！！注意此协议中所有的方法实现一定要非阻塞！！！！！！！！！！！！！！！！！！！！！！！！！！！！
 *  ！！！！！！！！！！！！！！！！！！！！！！！注意此协议中所有的方法实现一定要非阻塞！！！！！！！！！！！！！！！！！！！！！！！！！！！！
 *  ！！！！！！！！！！！！！！！！！！！！！！！注意此协议中所有的方法实现一定要非阻塞！！！！！！！！！！！！！！！！！！！！！！！！！！！！
 *  ！！！！！！！！！！！！！！！！！！！！！！！注意此协议中所有的方法实现一定要非阻塞！！！！！！！！！！！！！！！！！！！！！！！！！！！！
 *  ！！！！！！！！！！！！！！！！！！！！！！！注意此协议中所有的方法实现一定要非阻塞！！！！！！！！！！！！！！！！！！！！！！！！！！！！
 *  ！！！！！！！！！！！！！！！！！！！！！！！注意此协议中所有的方法实现一定要非阻塞！！！！！！！！！！！！！！！！！！！！！！！！！！！！
 *  ！！！！！！！！！！！！！！！！！！！！！！！注意此协议中所有的方法实现一定要非阻塞！！！！！！！！！！！！！！！！！！！！！！！！！！！！
 *  ！！！！！！！！！！！！！！！！！！！！！！！注意此协议中所有的方法实现一定要非阻塞！！！！！！！！！！！！！！！！！！！！！！！！！！！！
 *  ！！！！！！！！！！！！！！！！！！！！！！！注意此协议中所有的方法实现一定要非阻塞！！！！！！！！！！！！！！！！！！！！！！！！！！！！
 *  ！！！！！！！！！！！！！！！！！！！！！！！注意此协议中所有的方法实现一定要非阻塞！！！！！！！！！！！！！！！！！！！！！！！！！！！！
 *  ！！！！！！！！！！！！！！！！！！！！！！！注意此协议中所有的方法实现一定要非阻塞！！！！！！！！！！！！！！！！！！！！！！！！！！！！
 *  ！！！！！！！！！！！！！！！！！！！！！！！注意此协议中所有的方法实现一定要非阻塞！！！！！！！！！！！！！！！！！！！！！！！！！！！！
 *  ！！！！！！！！！！！！！！！！！！！！！！！注意此协议中所有的方法实现一定要非阻塞！！！！！！！！！！！！！！！！！！！！！！！！！！！！
 *  ！！！！！！！！！！！！！！！！！！！！！！！注意此协议中所有的方法实现一定要非阻塞！！！！！！！！！！！！！！！！！！！！！！！！！！！！
 */
@protocol MASSCallback <NSObject>

@optional

/**
 *  上传文件的进度百分比回调，0-100的整数.
 *
 *  @param filename 上传文件的文件名
 *  @param percent  百分比数，0-100
 */
-(void)UploadFile:(NSString*)filename taskId:(NSString*)tk percent:(float)percent uploaded:(NSInteger)upedSize wholeSize:(NSInteger)whole;

/**
 *  文件上传成功了，返回成功的文件信息
 *
 *  @param filename 文件名
 *  @param fileid   返回id
 *  @param zooms    文件规格列表，没有就是nil
 *  @param disc     返回的所有描述，由返回json解析而来
 */
-(void)UploadFileComplatedName:(NSString*)filename taskId:(NSString*)tk fileId:(NSString*)fileid picZooms:(NSString*)zooms discriptions:(NSDictionary*)disc userInfo:(NSDictionary*)info;

/**
 *  上传失败直接返回
 *
 *  @param filename 文件名
 *  @param tk       任务id
 *  @param info     统计日志信息
 */
-(void)UploadFileFailName:(NSString*)filename taskId:(NSString*)tk error:(NSError*)error userInfo:(NSDictionary*)info;

/**
 *  文件下载成功了，返回的是文件的内容
 *
 *  @param fname    文件名，启动任务时候给的
 *  @param fid      文件id
 *  @param fcontent 下载的文件内容
 */
-(void)DownloadFileSuccName:(NSString*)fname taskId:(NSString*)tk fileId:(NSString*)fid content:(NSData*)fcontent userInfo:(NSDictionary*)info;

/**
 *  下载的进度情况
 *
 *  @param fname   文件名
 *  @param percent 进度
 */
-(void)DownloadFileName:(NSString*)fname taskId:(NSString*)tk fileId:(NSString*)fid percent:(float)percent downloaded:(NSInteger)downed wholeSize:(NSInteger)whole partlyData:(NSData*)partData;

/**
 *  文件下载失败了
 *
 *  @param fname    文件名，启动任务时候给的
 *  @param fid      文件id
 */
-(void)DownloadFileFailName:(NSString*)fname taskId:(NSString*)tk fileId:(NSString*)fid userInfo:(NSDictionary*)info;

/**
 *  tfs文件下载成功
 *
 *  @param tk       任务id
 *  @param fcontent 数据返回时文件内容
 *  @param info     日志信息
 */
-(void)TfsDownloadSuccTaskId:(NSString*)tk Content:(NSData*)fcontent head:(NSData*)head UserInfo:(NSDictionary*)info;

/**
 *  tfs文件下载收到了http头
 *
 */
-(void)TfsDownloadRcvedHeadTaskId:(NSString*)tk head:(NSData*)head;

/**
 *  下载进度情况
 *
 *  @param tk      任务id
 *  @param percent 进度
 *  @param downed  已经下载多少
 *  @param whole   文件总大小
 */
-(void)TfsDownloadTaskId:(NSString*)tk Percent:(float)percent partFile:(NSData*)partfile Downloaded:(NSInteger)downed WholeSize:(NSInteger)whole;

/**
 *  tfs文件下载失败
 *
 *  @param tk       任务id
 *  @param info     日志信息
 */
-(void)TfsDownloadFailTaskId:(NSString*)tk UserInfo:(NSDictionary*)info;

/**
 *  边录边传成功
 *
 *  @param fname
 *  @param tk    任务id
 *  @param fid   fileID
 *  @param disc  django返回信息
 *  @param info  统计信息
 */
-(void)RecordingSuccFileName:(NSString*)fname taskId:(NSString*)tk fileId:(NSString*)fid discriptions:(NSDictionary*)disc userInfo:(NSDictionary*)info;

/**
 *  边录边传失败
 *
 *  @param taskid  任务id
 *  @param error   错误信息
 *  @param useinfo 统计信息
 */
-(void)RecordingFailTaskId:(NSString*)taskid error:(NSError*)error userInfo:(NSDictionary*)useinfo;
/**
 *  降级接口
 *
 *  @param tk 任务ID
 */
-(void)taskDemote:(NSString*)tk;

/**
 *  任务真正开始执行
 *
 *  @param tk 任务ID
 */
-(void)taskStartExcute:(NSString*)tk;

/**
 *  水印下载
 *
 *  @param tk
 *  @param fcontent
 *  @param info
 */
-(void)MarkDownloadSuccTaskId:(NSString*)tk Content:(NSData*)fcontent UserInfo:(NSDictionary*)info;

/**
 *  水印下载
 *
 *  @param tk
 *  @param percent
 *  @param downloaded
 *  @param whole
 */
-(void)MarkDownloadProgressTaskId:(NSString *)tk percent:(float)percent downloaded:(NSInteger)downloaded wholeSize:(NSInteger)whole;

/**
 *  离线上传
 *
 *  @param tk
 *  @param dic
 *  @param info 
 */
-(void)OfflineUploadSuccTaskID:(NSString*)tk discription:(NSDictionary*)dic userInfo:(NSDictionary*)info;


@end
