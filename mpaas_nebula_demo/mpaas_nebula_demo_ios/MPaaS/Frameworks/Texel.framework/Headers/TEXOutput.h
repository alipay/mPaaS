//
//  TEXOutput.h
//  Texel
//
//  Created by Cloud on 2017/5/3.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreMedia/CoreMedia.h>

#import "TEXContext.h"
#import "TEXFramebuffer.h"

@class TEXOutput;
@protocol TEXInput <NSObject>

- (void)receiveFramebuffer:(TEXFramebuffer *)framebuffer fromOutput:(TEXOutput *)output atTime:(CMTime)time;
@optional
- (void)addToOutput:(TEXOutput *)output;
- (void)removeFromOutput:(TEXOutput *)output;
- (void)outputDidReset:(TEXOutput *)output;

@end

@interface TEXOutput : NSObject

@property (nonatomic, strong) TEXFramebuffer *framebuffer;
@property (nonatomic, assign) CMTime time;
@property (nonatomic, assign) BOOL reference;
@property (nonatomic, strong, readonly) NSMutableArray <id<TEXInput>>*successors;
@property (nonatomic, assign) BOOL retryIgnoredFramebufferWhenAvailable; // 重新发送之前因为压后台而丢掉的帧，默认为NO

- (void)addSuccessor:(id<TEXInput>)successor;
- (void)removeSuccessor:(id<TEXInput>)successor;
- (void)suspendSuccessor:(id<TEXInput>)successor;
- (void)resumeSuccessor:(id<TEXInput>)successor;
- (void)framebufferReady:(CMTime)time;
- (CMTime)currentTime;

@end
