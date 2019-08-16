//
//  H5JSCBridge.h
//
//  Created by theone on 16/11/21.
//  Copyright © 2016年 theone. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <NebulaTinyapp/NebulaTinyappDefine.h>

@class H5JSCExecutor;
@class H5JSCTiming;

@interface H5JSCBridge : PSDJsBridge

@property(nonatomic, copy, nullable)   NSString       *jsc_workerId;
@property(nonatomic, weak, nullable)   H5JSCExecutor  *javaScriptExecutor;

- (instancetype _Nonnull)initWithSession:(nonnull PSDSession *)session
                             isDebugMode:(BOOL)isDebugMode;

- (void)executeAsyncJavaScript:(nonnull NSString *)javaScript
                sourceURL:(nullable NSURL *)sourceURL
               onComplete:(nullable NBJavaScriptCallback)onComplete;

- (void)executeJavaScript:(nonnull NSString *)javaScript
                sourceURL:(nullable NSURL *)sourceURL
               onComplete:(nullable NBJavaScriptCallback)onComplete;

- (void)doFlushMessageQueue:(nullable id)buffer;

- (void)doFlushMessageQueue:(nullable NSDictionary *)message
                   callBack:(nullable PSDJsApiResponseCallbackBlock)callback;

- (void)sendMessage:(nonnull NSString *)messageName
               data:(nullable id)data
   responseCallback:(nullable PSDJsApiResponseCallbackBlock)responseCallback;

//timer
- (void)addUpdateObserver:(nonnull H5JSCTiming *)timer;
- (void)createTimer:(nonnull NSNumber *)callbackID
           duration:(NSTimeInterval)jsDuration
   jsSchedulingTime:(nonnull NSDate *)jsSchedulingTime
            repeats:(BOOL)repeats;
- (void)deleteTimer:(nonnull NSNumber *)timerID;
- (void)invalidate;
- (void)setUp;

//importjs
- (void)importJSWithUrl:(nullable NSString *)url callback:(nullable NBImportJsCallback)callback;
@end
