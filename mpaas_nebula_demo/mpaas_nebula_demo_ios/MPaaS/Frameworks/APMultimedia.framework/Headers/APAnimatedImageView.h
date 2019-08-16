//
//  APFLAnimatedImageView.h
//  Flipboard
//
//  Created by Raphael Schaad on 7/8/13.
//  Copyright (c) 2013-2015 Flipboard. All rights reserved.
//


#import <UIKit/UIKit.h>

//
//  An `APFLAnimatedImageView` can take an `APFLAnimatedImage` and plays it automatically when in view hierarchy and stops when removed.
//  The animation can also be controlled with the `UIImageView` methods `-start/stop/isAnimating`.
//  It is a fully compatible `UIImageView` subclass and can be used as a drop-in component to work with existing code paths expecting to display a `UIImage`.
//  Under the hood it uses a `CADisplayLink` for playback, which can be inspected with `currentFrame` & `currentFrameIndex`.
//
@interface APAnimatedImageView : UIImageView

@property (nonatomic, strong, readonly) UIImage *currentFrame;
@property (nonatomic, assign, readonly) NSUInteger currentFrameIndex;

// The animation runloop mode. Enables playback during scrolling by allowing timer events (i.e. animation) with NSRunLoopCommonModes.
// To keep scrolling smooth on single-core devices such as iPhone 3GS/4 and iPod Touch 4th gen, the default run loop mode is NSDefaultRunLoopMode. Otherwise, the default is NSRunLoopCommonModes.
@property (nonatomic, copy) NSString *runLoopMode;

/**
 是否由上层完全控制动画的播放和停止
 */
@property (nonatomic, assign) BOOL manualControlAnimated;

/**
 设置gif data

 @param gifData gif二进制数据
 */
- (void)setGifData:(NSData *)gifData;

/**
 设置UIAnimationImage,UIAnimationImage是系统提供的gif image对象

 @param animationImage UIAnimationImage 对象
 */
- (void)setUIAnimationImage:(UIImage *)animationImage;

@end
