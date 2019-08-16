//
//  AntRealtimeLogUploader.h
//  APRemoteLogging
//
//  Created by 卡迩 on 2017/6/30.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AntRealtimeLogItem.h"

@protocol AntRealtimeLogUploaderDelegate;

////////////////////////////////////////////////////////////////////////////////

@protocol AntRealtimeLogUploader <NSObject>

+ (id<AntRealtimeLogUploader>)sharedInstance;

- (void)setDelegate:(id<AntRealtimeLogUploaderDelegate>)delegate;

- (void)startTimerWithInterval:(NSUInteger)interval;

- (void)stopTimer;

- (void)enqueueLogs:(NSArray<AntRealtimeLogItem *> *)logs;

@end

////////////////////////////////////////////////////////////////////////////////

@protocol AntRealtimeLogUploaderDelegate <NSObject>

- (void)onRealtimeLogUploaderTimerFired;

- (void)onRealtimeLogUploadFinish:(BOOL)success
                            items:(NSArray<AntRealtimeLogItem *> *)items
                        extraInfo:(NSDictionary *)info;
@end

////////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
    id<AntRealtimeLogUploader> AntRealtimeLogUploaderGet();
#ifdef __cplusplus
}
#endif // __cplusplus


