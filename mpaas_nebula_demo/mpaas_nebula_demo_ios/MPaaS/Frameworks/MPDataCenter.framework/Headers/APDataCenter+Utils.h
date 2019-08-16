//
//  APDataCenter+Utils.h
//  MobileFoundation
//
//  Created by shenmo on 12/16/15.
//  Copyright © 2015 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * 统一存储定期检查应用的存储空间状态，发生紧张的情况，会抛此通知。
 */
extern NSString* const kDidReceiveStorageSpaceWarningNotification;

/**
 *  当内部的数据库操作触发了SQLITE_FULL，SQLITE_CANTOPEN时，抛此异常。
 *  由上层检测是否磁盘空间已满，同时进行一些操作。
 *  该通知由统一存储抛出，上层代码监听。
 */
extern NSString* const kDidReceiveSQLiteFullExceptionNotification;

/**
 *  当上层处理了一次磁盘满的异常后，抛此通知。
 *  该通知由上层代码抛出，统一存储监听。
 */
extern NSString* const kDidSQLiteFullExceptionHandledNotification;

@interface APDataCenterUtils : NSObject

/**
 *  取某个目录的大小
 */
+ (unsigned long long)folderSizeAtPath:(NSString *)path;

/**
 *  取本应用沙箱总大小
 */
+ (unsigned long long)sandboxSize;

/**
 *  取系统剩余空间大小
 */
+ (unsigned long long)freeDiskSpace;

/**
 *  硬件总存储空间大小
 */
+ (unsigned long long)totalDiskSpace;

/**
 *  将字节数格式化成较好看的样子。小于700字节，用字节；小于700KB，用KB；。。。
 *
 *  @param size 字节数
 *
 *  @return 字符串
 */
+ (NSString*)prettyBytesFormat:(unsigned long long)size;

/**
 *  开始后台检测空闲空间，当出现不足是抛出通知kDidReceiveStorageSpaceWarningNotification
 */
+ (void)startCheckFreeSpaceInBackground;

/**
 *  增加进程文件句柄上限，每次调用增加256，返回是否成功
 */
+ (BOOL)increaseFileHandleLimit;

@end
