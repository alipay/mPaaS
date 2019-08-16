//
//  APLogMgr.h
//  APLog
//
//  Created by myy on 17/1/2.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>


@protocol APLogZipInterface
- (BOOL)createZipFile:(NSString*)zipFile;
- (BOOL)addFileToZip:(NSString*)file newname:(NSString*)newname;
- (BOOL)closeZipFile;
@end


@protocol APLogMgrDelegate
- (NSString*)uploadLogUrl;
- (NSString*)uploadStatusUrl;
- (NSString*)currentUserId;
- (id<APLogZipInterface>)makeZipObj;
@optional
- (BOOL)isLogFormatAssertCheck;
- (BOOL)isCloseLogEncrypt;
//- (BOOL)isCloseNewFormatLog;
- (void)logWithoutEncrypt:(NSString*)logString;
- (void)logExtra:(NSString*)tag level:(int)level logString:(NSString*)logString;
@end


//函数中在获取到日志时，可以通过 delegate 让外部可以获取日志并进行对应分析，将 Tag、level、logString 进行传递。
// APLogListenerDelegate mpaas 专用
@protocol APLogListenerDelegate <NSObject>
@optional
- (void)logExtra:(NSString*)tag level:(int)level logString:(NSString*)logString;
@end

@interface APLogMgr : NSObject
@property (nonatomic, weak) id<APLogMgrDelegate> delegate;
@property (nonatomic, weak) id<APLogListenerDelegate> listenerDelegate;
@property (nonatomic, assign) BOOL logPrintEnable; // 日志打印开关
+ (APLogMgr*)sharedInstance;
- (void)handleUserChanged;
- (void)handleConfigUploadCmd:(NSArray*)taskArray;
- (void)handleSyncUploadCmd:(NSString*)syncOpString;
- (void)handleAutoUpload:(NSDictionary*)param;
- (void)addExcuteBlockAfterUpload:(void (^)(void))block;
- (void)uploadLogWithAccount:(NSString*)account startDate:(NSDate*)startDate endDate:(NSDate*)endDate;
@end



