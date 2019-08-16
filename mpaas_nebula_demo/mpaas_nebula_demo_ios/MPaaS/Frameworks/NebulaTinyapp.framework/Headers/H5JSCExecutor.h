//
//  H5JSCExecutor.h
//  FingerPrint
//
//  Created by theone on 16/11/17.
//  Copyright © 2016年 theone. All rights reserved.
//

#import <Foundation/Foundation.h>
@class H5JSCBridge;
@class JSContext;

@interface H5JSCExecutor : NSObject
- (instancetype)initWithBridge:(H5JSCBridge *)bridge;
//从外部给javascrpt执行一段js
- (void)executeJavaScript:(NSString *)javaScript
                sourceURL:(NSURL *)sourceURL
               onComplete:(NBJavaScriptCallback)onComplete;

- (void)executeBlockOnJavaScriptQueue:(dispatch_block_t)block;

- (void)executeAsyncBlockOnJavaScriptQueue:(dispatch_block_t)block;

- (void)setUp;
@end
